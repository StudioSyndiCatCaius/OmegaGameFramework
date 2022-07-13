// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaLinearEvent.h"

UOmegaLinearEvent::UOmegaLinearEvent(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter())
	{
		WorldPrivate = Owner->GetWorld();
	}
}

UWorld* UOmegaLinearEvent::GetWorld() const
{
	if(GetGameInstance())
	{
		return GetGameInstance()->GetWorld();
	}
	return nullptr;
}

UGameInstance* UOmegaLinearEvent::GetGameInstance() const
{
	return GameInstanceRef;
}

void UOmegaLinearEvent::Finish()
{
	OnEventEnd();
	EventEnded.Broadcast();
	
}
