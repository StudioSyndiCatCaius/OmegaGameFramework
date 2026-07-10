// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_SaveSlot.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "DataAssets/DA_Zone.h"
#include "Subsystems/Subsystem_World.h"


void UDataWidgetBase_SaveSlot::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(GetOwningPlayer() && GetGameInstance())
	{
		UOmegaSubsystem_World* l_ZoneSub=GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
		
		UWidgetSwitcher* switcher_ValidSave=nullptr;
		UTextBlock* txt_playtime=nullptr;
		UTextBlock* txt_levelname=nullptr;
		UTextBlock* txt_zonename=nullptr;
		UImage* img_screenshot=nullptr;
		
		GetDataWidgetBindings(switcher_ValidSave,txt_playtime,txt_levelname,txt_zonename,img_screenshot);
		
		if(UOmegaSaveGame* sav=Cast<UOmegaSaveGame>(Asset))
		{
			if(switcher_ValidSave)
			{
				switcher_ValidSave->SetActiveWidgetIndex(0);
			}
			if(img_screenshot)
			{
				if(sav->SaveScreenshot)
				{
					img_screenshot->SetBrushFromTexture(sav->SaveScreenshot);
				}
			}
			if(txt_playtime)
			{
				txt_playtime->SetText(FText::FromString(sav->Playtime.ToString()));
			}
			if(txt_levelname)
			{
				if(UOmegaLevelData* lvl= l_ZoneSub->GetWorldManager()->Zone_GetLevelData(nullptr))
				{
					txt_levelname->SetText(lvl->DisplayName);
				}
				else
				{
					txt_levelname->SetText(FText::FromString("???"));
				}
			}
			if(txt_zonename)
			{
				if(sav->ActiveZone)
				{
					txt_zonename->SetText(sav->ActiveZone->DisplayName);
				}
				else
				{
					txt_zonename->SetText(FText::FromString("???"));
				}
			}
			OnSaveWidgetInit(sav);
		}
		if(switcher_ValidSave) { switcher_ValidSave->SetActiveWidgetIndex(1); }
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_SaveSlot::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}
