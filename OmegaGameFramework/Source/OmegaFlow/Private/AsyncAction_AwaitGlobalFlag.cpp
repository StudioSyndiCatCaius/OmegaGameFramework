// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_AwaitGlobalFlag.h"


#include "Functions/F_Common.h"
#include "Functions/F_GlobalParam.h"
#include "Subsystems/Subsystem_GameManager.h"

void UAsyncAction_AwaitGlobalFlag::Tick(float DeltaTime)
{
	if (!b_killing && WC)
	{
		if (UOmegaFunctions_GlobalVars::Bitflag_HasAny(WC,var_target,target_flag)==target_state)
		{
			b_killing=true;
			Finished.Broadcast();
			SetReadyToDestroy();
		}
	}
}

UAsyncAction_AwaitGlobalFlag* UAsyncAction_AwaitGlobalFlag::AwaitGlobalFlag(UObject* WorldContextObject,
                                                                            FGameplayTag Flag, TEnumAsByte<EOmegaGlobalParamTarget> Target, bool bDesiredState)
{
	if (!WorldContextObject || !Flag.IsValid()) { return nullptr; }
	if (UAsyncAction_AwaitGlobalFlag* newNode = NewObject<UAsyncAction_AwaitGlobalFlag>())
	{
		newNode->WC=WorldContextObject;
		newNode->var_target=Target;
		newNode->target_flag=Flag;
		newNode->target_state=bDesiredState;
		return newNode;
	}
	return nullptr;
}
