// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_Menus.h"

#include "Widget/DataList.h"

void UMenuBase_SaveLoad::L_SetSavePathCategory(int32 cat)
{
	if(UWidgetSwitcher* sw=GetWidget_WidgetSwitcher_State())
	{
		sw->SetActiveWidgetIndex(cat);
	}
	if(l_subsys)
	{
		if(UDataList* savlist=GetDataList_SavePaths(cat))
		{
			savlist->ClearList();
			if(b_isloadMenu)
			{
				
				for(auto* s: l_subsys->ListSavedGames(GetSavesPath_ByCategory(cat),SaveCount-1,false))
				{
					if(s)
					{
						savlist->AddAssetToList(s,"load");
					}
				}
			}
			else
			{
				for (int i = 0; i < SaveCount; ++i)
				{
					bool is_suc;
					if(UOmegaSaveGame* gam=l_subsys->LoadGame(i,is_suc,GetSavesPath_ByCategory(cat)))
					{
						savlist->AddAssetToList(gam,"save");
					}
					else
					{
						savlist->AddedCustomEntryToList(FCustomAssetData(),"save");
					}
				}
			}
		}
	}
}

void UMenuBase_SaveLoad::L_OnSelectSlot(UDataWidget* dw, FString lbl, UObject* asset, int32 ind)
{
}

void UMenuBase_SaveLoad::MenuOpened_Implementation(FGameplayTagContainer Tags, UObject* Context, const FString& Flag)
{
	l_subsys=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
	b_isloadMenu=false;
	if(Flag=="1" || Flag=="Load")
	{
		b_isloadMenu=true;
	}
	L_SetSavePathCategory(0);

	if(UDataList* list=GetDataList_SaveSlots())
	{
		list->OnEntrySelected.AddDynamic(this, &UMenuBase_SaveLoad::UMenuBase_SaveLoad::L_OnSelectSlot);
	}
	Super::MenuOpened_Implementation(Tags, Context, Flag);
}
