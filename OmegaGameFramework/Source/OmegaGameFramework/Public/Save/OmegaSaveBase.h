// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "DataInterface_General.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "UObject/SoftObjectPath.h"

#include "OmegaSaveBase.generated.h"

class UWorld;
class UGameInstance;
class UPrimaryDataAsset;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveBase : public USaveGame, public IDataInterface_General, public IGameplayTagsInterface
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

	//Tags
	UPROPERTY(BlueprintReadOnly, DisplayName="Save State", Category="Tags")
	FGameplayTag StoryState;
	
	UPROPERTY(BlueprintReadOnly, DisplayName="Save Tags", Category="Tags")
	FGameplayTagContainer StoryTags;

	//DataAssets
	UPROPERTY(BlueprintReadOnly, Category="Save")
	TArray<UPrimaryDataAsset*> CollectedDataAssets;
};
