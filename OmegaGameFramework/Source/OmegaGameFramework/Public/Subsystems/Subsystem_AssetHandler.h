// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Subsystems/EngineSubsystem.h"
#include "Subsystem_AssetHandler.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_AssetHandler : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY() TMap<FString, UObject*> SortedAssets;

	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	void ClearSortedAssets_All();

	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	TArray<UObject*> GetSortedAsset_All();
	
	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	UObject* GetSortedAsset_FromLabel(const FString& Name);
	
	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	void Register_SortedAsset(UObject* Asset, FString Name, bool bOverride);
	
	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler|Lua")
	void GenerateLuaTableDataAssets();
private:
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAssetHandlerFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get All Sorted Assets (of Class)")
	static TArray<UObject*> GetSortedAssets_OfClass(UClass* Class);

	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get All Sorted Assets (of Category)")
	static TArray<UObject*> GetSortedAssets_OfCategory(FGameplayTag CategoryTag, UClass* Class);

	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"),DisplayName="Ω🔴 Get All Sorted Assets (with Tags)")
	static TArray<UObject*> GetSortedAssets_WithTags(FGameplayTagContainer Tags, UClass* Class);

	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class", ExpandBoolAsExecs="result"),DisplayName="Ω🔴 Get All Sorted Assets (with Tags)")
	static UObject* GetSortedAsset_FromName(const FString& Name, UClass* Class, bool& result);
};
