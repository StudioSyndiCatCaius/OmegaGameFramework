// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MovieSceneMarkedFrame.h"
#include "UObject/Interface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_LevelSequence.generated.h"




class ULevelSequence;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelSequenceFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	
	UFUNCTION(BlueprintCallable,Category="Omega|LevelSequence",meta=(ExpandBoolAsExecs="result"),DisplayName="Sequence - Has Mark?")
	static FMovieSceneMarkedFrame DoesSequenceHaveMark(ULevelSequence* Sequence, const FString& Mark, bool& result);
	
	//Get the marked frame (by label) time in the sequence (offset from the start) (search starting from the StartTime)
	UFUNCTION(BlueprintCallable,Category="Omega|LevelSequence",DisplayName="Sequence - Get Marked Frame Time")
	static float GetMarkedFrameTime(ULevelSequence* Sequence, const FString& Mark, float StartTime=0.0);
};
