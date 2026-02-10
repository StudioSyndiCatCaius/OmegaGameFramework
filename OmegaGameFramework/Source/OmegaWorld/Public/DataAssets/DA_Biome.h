// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Biome.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAWORLD_API UOmegaBiome_Asset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Biome")
	UOmegaBiome_Asset* Fallback;
};
