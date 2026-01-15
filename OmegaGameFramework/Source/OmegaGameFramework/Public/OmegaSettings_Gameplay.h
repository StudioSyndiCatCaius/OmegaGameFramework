// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Misc/OmegaGameplayModule.h"
#include "NiagaraSystem.h"
#include "Types/Struct_InputConfig.h"
#include "OmegaSettings_Gameplay.generated.h"

class UOmegaFaction;
class UMenu;
class UOAsset_Appearance;
class UOAsset_ActorModifierCollection;
class UEquipmentSlot;
class UOmegaAttribute;
class UOmegaAttributeSet;
class AZoneEntityDisplayActor;
class UOmegaCharacterConfig;
class UOmegaActorConfig;
class USubscriptCollection;
class AOmegaActorProcessor;
class UOmegaTextFormater_Collection;
class AOmegaActor_ChoiceBASE;
class UOmegaGameplayModule;
class AOmegaGameplaySystem;

// ------------------------------------------------------------------------------------------------------------------------
// Data Asset MetaSettings
// ------------------------------------------------------------------------------------------------------------------------

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaDataAssetMetaSettingsInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Settings")
	UPrimaryDataAsset* DataAsset=nullptr;
	UPROPERTY(EditAnywhere,Instanced, BlueprintReadOnly,Category="Settings")
	TArray<UOmegaDataAssetMetaSetting*> Settings;
};



UCLASS(Blueprintable,BlueprintType,EditInlineNew,Const,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaDataAssetMetaSetting : public UObject
{
	GENERATED_BODY()

public:
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDataAssetMetaSettingCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="DataAsset")
	TArray<FOmegaDataAssetMetaSettingsInfo> Settings;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Gameplay : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UOmegaSettings_Gameplay();
	
	TArray<UOmegaGameplayModule*> GetModules();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules")
	TArray<UOmegaGameplayModuleSet*> ModuleSets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Modules")
	TArray<UOmegaGameplayModule*> ScriptedModules;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Player")
	TMap<FName,FOmegaInputConfig> InputActionConfigs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="DataAssets",AdvancedDisplay)
	TArray<UOmegaDataAssetMetaSettingCollection*> DataAssetSettingCollections;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="DataAssets",AdvancedDisplay)
	TArray<FOmegaDataAssetMetaSettingsInfo> DataAssetSettings;

	UFUNCTION()
	TArray<FOmegaDataAssetMetaSettingsInfo> GetAllDataAssetMetaSettings()
	{
		TArray<FOmegaDataAssetMetaSettingsInfo> out=DataAssetSettings;
		for (auto* col : DataAssetSettingCollections)
		{
			if(col) { out.Append(col->Settings);}
		}
		return out;
	}
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayStyleFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	

};

