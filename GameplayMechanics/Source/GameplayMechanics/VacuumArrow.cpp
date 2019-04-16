// Fill out your copyright notice in the Description page of Project Settings.

#include "VacuumArrow.h"

// Sets default values
AVacuumArrow::AVacuumArrow()
{
	// Set this actor to call Tick() every frame.You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionComponent->OnComponentHit.AddDynamic(this, &AVacuumArrow::OnHit);		// set up a notification for when this component hits something blocking

	enemyScannerCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("EnemyScannerComponent"));
	enemyScannerCollisionComponent->InitSphereRadius(0.01f);
	enemyScannerCollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	enemyScannerCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	enemyScannerCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AVacuumArrow::OnOverlapBegin);
	enemyScannerCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AVacuumArrow::OnOverlapEnd);

	enemyScannerCollisionComponent->SetupAttachment(RootComponent);


	// Die after 10 seconds by default
	InitialLifeSpan = 10.0f;

}

// Called when the game starts or when spawned
void AVacuumArrow::BeginPlay()
{
	Super::BeginPlay();
}

void AVacuumArrow::initArrow(float initialVelocity, float maxDuration, float pullStrength)
{
	
	maxTime = maxDuration;
	gravityPullStrength = pullStrength;
	projectileMovement->SetVelocityInLocalSpace(FVector(initialVelocity, 0, 0));
}

// Called every frame
void AVacuumArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateArrowVelocityRotation();

	
	if (isHit == true)
	{
		currentTime += DeltaTime;

		if (enemiesInRange.Num() > 0)
		{

			
			for (int i = 0; i < enemiesInRange.Num(); i++)
			{
				//DrawDebugLine(GetWorld(), GetActorLocation(), enemiesInRange[i]->GetAttachmentRootActor()->GetActorLocation(), FColor(0, 255, 0), true, 0.01, 0, 10);
				FCollisionQueryParams CollisionParams;
				FHitResult actorVisibileHitResult;

				GetWorld()->LineTraceSingleByChannel(actorVisibileHitResult, GetActorLocation(), enemiesInRange[i]->GetComponentLocation(), ECC_Visibility, CollisionParams);

				if (actorVisibileHitResult.bBlockingHit && actorVisibileHitResult.GetComponent()->IsSimulatingPhysics())
				{
					DrawDebugLine(GetWorld(), GetActorLocation(), enemiesInRange[i]->GetComponentLocation(), FColor(0, 255, 0), true, 0.01, 0, 10);

					if (currentTime > maxTime)
					{
						FVector directionVector = GetActorLocation() - enemiesInRange[i]->GetComponentLocation();

						enemiesInRange[i]->AddImpulse(directionVector * gravityPullStrength);
						//enemiesInRange[i]->SetSimulatePhysics(false);
						//enemiesInRange[i]->SetSimulatePhysics(true);
					}
				}
			}		
		}

		if (currentTime > maxTime)
		{
			Destroy();
		}
	}
}

void AVacuumArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	enemyScannerCollisionComponent->SetSphereRadius(1000.0f);

	//projectileMovement->StopMovementImmediately();
	RootComponent->AttachTo(OtherComp, NAME_None, EAttachLocation::KeepWorldPosition, false);

	isHit = true;
}




void AVacuumArrow::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp->IsSimulatingPhysics())
	{
		if (!enemiesInRange.Contains(OtherComp))
		{
			enemiesInRange.Add(OtherComp);
		}

	}
}
void AVacuumArrow::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp->IsSimulatingPhysics())
	{
		if (enemiesInRange.Contains(OtherComp))
		{
			enemiesInRange.Remove(OtherComp);
		}
	}
}
