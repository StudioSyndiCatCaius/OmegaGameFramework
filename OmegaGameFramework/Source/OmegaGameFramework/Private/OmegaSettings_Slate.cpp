// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Slate.h"

#include "CommonBorder.h"
#include "CommonTextBlock.h"
#include "OmegaSettings.h"
#include "Components/Button.h"
#include "Functions/F_Text.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Widget/DataWidget.h"


UOmegaStyleSettings::UOmegaStyleSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
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
	
	Sound_Cycle=OGF_UASSET_SOUND_UI(wav_ui_maximize_003);
	Sound_Error=OGF_UASSET_SOUND_UI(wav_ui_error);
	Sound_Hover=OGF_UASSET_SOUND_UI(wav_ui_tick_001);
	Sound_Menu_Close=OGF_UASSET_SOUND_UI(wav_ui_minimize_001);
	Sound_Menu_Open=OGF_UASSET_SOUND_UI(wav_ui_maximize_001);
	Sound_Select=OGF_UASSET_SOUND_UI(wav_ui_click1);
	
}

TArray<UOmegaTextFormater_Collection*> UOmegaStyleSettings::L_GetTextFormaters()
{
	TArray<UOmegaTextFormater_Collection*> out;
	for (auto t :TextFormaters)
	{
		if (UOmegaTextFormater_Collection* o=Cast<UOmegaTextFormater_Collection>(t.LoadSynchronous()))
		{
			out.Add(o);
		}
	}
	return out;
}

FText UOmegaStyleSettings::L_FormatGameplayText(FText text, UObject* WorldContext, FGameplayTag Tag, FOmegaCommonMeta meta)
{
	FText out=text;
	for (auto* o : L_GetTextFormaters())
	{
		if (o)
		{
			out=o->ApplyTextFormat(out,WorldContext,Tag,meta);
		}
	}
	return out;
}

void UOmegaSlateFunctions::SetSlateStyle_AllWidgets(UPanelWidget* Parent, EOmegaSlateTextType TextType, EOmegaSlateBorderType BorderType)
{
	if (!Parent) return;

	for (int32 i = 0; i < Parent->GetChildrenCount(); ++i) {
		if (auto* ChildWidget = Cast<UWidget>(Parent->GetChildAt(i))) {

			if (auto* Border = Cast<UOmegaBorder>(ChildWidget)) {
				SetSlateStyle_Border(Border,BorderType);
			} else if (auto* Text = Cast<UCommonTextBlock>(ChildWidget)) {
				//SetSlateStyle_Text(Text,TextType);
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


void UOmegaSlateFunctions::SetSlateStyle_WidgetChildren_Text(UPanelWidget* widget, EOmegaSlateTextType Type)
{
	if(widget)
	{
		for(auto* temp_child : widget->GetAllChildren())
		{
			
		}
	}
}




void UOmegaSlateFunctions::SetSlateStyle_Button(UButton* widget)
{
	if(widget)
	{
		if (UOmegaSlateStyle_Button* style=GetMutableDefault<UOmegaStyleSettings>()->Button_Default.LoadSynchronous())
		{
			widget->SetStyle(style->ButtonStyle);			
		}
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Border(UOmegaBorder* widget, EOmegaSlateBorderType type)
{
	if(widget)
	{
		widget->SetStyleAsset(OGF_CFG_STYLE()->Styled_Borders.FindOrAdd(type).LoadSynchronous());
	}
}

void UOmegaSlateFunctions::SetSlateStyle_ProgressBar(UProgressBar* widget)
{
	if(widget)
	{
		if (UOmegaSlateStyle_ProgressBar* style=GetMutableDefault<UOmegaStyleSettings>()->ProgressBar_Default.LoadSynchronous())
		{
			widget->SetWidgetStyle(style->Brush_ProgressBar);
		}
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Slider(USlider* widget)
{
	if(widget)
	{
		if (UOmegaSlateStyle_Slider* style=GetMutableDefault<UOmegaStyleSettings>()->Slider_Default.LoadSynchronous())
		{
		widget->SetWidgetStyle(style->Brush_Slider);
		}
	}
}

void UOmegaSlateFunctions::SetSlateStyle_Checkbox(UCheckBox* widget)
{
	if(widget)
	{
		if (UOmegaSlateStyle_CheckBox* style=GetMutableDefault<UOmegaStyleSettings>()->Checkbox_default.LoadSynchronous())
		{
		widget->SetWidgetStyle(style->CheckBox);
		}
	}
}

