// Fill out your copyright notice in the Description page of Project Settings.

#include "ScatterArrow.h"

// Sets default values
AScatterArrow::AScatterArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	collisionComponent->OnComponentHit.AddDynamic(this, &AScatterArrow::OnHit);		// set up a notification for when this component hits something blocking

	// Die after 10 seconds by default
	InitialLifeSpan = 10.0f;
}
void AScatterArrow::initArrow(float initialVelocity, float chargeTime, float scatteredArrowsVelocity, int noOfBounces)
{
	numberOfBounces = noOfBounces;
	scatterArrowVelocity = scatteredArrowsVelocity;
	projectileMovement->SetVelocityInLocalSpace(FVector(initialVelocity, 0, 0));
	chargedTime = chargeTime;

}

// Called when the game starts or when spawned
void AScatterArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScatterArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateArrowVelocityRotation();
}


void AScatterArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
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


		
		}
		else if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());	
		}
	Destroy();
	}
	
	FVector SpawnLocation = (GetActorLocation());
	FRotator SpawnRotation;
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector arrowAxes;
	FVector oneLOL = GetActorForwardVector() - (2 * (GetActorForwardVector() * Hit.Normal) * Hit.Normal);
	UKismetMathLibrary::BreakRotator(UKismetMathLibrary::MakeRotFromX(oneLOL), arrowAxes.X, arrowAxes.Y, arrowAxes.Z);
	
	//Arrows from left to right when they spawn
	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z - 25);
	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->initArrow(scatterArrowVelocity, numberOfBounces);

	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y + 15, arrowAxes.Z - 15);
	newArrow[1] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[1]->initArrow(scatterArrowVelocity, numberOfBounces);

	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z);
	newArrow[2] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[2]->initArrow(scatterArrowVelocity, numberOfBounces);

	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y + 15, arrowAxes.Z + 15);
	newArrow[3] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[3]->initArrow(scatterArrowVelocity, numberOfBounces);

	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z + 25);
	newArrow[4] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[4]->initArrow(scatterArrowVelocity, numberOfBounces);
}