// Fill out your copyright notice in the Description page of Project Settings.

#include "DataWidgets/DW_Attribute.h"
#include "Components/ActorComponent.h"
#include "Components/Component_Combatant.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Functions/F_Common.h"
#include "Widget/WG_DynamicProgressBar.h"
#include "Engine/HitResult.h"


void UDataWidgetBase_Attribute::local_Update()
{
	if(REF_attribute && REF_Combatant)
	{
		float _att_percent=REF_Combatant->GetAttributePercentage(REF_attribute);
		//set bar color
		FLinearColor in_color=REF_attribute->color;
		if(REF_Combatant && bUseDamageColor && _att_percent<DamageColorPercentChange)
		{
			in_color=REF_attribute->DamageColor;
		}

		UProgressBar* ProgressBar=nullptr;
		UDynamicProgressBar* DynaProgressBar=nullptr;
		UTextBlock* txt_currentValue=nullptr;
		UTextBlock* txt_maxValue=nullptr;
		UTextBlock* txt_percentValue=nullptr;
		GetDataWidgetBindings(ProgressBar, DynaProgressBar, txt_currentValue, txt_maxValue, txt_percentValue);

		if(ProgressBar)
		{
			ProgressBar->SetPercent(_att_percent);
			ProgressBar->SetFillColorAndOpacity(in_color);
		}
		if(DynaProgressBar)
		{
			DynaProgressBar->SetProgress(_att_percent);
		}

		float val_cur;
		float val_max;
		REF_Combatant->GetAttributeValue(REF_attribute, val_cur, val_max);

		if(txt_currentValue)
		{
			txt_currentValue->SetText(REF_attribute->GetAttributeValueDisplayText(val_cur));
		}
		if(txt_maxValue)
		{
			txt_maxValue->SetText(REF_attribute->GetAttributeValueDisplayText(val_max));
		}
		if(txt_percentValue)
		{
			txt_percentValue->SetText(REF_attribute->GetAttributeValueDisplayText(_att_percent));
		}
	}
}

void UDataWidgetBase_Attribute::local_OnAttributeDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
                                                         float FinalDamage, UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit)
{
	if(Combatant==REF_Combatant && Attribute==REF_attribute)
	{
		local_Update();
	}
}

void UDataWidgetBase_Attribute::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	if(SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaAttribute::StaticClass()))
	{
		SetAttribute(Cast<UOmegaAttribute>(SourceAsset));
	}
	else if(UActorComponent* ref_comp = local_GetComponentFromObject(SourceAsset,UCombatantComponent::StaticClass()))
	{
		SetCombatant(Cast<UCombatantComponent>(ref_comp));
	}

	Super::Native_OnSourceAssetChanged(SourceAsset);
}

void UDataWidgetBase_Attribute::Native_OnListOwnerChanged(UObject* ListOwner)
{
	if(UActorComponent* ref_comp = local_GetComponentFromObject(ListOwner,UCombatantComponent::StaticClass()))
	{
		SetCombatant(Cast<UCombatantComponent>(ref_comp));
	}
	Super::Native_OnListOwnerChanged(ListOwner);
}

void UDataWidgetBase_Attribute::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	local_Update();
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

void UDataWidgetBase_Attribute::NativePreConstruct()
{
	SetAttribute(REF_attribute);
	Super::NativePreConstruct();
}

void UDataWidgetBase_Attribute::SetCombatant(UCombatantComponent* Combatant)
{
	if(Combatant)
	{
		if(REF_Combatant)
		{
			Combatant->OnDamaged.RemoveDynamic(this,&UDataWidgetBase_Attribute::local_OnAttributeDamaged);
		}
		REF_Combatant=Combatant;
		Combatant->OnDamaged.AddDynamic(this, &UDataWidgetBase_Attribute::local_OnAttributeDamaged);
	}
	else
	{
		REF_Combatant=nullptr;
	}
}

UCombatantComponent* UDataWidgetBase_Attribute::GetCombatant() const
{
	if(REF_Combatant) {return REF_Combatant;} return nullptr;
}

void UDataWidgetBase_Attribute::SetAttribute(UOmegaAttribute* Attribute)
{
	if(Attribute)
	{
		if(REF_attribute!=Attribute)
		{
			OnAttributeChanged(Attribute);
		}
		REF_attribute=Attribute;
		Refresh();
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
