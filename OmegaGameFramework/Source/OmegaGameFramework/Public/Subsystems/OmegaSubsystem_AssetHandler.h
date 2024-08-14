// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Subsystems/EngineSubsystem.h"
#include "OmegaSubsystem_AssetHandler.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_AssetHandler : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	TArray<UObject*> GetSortedAsset_All();
	
	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	UObject* GetSortedAsset_FromLabel(const FString& Name);

	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler")
	void Register_SortedAsset(UObject* Asset, FString Name);

	UPROPERTY() TMap<FString, UObject*> SortedAssets;
private:
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAssetHandlerFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"))
	static TArray<UObject*> GetAllAssetsInPath(const FString& Path, bool bRecursive, UClass* Class);

	
	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"))
	static TArray<UObject*> GetSortedAssets_OfClass(UClass* Class);

	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"))
	static TArray<UObject*> GetSortedAssets_OfCategory(FGameplayTag CategoryTag, UClass* Class);

	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",meta=(DeterminesOutputType="Class"))
	static TArray<UObject*> GetSortedAssets_WithTags(FGameplayTagContainer Tags, UClass* Class);
};
