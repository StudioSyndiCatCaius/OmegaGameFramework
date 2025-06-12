// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_AssetHandler.h"
#include "Engine/World.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "IPlatformFilePak.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "Misc/PackageName.h"


void UOmegaSubsystem_AssetHandler::ClearSortedAssets_All()
{
	SortedAssets.Empty();
}

TArray<UObject*> UOmegaSubsystem_AssetHandler::GetSortedAsset_All()
{
	TArray<UObject*> out;
	TArray<FString> asset_list;
	SortedAssets.GetKeys(asset_list);
	for(FString tempName : asset_list)
	{
		out.Add(GetSortedAsset_FromLabel(tempName));
	}
	return  out;
}

UObject* UOmegaSubsystem_AssetHandler::GetSortedAsset_FromLabel(const FString& Name)
{
	if(SortedAssets.Contains(Name))
	{
		return SortedAssets[Name].LoadSynchronous();
	}
	return nullptr;
}

void UOmegaSubsystem_AssetHandler::Register_SortedAsset(UObject* Asset, FString Name, bool bOverride)
{
	if(Asset && (!SortedAssets.Contains(Name) || bOverride))
	{
		SortedAssets.Add(Name,Asset);
	}
}



TArray<UObject*> UOmegaAssetHandlerFunctions::GetSortedAssets_OfClass(UClass* Class)
{
	TArray<UObject*> out;
	for (auto* TempAsset : GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->GetSortedAsset_All())
	{
		if(TempAsset && TempAsset->GetClass()->IsChildOf(Class))
		{
			out.Add(TempAsset);
		}
	}
	return out;
}

TArray<UObject*> UOmegaAssetHandlerFunctions::GetSortedAssets_OfCategory(FGameplayTag CategoryTag, UClass* Class)
{
	TArray<UObject*> out;
	for (auto* TempAsset : GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->GetSortedAsset_All())
	{
		if(TempAsset && (TempAsset->GetClass()->IsChildOf(Class) || !Class) && TempAsset->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
		{
			FGameplayTag TempAssetTag = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempAsset);
			if(TempAssetTag.MatchesTag(CategoryTag))
			{
				out.Add(TempAsset);
			}
		}
	}
	return out;
}

TArray<UObject*> UOmegaAssetHandlerFunctions::GetSortedAssets_WithTags(FGameplayTagContainer Tags, UClass* Class)
{
	TArray<UObject*> out;
	for (auto* TempAsset : GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->GetSortedAsset_All())
	{
		if(TempAsset && (TempAsset->GetClass()->IsChildOf(Class) || !Class) && TempAsset->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
		{
			if(IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempAsset).HasAllExact(Tags))
			{
				out.Add(TempAsset);
			}
		}
	}
	return out;
}

UObject* UOmegaAssetHandlerFunctions::GetSortedAsset_FromName(const FString& Name, UClass* Class, bool& result)
{
	
	UObject* _temp=GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->GetSortedAsset_FromLabel(Name);
	if(_temp && (!Class || _temp->GetClass()->IsChildOf(Class)))
	{
		result=true;
		return nullptr;
	}
	result=false;
	return nullptr;
}
