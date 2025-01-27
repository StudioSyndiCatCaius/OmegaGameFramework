// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "OmegaSettings_Gameplay.generated.h"

class UEquipmentSlot;
class UOmegaAttribute;
class AZoneEntityDisplayActor;

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
class OMEGAGAMEFRAMEWORK_API UOmegaSettings_Gameplay : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_Splash;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_Title;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Maps")
	TSoftObjectPtr<UWorld> Map_NewGame;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_Character;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_Player;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Abilities")
	TArray<TSubclassOf<AOmegaAbility>> Abilities_NonPlayer;

	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Zone")
	TSubclassOf<AZoneEntityDisplayActor> DefaultZoneEntityDisplayActor;

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
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Instanced, Category="Systems")
	TArray<UOmegaGameplayMetaSettings*> MetaSettings;

};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayStyleFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Gameplay", DisplayName="Get Gameplay Settings")
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

};