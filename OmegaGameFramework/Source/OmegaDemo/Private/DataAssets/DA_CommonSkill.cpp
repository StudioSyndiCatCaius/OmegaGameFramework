// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonSkill.h"
#include "LevelSequence.h"
#include "Animation/AnimMontage.h"
#include "Components/Component_Combatant.h"
#include "Functions/F_ScriptedEffects.h"
#include "Condition/Condition_Actor.h"
#include "Condition/Condition_Combatant.h"



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

TMap<UOmegaAttribute*, float> UOAsset_CommonSkill::GetSkillAttributeCosts_Implementation(UCombatantComponent* Combatant,
                                                                                         UObject* Context)
{
	return AttributeUseCost;
}

