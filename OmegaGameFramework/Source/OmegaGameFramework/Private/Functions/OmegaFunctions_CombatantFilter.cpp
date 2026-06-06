// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_CombatantFilter.h"

#include "Interfaces/I_Skill.h"

const TArray<UCombatantComponent*> UCombatantFilterScript::FilterCombatants_Implementation(
	UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& CombatantsIn) const
{
	return TArray<UCombatantComponent*>();
}

TArray<UCombatantComponent*> UCombatantFilterCollection::FilterCombatants(UCombatantComponent* Instigator, TArray<UCombatantComponent*> In)
{
	TArray<UCombatantComponent*> out=In;
	for (auto* i : FilterScripts)
	{
		if (i)
		{
			out=i->FilterCombatants(Instigator,out);
		}
	}
	return out;
}

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


UPrimaryDataAsset* UCombatantFilterFunctions::SelectFirstSkillThatCanTarget(UCombatantComponent* Instigator,
	TArray<UPrimaryDataAsset*> Skills, UCombatantComponent* Target, bool& Outcome)
{
	if(Instigator && Target)
	{
		for(auto* s : Skills)
		{
			if(s && s->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
			{
				FOmegaSkillConfig _SkillConfig=IDataInterface_Skill::Execute_Skill_GetConfig(s,Instigator);
				TArray<UCombatantComponent*> lis;
				lis.Add(Target);
				lis=FilterCombatants_ByScript(Instigator,lis,_SkillConfig.TargetFilter);
				if(lis.Contains(Target))
				{
					Outcome=true;
					return s;
				}
			}
		}
	}
	Outcome=false;
	return nullptr;
}
