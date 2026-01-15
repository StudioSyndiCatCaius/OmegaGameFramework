// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/UI_Widgets.h"

#include "OmegaSettings_Slate.h"
#include "Misc/OmegaUtils_Macros.h"

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
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaButton::SetStyleAsset(UOmegaSlateStyle_Button* Style)
{
	if(L_GetStyle())
	{
		L_GetStyle()->Apply(this);
	}
}

UOmegaSlateStyle_Slider* UOmegaSlider::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaSlider::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaSlider::SetStyleAsset(UOmegaSlateStyle_Slider* Style)
{
	if (Style)
	{
		StyleAsset=Style;
		if(L_GetStyle())
		{
			SetWidgetStyle(L_GetStyle()->Brush_Slider);
		}
	}
}

UOmegaSlateStyle_ProgressBar* UOmegaProgressBar::L_GetStyle() const
{
	if (UseDefaultStyle)
	{
		if (UOmegaSlateStyle_ProgressBar* _style=OGF_CFG_STYLE()->ProgressBar_Default.LoadSynchronous())
		{
			return _style;
		}
	}
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaProgressBar::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaProgressBar::SetStyleAsset(UOmegaSlateStyle_ProgressBar* Style)
{
	if (Style)
	{
		StyleAsset=Style;
		if(L_GetStyle())
		{
			SetWidgetStyle(L_GetStyle()->Brush_ProgressBar);
		}
	}
}

UOmegaSlateStyle_CheckBox* UOmegaCheckBox::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaCheckBox::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaCheckBox::SetStyleAsset(UOmegaSlateStyle_CheckBox* Style)
{
	if (Style)
	{
		StyleAsset=Style;
		if(L_GetStyle())
		{
			L_GetStyle()->Apply(this);
		}
	}
}

UOmegaSlateStyle_ComboBox* UOmegaComboBox::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaComboBox::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaComboBox::SetStyleAsset(UOmegaSlateStyle_ComboBox* Style)
{
	if (Style)
	{
		StyleAsset=Style;
		if(L_GetStyle())
		{
			L_GetStyle()->Apply(this);
		}
	}
}

UOmegaSlateStyle_Border* UOmegaBorder::L_GetStyle() const
{
	if(bUseDefaultStyle)
	{
		UOmegaStyleSettings* set=OGF_CFG_STYLE();
		if(set->Styled_Borders.Contains(DefaultStyleToUse))
		{
			return set->Styled_Borders[DefaultStyleToUse].LoadSynchronous();
		}
	}
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaBorder::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaBorder::SetStyleAsset(UOmegaSlateStyle_Border* Style)
{
	if (Style)
	{
		StyleAsset=Style;
		if(L_GetStyle())
		{
			L_GetStyle()->Apply(this);
		}
	}
}

UOmegaSlateStyle_Text* UOmegaTextBlock::L_GetStyle() const
{
	if(bUseDefaultStyle)
	{
		if (UOmegaSlateStyle_Text* _style= GetMutableDefault<UOmegaStyleSettings>()->Styled_Text.FindOrAdd(DefaultStyleToUse).LoadSynchronous())
		{
			return _style;
		}
	}
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaTextBlock::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaTextBlock::SetStyleAsset(UOmegaSlateStyle_Text* Style)
{
	if (Style)
	{
		StyleAsset=Style;
		if(L_GetStyle())
		{
			L_GetStyle()->Apply(this);
		}
	}
}

UOmegaSlateStyle_RichText* UOmegaRichTextBlock::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaRichTextBlock::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaRichTextBlock::SetStyleAsset(UOmegaSlateStyle_RichText* NewStyle)
{
	if (NewStyle)
	{
		StyleAsset=NewStyle;
		if(L_GetStyle())
		{
		
		}
	}
}

UOmegaSlateStyle_ExpandableArea* UOmegaExpandableArea::L_GetStyle() const
{
	if(StyleAsset) { return StyleAsset; } return nullptr;
}

void UOmegaExpandableArea::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaExpandableArea::SetStyleAsset(UOmegaSlateStyle_ExpandableArea* NewStyle)
{
	if (NewStyle)
	{
		StyleAsset=NewStyle;
		if(L_GetStyle())
		{
			SetStyle(L_GetStyle()->Style);
		}
	}
}
