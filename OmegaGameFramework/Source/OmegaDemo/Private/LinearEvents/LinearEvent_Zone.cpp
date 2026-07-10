// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_Zone.h"

#include "Actors/Actor_Zone.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

void ULinearEvent_AwaitZone::L_OnSpawn(APlayerController* Player, AOmegaZonePoint* Point)
{
	if (Point)
	{
		if (bAwaitSpecificPoint && Point==_Point.LoadSynchronous())
		{
			Finish("");
		}
		else if (!bAwaitSpecificPoint && Point->ZoneToLoad==Zone)
		{
			Finish("");
		}
	}
	
}

void ULinearEvent_AwaitZone::Native_Begin(const FString& Flag)
{
	Super::Native_Begin(Flag);
	if (UOmegaSubsystem_World* ss=OGF_Subsystems::oWorld(this))
	{
		ss->OnZone_PlayerSpawnAtPoint.AddDynamic(this, &ULinearEvent_AwaitZone::L_OnSpawn);
	}
	
}

void ULinearEvent_AwaitZone::OnEventEnd_Implementation(const FString& Flag)
{
	if (UOmegaSubsystem_World* ss=OGF_Subsystems::oWorld(this))
	{
		ss->OnZone_PlayerSpawnAtPoint.RemoveDynamic(this, &ULinearEvent_AwaitZone::L_OnSpawn);
	}
	Super::OnEventEnd_Implementation(Flag);
}
