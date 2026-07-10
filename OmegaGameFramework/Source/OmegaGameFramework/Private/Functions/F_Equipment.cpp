// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Equipment.h"

#include "OmegaSettings.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_Inventory.h"
#include "Condition/Condition_DataAsset.h"
#include "DataAssets/DA_EquipSlot.h"
#include "Engine/DataAsset.h"
#include "Engine/GameInstance.h"
#include "Functions/F_Common.h"
#include "Interfaces/I_Common.h"

/*
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


//##############################################################################################
// Equipment Slot
//##############################################################################################

*/


TArray<UPrimaryDataAsset*> UOmegaEquipmentFunctions::FilterEquippableItems(TArray<UPrimaryDataAsset*> items,
	UCombatantComponent* component, UEquipmentSlot* Slot)
{
	TArray<UPrimaryDataAsset*>  out;
	if (component && Slot)
	{
		for(auto* p : items)
		{
			if (p && Slot->CanSlotEquipItemOnCombatant(component,p))
			{
				out.Add(p);	
			}
		}
	}
	return out;
}

TArray<UPrimaryDataAsset*> UOmegaEquipmentFunctions::GetEquippableItems_FromInventory(UCombatantComponent* Combatant,
	UCombatantComponent* Inventory, UEquipmentSlot* Slot, int32 FilterMinimum)
{
	TArray<UPrimaryDataAsset*>  out;
	if(Combatant && Inventory)
	{
		TArray<UPrimaryDataAsset*>  i;
		Inventory->Inventory_Get(FilterMinimum).GetKeys(i);
		return FilterEquippableItems(i,Combatant,Slot);
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
			/*
			if(UEquipmentSlot* _slot=Cast<UEquipmentSlot>(p.Key))
			{
				out.Add(_slot,p.Value);
			*/
		}
	}
	return out;
}


