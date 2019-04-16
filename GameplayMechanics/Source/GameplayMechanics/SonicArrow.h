// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseArrow.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "SonicArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API ASonicArrow : public ABaseArrow
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ASonicArrow();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep,const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);




	void initArrow(float initialVelocity, float sonicComponentRadius);

private:
	float sonicSphereRadius = 1000.0f;
	USphereComponent* sonicCollisionComponent;
};
