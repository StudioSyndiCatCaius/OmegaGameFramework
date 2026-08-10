// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_TurnManager.h"

#include "Components/Component_Combatant.h"
#include "Components/Component_TurnBasedManager.h"

void UListenFor_TurnManager::L_OnTurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant)
{
	if (IsValid(TurnManager))
	{
		TurnStart.Broadcast(Component, Combatant, TEXT(""));
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_TurnManager::L_OnTurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant)
{
	if (IsValid(TurnManager))
	{
		TurnEnd.Broadcast(Component, Combatant, TEXT(""));
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_TurnManager::L_OnTurnFail(FString Reason)
{
	if (IsValid(TurnManager))
	{
		TurnFail.Broadcast(TurnManager, nullptr, Reason);
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_TurnManager::L_OnTurnOrderGenerated(UTurnBasedManagerComponent* Component)
{
	if (IsValid(TurnManager))
	{
		TurnOrderGenerated.Broadcast(Component, nullptr, TEXT(""));
	}
	else
	{
		SetReadyToDestroy();
	}
}

void UListenFor_TurnManager::Activate()
{
	Super::Activate();

	if (!IsValid(TurnManager))
	{
		SetReadyToDestroy();
		return;
	}

	// Keep this listener alive after the calling Blueprint function returns.
	// Without this, GC can reclaim the node before later turn events (e.g. TurnOrderGenerated) fire.
	RegisterWithGameInstance(TurnManager);

	TurnManager->OnTurnStart.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnStart);
	TurnManager->OnTurnEnd.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnEnd);
	TurnManager->OnTurnFail.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnFail);
	TurnManager->OnTurnOrderGenerated.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnOrderGenerated);
}

void UListenFor_TurnManager::SetReadyToDestroy()
{
	if (IsValid(TurnManager))
	{
		TurnManager->OnTurnStart.RemoveDynamic(this, &UListenFor_TurnManager::L_OnTurnStart);
		TurnManager->OnTurnEnd.RemoveDynamic(this, &UListenFor_TurnManager::L_OnTurnEnd);
		TurnManager->OnTurnFail.RemoveDynamic(this, &UListenFor_TurnManager::L_OnTurnFail);
		TurnManager->OnTurnOrderGenerated.RemoveDynamic(this, &UListenFor_TurnManager::L_OnTurnOrderGenerated);
	}

	TurnManager = nullptr;
	Super::SetReadyToDestroy();
}

UListenFor_TurnManager* UListenFor_TurnManager::ListenFor_TurnManager(UTurnBasedManagerComponent* Component)
{
	// Always return a node so the latent Blueprint pin graph stays valid; Activate handles a bad Component.
	UListenFor_TurnManager* NewNode = NewObject<UListenFor_TurnManager>();
	NewNode->TurnManager = Component;
	return NewNode;
}
