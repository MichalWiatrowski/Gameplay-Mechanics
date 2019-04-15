// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "SonicArrow.h"
#include "CoreMinimal.h"
#include "FlyingArrow.h"
#include "ScatterArrow.h"
#include "StandardArrow.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Math/UnrealMathVectorCommon.h"
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

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* arrowMesh;
public:
	AGameplayMechanicsCharacter();

	


	FVector arrowMeshMaxChargeLocation = (FVector(35.0f, 3.0f, -20.5f));
	FVector arrowMeshCurrentLocation = (FVector(75.0f, 3.0f, -20.5f));
	FVector arrowMeshMinChargeLocation = (FVector(75.0f, 3.0f, -20.5f));
	float currentChargedVelocity = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Custom Settings | ArrowTypes | Standard Arrow")
	UMaterial* standardArrowMaterial;
	UPROPERTY(EditAnywhere, Category = "Custom Settings | ArrowTypes | Scatter Arrow")
	UMaterial* scatterArrowMaterial;
	UPROPERTY(EditAnywhere, Category = "Custom Settings | ArrowTypes | Sonic Arrow")
	UMaterial* sonicArrowMaterial;









	

	//float minVelocity = 1500.0f;
	//float maxVelocity = 7000.0f;


	float climbTime = 0.0f;
	bool isClimbing = false;
	bool canClimb = true;



	bool canSecondJump = false;

	enum arrows { Standard, Scatter, Sonic } arrowType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Settings | ArrowTypes | Standard Arrow")
		int32 maxArrowsAmmo = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Settings | ArrowTypes | Standard Arrow")
		int32 currentArrowsAmmo = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Settings | ArrowTypes | Scatter Arrow")
	float scatterArrowCooldown = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Settings | ArrowTypes | Scatter Arrow")
	float scatterTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Settings | ArrowTypes | Sonic Arrow")
		float sonicArrowCooldown = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Settings | ArrowTypes | Sonic Arrow")
		float sonicTimer = 0.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Settings | Archer Settings")
	float minVelocity = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Settings | Archer Settings")
	float maxVelocity = 12000.0f;

	UPROPERTY(EditAnywhere, Category = "Custom Settings | Archer Settings")
	float chargeSpeed = 1.0f;





	bool scatterArrowReady = true;
	bool sonicArrowReady = true;









protected:
	virtual void BeginPlay(); //On begin play
	virtual void Tick(float DeltaTime) override; //update/tick

	//Handles the firing of arrows
	void shootArrow();

	//Handles wall climbing
	void wallClimb(float DeltaTime);

	//Handles the calculation of initial velocity of arrows
	void bowPullBack(float DeltaTime);


	void handleInput(float DeltaTime);
	void handleCooldowns(float DeltaTime);









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
		FVector ArrowOffset;
};

