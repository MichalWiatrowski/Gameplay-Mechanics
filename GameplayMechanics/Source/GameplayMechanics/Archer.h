// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FlyingArrow.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Archer.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API AArcher : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AArcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};
