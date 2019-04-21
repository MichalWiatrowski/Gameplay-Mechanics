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
void AStandardArrow::initArrow(float initialVelocity, float chargeTime)
{
	projectileMovement->SetVelocityInLocalSpace(FVector(initialVelocity, 0, 0));
	chargedTime = chargeTime;
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

			if (OtherComp->IsSimulatingPhysics())
			{
				OtherComp->AddImpulseAtLocation(GetVelocity(), GetActorLocation()); //for the memes
			}
			else
			{
				FDamageEvent damageEvent;
				OtherActor->TakeDamage(calculateDamage(chargedTime, 25, Hit.BoneName), damageEvent, GetInstigatorController(), this);
			}
				
				
				if (Hit.BoneName != NAME_None)
				{
					RootComponent->AttachTo(OtherComp, Hit.BoneName, EAttachLocation::KeepWorldPosition, true);
				}
				else
				{
					RootComponent->AttachTo(OtherComp, FName(TEXT("pelvisSocket")), EAttachLocation::KeepWorldPosition, true);
				}
		}
		else if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation()); 
			RootComponent->AttachTo(OtherComp, NAME_None, EAttachLocation::KeepWorldPosition, true);
		}
		else
		{
			RootComponent->AttachTo(OtherComp, NAME_None, EAttachLocation::KeepWorldPosition, true);
		}	
	}
}

