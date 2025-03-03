// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseArrow.h"
#include "StandardArrow.generated.h"


UCLASS()
class GAMEPLAYMECHANICS_API AStandardArrow : public ABaseArrow
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStandardArrow();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void initArrow(float initialVelocity, float chargeTime);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
