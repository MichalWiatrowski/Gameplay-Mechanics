// Fill out your copyright notice in the Description page of Project Settings.

#include "StandardArrow.h"

// Sets default values
AStandardArrow::AStandardArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionComponent->OnComponentHit.AddDynamic(this, &AStandardArrow::OnHit);		// set up a notification for when this component hits something blocking

	
	// Die after 10 seconds by default
	InitialLifeSpan = 10.0f;

	
}

// Called when the game starts or when spawned
void AStandardArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStandardArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//execute the rotation function
	updateArrowVelocityRotation();

}

void AStandardArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		if (OtherActor->ActorHasTag(FName(TEXT("enemy"))))
		{
				FDamageEvent damageEvent;
				OtherActor->TakeDamage(25, damageEvent, GetInstigatorController(), this);
				Destroy();
		}
		else if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
			Destroy();
		}



	
		
		
		
	}
}

