// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_Functions.h"

#include "OmegaSettings_Assets.h"

TArray<FName> UOmegaDemoFunctions::GetAssetKeys_Attributes()
{
	TArray<FName> out;
	if(UOmegaSettings_Assets* set=UOmegaSettings_AssetsFunctions::GetCurrentAssetSettings())
	{
		set->Named_Attributes.GetKeys(out);
	}
	return out;
}

TArray<FName> UOmegaDemoFunctions::GetAssetKeys_EquipSlots()
{
	TArray<FName> out;
	if(UOmegaSettings_Assets* set=UOmegaSettings_AssetsFunctions::GetCurrentAssetSettings())
	{
		set->Named_EquipSlots.GetKeys(out);
	}
	return out;
}

