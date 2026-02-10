// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Widget/UI_Background.h"

#include "Components/BorderSlot.h"
#include "Components/Image.h"
#include "Components/NamedSlot.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBox.h"
#include "Components/VerticalBoxSlot.h"


void L_SetContentToSlot(UWidget* content, UNamedSlot* slot)
{
	if(slot)
	{
		slot->ClearChildren();
		if(content)
		{
			slot->AddChild(content);
		}
	}
}

TArray<FOmegaUI_SectionInfo> UOmegaUIStyle_Background::GetBorderSections_Implementation()
{
	TArray<FOmegaUI_SectionInfo> out;
	out.Add(Top_Style);
	out.Add(Center_Style);
	out.Add(Bottom_Style);
	return out;
}

void UOmegaUI_Background::NativePreConstruct()
{
	SetStyle(Style);
	Super::NativePreConstruct();
}

void UOmegaUI_Background::L_Refresh()
{
	/*
	if(Style)
	{
		if(img_bkg)
		{
			img_bkg->SetBrush(Style->Background_Brush);
		}
		// Fix: Get the overlay slot correctly
		if(UOverlaySlot* vbox_slot = Cast<UOverlaySlot>(vbox->Slot))
		{
			vbox_slot->SetPadding(Style->Background_Margins);
		}
		L_UpdateStyleElements(Style->Top_Style,Border_top);
		L_UpdateStyleElements(Style->Center_Style,Border_center);
		L_UpdateStyleElements(Style->Bottom_Style,Border_bottom);
		//L_UpdateStyleElements(Style->Background_Style,img_bkg,nullptr,RootOverlay);
	}
	*/
}

void UOmegaUI_Background::L_UpdateStyleElements(FOmegaUI_SectionInfo style, int32 index)
{
	UBorder* Border;
	UNamedSlot* nslot;
	USizeBox* SizeBox;
	GetWidgets_Section(index,nslot,Border,SizeBox);
	if(Border)
	{
		Border->SetBrush(style.Brush);
		Border->SetPadding(style.InnerMargins);
		if(UVerticalBoxSlot* slot = Cast<UVerticalBoxSlot>(Border->Slot))
		{
			slot->SetPadding(style.OuterMargins); 
			slot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		}
		if(UBorderSlot* slot=Cast<UBorderSlot>(Border->AddChild(nslot)))
		{
			slot->SetHorizontalAlignment(HAlign_Fill);
			slot->SetVerticalAlignment(VAlign_Fill);
		}
	}
	if(SizeBox)
	{
		SizeBox->SetWidthOverride(style.BoxSize.X);
		SizeBox->SetHeightOverride(style.BoxSize.Y);
	}
}

void UOmegaUI_Background::L_InitSection(UBorder*& border, UNamedSlot*& nslot,FName slotName)
{
	/*
	if(vbox)
	{
		border=NewObject<UBorder>(this);
		UVerticalBoxSlot* slot_vbox=vbox->AddChildToVerticalBox(border);
		slot_vbox->SetHorizontalAlignment(HAlign_Fill);
		slot_vbox->SetVerticalAlignment(VAlign_Fill);
		nslot=NewObject<UNamedSlot>(this,slotName);
		border->AddChild(nslot);
	}
	*/
}

void UOmegaUI_Background::SetStyle(UOmegaUIStyle_Background* InStyle)
{
	if(InStyle)
	{
		Style=InStyle;
		UImage* img;
		UOverlay* overlay;
		UPanelWidget* panel = nullptr;
		GetWidgets_Base(img,overlay,panel);
		if(Style)
		{
			if(img)
			{
				img->SetBrush(Style->Background_Brush);
				if(UOverlaySlot* slot=Cast<UOverlaySlot>(img->Slot))
				{
					slot->SetPadding(Style->Background_Margins);
				}
			}
			TArray<FOmegaUI_SectionInfo> sec=Style->GetBorderSections();
			for (int i = 0; i < sec.Num(); ++i)
			{
				L_UpdateStyleElements(sec[i],i);
			}
		}
	}
}

