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
	UCombatantComponent* Target)
{
	float score_total = 0.f;
	float score_average = 0.f;
	UOmegaScriptedEffectFunctions::GetEffects_UtilityScore(Effects, Target, Combatant, score_total, score_average);
	return score_average;
}


