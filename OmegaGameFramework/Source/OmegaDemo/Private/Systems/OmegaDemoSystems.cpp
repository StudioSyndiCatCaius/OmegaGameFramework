// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/OmegaDemoSystems.h"

#include "LevelSequence.h"
#include "LevelSequencePlayer.h"


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

// =====================================================================================================================
// Turn Based Combat
// =====================================================================================================================
ADemoSystem_TurnBasedCombat::ADemoSystem_TurnBasedCombat()
{
}

void ADemoSystem_TurnBasedCombat::BeginPlay()
{
	Super::BeginPlay();
}

void ADemoSystem_TurnBasedCombat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADemoSystem_TurnBasedCombat::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	Super::SystemActivated_Implementation(Context, Flag);
}


void ADemoSystem_TurnBasedCombat::RandSequenceEnded()
{
	switch (sequence_state)
	{
		case 0:
		break;
	default: ;
	}
}

void ADemoSystem_TurnBasedCombat::PlayRandomSequence(TArray<TObjectPtr<ULevelSequence>> sequenceList, uint8 state)
{
	sequence_state = state;
	
	int32 RandomIndex = FMath::RandRange(0, sequenceList.Num() - 1);
	
	if (sequenceList.Contains(RandomIndex))
	{
		ULevelSequence* s=sequenceList[RandomIndex];
		FMovieSceneSequencePlaybackSettings Settings = FMovieSceneSequencePlaybackSettings();
		ALevelSequenceActor* SeqActor;
		ULevelSequencePlayer* seqPlayer=ULevelSequencePlayer::CreateLevelSequencePlayer(this,s,Settings,SeqActor);
		seqPlayer->OnFinished.AddDynamic(this,&ADemoSystem_TurnBasedCombat::RandSequenceEnded);
	}
	else
	{
		RandSequenceEnded();
	}
	
}

