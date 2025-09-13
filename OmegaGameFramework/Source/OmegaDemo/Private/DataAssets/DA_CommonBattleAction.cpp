// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonBattleAction.h"

#include "Components/Component_Combatant.h"

ULevelSequence* UOAsset_CommonBattleAction::GetSkill_Sequences_Implementation(UCombatantComponent* Combatant,
                                                                              FName Name)
{
	if(!Name.IsNone())
	{
		if (Sequence_Named.Contains(Name))
		{
			if( Sequence_Named[Name])
			{
				return Sequence_Named[Name]->GetLevelSequence(Combatant);
			}
		}
		return nullptr;
	}
	if(Sequence)
	{
		return Sequence->GetLevelSequence(Combatant);
	}
	return nullptr;
};

UAnimMontage* UOAsset_CommonBattleAction::GetSkill_Montage_Implementation(UCombatantComponent* Combatant, FName Name)
{
	if(!Name.IsNone())
	{
		if (Montage_Named.Contains(Name))
		{
			if( Montage_Named[Name])
			{
				return Montage_Named[Name]->GetMontage(Combatant);
			}
		}
		return nullptr;
	}
	if(Montage)
	{
		return Montage->GetMontage(Combatant);
	}
	return nullptr;
}

FOmegaCustomScriptedEffects UOAsset_CommonBattleAction::GetScriptedEffects_Implementation(FName Name)
{
	if(!Name.IsNone())
	{
		if(Effects_Named.Contains(Name))
		{
			return Effects_Named[Name];
		}
		return FOmegaCustomScriptedEffects();
	}
	FOmegaCustomScriptedEffects ef;
	ef.CustomEffects=Effects;
	return ef;
}
