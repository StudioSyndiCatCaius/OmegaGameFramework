// Fill out your copyright notice in the Description page of Project Settings.


#include "DataItemComponent.h"

#include "OmegaDataSubsystem.h"

// Sets default values for this component's properties
UDataItemComponent::UDataItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDataItemComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaDataSubsystem>()->RegisterDataComponent(this);

	if(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		UCombatantComponent* LocalCombatant = Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()));
		LocalCombatant->AddAttrbuteModifier(this);
		LocalCombatant->SetSkillSourceActive(this, true);
	}

	if(DataItem)
	{
		OnDataItemChanged.Broadcast(DataItem);
	}
	
	// ...
	
}


// Called every frame
void UDataItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDataItemComponent::SetDataItem(UOmegaDataItem* NewDataItem)
{
	if(!NewDataItem)
	{
		DataItem = nullptr;
		return;
	}
	DataItem = NewDataItem;
	DataItem->ApplyTraitsToActor(GetOwner(), FlagOnApplied, TagsOnApplied);
	OnDataItemChanged.Broadcast(NewDataItem);
}

UOmegaDataItem* UDataItemComponent::GetDataItem()
{
	if(DataItem)
	{
		return DataItem;
	}
	return nullptr;
}

TArray<FOmegaAttributeModifier> UDataItemComponent::GetModifierValues_Implementation()
{
	if(DataItem)
	{
		return IDataInterface_AttributeModifier::Execute_GetModifierValues(DataItem);
	}
	return IDataInterface_AttributeModifier::GetModifierValues_Implementation();
}

TArray<UPrimaryDataAsset*> UDataItemComponent::GetSkills_Implementation()
{
	if(DataItem)
	{
		return IDataInterface_SkillSource::Execute_GetSkills(DataItem);
	}
	return IDataInterface_SkillSource::GetSkills_Implementation();
}

