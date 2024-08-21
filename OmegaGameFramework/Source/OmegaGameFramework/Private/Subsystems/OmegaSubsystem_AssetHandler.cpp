// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_AssetHandler.h"
#include "Engine/World.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "AssetRegistry/AssetRegistryModule.h"

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
		return SortedAssets[Name];
	}
	return nullptr;
}

void UOmegaSubsystem_AssetHandler::Register_SortedAsset(UObject* Asset, FString Name)
{
	if(Asset && Asset->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		SortedAssets.Add(Name,Asset);
	}
}


TArray<UObject*> UOmegaAssetHandlerFunctions::GetAllAssetsInPath(const FString& Path, bool bRecursive, UClass* Class)
{
	TArray<UObject*> AssetObjects;

	// Get the AssetRegistryModule
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	// Convert the path to a package path (in "/Game/..." format)
	FString PackagePath = Path;
	if (!PackagePath.StartsWith("/Game"))
	{
		PackagePath = FString::Printf(TEXT("/Game/%s"), *Path);
	}

	// Set up the filter
	FARFilter Filter;
	Filter.PackagePaths.Add(FName(*PackagePath));
	Filter.bRecursivePaths = bRecursive;
	Filter.ClassNames.Add(UObject::StaticClass()->GetFName());

	// Get assets
	TArray<FAssetData> AssetDataList;
	AssetRegistryModule.Get().GetAssets(Filter, AssetDataList);

	// Load assets
	for (const FAssetData& AssetData : AssetDataList)
	{
		UObject* LoadedAsset = AssetData.GetAsset();
		if (LoadedAsset && (LoadedAsset->GetClass()->IsChildOf(Class) || !Class))
		{
			AssetObjects.Add(LoadedAsset);
		}
	}

	return AssetObjects;
}

TArray<UObject*> UOmegaAssetHandlerFunctions::GetAllAssetsInPathList(TArray<FString> Paths, bool bRecursive,
	UClass* Class)
{
	TArray<UObject*> out;
	for(FString temp_path:Paths)
	{
		out.Append(GetAllAssetsInPath(temp_path,bRecursive,Class));
	}
	return out;
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
