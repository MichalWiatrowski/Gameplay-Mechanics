// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GameplayMechanicsCharacter.h"
#include "GameplayMechanicsProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId


DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AGameplayMechanicsCharacter

AGameplayMechanicsCharacter::AGameplayMechanicsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(65.f, 96.0f);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGameplayMechanicsCharacter::OnCapsuleOverlapBegin);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AGameplayMechanicsCharacter::OnCapsuleOverlapEnd);
	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for arrows to spawn
	ArrowOffset = FVector(80, 1.5f, 40);



	bowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BowVisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> bowMeshAsset(TEXT("/Game/bowMesh.bowMesh"));

	if (bowMeshAsset.Succeeded())
	{
		bowMesh->SetStaticMesh(bowMeshAsset.Object);
		bowMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);


		bowMesh->bCastDynamicShadow = false;
		bowMesh->CastShadow = false;
		bowMesh->SetupAttachment(FirstPersonCameraComponent);
		bowMesh->SetRelativeLocation(FVector(50.0f, -20.0f, -60.0f));
		bowMesh->SetRenderCustomDepth(true);
	}

	arrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArrowVisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> arrowMeshAsset(TEXT("/Game/arrowMesh.arrowMesh"));
	if (arrowMeshAsset.Succeeded())
	{
		arrowMesh->SetStaticMesh(arrowMeshAsset.Object);
		//offset the mesh so the sphere collider component is just behind the the tip of the mesh to give the effect of the tip going into an object
		arrowMesh->SetupAttachment(FirstPersonCameraComponent);
		arrowMesh->SetRelativeLocation(FVector(70.0f, 3.2f, -20.5f));
		arrowMesh->SetRelativeRotation(FRotator(-90, 90, -180));
		arrowMesh->SetWorldScale3D(FVector(1.0f));
		arrowMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		arrowMesh->SetRenderCustomDepth(true);

		arrowMesh->bCastDynamicShadow = false;
		arrowMesh->CastShadow = false;
	}

}

void AGameplayMechanicsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	scatterTimer = scatterArrowCooldown;
	sonicTimer = sonicArrowCooldown;
	vacuumTimer = vacuumArrowCooldown;

	currentArrowsAmmo = maxArrowsAmmo;

	//currentChargedVelocity = minVelocity;
	arrowMesh->SetMaterial(0, standardArrowMaterial);

	
	
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGameplayMechanicsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameplayMechanicsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameplayMechanicsCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGameplayMechanicsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGameplayMechanicsCharacter::LookUpAtRate);
}

void AGameplayMechanicsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	handleInput(DeltaTime);
	handleCooldowns(DeltaTime);

	wallClimb(DeltaTime);
}

//Handle the input for the character
void AGameplayMechanicsCharacter::handleInput(float DeltaTime)
{

	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::LeftMouseButton) && (currentArrowsAmmo > 0 || (arrowType != Standard)))
	{
		bowPullBack(DeltaTime);
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
	{
		shootArrow();
	}

	//Change the type of arrow currently in use
	if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::One))
	{
		arrowMesh->SetMaterial(0, standardArrowMaterial);
		arrowType = Standard;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Two) && scatterArrowReady == true)
	{
		arrowMesh->SetMaterial(0, scatterArrowMaterial);
		arrowType = Scatter;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Three) && sonicArrowReady == true)
	{
		arrowMesh->SetMaterial(0, sonicArrowMaterial);
		arrowType = Sonic;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Four) && vacuumArrowReady == true)
	{
		arrowMesh->SetMaterial(0, vacuumArrowMaterial);
		arrowType = Vacuum;
	}


	//Reload the standard arrows
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::R) && currentArrowsAmmo < maxArrowsAmmo)
	{
		currentArrowsAmmo = maxArrowsAmmo;
	}
}


void AGameplayMechanicsCharacter::handleCooldowns(float DeltaTime)
{
	//Handle cooldown for scatter arrow
	if (scatterArrowReady == false)
	{
		scatterTimer += DeltaTime;
		if (scatterTimer > scatterArrowCooldown)
		{

			scatterArrowReady = true;
		}
	}

	//Handle cooldown for sonic arrow
	if (sonicArrowReady == false)
	{
		sonicTimer += DeltaTime;
		if (sonicTimer > sonicArrowCooldown)
		{

			sonicArrowReady = true;
		}
	}

	//Handle cooldown for vacuum arrow
	if (vacuumArrowReady == false)
	{
		vacuumTimer += DeltaTime;
		if (vacuumTimer > vacuumArrowCooldown)
		{

			vacuumArrowReady = true;
		}
	}


}

void AGameplayMechanicsCharacter::bowPullBack(float DeltaTime)
{
	
	
		if (currentChargedVelocity < maxVelocity)
		{
		
			arrowMeshCurrentLocation = FMath::Lerp(arrowMeshCurrentLocation, arrowMeshMaxChargeLocation, DeltaTime * 2.5  * chargeSpeed); //2.5 is animation speed (add variable)
			arrowMesh->SetRelativeLocation(arrowMeshCurrentLocation);


			chargeTime += DeltaTime;
			currentChargedVelocity += maxVelocity * DeltaTime * chargeSpeed;

			if (currentChargedVelocity > maxVelocity)
				currentChargedVelocity = maxVelocity;

	
			if (GEngine)
			{
				GEngine->ClearOnScreenDebugMessages();
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Debug: chargedVelocity : %f"), currentChargedVelocity));
			}
				
		}
}
void AGameplayMechanicsCharacter::shootArrow()
{

	UWorld* const World = GetWorld();

	const FRotator SpawnRotation = GetControlRotation();

	const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(ArrowOffset);
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (arrowType == Standard)
	{
		if (currentArrowsAmmo > 0)
		{
			AStandardArrow* newArrow = GetWorld()->SpawnActor<AStandardArrow>(AStandardArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			//newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(currentChargedVelocity, 0, 0));
			newArrow->initArrow(currentChargedVelocity, chargeTime);




			currentChargedVelocity = 0.0f;

			currentArrowsAmmo--;
		}
			

	}

	else if (arrowType == Scatter)
	{
		AScatterArrow* newArrow = GetWorld()->SpawnActor<AScatterArrow>(AScatterArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
		newArrow->initArrow(currentChargedVelocity, chargeTime, scatterArrowVelocity, scatterArrowBounceAmount);
		
		scatterArrowReady = false;
		scatterTimer = 0.0f;

		currentChargedVelocity = 0.0f;
		arrowType = Standard;
		arrowMesh->SetMaterial(0, standardArrowMaterial);
	}

	else if (arrowType == Sonic)
	{
		ASonicArrow* newArrow = GetWorld()->SpawnActor<ASonicArrow>(ASonicArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
		newArrow->initArrow(currentChargedVelocity, chargeTime, sonicSphereRadius);

		sonicArrowReady = false;
		sonicTimer = 0.0f;

		currentChargedVelocity = 0.0f;
		arrowType = Standard;
		arrowMesh->SetMaterial(0, standardArrowMaterial);
	}
	else if (arrowType == Vacuum)
	{
		AVacuumArrow* newArrow = GetWorld()->SpawnActor<AVacuumArrow>(AVacuumArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
		newArrow->initArrow(currentChargedVelocity, chargeTime,vacuumMaxDelay, vacuumPullStrength);

		vacuumArrowReady = false;
		vacuumTimer = 0.0f;

		currentChargedVelocity = 0.0f;
		arrowType = Standard;
		arrowMesh->SetMaterial(0, standardArrowMaterial);
		
	}
	chargeTime = 0.0f;
	arrowMeshCurrentLocation = arrowMeshMinChargeLocation;
	arrowMesh->SetRelativeLocation(arrowMeshCurrentLocation);
}

void AGameplayMechanicsCharacter::wallClimb(float DeltaTime)
{

	FCollisionQueryParams CollisionParams;

	if (canClimb == true)
	{
		FHitResult wallHitResult;
		GetWorld()->LineTraceSingleByChannel(wallHitResult, GetActorLocation(), (GetActorLocation() + (GetActorForwardVector() * 66)), ECC_Visibility, CollisionParams);
		//DrawDebugLine(GetWorld(), GetActorLocation(), (GetActorLocation() + (GetActorForwardVector() * 66)), FColor(0, 255, 0), true, 0.1, 1, 0.2);

		if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::SpaceBar))
		{

			static const FName ClimbableTag = TEXT("climbable");

			if (wallHitResult.bBlockingHit && wallHitResult.GetActor()->ActorHasTag(ClimbableTag))
			{
				climbTime += DeltaTime;
				isClimbing = true;
				if (climbTime > 0.0f && climbTime < 0.7f && canClimb == true)
				{
					LaunchCharacter(FVector(0, 0, 450), true, true);
				}
			}
		}


		if ((GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::SpaceBar) && isClimbing == true) || (climbTime >= 0.7 && isClimbing == true) || (!wallHitResult.bBlockingHit && isClimbing == true))
		{
			canClimb = false;
		}

	}
	else if (canClimb == false)
	{
		FHitResult groundHitResult;
		GetWorld()->LineTraceSingleByChannel(groundHitResult, GetActorLocation(), (GetActorLocation() + (-GetActorUpVector() * 120)), ECC_Visibility, CollisionParams);

		if (groundHitResult.bBlockingHit)
		{
			climbTime = 0.0f;
			canClimb = true;
			isClimbing = false;
		}
	}

}
void AGameplayMechanicsCharacter::OnCapsuleOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherActor->ActorHasTag(FName(TEXT("arrow"))))
	{
		OtherComp->SetRenderCustomDepth(true);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
	}
}
void AGameplayMechanicsCharacter::OnCapsuleOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherActor->ActorHasTag(FName(TEXT("arrow"))))
	{
		OtherComp->SetRenderCustomDepth(false);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
	}
}



void AGameplayMechanicsCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGameplayMechanicsCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGameplayMechanicsCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGameplayMechanicsCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

