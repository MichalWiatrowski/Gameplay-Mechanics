// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseArrow.h"
#include "DrawDebugHelpers.h"
#include "VacuumArrow.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYMECHANICS_API AVacuumArrow : public ABaseArrow
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	AVacuumArrow();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	void initArrow(float initialVelocity, float chargeTime, float maxDuration, float pullStrength);
	
private:
	USphereComponent* enemyScannerCollisionComponent;
	TArray<UPrimitiveComponent*> enemiesInRange;
	

	float currentTime = 0.0f;
	float maxTime = 2.0f;
	float gravityPullStrength = 1000.0f;

};
