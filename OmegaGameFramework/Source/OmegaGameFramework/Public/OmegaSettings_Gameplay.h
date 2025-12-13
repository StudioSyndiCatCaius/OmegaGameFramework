// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "Misc/OmegaGameplayModule.h"
#include "NiagaraSystem.h"
#include "OmegaSettings_Gameplay.generated.h"

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
	TArray<UOmegaGameplayModule*> GetModules();
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Modules")
	TArray<UOmegaGameplayModuleSet*> ModuleSets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Modules")
	TArray<UOmegaGameplayModule*> ScriptedModules;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Classes")
	TSubclassOf<AOmegaActor_ChoiceBASE> DefaultChoiceInstance;
	
	// ---------------------------------------------------------------------------
	// Actor
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	TSoftClassPtr<UAnimInstance> DefaultCharacter_AnimClass;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	TSubclassOf<ACharacter> Default_EncounterCharacter;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Actor")
	TMap<TSubclassOf<AActor>,UOmegaActorConfig*> ActorConfig_ByClass;
	
	// ---------------------------------------------------------------------------
	// Combatant
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Combatant")
	UOmegaAttributeSet* Default_AttributeSet;
	
	// ---------------------------------------------------------------------------
	// Zones
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere,Category = "Zone") bool bAutoSpawnAtFirstPoint=true;
	UPROPERTY(EditAnywhere,Category = "Zone") bool bAutoplayZoneBgm=true;
	UPROPERTY(EditAnywhere,Category = "Zone") bool bDynamicCameraViewTargetOnTransit=true;
	UPROPERTY(EditAnywhere,Category = "Zone") float SpawnAtFirstPointDelay=0.1;
	UPROPERTY(EditAnywhere,Category = "Zone") FGameplayTag ZoneBGMSlot;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone") TSubclassOf<AZoneEntityDisplayActor> DefaultZoneEntityDisplayActor;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone") TSoftClassPtr<AOmegaGameplaySystem> ZoneTransitSystem;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone") TSoftObjectPtr<UNiagaraSystem> DefaultZoneTransitParticle;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone") TSoftObjectPtr<ULevelSequence> Sequence_ZoneTransit;

	// ---------------------------------------------------------------------------
	// Systems
	// ---------------------------------------------------------------------------

	//Triggered with Demo CombatEncounter events
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Systems")
	TSoftClassPtr<AOmegaGameplaySystem> System_CombatEncounter;

	//Triggered with Demo FlowAsset events
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Systems")
	TSoftClassPtr<AOmegaGameplaySystem> System_FlowAsset;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Systems",DisplayName="Systems (Auto Activated)")
	TArray<TSubclassOf<AOmegaGameplaySystem>> System_AutoActivated;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Systems",DisplayName="Systems (Named)")
	TMap<FName,TSubclassOf<AOmegaGameplaySystem>> System_Named;
	// ---------------------------------------------------------------------------
	// Data Asset
	// ---------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Misc",AdvancedDisplay)
	TArray<UOmegaDataAssetMetaSettingCollection*> DataAssetSettingCollections;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category="Misc",AdvancedDisplay)
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

	
	UPROPERTY()
	TArray<UOmegaSettings_Gameplay_InputEvent*> CustomInputEvents;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Advanced")
	TArray<UOmegaGameplayMetaSettingsCollection*> MetaSettingsCollections;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Instanced, Category="Advanced")
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
	
	UFUNCTION(BlueprintCallable,Category="Omega|Gameplay",meta=(DeterminesOutputType="Class", ExpandBoolAsExecs="Result"))
	static UOmegaDataAssetMetaSetting* GetDataAssetMetaSetting(UPrimaryDataAsset* DataAsset, TSubclassOf<UOmegaDataAssetMetaSetting> Class, bool& Result);

};

