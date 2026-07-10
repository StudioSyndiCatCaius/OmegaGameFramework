// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "DA_Collection.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDataAssetCollection : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Collection")
	TArray<UPrimaryDataAsset*> Assets;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Collection",meta=(ForceInlineRow))
	TMap<FGameplayTag,FOmegaList_DataAsset> TaggedAssets;
};
