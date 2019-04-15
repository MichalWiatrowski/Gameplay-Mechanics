// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyingArrow.h"

// Sets default values
AFlyingArrow::AFlyingArrow()
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionComponent->OnComponentHit.AddDynamic(this, &AFlyingArrow::OnHit);		// set up a notification for when this component hits something blocking




	projectileMovement->bRotationFollowsVelocity = true;

	projectileMovement->bShouldBounce = true;
	projectileMovement->Bounciness = 0;
	projectileMovement->ProjectileGravityScale = 0;


	// Die after 10 seconds by default

	InitialLifeSpan = 10.0f;
}

// Called when the game starts or when spawned
void AFlyingArrow::BeginPlay()
{
	Super::BeginPlay();
	lastPosition = GetActorLocation();
}

// Called every frame
void AFlyingArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugLine(GetWorld(), GetActorLocation(), lastPosition, FColor(35, 222, 255), true, 0.2, 0, 4);

	//execute the rotation function
	updateArrowVelocityRotation();


	lastPosition = GetActorLocation();
	projectileMovement->SetVelocityInLocalSpace(FVector(6000, 0, 0));

}


void AFlyingArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();

	}

	//If the number of bounces is over 5, destroy the actor
	if (numberOfBounces > 5)
		Destroy();
	//otherwise increment the number of bounces
	else
		numberOfBounces++;

	float maxSpeed = 6000;


	UWorld* const World = GetWorld(); //get the world

	FVector newArrowAxes = (((GetActorForwardVector() * Hit.Normal) * -3) * Hit.Normal) + GetActorForwardVector();
	FVector arrowAxes;

	FVector newReflectionVector = GetActorForwardVector() - (2 * (GetActorForwardVector() * Hit.Normal) * Hit.Normal);
	SetActorRotation(UKismetMathLibrary::MakeRotFromX(newReflectionVector));



	projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));



	maxSpeed = 6000;
}

