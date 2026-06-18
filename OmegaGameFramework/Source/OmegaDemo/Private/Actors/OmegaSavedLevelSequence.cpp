// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OmegaSavedLevelSequence.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "Components/BillboardComponent.h"
#include "Functions/F_GlobalParam.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Save.h"

const uint8 FLAG_SAVEDSEQ_FINISHED=1;
const FName param_state="STATE_ACTIVE";

AOmegaSavedLevelSequence::AOmegaSavedLevelSequence()
{
	RootComponent=CreateDefaultSubobject<UBillboardComponent>("ROOT");
	PrimaryActorTick.bCanEverTick = true;
}

void AOmegaSavedLevelSequence::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}


void AOmegaSavedLevelSequence::BeginPlay()
{
	Super::BeginPlay();
	if (LevelSequence)
	{
		FMovieSceneSequencePlaybackSettings set;
		ULevelSequencePlayer::CreateLevelSequencePlayer(this,LevelSequence,set,LevelSequenceActor);	
	}
	
	if (GetSavedState())
	{
		if (LevelSequenceActor)
		{
			LevelSequenceActor->GetSequencePlayer()->GoToEndAndStop();
		}
	}
	
}


void AOmegaSavedLevelSequence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (LevelSequenceActor && b_isPlaying)
	{
		if (!LevelSequenceActor->GetSequencePlayer()->IsPlaying())
		{
			b_isPlaying=false;
			OnPlayingStateChange.Broadcast(this,false);
		}
	}
}

void AOmegaSavedLevelSequence::SetSavedState(bool bState)
{
	if (GetSavedState()!=bState)
	{
		SetGuidflagValue(FLAG_SAVEDSEQ_FINISHED,bState);
		OnStateChange.Broadcast(this,bState);
		if (LevelSequenceActor)
		{
			if (bState)
			{
				LevelSequenceActor->GetSequencePlayer()->Play();
			}
			else
			{
				LevelSequenceActor->GetSequencePlayer()->PlayReverse();
			}
			b_isPlaying=true;
			OnPlayingStateChange.Broadcast(this,true);
		}
	}
	
}

bool AOmegaSavedLevelSequence::GetSavedState()
{
	return GetGuidflagValue(FLAG_SAVEDSEQ_FINISHED);
}

// ---------------------------------------------------------------------------------------------------------------------
// FLOW NODE
// ---------------------------------------------------------------------------------------------------------------------

UFlowNode_PlaySavedLevelSequence::UFlowNode_PlaySavedLevelSequence()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Finished")));
}

void UFlowNode_PlaySavedLevelSequence::L_OnPlayFinish(AOmegaSavedLevelSequence* Actor, bool bNewState)
{
	if (!bNewState)
	{
		if (AOmegaSavedLevelSequence* seq=LevelSequenceActor.LoadSynchronous())
		{
			seq->OnPlayingStateChange.RemoveDynamic(this,&UFlowNode_PlaySavedLevelSequence::L_OnPlayFinish);
		}
		TriggerFirstOutput(true);
	}
}

void UFlowNode_PlaySavedLevelSequence::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if (AOmegaSavedLevelSequence* seq=LevelSequenceActor.LoadSynchronous())
	{
		seq->OnPlayingStateChange.AddDynamic(this,&UFlowNode_PlaySavedLevelSequence::L_OnPlayFinish);
		seq->SetSavedState(bTargetState);
	}
	else
	{
		TriggerFirstOutput(true);
	}
}

