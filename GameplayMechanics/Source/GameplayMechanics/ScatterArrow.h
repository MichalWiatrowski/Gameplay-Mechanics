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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	USphereComponent* collisionComponent;
	UProjectileMovementComponent* projectileMovement;
	UStaticMeshComponent* arrowMesh;
	void updateArrowVelocityRotation();

	
};
