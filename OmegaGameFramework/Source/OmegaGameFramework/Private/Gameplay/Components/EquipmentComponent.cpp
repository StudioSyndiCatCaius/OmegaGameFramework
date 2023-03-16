// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Components/EquipmentComponent.h"
#include "Engine/DataAsset.h"
#include "Gameplay/CombatantComponent.h"
#include "Gameplay/GameplayTagsInterface.h"


// Sets default values for this component's properties
UEquipmentComponent::UEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	if(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->AddAttrbuteModifier(this);
	}
	
	Super::BeginPlay();
}

void UEquipmentComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))->RemoveAttributeModifier(this);
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

TMap<FString, UPrimaryDataAsset*> UEquipmentComponent::GetEquipment()
{
	return EquippedItems;
}

TArray<UPrimaryDataAsset*> UEquipmentComponent::GetEquippedItems()
{
	TArray<UPrimaryDataAsset*> OutItems;
	TArray<FString> LocalSlots;
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

void UEquipmentComponent::SetEquipment(TMap<FString, UPrimaryDataAsset*> Equipment)
{
	EquippedItems = Equipment;
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

bool UEquipmentComponent::EquipItem(UPrimaryDataAsset* Item, FString Slot)
{
	if(!Item)
	{
		return false;
	}
	if(IsItemAccepted(Item) && !IsItemRejected(Item))
	{
		UnequipSlot(Slot);
		EquippedItems.Add(Slot, Item);
		OnItemEquipped.Broadcast(Item, Slot);
		return true;
	}
	return false;
}

bool UEquipmentComponent::UnequipSlot(FString Slot)
{
	if(EquippedItems.FindOrAdd(Slot))
	{
		UPrimaryDataAsset* RemovedItem = EquippedItems.FindOrAdd(Slot);
		EquippedItems.Remove(Slot);
		OnItemUnequipped.Broadcast(RemovedItem, Slot);
		return true;
	}
	return false;
}



UPrimaryDataAsset* UEquipmentComponent::GetEquipmentInSlot(FString Slot, bool& bValidItem)
{
	if(EquippedItems.FindOrAdd(Slot))
	{
		bValidItem = true;
		return EquippedItems.FindOrAdd(Slot);
	}
	bValidItem = false;
	return nullptr;
}

TArray<FOmegaAttributeModifier> UEquipmentComponent::GetModifierValues_Implementation()
{
	TArray<FOmegaAttributeModifier> OutMods;
	
	TArray<UPrimaryDataAsset*> LocalItems;
	EquippedItems.GenerateValueArray(LocalItems);

	for(auto* TempAsset : LocalItems)
	{
		if(TempAsset && TempAsset->GetClass()->ImplementsInterface(UDataInterface_AttributeModifier::StaticClass()))
		{
			OutMods.Append(IDataInterface_AttributeModifier::Execute_GetModifierValues(TempAsset));
		}
	}
	return OutMods;
}

