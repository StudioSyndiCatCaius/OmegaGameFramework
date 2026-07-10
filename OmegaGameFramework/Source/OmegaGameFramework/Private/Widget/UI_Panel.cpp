// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Widget/UI_Panel.h"

#include "Components/Border.h"
#include "Components/TextBlock.h"

// ---------------------------------------------------------------------------------------------------------------------
// Style resolution
// ---------------------------------------------------------------------------------------------------------------------

UOmegaSlateStyle_Panel* UOmegaUI_Panel::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaUI_Panel*>(this)))
	{
		return Theme->GetStyle_Panel(StyleTag);
	}
	return nullptr;
}

// ---------------------------------------------------------------------------------------------------------------------
// Lifecycle
// ---------------------------------------------------------------------------------------------------------------------

void UOmegaUI_Panel::NativePreConstruct()
{
	SetTitle(Title);
	SetStyleAsset(L_GetStyle());
	Super::NativePreConstruct();
}

void UOmegaUI_Panel::NativeConstruct()
{
	SetStyleAsset(L_GetStyle());
	Super::NativeConstruct();
}

// ---------------------------------------------------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------------------------------------------------

void UOmegaUI_Panel::SetTitle(FText NewTitle)
{
	Title = NewTitle;
	if (UTextBlock* _t = GetWidget_Text_Title()) { _t->SetText(NewTitle); }
}

void UOmegaUI_Panel::SetStyleAsset(UOmegaSlateStyle_Panel* InStyle)
{
	if (InStyle) { OverrideStyle = InStyle; }
	if (UOmegaSlateStyle_Panel* Resolved = L_GetStyle()) { Resolved->Apply(this); }
}
