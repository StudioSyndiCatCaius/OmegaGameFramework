// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_CombatantSelector.h"


void UCombatantSelector::L_UpdateTargets()
{
	if (b_blocktargetUpdate) return;
	OnSelector_TargetsUpdated.Broadcast(this);
}

void UCombatantSelector::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description,
	FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig)
{
	Name=SelectorName;
	Description=SelectorDescription;
	iconBrush=SelectorIcon;
}

void UCombatantSelector::SetSelectorTargetActive(UCombatantComponent* Target, bool bActive)
{
	if (Target)
	{
		if (bActive && !ActiveTargets.Contains(Target))
		{
			if (IsTargetValid(Target))
			{
				ActiveTargets.AddUnique(Target);
				L_UpdateTargets();
			}
		}
		else if (!bActive && ActiveTargets.Contains(Target))
		{
			ActiveTargets.Remove(Target);
			L_UpdateTargets();
		}
	}
}

void UCombatantSelector::SetSelectorTargetsActive(TArray<UCombatantComponent*> Targets, bool bActive)
{
	b_blocktargetUpdate=true;
	for (auto* Target : Targets)
	{
		if (Target)
		{
			SetSelectorTargetActive(Target, bActive);
		}
	}
	b_blocktargetUpdate=false;
}

void UCombatantSelector::Refresh()
{
	TArray<UCombatantComponent*> ToRemove;
	for (auto* a : ActiveTargets)
	{
		if (a && !IsTargetValid(a))
		{
			ToRemove.Add(a);
		}
	}
	for (auto* a : ToRemove)
	{
		SetSelectorTargetActive(a, false);
	}
}

void UCombatantSelector::SelectorEvent(FGameplayTag Event)
{
	OnSelectorEvent(Event);
	Refresh();
}

void UCombatantSelector::OnSelectorEvent_Implementation(FGameplayTag Event)
{
}

void UCombatantSelector::FinalizeAndComplete()
{
	ActiveTargets=OnFinalizeTargets(ActiveTargets);
	OnSelector_Finalized.Broadcast(this);
}

void UCombatantSelector::CancelSelector()
{
	OnSelector_Cancelled.Broadcast(this);
	OnSelectorCancelled();
}

void UCombatantSelector::OnSelectorBegin_Implementation()
{
}

void UCombatantSelector::OnSelectorCancelled_Implementation()
{
}

TArray<UCombatantComponent*> UCombatantSelector::OnFinalizeTargets_Implementation(
	const TArray<UCombatantComponent*>& Targets) const
{
	return Targets;
}

bool UCombatantSelector::IsTargetValid_Implementation(UCombatantComponent* Target) const
{
	return true;
}

void UOmegaCombatantSelectorAsync::Local_TargetsUpdated(UCombatantSelector* Selector)
{
	TargetsUpdated.Broadcast(Selector);
}

void UOmegaCombatantSelectorAsync::Local_Finalized(UCombatantSelector* Selector)
{
	Finalized.Broadcast(Selector);
	SetReadyToDestroy();
}

void UOmegaCombatantSelectorAsync::Local_Cancelled(UCombatantSelector* Selector)
{
	Cancelled.Broadcast(Selector);
	SetReadyToDestroy();
}

void UOmegaCombatantSelectorAsync::Activate()
{
	Super::Activate();
	if (LocalSelectorClass && LocalInstigator)
	{
		LocalSelector = NewObject<UCombatantSelector>(this, LocalSelectorClass);
		LocalSelector->Instigator = LocalInstigator;
		LocalSelector->InputTargets = LocalInputTargets;
		LocalSelector->OnSelector_TargetsUpdated.AddDynamic(this, &UOmegaCombatantSelectorAsync::Local_TargetsUpdated);
		LocalSelector->OnSelector_Finalized.AddDynamic(this, &UOmegaCombatantSelectorAsync::Local_Finalized);
		LocalSelector->OnSelector_Cancelled.AddDynamic(this, &UOmegaCombatantSelectorAsync::Local_Cancelled);
		LocalSelector->OnSelectorBegin();
		LocalSelector->Refresh();
		LocalSelector->L_UpdateTargets();
	}
	else
	{
		SetReadyToDestroy();
	}
}

UOmegaCombatantSelectorAsync* UOmegaCombatantSelectorAsync::RunCombatantSelector(TSubclassOf<UCombatantSelector> Selector,
	UCombatantComponent* Instigator, TArray<UCombatantComponent*> InputTargets)
{
	UOmegaCombatantSelectorAsync* NewNode = NewObject<UOmegaCombatantSelectorAsync>();
	NewNode->LocalSelectorClass = Selector;
	NewNode->LocalInstigator = Instigator;
	NewNode->LocalInputTargets = InputTargets;
	return NewNode;
}

