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

	UPROPERTY()
	FString SaveJsonData;
	
	
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
	void SetSaveProperty_Bool(FName Name, bool Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	bool GetSaveProperty_Bool(FName Name);
	
	UPROPERTY()
	TMap<FName, float> Prop_float;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Float(FName Name, float Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	float GetSaveProperty_Float(FName Name);
	
	UPROPERTY()
	TMap<FName, int32> Prop_int;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Int(FName Name, int32 Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	int32 GetSaveProperty_Int(FName Name);
	
	UPROPERTY()
	TMap<FName, FString> Prop_string;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_String(FName Name, const FString& Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FString GetSaveProperty_String(FName Name);
	
	UPROPERTY()
	TMap<FName, FGameplayTag> Prop_Tag;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Tag(FName Name, FGameplayTag Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FGameplayTag GetSaveProperty_Tag(FName Name);
	
	UPROPERTY()
	TMap<FName, UPrimaryDataAsset*> Prop_Asset;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Asset(FName Name, UPrimaryDataAsset* Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	UPrimaryDataAsset* GetSaveProperty_Asset(FName Name);
	
	UPROPERTY()
	TMap<FName, FVector> Prop_Vector;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Vector(FName Name, FVector Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FVector GetSaveProperty_Vector(FName Name);
	
	UPROPERTY()
	TMap<FName, FRotator> Prop_Rotator;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Rotator(FName Name, FRotator Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FRotator GetSaveProperty_Rotator(FName Name);
	
	UPROPERTY()
	TMap<FName, FTransform> Prop_Transform;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Transform(FName Name, FTransform Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FTransform GetSaveProperty_Transform(FName Name);
	
};
