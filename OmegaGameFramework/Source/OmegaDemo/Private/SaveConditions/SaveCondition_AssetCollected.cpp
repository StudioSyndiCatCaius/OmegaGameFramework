// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveConditions/SaveCondition_AssetCollected.h"

bool USaveCondition_AssetCollected::CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const
{
	for(auto* TempAsset: DataAssets)
	{
		if(SaveSubsystem->IsDataAssetInSaveCollection(TempAsset, GlobalSave) != NOT)
		{
			return false;
		}
	}
	return true;
}
