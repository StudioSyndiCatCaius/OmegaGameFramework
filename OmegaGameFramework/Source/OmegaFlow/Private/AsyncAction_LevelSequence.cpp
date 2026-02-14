// Fill out your copyright notice in the Description page of Project Settings.

#include "AsyncAction_LevelSequence.h"
#include "ExtensionLibraries/MovieSceneSequenceExtensions.h"
#include "MovieSceneSequence.h"
#include "Runtime/LevelSequence/Public/DefaultLevelSequenceInstanceData.h"


void UAsyncAction_LevelSequence::Tick(float DeltaTime)
{
	if(LocalPlayer)
	{
		FQualifiedFrameTime time_frame= LocalPlayer->GetCurrentTime();
		int32 frame=time_frame.Time.FrameNumber.Value;
		
		//UE_LOG(LogTemp, Warning, TEXT("Ticked frame at %s"), *FString::FromInt(frame));
		if(!seen_frames.Contains(frame) && mapped_frames.Contains(frame))
		{
			seen_frames.Add(frame);
			OnMark.Broadcast(LocalSeqActor,mapped_frames[frame]);
		}
	}
}

void UAsyncAction_LevelSequence::Local_Play()
{
	seen_frames.Empty();
	LocalPlayer->Play();
	Play.Broadcast(LocalSeqActor,FMovieSceneMarkedFrame());
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
	if(LocalSeqActor)
	{
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
	else
	{
		OnFailed.Broadcast();
		SetReadyToDestroy();
	}
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

	TArray<FMovieSceneMarkedFrame> loc_frames = LevelSequence->GetMovieScene()->GetMarkedFrames();
	for(FMovieSceneMarkedFrame TempFrame: loc_frames)
	{
		UMovieScene* MovieScene=LevelSequence->GetMovieScene();
		TempFrame.FrameNumber = FFrameRate::TransformTime(TempFrame.FrameNumber, MovieScene->GetTickResolution(), MovieScene->GetDisplayRate()).RoundToFrame();
		UE_LOG(LogTemp, Warning, TEXT("Mapped Mark from at %s"), *FString::FromInt(TempFrame.FrameNumber.Value));
	
		NewSeq->mapped_frames.Add(TempFrame.FrameNumber.Value,TempFrame);
	}
	
	return NewSeq;
}
