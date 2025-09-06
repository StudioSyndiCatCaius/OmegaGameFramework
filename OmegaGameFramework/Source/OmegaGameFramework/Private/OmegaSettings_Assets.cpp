// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Assets.h"

#include "Misc/OmegaAttribute.h"
#include "Components/Component_Equipment.h"
#include "OmegaSettings.h"
#include "Kismet/KismetStringLibrary.h"




FOmegaObjectTraits UOmegaSettings_Assets::L_GetAppendedTraits(UObject* o)
{
	if(UPrimaryDataAsset* _da=Cast<UPrimaryDataAsset>(o))
	{
		FOmegaObjectTraits tr;
		for(auto* i : AppendedTraitSets)
		{
			if(i && i->AppendedTraits.Contains(_da))
			{
				tr.Traits.Append(i->AppendedTraits[_da].Traits);
			}
		}
		if(AppendedTraits.Contains(_da))
		{
			tr.Traits.Append(AppendedTraits[_da].Traits);
		}
	}
	return FOmegaObjectTraits();
}

UOmegaSettings_Assets* UOmegaSettings_AssetsFunctions::GetCurrentAssetSettings()
{
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultSettings_Assets.TryLoad())
	{
		return Cast<UOmegaSettings_Assets>(style_ref);
	}
	return nullptr;
}

UPrimaryDataAsset* UOmegaSettings_AssetsFunctions::GetGlobalTagged_DataAsset(FGameplayTag Tag)
{
	if(!GetCurrentAssetSettings()) { return nullptr; }
	if(GetCurrentAssetSettings()->Tagged_DataAssets.Contains(Tag))
	{
		return GetCurrentAssetSettings()->Tagged_DataAssets[Tag].LoadSynchronous();	
	}
	return nullptr;
}

UOmegaAttribute* UOmegaSettings_AssetsFunctions::GetGlobalTagged_Attribute(FGameplayTag Tag)
{
	if(!GetCurrentAssetSettings()) { return nullptr; }
	if(GetCurrentAssetSettings()->Tagged_Attributes.Contains(Tag))
	{
		return GetCurrentAssetSettings()->Tagged_Attributes[Tag].LoadSynchronous();
	}
	return nullptr;
}

UEquipmentSlot* UOmegaSettings_AssetsFunctions::GetGlobalTagged_EquipSlot(FGameplayTag Tag)
{
	if(!GetCurrentAssetSettings()) { return nullptr; }
	if(GetCurrentAssetSettings()->Tagged_EquipSlots.Contains(Tag))
	{
		return GetCurrentAssetSettings()->Tagged_EquipSlots[Tag].LoadSynchronous();
	}
	return nullptr;
}