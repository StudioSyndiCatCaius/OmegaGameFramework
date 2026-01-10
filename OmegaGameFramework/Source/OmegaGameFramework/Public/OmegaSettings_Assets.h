// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "OmegaSettings_Assets.generated.h"

class UEquipmentSlot;
class UOmegaAttribute;
class UHUDLayer;
class UMenu;
class UOmegaGlobalSettings;
class AOmegaGameplaySystem;
class UOmegaGameplayModule;
class UOmegaAttributeSet;
class UOAsset_Appearance;
class UOmegaFaction;
class UNiagaraSystem;
class ULevelSequence;

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Asset"))
class OMEGAGAMEFRAMEWORK_API UOmegaAssetSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	// ---------------------------------------------------------------------------
	// Named Assets
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, config, Category = "Named Assets")
	TMap<FName, TSoftObjectPtr<UPrimaryDataAsset>> Named_DataAssets;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Assets")
	TMap<FName, TSoftObjectPtr<UOmegaAttribute>> Named_Attributes;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Assets")
	TMap<FName, TSoftObjectPtr<UEquipmentSlot>> Named_EquipSlots;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Assets")
	TMap<FName, TSoftObjectPtr<UOmegaFaction>> Named_Faction;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Classes")
	TMap<FName, TSoftClassPtr<UPrimaryDataAsset>> Named_DataAssetClasses;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Classes")
	TMap<FName, TSoftClassPtr<AOmegaGameplaySystem>> Named_Systems;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Classes")
	TMap<FName, TSoftClassPtr<UMenu>> Named_Menus;
	
	UPROPERTY(EditAnywhere, config, Category = "Named Classes")
	TMap<FName, TSoftClassPtr<UHUDLayer>> Named_HUDLayers;
	
};

