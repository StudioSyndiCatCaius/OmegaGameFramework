// Fill out your copyright notice in the Description page of Project Settings.

#include "AsyncAction_LevelSequence.h"
#include "ExtensionLibraries/MovieSceneSequenceExtensions.h"
#include "MovieSceneSequence.h"
#include "Runtime/LevelSequence/Public/DefaultLevelSequenceInstanceData.h"


void UAsyncAction_LevelSequence::Tick(float DeltaTime)
{
	if (!b_tickActive) { return; }
	if(LocalPlayer)
	{
		if (LocalPlayer->IsPlaying())
		{
			FQualifiedFrameTime time_frame= LocalPlayer->GetCurrentTime();
			int32 frame=time_frame.Time.FrameNumber.Value;
		
			//UE_LOG(LogTemp, Warning, TEXT("Ticked frame at %s"), *FString::FromInt(frame));
			if(!seen_frames.Contains(frame) && mapped_frames.Contains(frame))
			{
				seen_frames.Add(frame);
				if (LocalSeqActor)
				{
					OnMark.Broadcast(LocalSeqActor,mapped_frames[frame]);	
				}
			}
		}
		else
		{
			b_tickActive=false;
		}
	}
	else
	{
		b_tickActive=false;
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
	L_Kill();
}

void UAsyncAction_LevelSequence::Local_Stop()
{
	Stopped.Broadcast();
	L_Kill();
}

void UAsyncAction_LevelSequence::L_Kill()
{
	if (!b_killing)
	{
		b_tickActive = false;
		b_killing = true;
		if (L_config.bAutoDestroy && IsValid(LocalSeqActor))
		{
			// Defer destruction by one tick. Destroying the actor synchronously inside
			// OnFinished/OnStop crashes because StopInternal() is still on the callstack
			// holding a reference to the SequenceTickManager, which the actor owns.
			// Destroying it immediately nulls the TickManager, causing an ensure failure.
			ALevelSequenceActor* ActorToDestroy = LocalSeqActor;
			if (UWorld* World = ActorToDestroy->GetWorld())
			{
				World->GetTimerManager().SetTimerForNextTick([ActorToDestroy]()
				{
					if (IsValid(ActorToDestroy))
					{
						ActorToDestroy->K2_DestroyActor();
					}
				});
			}
		}
	}
}

void UAsyncAction_LevelSequence::Activate()
{
	if(!LocalContext->GetWorld() || !LocalLevelSequence)
	{
		OnFailed.Broadcast();
		L_Kill();
		return;
	}

	LocalPlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(LocalContext, LocalLevelSequence, LocalSettings, LocalSeqActor);

	if(!LocalPlayer)
	{
		OnFailed.Broadcast();
		L_Kill();
		return;
	}

	if(!LocalSeqActor)
	{
		OnFailed.Broadcast();
		L_Kill();
		return;
	}

	if(L_config.bOverrideInstance)
	{
		LocalSeqActor->bOverrideInstanceData = true;
		UDefaultLevelSequenceInstanceData* TempSeqData = Cast<UDefaultLevelSequenceInstanceData>(LocalSeqActor->DefaultInstanceData);
		if(TempSeqData)
		{
			TempSeqData->TransformOriginActor = L_config.OriginActor;
			TempSeqData->TransformOrigin = L_config.OriginTransform;
		}
	}

	LocalPlayer->OnFinished.AddDynamic(this, &UAsyncAction_LevelSequence::Local_Finish);
	LocalPlayer->OnStop.AddDynamic(this, &UAsyncAction_LevelSequence::Local_Stop);

	TArray<FName> Bind_list;
	L_config.ActorBindings.GetKeys(Bind_list);
	for (FName name : Bind_list)
	{
		if (AActor* a = L_config.ActorBindings[name])
		{
			LocalSeqActor->AddBindingByTag(name, a);
		}
	}
	b_tickActive = true;
	Local_Play();
}


UAsyncAction_LevelSequence* UAsyncAction_LevelSequence::PlayLevelSequence(UObject* WorldContextObject,
                                                                          ULevelSequence* LevelSequence, FMovieSceneSequencePlaybackSettings Settings, FOmegaLevelSequenceConfig Config)
{
	if (!WorldContextObject) { return nullptr; }
	UAsyncAction_LevelSequence* NewSeq = NewObject<UAsyncAction_LevelSequence>();

	if(WorldContextObject)
	{
		NewSeq->LocalContext = WorldContextObject;
	}
		
	NewSeq->L_config=Config;
	if (LevelSequence)
	{
		if (Config.bDuplicateSequence)
		{
			NewSeq->LocalLevelSequence = DuplicateObject(LevelSequence,NewSeq);
		}
		else
		{
			NewSeq->LocalLevelSequence = LevelSequence;
		}
		TArray<FMovieSceneMarkedFrame> loc_frames = NewSeq->LocalLevelSequence->GetMovieScene()->GetMarkedFrames();
		for(FMovieSceneMarkedFrame TempFrame: loc_frames)
		{
			UMovieScene* MovieScene=NewSeq->LocalLevelSequence->GetMovieScene();
			TempFrame.FrameNumber = FFrameRate::TransformTime(TempFrame.FrameNumber, MovieScene->GetTickResolution(), MovieScene->GetDisplayRate()).RoundToFrame();
			UE_LOG(LogTemp, Warning, TEXT("Mapped Mark from at %s"), *FString::FromInt(TempFrame.FrameNumber.Value));
	
			NewSeq->mapped_frames.Add(TempFrame.FrameNumber.Value,TempFrame);
		}
	}
	NewSeq->LocalSettings = Settings;
		
	return NewSeq;
}
