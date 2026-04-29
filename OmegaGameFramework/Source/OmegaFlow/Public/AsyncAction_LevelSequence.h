// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"
#include "MovieSceneMarkedFrame.h"
#include "LevelSequenceActor.h"
#include "AsyncAction_LevelSequence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlaySequence, ALevelSequenceActor*, SequenceActor, FMovieSceneMarkedFrame, MarkedFrame);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAsyncLevelSequenceDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarkedFrame, ALevelSequenceActor*, SequenceActor, FMovieSceneMarkedFrame, MarkedFrame);

USTRUCT(BlueprintType,Blueprintable)
struct FOmegaLevelSequenceConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sequence") bool bOverrideInstance = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sequence") AActor* OriginActor = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sequence") FTransform OriginTransform;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sequence") TMap<FName,AActor*> ActorBindings;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sequence") bool bDuplicateSequence=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Sequence") bool bAutoDestroy=true;
	
};


UCLASS()
class OMEGAFLOW_API UAsyncAction_LevelSequence : public UBlueprintAsyncActionBase, public FTickableGameObject
{
	GENERATED_BODY()

public:
	bool b_tickActive=false;
	virtual void Tick(float DeltaTime) override;
	
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables );
	}
	virtual bool IsTickableWhenPaused() const
	{
		return true;
	}
	virtual bool IsTickableInEditor() const
	{
		return false;
	}
	// FTickableGameObject End

		
	UPROPERTY(BlueprintAssignable) FOnPlaySequence Play;
	UFUNCTION() void Local_Play();
	UPROPERTY(BlueprintAssignable) FOnAsyncLevelSequenceDelegate Finished;
	UFUNCTION() void Local_Finish();
	UPROPERTY(BlueprintAssignable) FOnAsyncLevelSequenceDelegate Stopped;
	UFUNCTION() void Local_Stop();
	UPROPERTY(BlueprintAssignable) FOnAsyncLevelSequenceDelegate OnFailed;
	UPROPERTY(BlueprintAssignable) FOnMarkedFrame OnMark;
	
	void L_Kill();
	bool b_killing=false;
	UPROPERTY() UObject* LocalContext = nullptr;
	UPROPERTY() ULevelSequence* LocalLevelSequence;
	UPROPERTY() ULevelSequencePlayer* LocalPlayer;
	UPROPERTY() ALevelSequenceActor* LocalSeqActor;
	UPROPERTY() FMovieSceneSequencePlaybackSettings LocalSettings;
	UPROPERTY() TMap<int32,FMovieSceneMarkedFrame> mapped_frames;
	UPROPERTY() TArray<int32> seen_frames;

	UPROPERTY() FOmegaLevelSequenceConfig L_config;
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|AsyncGameplayTasks", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="bOverrideInstanceData, OriginActor, OriginTransform"),
		DisplayName="Ω🔷 Play Level Sequence") 
	static UAsyncAction_LevelSequence* PlayLevelSequence(UObject* WorldContextObject, ULevelSequence* LevelSequence, FMovieSceneSequencePlaybackSettings Settings, FOmegaLevelSequenceConfig Config);
};
