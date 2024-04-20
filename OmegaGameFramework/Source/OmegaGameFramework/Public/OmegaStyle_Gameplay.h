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
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayStyle : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Systems")
	//TSubclassOf<AOmegaGameplaySystem> System_Exploration;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_Splash;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_Title;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_NewGame;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_Character;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_Player;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_NonPlayer;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayStyleFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Gameplay")
	static UOmegaGameplayStyle* GetCurrentGameplayStyle();
};