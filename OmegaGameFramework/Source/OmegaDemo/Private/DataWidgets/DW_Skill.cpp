// Fill out your copyright notice in the Description page of Project Settings.


#include "DataWidgets/DW_Skill.h"

#include "Components/Component_Combatant.h"
#include "Components/Image.h"
#include "DataAssets/DA_DamageType.h"
#include "Widget/DataList.h"

void UDataWidgetBase_Skill::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
	UCombatantComponent* comb=nullptr;
	if (UCombatantComponent* _c=Cast<UCombatantComponent>(ListOwner))
	{
		comb=_c;	
	}
	UDataList* dl_attCost=nullptr;
	UImage* imgIcon_DamageType=nullptr;
	UImage* imgIcon_Attribute=nullptr;
	
	GetDataWidgetBindings(dl_attCost,imgIcon_DamageType,imgIcon_Attribute);
	
	if (dl_attCost)
	{
		dl_attCost->ClearList();
	}
	if (SourceAsset && SourceAsset->GetClass()->ImplementsInterface(UDataInterface_Skill::StaticClass()))
	{
		FOmegaSkillConfig _cfg=IDataInterface_Skill::Execute_Skill_GetConfig(SourceAsset,comb);
		
		if (dl_attCost)
		{
			dl_attCost->SetListOwner(SourceAsset);
			TArray<UOmegaAttribute*> attList;
			_cfg.AttributeUseCost.GetKeys(attList);
			
			for (UOmegaAttribute* att : attList)
			{
				if (att)
				{
					dl_attCost->AddAssetToList(att,"");
				}
			}
		}
		if (imgIcon_DamageType && _cfg.DamageType)
		{
			imgIcon_DamageType->SetBrush(_cfg.DamageType->Icon);
		}
		if (imgIcon_Attribute && _cfg.Attribute)
		{
			imgIcon_Attribute->SetBrush(_cfg.Attribute->Icon);
		}
	}
}
