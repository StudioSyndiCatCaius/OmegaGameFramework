// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonBattleAction.h"

#include "Components/Component_Combatant.h"



FOmegaScriptedAnimationData UOAsset_CommonBattleAction::GetScriptedAnimation_Implementation(FGameplayTag Tag)
{
	if (Tag.IsValid())
	{
		if (Animation_Named.Contains(Tag))
		{
			return Animation_Named[Tag];
		}
		return FOmegaScriptedAnimationData();
	}
	return Animation;
}

FOmegaCustomScriptedEffects UOAsset_CommonBattleAction::GetScriptedEffects_Implementation(FGameplayTag Tag)
{
	if(Tag.IsValid())
	{
		if(Effects_Named.Contains(Tag))
		{
			return Effects_Named[Tag];
		}
		return FOmegaCustomScriptedEffects();
	}
	FOmegaCustomScriptedEffects ef;
	ef.CustomEffects=Effects;
	return ef;
}

