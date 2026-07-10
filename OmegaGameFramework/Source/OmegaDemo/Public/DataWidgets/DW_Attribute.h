// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Interfaces/I_Widget.h"
#include "Widget/DataWidget.h"
#include "DW_Attribute.generated.h"

class UDynamicProgressBar;
class UCombatantComponent;
class UOmegaAttribute;
class UOmegaDamageType;
class UProgressBar;
class UTextBlock;
class UPanelWidget;

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
	
	UFUNCTION(BlueprintImplementableEvent,Category="DataWidget")
	void GetDataWidgetBindings(UProgressBar*& ProgressBar,
		UDynamicProgressBar*& DynaProgressBar,
		UTextBlock*& txt_currentValue,
		UTextBlock*& txt_maxValue,
		UTextBlock*& txt_percentValue);

	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute",DisplayName="Attribute",AdvancedDisplay)
	ESlateVisibility PanelVisibility_OnMetric=ESlateVisibility::SelfHitTestInvisible;
	UPROPERTY(EditAnywhere,Category="DataWidget|Attribute",DisplayName="Attribute",AdvancedDisplay)
	ESlateVisibility PanelVisibility_OnStatic=ESlateVisibility::Collapsed;

	virtual void SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant, UObject* ComparedSource, UObject* UncomparedSource) override;
};
