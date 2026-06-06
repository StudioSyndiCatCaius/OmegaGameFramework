// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/GeneralDataObject.h"
#include "OmegaSettings_Constants.generated.h"

class AOmegaGameplaySystem;
class UMenu;
class UHUDLayer;
class UPrimaryDataAsset;
class UOmegaAttribute;
class UEquipmentSlot;
class UOmegaLevelingAsset;

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Constants"))
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Constants : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Field
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "Types",DisplayName="♾️ Byte") TMap<FName,uint8> Constant_byte;
	UPROPERTY(EditAnywhere, config, Category = "Types",DisplayName="♾️ Int") TMap<FName,int32> Constant_int;
	UPROPERTY(EditAnywhere, config, Category = "Types",DisplayName="♾️ Float") TMap<FName,float> Constant_float;
	UPROPERTY(EditAnywhere, config, Category = "Types",DisplayName="♾️ String") TMap<FName,FString> Constant_string;
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Constants
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "Classes",DisplayName="♾️ (Class) System")
	TMap<FName,TSoftClassPtr<AOmegaGameplaySystem>> Constant_Systems;
	UPROPERTY(EditAnywhere, config, Category = "Classes",DisplayName="♾️ (Class) Menu")
	TMap<FName,TSoftClassPtr<UMenu>> Constant_Menus;
	UPROPERTY(EditAnywhere, config, Category = "Classes",DisplayName="♾️ (Class) HUD Layer")
	TMap<FName,TSoftClassPtr<UHUDLayer>> Constant_Huds;
	//UPROPERTY(EditAnywhere, config, Category = "♾️Constants") TMap<FName,TSoftClassPtr<AActor>> Constant_Actors;
	UPROPERTY(EditAnywhere, config, Category = "Classes",DisplayName="♾️ (Class) Data Asset")
	TMap<FName,TSoftClassPtr<UPrimaryDataAsset>> Constant_DataAssetsClass;
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// DataAssets
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "Assets",DisplayName="♾️ Data Asset")
	TMap<FName,TSoftObjectPtr<UPrimaryDataAsset>> Constant_DataAsset;
	UPROPERTY(EditAnywhere, config, Category = "Assets",DisplayName="♾️ Data Asset (List)")
	TMap<FName,FOmegaList_DataAsset_Soft> Constant_DataAssetList;
	UPROPERTY(EditAnywhere, config, Category = "Assets",DisplayName="♾️ Attributes")
	TMap<FName,TSoftObjectPtr<UOmegaAttribute>> Constant_Attributes;
	UPROPERTY(EditAnywhere, config, Category = "Assets",DisplayName="♾️ Equip Slots")
	TMap<FName,TSoftObjectPtr<UEquipmentSlot>> Constant_EquipSlots;
	UPROPERTY(EditAnywhere, config, Category = "Assets",DisplayName="♾️ Leveling")
	TMap<FName,TSoftObjectPtr<UOmegaLevelingAsset>> Constant_Leveling;

	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Field
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "Text",DisplayName="♾️ Text") TMap<FName,FText> Constant_Text;
	UPROPERTY(EditAnywhere, config, Category = "Text",DisplayName="♾️ Text List") TMap<FName,FOmegaList_Text> Constant_TextList;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Levels
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "Levels",DisplayName="♾️ Level")
	TMap<FName,TSoftObjectPtr<UWorld>> Constant_Level;
	UPROPERTY(EditAnywhere, config, Category = "Levels",DisplayName="♾️ Level (List)")
	TMap<FName,FOmegaList_Level_Soft> Constant_LevelList;

	
};

