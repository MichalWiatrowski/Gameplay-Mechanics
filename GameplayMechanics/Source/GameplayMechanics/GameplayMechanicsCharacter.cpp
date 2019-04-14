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
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);



	bowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BowVisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> bowMeshAsset(TEXT("/Game/bowMesh.bowMesh"));

	if (bowMeshAsset.Succeeded())
	{
		bowMesh->SetStaticMesh(bowMeshAsset.Object);
		bowMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);


		bowMesh->bCastDynamicShadow = false;
		bowMesh->CastShadow = false;
		bowMesh->SetupAttachment(FirstPersonCameraComponent);
		bowMesh->SetRelativeLocation(FVector(60.0f, -20.0f, -60.0f));
	}
}

void AGameplayMechanicsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	scatterTimer = scatterArrowCooldown;
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


	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::LeftMouseButton))
	{
		isCharging = true;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::LeftMouseButton))
	{
		isCharging = false;
		shootArrow();
	}

	if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::One))
	{
		arrowType = 1;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Two) && scatterArrowReady == true)
	{
		arrowType = 2;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Three))
	{
		arrowType = 3;
	}

	if (scatterArrowReady == false)
	{
		scatterTimer += DeltaTime;
		if (scatterTimer > scatterArrowCooldown)
		{
			
			scatterArrowReady = true;
		}
	}

	bowPullBack(DeltaTime);

	wallClimb(DeltaTime);
}

void AGameplayMechanicsCharacter::wallClimb(float DeltaTime)
{

	FCollisionQueryParams CollisionParams;
	
	if (canClimb == true)
	{
		FHitResult wallHitResult;
		GetWorld()->LineTraceSingleByChannel(wallHitResult, GetActorLocation(), (GetActorLocation() + (GetActorForwardVector() * 60)), ECC_Visibility, CollisionParams);

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


		if ((GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::SpaceBar) && isClimbing == true ) || (climbTime >= 0.7 && isClimbing == true))
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
void AGameplayMechanicsCharacter::bowPullBack(float DeltaTime)
{
	if (isCharging == true)
	{
		if (maxSpeed < 7000)
		{
			maxSpeed += 7000 * DeltaTime;
			if (maxSpeed > 7000)
				maxSpeed = 7000;
			//FString::Printf(TEXT("%f"), maxSpeed);
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), maxSpeed));
		}

	}
}
void AGameplayMechanicsCharacter::shootArrow()
{
	if (isCharging == false)
	{
		UWorld* const World = GetWorld();

		const FRotator SpawnRotation = GetControlRotation();

		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		if (arrowType == 1)
		{
			AStandardArrow* newArrow = GetWorld()->SpawnActor<AStandardArrow>(AStandardArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;

		}

		else if (arrowType == 2)
		{
			AScatterArrow* newArrow = GetWorld()->SpawnActor<AScatterArrow>(AScatterArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;


			scatterArrowReady = false;
			scatterTimer = 0.0f;

			arrowType = 1;
		}

		else if (arrowType == 3)
		{
			ASonicArrow* newArrow = GetWorld()->SpawnActor<ASonicArrow>(ASonicArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;
		}
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

