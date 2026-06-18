// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/sys_TurnBasedCombat.h"

#include "LevelSequence.h"
#include "LevelSequencePlayer.h"


// Sets default values
AOmegaDemoSystem_TurnBasedCombat::AOmegaDemoSystem_TurnBasedCombat()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOmegaDemoSystem_TurnBasedCombat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOmegaDemoSystem_TurnBasedCombat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOmegaDemoSystem_TurnBasedCombat::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	Super::SystemActivated_Implementation(Context, Flag);
}
