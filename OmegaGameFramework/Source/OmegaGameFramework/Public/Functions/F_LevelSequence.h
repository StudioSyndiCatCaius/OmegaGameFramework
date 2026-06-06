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
	
	//UFUNCTION(BlueprintPure,Category="Omega|Animation")
	//static FMovieSceneMarkedFrame SelectFrameByName(ULevelSequence* LevelSequence, FString MarkName);

	UFUNCTION(BlueprintCallable,Category="Omega|LevelSequence",meta=(ExpandBoolAsExecs="result"),DisplayName="Sequence - Has Mark?")
	static FMovieSceneMarkedFrame DoesSequenceHaveMark(ULevelSequence* Sequence, const FString& Mark, bool& result);
};
