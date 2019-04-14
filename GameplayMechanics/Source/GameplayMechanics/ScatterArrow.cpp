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
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		
	}
	Destroy();

	float maxSpeed = 7000;
	UWorld* const World = GetWorld();

	FVector arrowAxes;
	FVector rotationOtherActor;

	UKismetMathLibrary::BreakRotator(OtherActor->GetActorRotation(), rotationOtherActor.X, rotationOtherActor.Y, rotationOtherActor.Z);

	FVector idk = UKismetMathLibrary::GetReflectionVector(UKismetMathLibrary::GetDirectionUnitVector(GetActorLocation(), Hit.ImpactPoint), Hit.ImpactNormal);
	
	
	FVector SpawnLocation = (GetActorLocation());
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AFlyingArrow* newArrow[5];



	FVector oneLOL = GetActorForwardVector() - (2 * (GetActorForwardVector() * Hit.Normal) * Hit.Normal);
	UKismetMathLibrary::BreakRotator(UKismetMathLibrary::MakeRotFromX(oneLOL), arrowAxes.X, arrowAxes.Y, arrowAxes.Z);
	FRotator SpawnRotation;



	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z - 25);



	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));




	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y + 15, arrowAxes.Z - 15);



	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));



	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z);



	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));




	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y + 15, arrowAxes.Z + 15);



	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));





	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z + 25);



	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));
}