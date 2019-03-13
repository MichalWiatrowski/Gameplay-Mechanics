// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyingArrow.h"

// Sets default values
AFlyingArrow::AFlyingArrow()
{


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	collisionComponent->InitSphereRadius(1.0f);
	collisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	collisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	collisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	collisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Block);
	collisionComponent->OnComponentHit.AddDynamic(this, &AFlyingArrow::OnHit);		// set up a notification for when this component hits something blocking
	//collisionComponent->SetSimulatePhysics(true);


	// Set as root component
	RootComponent = collisionComponent;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	projectileMovement->UpdatedComponent = collisionComponent;
	projectileMovement->InitialSpeed = 0.f;
	projectileMovement->MaxSpeed = 0.f;
	projectileMovement->bRotationFollowsVelocity = true;
	projectileMovement->bInitialVelocityInLocalSpace = true;
	projectileMovement->bShouldBounce = true;
	projectileMovement->Bounciness = 0;



	// Die after 10 seconds by default

	InitialLifeSpan = 10.0f;
	arrowMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));

	arrowMesh->SetupAttachment(RootComponent);
	//ArrowVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> arrowMeshAsset(TEXT("/Game/arrowMesh.arrowMesh"));
	if (arrowMeshAsset.Succeeded())
	{
		arrowMesh->SetStaticMesh(arrowMeshAsset.Object);
		//offset the mesh so the sphere collider component is just behind the the tip of the mesh to give the effect of the tip going into an object
		arrowMesh->SetRelativeLocation(FVector(-35.0f, 1.0f, -3.0f));
		arrowMesh->SetRelativeRotation(FRotator(0, -90, 0));
		arrowMesh->SetWorldScale3D(FVector(1.0f));
		arrowMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	}

}

// Called when the game starts or when spawned
void AFlyingArrow::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFlyingArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugLine(GetWorld(), lastPosition, GetActorLocation(), FColor(0, 0, 255), true, -1, 0, 12.333);

	//execute the rotation function
	updateArrowVelocityRotation();


	lastPosition = GetActorLocation();

}

void AFlyingArrow::updateArrowVelocityRotation()
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
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), GetVelocity().X));
	}

}
void AFlyingArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	if (numberOfBounces > 5)
		Destroy();
	else
		numberOfBounces++;

	float maxSpeed = 3000;
	UWorld* const World = GetWorld();

	FVector arrowAxes;








	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();

	}







	FVector oneLOL = (((GetActorForwardVector() * Hit.Normal) * -3) * Hit.Normal) + GetActorForwardVector();

	SetActorRotation(UKismetMathLibrary::MakeRotFromX(oneLOL));



	projectileMovement->SetVelocityInLocalSpace(FVector(3000, 0, 0));



	maxSpeed = 3000;
}

