// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "OmegaStyle_Gameplay.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStyle_Gameplay : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Systems")
	//TSubclassOf<AOmegaGameplaySystem> System_Exploration;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaGameplaySystem>> Abilities_Character;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaGameplaySystem>> Abilities_Player;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaGameplaySystem>> Abilities_NonPlayer;
};
