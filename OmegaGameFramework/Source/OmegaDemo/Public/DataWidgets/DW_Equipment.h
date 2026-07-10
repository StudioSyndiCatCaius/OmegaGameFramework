// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataWidgets/DW_Combatant.h"
#include "Functions/F_Equipment.h"
#include "DW_Equipment.generated.h"

class UDataList;
class UDataWidget;

// ==============================================================================================================
// Equipment
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Equipment : public UDataWidgetBase_CombatantBASE
{
	GENERATED_BODY()

public:

	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataList* GetDataList_EquipSlots();
};

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_EquipmentSlot : public UDataWidgetBase_CombatantBASE
{
	GENERATED_BODY()

	UPROPERTY() UEquipmentSlot* REF_Slot;

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void OnNewListOwner_Implementation(UObject* ListOwner) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataWidget* GetDataWidget_EquippedItem();
};
