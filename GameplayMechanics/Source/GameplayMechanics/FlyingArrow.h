// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DrawDebugHelpers.h"
#include "BaseArrow.h"
#include "FlyingArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API AFlyingArrow : public ABaseArrow
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AFlyingArrow();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	void initArrow(float initialVelocity, int noOfMaxBounces);

private:
	float arrowVelocity = 6000;
	int numberOfBounces = 0;
	int numberOfMaxBounces = 5;
	FVector lastPosition;
};