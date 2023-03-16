// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Combatant/CombatantGroupComponent.h"

#include "JsonObjectWrapper.h"
#include "Gameplay/CombatantComponent.h"

// Sets default values for this component's properties
UCombatantGroupComponent::UCombatantGroupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatantGroupComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatantGroupComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCombatantGroupComponent::IsGroupFull()
{
	return MaxGroupMembers>0 && GetCombatants().Num() >= MaxGroupMembers;
}

UCombatantComponent* UCombatantGroupComponent::GetCombatantOfIndex(int32 Index)
{
	if(Local_CombatantList[0])
	{
		return Local_CombatantList[0];
	}
	return nullptr;
}

bool UCombatantGroupComponent::SetCombatantInGroup(UCombatantComponent* Combatant, bool InGroup)
{
	if(IsGroupFull() && !ReplaceIfAtMaxCapacity)
	{
		return false;
	}
	if(Combatant)
	{
		if(InGroup)
		{
			if(IsGroupFull() && ReplaceIfAtMaxCapacity)
			{
				Local_CombatantList.RemoveAt(0);
				
			}
			Local_CombatantList.AddUnique(Combatant);
		}
		else
		{
			Local_CombatantList.Remove(Combatant);
		}
		
		OnCombatantSetInGroup.Broadcast(Combatant, InGroup);
	}
	return true;
}

TArray<UCombatantComponent*> UCombatantGroupComponent::GetCombatants()
{
	TArray<UCombatantComponent*> OutList;
	for(auto* TempCombatant : Local_CombatantList)
	{
		if(TempCombatant)
		{
			OutList.AddUnique(TempCombatant);
		}
	}
	return OutList;
}

void UCombatantGroupComponent::SetPrimitiveComponentRegister(UPrimitiveComponent* Component, bool bActive)
{
	if(Component)
	{
		if(bActive)
		{
			Local_BreakLinkedComp();
			
			Component->OnComponentBeginOverlap.AddDynamic(this, &UCombatantGroupComponent::Local_Overlap);
			Component->OnComponentEndOverlap.AddDynamic(this, &UCombatantGroupComponent::Local_OverlapEnd);
			LinkedPrimitiveComponent = Component;
		}
		else
		{
			Local_BreakLinkedComp();	
		}
	}
}

void UCombatantGroupComponent::Local_Overlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor && OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		UCombatantComponent* LocalComb = Cast<UCombatantComponent>(OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()));
		SetCombatantInGroup(LocalComb, true);
	}
}

void UCombatantGroupComponent::Local_OverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor && OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		UCombatantComponent* LocalComb = Cast<UCombatantComponent>(OtherActor->GetComponentByClass(UCombatantComponent::StaticClass()));
		SetCombatantInGroup(LocalComb, false);
	}
}

void UCombatantGroupComponent::Local_BreakLinkedComp()
{
	if(LinkedPrimitiveComponent)
	{
		LinkedPrimitiveComponent->OnComponentBeginOverlap.RemoveDynamic(this, &UCombatantGroupComponent::Local_Overlap);
		LinkedPrimitiveComponent->OnComponentEndOverlap.RemoveDynamic(this, &UCombatantGroupComponent::Local_OverlapEnd);
		LinkedPrimitiveComponent = nullptr;
	}
}