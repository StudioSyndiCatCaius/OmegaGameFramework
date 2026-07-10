// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_BodySlot.h"
#include "DataAssets/DA_Body.h"
#include "Functions/F_Common.h"


void UDataWidgetBase_BodySlot::local_OnCheckChanged(bool bIsChecked)
{
	if(REF_Slot && REF_Comp)
	{
		REF_Comp->SetBodyParam_Bool(REF_Slot,bIsChecked);
	}
}

void UDataWidgetBase_BodySlot::local_SliderValueUpdate(float value)
{
	if(REF_Slot && REF_Comp)
	{
		REF_Comp->SetBodyParam_Float(REF_Slot,value);
	}
}

void UDataWidgetBase_BodySlot::local_onColorChange(const FLinearColor& color)
{
}

void UDataWidgetBase_BodySlot::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_BodySlot::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
	if(UActorComponent* temp_comp = local_GetComponentFromObject(ListOwner,USkinComponent::StaticClass()))
	{
		REF_Comp=Cast<USkinComponent>(temp_comp);
	}

	if(SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaBodySlot::StaticClass()))
	{
		REF_Slot=Cast<UOmegaBodySlot>(SourceAsset);
		if(REF_Comp)
		{
			if(GetWidget_ToggleCheckBox())
			{
				GetWidget_ToggleCheckBox()->SetIsChecked(REF_Comp->GetBodyParam_Bool(REF_Slot));
				GetWidget_ToggleCheckBox()->OnCheckStateChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_OnCheckChanged);
			}
			if(GetWidget_Slider_Float())
			{
				GetWidget_Slider_Int()->SetMaxValue(REF_Slot->GetMaxValue().X);
				GetWidget_Slider_Float()->SetValue(REF_Comp->GetBodyParam_Float(REF_Slot));
				GetWidget_Slider_Float()->OnValueChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_SliderValueUpdate);
			}
			if(GetWidget_Slider_Int())
			{
				GetWidget_Slider_Int()->SetMaxValue(REF_Slot->GetMaxValue().X);
				GetWidget_Slider_Int()->SetStepSize(1.0);
				GetWidget_Slider_Int()->MouseUsesStep=true;
				GetWidget_Slider_Int()->SetValue(REF_Comp->GetBodyParam_Int(REF_Slot));
				GetWidget_Slider_Int()->OnValueChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_SliderValueUpdate);
			}
			if(GetWidget_Color())
			{
				GetWidget_Color()->OnColorChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_onColorChange);
				GetWidget_Color()->SetColor(FLinearColor(REF_Comp->GetBodyParam_Vector(REF_Slot)));
			}
		}
	}
}
