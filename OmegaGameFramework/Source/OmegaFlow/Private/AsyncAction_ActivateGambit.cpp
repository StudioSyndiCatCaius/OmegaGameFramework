// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_ActivateGambit.h"

#include "Gameplay/CombatantComponent.h"

void UAsyncAction_ActivateGambit::NativeShutdown(bool bCancelled)
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

void UAsyncAction_ActivateGambit::Activate()
{
	TSubclassOf<AOmegaAbility> IncomingAbility;
	UObject* IncomingContext;
		
	if(CombatantRef->GetActionDataFromGambit(LocalGambit, IncomingAbility,IncomingContext))
	{
		bool WasSuccess;
		LocalAbility = CombatantRef->ExecuteAbility(IncomingAbility, IncomingContext,WasSuccess);
		if(WasSuccess && LocalAbility)
		{
			LocalAbility->OnAbilityFinished.AddDynamic(this, &UAsyncAction_ActivateGambit::NativeShutdown);
		}
		else
		{
			Failed.Broadcast();
			SetReadyToDestroy();
		}
	}
	
}

UAsyncAction_ActivateGambit* UAsyncAction_ActivateGambit::ActivateGambit(UCombatantComponent* Combatant, UCombatantGambitAsset* Gambit)
{
	UAsyncAction_ActivateGambit* NewAbility = NewObject<UAsyncAction_ActivateGambit>();

	NewAbility->CombatantRef = Combatant;
	NewAbility->LocalGambit = Gambit;
	
	return NewAbility;
}
