// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_CombatantFilter.h"

TArray<UCombatantComponent*> UCombatantFilterFunctions::FilterCombatants_ByScript(UCombatantComponent* Instigator,
	TArray<UCombatantComponent*> CombatantsIn, FCombatantFilterData Filter)
{
	TArray<UCombatantFilterScript*> filter_scripts=Filter.FilterScripts;
	TArray<UCombatantComponent*> out=CombatantsIn;
	for(auto* tempCol : Filter.FilterCollections)
	{
		if(tempCol)
		{
			filter_scripts.Append(tempCol->FilterScripts);
		}
	}

	for(auto* temp_script : filter_scripts)
	{
		out=temp_script->FilterCombatants(Instigator,out);
	}
	return out;
}

TArray<UCombatantComponent*> UCombatantFilterFunctions::FilterCombatants_ByAsset(UCombatantComponent* Instigator,
	TArray<UCombatantComponent*> CombatantsIn, UObject* FilterAsset)
{
	TArray<UCombatantComponent*> out;
	if(FilterAsset && FilterAsset->GetClass()->ImplementsInterface(UDataInterface_CombatantFilter::StaticClass()))
	{
		return FilterCombatants_ByScript(Instigator,CombatantsIn,IDataInterface_CombatantFilter::Execute_GetSkillTargetFilterData(FilterAsset));
	}
	return out;
}
