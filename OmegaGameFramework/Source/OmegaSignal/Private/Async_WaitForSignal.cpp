// Fill out your copyright notice in the Description page of Project Settings.

#include "Async_WaitForSignal.h"

#include "OmegaSignalSubsystem.h"

UAsync_WaitForSignal* UAsync_WaitForSignal::WaitForSignal
(const UObject* WorldContextObject, UOmegaSignalAsset* Signal)
{
	UAsync_WaitForSignal* NewSysNode = NewObject<UAsync_WaitForSignal>();
	
	if(Signal)
	{
		NewSysNode->LocalSignal = Signal;
	}
	
	NewSysNode->Local_WorldContext = WorldContextObject;
	
	return NewSysNode;
}



void UAsync_WaitForSignal::Local_OnSignal(UOmegaSignalAsset* LocalSig)
{
	if(LocalSignal == LocalSig)
	{
		OnSignal.Broadcast();
		SetReadyToDestroy();
	}
	
}

void UAsync_WaitForSignal::Activate()
{
	if(LocalSignal)
	{
		if(Local_WorldContext->GetWorld())
		{
			UOmegaSignalSubsystem* SubSysRef = Local_WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSignalSubsystem>();
			SubSysRef->OnFireSignal.AddDynamic(this, &UAsync_WaitForSignal::Local_OnSignal);
		}
	}
	else
	{
		SetReadyToDestroy();
	}
	
}
