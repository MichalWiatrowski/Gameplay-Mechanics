// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "FlyingArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API AFlyingArrow : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFlyingArrow();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void updateArrowVelocityRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	USphereComponent* collisionComponent;
	UProjectileMovementComponent* projectileMovement;
	UStaticMeshComponent* arrowMesh;
	
	int numberOfBounces = 0;
	FVector lastPosition;
};