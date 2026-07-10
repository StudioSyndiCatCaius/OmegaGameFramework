// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_Combatant.h"
#include "Components/Component_Combatant.h"
#include "Functions/F_Common.h"
#include "Widget/DataList.h"


void UDataWidgetBase_CombatantBASE::L_Refresh(UCombatantComponent* Combatant)
{
	Refresh();
}

void UDataWidgetBase_CombatantBASE::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	if(UCombatantComponent* ref_comp = Cast<UCombatantComponent>(local_GetComponentFromObject(SourceAsset,UCombatantComponent::StaticClass())))
	{
		REF_combatant=ref_comp;
		ref_comp->OnUpdated.AddUniqueDynamic(this,&UDataWidgetBase_CombatantBASE::L_Refresh);
	}
	Super::Native_OnSourceAssetChanged(SourceAsset);
}

void UDataWidgetBase_CombatantBASE::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

UCombatantComponent* UDataWidgetBase_CombatantBASE::GetLinkedCombatant()
{
	if (REF_combatant) { return REF_combatant;}
	if (UCombatantComponent* _c=Cast<UCombatantComponent>(local_GetComponentFromObject(ReferencedAsset,UCombatantComponent::StaticClass())))
	{
		REF_combatant=_c;
		return REF_combatant;
	}
	if (GetOwningList())
	{
		if (UCombatantComponent* _c=Cast<UCombatantComponent>(local_GetComponentFromObject(GetOwningList()->ListOwner,UCombatantComponent::StaticClass())))
		{
			REF_combatant=_c;
			return REF_combatant;
		}
	}
	return nullptr;
}


static void L_ReplicateCompare(UDataList* l, bool bComparing, UCombatantComponent* Combatant,
	UObject* ComparedSource, UObject* UncomparedSource)
{
	if(l)
	{
		for(auto* i : l->GetEntries())
		{
			if(i && i->GetClass()->ImplementsInterface(UWidgetInterface_Combatant::StaticClass()))
			{
				IWidgetInterface_Combatant::Execute_SetAttributeComparison(i,bComparing,Combatant,ComparedSource,UncomparedSource);
			}
		}
	}
}

void UDataWidgetBase_Combatant::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(GetDataList_Attributes())
	{
		GetDataList_Attributes()->SetListOwner(SourceAsset);
		if(GetLinkedCombatant())
		{
			GetDataList_Attributes()->ClearList();
			for (UOmegaAttribute* temp_att : GetLinkedCombatant()->AttributeSet->GetAllAttributes())
			{
				GetDataList_Attributes()->AddAssetToList(temp_att,"");
			}
		}
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

void UDataWidgetBase_Combatant::SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant,
	UObject* ComparedSource, UObject* UncomparedSource)
{
	L_ReplicateCompare(GetDataList_Attributes(),bComparing,Combatant,ComparedSource,UncomparedSource);
	L_ReplicateCompare(GetDataList_Attributes_Metric(),bComparing,Combatant,ComparedSource,UncomparedSource);
	L_ReplicateCompare(GetDataList_Attributes_Static(),bComparing,Combatant,ComparedSource,UncomparedSource);
}
