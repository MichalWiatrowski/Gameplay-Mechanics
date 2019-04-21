// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "BaseArrow.h"
#include "FlyingArrow.h"

#include "ScatterArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API AScatterArrow : public ABaseArrow
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AScatterArrow();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	void initArrow(float initialVelocity, float chargeTime, float scatteredArrowsVelocity, int noOfBounces);

	
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	float scatterArrowVelocity = 6000;
	int numberOfBounces = 5;

	AFlyingArrow* newArrow[5];
};
