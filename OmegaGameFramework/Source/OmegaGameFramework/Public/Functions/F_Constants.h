// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Constants.generated.h"


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
	UFUNCTION() static TArray<FName> opts_float();
	UFUNCTION() static TArray<FName> opts_string();
	
	UFUNCTION() static TArray<FName> opts_da();
	UFUNCTION() static TArray<FName> opts_daList();
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜Data Asset Class")
	static TSubclassOf<UPrimaryDataAsset> Class_DataAsset(UPARAM(meta = (GetOptions = "opts_dataasset")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜System")
	static TSubclassOf<AOmegaGameplaySystem> Class_System(UPARAM(meta = (GetOptions = "opts_system")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜Menu")
	static TSubclassOf<UMenu> Class_Menu(UPARAM(meta = (GetOptions = "opts_menu")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - 💜HUD")
	static TSubclassOf<UHUDLayer> Class_HUD(UPARAM(meta = (GetOptions = "opts_hud")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Int32")
	static int32 Int(UPARAM(meta = (GetOptions = "opts_int")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Float")
	static float Float(UPARAM(meta = (GetOptions = "opts_float")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - String")
	static FString String(UPARAM(meta = (GetOptions = "opts_string")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Data Asset")
	static UPrimaryDataAsset* DataAsset(UPARAM(meta = (GetOptions = "opts_da")) FName Name);
	
	UFUNCTION(BlueprintPure, Category = "Omega|Constants",meta=(AdvancedDisplay="Fallback"),DisplayName="♾️Constant - Data Asset (List)")
	static TArray<UPrimaryDataAsset*> DataAssetList(UPARAM(meta = (GetOptions = "opts_daList")) FName Name);
	

};
