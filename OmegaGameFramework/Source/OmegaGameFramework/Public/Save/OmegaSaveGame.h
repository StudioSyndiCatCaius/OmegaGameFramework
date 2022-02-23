// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "DataInterface_General.h"
#include "UObject/SoftObjectPath.h"

#include "OmegaSaveGame.generated.h"

class UWorld;
class UGameInstance;

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveGame : public USaveGame, public IDataInterface_General
{
	GENERATED_BODY()

public:

		UPROPERTY()
		FString ActiveLevelName;

		UPROPERTY()
		FTransform SavedPlayerTransform;

	UFUNCTION(BlueprintImplementableEvent, Category="Save")
	void OnGameStarted(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Save")
	FText GetDisplayName();
	

		//GamePreferences
		UPROPERTY()
			TMap<class UGamePreferenceBool*, bool> BoolPrefs;
		UPROPERTY()
			TMap<class UGamePreferenceFloat*, float> FloatPrefs;
		UPROPERTY()
			TMap<class UGamePreferenceString*, FString> StringPrefs;
		UPROPERTY()
			TMap<class UGamePreferenceTag*, FGameplayTag> TagPrefs;

	//Tags
		UPROPERTY(BlueprintReadWrite, Category="Tags")
		FGameplayTag StoryState;
	
		UPROPERTY(BlueprintReadWrite, Category="Tags")
		FGameplayTagContainer StoryTags;
	
		UPROPERTY(BlueprintReadWrite, Category="Tags")
		TMap<TSoftObjectPtr<AActor>, FGameplayTag> ActorStates;
	
		UPROPERTY(BlueprintReadWrite, Category="Tags")
		TMap<TSoftObjectPtr<AActor>, FGameplayTagContainer> ActorTags;
	
	
	
};
