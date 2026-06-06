// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Misc/OmegaUtils_Structs.h"
#include "UObject/Object.h"
#include "OmegaSettings_Assets.generated.h"

class UOmegaAssetHandlerConfig;
class UEquipmentSlot;
class UOmegaAttribute;
class UHUDLayer;
class UMenu;
class UOmegaGameManager;
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
	
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Editor") void LoadDevConfig();
	
	// ---------------------------------------------------------------------------
	// Named Assets
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Quickload")
	TArray<FString> Quickload_ContentDirectories;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Quickload")
	TArray<FString> Quickload_ClassDirectories;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Quickload")
	TMap<TSoftClassPtr<UObject>,FString> Quickload_ClassNameRemap;
	
	// ---------------------------------------------------------------------------
	// Named Assets
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Tagged Assets (Omega)",meta=(ForceInlineRow,Categories="UASSET"))
	TMap<FGameplayTag, TSoftObjectPtr<UPrimaryDataAsset>> GlobalTagged_DataAssets;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Tagged Assets (Omega)",meta=(ForceInlineRow,Categories="UCLASS"))
	TMap<FGameplayTag, TSoftClassPtr<UObject>> GlobalTagged_Classes;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Tagged Assets (Omega)",meta=(ForceInlineRow,Categories="UASSET_LIST"))
	TMap<FGameplayTag, FOmegaList_DataAsset_Soft> GlobalTagged_AssetList;

	// ---------------------------------------------------------------------------
	// Named Assets
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "🇺 Named Assets (Unreal)") TMap<FName, TSoftObjectPtr<UTexture2D>> Named_Textures;
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "🇺 Named Assets (Unreal)") TMap<FName, TSoftObjectPtr<UMaterialInterface>> Named_Material;
	
	// ---------------------------------------------------------------------------
	// Named Assets
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Named Assets (Omega)")
	TMap<FName, TSoftObjectPtr<UPrimaryDataAsset>> Named_DataAssets;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Named Assets (Omega)")
	TMap<FName, TSoftObjectPtr<UOmegaAttribute>> Named_Attributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Named Assets (Omega)")
	TMap<FName, TSoftObjectPtr<UEquipmentSlot>> Named_EquipSlots;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "♎ Named Assets (Omega)")
	TMap<FName, TSoftObjectPtr<UOmegaFaction>> Named_Faction;
	
	// ---------------------------------------------------------------------------
	// Named Lists
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "📋 Named Lists")
	TMap<FName, FOmegaList_Object_Soft> NamedList_Object;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,config, Category = "📋 Named Lists")
	TMap<FName, FOmegaList_DataAsset_Soft> NamedList_DataAssets;
};

