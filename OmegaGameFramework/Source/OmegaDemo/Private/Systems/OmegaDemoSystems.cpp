// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/OmegaDemoSystems.h"


// Sets default values
AOmegaDemoSystems::AOmegaDemoSystems()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOmegaDemoSystems::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOmegaDemoSystems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOmegaDemoSystems::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	Super::SystemActivated_Implementation(Context, Flag);
}

