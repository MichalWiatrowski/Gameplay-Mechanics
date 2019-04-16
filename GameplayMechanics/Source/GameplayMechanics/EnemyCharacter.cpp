// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	/*collisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	collisionComponent->SetBoxExtent(FVector(50, 50, 50));
	collisionComponent->BodyInstance.SetCollisionProfileName("PhysicsActor");
	collisionComponent->SetMaterial(0, enemyMaterial);
	RootComponent = collisionComponent;*/



	boxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	//ArrowVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> boxMeshAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	if (boxMeshAsset.Succeeded())
	{
		boxMesh->SetStaticMesh(boxMeshAsset.Object);
		
		RootComponent = boxMesh;
		
		//offset the mesh so the sphere collider component is just behind the the tip of the mesh to give the effect of the tip going into an object
		//boxMesh->SetRelativeLocation(FVector(-35.0f, 1.0f, -3.0f));
		//boxMesh->SetRelativeRotation(FRotator(0, -90, 0));
		//boxMesh->SetWorldScale3D(FVector(1.0f));
		//boxMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	}
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

