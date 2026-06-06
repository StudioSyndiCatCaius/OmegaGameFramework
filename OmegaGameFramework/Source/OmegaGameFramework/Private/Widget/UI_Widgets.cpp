// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/UI_Widgets.h"

#include "OmegaSettings_Slate.h"
#include "Widget/UI_Panel.h"
#include "Widget/UI_Background.h"
#include "Components/Image.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Component_Combatant.h"
#include "Materials/MaterialInstanceDynamic.h"

// Returns the dynamic material from widget types that support it; nullptr otherwise.
static UMaterialInstanceDynamic* GetWidgetDynMat(UWidget* Widget)
{
	if (UImage*       w = Cast<UImage>(Widget))       { return w->GetDynamicMaterial(); }
	if (UBorder*      w = Cast<UBorder>(Widget))      { return w->GetDynamicMaterial(); }
	//if (UProgressBar* w = Cast<UProgressBar>(Widget)) { return w->GetDynamicMaterial(); }
	return nullptr;
}

void FOmegaWidgetPostProcess::Apply(UMaterialInstanceDynamic* Mat) const
{
	if (Mat)
	{
		MaterialParams.Apply(Mat);
	}
}

void UOmegaSlateStyle::ApplyPostProcess(UWidget* Widget) const
{
	UMaterialInstanceDynamic* DynMat = GetWidgetDynMat(Widget);
	PostProcess.Apply(DynMat);                                         // 2. style asset PP
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(Widget))
	{
		Theme->PostProcess.Apply(DynMat);                              // 3. theme PP
	}
}

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
		PostProcess.Apply(GetWidgetDynMat(widget));
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

UOmegaSlateTheme* UOmegaWidgetInterface::GetTheme(UWidget* Widget)
{
	UWidget* Current = Widget;
	while (Current)
	{
		if (Current->Implements<UOmegaWidgetInterface>())
		{
			if (UOmegaSlateTheme* Theme = IOmegaWidgetInterface::Execute_GetSlateTheme(Current))
			{
				return Theme;
			}
		}
		Current = Current->GetParent();
	}
	if (UOmegaSlateTheme* _defTheme=GetMutableDefault<UOmegaStyleSettings>()->DefaultSlateTheme.LoadSynchronous())
	{
		return _defTheme;
	}
	return nullptr;
}

UOmegaSlateStyle_Button* UOmegaButton::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaButton*>(this)))
	{
		return Theme->GetStyle_Button(StyleTag);
	}
	return nullptr;
}

void UOmegaButton::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaButton::SetStyleAsset(UOmegaSlateStyle_Button* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_Button* Resolved = L_GetStyle()) { Resolved->Apply(this); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_Slider* UOmegaSlider::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaSlider*>(this)))
	{
		return Theme->GetStyle_Slider(StyleTag);
	}
	return nullptr;
}

void UOmegaSlider::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaSlider::SetStyleAsset(UOmegaSlateStyle_Slider* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_Slider* Resolved = L_GetStyle()) { SetWidgetStyle(Resolved->Brush_Slider); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_ProgressBar* UOmegaProgressBar::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaProgressBar*>(this)))
	{
		return Theme->GetStyle_ProgressBar(StyleTag);
	}
	return nullptr;
}

void UOmegaProgressBar::L_OnCombUpdat(UCombatantComponent* Combatant)
{
	if (Combatant==BoundCombatant && BoundAttribute)
	{
		SetPercent(Combatant->GetAttributePercentage(BoundAttribute));
	}
}

void UOmegaProgressBar::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaProgressBar::BindAttribute(UCombatantComponent* Combatant, UOmegaAttribute* Attribute)
{
	if (Combatant && Attribute)
	{
		BoundAttribute=Attribute;
		BoundCombatant=Combatant;
		Combatant->OnUpdated.AddDynamic(this,&UOmegaProgressBar::L_OnCombUpdat);
		L_OnCombUpdat(BoundCombatant);
	}
}

void UOmegaProgressBar::UnbindAttribute()
{
	if (BoundCombatant)
	{
		BoundCombatant->OnUpdated.RemoveDynamic(this,&UOmegaProgressBar::L_OnCombUpdat);
	}
	BoundCombatant=nullptr;
	BoundAttribute=nullptr;
}

void UOmegaProgressBar::SetStyleAsset(UOmegaSlateStyle_ProgressBar* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_ProgressBar* Resolved = L_GetStyle()) { SetWidgetStyle(Resolved->Brush_ProgressBar); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_CheckBox* UOmegaCheckBox::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaCheckBox*>(this)))
	{
		return Theme->GetStyle_CheckBox(StyleTag);
	}
	return nullptr;
}

void UOmegaCheckBox::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaCheckBox::SetStyleAsset(UOmegaSlateStyle_CheckBox* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_CheckBox* Resolved = L_GetStyle()) { Resolved->Apply(this); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_ComboBox* UOmegaComboBox::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaComboBox*>(this)))
	{
		return Theme->GetStyle_ComboBox(StyleTag);
	}
	return nullptr;
}

void UOmegaComboBox::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaComboBox::SetStyleAsset(UOmegaSlateStyle_ComboBox* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_ComboBox* Resolved = L_GetStyle()) { Resolved->Apply(this); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_Border* UOmegaBorder::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaBorder*>(this)))
	{
		return Theme->GetStyle_Border(StyleTag);
	}
	return nullptr;
}

void UOmegaBorder::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaBorder::SetStyleAsset(UOmegaSlateStyle_Border* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_Border* Resolved = L_GetStyle()) { Resolved->Apply(this); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_Text* UOmegaTextBlock::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaTextBlock*>(this)))
	{
		return Theme->GetStyle_Text(StyleTag);
	}
	return nullptr;
}

void UOmegaTextBlock::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaTextBlock::SetStyleAsset(UOmegaSlateStyle_Text* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_Text* Resolved = L_GetStyle()) { Resolved->Apply(this); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_RichText* UOmegaRichTextBlock::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaRichTextBlock*>(this)))
	{
		return Theme->GetStyle_RichText(StyleTag);
	}
	return nullptr;
}

void UOmegaRichTextBlock::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaRichTextBlock::SetStyleAsset(UOmegaSlateStyle_RichText* NewStyle)
{
	if (NewStyle) { OverrideStyle = NewStyle; }
	if (UOmegaSlateStyle_RichText* Resolved = L_GetStyle()) { Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_Border* UOmegaSlateTheme::GetStyle_Border(FGameplayTag Tag)
{
	if (Tag.IsValid() && Border_Tagged.Contains(Tag)) { return Border_Tagged[Tag]; }
	return Border_Default;
}

UOmegaSlateStyle_Text* UOmegaSlateTheme::GetStyle_Text(FGameplayTag Tag)
{
	if (Tag.IsValid() && Text_Tagged.Contains(Tag)) { return Text_Tagged[Tag]; }
	return Text_Default;
}

UOmegaSlateStyle_RichText* UOmegaSlateTheme::GetStyle_RichText(FGameplayTag Tag)
{
	if (Tag.IsValid() && RichText_Tagged.Contains(Tag)) { return RichText_Tagged[Tag]; }
	return RichText_Default;
}

UOmegaSlateStyle_Button* UOmegaSlateTheme::GetStyle_Button(FGameplayTag Tag)
{
	if (Tag.IsValid() && Button_Tagged.Contains(Tag)) { return Button_Tagged[Tag]; }
	return Button_Default;
}

UOmegaSlateStyle_Slider* UOmegaSlateTheme::GetStyle_Slider(FGameplayTag Tag)
{
	if (Tag.IsValid() && Slider_Tagged.Contains(Tag)) { return Slider_Tagged[Tag]; }
	return Slider_Default;
}

UOmegaSlateStyle_ProgressBar* UOmegaSlateTheme::GetStyle_ProgressBar(FGameplayTag Tag)
{
	if (Tag.IsValid() && ProgressBar_Tagged.Contains(Tag)) { return ProgressBar_Tagged[Tag]; }
	return ProgressBar_Default;
}

UOmegaSlateStyle_CheckBox* UOmegaSlateTheme::GetStyle_CheckBox(FGameplayTag Tag)
{
	if (Tag.IsValid() && CheckBox_Tagged.Contains(Tag)) { return CheckBox_Tagged[Tag]; }
	return CheckBox_Default;
}

UOmegaSlateStyle_ComboBox* UOmegaSlateTheme::GetStyle_ComboBox(FGameplayTag Tag)
{
	if (Tag.IsValid() && ComboBox_Tagged.Contains(Tag)) { return ComboBox_Tagged[Tag]; }
	return ComboBox_Default;
}

UOmegaSlateStyle_ExpandableArea* UOmegaSlateTheme::GetStyle_ExpandableArea(FGameplayTag Tag)
{
	if (Tag.IsValid() && ExpandableArea_Tagged.Contains(Tag)) { return ExpandableArea_Tagged[Tag]; }
	return ExpandableArea_Default;
}

UOmegaSlateStyle_ScrollBox* UOmegaSlateTheme::GetStyle_ScrollBox(FGameplayTag Tag)
{
	if (Tag.IsValid() && ScrollBox_Tagged.Contains(Tag)) { return ScrollBox_Tagged[Tag]; }
	return ScrollBox_Default;
}

UOmegaUIStyle_Background* UOmegaSlateTheme::GetStyle_Background(FGameplayTag Tag)
{
	if (Tag.IsValid() && Background_Tagged.Contains(Tag)) { return Background_Tagged[Tag]; }
	return Background_Default;
}

UOmegaSlateStyle_Panel* UOmegaSlateTheme::GetStyle_Panel(FGameplayTag Tag)
{
	if (Tag.IsValid() && Panel_Tagged.Contains(Tag)) { return Panel_Tagged[Tag]; }
	return Panel_Default;
}

void UOmegaSlateStyle_Panel::Apply(UOmegaUI_Panel* Panel)
{
	if (!Panel) { return; }

	if (UBorder* b = Panel->GetWidget_Border_Title())
	{
		b->SetBrush(TitleBorder_Brush);
		b->SetPadding(TitleBorder_InnerPadding);
		if (UVerticalBoxSlot* s = Cast<UVerticalBoxSlot>(b->Slot)) { s->SetPadding(TitleBorder_OuterPadding); }
		ApplyPostProcess(b);
	}

	if (UTextBlock* t = Panel->GetWidget_Text_Title())
	{
		t->SetFont(TitleText);
	}

	if (UBorder* b = Panel->GetWidget_Border_Body())
	{
		b->SetBrush(BodyBorder_Brush);
		b->SetPadding(BodyBorder_InnerPadding);
		if (UVerticalBoxSlot* s = Cast<UVerticalBoxSlot>(b->Slot)) { s->SetPadding(BodyBorder_OuterPadding); }
		ApplyPostProcess(b);
	}
}

void UOmegaSlateStyle_Panel::ApplyStyleAgnostic(UWidget* Widget)
{
	if (UOmegaUI_Panel* _wg = Cast<UOmegaUI_Panel>(Widget)) { Apply(_wg); }
}

void UOmegaSlateStyle_ScrollBox::Apply(UScrollBox* widget)
{
	if (widget)
	{
		widget->SetWidgetStyle(ScrollBoxStyle);
		widget->SetWidgetBarStyle(ScrollBarStyle);
	}
}

UOmegaSlateStyle_ExpandableArea* UOmegaExpandableArea::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaExpandableArea*>(this)))
	{
		return Theme->GetStyle_ExpandableArea(StyleTag);
	}
	return nullptr;
}

void UOmegaExpandableArea::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaExpandableArea::SetStyleAsset(UOmegaSlateStyle_ExpandableArea* NewStyle)
{
	if (NewStyle) { OverrideStyle = NewStyle; }
	if (UOmegaSlateStyle_ExpandableArea* Resolved = L_GetStyle()) { SetStyle(Resolved->Style); Resolved->ApplyPostProcess(this); }
}

UOmegaSlateStyle_ScrollBox* UOmegaScrollBox::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaScrollBox*>(this)))
	{
		return Theme->GetStyle_ScrollBox(StyleTag);
	}
	return nullptr;
}

void UOmegaScrollBox::OnWidgetRebuilt()
{
	SetStyleAsset(L_GetStyle());
	Super::OnWidgetRebuilt();
}

void UOmegaScrollBox::SetStyleAsset(UOmegaSlateStyle_ScrollBox* Style)
{
	if (Style) { OverrideStyle = Style; }
	if (UOmegaSlateStyle_ScrollBox* Resolved = L_GetStyle()) { Resolved->Apply(this); Resolved->ApplyPostProcess(this); }
}
