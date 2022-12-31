// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OmegaDataTraitCollection.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Omega Subsystem: Data")
class OMEGADATA_API UOmegaDataTraitCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
	public:
	
	UPROPERTY(BlueprintReadOnly, Category="Traits", instanced, EditAnywhere)
	TArray<class UOmegaDataTrait*> Traits;
};
