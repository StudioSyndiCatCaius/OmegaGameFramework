// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_Leveling.h"

#include "Components/Component_Combatant.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


void UDataWidgetBase_Leveling::L_SetTextFromVal(float val, UTextBlock* text) const
{
	if (text && LevelingAsset)
	{
		text->SetText(LevelingAsset->GetTextFromValue(val));
	}
}

void UDataWidgetBase_Leveling::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if (SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaLevelingAsset::StaticClass()))
	{
		LevelingAsset=Cast<UOmegaLevelingAsset>(SourceAsset);
	}
	if (LevelingAsset)
	{
		UTextBlock* text_RankName=nullptr;
		UTextBlock* text_RankValue=nullptr;
		UTextBlock* text_xpName=nullptr;
		UTextBlock* text_xpCurrent=nullptr;
		UTextBlock* text_xpMax=nullptr;
		UProgressBar* ProgressBar_xpPercent=nullptr;
		GetLevelingWidgets(text_RankName,text_RankValue,text_xpName,text_xpCurrent,
		                   text_xpMax,ProgressBar_xpPercent);
		if (text_RankName)
		{
			text_RankName->SetText(LevelingAsset->DisplayName);
		}
		if (text_xpName)
		{
			text_xpName->SetText(LevelingAsset->XPName);
		}

		if (GetLinkedCombatant())
		{
			float _cur=GetLinkedCombatant()->XP_Get(LevelingAsset);

			float _min, _max, _perc;

			GetLinkedCombatant()->XP_GetValues(LevelingAsset,_min,_max,_perc);
			if (ProgressBar_xpPercent)
			{
				ProgressBar_xpPercent->SetPercent(_perc);
			}
			L_SetTextFromVal(_cur,text_xpCurrent);
			L_SetTextFromVal(_max,text_xpMax);
			L_SetTextFromVal(GetLinkedCombatant()->XP_GetLevel(LevelingAsset),text_RankValue);
		}
	}

	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

void UDataWidgetBase_Leveling::SetLevelingAsset(UOmegaLevelingAsset* Asset)
{
	if (Asset)
	{
		LevelingAsset = Asset;
		Refresh();
	}
}
