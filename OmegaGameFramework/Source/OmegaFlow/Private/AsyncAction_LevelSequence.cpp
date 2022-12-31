// Fill out your copyright notice in the Description page of Project Settings.

#include "AsyncAction_LevelSequence.h"

#include "LevelSequence/Public/DefaultLevelSequenceInstanceData.h"


void UAsyncAction_LevelSequence::Local_Play()
{
	LocalPlayer->Play();
	Play.Broadcast(LocalSeqActor);
}

void UAsyncAction_LevelSequence::Local_Finish()
{
	Finished.Broadcast();
}

void UAsyncAction_LevelSequence::Local_Stop()
{
	Stopped.Broadcast();
}

void UAsyncAction_LevelSequence::Activate()
{
	if(!LocalContext->GetWorld() || !LocalLevelSequence) //Fail of invalid world
	{
		OnFailed.Broadcast();
		SetReadyToDestroy();
	}
	
	LocalPlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(LocalContext, LocalLevelSequence, LocalSettings, LocalSeqActor);
	
	if(!LocalPlayer)
	{
		OnFailed.Broadcast();
		SetReadyToDestroy();
	}
	
	if(Local_OverrideInstanceData)
	{
		LocalSeqActor->bOverrideInstanceData = Local_OverrideInstanceData;
		UDefaultLevelSequenceInstanceData* TempSeqData = Cast<UDefaultLevelSequenceInstanceData>(LocalSeqActor->DefaultInstanceData);

		if(LocalSeqActor)
		{
			TempSeqData->TransformOriginActor = Local_OriginActor;
		}
		TempSeqData->TransformOrigin = Local_OriginTransform;
	}
	
	LocalPlayer->OnFinished.AddDynamic(this, &UAsyncAction_LevelSequence::Local_Finish);
	LocalPlayer->OnStop.AddDynamic(this, &UAsyncAction_LevelSequence::Local_Stop);

	Local_Play();
}

UAsyncAction_LevelSequence* UAsyncAction_LevelSequence::PlayLevelSequence(UObject* WorldContextObject,
	ULevelSequence* LevelSequence, FMovieSceneSequencePlaybackSettings Settings, bool bOverrideInstanceData,
	AActor* OriginActor, FTransform OriginTransform)
{
	UAsyncAction_LevelSequence* NewSeq = NewObject<UAsyncAction_LevelSequence>();

	if(WorldContextObject)
	{
		NewSeq->LocalContext = WorldContextObject;
	}
	if(OriginActor)
	{
		NewSeq->Local_OriginActor = OriginActor;
	}
	if(LevelSequence)
	{
		NewSeq->LocalLevelSequence = LevelSequence;
	}
	NewSeq->LocalLevelSequence = LevelSequence;
	NewSeq->LocalSettings = Settings;
	NewSeq->Local_OverrideInstanceData = bOverrideInstanceData;
	NewSeq->Local_OriginTransform = OriginTransform;
	
	return NewSeq;
	
}
