// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_CommonPickup.h"

bool UOAsset_Pickup_Common::CanPickup_Implementation(APawn* Pawn, APlayerController* Controller)
{
	if (Pawn)
	{
		return PickupConditions.CheckConditions(Pawn);
	}
	return false;
}

int32 UOAsset_Pickup_Common::OnPickup_Implementation(APawn* Pawn, APlayerController* Controller)
{
	if (Pawn)
	{
		PickupEffects.ApplyMods(Pawn);
		UOmegaFunctions_GlobalScripting::RunGlobalScripts(Pawn,GlobalScriptsOnPickup);	
	}
	return 0;
}
