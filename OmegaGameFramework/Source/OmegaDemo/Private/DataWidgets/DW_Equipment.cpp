// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_Equipment.h"
#include "DataAssets/DA_EquipSlot.h"
#include "Widget/DataList.h"
#include "Widget/DataWidget.h"


void UDataWidgetBase_Equipment::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(GetDataList_EquipSlots())
	{
		GetDataList_EquipSlots()->RefreshAllEntries();
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

void UDataWidgetBase_EquipmentSlot::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(Asset && Asset->GetClass()->IsChildOf(UEquipmentSlot::StaticClass()))
	{
		REF_Slot=Cast<UEquipmentSlot>(Asset);
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_EquipmentSlot::OnNewListOwner_Implementation(UObject* ListOwner)
{
	Super::OnNewListOwner_Implementation(ListOwner);
}

void UDataWidgetBase_EquipmentSlot::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if (REF_Slot)
	{
		if (UDataWidget* _wig=GetDataWidget_EquippedItem())
		{
			bool _valid;
			_wig->SetSourceAsset(GetLinkedCombatant()->Equipment_GetInSlot(REF_Slot,_valid));
		}
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}
