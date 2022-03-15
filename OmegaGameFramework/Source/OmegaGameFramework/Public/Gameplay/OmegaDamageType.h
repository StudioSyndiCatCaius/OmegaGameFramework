// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "DataInterface_General.h"
#include "Gameplay/GameplayTagsInterface.h"

#include "OmegaDamageType.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDamageType : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public: 
	//General
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
	FText Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
	UTexture2D* Icon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
	FLinearColor Color;

	//Damage
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Damage")
	float BaseDamageModifier = 1.0;
	
};
