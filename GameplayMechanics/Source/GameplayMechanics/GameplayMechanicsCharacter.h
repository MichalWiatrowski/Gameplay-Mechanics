// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "SonicArrow.h"
#include "CoreMinimal.h"
#include "FlyingArrow.h"
#include "ScatterArrow.h"
#include "StandardArrow.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "GameplayMechanicsCharacter.generated.h"


class UInputComponent;

UCLASS(config = Game)
class AGameplayMechanicsCharacter : public ACharacter
{
	GENERATED_BODY()

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	//Bow model
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* bowMesh;
public:
	AGameplayMechanicsCharacter();

	




	bool isCharging = false;
	float maxSpeed = 1500.0f;

	float climbTime = 0.0f;
	bool isClimbing = false;
	bool canClimb = true;



	bool canSecondJump = false;
	int arrowType = 1;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StandardArrow)
		int32 maxArrowsAmmo = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StandardArrow)
		int32 currentArrowsAmmo = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StandardArrow)
	float scatterArrowCooldown = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StandardArrow)
	float scatterTimer = 0.0f;
	bool scatterArrowReady = true;

protected:
	virtual void BeginPlay(); //On begin play
	virtual void Tick(float DeltaTime) override; //update/tick

	//Handles the firing of arrows
	void shootArrow();

	//Handles wall climbing
	void wallClimb(float DeltaTime);

	//Handles the calculation of initial velocity of arrows
	void bowPullBack(float DeltaTime);













	//////////* Basic movement related functions from the template character *//////////

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:

	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;
};

