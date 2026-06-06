// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Constants.generated.h"


class UOmegaLevelingAsset;
class UOmegaAttribute;
class UEquipmentSlot;
class AOmegaGameplaySystem;
class UMenu;
class UHUDLayer;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Constants : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION() static TArray<FName> opts_dataasset();
	UFUNCTION() static TArray<FName> opts_system();
	UFUNCTION() static TArray<FName> opts_menu();
	UFUNCTION() static TArray<FName> opts_hud();
	
	UFUNCTION() static TArray<FName> opts_int();
	UFUNCTION() static TArray<FName> opts_byte();
	UFUNCTION() static TArray<FName> opts_float();
	UFUNCTION() static TArray<FName> opts_string();
	
	UFUNCTION() static TArray<FName> opts_da();
	UFUNCTION() static TArray<FName> opts_daList();
	UFUNCTION() static TArray<FName> opts_att();
	UFUNCTION() static TArray<FName> opts_equipSlot();
	UFUNCTION() static TArray<FName> opts_leveling();
	
	UFUNCTION() static TArray<FName> opts_text();
	UFUNCTION() static TArray<FName> opts_textList();
	
	UFUNCTION() static TArray<FName> opts_level();
	UFUNCTION() static TArray<FName> opts_levelList();
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜Data Asset Class")
	static TSubclassOf<UPrimaryDataAsset> Class_DataAsset(UPARAM(meta = (GetOptions = "opts_dataasset")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜System")
	static TSubclassOf<AOmegaGameplaySystem> Class_System(UPARAM(meta = (GetOptions = "opts_system")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜Menu")
	static TSubclassOf<UMenu> Class_Menu(UPARAM(meta = (GetOptions = "opts_menu")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜HUD")
	static TSubclassOf<UHUDLayer> Class_HUD(UPARAM(meta = (GetOptions = "opts_hud")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Byte")
	static uint8 Byte(UPARAM(meta = (GetOptions = "opts_byte")) FName Name, uint8 Fallback=0);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Int32")
	static int32 Int(UPARAM(meta = (GetOptions = "opts_int")) FName Name, int32 Fallback=0);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Float")
	static float Float(UPARAM(meta = (GetOptions = "opts_float")) FName Name, float Fallback=0.0);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - String")
	static FString String(UPARAM(meta = (GetOptions = "opts_string")) FName Name, FString Fallback="");
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Class",DeterminesOutputType="Class"),DisplayName="♾️Constant - Data Asset")
	static UPrimaryDataAsset* DataAsset(UPARAM(meta = (GetOptions = "opts_da")) FName Name,TSubclassOf<UPrimaryDataAsset> Class);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Class",DeterminesOutputType="Class"),DisplayName="♾️Constant - Data Asset (List)")
	static TArray<UPrimaryDataAsset*> DataAssetList(UPARAM(meta = (GetOptions = "opts_daList")) FName Name, TSubclassOf<UPrimaryDataAsset> Class);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Attribute")
	static UOmegaAttribute* Attribute(UPARAM(meta = (GetOptions = "opts_att")) FName Name);
		
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Equip Slots")
	static UEquipmentSlot* EquipSlot(UPARAM(meta = (GetOptions = "opts_equipSlot")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Leveling")
	static UOmegaLevelingAsset* Leveling(UPARAM(meta = (GetOptions = "opts_leveling")) FName Name);
		
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Text")
	static FText Text(UPARAM(meta = (GetOptions = "opts_text")) FName Name);
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - List Text")
	static FText ListedText(UPARAM(meta = (GetOptions = "opts_textList")) FName Name, int32 index);

	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Level")
	static TSoftObjectPtr<UWorld> Level(UPARAM(meta = (GetOptions = "opts_level")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Level List")
	static TArray<TSoftObjectPtr<UWorld>> LevelList(UPARAM(meta = (GetOptions = "opts_levelList")) FName Name);
	
};
