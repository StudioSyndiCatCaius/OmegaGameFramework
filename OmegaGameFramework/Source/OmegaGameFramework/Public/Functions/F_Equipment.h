// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Combatant.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "F_Equipment.generated.h"

class UOmegaCondition_DataAsset;
class UDataAssetCollectionComponent;

UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - 🗡️Equipable") class UDataInterface_Equipable : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Equipable
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🗡️Equipment",DisplayName="🗡️Equipable - Can Equip?")
	bool CanEquipItem(UCombatantComponent* Component,UEquipmentSlot* Slot);
	
};

UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Equipment Source") class UDataInterface_EquipmentSource : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_EquipmentSource
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent,Category="♎I|🗡️Equipment",DisplayName="Equipment Source - Get Equipment")
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipment();
};

UCLASS()
class UOmegaEquipmentFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure,Category="Omega|Equipment",DisplayName="🗡️Equipment - Filter Equippables")
	static TArray<UPrimaryDataAsset*> FilterEquippableItems(TArray<UPrimaryDataAsset*> items, UCombatantComponent* component, UEquipmentSlot* Slot);

	UFUNCTION(BlueprintCallable,Category="Omega|Equipment",meta=(AdvancedDisplay="bIncludedSources"))
	static TArray<UPrimaryDataAsset*> GetEquippableItems_FromInventory(UCombatantComponent* Combatant,UCombatantComponent* Inventory,UEquipmentSlot* Slot,int32 FilterMinimum=1);

	UFUNCTION()
	static TMap<UEquipmentSlot*,UPrimaryDataAsset*> GetEquipmentFromLinkedAssetList(TMap<UPrimaryDataAsset*,UPrimaryDataAsset*> list);
};
