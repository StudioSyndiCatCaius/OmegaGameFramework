// Fill out your copyright notice in the Description page of Project Settings.

// Functions that may commonly be used in relation to the combatant component.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "OmegaFunctions_CombatAction.generated.h"

class UCombatantComponent;

// ================================================================================================================
// COMBATANT FILTER
// ================================================================================================================

UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract,Const,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UCombatantActionSelector_Script : public UObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, Category="CombatantFilter")
	const bool SelectAction(UCombatantComponent* Instigator,
		UPrimaryDataAsset*& ChosenAction, TArray<UCombatantComponent*>& ChosenTargets) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantActionSelector_Preset : public UOmegaDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced, Category="Filter")
	TArray<UCombatantActionSelector_Script*> Scripts;

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UCombatantActionSelectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="Omega|Combatant|Filter")
	static void SelectCombatAction_ByScript(TSubclassOf<UCombatantActionSelector_Script> Script, UCombatantComponent* Instigator,
		UPrimaryDataAsset*& ChosenAction, TArray<UCombatantComponent*>& ChosenTargets);

	static void SelectCombatAction_ByPreset(UCombatantActionSelector_Preset* Script, UCombatantComponent* Instigator,
		UPrimaryDataAsset*& ChosenAction, TArray<UCombatantComponent*>& ChosenTargets);
};