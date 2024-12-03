// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Leveling.h"
#include "Subsystems/OmegaSubsystem_Quest.h"
#include "Widget/DataWidget.h"
#include "Widget/Widget_DynamicMeter.h"
#include "OmegaDemo_Widgets.generated.h"

class UCombatantComponent;
class UOmegaAttribute;

 UActorComponent* local_GetComponentFromObject(UObject* object, TSubclassOf<UActorComponent> Class);

// ==============================================================================================================
// Combatant
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Combatant : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UCombatantComponent* REF_combatant;

public:

	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	UDataList* GetDataList_Attributes();

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	UDataList* GetDataList_Skills();
};

// ==============================================================================================================
// Attribute
// ==============================================================================================================


UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Attribute : public UDataWidget, public IWidgetInterface_Combatant
{
	GENERATED_BODY()

	void local_UpdateColor();
	
	UPROPERTY() UCombatantComponent* REF_Combatant;
	UFUNCTION() void local_OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);

public:
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	virtual void NativePreConstruct() override;
	
	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute",DisplayName="Attribute")
	UOmegaAttribute* REF_attribute;


	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute")
	bool bUseDamageColor;
	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute")
	float DamageColorPercentChange=0.3;
	
	UFUNCTION(BlueprintCallable,Category="DataWidget|Attribute")
	void SetAttribute(UOmegaAttribute* Attribute);
	UFUNCTION(BlueprintPure,Category="DataWidget|Attribute")
	UOmegaAttribute* GetAttribute() const;
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget|Attribute")
	void OnAttributeChanged(UOmegaAttribute* Attribute);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UProgressBar* GetWidget_ProgressBar_Attribute();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDynamicProgressMeter* GetWidget_DynamicMeter_Attribute();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_CurrentValue();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_MaxValue();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UPanelWidget* GetWidget_Panel_MetricValue();

	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute",DisplayName="Attribute",AdvancedDisplay)
	ESlateVisibility PanelVisibility_OnMetric=ESlateVisibility::SelfHitTestInvisible;
	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute",DisplayName="Attribute",AdvancedDisplay)
	ESlateVisibility PanelVisibility_OnStatic=ESlateVisibility::Collapsed;

	virtual void SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant, UObject* ComparedSource, UObject* UncomparedSource) override;
};

// ==============================================================================================================
// Leveling
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Leveling : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() ULevelingComponent* REF_Comp;

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UProgressBar* GetWidget_ProgressBar();
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_RankName();
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_XpName();
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_RankValue();
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_CurrentValue();
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_MaxValue();
};


// ==============================================================================================================
// QUEST
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Quest : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UOmegaQuestComponent* QuestComponent;

public:

	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Quest")
	UDataList* GetDataList_ActiveTasks();

	//Queries the gameplay tags of the active quest tasks to determine which ones will be added to the datalist. (blank allows all)


};

// ==============================================================================================================
// Equipment
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Equipment : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UEquipmentComponent* REF_Comp;

public:
	
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataList* GetDataList_EquipSlots();
};

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_EquipmentSlot : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UEquipmentComponent* REF_Comp;
	UPROPERTY() UEquipmentSlot* REF_Slot;

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void OnNewListOwner_Implementation(UObject* ListOwner) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataWidget* GetDataWidget_EquippedItem();
};

// ==============================================================================================================
// Message
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Message : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UOmegaGameplayMessage* REF_message;

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_Message();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataWidget* GetDataWidget_MessageInstigator();
};