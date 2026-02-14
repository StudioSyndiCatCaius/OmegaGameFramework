// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaSettings_Paths.generated.h"

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaSortedClassPathData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	FString AssetPrefex;
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	FString AssetSuffex;
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	TArray<FString> AssetPaths;
	
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	bool AutoscanPathsOnStartup=true;
	UPROPERTY(EditAnywhere,Category="SortedClassData")
	FString ExternalFileDirectoryName;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Paths : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Paths")
	TArray<FString> GetPathsFromAssetName(const FString& AssetName, TSubclassOf<UObject> Class);

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Paths")
	TArray<UOmegaSettings_Paths*> ImportedPaths;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Paths")
	TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> ClassPaths;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_PathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Settings", DisplayName="Get OMEGA Settings (Path)")
	static UOmegaSettings_Paths* GetOmegaPathSettings();
};
