// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_ActivateAbility.h"

#include "Components/Component_Combatant.h"

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
	if(CombatantRef)
	{
		if(b_autoGrant)
		{
			CombatantRef->SetAbilityGranted(LocalAbilityClass,true);
		}
		bool IsSuccess;
		if(AOmegaAbility* LocalAbility=CombatantRef->GetAbility(LocalAbilityClass,IsSuccess))
		{
			IsSuccess=false;
			if(LocalAbility->CanActivate(LocalContext))
			{
				CombatantRef->ExecuteAbility(LocalAbilityClass, LocalContext, IsSuccess);
				LocalAbility->OnAbilityFinished.AddDynamic(this, &UAsyncAction_ActivateAbility::UAsyncAction_ActivateAbility::NativeShutdown);
				return;
			}
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
                                                                            const TSubclassOf<AOmegaAbility> Ability, UObject* Context, bool bForceGrant)
{
	UAsyncAction_ActivateAbility* NewAbility = NewObject<UAsyncAction_ActivateAbility>();

	NewAbility->CombatantRef = Combatant;
	NewAbility->LocalAbilityClass = Ability;
	NewAbility->LocalContext = Context;
	NewAbility->b_autoGrant=bForceGrant;
	return NewAbility;
}
