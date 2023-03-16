// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Components/ActorStateComponent.h"

#include "Save/OmegaSaveGame.h"
#include "Save/OmegaSaveSubsystem.h"

void UActorStateComponent::BeginPlay()
{
	SubsysRef = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();

	if(!SubsysRef->ActiveSaveData->ActorStates.Contains(GetOwner()))
	{
		SetActorState(DefaultState);
	}

	OnBeginWithState.Broadcast(GetActorState());
	
	Super::BeginPlay();
}

void UActorStateComponent::SetActorState(FGameplayTag State)
{
	SubsysRef->ActiveSaveData->ActorStates.Add(GetOwner(), State);
}

FGameplayTag UActorStateComponent::GetActorState() const
{
	return SubsysRef->ActiveSaveData->ActorStates.FindOrAdd(GetOwner());
}
