// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Widget/UI_Background.h"

#include "OmegaSettings_Slate.h"
#include "Components/BorderSlot.h"
#include "Components/Image.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/NamedSlot.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Misc/OmegaUtils_Macros.h"

// ---------------------------------------------------------------------------------------------------------------------
// Style asset
// ---------------------------------------------------------------------------------------------------------------------

TArray<FOmegaUI_SectionInfo> UOmegaUIStyle_Background::GetBorderSections_Implementation()
{
	TArray<FOmegaUI_SectionInfo> out;
	out.Add(Top_Style);
	out.Add(Center_Style);
	out.Add(Bottom_Style);
	return out;
}

// ---------------------------------------------------------------------------------------------------------------------
// Style resolution
// ---------------------------------------------------------------------------------------------------------------------

UOmegaUIStyle_Background* UOmegaUI_Background::L_GetStyle() const
{
	if (!UseStyle) { return nullptr; }
	if (OverrideStyle) { return OverrideStyle; }
	if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(const_cast<UOmegaUI_Background*>(this)))
	{
		return Theme->GetStyle_Background(StyleTag);
	}
	return nullptr;
}

// ---------------------------------------------------------------------------------------------------------------------
// Lifecycle
// ---------------------------------------------------------------------------------------------------------------------

void UOmegaUI_Background::NativePreConstruct()
{
	SetStyleAsset(L_GetStyle());
	Super::NativePreConstruct();
}

void UOmegaUI_Background::NativeConstruct()
{
	SetStyleAsset(L_GetStyle());
	Super::NativeConstruct();
}

// ---------------------------------------------------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------------------------------------------------

void UOmegaUI_Background::SetStyleAsset(UOmegaUIStyle_Background* InStyle)
{
	if (InStyle) { OverrideStyle = InStyle; }
	if (UOmegaUIStyle_Background* Resolved = L_GetStyle())
	{
		SetStyle(Resolved);
		// Retrieve the background image widget so PP can target its dynamic material
		UImage* Img = nullptr;
		UOverlay* Overlay = nullptr;
		UPanelWidget* Panel = nullptr;
		GetWidgets_Base(Img, Overlay, Panel);
		UMaterialInstanceDynamic* DynMat = Img ? Img->GetDynamicMaterial() : nullptr;
		Resolved->PostProcess.Apply(DynMat);                              // 2. style asset PP
		if (UOmegaSlateTheme* Theme = UOmegaWidgetInterface::GetTheme(this))
		{
			Theme->PostProcess.Apply(DynMat);                          // 3. theme PP
		}
	}
}

void UOmegaUI_Background::SetStyle(UOmegaUIStyle_Background* InStyle)
{
	if (!InStyle) { return; }

	UImage* img;
	UOverlay* overlay;
	UPanelWidget* panel = nullptr;
	GetWidgets_Base(img, overlay, panel);

	if (img)
	{
		img->SetBrush(InStyle->Background_Brush);
		if (UOverlaySlot* slot = Cast<UOverlaySlot>(img->Slot))
		{
			slot->SetPadding(InStyle->Background_Margins);
		}
	}

	TArray<FOmegaUI_SectionInfo> sec = InStyle->GetBorderSections();
	for (int i = 0; i < sec.Num(); ++i)
	{
		L_UpdateStyleElements(sec[i], i);
	}
}

// ---------------------------------------------------------------------------------------------------------------------
// Private helpers
// ---------------------------------------------------------------------------------------------------------------------

void UOmegaUI_Background::L_Refresh()
{
	if (UOmegaUIStyle_Background* Resolved = L_GetStyle()) { SetStyle(Resolved); }
}

void UOmegaUI_Background::L_UpdateStyleElements(FOmegaUI_SectionInfo style, int32 index)
{
	UBorder* Border;
	UNamedSlot* nslot;
	USizeBox* SizeBox;
	GetWidgets_Section(index, nslot, Border, SizeBox);

	if (Border)
	{
		Border->SetBrush(style.Brush);
		Border->SetPadding(style.InnerMargins);
		if (UVerticalBoxSlot* slot = Cast<UVerticalBoxSlot>(Border->Slot))
		{
			slot->SetPadding(style.OuterMargins);
			slot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		}
		if (UBorderSlot* slot = Cast<UBorderSlot>(Border->AddChild(nslot)))
		{
			slot->SetHorizontalAlignment(HAlign_Fill);
			slot->SetVerticalAlignment(VAlign_Fill);
		}
	}

	if (SizeBox)
	{
		SizeBox->SetWidthOverride(style.BoxSize.X);
		SizeBox->SetHeightOverride(style.BoxSize.Y);
	}
}

void UOmegaUI_Background::L_InitSection(UBorder*& border, UNamedSlot*& nslot, FName slotName)
{
	// Reserved for runtime-constructed section initialisation
}
