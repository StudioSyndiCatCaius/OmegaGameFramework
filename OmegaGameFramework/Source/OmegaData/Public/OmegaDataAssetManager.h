// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
	#include "Engine/AssetManager.h"
#include "OmegaDataAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class OMEGADATA_API UOmegaDataAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
	UOmegaDataAssetManager() {};

	virtual void StartInitialLoading() override;
	
	static const FPrimaryAssetType OmegaDataItems;

	static UOmegaDataAssetManager& Get();
};
