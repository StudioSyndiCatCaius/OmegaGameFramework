// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Assets.generated.h"


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
	
	UFUNCTION() static TArray<FName> nameOptions_System();
	UFUNCTION() static TArray<FName> nameOptions_Menu();
	UFUNCTION() static TArray<FName> nameOptions_HUD();
	
	UFUNCTION() static TArray<FName> nameOptions_List_Asset();
	
	/**
	 * Get a UClass by its name (e.g., "Actor", "Character", "MyCustomClass")
	 * @param ClassName The name of the class (without prefix like 'A' or 'U')
	 * @return The UClass if found, nullptr otherwise
	 */
	UFUNCTION(BlueprintCallable, Category = "Omega|Class", meta = (Keywords = "class name string",ExpandBoolAsExecs = "result"))
	static UClass* GetClassByName(const FString& ClassName, bool& result);
    
	UFUNCTION(BlueprintCallable, Category = "Omega|Class", meta = (Keywords = "class name string"))
	static TArray<UClass*> GetAllClassesInPath(const FString& Path, TSubclassOf<UObject> ParentFilter, bool bRecursiveSearch);

	
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Asset", meta = (DeterminesOutputType="Class",ExpandBoolAsExecs = "result"))
	static UObject* CreateObject_FromFile(TSubclassOf<UObject> Class, UObject* Outer, const FString& File, bool& result);

	UFUNCTION(BlueprintCallable, Category = "Omega|Asset")
	static UObject* LoadUassetWithMount(const FString& UAssetFilepath);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UPrimaryDataAsset* GetNamed_DataAsset(UPARAM(meta = (GetOptions = "nameOptions_DataAsset")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UOmegaAttribute* GetNamed_Attribute(UPARAM(meta = (GetOptions = "nameOptions_Attribute")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UEquipmentSlot* GetNamed_EquipSlot(UPARAM(meta = (GetOptions = "nameOptions_EquipSlot")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static UOmegaFaction* GetNamed_Faction(UPARAM(meta = (GetOptions = "nameOptions_Faction")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",meta=(AdvancedDisplay="Fallback"))
	static TSubclassOf<UPrimaryDataAsset> GetNamed_DataAssetClass(FName Name, TSubclassOf<UPrimaryDataAsset> Fallback=nullptr);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",meta=(AdvancedDisplay="Fallback"))
	static TSubclassOf<AOmegaGameplaySystem> GetNamed_System(UPARAM(meta = (GetOptions = "nameOptions_System")) FName Name, TSubclassOf<AOmegaGameplaySystem> Fallback=nullptr);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",meta=(AdvancedDisplay="Fallback"))
	static TSubclassOf<UMenu> GetNamed_Menu(UPARAM(meta = (GetOptions = "nameOptions_Menu")) FName Name, TSubclassOf<UMenu> Fallback=nullptr);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Asset",meta=(AdvancedDisplay="Fallback"))
	static TSubclassOf<UHUDLayer> GetNamed_HUD(UPARAM(meta = (GetOptions = "nameOptions_HUD")) FName Name, TSubclassOf<UHUDLayer> Fallback=nullptr);
		
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static TMap<UEquipmentSlot*, UPrimaryDataAsset*> ConvNamed_Equipment(TMap<FName, UPrimaryDataAsset*> In);
	
		
	UFUNCTION(BlueprintPure, Category = "Omega|Asset")
	static TArray<UPrimaryDataAsset*> GetNamedList_DataAsset(UPARAM(meta = (GetOptions = "nameOptions_List_Asset")) FName Name);
	
};
