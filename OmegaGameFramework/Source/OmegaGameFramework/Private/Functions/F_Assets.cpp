// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Assets.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/AssetData.h"
#include "UObject/Class.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Assets.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Functions/F_Equipment.h"
#include "DataAssets/DA_EquipSlot.h"
#include "Engine/AssetManager.h"
#include "Engine/PrimaryAssetLabel.h"
#include "DataAssets/DA_Attribute.h"
#include "DataAssets/DA_Faction.h"
#include "Misc/OmegaUtils_Macros.h"
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



TArray<FName> UOmegaFunctions_Asset::nameOptions_List_Asset()
{
    TArray<FName> out;
    GetMutableDefault<UOmegaAssetSettings>()->NamedList_DataAssets.GetKeys(out);
    return out;
}

TArray<TSubclassOf<UObject>> UOmegaFunctions_Asset::GetAllChildClasses(TSubclassOf<UObject> ParentClass,
    bool bIncludeDescendants, bool bIncludeParent)
{TArray<TSubclassOf<UObject>> Result;

    if (!ParentClass) return Result;

    if (bIncludeParent)
        Result.Add(ParentClass);

    for (TObjectIterator<UClass> It; It; ++It)
    {
        UClass* Class = *It;
        if (!Class || Class == ParentClass.Get()) continue;

        bool bMatches = bIncludeDescendants
            ? Class->IsChildOf(ParentClass)
            : Class->GetSuperClass() == ParentClass.Get();

        if (bMatches)
            Result.Add(Class);
    }

    return Result;
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
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 7
        if (UClass* FoundClass = FindObject<UClass>(ANY_PACKAGE, *PrefixedName))
        {
            UE_LOG(LogTemp, Log, TEXT("GetClassByName: Successfully found class '%s' using prefix variation '%s'"), 
                   *FoundClass->GetName(), *PrefixedName);
            return FoundClass;
        }
#else
        if (UClass* FoundClass = FindFirstObject<UClass>(*PrefixedName, EFindFirstObjectOptions::NativeFirst))
        {
            UE_LOG(LogTemp, Log, TEXT("GetClassByName: Successfully found class '%s' using prefix variation '%s'"), 
                   *FoundClass->GetName(), *PrefixedName);
            return FoundClass;
        }
#endif   
        //fix in later versions
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

UClass* UOmegaFunctions_Asset::GetBlueprintClassFromPath(const FString Path)
{
	FSoftClassPath LocalPath;
	LocalPath.SetSubPathString(Path);
	return LocalPath.ResolveClass();
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

UPrimaryDataAsset* UOmegaFunctions_Asset::GetGlobalTagged_Asset(FGameplayTag Tag, TSubclassOf<UPrimaryDataAsset> Class,
    UPrimaryDataAsset* Fallback)
{
    UPrimaryDataAsset* out=Fallback;
    
    if (UPrimaryDataAsset* a=GetMutableDefault<UOmegaAssetSettings>()->GlobalTagged_DataAssets.FindOrAdd(Tag).LoadSynchronous())
    {
        out=a;
    }
    
    if (out && (!Class || out->GetClass()->IsChildOf(Class)))
    {
        return out;
    }
    return nullptr;
}

TArray<UPrimaryDataAsset*> UOmegaFunctions_Asset::GetNamedList_DataAssetList(FGameplayTag Tag,
    TSubclassOf<UPrimaryDataAsset> Class)
{
    TArray<UPrimaryDataAsset*> out;
    
    for (TSoftObjectPtr<UPrimaryDataAsset> p : GetMutableDefault<UOmegaAssetSettings>()->GlobalTagged_AssetList.FindOrAdd(Tag).List)
    {
        if (UPrimaryDataAsset* da=p.LoadSynchronous())
        {
            if (!Class || da->GetClass()->IsChildOf(Class))
            {
                out.Add(da);
            }
        }
    }
    
    return out;
}

TSubclassOf<UObject> UOmegaFunctions_Asset::GetGlobalTagged_Class(FGameplayTag Tag, TSubclassOf<UObject> Class,
    TSubclassOf<UObject> Fallback)
{
    TSubclassOf<UObject> out=Fallback;
    
    if (TSubclassOf<UObject> a=GetMutableDefault<UOmegaAssetSettings>()->GlobalTagged_Classes.FindOrAdd(Tag).LoadSynchronous())
    {
        out=a;
    }
    
    if (out && (!Class || out->GetClass()->IsChildOf(Class)))
    {
        return out;
    }
    if (Fallback)
    {
        return Fallback;    
    }
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

TArray<UPrimaryDataAsset*> UOmegaFunctions_Asset::GetNamedList_DataAsset(FName Name)
{
    return GetMutableDefault<UOmegaAssetSettings>()->NamedList_DataAssets.FindOrAdd(Name).GetAssets();
}

TArray<UPrimaryAssetLabel*> UOmegaFunctions_Asset::GetAllLoadedLabels()
{
    TArray<UPrimaryAssetLabel*> Labels;

    if (!UAssetManager::IsInitialized()) return Labels;
    UAssetManager& AM = UAssetManager::Get();

    TArray<FPrimaryAssetId> AssetIds;
    AM.GetPrimaryAssetIdList(FPrimaryAssetType(TEXT("PrimaryAssetLabel")), AssetIds);

    for (const FPrimaryAssetId& Id : AssetIds)
    {
        FSoftObjectPath Path = AM.GetPrimaryAssetPath(Id);
        if (UPrimaryAssetLabel* Label = Cast<UPrimaryAssetLabel>(Path.ResolveObject()))
        {
            Labels.Add(Label);
        }
    }

    return Labels;
}


void UOmegaFunctions_Asset::AppendManagedAssets(UPrimaryAssetLabel* Label, TSubclassOf<UObject> FilterClass,
                                TSet<UObject*>& OutSet)
{
    if (!IsValid(Label)) return;

    IAssetRegistry& AR =
        FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

    const FAssetIdentifier LabelId(Label->GetOutermost()->GetFName(), Label->GetFName());

    TArray<FAssetIdentifier> Managed;
    AR.GetDependencies(LabelId, Managed, UE::AssetRegistry::EDependencyCategory::Manage);

    for (const FAssetIdentifier& Id : Managed)
    {
        const FString PkgStr  = Id.PackageName.ToString();
        const FString NameStr = Id.ObjectName.IsNone()
            ? FPackageName::GetLongPackageAssetName(PkgStr)
            : Id.ObjectName.ToString();

        UObject* Obj = FSoftObjectPath(PkgStr + TEXT(".") + NameStr).ResolveObject();
        if (!Obj) continue;
        if (FilterClass && !Obj->IsA(FilterClass)) continue;

        OutSet.Add(Obj);
    }
}


TArray<UObject*> UOmegaFunctions_Asset::GetPAL_AllAssets(UPrimaryAssetLabel* Label)
{
    TArray<UObject*> Result;
    if (!IsValid(Label)) return Result;

    IAssetRegistry& AssetRegistry =
        FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

    // Build the FAssetIdentifier for this label (package + asset name)
    const FName PackageName  = Label->GetOutermost()->GetFName();
    const FName AssetName    = Label->GetFName();
    const FAssetIdentifier LabelIdentifier(PackageName, AssetName);

    // Collect all assets that this label manages via the Manage dependency edge
    TArray<FAssetIdentifier> ManagedIdentifiers;
    AssetRegistry.GetDependencies(
        LabelIdentifier,
        ManagedIdentifiers,
        UE::AssetRegistry::EDependencyCategory::Manage
    );

    Result.Reserve(ManagedIdentifiers.Num());

    for (const FAssetIdentifier& Id : ManagedIdentifiers)
    {
        // Build a full object path: /Game/Path/Package.AssetName
        const FString PkgStr  = Id.PackageName.ToString();
        const FString NameStr = Id.ObjectName.IsNone()
            ? FPackageName::GetLongPackageAssetName(PkgStr)   // derive name from package tail
            : Id.ObjectName.ToString();

        const FSoftObjectPath SoftPath(PkgStr + TEXT(".") + NameStr);

        // ResolveObject() returns nullptr if not currently loaded — no forced load
        if (UObject* LoadedObj = SoftPath.ResolveObject())
        {
            Result.Add(LoadedObj);
        }
    }

    return Result;
}

TArray<UObject*> UOmegaFunctions_Asset::GetPALObjects_All(TSubclassOf<UObject> FilterClass)
{
    TSet<UObject*> Unique;

    for (UPrimaryAssetLabel* Label : GetAllLoadedLabels())
    {
        AppendManagedAssets(Label, FilterClass, Unique);
    }

    return Unique.Array();
}

TArray<UObject*> UOmegaFunctions_Asset::GetPALObjects_OfIDRange(int32 minChunkID, int32 maxChunkID,
    TSubclassOf<UObject> FilterClass)
{
    TSet<UObject*> Unique;

    for (UPrimaryAssetLabel* Label : GetAllLoadedLabels())
    {
        if (Label->Rules.ChunkId >= minChunkID && Label->Rules.ChunkId <= maxChunkID)
        {
            AppendManagedAssets(Label, FilterClass, Unique);
        }
    }

    return Unique.Array();
}
