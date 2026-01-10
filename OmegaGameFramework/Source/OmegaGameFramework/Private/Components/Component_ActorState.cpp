// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorState.h"
#include "Subsystems/Subsystem_Save.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"


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
