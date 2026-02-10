// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/Subsystem_QueueEvents.h"

#include "GameplayTagContainer.h"


// -------------------------------------------------------------------------------------
// DELAY
// -------------------------------------------------------------------------------------
bool UOmegaSubsystem_QueueEvents::IsTagInQueuedDelay(FGameplayTag Tag)
{
	for (auto* TempObject : sources_delay)
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

bool UOmegaSubsystem_QueueEvents::SetQueuedDelaySourceRegistered(UObject* Source, bool bIsRegistered)
{
	if(bIsRegistered)
	{
		if(Source && Source->GetClass()->ImplementsInterface(UInterface_QueueDelay::StaticClass()))
		{
			sources_delay.AddUnique(Source);
			return true;
		}	
	}
	else if(Source && sources_delay.Contains(Source))
	{
		sources_delay.Remove(Source);
		return true;
	}
	return false;
}

// -------------------------------------------------------------------------------------
// QUERY
// -------------------------------------------------------------------------------------

bool UOmegaSubsystem_QueueEvents::CheckQueuedQuery(FGameplayTag Tag, UObject* Context)
{
	for (auto* TempObject : sources_query)
	{
		if(TempObject &&
			TempObject->GetClass()->ImplementsInterface(UInterface_QueuedQuery::StaticClass()) &&
			!IInterface_QueuedQuery::Execute_GetQueuedQueryValue(TempObject,Tag,Context) )
		{
			UE_LOG(LogTemp, Warning, TEXT("Query returned false from %s"), *TempObject->GetName());
			return false;
		}
	}
	return true;
}

bool UOmegaSubsystem_QueueEvents::SetQueuedQuerySourceRegistered(UObject* Source, bool bIsRegistered)
{
	if(bIsRegistered)
	{
		if(Source && Source->GetClass()->ImplementsInterface(UInterface_QueuedQuery::StaticClass()))
		{
			sources_query.AddUnique(Source);
			return true;
		}	
	}
	else if(Source && sources_query.Contains(Source))
	{
		sources_query.Remove(Source);
		return true;
	}
	return false;
}


// -------------------------------------------------------------------------------------
// SELECTOR
// -------------------------------------------------------------------------------------

UObject* UOmegaSubsystem_QueueEvents::GetQueuedSelectedObject(FGameplayTag Tag, UObject* Fallback,
	TSubclassOf<UObject> Class, bool& Result)
{

	TArray<UObject*> possibles;
	TMap<UObject*,int32> possible_ints;
	
	for(auto* s : sources_selector)
	{
		if(s)
		{
			int32 _pri;
			if(UObject* _obj=IInterface_QueuedSelector::Execute_GetQueuedSelectorObject(s,Tag,_pri))
			{
				if(!Class || _obj->GetClass()->IsChildOf(Class))
				{
					possibles.Add(_obj);
					possible_ints.Add(_obj,_pri);
				}
			}
			
		}
	}

	// Sort in descending order (highest priority first)
	possibles.Sort([&possible_ints](const UObject& A, const UObject& B) {
		int32 PriorityA = possible_ints.FindRef(&A);
		int32 PriorityB = possible_ints.FindRef(&B);
		return PriorityA > PriorityB;
	});
	
	if(possibles.IsValidIndex(0))
	{
		Result=true;
		return possibles[0];
	}
	if(Fallback && (!Class || Fallback->GetClass()->IsChildOf(Class)))
	{
		Result=true;
		return Fallback;
	}
	Result=false;
	return nullptr;	
}

bool UOmegaSubsystem_QueueEvents::SetQueuedSelectorSourceRegistered(UObject* Source, bool bIsRegistered)
{
	if(Source && Source->GetClass()->ImplementsInterface(UInterface_QueuedSelector::StaticClass()))
	{
		if(bIsRegistered && !sources_selector.Contains(Source))
		{
			sources_selector.Add(Source);
			return true;
		}
		if(!bIsRegistered && sources_selector.Contains(Source))
		{
			sources_selector.Remove(Source);
			return true;
		}
	}
	return false;
}


// -------------------------------------------------------------------------------------
// ASYNC AWAIT - DEALY
// -------------------------------------------------------------------------------------

void UAsyncAction_AwaitQueuedDelay::local_TryEnd()
{
	if(!local_WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueueEvents>()->IsTagInQueuedDelay(local_tag))
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
