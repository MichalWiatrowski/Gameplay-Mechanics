// Fill out your copyright notice in the Description page of Project Settings.

#include "SonicArrow.h"

// Sets default values
ASonicArrow::ASonicArrow()
{
	// Set this actor to call Tick() every frame.You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;

	collisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	collisionComponent->InitSphereRadius(1.0f);
	collisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	collisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	collisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	collisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
	collisionComponent->OnComponentHit.AddDynamic(this, &ASonicArrow::OnHit);		// set up a notification for when this component hits something blocking

	// Set as root component
	RootComponent = collisionComponent;


	sonicCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SonicComponent"));
	sonicCollisionComponent->InitSphereRadius(1000.0f);

	sonicCollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	sonicCollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	sonicCollisionComponent->Deactivate();
	
	
	sonicCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASonicArrow::OnOverlapBegin);	
	sonicCollisionComponent->OnComponentEndOverlap.AddDynamic(this, &ASonicArrow::OnOverlapEnd);	// set up a notification for when this component hits something blocking

	sonicCollisionComponent->SetupAttachment(RootComponent);


	// Use a ProjectileMovementComponent to govern this projectile's movement
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	projectileMovement->UpdatedComponent = collisionComponent;
	projectileMovement->InitialSpeed = 0.f;
	projectileMovement->MaxSpeed = 0.f;
	projectileMovement->bRotationFollowsVelocity = false;
	projectileMovement->bInitialVelocityInLocalSpace = true;
	projectileMovement->bShouldBounce = false;


	// Die after 10 seconds by default

	InitialLifeSpan = 10.0f;
	arrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));

	arrowMesh->SetupAttachment(RootComponent);
	//ArrowVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> arrowMeshAsset(TEXT("/Game/arrowMesh.arrowMesh"));
	if (arrowMeshAsset.Succeeded())
	{
		arrowMesh->SetStaticMesh(arrowMeshAsset.Object);
		arrowMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		//offset the mesh so the sphere collider component is just behind the the tip of the mesh to give the effect of the tip going into an object
		arrowMesh->SetRelativeLocation(FVector(-35.0f, 1.0f, -3.0f));
		arrowMesh->SetRelativeRotation(FRotator(0, -90, 0));
		arrowMesh->SetWorldScale3D(FVector(1.0f));

	}



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

	if (hitLOL == true)
	DrawDebugSphere(GetWorld(), GetActorLocation(), sonicCollisionComponent->GetScaledSphereRadius(), 32, FColor(0, 0, 255), true, 0.01, 0, 5);
}

void ASonicArrow::updateArrowVelocityRotation()
{
	//get velocity of the actor and if it isnt 0 in any direction, apply rotation based on the velocity
	//this is to enable the effect of the arrow penetrating and getting stuck inside an object, wall etc
	if (GetVelocity() != FVector(0, 0, 0))
	{
		FRotator currentRotation = GetActorRotation();
		FRotator rotationFromVelocity = UKismetMathLibrary::MakeRotFromX(GetVelocity());


		FVector velocityAxes;
		FVector actorAxes;

		FRotator finalRotation;




		UKismetMathLibrary::BreakRotator(rotationFromVelocity, velocityAxes.X, velocityAxes.Y, velocityAxes.Z);
		UKismetMathLibrary::BreakRotator(currentRotation, actorAxes.X, actorAxes.Y, actorAxes.Z);

		finalRotation = UKismetMathLibrary::MakeRotator(actorAxes.X, velocityAxes.Y, actorAxes.Z);

		SetActorRotation(finalRotation);
	}

}

void ASonicArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	hitLOL = true;
	//DrawDebugSphere(GetWorld(), GetActorLocation(), sonicCollisionComponent->GetScaledSphereRadius(), 32, FColor(0, 0, 255), true, 0.1, 0, 5);
	sonicCollisionComponent->Activate();
}




void ASonicArrow::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->SetRenderCustomDepth(true);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
	}
}
void ASonicArrow::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->SetRenderCustomDepth(false);
		OtherComp->SetVisibility(false);
		OtherComp->SetVisibility(true);
	}
}
