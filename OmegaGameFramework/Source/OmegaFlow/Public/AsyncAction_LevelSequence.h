// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"
#include "LevelSequenceActor.h"
#include "AsyncAction_LevelSequence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlaySequence, ALevelSequenceActor*, SequenceActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishedSequence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStoppedSequence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailedPlay);

UCLASS()
class OMEGAFLOW_API UAsyncAction_LevelSequence : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPlaySequence Play;
	UFUNCTION()
	void Local_Play();
	
	UPROPERTY(BlueprintAssignable)
	FOnFinishedSequence Finished;
	UFUNCTION()
	void Local_Finish();
	
	UPROPERTY(BlueprintAssignable)
	FOnStoppedSequence Stopped;
	UFUNCTION()
	void Local_Stop();
	
	UPROPERTY(BlueprintAssignable)
	FOnFailedPlay OnFailed;
	
	UPROPERTY()
	UObject* LocalContext = nullptr;
	UPROPERTY()
	ULevelSequence* LocalLevelSequence;
	UPROPERTY()
	ULevelSequencePlayer* LocalPlayer;
	UPROPERTY()
	ALevelSequenceActor* LocalSeqActor;
	UPROPERTY()
	FMovieSceneSequencePlaybackSettings LocalSettings;

	UPROPERTY()
	bool Local_OverrideInstanceData;
	UPROPERTY()
	AActor* Local_OriginActor;
	UPROPERTY()
	FTransform Local_OriginTransform;
	
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="bOverrideInstanceData, OriginActor, OriginTransform")) 
	static UAsyncAction_LevelSequence* PlayLevelSequence(UObject* WorldContextObject, ULevelSequence* LevelSequence, FMovieSceneSequencePlaybackSettings Settings, bool bOverrideInstanceData, AActor* OriginActor, FTransform OriginTransform);
};
