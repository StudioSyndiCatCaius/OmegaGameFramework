// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonSkill.h"
#include "LevelSequence.h"
#include "Animation/AnimMontage.h"
#include "Components/Component_Combatant.h"
#include "Functions/F_ScriptedEffects.h"
#include "Condition/Condition_Actor.h"
#include "Condition/Condition_Combatant.h"


void UOAsset_CommonSkill::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Super::GetGeneralDataText_Implementation(Label, Context, Name, Description);
	if(bAppendEffectsDescription)
	{
		FString str=Description.ToString();

		//FOmegaCustomScriptedEffects ef=GetScriptedEffects("");
		//Description=ef.GetEffectsDescription();

		
		//Description=FText::FromString(str);
	}
}

bool UOAsset_CommonSkill::CanUseSkill_Implementation(UCombatantComponent* Combatant)
{
	FOmegaConditions_Actor con;
	con.Conditions=Conditions_CanUse;
	return con.CheckConditions(Combatant->GetOwner());
}

TMap<UOmegaAttribute*, float> UOAsset_CommonSkill::GetSkillAttributeCosts_Implementation(UCombatantComponent* Combatant,
                                                                                         UObject* Context)
{
	return AttributeUseCost;
}

