// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Engine/DataAsset.h"
#include "Misc/OmegaGameplayModule.h"
#include "Misc/OmegaUtils_Enums.h"
#include "UObject/Object.h"
#include "OmegaSettings_Gameplay.generated.h"

class UOAsset_ActorModifierCollection;
class UEquipmentSlot;
class UOmegaAttribute;
class AZoneEntityDisplayActor;
class UOmegaCharacterConfig;
class UOmegaActorConfig;
class USubscriptCollection;
class AOmegaActorProcessor;

// ------------------------------------------------------------------------------------------------------------------------
// Data Asset MetaSettings
// ------------------------------------------------------------------------------------------------------------------------

USTRUCT(Blueprintable,BlueprintType)
struct FOmegaDataAssetMetaSettingsInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Settings")
	UPrimaryDataAsset* DataAsset;
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


UCLASS(Blueprintable,BlueprintType,EditInlineNew,Const)
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayMetaSettings : public UObject
{
	GENERATED_BODY()

public:
	
};

UCLASS(Blueprintable,BlueprintType,EditInlineNew,CollapseCategories,Const)
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Gameplay_InputEvent : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input") TArray<FKey> InputKeys;
	// Requires gameplay systems with the following tags to be active. If blank, always a success.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input") FGameplayTagContainer GameplaySystem_Required;

	UFUNCTION(BlueprintImplementableEvent,Category="InputEvent")
	void OnInput_Start(APlayerController* Controller, UOmegaGameplaySubsystem* GameplaySubsystem) const;

	UFUNCTION(BlueprintImplementableEvent,Category="InputEvent")
	void OnInput_End(APlayerController* Controller, UOmegaGameplaySubsystem* GameplaySubsystem) const;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayMetaSettingsCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Instanced, Category="Systems")
	TArray<UOmegaGameplayMetaSettings*> MetaSettings;
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Gameplay : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Modules")
	TArray<UOmegaGameplayModule*> ScriptedModules;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_Splash;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_Title;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_NewGame;
	
	// ---------------------------------------------------------------------------
	// Actor
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	TArray<TSubclassOf<AOmegaActorProcessor>> ActorProcessors;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor",DisplayName="Subscripts (Character)")
	TArray<USubscriptCollection*> SubscriptCollections_Character;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	UOmegaCharacterConfig* DefaultActorConfig_Character;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	UOmegaActorConfig* DefaultActorConfig_Interactable;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	UOmegaActorConfig* DefaultActorConfig_FloatingCombatant;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Actor")
	UOAsset_ActorModifierCollection* ActorMods_Character;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Actor")
	UOAsset_ActorModifierCollection* ActorMods_Interactable;
	
	// ---------------------------------------------------------------------------
	// Abilities
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_Character;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_Player;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_NonPlayer;

	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone")
	TSubclassOf<AZoneEntityDisplayActor> DefaultZoneEntityDisplayActor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone")
	UStaticMesh* ZoneTransitDisplayMesh=nullptr;

	// ---------------------------------------------------------------------------
	// Data Asset
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="DataAssets")
	TArray<UOmegaDataAssetMetaSettingCollection*> DataAssetSettingCollections;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="DataAssets")
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
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="DataAssets")
	TMap<FGameplayTag, UPrimaryDataAsset*> GlobalDataAssets_Common;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="DataAssets")
	TMap<FGameplayTag, UOmegaAttribute*> GlobalDataAssets_Attribute;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="DataAssets")
	TMap<FGameplayTag, UEquipmentSlot*> GlobalDataAssets_EquipSlot;
	
	
	UPROPERTY()
	TArray<UOmegaSettings_Gameplay_InputEvent*> CustomInputEvents;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Systems")
	TSubclassOf<AOmegaGameplaySystem> System_Dialogue;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Systems")
	TSubclassOf<AOmegaGameplaySystem> System_Battle;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="MetaSettings")
	TArray<UOmegaGameplayMetaSettingsCollection*> MetaSettingsCollections;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Instanced, Category="MetaSettings")
	TArray<UOmegaGameplayMetaSettings*> MetaSettings;


	UFUNCTION()
	TArray<UOmegaGameplayMetaSettings*> GetAllMetaSettings()
	{
		TArray<UOmegaGameplayMetaSettings*> out=MetaSettings;
		for (auto* col : MetaSettingsCollections)
		{
			if(col) { out.Append(col->MetaSettings);}
		}
		return out;
	}
	

};


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayStyleFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Settings", DisplayName="Get OMEGA Settings (Gameplay)")
	static UOmegaSettings_Gameplay* GetCurrentGameplayStyle();
	
	UFUNCTION(BlueprintPure,Category="Omega|Gameplay", DisplayName="Get Gameplay Meta Settings",meta=(DeterminesOutputType="Class"))
    static UOmegaGameplayMetaSettings* GetCurrentGameplayMetaStyle(TSubclassOf<UOmegaGameplayMetaSettings> Class);

	UFUNCTION(BlueprintCallable,Category="Omega|Gameplay")
	static bool OmegaGameplayInputCall(APlayerController* Player, const FKey& Key, bool End);

	UFUNCTION(BlueprintPure,Category="Omega|Gameplay|GlobalDataAssets",DisplayName="Get Global DataAsset (Common)",meta=(CompactNodeTitle="DA Common"))
	static UPrimaryDataAsset* GetGlobalDataAsset_Common(FGameplayTag Tag);
	UFUNCTION(BlueprintPure,Category="Omega|Gameplay|GlobalDataAssets",DisplayName="Get Global DataAsset (Attribute)",meta=(CompactNodeTitle="GDA Attribute"))
    static UOmegaAttribute* GetGlobalDataAsset_Attribute(FGameplayTag Tag);
	UFUNCTION(BlueprintPure,Category="Omega|Gameplay|GlobalDataAssets",DisplayName="Get Global DataAsset (Equipment Slot)",meta=(CompactNodeTitle="GDA EquipSlot"))
	static UEquipmentSlot* GetGlobalDataAsset_EquipSlot(FGameplayTag Tag);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Gameplay",meta=(DeterminesOutputType="Class", ExpandBoolAsExecs="Result"))
	static UOmegaDataAssetMetaSetting* GetDataAssetMetaSetting(UPrimaryDataAsset* DataAsset, TSubclassOf<UOmegaDataAssetMetaSetting> Class, bool& Result);

};

