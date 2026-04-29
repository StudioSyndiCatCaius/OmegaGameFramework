// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Assets.generated.h"


struct FGameplayTag;
class UPrimaryAssetLabel;
class UOmegaAttribute;
class UEquipmentSlot;
class UOmegaFaction;
class UMenu;
class UHUDLayer;
class AOmegaGameplaySystem;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Asset : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION() static TArray<FName> nameOptions_DataAsset();
	UFUNCTION() static TArray<FName> nameOptions_Attribute();
	UFUNCTION() static TArray<FName> nameOptions_EquipSlot();
	UFUNCTION() static TArray<FName> nameOptions_Faction();
	
	UFUNCTION() static TArray<FName> nameOptions_List_Asset();
	
	/**
	 * Get a UClass by its name (e.g., "Actor", "Character", "MyCustomClass")
	 * @param ClassName The name of the class (without prefix like 'A' or 'U')
	 * @return The UClass if found, nullptr otherwise
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Utilities|Class")
	static TArray<TSubclassOf<UObject>> GetAllChildClasses(TSubclassOf<UObject> ParentClass,bool bIncludeDescendants = false,bool bIncludeParent = false);
	
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Class", meta = (Keywords = "class name string",ExpandBoolAsExecs = "result"))
	static UClass* GetClassByName(const FString& ClassName, bool& result);
    
	UFUNCTION(BlueprintCallable, Category = "Omega|Class", meta = (Keywords = "class name string"))
	static TArray<UClass*> GetAllClassesInPath(const FString& Path, TSubclassOf<UObject> ParentFilter, bool bRecursiveSearch);

	UFUNCTION(BlueprintPure,Category="Omega|Asset")
	static UClass* GetBlueprintClassFromPath(const FString Path);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Asset", meta = (DeterminesOutputType="Class",ExpandBoolAsExecs = "result"))
	static UObject* CreateObject_FromFile(TSubclassOf<UObject> Class, UObject* Outer, const FString& File, bool& result);

	UFUNCTION(BlueprintCallable, Category = "Omega|Asset")
	static UObject* LoadUassetWithMount(const FString& UAssetFilepath);
		
	//──────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Global Taggged
	//──────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",DisplayName="Get GlobalTagged - Data Asset",meta=(DeterminesOutputType="Class",AdvancedDisplay="Fallback"))
	static UPrimaryDataAsset* GetGlobalTagged_Asset(UPARAM(meta=(Categories="UASSET") )FGameplayTag Tag, TSubclassOf<UPrimaryDataAsset> Class,UPrimaryDataAsset* Fallback=nullptr);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",DisplayName="Get GlobalTagged - Data Asset List",meta=(DeterminesOutputType="Class",AdvancedDisplay="Fallback"))
	static TArray<UPrimaryDataAsset*> GetNamedList_DataAssetList(UPARAM(meta=(Categories="UASSET_LIST") )FGameplayTag Tag, TSubclassOf<UPrimaryDataAsset> Class);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",DisplayName="Get GlobalTagged - Class",meta=(DeterminesOutputType="Class",AdvancedDisplay="Fallback"))
	static TSubclassOf<UObject> GetGlobalTagged_Class(UPARAM(meta=(Categories="UCLASS") )FGameplayTag Tag, TSubclassOf<UObject> Class,TSubclassOf<UObject> Fallback=nullptr);
	
	//──────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Named
	//──────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UPrimaryDataAsset* GetNamed_DataAsset(UPARAM(meta = (GetOptions = "nameOptions_DataAsset")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UOmegaAttribute* GetNamed_Attribute(UPARAM(meta = (GetOptions = "nameOptions_Attribute")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UEquipmentSlot* GetNamed_EquipSlot(UPARAM(meta = (GetOptions = "nameOptions_EquipSlot")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UOmegaFaction* GetNamed_Faction(UPARAM(meta = (GetOptions = "nameOptions_Faction")) FName Name);
	
		
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static TMap<UEquipmentSlot*, UPrimaryDataAsset*> ConvNamed_Equipment(TMap<FName, UPrimaryDataAsset*> In);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static TArray<UPrimaryDataAsset*> GetNamedList_DataAsset(UPARAM(meta = (GetOptions = "nameOptions_List_Asset")) FName Name);
	
	//──────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Primary Asset
	//──────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	static TArray<UPrimaryAssetLabel*> GetAllLoadedLabels();
	
	static void AppendManagedAssets(UPrimaryAssetLabel* Label, TSubclassOf<UObject> FilterClass,TSet<UObject*>& OutSet);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Asset",meta=(DeterminesOuputType="FilterClass"),DisplayName="Primary Asset Label - Get of (ALL)")
	static TArray<UObject*> GetPAL_AllAssets(UPrimaryAssetLabel* Label);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Asset",meta=(DeterminesOuputType="FilterClass"),DisplayName="Primary Assets - Get (ALL)")
	static TArray<UObject*> GetPALObjects_All(TSubclassOf<UObject> FilterClass=nullptr);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",meta=(DeterminesOuputType="FilterClass"),DisplayName="Primary Assets - Get (Chunk Range)")
	static TArray<UObject*> GetPALObjects_OfIDRange(int32 minChunkID,int32 maxChunkID, TSubclassOf<UObject> FilterClass=nullptr);
	
};
