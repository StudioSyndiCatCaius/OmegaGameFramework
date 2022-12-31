// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "DataInterface_General.h"
#include "JsonObjectWrapper.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "Preferences/GamePreference.h"
#include "UObject/SoftObjectPath.h"

#include "OmegaSaveBase.generated.h"

class UWorld;
class UGameInstance;
class UPrimaryDataAsset;

USTRUCT()
struct FOmegaSaveAssetList
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<UPrimaryDataAsset*> AssetList;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveBase : public USaveGame, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FString SaveJsonData;


	UFUNCTION()
	void Local_OnLoaded();
	
	
	//GamePreferences
	UPROPERTY()
	TMap<class UGamePreferenceBool*, bool> BoolPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceFloat*, float> FloatPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceString*, FString> StringPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceTag*, FGameplayTag> TagPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceInt*, int32> IntPrefs;
	
	
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
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Bool(const FString& Name, bool Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	bool GetSaveProperty_Bool(const FString& Name);
	
	UPROPERTY()
	TMap<FName, float> Prop_float;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Float(const FString& Name, float Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	float GetSaveProperty_Float(const FString& Name);
	
	UPROPERTY()
	TMap<FName, int32> Prop_int;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Int(const FString& Name, int32 Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	int32 GetSaveProperty_Int(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FString> Prop_string;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_String(const FString& Name, const FString& Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FString GetSaveProperty_String(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FGameplayTag> Prop_Tag;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Tag(const FString& Name, FGameplayTag Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FGameplayTag GetSaveProperty_Tag(const FString& Name);

	UPROPERTY()
	TMap<FName, FGameplayTagContainer> Prop_Tags;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Tags(const FString& Name, FGameplayTagContainer Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FGameplayTagContainer GetSaveProperty_Tags(const FString& Name);
	
	UPROPERTY()
	TMap<FName, UPrimaryDataAsset*> Prop_Asset;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Asset(const FString& Name, UPrimaryDataAsset* Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	UPrimaryDataAsset* GetSaveProperty_Asset(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FVector> Prop_Vector;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Vector(const FString& Name, FVector Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FVector GetSaveProperty_Vector(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FRotator> Prop_Rotator;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Rotator(const FString& Name, FRotator Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FRotator GetSaveProperty_Rotator(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FTransform> Prop_Transform;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Transform(const FString& Name, FTransform Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FTransform GetSaveProperty_Transform(const FString& Name);

	//JsonProperty
	UPROPERTY()
	TMap<FName, FJsonObjectWrapper> Prop_Json;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Json(const FString& Name, FJsonObjectWrapper Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FJsonObjectWrapper GetSaveProperty_Json(const FString& Name);
	
};
