// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataSubsystem.h"

#include "OmegaDataItem.h"
#include "OmegaDataSettings.h"
#include "OmegaGameFrameworkBPLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"


void UOmegaDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	FARFilter Filter;
	Filter.ClassNames.Add("OmegaDataItem");
	
	for(FName NewPath : GetMutableDefault<UOmegaDataSettings>()->DataItemScansPath)
	{
		Filter.PackagePaths.Add(NewPath);
	}
	
	Filter.bRecursiveClasses = true;
	Filter.bRecursivePaths = true;
	AssetRegistryModule.Get().GetAssets(Filter, AssetData);

	for(FAssetData TempAssetData : AssetData)
	{
		if(Cast<UOmegaDataItem>(TempAssetData.GetAsset()))
		{
			PrivateDataItems.AddUnique(Cast<UOmegaDataItem>(TempAssetData.GetAsset()));
		}
	}
	
	Super::Initialize(Collection);
}


TArray<UOmegaDataItem*> UOmegaDataSubsystem::GetAllDataItems()
{
	TArray<UOmegaDataItem*> LocalItems;
	for(auto TempItem : PrivateDataItems)
	{
		if(TempItem)
		{
			LocalItems.Add(TempItem);
		}
	}
	return LocalItems;
}

TArray<UOmegaDataItem*> UOmegaDataSubsystem::GetAllDataItemsOfCategory(FGameplayTag CategoryTag, bool Exact)
{
	TArray<UOmegaDataItem*> LocalItems;
	for(auto TempItem : GetAllDataItems())
	{
		if(TempItem)
		{
			bool bIsMatch;
			FGameplayTag TargetTag = IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempItem);
			if(Exact)
			{
				bIsMatch = TargetTag.MatchesTagExact(CategoryTag);
			}
			else
			{
				bIsMatch = TargetTag.MatchesTag(CategoryTag);
			}

			if (bIsMatch)
			{
				LocalItems.AddUnique(TempItem);
			}
		}
	}
	return LocalItems;
}

TArray<UOmegaDataItem*> UOmegaDataSubsystem::GetAllDataItemsWithTags(FGameplayTagContainer Tags, bool Exact)
{
	TArray<UOmegaDataItem*> LocalItems;
	for(auto TempItem : GetAllDataItems())
	{
		if(TempItem)
		{
			bool bIsMatch;
			FGameplayTagContainer TargetTag = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempItem);
			if(Exact)
			{
				bIsMatch = TargetTag.HasAnyExact(Tags);
			}
			else
			{
				bIsMatch = TargetTag.HasAny(Tags);
			}

			if (bIsMatch)
			{
				LocalItems.AddUnique(TempItem);
			}
		}
	}
	return LocalItems;
}

TArray<UOmegaDataItem*> UOmegaDataSubsystem::GetAllDataItemsWithTrait(TSubclassOf<UOmegaDataTrait> Trait)
{
	TArray<UOmegaDataItem*> LocalItems;
	for(auto TempItem : GetAllDataItems())
	{
		if(TempItem)
		{
			if(TempItem->GetTraitByType(Trait))
			{
				LocalItems.AddUnique(TempItem);
			}
		}
	}
	return LocalItems;
}
