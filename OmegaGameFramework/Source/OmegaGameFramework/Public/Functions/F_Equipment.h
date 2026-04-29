// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Combatant.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "F_Equipment.generated.h"

class UOmegaCondition_DataAsset;
class UDataAssetCollectionComponent;

UINTERFACE(MinimalAPI) class UDataInterface_Equipable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Equipable
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Equipment",DisplayName="Equipable - Can Equip?")
	bool CanEquipItem(UCombatantComponent* Component,UEquipmentSlot* Slot);
	
};

UINTERFACE(MinimalAPI) class UDataInterface_EquipmentSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_EquipmentSource
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent,Category="ΩI|Equipment",DisplayName="Equipment Source - Get Equipment")
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipment();
};

UCLASS()
class UOmegaEquipmentFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Equipment",DisplayName="🗡️Equipment - Is Item Equippable?")
	static bool IsItemEquippable(UPrimaryDataAsset* item, UCombatantComponent* component, UEquipmentSlot* Slot);

	UFUNCTION(BlueprintPure,Category="Omega|Equipment",DisplayName="🗡️Equipment - Filter Equippables")
	static TArray<UPrimaryDataAsset*> FilterEquippableItems(TArray<UPrimaryDataAsset*> items, UCombatantComponent* component, UEquipmentSlot* Slot);

	UFUNCTION(BlueprintCallable,Category="Omega|Equipment",meta=(AdvancedDisplay="bIncludedSources"))
	static TArray<UPrimaryDataAsset*> GetEquippableItems_FromInventory(UCombatantComponent* Equipment,UCombatantComponent* Inventory,UEquipmentSlot* Slot,bool bIncludedSources=true);

	UFUNCTION(BlueprintCallable,Category="Omega|Equipment")
	static TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipmentFromLinkedAssetList(TMap<UPrimaryDataAsset*,UPrimaryDataAsset*> list);
};
