// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Misc/OmegaUtils_Actor.h"



AActor* UOmegaActorUtilFunctions::GetSelectedActor(FOmegaActorSelectorData selectorData)
{
	if(selectorData.Selector)
	{
		if(AActor* out_actor = selectorData.Selector->GetActor())
		{
			return out_actor;
		}
	}
	return nullptr;
}

UWorld* UOmegaActorSelector::GetWorld() const
{
	if(WorldPrivate) {return WorldPrivate; }
	if(GetGameInstance()) { return GetGameInstance()->GetWorld(); } return nullptr;
}

UGameInstance* UOmegaActorSelector::GetGameInstance() const
{
	return Cast<UGameInstance>(GetOuter());
}

UOmegaActorSelector::UOmegaActorSelector(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
}

AActor* UOmegaActorSelector::Private_GetActor(UWorld* WorldContext)
{
	if(WorldContext)
	{
		WorldPrivate=WorldContext;
	}
	return GetActor();
}

