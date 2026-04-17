// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenFor_TurnManager.h"

#include "Components/Component_Combatant.h"
#include "Components/Component_TurnBasedManager.h"

void UListenFor_TurnManager::L_OnTurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant)
{
	TurnStart.Broadcast(Component,Combatant,"");
}

void UListenFor_TurnManager::L_OnTurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant)
{
	TurnEnd.Broadcast(Component,Combatant,"");
}

void UListenFor_TurnManager::L_OnTurnFail(FString Reason)
{
	TurnFail.Broadcast(TurnManager,nullptr,Reason);
}

void UListenFor_TurnManager::L_OnTurnOrderGenerated(UTurnBasedManagerComponent* Component)
{
	TurnOrderGenerated.Broadcast(Component,nullptr,"");
}

void UListenFor_TurnManager::Activate()
{
	Super::Activate();
	TurnManager->OnTurnStart.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnStart);
	TurnManager->OnTurnEnd.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnEnd);
	TurnManager->OnTurnFail.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnFail);
	TurnManager->OnTurnOrderGenerated.AddDynamic(this, &UListenFor_TurnManager::L_OnTurnOrderGenerated);
}

UListenFor_TurnManager* UListenFor_TurnManager::ListenFor_TurnManager(UTurnBasedManagerComponent* Component)
{
	if (!Component) { return nullptr; }
	if (UListenFor_TurnManager* newNode=NewObject<UListenFor_TurnManager>())
	{
		newNode->TurnManager = Component;
		return newNode;
	}
	return nullptr;
}
