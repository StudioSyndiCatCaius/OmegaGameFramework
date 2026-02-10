// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_DemoEffects.h"

#include "Components/Component_TurnBasedManager.h"

bool AGameplayEffect_TurnBased::L_ContextHasValidInterface() const
{
	if(EffectContext && EffectContext->GetClass()->ImplementsInterface(UDataInterface_TurnEntity::StaticClass()))
	{
		return true;
	}
	return false;
}

void AGameplayEffect_TurnBased::L_TurnTrackerUpdated(UTurnTrackerComponent* Component, int32 TurnsElapsed)
{
	if(L_ContextHasValidInterface())
	{
		if(TurnsElapsed>IDataInterface_TurnEntity::Execute_GetTurns_Max(EffectContext))
		{
			K2_DestroyActor();
		}
	}
}

AGameplayEffect_TurnBased::AGameplayEffect_TurnBased()
{
	TurnTracker=CreateOptionalDefaultSubobject<UTurnTrackerComponent>("TurnTracker");

	TurnTracker->OnTurnValueChanged.AddDynamic(this,&AGameplayEffect_TurnBased::L_TurnTrackerUpdated);
}

void AGameplayEffect_TurnBased::BeginPlay()
{
	if(EffectContext)
	{
		TurnTracker->SetSource(EffectContext,true);
	}
}
