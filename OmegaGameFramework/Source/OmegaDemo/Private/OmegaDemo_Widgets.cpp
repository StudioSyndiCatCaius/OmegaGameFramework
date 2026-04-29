// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaDemo_Widgets.h"
#include "Components/ActorComponent.h"
#include "Components/Component_Combatant.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "DataAssets/DA_Body.h"
#include "DataAssets/DA_EquipSlot.h"
#include "DataAssets/DA_Zone.h"
#include "Functions/F_Common.h"
#include "Kismet/KismetStringLibrary.h"
#include "Subsystems/Subsystem_World.h"
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
		//REF_combatant->OnCombatantNotify.AddDynamic(this, &UDataWidgetBase_Combatant::OnCombatantNotify);
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


void UDataWidgetBase_Leveling::L_SetTextFromVal(float val, UTextBlock* text) const
{
	if (text && LevelingAsset)
	{
		text->SetText(LevelingAsset->GetTextFromValue(val));
	}
}



void UDataWidgetBase_Leveling::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
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

// ==============================================================================================================
// QUEST
// ==============================================================================================================

void UDataWidgetBase_Quest::OnSourceAssetChanged_Implementation(UObject* Asset)
{
	if(UActorComponent* temp_comp = local_GetComponentFromObject(Asset,AOmegaQuestInstance::StaticClass()))
	{
		QuestInstance=Cast<AOmegaQuestInstance>(temp_comp);
		if(GetDataList_ActiveTasks())
		{
			GetDataList_ActiveTasks()->SetListOwner(QuestInstance);
		}
	}
	Super::OnSourceAssetChanged_Implementation(Asset);
}

void UDataWidgetBase_Quest::Native_OnRefreshed(UObject* SourceAsset, UObject* ListOwner)
{
	if(QuestInstance)
	{
		if(GetDataList_ActiveTasks())
		{
			GetDataList_ActiveTasks()->ClearList();
			for(auto* temp_object : QuestInstance->GetActiveTasks())
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
		UOmegaSubsystem_World* l_ZoneSub=GetWorld()->GetSubsystem<UOmegaSubsystem_World>();
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
				if(UOmegaLevelData* lvl= l_ZoneSub->GetWorldManager()->Zone_GetLevelData(nullptr))
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
