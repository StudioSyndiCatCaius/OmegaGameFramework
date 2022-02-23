// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "OmegaSaveGlobal.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveGlobal : public USaveGame
{
	GENERATED_BODY()


public:
	//GamePreferences
	UPROPERTY()
	TMap<class UGamePreferenceBool*, bool> BoolPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceFloat*, float> FloatPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceString*, FString> StringPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceTag*, FGameplayTag> TagPrefs;

	UPROPERTY(BlueprintReadWrite, Category="GameplayTags")
	FGameplayTagContainer GlobalSaveTags;

	
	
};
