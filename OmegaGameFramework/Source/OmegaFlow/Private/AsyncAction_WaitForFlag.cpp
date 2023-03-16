// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_WaitForFlag.h"

#include "OmegaGameManager.h"


void UAsyncAction_WaitForFlag::Native_OnFlagEvent(FString Flag, bool State)
{
	Local_Finish();
}

void UAsyncAction_WaitForFlag::Local_Finish()
{
	OnFlagValid.Broadcast();
	SetReadyToDestroy();
}

void UAsyncAction_WaitForFlag::Activate()
{
	UOmegaGameManager* SubsystemRef = LocalWorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaGameManager>();
	if(SubsystemRef->IsFlagActive(Local_Flag) == Local_State)
	{
		Local_Finish();
	}
	else
	{
		SubsystemRef->OnFlagStateChange.AddDynamic(this, &UAsyncAction_WaitForFlag::Native_OnFlagEvent);
	}
	
}


UAsyncAction_WaitForFlag* UAsyncAction_WaitForFlag::WaitForFlagState(UObject* WorldContextObject, const FString& Flag, bool bState)
{
	UAsyncAction_WaitForFlag* NewNode = NewObject<UAsyncAction_WaitForFlag>();
	NewNode->Local_Flag = Flag;
	NewNode->Local_State = bState;
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}
