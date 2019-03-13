// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Engine/TriggerSphere.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SonicArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API ASonicArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASonicArrow();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void updateArrowVelocityRotation();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep,const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	bool hitLOL = false;
	UPROPERTY(EditAnywhere)
	USphereComponent* sonicCollisionComponent;

	UPROPERTY(EditAnywhere)
	USphereComponent* collisionComponent;

	UProjectileMovementComponent* projectileMovement;
	UStaticMeshComponent* arrowMesh;
};
