// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/OmegaSubsystem_QueuedQuery.h"
#include "GameplayTagContainer.h"

bool UOmegaSubsystem_QueuedQuery::CheckQueuedQuery(FGameplayTag Tag, UObject* Context)
{
	for (auto* TempObject : QuerySources)
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

bool UOmegaSubsystem_QueuedQuery::SetQueuedQuerySourceRegistered(UObject* Source, bool bIsRegistered)
{
	if(bIsRegistered)
	{
		if(Source && Source->GetClass()->ImplementsInterface(UInterface_QueuedQuery::StaticClass()))
		{
			QuerySources.AddUnique(Source);
			return true;
		}	
	}
	else if(Source && QuerySources.Contains(Source))
	{
		QuerySources.Remove(Source);
		return true;
	}
	return false;
}

bool UOmegaFunctions_QueueQuery::CheckQueuedQuery(UObject* WorldContextObject, FGameplayTag Tag, UObject* Context)
{
	if(WorldContextObject && WorldContextObject->GetWorld())
	{
		return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSubsystem_QueuedQuery>()->CheckQueuedQuery(Tag,Context);
	}
	return true;
}
