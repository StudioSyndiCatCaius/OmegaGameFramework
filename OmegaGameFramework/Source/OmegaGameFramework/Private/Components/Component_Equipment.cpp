// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Equipment.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Global.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_Inventory.h"
#include "Condition/Condition_DataAsset.h"
#include "Engine/DataAsset.h"
#include "Engine/GameInstance.h"
#include "Functions/F_Common.h"
#include "Interfaces/I_Common.h"


// Sets default values for this component's properties
UEquipmentComponent::UEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	if(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->SetMasterDataSourceActive(this,true);
	}
	
	Super::BeginPlay();
}

void UEquipmentComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->SetAttributeModifierActive(this,false);
	}
	
	Super::EndPlay(EndPlayReason);
}


// Called every frame
void UEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


TMap<UEquipmentSlot*, UPrimaryDataAsset*> UEquipmentComponent::GetEquipment()
{
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> out=Slots;
	for(auto* s : Sources)
	{
		if(s && s->GetClass()->ImplementsInterface(UDataInterface_EquipmentSource::StaticClass()))
		{
			out.Append(IDataInterface_EquipmentSource::Execute_GetEquipment(s));
		}
	}
	out.Append(GetMutableDefault<UOmegaSettings>()->GetGlobalSettings()->Append_Equipment(this));
	return out;
}

void UEquipmentComponent::SetEquipment(TMap<UEquipmentSlot*, UPrimaryDataAsset*> Equipment)
{
	TArray<UEquipmentSlot*> slot_list;
	Slots.GetKeys(slot_list);
	for(UEquipmentSlot* temp_slot : slot_list)
	{
		UnequipSlot(temp_slot);
	}
	Equipment.GetKeys(slot_list);
	for(UEquipmentSlot* temp_slot : slot_list)
	{
		EquipItem(Equipment[temp_slot], temp_slot);
	}
}

void UEquipmentComponent::SetEquipment_SourceActive(UObject* Source, bool bActiveSource)
{
	if (Source && Source->GetClass()->ImplementsInterface(UDataInterface_EquipmentSource::StaticClass()))
	{
		if(bActiveSource && !Sources.Contains(Source))
		{
			Sources.AddUnique(Source);
		}
		else if(!bActiveSource && Sources.Contains(Source))
		{
			Sources.Remove(Source);
		}
	}
}


TArray<UPrimaryDataAsset*> UEquipmentComponent::GetEquippedItems()
{
	TArray<UPrimaryDataAsset*> OutItems;
	TArray<UEquipmentSlot*> LocalSlots;
	GetEquipment().GetKeys(LocalSlots);
	for(auto TempSlot : LocalSlots)
	{
		if(GetEquipment().Find(TempSlot))
		{
			OutItems.Add(GetEquipment()[TempSlot]);
		}
	}
	return OutItems;
}


///ACCEPT AND REJECT ITEM
bool UEquipmentComponent::IsItemAccepted(UPrimaryDataAsset* Item)
{
	if(AcceptedItemTags.IsEmpty()) {return true;}
	
	if(Item->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		if(AcceptedItemTags.HasAnyExact(IGameplayTagsInterface::Execute_GetObjectGameplayTags(Item)))
		{
			return true;
		}
	}
	return false;
}

bool UEquipmentComponent::IsItemRejected(UPrimaryDataAsset* Item)
{
	if(RejectedItemTags.IsEmpty()) {return false;}
	
	if(Item->GetClass()->ImplementsInterface(UGameplayTagsInterface::StaticClass()))
	{
		if(RejectedItemTags.HasAnyExact(IGameplayTagsInterface::Execute_GetObjectGameplayTags(Item)))
		{
			return true;
		}
	}
	return false;
}

bool UEquipmentComponent::CanEquipItem(UPrimaryDataAsset* Item, UEquipmentSlot* Slot)
{
	if(Item && Slot)
	{
		if(Item->GetClass()->ImplementsInterface(UDataInterface_Equipable::StaticClass()))
		{
			if(!IDataInterface_Equipable::Execute_CanEquipItem(Item,this,Slot)) {return false;};
		}
		if(!Slot->CanSlotEquipItem(Item)) { return false; }

		return true; //if all succeed, return true
	}
	return false;
}

TArray<UPrimaryDataAsset*> UEquipmentComponent::FilterEquippableItems(TArray<UPrimaryDataAsset*> Items,
	UEquipmentSlot* Slot)
{
	TArray<UPrimaryDataAsset*> out;
	if(Slot)
	{
		for(auto* tempItem: Items)
		{
			if(tempItem && CanEquipItem(tempItem,Slot))
			{
				out.Add(tempItem);
			}
		}
	}
	return out;
}

bool UEquipmentComponent::EquipItem(UPrimaryDataAsset* Item, UEquipmentSlot* Slot)
{
	if(!Item || !Slot)
	{
		return false;
	}
	if(IsItemAccepted(Item) && !IsItemRejected(Item))
	{
		//Check if the component script is blocking the item
		if(Script)
		{
			bool success = CanEquipItem(Item,Slot);
			if(!success)
			{
				return false;
			}
		}
		
		UnequipSlot(Slot);
		
		for(auto* temp_script : Slot->SlotScripts)
		{
			temp_script->OnEquip(this,Item);
		}
		
		Slots.Add(Slot, Item);
		OnItemEquipped.Broadcast(this,Item, Slot);
		
		//Modify Linked Collection Component
		if(LinkedCollectionComp)
		{
			LinkedCollectionComp->RemoveAsset(Item,1);
		}
		
		return true;
	}
	return false;
}

bool UEquipmentComponent::UnequipSlot(UEquipmentSlot* Slot)
{
	if(Slot)
	{
		if(Slots.FindOrAdd(Slot))
		{
			UPrimaryDataAsset* RemovedItem = Slots.FindOrAdd(Slot);
			if(Slot)
			{
				for(auto* temp_script : Slot->SlotScripts)
				{
					temp_script->OnUnequip(this,RemovedItem);
				}
			}
			Slots.Remove(Slot);
			OnItemUnequipped.Broadcast(this,RemovedItem, Slot);
			//Modify Linked Collection Component
			if(LinkedCollectionComp)
			{
				LinkedCollectionComp->AddAsset(RemovedItem,1);
			}
		
			return true;
		}
	}
	return false;
}



UPrimaryDataAsset* UEquipmentComponent::GetEquipmentInSlot(UEquipmentSlot* Slot, bool& bValidItem)
{
	TMap<UEquipmentSlot*,UPrimaryDataAsset*> tempEQ=GetEquipment();
	if(tempEQ.FindOrAdd(Slot))
	{
		bValidItem = true;
		return tempEQ.FindOrAdd(Slot);
	}
	bValidItem = false;
	return nullptr;
}

TArray<FOmegaAttributeModifier> UEquipmentComponent::GetModifierValues_Implementation(UCombatantComponent* CombatantComponent)
{
	TArray<FOmegaAttributeModifier> OutMods;
	if(bModifyAttributes)
	{
		TArray<UPrimaryDataAsset*> LocalItems;
		Slots.GenerateValueArray(LocalItems);
		for(auto* TempAsset : LocalItems)
		{
			if(TempAsset && TempAsset->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
			{
				OutMods.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(TempAsset, CombatantComponent));
			}
		}
	}
	return OutMods;
}

TArray<UPrimaryDataAsset*> UEquipmentComponent::GetSkills_Implementation(UCombatantComponent* Combatant)
{
	TArray<UPrimaryDataAsset*> out;
	if(bIsSkillSource)
	{
		TArray<UPrimaryDataAsset*> item_list;
		Slots.GenerateValueArray(item_list);
		for(auto* temp_item : item_list)
		{
			if(temp_item && temp_item->GetClass()->ImplementsInterface(UDataInterface_SkillSource::StaticClass()))
			{
				out.Append(IDataInterface_SkillSource::Execute_GetSkills(temp_item,Combatant));
			}
		}
	}
	return out;
}

float UEquipmentComponent::ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target,
	UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context)
{
	if(!bModifyDamage) { return BaseDamage; }
	
	float dmg=BaseDamage;
	TArray<UPrimaryDataAsset*> items;
	GetEquipment().GenerateValueArray(items);
	
	for(auto* i : items)
	{
		if(i && i->GetClass()->ImplementsInterface(UDataInterface_DamageModifier::StaticClass()))
		{
			dmg=IDataInterface_DamageModifier::Execute_ModifyDamage(i,Attribute,Target,Instigator,dmg,DamageType,Context);
		}
	}
	return dmg;
}

void UEquipmentComponent::LinkAssetCollectionComponent(UDataAssetCollectionComponent* Component)
{
	if(Component)
	{
		LinkedCollectionComp = Component;
	}
}

void UEquipmentComponent::ClearLinkedAssetCollectionComponent(UDataAssetCollectionComponent* Component)
{
	LinkedCollectionComp = nullptr;
}

//##############################################################################################
// Equipment Script
//##############################################################################################

UWorld* UEquipmentScript::GetWorld() const
{
	if(GetGameInstance()) { return GetGameInstance()->GetWorld(); } return nullptr;
}

UGameInstance* UEquipmentScript::GetGameInstance() const
{
	return Cast<UGameInstance>(GetOuter());
}

UEquipmentScript::UEquipmentScript(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
}

bool UEquipmentSlotScript::CanEquipItem_Implementation(UObject* Item) const
{
	return true;
}


//##############################################################################################
// Equipment Slot
//##############################################################################################

void UEquipmentSlot::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                       FText& Description)
{
	Name = SlotName;
	Description = SlotDescription;
}

void UEquipmentSlot::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = SlotIcon;
}

void UEquipmentSlot::GetGeneralAssetLabel_Implementation(FString& Label)
{
	Label = this->GetName();
}

FGameplayTag UEquipmentSlot::GetObjectGameplayCategory_Implementation()
{
	return SlotCategory;
}

FGameplayTagContainer UEquipmentSlot::GetObjectGameplayTags_Implementation()
{
	return SlotTags;
}

bool UEquipmentSlot::CanSlotEquipItem(UPrimaryDataAsset* Item)
{
	if(Item)
	{
		FOmegaConditions_DataAsset con;
		con.Conditions=EquipConditions;
		TArray<FText> r; // this should probably be made an output at some point.
		if(!con.CheckConditions(Item,r)) { return false; }
		for(auto* temp_script : SlotScripts)
		{
			if(!temp_script->CanEquipItem(Item))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

UPrimaryDataAsset* UOmegaEquipmentFunctions::TryGetEquipmentInSlot(UObject* Target, UEquipmentSlot* Slot,
	bool& Outcome)
{
	if(Slot)
	{
		if(UActorComponent* _equipComp = UOmegaGameFrameworkBPLibrary::TryGetComponentFromObject(Target,UEquipmentComponent::StaticClass(),Outcome))
		{
			bool _boolReturn;
			if(UPrimaryDataAsset* _out = Cast<UEquipmentComponent>(_equipComp)->GetEquipmentInSlot(Slot,_boolReturn))
			{
				Outcome=true;
				return _out;
			}
		}
	}
	Outcome=false;
	return nullptr;
}

TArray<UPrimaryDataAsset*> UOmegaEquipmentFunctions::GetEquippableItems_FromInventory(UEquipmentComponent* Equipment,
	UDataAssetCollectionComponent* Inventory, UEquipmentSlot* Slot,bool bIncludedSources)
{
	TArray<UPrimaryDataAsset*>  out;
	if(Equipment && Inventory)
	{
		TArray<UPrimaryDataAsset*>  i;
		Inventory->GetCollectionMap(1,bIncludedSources).GetKeys(i);
		return Equipment->FilterEquippableItems(i,Slot);
	}
	return  out;
		
}

TMap<UEquipmentSlot*, UPrimaryDataAsset*> UOmegaEquipmentFunctions::GetEquipmentFromLinkedAssetList(
	TMap<UPrimaryDataAsset*, UPrimaryDataAsset*> list)
{
	TMap<UEquipmentSlot*, UPrimaryDataAsset*> out;
	for(auto& p : list)
	{
		if(p.Key && p.Value)
		{
			if(UEquipmentSlot* _slot=Cast<UEquipmentSlot>(p.Key))
			{
				out.Add(_slot,p.Value);
			}
		}
	}
	return out;
}


