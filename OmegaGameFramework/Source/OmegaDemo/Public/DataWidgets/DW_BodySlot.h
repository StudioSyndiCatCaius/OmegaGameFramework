// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CheckBox.h"
#include "Components/Component_Skin.h"
#include "Components/Slider.h"
#include "Widget/DataWidget.h"
#include "Widget/ColorWheel/ColorWidget.h"
#include "DW_BodySlot.generated.h"

class UDataList;

// ==============================================================================================================
// Body Slot
// ==============================================================================================================

UCLASS(Abstract)
class OMEGADEMO_API UDataWidgetBase_BodySlot : public UDataWidget
{
	GENERATED_BODY()

	UPROPERTY() UOmegaBodySlot* REF_Slot;
	UPROPERTY() USkinComponent* REF_Comp;

	UFUNCTION() void local_OnCheckChanged(bool bIsChecked);
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
