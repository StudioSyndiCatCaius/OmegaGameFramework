// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/OmegaSavedLevelSequence.h"

#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "Components/BillboardComponent.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Save.h"


const FName param_state="STATE_ACTIVE";;

AOmegaSavedLevelSequence::AOmegaSavedLevelSequence()
{
	RootComponent=CreateDefaultSubobject<UBillboardComponent>("ROOT");
	PrimaryActorTick.bCanEverTick = true;
}

void AOmegaSavedLevelSequence::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (!GUID.IsValid()) { GUID=FGuid::NewGuid(); }
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

FOmegaEntity* AOmegaSavedLevelSequence::L_GetEntity() const
{
	if (GetGameInstance())
	{
		return &OGF_Subsystems::oSave(this)->ActiveSaveData->Entities.Entities_Guid.FindOrAdd(GUID);
	}
	return nullptr;
}

void AOmegaSavedLevelSequence::SetSavedState(bool bState)
{
	if (FOmegaEntity* e = L_GetEntity())
	{
		if (GetSavedState()!=bState)
		{
			e->params_int32.Add(param_state,bState);
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
}

bool AOmegaSavedLevelSequence::GetSavedState() const
{
	if (FOmegaEntity* e = L_GetEntity())
	{
		return e->params_int32.FindOrAdd(param_state)>=1;
	}
	return false;
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

