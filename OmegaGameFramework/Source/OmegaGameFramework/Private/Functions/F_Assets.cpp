// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Assets.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/AssetData.h"
#include "UObject/Class.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Assets.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Components/Component_Equipment.h"
#include "Misc/OmegaAttribute.h"
#include "Misc/OmegaFaction.h"
#include "UObject/LinkerLoad.h"
#include "UObject/Package.h"
#include "UObject/UObjectGlobals.h"
#include "Widget/Menu.h"


TArray<FName> UOmegaFunctions_Asset::nameOptions_DataAsset()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_DataAssets.GetKeys(out);
    return out;
}

TArray<FName> UOmegaFunctions_Asset::nameOptions_Attribute()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_Attributes.GetKeys(out);
    return out;
}

TArray<FName> UOmegaFunctions_Asset::nameOptions_EquipSlot()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_EquipSlots.GetKeys(out);
    return out;
}

TArray<FName> UOmegaFunctions_Asset::nameOptions_Faction()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_Faction.GetKeys(out);
    return out;
}

TArray<FName> UOmegaFunctions_Asset::nameOptions_System()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_Systems.GetKeys(out);
    return out;
}

TArray<FName> UOmegaFunctions_Asset::nameOptions_Menu()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_Menus.GetKeys(out);
    return out;
}

TArray<FName> UOmegaFunctions_Asset::nameOptions_HUD()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->Named_HUDLayers.GetKeys(out);
    return out;
}

UClass* UOmegaFunctions_Asset::GetClassByName(const FString& ClassName, bool& result)
{
    result=true;
	    // Try with common prefixes
    TArray<FString> PrefixesToTry = {
        ClassName,              // As-is
        TEXT("A") + ClassName,  // Actor prefix
        TEXT("U") + ClassName,  // UObject prefix
        TEXT("F") + ClassName,  // Struct prefix (though this won't work for UClass)
    };
    
    UE_LOG(LogTemp, Verbose, TEXT("GetClassByName: Trying variations with common prefixes..."));
    
    for (const FString& PrefixedName : PrefixesToTry)
    {
        UE_LOG(LogTemp, VeryVerbose, TEXT("GetClassByName: Attempting to find '%s'"), *PrefixedName);

        if (UClass* FoundClass = FindObject<UClass>(ANY_PACKAGE, *PrefixedName))
        {
            UE_LOG(LogTemp, Log, TEXT("GetClassByName: Successfully found class '%s' using prefix variation '%s'"), 
                   *FoundClass->GetName(), *PrefixedName);
            return FoundClass;
        }
    }
    
    UE_LOG(LogTemp, Verbose, TEXT("GetClassByName: Prefix search failed, iterating through all loaded classes..."));
    
    // Try searching through all loaded classes
    int32 ClassesSearched = 0;
    for (TObjectIterator<UClass> It; It; ++It)
    {
        UClass* CurrentClass = *It;
        ClassesSearched++;
        
        if (CurrentClass)
        {
            FString CurrentClassName = CurrentClass->GetName();
            
            // Check if name matches (with or without prefix)
            if (CurrentClassName.Equals(ClassName, ESearchCase::IgnoreCase) ||
                CurrentClassName.Equals(TEXT("A") + ClassName, ESearchCase::IgnoreCase) ||
                CurrentClassName.Equals(TEXT("U") + ClassName, ESearchCase::IgnoreCase))
            {
                UE_LOG(LogTemp, Log, TEXT("GetClassByName: Found class '%s' after searching %d loaded classes"), 
                       *CurrentClass->GetName(), ClassesSearched);
                return CurrentClass;
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("GetClassByName: Failed to find class '%s' after searching %d loaded classes"), 
           *ClassName, ClassesSearched);
    
    result=false;
    return nullptr;
}

TArray<UClass*> UOmegaFunctions_Asset::GetAllClassesInPath(const FString& Path, TSubclassOf<UObject> ParentFilter,
    bool bRecursiveSearch)
{
    TArray<UClass*> FoundClasses;
    
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
    
    AssetRegistry.SearchAllAssets(true);
    
    FString ContentPath = Path;
    
    // Test: Get ALL assets in the path first
    TArray<FAssetData> AllAssets;
    AssetRegistry.GetAssetsByPath(FName(*ContentPath), AllAssets, bRecursiveSearch);
    UE_LOG(LogTemp, Warning, TEXT("Total assets found in '%s': %d"), *ContentPath, AllAssets.Num());
    
    // Now filter for blueprints
    FARFilter Filter;
    Filter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());
    Filter.PackagePaths.Add(FName(*ContentPath));
    Filter.bRecursivePaths = bRecursiveSearch;
    
    TArray<FAssetData> AssetDataList;
    AssetRegistry.GetAssets(Filter, AssetDataList);
    
    UE_LOG(LogTemp, Warning, TEXT("Blueprint assets found: %d"), AssetDataList.Num());
    
    for (const FAssetData& AssetData : AssetDataList)
    {
        UBlueprint* Blueprint = Cast<UBlueprint>(AssetData.GetAsset());
        
        if (Blueprint && Blueprint->GeneratedClass)
        {
            UClass* AssetClass = Blueprint->GeneratedClass;
            
            if (!ParentFilter || AssetClass->IsChildOf(ParentFilter))
            {
                FoundClasses.Add(AssetClass);
            }
        }
    }
    
    return FoundClasses;
}

UObject* UOmegaFunctions_Asset::CreateObject_FromFile(TSubclassOf<UObject> Class,UObject* Outer, const FString& File, bool& result)
{
    if (Class)
    {
        UObject* new_object=NewObject<UObject>(Outer,Class);
        
        result=true;
        return new_object;
    }
    
    result=false;
    return nullptr;
}

UObject* UOmegaFunctions_Asset::LoadUassetWithMount(const FString& UAssetFilepath)
{
    return nullptr;

}

UPrimaryDataAsset* UOmegaFunctions_Asset::GetNamed_DataAsset(FName Name)
{
    if (UPrimaryDataAsset* out=GetMutableDefault<UOmegaAssetSettings>()->Named_DataAssets.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return nullptr;
}

UOmegaAttribute* UOmegaFunctions_Asset::GetNamed_Attribute(FName Name)
{
    if (UOmegaAttribute* out=GetMutableDefault<UOmegaAssetSettings>()->Named_Attributes.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return nullptr;
}

UEquipmentSlot* UOmegaFunctions_Asset::GetNamed_EquipSlot(FName Name)
{
    if (UEquipmentSlot* out=GetMutableDefault<UOmegaAssetSettings>()->Named_EquipSlots.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return nullptr;
}

UOmegaFaction* UOmegaFunctions_Asset::GetNamed_Faction(FName Name)
{
    if (UOmegaFaction* out=GetMutableDefault<UOmegaAssetSettings>()->Named_Faction.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return nullptr;
}

TSubclassOf<UPrimaryDataAsset> UOmegaFunctions_Asset::GetNamed_DataAssetClass(FName Name, TSubclassOf<UPrimaryDataAsset> Fallback)
{
    if (TSubclassOf<UPrimaryDataAsset> out=GetMutableDefault<UOmegaAssetSettings>()->Named_DataAssetClasses.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return Fallback;
}

TSubclassOf<AOmegaGameplaySystem> UOmegaFunctions_Asset::GetNamed_System(FName Name, TSubclassOf<AOmegaGameplaySystem> Fallback)
{
    if (TSubclassOf<AOmegaGameplaySystem> out=GetMutableDefault<UOmegaAssetSettings>()->Named_Systems.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return Fallback;
}

TSubclassOf<UMenu> UOmegaFunctions_Asset::GetNamed_Menu(FName Name, TSubclassOf<UMenu> Fallback)
{
    if (TSubclassOf<UMenu> out=GetMutableDefault<UOmegaAssetSettings>()->Named_Menus.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return Fallback;
}

TSubclassOf<UHUDLayer> UOmegaFunctions_Asset::GetNamed_HUD(FName Name, TSubclassOf<UHUDLayer> Fallback)
{
    if (TSubclassOf<UHUDLayer> out=GetMutableDefault<UOmegaAssetSettings>()->Named_HUDLayers.FindOrAdd(Name).LoadSynchronous())
    {
        return out;
    }
    return Fallback;
}

TMap<UEquipmentSlot*, UPrimaryDataAsset*> UOmegaFunctions_Asset::ConvNamed_Equipment(TMap<FName, UPrimaryDataAsset*> In)
{
    TMap<UEquipmentSlot*, UPrimaryDataAsset*> out;
    TArray<FName> nams;
    In.GetKeys(nams);
    for (FName Name : nams)
    {
        out.Add(GetNamed_EquipSlot(Name),In[Name]);
    }
    return out;
}

