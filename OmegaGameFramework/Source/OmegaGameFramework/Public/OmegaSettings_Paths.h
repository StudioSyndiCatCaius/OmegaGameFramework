// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaSettings_Paths.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Paths : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Paths")
	TMap<TSubclassOf<UObject>, FDirectoryPath> ClassPaths;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_PathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Paths")
	static UOmegaSettings_Paths* GetOmegaPathSettings();
};
