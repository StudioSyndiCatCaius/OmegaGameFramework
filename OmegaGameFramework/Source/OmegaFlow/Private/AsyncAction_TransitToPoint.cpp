// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_TransitToPoint.h"

#include "Actors/Actor_Zone.h"
#include "Subsystems/Subsystem_World.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

UAsyncAction_TransitToPoint* UAsyncAction_TransitToPoint::AsyncTransitToPoint(UObject* WorldContextObject,
	AOmegaZonePoint* Point, APlayerController* Player)
{
	// Default to the first player if none was supplied.
	if (!Player && WorldContextObject)
	{
		Player = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	}

	UAsyncAction_TransitToPoint* NewAction = NewObject<UAsyncAction_TransitToPoint>();
	NewAction->WorldContextObject = WorldContextObject;
	NewAction->Point = Point;
	NewAction->Player = Player;
	return NewAction;
}

void UAsyncAction_TransitToPoint::Activate()
{
	UWorld* World = WorldContextObject ? WorldContextObject->GetWorld() : nullptr;
	UOmegaSubsystem_World* Subsystem = World ? World->GetSubsystem<UOmegaSubsystem_World>() : nullptr;

	if (!Point || !Subsystem)
	{
		Failed.Broadcast();
		SetReadyToDestroy();
		return;
	}

	AOmegaWorldManager* WorldManager = Subsystem->GetWorldManager();
	if (!WorldManager)
	{
		Failed.Broadcast();
		SetReadyToDestroy();
		return;
	}

	// Listen for the spawn-at-point event so we know when the transit is finished.
	Subsystem->OnZone_PlayerSpawnAtPoint.AddDynamic(this, &UAsyncAction_TransitToPoint::OnPlayerSpawnedAtPoint);

	WorldManager->Zone_Transit(Point, Player);
}

void UAsyncAction_TransitToPoint::OnPlayerSpawnedAtPoint(APlayerController* SpawnedPlayer, AOmegaZonePoint* SpawnedPoint)
{
	// Only respond to the transit we started.
	if (SpawnedPoint != Point)
	{
		return;
	}

	UWorld* World = WorldContextObject ? WorldContextObject->GetWorld() : nullptr;
	if (UOmegaSubsystem_World* Subsystem = World ? World->GetSubsystem<UOmegaSubsystem_World>() : nullptr)
	{
		Subsystem->OnZone_PlayerSpawnAtPoint.RemoveDynamic(this, &UAsyncAction_TransitToPoint::OnPlayerSpawnedAtPoint);
	}

	Finished.Broadcast();
	SetReadyToDestroy();
}
