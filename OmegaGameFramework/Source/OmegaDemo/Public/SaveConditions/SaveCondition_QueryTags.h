// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Save/OmegaSaveCondition.h"
#include "Save/OmegaSaveSubsystem.h"
#include "UObject/Object.h"
#include "SaveCondition_QueryTags.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Condition (Query Save Tags)")
class OMEGADEMO_API USaveCondition_QueryTags : public UOmegaSaveCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="Condition")
	FGameplayTagQuery TagQuery;
	UPROPERTY(EditInstanceOnly, Category="Condition")
	bool GlobalSave;
	
	virtual bool CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const override;
	
};
