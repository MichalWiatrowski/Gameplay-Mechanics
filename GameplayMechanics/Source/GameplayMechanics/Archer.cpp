// Fill out your copyright notice in the Description page of Project Settings.

#include "Archer.h"

// Sets default values
AArcher::AArcher()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArcher::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::LeftMouseButton))
	{
		UWorld* const World = GetWorld();

		const FRotator SpawnRotation = GetControlRotation();

		const FVector SpawnLocation = GetActorLocation();
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		//World->SpawnActor<AGameplayMechanicsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);



		AFlyingArrow* newArrow = GetWorld()->SpawnActor<AFlyingArrow>(AFlyingArrow::StaticClass(), SpawnLocation, SpawnRotation, ActorSpawnParams);
	}

}

// Called to bind functionality to input
void AArcher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

