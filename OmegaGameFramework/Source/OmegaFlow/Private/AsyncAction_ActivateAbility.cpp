// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_ActivateAbility.h"

#include "Gameplay/CombatantComponent.h"

void UAsyncAction_ActivateAbility::NativeShutdown(bool bCancelled)
{
	if(bCancelled)
	{
		Canceled.Broadcast();
		SetReadyToDestroy();
	}
	else
	{
		Completed.Broadcast();
		SetReadyToDestroy();
	}
}

void UAsyncAction_ActivateAbility::Activate()
{
	AOmegaAbility* AbilityRef;
	if(!CombatantRef->IsAbilityActive(LocalAbilityClass, AbilityRef))
	{
		bool IsSuccess;
		AOmegaAbility* LocalAbility = CombatantRef->ExecuteAbility(LocalAbilityClass, LocalContext, IsSuccess);
		if(IsSuccess)
		{
			LocalAbility->OnAbilityFinished.AddDynamic(this, &UAsyncAction_ActivateAbility::UAsyncAction_ActivateAbility::NativeShutdown);
		}
		else
		{
			Failed.Broadcast();
			SetReadyToDestroy();
		}
	}
	else
	{
		Failed.Broadcast();
		SetReadyToDestroy();
	}
}

UAsyncAction_ActivateAbility* UAsyncAction_ActivateAbility::ActivateAbility(UCombatantComponent* Combatant,
                                                                            const TSubclassOf<AOmegaAbility> Ability, UObject* Context)
{
	UAsyncAction_ActivateAbility* NewAbility = NewObject<UAsyncAction_ActivateAbility>();

	NewAbility->CombatantRef = Combatant;
	NewAbility->LocalAbilityClass = Ability;
	NewAbility->LocalContext = Context;

	return NewAbility;
}
