// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_QueueDelay.h"

#include "GameplayTagContainer.h"


bool UOmegaSubsystem_QueueDelay::IsTagInQueuedDelay(FGameplayTag Tag)
{
	for (auto* TempObject : DelaySources)
	{
		if(TempObject &&
			IInterface_QueueDelay::Execute_GetQueuedDelayTags(TempObject).HasTagExact(Tag) &&
			IInterface_QueueDelay::Execute_GetQueuedDelayActive(TempObject))
		{
			return true;
		}
	}
	return false;
}

bool UOmegaSubsystem_QueueDelay::SetQueuedDelaySourceRegistered(UObject* Source, bool bIsRegistered)
{
	if(bIsRegistered)
	{
		if(Source && Source->GetClass()->ImplementsInterface(UInterface_QueueDelay::StaticClass()))
		{
			DelaySources.AddUnique(Source);
			return true;
		}	
	}
	else if(Source && DelaySources.Contains(Source))
	{
		DelaySources.Remove(Source);
		return true;
	}
	return false;
}

void UAsyncAction_AwaitQueuedDelay::local_TryEnd()
{
	if(!local_WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueueDelay>()->IsTagInQueuedDelay(local_tag))
	{
		local_finishing=true;
		Finished.Broadcast();
		SetReadyToDestroy();
	}
}

void UAsyncAction_AwaitQueuedDelay::Tick(float DeltaTime)
{
	if (!local_finishing && local_WorldContext)
	{
		local_TryEnd();
	}
}

void UAsyncAction_AwaitQueuedDelay::Activate()
{
	Super::Activate();
	local_TryEnd();
}

UAsyncAction_AwaitQueuedDelay* UAsyncAction_AwaitQueuedDelay::AwaitQueuedDelay(UObject* WorldContextObject,
	FGameplayTag QueueTag)
{
	UAsyncAction_AwaitQueuedDelay* NewNode = NewObject<UAsyncAction_AwaitQueuedDelay>();
	NewNode->local_WorldContext=WorldContextObject;
	NewNode->local_tag=QueueTag;
	return NewNode;
}
