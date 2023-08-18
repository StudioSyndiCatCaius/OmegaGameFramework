// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Combatant/CombatantGambits.h"

TArray<FCombatantGambit> UCombatantGambitAsset::GetAllGambitActions()
{
	TArray<FCombatantGambit> OutActions;
	
	for(auto* TempGambit : PrecedingGambits)
	{
		OutActions.Append(TempGambit->GetAllGambitActions());
	}
	
	OutActions.Append(GambitActions);
	
	for(auto* TempGambit : FollowingGambits)
	{
		OutActions.Append(TempGambit->GetAllGambitActions());
	}
	
	return OutActions;
}
