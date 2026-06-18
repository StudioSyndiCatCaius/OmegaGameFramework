// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_CombatantFilter.h"

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

TArray<UCombatantComponent*> UCombatantFilterFunctions::FilterCombatants_ByInterface(UCombatantComponent* Instigator,
	TArray<UCombatantComponent*> CombatantsIn, TScriptInterface<IDataInterface_Skill> Filter)
{
	if (Filter.GetObject())
	{
		FOmegaSkillConfig _cfg=IDataInterface_Skill::Execute_Skill_GetConfig(Filter.GetObject(),Instigator);
		if (_cfg.TargetFilter)
		{
			return _cfg.TargetFilter->FilterCombatants(Instigator, CombatantsIn);
		}
	}
	return TArray<UCombatantComponent*>();
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
				FOmegaSkillConfig _cfg=IDataInterface_Skill::Execute_Skill_GetConfig(s,Instigator);
				TArray<UCombatantComponent*> lis;
				lis.Add(Target);
				if (_cfg.TargetFilter)
				{
					lis= _cfg.TargetFilter->FilterCombatants(Instigator, lis);
				}
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
