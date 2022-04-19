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
	UPROPERTY(BlueprintReadOnly, DisplayName="Save State", Category="Ω|SaveGame")
	FGameplayTag StoryState;
	
	UPROPERTY(BlueprintReadOnly, DisplayName="Save Tags", Category="Ω|SaveGame")
	FGameplayTagContainer StoryTags;

	//DataAssets
	UPROPERTY(BlueprintReadOnly, Category="Ω|SaveGame")
	TArray<UPrimaryDataAsset*> CollectedDataAssets;

	//Soft Property
	UPROPERTY()
	TMap<FName, bool> Prop_bool;
	UPROPERTY()
	TMap<FName, float> Prop_float;
	UPROPERTY()
	TMap<FName, int32> Prop_int;
	UPROPERTY()
	TMap<FName, FString> Prop_string;
	UPROPERTY()
	TMap<FName, FGameplayTag> Prop_Tag;

	
};
