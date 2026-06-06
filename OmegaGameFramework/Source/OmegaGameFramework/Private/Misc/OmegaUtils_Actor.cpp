// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Misc/OmegaUtils_Actor.h"


AActor* UOmegaActorUtilFunctions::GetSelectedActor(UObject* WorldContextObject, FOmegaActorSelectorData selectorData)
{
	if(selectorData.Selector)
	{
		if(AActor* out_actor = selectorData.Selector->Private_GetActor(WorldContextObject->GetWorld()))
		{
			return out_actor;
		}
	}
	return nullptr;
}

TArray<AActor*> UOmegaActorUtilFunctions::GetSelectedActors(UObject* WorldContextObject, FOmegaActorSelectorData selectorData)
{
	return selectorData.Selector->Private_GetActorList(WorldContextObject->GetWorld());
}

AActor* UOmegaActorSelector::Private_GetActor(UWorld* WorldContext)
{
	if(Private_GetActorList(WorldContext).IsValidIndex(0))
	{
		return Private_GetActorList(WorldContext)[0];
	}
	return nullptr;
}

TArray<AActor*> UOmegaActorSelector::Private_GetActorList(UWorld* WorldContext)
{
	if(WorldContext)
	{
		return GetActors(WorldContext);
	}
	TArray<AActor*> nullOut;
	return nullOut;
}

