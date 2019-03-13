// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/KismetMathLibrary.h"
#include "CoreMinimal.h"
#include "StandardArrow.h"
#include "FlyingArrow.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ScatterArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API AScatterArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScatterArrow();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void updateArrowVelocityRotation();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	USphereComponent* collisionComponent;
	UProjectileMovementComponent* projectileMovement;
	UStaticMeshComponent* arrowMesh;
};
