// Fill out your copyright notice in the Description page of Project Settings.

#include "SonicArrow.h"

// Sets default values
ASonicArrow::ASonicArrow()
{
	// Set this actor to call Tick() every frame.You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	collisionComponent->OnComponentHit.AddDynamic(this, &ASonicArrow::OnHit);		// set up a notification for when this component hits something blocking

	sonicCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SonicComponent"));
	sonicCollisionComponent->InitSphereRadius(0.01f);
	sonicCollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	sonicCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	sonicCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASonicArrow::OnOverlapBegin);	
	sonicCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ASonicArrow::OnOverlapEnd);

	sonicCollisionComponent->SetupAttachment(RootComponent);

	arrowMesh->SetRenderCustomDepth(true);
	arrowMesh->CustomDepthStencilValue = 255;
	// Die after 10 seconds by default
	InitialLifeSpan = 10.0f;
}

// Called when the game starts or when spawned
void ASonicArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASonicArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	updateArrowVelocityRotation();


	
}



void ASonicArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	sonicCollisionComponent->SetSphereRadius(1000.0f);
	
	//projectileMovement->StopMovementImmediately();
	RootComponent->AttachTo(OtherComp, NAME_None, EAttachLocation::KeepWorldPosition, false);
	
}




void ASonicArrow::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->SetRenderCustomDepth(true);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
		OtherComp->CustomDepthStencilValue = 1;
	
	}
}
void ASonicArrow::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->SetRenderCustomDepth(false);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
		OtherComp->CustomDepthStencilValue = 0;
	}
}
