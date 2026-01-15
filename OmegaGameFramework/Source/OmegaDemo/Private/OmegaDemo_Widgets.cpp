// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_Widgets.h"
#include "Components/ActorComponent.h"
#include "Components/Component_Combatant.h"
#include "Components/ProgressBar.h"
#include "Components/WidgetSwitcher.h"
#include "DataAssets/DA_Body.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetStringLibrary.h"
#include "Subsystems/Subsystem_Message.h"
#include "Subsystems/Subsystem_Zone.h"
#include "Widget/DataList.h"


UActorComponent* local_GetComponentFromObject(UObject* object, TSubclassOf<UActorComponent> Class)
{
	if(!Class || !object) { return nullptr; }
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

void UDataWidgetBase_Combatant::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	if(UCombatantComponent* ref_comp = Cast<UCombatantComponent>(local_GetComponentFromObject(SourceAsset,UCombatantComponent::StaticClass())))
	{
		REF_combatant=ref_comp;
		//REF_combatant->OnCombatantNotify.AddDynamic(this, &UDataWidgetBase_Combatant::OnCombatantNotify);
	}
	Super::Native_OnSourceAssetChanged(SourceAsset);
}

void UDataWidgetBase_Combatant::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(GetDataList_Attributes())
	{
		GetDataList_Attributes()->SetListOwner(SourceAsset);
		if(REF_combatant)
		{
			GetDataList_Attributes()->ClearList();
			for (UOmegaAttribute* temp_att : REF_combatant->AttributeSet->GetAllAttributes())
			{
				GetDataList_Attributes()->AddAssetToList(temp_att,"");
			}
		}
		//GetDataList_Attributes()->AddAssetsToList(REF_combatant->AttributeSet->Attributes,"")
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}

// ==============================================================================================================
// Attribute
// ==============================================================================================================


void L_ReplicateCompare(UDataList* l,bool bComparing, UCombatantComponent* Combatant,
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

void UDataWidgetBase_Combatant::SetAttributeComparison_Implementation(bool bComparing, UCombatantComponent* Combatant,
	UObject* ComparedSource, UObject* UncomparedSource)
{
	L_ReplicateCompare(GetDataList_Attributes(),bComparing,Combatant,ComparedSource,UncomparedSource);
	L_ReplicateCompare(GetDataList_Attributes_Metric(),bComparing,Combatant,ComparedSource,UncomparedSource);
	L_ReplicateCompare(GetDataList_Attributes_Static(),bComparing,Combatant,ComparedSource,UncomparedSource);
}

void UDataWidgetBase_Attribute::local_Update()
{
	if(REF_attribute && REF_Combatant)
	{
		float _att_percent=REF_Combatant->GetAttributePercentage(REF_attribute);
		//set bar color
		FLinearColor in_color=REF_attribute->AttributeColor;
		if(REF_Combatant && bUseDamageColor && _att_percent<DamageColorPercentChange)
		{
			in_color=REF_attribute->DamageColor;
		}
		
		if(UProgressBar* _bar =  GetWidget_ProgressBar_Attribute())
		{
			if(REF_Combatant)
			{
				_bar->SetPercent(_att_percent);
			}
			_bar->SetFillColorAndOpacity(in_color);
		}
		if(UDynamicProgressMeter* _dmeter = GetWidget_DynamicMeter_Attribute())
		{
			if(REF_Combatant)
			{
				_dmeter->SetPercent_Progress(_att_percent);
			}
			_dmeter->SetProgress_Color(in_color);
		}
		
		float val_cur;
		float val_max;
		if(REF_Combatant)
		{
			REF_Combatant->GetAttributeValue(REF_attribute,val_cur,val_max);
		}
		if(UTextBlock* _txt = GetWidget_Text_CurrentValue())
		{
			_txt->SetText(REF_attribute->GetAttributeValueDisplayText(val_cur));
		}
		if(UTextBlock* _txt = GetWidget_Text_MaxValue())
		{
			_txt->SetText(REF_attribute->GetAttributeValueDisplayText(val_max));
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
		if(GetWidget_Panel_MetricValue())
		{
			if(Attribute->bIsValueStatic)
			{
				GetWidget_Panel_MetricValue()->SetVisibility(PanelVisibility_OnStatic);
			}
			else
			{
				
				GetWidget_Panel_MetricValue()->SetVisibility(PanelVisibility_OnMetric);
			}
		}
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

// ==============================================================================================================
// Leveling
// ==============================================================================================================

void UDataWidgetBase_Leveling::L_SetLevelComp(ULevelingComponent* comp)
{
	if(comp)
	{
		REF_Comp=comp;
		OnLevelingComponentChanged(REF_Comp);
	}
}


void UDataWidgetBase_Leveling::L_onXP(ULevelingComponent* comp, float xp, float changed,UOmegaLevelingAsset* asset)
{
	Refresh();
}

void UDataWidgetBase_Leveling::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(Asset,ULevelingComponent::StaticClass()))
	{
		L_SetLevelComp(Cast<ULevelingComponent>(temp_comp));
		if(REF_Comp && REF_Comp->L_ValidateLevelAsset(GetLevelingAsset()))
		{
			if(GetWidget_Text_RankName())
			{
				GetWidget_Text_RankName()->SetText(REF_Comp->L_ValidateLevelAsset(GetLevelingAsset())->RankName);
			}
			if(GetWidget_Text_XpName())
			{
				GetWidget_Text_XpName()->SetText(REF_Comp->L_ValidateLevelAsset(GetLevelingAsset())->XPName);
			}
			REF_Comp->OnXPUpdated.AddDynamic(this, &UDataWidgetBase_Leveling::L_onXP);
		}
	}
	else if(UOmegaLevelingAsset* lvl_asset=Cast<UOmegaLevelingAsset>(Asset))
	{
		LevelingAsset=lvl_asset;
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_Leveling::Native_OnListOwnerChanged(UObject* ListOwner)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(ListOwner,ULevelingComponent::StaticClass()))
	{
		L_SetLevelComp(Cast<ULevelingComponent>(temp_comp));
	}
	Super::Native_OnListOwnerChanged(ListOwner);
}

void UDataWidgetBase_Leveling::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(REF_Comp)
	{
		if(GetWidget_ProgressBar())
		{
			GetWidget_ProgressBar()->SetPercent(REF_Comp->GetPercentageToNextLevel(LevelingAsset));
		}
		if(GetWidget_Text_RankValue())
		{
			GetWidget_Text_RankValue()->SetText(FText::AsNumber(REF_Comp->GetCurrentLevel(LevelingAsset)));
		}
		if(GetWidget_Text_CurrentValue())
		{
			GetWidget_Text_CurrentValue()->SetText(FText::AsNumber(REF_Comp->GetXP(LevelingAsset)));
		}
		if(GetWidget_Text_MaxValue())
		{
			GetWidget_Text_CurrentValue()->SetText(FText::AsNumber(REF_Comp->GetCurrentLevelMaxXP(LevelingAsset)));
		}
	}
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
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

void UDataWidgetBase_Message::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if(bWriteTextOverTime && __bTextIsUpdating)
	{
		//if count is over max strings, end
		if(!__stringsRemaining.IsValidIndex(__stringAmount))
		{
			__bTextIsUpdating=false;
		}
		else
		{
			if(__TextWriteTime>=TextWriteFrequency)
			{
				__TextWriteTime=0.0;
				if(UTextBlock* _text = GetWidget_Text_Message())
				{
					FString _inStr=_text->GetText().ToString()+__stringsRemaining[__stringAmount];
					_text->SetText(FText::FromString(_inStr));
				}
				__stringAmount+=1;
			}
			else
			{
				__TextWriteTime+=InDeltaTime;
			}
		}
	}
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UDataWidgetBase_Message::Native_OnSourceAssetChanged(UObject* SourceAsset)
{
	if(SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaGameplayMessage::StaticClass()))
	{
		REF_message=Cast<UOmegaGameplayMessage>(SourceAsset);
		OnMessageUpdate(REF_message);
		if(GetWidget_Text_Message())
		{
			FText _txt = REF_message->GetMessageText();
			if(bWriteTextOverTime)
			{
				GetWidget_Text_Message()->SetText(FText::FromString(""));
				__stringsRemaining=UKismetStringLibrary::GetCharacterArrayFromString(_txt.ToString());
				__stringAmount=0;
				
				__bTextIsUpdating=true;
			}
			else
			{
				GetWidget_Text_Message()->SetText(_txt);
			}
		}
		if(GetDataWidget_MessageInstigator())
		{
			GetDataWidget_MessageInstigator()->SetSourceAsset(REF_message->GetMessageInstigator());	
		}
		if(REF_message->GetMessageInstigator()!=REF_lastInstigator)
		{
			OnInstigatorChange(REF_message->GetMessageInstigator(),REF_lastInstigator);
			REF_lastInstigator=REF_message->GetMessageInstigator();
		}
		if(REF_lastInstigator)
		{
			if(REF_lastInstigator->GetClass()->ImplementsInterface(UDataInterface_MessageInstigator::StaticClass()))
			{
				if(UImage* _img = GetImage_InstigatorBrush())
				{
					_img->SetBrush(IDataInterface_MessageInstigator::Execute_GetMessageBrush(_img,REF_message));
				}
			}
		}
	}
	Super::Native_OnSourceAssetChanged(SourceAsset);
}


UOmegaGameplayMessage* UDataWidgetBase_Message::GetCurrentMessage() const
{
	if(REF_message) { return REF_message; } return nullptr;
}

// ==============================================================================================================
// Body Option
// ==============================================================================================================

void UDataWidgetBase_BodySlot::local_OnCheckChanged(bool bIsChecked)
{
	if(REF_Slot && REF_Comp)
	{
		REF_Comp->SetBodyParam_Bool(REF_Slot,bIsChecked);
	}
}

void UDataWidgetBase_BodySlot::local_SliderValueUpdate(float value)
{
	if(REF_Slot && REF_Comp)
	{
		REF_Comp->SetBodyParam_Float(REF_Slot,value);
	}
}

void UDataWidgetBase_BodySlot::local_onColorChange(const FLinearColor& color)
{
}


void UDataWidgetBase_BodySlot::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_BodySlot::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
	if(UActorComponent* temp_comp = local_GetComponentFromObject(ListOwner,USkinComponent::StaticClass()))
	{
		REF_Comp=Cast<USkinComponent>(temp_comp);
	}
	
	if(SourceAsset && SourceAsset->GetClass()->IsChildOf(UOmegaBodySlot::StaticClass()))
	{
		REF_Slot=Cast<UOmegaBodySlot>(SourceAsset);
		if(REF_Comp)
		{
			if(GetWidget_ToggleCheckBox())
			{
				GetWidget_ToggleCheckBox()->SetIsChecked(REF_Comp->GetBodyParam_Bool(REF_Slot));
				GetWidget_ToggleCheckBox()->OnCheckStateChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_OnCheckChanged);
			}
			if(GetWidget_Slider_Float())
			{
				GetWidget_Slider_Int()->SetMaxValue(REF_Slot->GetMaxValue().X);
				GetWidget_Slider_Float()->SetValue(REF_Comp->GetBodyParam_Float(REF_Slot));
				GetWidget_Slider_Float()->OnValueChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_SliderValueUpdate);
			}
			if(GetWidget_Slider_Int())
			{
				GetWidget_Slider_Int()->SetMaxValue(REF_Slot->GetMaxValue().X);
				GetWidget_Slider_Int()->SetStepSize(1.0);
				GetWidget_Slider_Int()->MouseUsesStep=true;
				GetWidget_Slider_Int()->SetValue(REF_Comp->GetBodyParam_Int(REF_Slot));
				GetWidget_Slider_Int()->OnValueChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_SliderValueUpdate);
			}
			if(GetWidget_Color())
			{
				GetWidget_Color()->OnColorChanged.AddDynamic(this, &UDataWidgetBase_BodySlot::local_onColorChange);
				GetWidget_Color()->SetColor(FLinearColor(REF_Comp->GetBodyParam_Vector(REF_Slot)));
			}
			
		}
	}
}

void UDataWidgetBase_SaveSlot::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(GetOwningPlayer() && GetGameInstance())
	{
		UOmegaZoneSubsystem* l_ZoneSub=GetWorld()->GetSubsystem<UOmegaZoneSubsystem>();
		UWidgetSwitcher* sw=GetWidget_Switcher_Type();
		if(UOmegaSaveGame* sav=Cast<UOmegaSaveGame>(Asset))
		{
			if(sw)
			{
				sw->SetActiveWidgetIndex(0);
			}
			if(UImage* img=GetWidget_Image_Screenshot())
			{
				if(sav->SaveScreenshot)
				{
					img->SetBrushFromTexture(sav->SaveScreenshot);
				}
			}
			if(UTextBlock* txt=GetWidget_Text_Playime())
			{
				txt->SetText(FText::FromString(sav->Playtime.ToString()));
			}
			if(UTextBlock* txt=GetWidget_Text_LevelName())
			{
				if(UOmegaLevelData* lvl= l_ZoneSub->GetLevelData(nullptr))
				{
					txt->SetText(lvl->DisplayName);
				}
				else
				{
					txt->SetText(FText::FromString("???"));
				}
			}
			if(UTextBlock* txt=GetWidget_Text_ZoneName())
			{
				if(sav->ActiveZone)
				{
					txt->SetText(sav->ActiveZone->DisplayName);
				}
				else
				{
					txt->SetText(FText::FromString("???"));
				}
			}
			OnSaveWidgetInit(sav);
		}
		if(sw) { sw->SetActiveWidgetIndex(1); }
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_SaveSlot::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	Super::Native_OnRefreshed(SourceAsset, ListOwner);
}
