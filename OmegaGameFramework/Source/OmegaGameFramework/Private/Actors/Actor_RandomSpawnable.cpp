// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_RandomSpawnable.h"

#include "Algo/RandomShuffle.h"
#include "Components/ChildActorComponent.h"
#include "Components/SphereComponent.h"
#include "Functions/F_GlobalParam.h"
#include "Kismet/KismetMathLibrary.h"


TSubclassOf<AActor> FOmegaRandomSpawnableConfig::RandomizeActorToSpawn(int32 seed)
{
	while (true)
	{
		TArray<TSubclassOf<AActor>> actors;
		SpawnableActors.GetKeys(actors);
		Algo::RandomShuffle(actors);
	
		for (auto actor : actors)
		{
			FRandomStream stream=FRandomStream(seed);
			float chance=stream.FRand();
			if (chance <= SpawnableActors[actor])
			{
				return actor;
			}
		}
	}
	return nullptr;
}

AOmega_RandomSpawnable::AOmega_RandomSpawnable()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("RootComponent");
	ChildActorComponent=CreateOptionalDefaultSubobject<UChildActorComponent>("ChildActorComponent");
	ChildActorComponent->SetupAttachment(RootComponent);
}

void AOmega_RandomSpawnable::BeginPlay()
{
	int32 in_seed=UOmegaFunctions_GlobalVars::GetGlobalVariable_Int32(this,Seed_GlobalParamSource,Seed_GlobalParamName);
	Super::BeginPlay();
	FRandomStream stream=FRandomStream(in_seed+2346);
	float chance=stream.FRand();
	if (chance <= SpawnableConfig.SpawnChance)
	{
		ChildActorComponent->SetChildActorClass(SpawnableConfig.RandomizeActorToSpawn(in_seed));
	}
	else
	{
		ChildActorComponent->SetChildActorClass(nullptr);
	}
}

void AOmega_RandomSpawnable::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	TArray<TSubclassOf<AActor>> actors;
	SpawnableConfig.SpawnableActors.GetKeys(actors);
	ChildActorComponent->SetChildActorClass(nullptr);
	if (actors.IsValidIndex(Preview))
	{
		if (TSubclassOf<AActor> a = actors[Preview])
		{
			ChildActorComponent->SetChildActorClass(a);
		}
	}
	
}
