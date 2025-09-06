// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/UI_Widgets.h"

#include "OmegaSettings_Slate.h"

void UOmegaSlateStyle_Button::Apply(UButton* button)
{
	if(button)
	{
		button->SetStyle(ButtonStyle);
		button->SetColorAndOpacity(ButtonColor);
		button->SetBackgroundColor(BackgroundColor);
	}
}

void UOmegaSlateStyle_CheckBox::Apply(UCheckBox* widget)
{
	if(widget)
	{
		widget->SetWidgetStyle(CheckBox);
	}
}

void UOmegaSlateStyle_ComboBox::Apply(UComboBoxString* box)
{
	if(box)
	{
		box->SetWidgetStyle(ComboBox);
		box->SetItemStyle(Item);
		box->SetContentPadding(ContentPadding);
		box->Font=Font;
		box->ScrollBarStyle=ScrollBar;
	}
}

void UOmegaSlateStyle_Border::Apply(UBorder* widget)
{
	if(widget)
	{
		widget->SetBrush(Brush);
		widget->SetPadding(Padding);
	}
}

void UOmegaSlateStyle_Text::Apply(UTextBlock* widget)
{
	if(widget)
	{
		widget->SetFont(Font);
		widget->SetColorAndOpacity(Color);
		widget->SetStrikeBrush(StrikeBrush);
		widget->SetShadowColorAndOpacity(ShadowColor);
		widget->SetShadowOffset(ShadowOffset);
		widget->SetMargin(Margins);
		widget->SetLineHeightPercentage(LineHeightPercentage);
	}
}

UOmegaSlateStyle_Button* UOmegaButton::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaButton::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		L_GetStyle()->Apply(this);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_Slider* UOmegaSlider::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaSlider::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		SetWidgetStyle(L_GetStyle()->Brush_Slider);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_ProgressBar* UOmegaProgressBar::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaProgressBar::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		SetWidgetStyle(L_GetStyle()->Brush_ProgressBar);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_CheckBox* UOmegaCheckBox::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaCheckBox::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		L_GetStyle()->Apply(this);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_ComboBox* UOmegaComboBox::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaComboBox::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		L_GetStyle()->Apply(this);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_Border* UOmegaBorder::L_GetStyle() const
{
	if(bUseDefaultStyle)
	{
		if(UOmegaSettings_Slate* set=UOmegaSlateFunctions::GetCurrentSlateStyle())
		{
			if(set->Styled_Borders.Contains(DefaultStyleToUse))
			{
				return set->Styled_Borders[DefaultStyleToUse].LoadSynchronous();
			}
		}
	}
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaBorder::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		L_GetStyle()->Apply(this);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_Text* UOmegaTextBlock::L_GetStyle() const
{
	if(bUseDefaultStyle)
	{
		if(UOmegaSettings_Slate* set=UOmegaSlateFunctions::GetCurrentSlateStyle())
		{
			if(set->Styled_Text.Contains(DefaultStyleToUse))
			{
				return set->Styled_Text[DefaultStyleToUse].LoadSynchronous();
			}
		}
	}
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaTextBlock::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		L_GetStyle()->Apply(this);
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_RichText* UOmegaRichTextBlock::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaRichTextBlock::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		
	}
	Super::OnWidgetRebuilt();
}

UOmegaSlateStyle_ExpandableArea* UOmegaExpandableArea::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaExpandableArea::OnWidgetRebuilt()
{
	if(L_GetStyle())
	{
		SetStyle(L_GetStyle()->Style);
	}
	Super::OnWidgetRebuilt();
}
