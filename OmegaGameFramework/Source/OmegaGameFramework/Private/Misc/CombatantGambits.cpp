// Fill out your copyright notice in the Description page of Project Settings.

#include "DataAssets/DA_CombatantGambits.h"

TArray<UCombatantGambitAction*> UCombatantGambitAsset::GetAllGambitActions()
{
	TArray<UCombatantGambitAction*> OutActions;
	
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
