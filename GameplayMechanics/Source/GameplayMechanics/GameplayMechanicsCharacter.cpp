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

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P, FP_Gun, and VR_Gun 
	// are set in the derived blueprint asset named MyCharacter to avoid direct content references in C++.

	// Create VR Controllers.
	R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("R_MotionController"));
	R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	R_MotionController->SetupAttachment(RootComponent);
L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("L_MotionController"));
L_MotionController->SetupAttachment(RootComponent);

// Create a gun and attach it to the right-hand VR controller.
// Create a gun mesh component
VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
VR_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
VR_Gun->bCastDynamicShadow = false;
VR_Gun->CastShadow = false;
VR_Gun->SetupAttachment(R_MotionController);
VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

VR_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
VR_MuzzleLocation->SetupAttachment(VR_Gun);
VR_MuzzleLocation->SetRelativeLocation(FVector(0.000004, 53.999992, 10.000000));
VR_MuzzleLocation->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));		// Counteract the rotation of the VR gun model.

// Uncomment the following line to turn motion controllers on by default:
//bUsingMotionControllers = true;
}

void AGameplayMechanicsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	// Show or hide the two versions of the gun based on whether or not we're using motion controllers.
	if (bUsingMotionControllers)
	{
		VR_Gun->SetHiddenInGame(false, true);
		Mesh1P->SetHiddenInGame(true, true);
	}
	else
	{
		VR_Gun->SetHiddenInGame(true, true);
		Mesh1P->SetHiddenInGame(false, true);
	}
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



	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AGameplayMechanicsCharacter::OnFire);



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
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Two))
	{
		arrowType = 2;
	}
	else if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustReleased(EKeys::Three))
	{
		arrowType = 3;
	}
	bowPullBack(DeltaTime);

	wallClimb();

	
	

}

void AGameplayMechanicsCharacter::wallClimb()
{
	FHitResult hitResult;
	FCollisionQueryParams CollisionParams;
	GetWorld()->LineTraceSingleByChannel(hitResult, GetActorLocation(), (GetActorLocation() + (GetActorForwardVector() * 100)), ECC_Visibility, CollisionParams);


	static const FName ClimbableTag = TEXT("climbable");
	if (hitResult.bBlockingHit)
	{
		if (hitResult.GetActor()->ActorHasTag(ClimbableTag))
		{

			climbTime = GetWorld()->GetFirstPlayerController()->GetInputKeyTimeDown(EKeys::SpaceBar);
			if (climbTime > 0.0f && climbTime < 1.0f)
			{
				LaunchCharacter(FVector(0, 0, 350), true, true);
			}
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

		const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		if (arrowType == 1)
		{
			AStandardArrow* newArrow = GetWorld()->SpawnActor<AStandardArrow>(AStandardArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;
			/*ATestArrow* newArrow = GetWorld()->SpawnActor<ATestArrow>(ATestArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;*/
		}
		
		else if (arrowType == 2)
		{
			AScatterArrow* newArrow = GetWorld()->SpawnActor<AScatterArrow>(AScatterArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;
		}

		else if (arrowType == 3)
		{
			ASonicArrow* newArrow = GetWorld()->SpawnActor<ASonicArrow>(ASonicArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
			newArrow->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
			maxSpeed = 1500;
		}
	}
	
}
void AGameplayMechanicsCharacter::OnFire()
{
	

}

void AGameplayMechanicsCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AGameplayMechanicsCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
	{
		return;
	}
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void AGameplayMechanicsCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	TouchItem.bIsPressed = false;
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

bool AGameplayMechanicsCharacter::EnableTouchscreenMovement(class UInputComponent* PlayerInputComponent)
{
	if (FPlatformMisc::SupportsTouchInput() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGameplayMechanicsCharacter::BeginTouch);
		PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this, &AGameplayMechanicsCharacter::EndTouch);

		//Commenting this out to be more consistent with FPS BP template.
		//PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AGameplayMechanicsCharacter::TouchUpdate);
		return true;
	}
	
	return false;
}
