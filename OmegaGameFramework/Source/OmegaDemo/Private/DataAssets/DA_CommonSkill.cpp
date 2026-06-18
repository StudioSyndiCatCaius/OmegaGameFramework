// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonSkill.h"
#include "LevelSequence.h"
#include "Animation/AnimMontage.h"
#include "Components/Component_Combatant.h"
#include "Functions/F_ScriptedEffects.h"
#include "Condition/Condition_Actor.h"
#include "Condition/Condition_Combatant.h"
#include "Functions/F_Combatant.h"


bool UOAsset_CommonSkill::CanUseSkill_Implementation(UCombatantComponent* Combatant)
{
	FOmegaConditions_Actor con;
	con.Conditions=Conditions_CanUse;
	return con.CheckConditions(Combatant->GetOwner());
}

void UOAsset_CommonSkill::SetValue_Implementation(FLuaValue Value, const FString& Flag)
{
	Super::SetValue_Implementation(Value, Flag);
}

FOmegaSkillConfig UOAsset_CommonSkill::Skill_GetConfig_Implementation(UCombatantComponent* Combatant)
{
	return SkillConfig;
}

float UOAsset_CommonSkill::Skill_CheckUtility_Implementation(UCombatantComponent* Combatant,
	const TArray<UCombatantComponent*>& Targets, FGameplayTag Tag)
{
	TArray<UCombatantComponent*> targets=Targets;
	if (SkillConfig.TargetFilter)
	{
		targets=SkillConfig.TargetFilter->FilterCombatants(Combatant,Targets);
	}
	float out=0.0;
	float num=0.0;
	for (auto* i : targets)
	{
		if (i)
		{
			float score_total, score_average;
			UOmegaScriptedEffectFunctions::GetEffects_UtilityScore(Effects, i, Combatant, score_total, score_average);
			out += score_average;
			num++;
		}
	}
	return out/num;
}

float UOAsset_CommonSkill::Skill_CheckUtility_OneTarget_Implementation(UCombatantComponent* Combatant,
	UCombatantComponent* Target, FGameplayTag Tag)
{
	float score_total, score_average;
	UOmegaScriptedEffectFunctions::GetEffects_UtilityScore(Effects,Target,Combatant,score_total,score_average);
	return score_average;
}


