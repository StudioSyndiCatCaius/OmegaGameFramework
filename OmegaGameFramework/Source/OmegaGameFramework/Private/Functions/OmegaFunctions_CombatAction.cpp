// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_CombatAction.h"

void UCombatantActionSelectFunctions::SelectCombatAction_ByScript(TSubclassOf<UCombatantActionSelector_Script> Script,
	UCombatantComponent* Instigator, UPrimaryDataAsset*& ChosenAction, TArray<UCombatantComponent*>& ChosenTargets)
{
	if(Instigator && Script)
	{
		GetMutableDefault<UCombatantActionSelector_Script>(Script)->SelectAction(Instigator,ChosenAction,ChosenTargets);
	}
}

void UCombatantActionSelectFunctions::SelectCombatAction_ByPreset(UCombatantActionSelector_Preset* Script,
	UCombatantComponent* Instigator, UPrimaryDataAsset*& ChosenAction, TArray<UCombatantComponent*>& ChosenTargets)
{
	if(Instigator && Script)
	{
		
	}
}
