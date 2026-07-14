// Fill out your copyright notice in the Description page of Project Settings.


#include "DataWidgets/DW_Skill.h"

#include "Components/Component_Combatant.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "DataAssets/DA_DamageType.h"
#include "Functions/F_CombatantFilter.h"
#include "Functions/F_CombatantSelector.h"
#include "Widget/DataList.h"

void UDataWidgetBase_Skill::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
	UCombatantComponent* comb=nullptr;
	if (UCombatantComponent* _c=Cast<UCombatantComponent>(ListOwner))
	{
		comb=_c;	
	}
	UDataList* List_AttributeCosts=nullptr;
	UImage* imgIcon_DamageType=nullptr;
	UTextBlock* txtName_DamageType=nullptr;
	UImage* imgIcon_Attribute=nullptr;
	UTextBlock* txtName_Attribute=nullptr;
	UImage* imgIcon_CombatantFilter=nullptr;
	UTextBlock* txtName_CombatantFilter=nullptr;
	UImage* imgIcon_CombatantSelector=nullptr;
	UTextBlock* txtName_CombatantSelector=nullptr;
	
	GetDataWidgetBindings(List_AttributeCosts,
		imgIcon_DamageType,
		txtName_DamageType,
		imgIcon_Attribute,
		txtName_Attribute,
		imgIcon_CombatantFilter,
		txtName_CombatantFilter,
		imgIcon_CombatantSelector,
		txtName_CombatantSelector);
	
	if (List_AttributeCosts)
	{
		List_AttributeCosts->ClearList();
	}
	if (SourceAsset && SourceAsset->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
	{
		FOmegaSkillConfig _cfg=IDataInterface_Skill::Execute_Skill_GetConfig(SourceAsset,comb);
		
		if (List_AttributeCosts)
		{
			List_AttributeCosts->SetListOwner(SourceAsset);
			TArray<UOmegaAttribute*> attList;
			_cfg.AttributeUseCost.GetKeys(attList);
			
			for (UOmegaAttribute* att : attList)
			{
				if (att)
				{
					List_AttributeCosts->AddAssetToList(att,"");
				}
			}
		}
		if (imgIcon_DamageType && _cfg.Meta_DamageType)
		{
			imgIcon_DamageType->SetBrush(_cfg.Meta_DamageType->Icon);
		}
		if (txtName_DamageType && _cfg.Meta_DamageType)
		{
			txtName_DamageType->SetText(_cfg.Meta_DamageType->DisplayName);
		}
		if (imgIcon_Attribute && _cfg.Meta_Attribute)
		{
			imgIcon_Attribute->SetBrush(_cfg.Meta_Attribute->Icon);
		}
		if (txtName_Attribute && _cfg.Meta_Attribute)
		{
			txtName_Attribute->SetText(_cfg.Meta_Attribute->DisplayName);
		}
		if (imgIcon_CombatantFilter && _cfg.TargetFilter)
		{
			imgIcon_CombatantFilter->SetBrush(_cfg.TargetFilter->Icon);
		}
		if (txtName_CombatantFilter && _cfg.TargetFilter)
		{
			txtName_CombatantFilter->SetText(_cfg.TargetFilter->DisplayName);
		}
		if (_cfg.TargetSelector)
		{
			if (UCombatantSelector* _sel=_cfg.TargetSelector.GetDefaultObject())
			{
				if (imgIcon_CombatantSelector)
				{
					imgIcon_CombatantSelector->SetBrush(_sel->SelectorIcon);
				}
				if (txtName_CombatantSelector)
				{
					txtName_CombatantSelector->SetText(_sel->SelectorName);
				}
			}
		}
	}
}
