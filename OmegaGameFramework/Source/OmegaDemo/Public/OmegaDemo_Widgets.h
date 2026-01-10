// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CheckBox.h"
#include "Components/Component_Equipment.h"
#include "Components/Component_Leveling.h"
#include "Components/Component_Skin.h"
#include "Components/Slider.h"
#include "Interfaces/I_Widget.h"
#include "Subsystems/Subsystem_Quest.h"
#include "Widget/DataWidget.h"
#include "Widget/Widget_DynamicMeter.h"
#include "Widget/ColorWheel/ColorWidget.h"
#include "OmegaDemo_Widgets.generated.h"

class UWidgetSwitcher;
class UCombatantComponent;
class UOmegaAttribute;

 UActorComponent* local_GetComponentFromObject(UObject* object, TSubclassOf<UActorComponent> Class);

// ==============================================================================================================
// Combatant
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Combatant : public UDataWidget, public IWidgetInterface_Combatant
{
	GENERATED_BODY()

	UPROPERTY() UCombatantComponent* REF_combatant;

	virtual void Native_OnSourceAssetChanged(UObject* SourceAsset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
public:

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnCombatantNotify(UCombatantComponent* Combatant, FName Notify, const FString& Flag);

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Attributes();
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Attributes_Metric();
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Attributes_Static();
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget") UDataList* GetDataList_Skills();

	virtual void SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant, UObject* ComparedSource, UObject* UncomparedSource) override;
};

// ==============================================================================================================
// Attribute
// ==============================================================================================================


UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_Attribute : public UDataWidget, public IWidgetInterface_Combatant
{
	GENERATED_BODY()

	void local_Update();
	
	UPROPERTY() UCombatantComponent* REF_Combatant;
	UFUNCTION() void local_OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, class UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit);

public:
	virtual void Native_OnSourceAssetChanged(UObject* SourceAsset) override;
	virtual void Native_OnListOwnerChanged(UObject* ListOwner) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;
	virtual void NativePreConstruct() override;
	
	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute",DisplayName="Attribute")
	UOmegaAttribute* REF_attribute;

	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute")
	bool bUseDamageColor;
	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute")
	float DamageColorPercentChange=0.3;

	UFUNCTION(BlueprintCallable,Category="DataWidget|Attribute")
	void SetCombatant(UCombatantComponent* Combatant);
	UFUNCTION(BlueprintPure,Category="DataWidget|Attribute")
	UCombatantComponent* GetCombatant() const;
	
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

	void L_SetLevelComp(ULevelingComponent* comp);
	UPROPERTY() ULevelingComponent* REF_Comp;
	UFUNCTION() void L_onXP(ULevelingComponent* comp,float xp,float changed,UOmegaLevelingAsset* asset);

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnListOwnerChanged(UObject* ListOwner) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Leveling")
	UOmegaLevelingAsset* LevelingAsset=nullptr;

	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnLevelingComponentChanged(ULevelingComponent* Component);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UOmegaLevelingAsset* GetLevelingAsset();
	
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

	UPROPERTY() bool __bTextIsUpdating;
	UPROPERTY() float __TextWriteTime;
	UPROPERTY() TArray<FString> __stringsRemaining;
	UPROPERTY() int32 __stringAmount;

	
	UPROPERTY() UOmegaGameplayMessage* REF_message;
	UPROPERTY() UObject* REF_lastInstigator=nullptr;
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void Native_OnSourceAssetChanged(UObject* SourceAsset) override;

	UPROPERTY(EditAnywhere,Category="Message")
	bool bWriteTextOverTime;
	UPROPERTY(EditAnywhere,Category="Message")
	float TextWriteFrequency=0.02;
	
	UFUNCTION(BlueprintPure,Category="DataWidget")
	UOmegaGameplayMessage* GetCurrentMessage() const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnMessageUpdate(UOmegaGameplayMessage* Message);
	
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void OnInstigatorChange(UObject* New=nullptr,UObject* Old=nullptr);
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_Message();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataWidget* GetDataWidget_MessageInstigator();

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UImage* GetImage_InstigatorBrush();
};

// ==============================================================================================================
// Body Option
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_BodySlot : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UOmegaBodySlot* REF_Slot;
	UPROPERTY() USkinComponent* REF_Comp;

	UFUNCTION() void local_OnCheckChanged( bool bIsChecked);
	UFUNCTION() void local_SliderValueUpdate(float value);
	UFUNCTION() void local_onColorChange(const FLinearColor& color);

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UDataList* GetDataList_Options();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	USlider* GetWidget_Slider_Float();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	USlider* GetWidget_Slider_Int();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UColorWidget* GetWidget_Color();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UCheckBox* GetWidget_ToggleCheckBox();
};


// ==============================================================================================================
// Body Option
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_SaveSlot : public UDataWidget
{
	GENERATED_BODY()

public:
	virtual void OnSourceAssetChanged_Implementation(UObject* Asset) override;
	virtual void Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner) override;

	UFUNCTION(BlueprintImplementableEvent,Category="Save")
	void OnSaveWidgetInit(UOmegaSaveGame* Save);

	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UWidgetSwitcher* GetWidget_Switcher_Type();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_Playime();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_LevelName();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UTextBlock* GetWidget_Text_ZoneName();
	UFUNCTION(BlueprintImplementableEvent,BlueprintPure,Category="DataWidget")
	UImage* GetWidget_Image_Screenshot();

};