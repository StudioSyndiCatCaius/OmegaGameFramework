// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Save/OmegaSaveCondition.h"
#include "UObject/Object.h"
#include "SaveCondition_AssetCollected.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Condition (Data Assets Collected)")
class OMEGADEMO_API USaveCondition_AssetCollected : public UOmegaSaveCondition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category="Condition")
	TArray<UPrimaryDataAsset*> DataAssets;
	UPROPERTY(EditAnywhere, Category="Condition")
	bool NOT;
	UPROPERTY(EditAnywhere, Category="Condition")
	bool GlobalSave;

	virtual bool CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const override;
};
