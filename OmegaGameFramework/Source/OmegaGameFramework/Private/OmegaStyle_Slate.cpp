// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaStyle_Slate.h"

#include "OmegaSettings.h"

UOmegaSlateStyle* UOmegaSlateFunctions::GetCurrentSlateStyle()
{
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultSlateStyle.TryLoad())
	{
		return Cast<UOmegaSlateStyle>(style_ref);
	}
	return nullptr;
}

void UOmegaSlateFunctions::SetSlateStyle_Text(UCommonTextBlock* widget, EOmegaSlateTextType Type)
{
	if(GetCurrentSlateStyle() && widget)
	{
		switch (Type) {
			case Header1:
				widget->SetStyle(GetCurrentSlateStyle()->Text_Header_1);
				break;
			case Header2:
				widget->SetStyle(GetCurrentSlateStyle()->Text_Header_2); break;
			case Header3:
				widget->SetStyle(GetCurrentSlateStyle()->Text_Header_3); break;
			case Paragraph:
				widget->SetStyle(GetCurrentSlateStyle()->Text_Paragraph); break;
			case Tiny:
				widget->SetStyle(GetCurrentSlateStyle()->Text_Tiny); break;
			default: ;
		}
	}
}

void UOmegaSlateFunctions::SetSlateStyle_WidgetChildren_Text(UPanelWidget* widget, EOmegaSlateTextType Type)
{
	if(widget)
	{
		for(auto* temp_child : widget->GetAllChildren())
		{
			if(UCommonTextBlock* text = Cast<UCommonTextBlock>(temp_child))
			{
				SetSlateStyle_Text(text,Type);
			}
		}
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Border(UCommonBorder* widget, EOmegaSlateBorderType type)
{
	if(GetCurrentSlateStyle() && widget)
	{
		switch (type) {
		case Big: 
			widget->SetStyle(GetCurrentSlateStyle()->Border_Big); break;
		case Medium: 
			widget->SetStyle(GetCurrentSlateStyle()->Border_Medium); break;
		case Small: 
			widget->SetStyle(GetCurrentSlateStyle()->Border_Small); break;
		case Button: 
			widget->SetStyle(GetCurrentSlateStyle()->Border_Button); break;
		case Minimal:
			widget->SetStyle(GetCurrentSlateStyle()->Border_Minimal); break;
		case Background:
			widget->SetStyle(GetCurrentSlateStyle()->Border_Background); break;
			default: ;
		}
	}
}


void UOmegaSlateFunctions::SetSlateStyle_ProgressBar(UProgressBar* widget)
{
	if(GetCurrentSlateStyle() && widget)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->ProgressBar_Default);
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Slider(USlider* widget)
{
	if(GetCurrentSlateStyle() && widget)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->Slider_Default);
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Checkbox(UCheckBox* widget)
{
	if(GetCurrentSlateStyle() && widget)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->Checkbox_default);
	}
}

void UOmegaSlateFunctions::SetSlateStyle_ComboBox(UComboBoxString* widget)
{
	if(GetCurrentSlateStyle() && widget)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->ComboBox_Default);
		widget->SetItemStyle(GetCurrentSlateStyle()->ComboBoxItem_Default);
	}
}

