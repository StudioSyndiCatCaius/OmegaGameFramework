// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_AbilitySelector.h"
#include "Actors/Actor_Ability.h"
#include "Components/Component_Combatant.h"


UAbilitySelectorComponent::UAbilitySelectorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UAbilitySelectorComponent::BeginPlay()
{
	Super::BeginPlay();

	if (bForceGrantAbilities && CombatantRef)
	{
		CombatantRef->SetAbilitiesGranted(Abilities, true);
	}
}


void UAbilitySelectorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bSelectorActive || !CombatantRef) { return; }

	// Suppress selection while a blocking ability is active.
	for (AOmegaAbility* Ability : CombatantRef->GetGrantedAbilities())
	{
		if (Ability && Ability->bIsActive && Ability->BlockAutoAbilitySelectorWhileActive)
		{
			return;
		}
	}

	SelectorAccumulator += DeltaTime;
	if (SelectorAccumulator < SelectFrequency) { return; }
	SelectorAccumulator = 0.f;

	// Sync tracked state with actual ability activity.
	if (bSelectorAbilityActive)
	{
		if (!SelectorActiveAbilityClass || !CombatantRef->IsAbilityActive(SelectorActiveAbilityClass))
		{
			bSelectorAbilityActive = false;
			SelectorActiveAbilityClass = nullptr;
		}
	}

	// Evaluate utility for each ability in our explicit list.
	float BestUtil = 0.f;
	int32 BestPriority = INT32_MIN;
	TSubclassOf<AOmegaAbility> BestClass = nullptr;
	UObject* BestContext = nullptr;
	FOmegaCombatantEventMeta BestMeta;

	for (TSubclassOf<AOmegaAbility> AbilityClass : Abilities)
	{
		if (!AbilityClass) { continue; }

		bool bFound = false;
		AOmegaAbility* Ab = CombatantRef->GetAbility(AbilityClass, bFound);
		if (!bFound || !Ab) { continue; }

		UObject* LocalContext = nullptr;
		FOmegaCombatantEventMeta Meta;
		int32 Priority = 0;
		const float UtilVal = Ab->UtilityCheck(CombatantRef, LocalContext,Meta, Priority);

		if (UtilVal <= 0.f) { continue; }

		const bool bBetterUtil = UtilVal > BestUtil;
		const bool bSameUtilHigherPriority = (UtilVal == BestUtil) && (Priority > BestPriority);

		if (bBetterUtil || bSameUtilHigherPriority)
		{
			BestUtil = UtilVal;
			BestPriority = Priority;
			BestClass = AbilityClass;
			BestContext = LocalContext;
			BestMeta=Meta;
		}
	}

	if (!BestClass) { return; }

	// Already running this ability — nothing to change.
	if (bSelectorAbilityActive && BestClass == SelectorActiveAbilityClass) { return; }

	// A different ability won; cancel the current one if configured to do so.
	if (bSelectorAbilityActive)
	{
		if (!bCancelAbilityOnSelectorChange) { return; }
		CombatantRef->StopAbility(SelectorActiveAbilityClass, true);
	}

	bool bExecuted = false;
	CombatantRef->ExecuteAbility(BestClass, BestContext,BestMeta, bExecuted);

	if (bExecuted)
	{
		bSelectorAbilityActive = true;
		SelectorActiveAbilityClass = BestClass;
	}
}
