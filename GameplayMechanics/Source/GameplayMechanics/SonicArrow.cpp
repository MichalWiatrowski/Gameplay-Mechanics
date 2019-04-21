// Fill out your copyright notice in the Description page of Project Settings.

#include "SonicArrow.h"

// Sets default values
ASonicArrow::ASonicArrow()
{
	// Set this actor to call Tick() every frame.You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	collisionComponent->OnComponentHit.AddDynamic(this, &ASonicArrow::OnHit);		// set up a notification for when this component hits something blocking

	sonicCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SonicComponent"));
	sonicCollisionComponent->InitSphereRadius(0.001f);
	sonicCollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	sonicCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	sonicCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASonicArrow::OnOverlapBegin);	
	sonicCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ASonicArrow::OnOverlapEnd);

	sonicCollisionComponent->SetupAttachment(RootComponent);

	
	// Die after 10 seconds by default
	InitialLifeSpan = 10.0f;
}

// Called when the game starts or when spawned
void ASonicArrow::BeginPlay()
{
	Super::BeginPlay();
}
void ASonicArrow::initArrow(float initialVelocity, float chargeTime, float sonicComponentRadius)
{
	projectileMovement->SetVelocityInLocalSpace(FVector(initialVelocity, 0, 0));
	sonicSphereRadius = sonicComponentRadius;
	chargedTime = chargeTime;
}
// Called every frame
void ASonicArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateArrowVelocityRotation();
}

void ASonicArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	sonicCollisionComponent->SetSphereRadius(sonicSphereRadius);
	
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
	
	arrowMesh->SetRenderCustomDepth(true);
	
}

void ASonicArrow::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor && (OtherActor != this) && (OtherActor->ActorHasTag(FName(TEXT("enemy"))) || OtherActor->ActorHasTag(FName(TEXT("arrow")))))
	{
		OtherComp->SetRenderCustomDepth(true);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
		OtherComp->CustomDepthStencilValue = 1;
	
	}
}
void ASonicArrow::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && (OtherActor->ActorHasTag(FName(TEXT("enemy"))) || OtherActor->ActorHasTag(FName(TEXT("arrow")))))
	{
		OtherComp->SetRenderCustomDepth(false);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
		OtherComp->CustomDepthStencilValue = 0;
	}
}
