// Fill out your copyright notice in the Description page of Project Settings.

#include "ScatterArrow.h"

// Sets default values
AScatterArrow::AScatterArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	collisionComponent->InitSphereRadius(1.0f);
	collisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	collisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	collisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	collisionComponent->OnComponentHit.AddDynamic(this, &AScatterArrow::OnHit);		// set up a notification for when this component hits something blocking



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
		arrowMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		//offset the mesh so the sphere collider component is just behind the the tip of the mesh to give the effect of the tip going into an object
		arrowMesh->SetRelativeLocation(FVector(-35.0f, 1.0f, -3.0f));
		arrowMesh->SetRelativeRotation(FRotator(0, -90, 0));
		arrowMesh->SetWorldScale3D(FVector(1.0f));

	}
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

void AScatterArrow::updateArrowVelocityRotation()
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

void AScatterArrow::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//// Only add impulse and destroy projectile if we hit a physics
	//if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	//{
	//	OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	//}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("HIT HIT HIT WOWOWOWOWOWO")));
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
	//for (int i = 0; i < 8; i++)
	//{


	//	FVector oneLOL = (((GetActorForwardVector() * Hit.Normal) * -2) * Hit.Normal) + GetActorForwardVector();



	//	UKismetMathLibrary::BreakRotator(UKismetMathLibrary::MakeRotFromX(oneLOL), arrowAxes.X, arrowAxes.Y, arrowAxes.Z);
	//	

	//
	//	FRotator SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z - ((-5 + i ) * 2));

	//	

	//	newArrow[i]= GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	//	newArrow[i]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));

	//	
	//}
	FVector oneLOL = (((GetActorForwardVector() * Hit.Normal) * -2) * Hit.Normal) + GetActorForwardVector();
	UKismetMathLibrary::BreakRotator(UKismetMathLibrary::MakeRotFromX(oneLOL), arrowAxes.X, arrowAxes.Y, arrowAxes.Z);
	FRotator SpawnRotation;



	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z - 30);



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





	SpawnRotation = UKismetMathLibrary::MakeRotator(arrowAxes.X, arrowAxes.Y, arrowAxes.Z +30);



	newArrow[0] = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	newArrow[0]->projectileMovement->SetVelocityInLocalSpace(FVector(maxSpeed, 0, 0));









	/*float maxSpeed = 3000;
	FVector idk = UKismetMathLibrary::GetReflectionVector((GetActorLocation() - Hit.ImpactPoint), Hit.ImpactNormal);

	FRotator SpawnRotation = UKismetMathLibrary::MakeRotator(idk.X, idk.Y, idk.Z);
	SetActorRotation(SpawnRotation);

	maxSpeed = 3000;*/
}