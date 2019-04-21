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
	enemyScannerCollisionComponent->SetRelativeLocation(FVector(-20.0f, 0.0f, 0.0f));

	// Die after 10 seconds by default
	InitialLifeSpan = 10.0f;

}

// Called when the game starts or when spawned
void AVacuumArrow::BeginPlay()
{
	Super::BeginPlay();
}

void AVacuumArrow::initArrow(float initialVelocity, float chargeTime, float maxDuration, float pullStrength)
{
	
	maxTime = maxDuration;
	gravityPullStrength = pullStrength;
	projectileMovement->SetVelocityInLocalSpace(FVector(initialVelocity, 0, 0));
	chargedTime = chargeTime;
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

			
				if (enemiesInRange[i]->ComponentHasTag((FName(TEXT("mesh")))))
				{
					GetWorld()->LineTraceSingleByChannel(actorVisibileHitResult, GetActorLocation(), enemiesInRange[i]->GetSocketLocation(FName(TEXT("pelvisSocket"))), ECC_Visibility, CollisionParams);

					if (actorVisibileHitResult.bBlockingHit && actorVisibileHitResult.GetComponent()->IsSimulatingPhysics() && actorVisibileHitResult.GetComponent()->ComponentHasTag((FName(TEXT("mesh")))))
					{
						DrawDebugLine(GetWorld(), GetActorLocation(), enemiesInRange[i]->GetSocketLocation(FName(TEXT("pelvisSocket"))), FColor(0, 255, 0), true, 0.1, 0, 10);

						if (currentTime > maxTime)
						{
							FVector directionVector = GetActorLocation() - enemiesInRange[i]->GetComponentLocation();

							enemiesInRange[i]->AddImpulse(directionVector * gravityPullStrength);
						}
					}




				}
				else 
				{
					GetWorld()->LineTraceSingleByChannel(actorVisibileHitResult, GetActorLocation(), enemiesInRange[i]->GetComponentLocation(), ECC_Visibility, CollisionParams);
					//DrawDebugLine(GetWorld(), GetActorLocation(), enemiesInRange[i]->GetComponentLocation(), FColor(255, 255, 0), true, 0.1, 0, 1);

					if (actorVisibileHitResult.bBlockingHit && actorVisibileHitResult.GetComponent()->IsSimulatingPhysics() && actorVisibileHitResult.GetActor()->ActorHasTag((FName(TEXT("box")))))
					{
						DrawDebugLine(GetWorld(), GetActorLocation(), enemiesInRange[i]->GetComponentLocation(), FColor(0, 255, 0), true, 0.1, 0, 10);

						if (currentTime > maxTime)
						{
							FVector directionVector = GetActorLocation() - enemiesInRange[i]->GetComponentLocation();

							enemiesInRange[i]->AddImpulse(directionVector * gravityPullStrength);
						}
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
