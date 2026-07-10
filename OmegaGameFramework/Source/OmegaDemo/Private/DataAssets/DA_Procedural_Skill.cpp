// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_Procedural_Skill.h"

#include "OmegaSettings_Demo.h"
#include "Kismet/KismetStringLibrary.h"

FString UDA_Procedural_Skill::L_GetProcValue(int32 index) const
{
	TArray<FString> vals=UKismetStringLibrary::ParseIntoArray(this->GetName(),"_");
	if (vals.Num()<=index)
	{
		return vals[index];
	}
	return "";
}

FOmegaSkillConfig UDA_Procedural_Skill::Skill_GetConfig_Implementation(UCombatantComponent* Combatant)
{
	FOmegaSkillConfig out;
	UOmegaSettings_Demo* settings=GetMutableDefault<UOmegaSettings_Demo>();
	
	return out;
}

float UDA_Procedural_Skill::Skill_CheckUtility_OneTarget_Implementation(UCombatantComponent* Combatant,
	UCombatantComponent* Target, FGameplayTag Tag)
{
	return IDataInterface_Skill::Skill_CheckUtility_OneTarget_Implementation(Combatant, Target, Tag);
}
