// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Widget.h"
#include "Widget/DataWidget.h"
#include "DW_Combatant.generated.h"

class UCombatantComponent;
class UDataList;

// ==============================================================================================================
// Combatant
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_CombatantBASE : public UDataWidget, public IWidgetInterface_Combatant
{
	GENERATED_BODY()
public:
	UPROPERTY() UCombatantComponent* REF_combatant;
	UFUNCTION()
	void L_Refresh(UCombatantComponent* Combatant);
	virtual void Native_OnSourceAssetChanged(UObject* SourceAsset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	UFUNCTION(BlueprintPure,Category="Combatant") UCombatantComponent* GetLinkedCombatant();
};

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Combatant : public UDataWidgetBase_CombatantBASE
{
	GENERATED_BODY()

public:
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnCombatantNotify(UCombatantComponent* Combatant, FName Notify, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Attributes();
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Attributes_Metric();
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Attributes_Static();
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Skills();

	virtual void SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant, UObject* ComparedSource, UObject* UncomparedSource) override;
};
