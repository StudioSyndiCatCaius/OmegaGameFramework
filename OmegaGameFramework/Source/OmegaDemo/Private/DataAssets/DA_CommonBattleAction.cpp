// Copyright Studio Syndicat 2025. All Rights Reserved.

#include "DataAssets/DA_CommonBattleAction.h"

#include "Components/Component_Combatant.h"

FOmegaScriptedAnimationData UOAsset_CommonBattleAction::GetScriptedAnimation_Implementation(FName name)
{
	if (!name.IsNone())
	{
		if (Animation_Named.Contains(name))
		{
			return Animation_Named[name];
		}
		return FOmegaScriptedAnimationData();
	}
	return Animation;
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
