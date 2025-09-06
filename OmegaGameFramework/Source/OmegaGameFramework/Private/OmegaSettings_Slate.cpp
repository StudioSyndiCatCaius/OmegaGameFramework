// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Slate.h"

#include "CommonBorder.h"
#include "CommonTextBlock.h"
#include "OmegaSettings.h"
#include "Components/Button.h"
#include "Functions/OmegaFunctions_Text.h"
#include "Widget/DataWidget.h"

UOmegaSettings_Slate::UOmegaSettings_Slate()
{
	Styled_Borders.Add(EOmegaSlateBorderType::Background,nullptr);
	Styled_Borders.Add(EOmegaSlateBorderType::Big,nullptr);
	Styled_Borders.Add(EOmegaSlateBorderType::Button,nullptr);
	Styled_Borders.Add(EOmegaSlateBorderType::Medium,nullptr);
	Styled_Borders.Add(EOmegaSlateBorderType::Minimal,nullptr);
	Styled_Borders.Add(EOmegaSlateBorderType::Small,nullptr);

	Styled_Text.Add(EOmegaSlateTextType::Header1,nullptr);
	Styled_Text.Add(EOmegaSlateTextType::Header2,nullptr);
	Styled_Text.Add(EOmegaSlateTextType::Header3,nullptr);
	Styled_Text.Add(EOmegaSlateTextType::Paragraph,nullptr);
	Styled_Text.Add(EOmegaSlateTextType::Tiny,nullptr);
}

FText UOmegaSettings_Slate::L_FormatDataWidgetText(UDataWidget* w, FText t) const
{
	if(TextFormater && w && DataWidgets_AutoFormatText)
	{
		FOmegaCommonMeta met;
		met.Context=nullptr;
		if(w->ReferencedAsset)
		{
			met.Context=w->ReferencedAsset;
		}
		return TextFormater->ApplyTextFormat(t, w,DataWidgets_TextFormatTag,met);
	}
	return t;
}

UOmegaSettings_Slate* UOmegaSlateFunctions::GetCurrentSlateStyle()
{
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultSettings_Slate.TryLoad())
	{
		return Cast<UOmegaSettings_Slate>(style_ref);
	}
	return nullptr;
}

void UOmegaSlateFunctions::SetSlateStyle_AllWidgets(UPanelWidget* Parent, EOmegaSlateTextType TextType, EOmegaSlateBorderType BorderType)
{
	if (!Parent) return;

	for (int32 i = 0; i < Parent->GetChildrenCount(); ++i) {
		if (auto* ChildWidget = Cast<UWidget>(Parent->GetChildAt(i))) {

			if (auto* Border = Cast<UCommonBorder>(ChildWidget)) {
				SetSlateStyle_Border(Border,BorderType);
			} else if (auto* Text = Cast<UCommonTextBlock>(ChildWidget)) {
				SetSlateStyle_Text(Text,TextType);
			} else if (auto* Slider = Cast<USlider>(ChildWidget)) {
				SetSlateStyle_Slider(Slider);
			} else if (auto* ProgressBar = Cast<UProgressBar>(ChildWidget)) {
				SetSlateStyle_ProgressBar(ProgressBar);
			} else if (auto* ComboBox = Cast<UComboBoxString>(ChildWidget)) {
				//SetSlateStyle_ComboBox(ComboBox);
			} else if (auto* Button = Cast<UButton>(ChildWidget)) {
				SetSlateStyle_Button(Button);
			} else if (auto* CheckBox = Cast<UCheckBox>(ChildWidget)) {
				SetSlateStyle_Checkbox(CheckBox);
			}

			// Recursively process if the child is also a UPanelWidget
			if (auto* ChildPanel = Cast<UPanelWidget>(ChildWidget)) {
				SetSlateStyle_AllWidgets(ChildPanel,TextType,BorderType);
			}
		}
	}
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

void UOmegaSlateFunctions::SetSlateStyle_Button(UButton* widget)
{
	if(GetCurrentSlateStyle() && widget && GetCurrentSlateStyle()->Button_Default)
	{
		widget->SetStyle(GetCurrentSlateStyle()->Button_Default->ButtonStyle);
	}
}

void UOmegaSlateFunctions::SetSlateStyle_ProgressBar(UProgressBar* widget)
{
	if(GetCurrentSlateStyle() && widget && GetCurrentSlateStyle()->ProgressBar_Default)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->ProgressBar_Default->Brush_ProgressBar);
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Slider(USlider* widget)
{
	if(GetCurrentSlateStyle() && widget && GetCurrentSlateStyle()->Slider_Default)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->Slider_Default->Brush_Slider);
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Checkbox(UCheckBox* widget)
{
	if(GetCurrentSlateStyle() && widget && GetCurrentSlateStyle()->Checkbox_default)
	{
		widget->SetWidgetStyle(GetCurrentSlateStyle()->Checkbox_default->CheckBox);
	}
}

FLinearColor UOmegaSlateFunctions::GetSlateColor_ByIndex(int32 index)
{
	if(GetCurrentSlateStyle())
	{
		if(index==0) {return GetCurrentSlateStyle()->Color_1; }
		if(index==1) {return GetCurrentSlateStyle()->Color_2; }
		if(index==2) {return GetCurrentSlateStyle()->Color_3; }
		if(index==3) {return GetCurrentSlateStyle()->Color_4; }
	}
	return FLinearColor();
}

FLinearColor UOmegaSlateFunctions::GetSlateColor_ByTag(FGameplayTag Tag, FLinearColor Fallback)
{
	if(GetCurrentSlateStyle()->Colors_Tagged.Contains(Tag)){ return GetCurrentSlateStyle()->Colors_Tagged.FindOrAdd(Tag);}
	return Fallback;
}

