// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LevelSequence.h"
#include "MovieSceneMarkedFrame.h"
#include "UObject/Interface.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaFunctions_LevelSequence.generated.h"




UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelSequenceFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	//UFUNCTION(BlueprintPure,Category="Omega|Animation")
	//static FMovieSceneMarkedFrame SelectFrameByName(ULevelSequence* LevelSequence, FString MarkName);

	UFUNCTION(BlueprintCallable,Category="Omega|LevelSequence",meta=(ExpandBoolAsExecs="result"))
	static FMovieSceneMarkedFrame DoesSequenceHaveMark(ULevelSequence* Sequence, const FString& Mark, bool& result);
};
