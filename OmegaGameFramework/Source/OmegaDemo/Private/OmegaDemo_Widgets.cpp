// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_Widgets.h"
#include "Components/ActorComponent.h"
#include "Components/Component_Combatant.h"
#include "Components/ProgressBar.h"
#include "Functions/OmegaFunctions_Common.h"
#include "Widget/DataList.h"


UActorComponent* local_GetComponentFromObject(UObject* object, TSubclassOf<UActorComponent> Class)
{
	if(!Class || !object)
	{
		return nullptr;
	}
	UActorComponent* local_comp=nullptr;
	if(object->GetClass()->IsChildOf(UActorComponent::StaticClass()))
	{
		local_comp=Cast<UActorComponent>(object);
	}
	else if(AActor* temp_actor = Cast<AActor>(object))
	{
		if(UActorComponent* temp_comp = temp_actor->GetComponentByClass(Class))
		{
			local_comp=temp_comp;
		}
	}
	if(local_comp && local_comp->GetClass()->IsChildOf(Class))
	{
		return local_comp;
	}
	return nullptr;
}

void UDataWidgetBase_Combatant::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
	
	//TEnumAsByte<EOmegaFunctionResult> out_result;
	//UActorComponent* temp_comp=
		
	if(UActorComponent* ref_comp = local_GetComponentFromObject(SourceAsset,UCombatantComponent::StaticClass()))
	{
		REF_combatant=Cast<UCombatantComponent>(ref_comp);
	}
	if(GetDataList_Attributes())
	{
		GetDataList_Attributes()->SetListOwner(SourceAsset);
		if(REF_combatant)
		{
			GetDataList_Attributes()->ClearList();
			for (UOmegaAttribute* temp_att : REF_combatant->AttributeSet->Attributes)
			{
				GetDataList_Attributes()->AddAssetToList(temp_att,"");
			}
		}
		//GetDataList_Attributes()->AddAssetsToList(REF_combatant->AttributeSet->Attributes,"")
	}
}

void UDataWidgetBase_Attribute::local_UpdateColor()
{
	if(REF_attribute)
	{
		FLinearColor in_color=REF_attribute->AttributeColor;
		if(REF_Combatant && bUseDamageColor && REF_Combatant->GetAttributePercentage(REF_attribute)<DamageColorPercentChange)
		{
			in_color=REF_attribute->DamageColor;
		}
		
		if(GetWidget_ProgressBar_Attribute())
		{
			if(REF_Combatant)
			{
				GetWidget_ProgressBar_Attribute()->SetPercent(REF_Combatant->GetAttributePercentage(REF_attribute));
			}
			GetWidget_ProgressBar_Attribute()->SetFillColorAndOpacity(in_color);
		}
		if(GetWidget_DynamicMeter_Attribute())
		{
			if(REF_Combatant)
			{
				GetWidget_DynamicMeter_Attribute()->SetPercent_Progress(REF_Combatant->GetAttributePercentage(REF_attribute));
			}
			GetWidget_DynamicMeter_Attribute()->SetProgress_Color(in_color);
		}
		float val_cur;
		float val_max;
		if(REF_Combatant)
		{
			REF_Combatant->GetAttributeValue(REF_attribute,val_cur,val_max);
		}
		if(GetWidget_Text_CurrentValue()) { GetWidget_Text_CurrentValue()->SetText(REF_attribute->GetAttributeValueDisplayText(val_cur)); }
		if(GetWidget_Text_MaxValue()) { GetWidget_Text_MaxValue()->SetText(REF_attribute->GetAttributeValueDisplayText(val_max)); }
	}
}

void UDataWidgetBase_Attribute::local_OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
                                                         float FinalDamage, UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit)
{
	if(Combatant==REF_Combatant && Attribute==REF_attribute)
	{
		local_UpdateColor();
	}

}

void UDataWidgetBase_Attribute::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
	if(SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaAttribute::StaticClass()))
	{
		SetAttribute(Cast<UOmegaAttribute>(SourceAsset));
	}
	UCombatantComponent* temp_comp =nullptr;
	if(UActorComponent* ref_comp = local_GetComponentFromObject(SourceAsset,UCombatantComponent::StaticClass()))
	{
		temp_comp=Cast<UCombatantComponent>(ref_comp);
		
	}
	if(UActorComponent* ref_compB = local_GetComponentFromObject(ListOwner,UCombatantComponent::StaticClass()))
    {
		temp_comp=Cast<UCombatantComponent>(ref_compB);
    }
	if(temp_comp)
	{
		if(temp_comp!=REF_Combatant && REF_attribute)
		{
			REF_Combatant=temp_comp;
			REF_Combatant->OnDamaged.AddDynamic(this, &UDataWidgetBase_Attribute::local_OnAttributeDamaged);
		}
	}
	
	local_UpdateColor();
}

void UDataWidgetBase_Attribute::NativePreConstruct()
{
	SetAttribute(REF_attribute);
	Super::NativePreConstruct();
}

void UDataWidgetBase_Attribute::SetAttribute(UOmegaAttribute* Attribute)
{
	if(Attribute)
	{
		REF_attribute=Attribute;
		if(GetWidget_Panel_MetricValue())
		{
			if(REF_attribute->bIsValueStatic)
			{
				GetWidget_Panel_MetricValue()->SetVisibility(PanelVisibility_OnStatic);
			}
			else
			{
				
				GetWidget_Panel_MetricValue()->SetVisibility(PanelVisibility_OnMetric);
			}
		}
		local_UpdateColor();
		OnAttributeChanged(REF_attribute);
	}
}

UOmegaAttribute* UDataWidgetBase_Attribute::GetAttribute() const
{
	if(REF_attribute) {return REF_attribute;} return nullptr;
}

void UDataWidgetBase_Attribute::SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant,
	UObject* ComparedSource, UObject* UncomparedSource)
{
	IWidgetInterface_Combatant::SetAttributeComparison_Implementation(bComparing, Combatant, ComparedSource,
	                                                                  UncomparedSource);
}

// ==============================================================================================================
// Leveling
// ==============================================================================================================

void UDataWidgetBase_Leveling::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(Asset,ULevelingComponent::StaticClass()))
	{
		REF_Comp=Cast<ULevelingComponent>(temp_comp);
		if(REF_Comp && REF_Comp->LevelingAsset)
		{
			if(GetWidget_Text_RankName())
			{
				GetWidget_Text_RankName()->SetText(REF_Comp->LevelingAsset->RankName);
			}
			if(GetWidget_Text_XpName())
			{
				GetWidget_Text_XpName()->SetText(REF_Comp->LevelingAsset->XPName);
			}
		}
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_Leveling::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);

	if(REF_Comp && REF_Comp->LevelingAsset)
	{
		if(GetWidget_ProgressBar())
		{
			GetWidget_ProgressBar()->SetPercent(REF_Comp->GetPercentageToNextLevel());
		}
		if(GetWidget_Text_RankValue())
		{
			GetWidget_Text_RankValue()->SetText(FText::AsNumber(REF_Comp->GetCurrentLevel()));
		}
		if(GetWidget_Text_CurrentValue())
		{
			GetWidget_Text_CurrentValue()->SetText(FText::AsNumber(REF_Comp->XP));
		}
		if(GetWidget_Text_MaxValue())
		{
			GetWidget_Text_CurrentValue()->SetText(FText::AsNumber(REF_Comp->GetCurrentLevelMaxXP()));
		}
	}
}

// ==============================================================================================================
// QUEST
// ==============================================================================================================

void UDataWidgetBase_Quest::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(Asset,UOmegaQuestComponent::StaticClass()))
	{
		QuestComponent=Cast<UOmegaQuestComponent>(temp_comp);
		if(GetDataList_ActiveTasks())
		{
			GetDataList_ActiveTasks()->SetListOwner(QuestComponent);
		}
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_Quest::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(QuestComponent)
	{
		if(GetDataList_ActiveTasks())
		{
			GetDataList_ActiveTasks()->ClearList();
			for(auto* temp_object : QuestComponent->GetActiveQuestTasks())
			{
				if(temp_object)
				{
					GetDataList_ActiveTasks()->AddAssetToList(temp_object,"");
				}
			}
		}
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

// ==============================================================================================================
// Equipment
// ==============================================================================================================

void UDataWidgetBase_Equipment::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(Asset,UEquipmentComponent::StaticClass()))
	{
		REF_Comp=Cast<UEquipmentComponent>(temp_comp);
		if(GetDataList_EquipSlots())
		{
			GetDataList_EquipSlots()->SetListOwner(REF_Comp);
		}
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

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
	if(UActorComponent* temp_comp = local_GetComponentFromObject(ListOwner,UEquipmentComponent::StaticClass()))
	{
		REF_Comp=Cast<UEquipmentComponent>(temp_comp);
	}
	Super::OnNewListOwner_Implementation(ListOwner);
}

void UDataWidgetBase_EquipmentSlot::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(REF_Comp && REF_Slot)
	{
		if(GetDataWidget_EquippedItem())
		{
			bool bRetunVal;
			GetDataWidget_EquippedItem()->SetSourceAsset(REF_Comp->GetEquipmentInSlot(REF_Slot,bRetunVal));
		}
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

// ==============================================================================================================
// Message
// ==============================================================================================================

void UDataWidgetBase_Message::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(Asset && Asset->GetClass()->IsChildOf(UOmegaGameplayMessage::StaticClass()))
	{
		REF_message=Cast<UOmegaGameplayMessage>(Asset);
		if(GetWidget_Text_Message())
		{
			GetWidget_Text_Message()->SetText(REF_message->GetMessageText());
		}
		if(GetDataWidget_MessageInstigator())
		{
			GetDataWidget_MessageInstigator()->SetSourceAsset(REF_message->GetMessageInstigator());	
		}
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}
