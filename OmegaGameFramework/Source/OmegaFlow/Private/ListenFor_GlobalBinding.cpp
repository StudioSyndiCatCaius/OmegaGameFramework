// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_GlobalBinding.h"
#include "Engine/World.h"
#include "Subsystems/Subsystem_World.h"

// ---------------------------------------------------------------------------------------------------------------------
// Named
// ---------------------------------------------------------------------------------------------------------------------

void UListenFor_NameGlobalBinding::Native_OnBound(FName Event, AActor* Actor)
{
	if (LocalWorldContext)
	{
		OnBound.Broadcast(Event,Actor);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_NameGlobalBinding::Native_OnUnbound(FName Event, AActor* Actor)
{
	if (LocalWorldContext)
	{
		OnUnbound.Broadcast(Event,Actor);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_NameGlobalBinding::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		if (UOmegaSubsystem_World* w=LocalWorldContext->GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
		{
			w->OnGlobalNamed_Bound.AddDynamic(this,&UListenFor_NameGlobalBinding::Native_OnBound);
			w->OnGlobalNamed_Unbound.AddDynamic(this,&UListenFor_NameGlobalBinding::Native_OnUnbound);
		}
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_NameGlobalBinding* UListenFor_NameGlobalBinding::ListenFor_NameGlobalBinding(const UObject* WorldContextObject)
{
	UListenFor_NameGlobalBinding* NewNode = NewObject<UListenFor_NameGlobalBinding>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}


// ---------------------------------------------------------------------------------------------------------------------
// Tagged
// ---------------------------------------------------------------------------------------------------------------------

void UListenFor_TagGlobalBinding::Native_OnBound(FGameplayTag Event, AActor* Actor)
{
	if (LocalWorldContext)
	{
		OnBound.Broadcast(Event,Actor);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_TagGlobalBinding::Native_OnUnbound(FGameplayTag Event, AActor* Actor)
{
	if (LocalWorldContext)
	{
		OnUnbound.Broadcast(Event,Actor);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_TagGlobalBinding::Activate()
{
	Super::Activate();
	if (LocalWorldContext)
	{
		if (UOmegaSubsystem_World* w=LocalWorldContext->GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
		{
			w->OnGlobalTagged_Bound.AddDynamic(this,&UListenFor_TagGlobalBinding::Native_OnBound);
			w->OnGlobalTagged_Unbound.AddDynamic(this,&UListenFor_TagGlobalBinding::Native_OnUnbound);
		}
	}
	else
	{
		SetReadyToDestroy();
	}
}

UListenFor_TagGlobalBinding* UListenFor_TagGlobalBinding::ListenFor_TagGlobalBinding(const UObject* WorldContextObject)
{
	UListenFor_TagGlobalBinding* NewNode = NewObject<UListenFor_TagGlobalBinding>();
	NewNode->LocalWorldContext = WorldContextObject;
	return NewNode;
}
