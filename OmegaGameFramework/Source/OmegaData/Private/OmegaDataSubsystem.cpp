// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDataSubsystem.h"

#include "FileSDKBPLibrary.h"
#include "GameFeaturesSubsystem.h"
#include "OmegaDataItem.h"
#include "OmegaDataSettings.h"
#include "Functions/OmegaFunctions_Common.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Subsystems/OmegaSubsystem_AssetHandler.h"

void UOmegaDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const TArray<FDirectoryPath> LocalPaths = GetMutableDefault<UOmegaDataSettings>()->DataItemScansPath;

	//Scan paths
	if(LocalPaths.IsValidIndex(0))
	{
		const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		TArray<FAssetData> AssetData;
		FARFilter Filter;
		Filter.ClassPaths.Add(UOmegaDataItem::StaticClass()->GetClassPathName());
	
		for(const FDirectoryPath NewPath : GetMutableDefault<UOmegaDataSettings>()->DataItemScansPath)
		{
			FString LocalString = NewPath.Path;
			Filter.PackagePaths.Add(FName(*LocalString));
		}
	
		Filter.bRecursiveClasses = true;
		Filter.bRecursivePaths = true;
		AssetRegistryModule.Get().GetAssets(Filter, AssetData);

		for(FAssetData TempAssetData : AssetData)
		{
			if(Cast<UOmegaDataItem>(TempAssetData.GetAsset()))
			{
				UOmegaDataItem* TempItem = Cast<UOmegaDataItem>(TempAssetData.GetAsset());
				PrivateDataItems.AddUnique(TempItem);
				if(TempItem->GameplayID.IsValid())
				{
					DataItemIDs.Add(TempItem->GameplayID, TempItem);
				}
				FString label=TempItem->GetName();
				if(!TempItem->CustomLabel.IsEmpty())
				{
					label=TempItem->CustomLabel;
				}
				GEngine->GetEngineSubsystem<UOmegaSubsystem_AssetHandler>()->Register_SortedAsset(TempItem,label);
			}
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

UOmegaDataItem* UOmegaDataSubsystem::GetDataItemOfID(FGameplayTag ID)
{
	if(DataItemIDs.Contains(ID))
	{
		return DataItemIDs[ID];
	}
	return nullptr;
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

TArray<UOmegaDataItem*> UOmegaDataSubsystem::GetAllDataItemsWithInterface(TSubclassOf<UInterface> Interface)
{
	TArray<UOmegaDataItem*> LocalItems;
	for(auto TempItem : GetAllDataItems())
	{
		if(TempItem)
		{
			if(TempItem->GetTraitWithInterface(Interface))
			{
				LocalItems.AddUnique(TempItem);
			}
		}
	}
	return LocalItems;
}

UOmegaDataItem* UOmegaDataSubsystem::GetDataItemFromName(const FString& Name)
{
	if(NamedItems.Contains(Name))
	{
		return NamedItems.FindOrAdd(Name);
	}
	
	for(auto* TempItem : GetAllDataItems())
	{
		if(TempItem->GetName() == Name)
		{
			NamedItems.Add(Name, TempItem);
			return TempItem;
		}
	}
	return nullptr;
}

UOmegaDataItem* UOmegaDataSubsystem::CreateDataItemFromString(FString StringData,
	TSubclassOf<UOmegaDataItemConstructor> ConstructorClass, FString ItemName)
{
	if(ConstructorClass)
	{
		UOmegaDataItemConstructor* TempConstructor = NewObject<UOmegaDataItemConstructor>(this, ConstructorClass);
		UOmegaDataItem* NewItem = NewObject<UOmegaDataItem>(this, UOmegaDataItem::StaticClass());
	
		TempConstructor->OnItemCreated(StringData, NewItem->DisplayName,NewItem->DisplayDescription,NewItem->Icon,NewItem->GameplayCategory,NewItem->GameplayTags);

		NamedItems.Add(ItemName, NewItem);
	
		return NewItem;
	}
	return nullptr;
}

void UOmegaDataSubsystem::RegisterDataComponent(UDataItemComponent* NewComponent)
{
	Local_DataComponentList.AddUnique(NewComponent);
}

TArray<UDataItemComponent*> UOmegaDataSubsystem::GetActiveDataItemComponents()
{
	TArray<UDataItemComponent*> OutComps;
	for(auto* TempComp : Local_DataComponentList)
	{
		if(TempComp)
		{
			OutComps.Add(TempComp);
		}
	}
	return OutComps;
}

UDataItemComponent* UOmegaDataSubsystem::GetComponentByDataItem(UOmegaDataItem* DataItem)
{
	for(auto* TempComp : GetActiveDataItemComponents())
	{
		if(TempComp->DataItem == DataItem)
		{
			return TempComp;
		}
	}
	return nullptr;
}

TArray<UDataItemComponent*> UOmegaDataSubsystem::GetComponentsByDataItem(UOmegaDataItem* DataItem)
{
	TArray<UDataItemComponent*> OutComps;
	for(auto* TempComp : GetActiveDataItemComponents())
	{
		if(TempComp->DataItem == DataItem)
		{
			OutComps.Add(TempComp);
		}
	}
	return OutComps;
}

TArray<UDataItemComponent*> UOmegaDataSubsystem::GetComponentsOfDataItemWithTags(UOmegaDataItem* DataItem,
	FGameplayTagContainer EntityTags, bool Exact)
{
	TArray<UDataItemComponent*> OutComps;
	for(auto* TempComp: GetComponentsByDataItem(DataItem))
	{
		bool LocalValid;
		if(Exact)
		{
			LocalValid = TempComp->EntityTags.HasAnyExact(EntityTags);
		}
		else
		{
			LocalValid = TempComp->EntityTags.HasAny(EntityTags);
		}

		if(LocalValid)
		{
			OutComps.Add(TempComp);
		}
	}
	return OutComps;
}

AActor* UOmegaDataSubsystem::GetActorByDataItem(UOmegaDataItem* DataItem)
{
	if(GetComponentByDataItem(DataItem))
	{
		return  GetComponentByDataItem(DataItem)->GetOwner();
	}
	return nullptr;
}

TArray<AActor*> UOmegaDataSubsystem::GetActorsByDataItem(UOmegaDataItem* DataItem)
{
	TArray<AActor*> OutActors;
	for (const auto* TempComp : GetComponentsByDataItem(DataItem))
	{
		if(TempComp)
		{
			OutActors.Add(TempComp->GetOwner());
		}
	}
	return OutActors;
}

TArray<FString> UOmegaDataSubsystem::LoadGameDataFiles(const FString& Extension)
{

	TArray<FString> LoadedFiles;
	FString LocalExt =Extension;
	/*
	if(!Extension.IsEmpty())
	{
		TArray<FString> TempLoadedFiles = UFileSDKBPLibrary::GetFilesFromDirectory(FPaths::ProjectPluginsDir(), "csv");
		LoadedFiles.Append(TempLoadedFiles);
		TempLoadedFiles = UFileSDKBPLibrary::GetFilesFromDirectory(FPaths::ProjectPluginsDir(), "csv");
		LoadedFiles.Append(TempLoadedFiles);
	}
	*/
	return LoadedFiles;
}

//########################//########################
// FUNCTION LIBRARY
//########################//########################

UOmegaDataTrait* UOmegaDataItemFunctions::TryGetDataTraitByClass(UObject* Source, TSubclassOf<UOmegaDataTrait> Class)
{
	if(Source && Cast<UOmegaDataItem>(Source))
	{
		return Cast<UOmegaDataItem>(Source)->GetTraitByType(Class);
	}
	return nullptr;
}

UOmegaDataTrait* UOmegaDataItemFunctions::TryGetDataTraitByInterface(UObject* Source, TSubclassOf<UInterface> Class)
{
	if(Source && Cast<UOmegaDataItem>(Source))
	{
		return Cast<UOmegaDataItem>(Source)->GetTraitWithInterface(Class);
	}
	return nullptr;
}

UOmegaDataItemConstructor::UOmegaDataItemConstructor(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UOmegaDataItemConstructor::GetWorld() const
{
	if(WorldPrivate)
	{
		return WorldPrivate;
	}
	return UObject::GetWorld();
}


