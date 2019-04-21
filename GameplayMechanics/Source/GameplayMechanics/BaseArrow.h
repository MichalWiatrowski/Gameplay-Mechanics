//Base arrow class that will be used as a base class for inheritance
//The class will hold the mesh, collision component and projectile movement
//In addition, since all arrows will use it, it contains the function for rotating the mesh based on the velocity

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "BaseArrow.generated.h"

UCLASS()
class GAMEPLAYMECHANICS_API ABaseArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void updateArrowVelocityRotation();
	int calculateDamage(float chargedTime, int minimumDamage, FName boneName);
	virtual void initArrow();

	bool isHit = false;
	float chargedTime = 0.0f;
public:
	USphereComponent* collisionComponent;
	UProjectileMovementComponent* projectileMovement;
	UStaticMeshComponent* arrowMesh;
};
