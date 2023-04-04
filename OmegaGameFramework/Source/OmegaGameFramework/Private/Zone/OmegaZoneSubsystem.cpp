// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Zone/OmegaZoneSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/LevelStreaming.h"
#include "Zone/OmegaZoneGameInstanceSubsystem.h"

void UOmegaZoneSubsystem::LoadZone(UOmegaZoneData* Zone, bool UnloadPreviousZones)
{
	if(Zone)
	{
		IncomingZone_Load = Zone;
		if(GetTopLoadedZones() && UnloadPreviousZones)
		{
			Local_IsWaitForLoad = true;
			UnloadZone(GetTopLoadedZones());
		}
		else
		{
			Local_FinishZoneLoad();
		}
	}
}

void UOmegaZoneSubsystem::UnloadZone(UOmegaZoneData* Zone)
{
	if(Zone)
	{
		IncomingZone_Unload = Zone;
		Local_OnBeginLoadTaskList(IncomingZone_Unload->StreamedLevels, false);
	}
}

TArray<UOmegaZoneData*> UOmegaZoneSubsystem::GetLoadedZones()
{
	return LoadedZones;
}

UOmegaZoneData* UOmegaZoneSubsystem::GetTopLoadedZones()
{
	if(GetLoadedZones().IsValidIndex(0))
	{
		return GetLoadedZones()[0];
	}
	return nullptr;
}

bool UOmegaZoneSubsystem::IsZoneLoaded(UOmegaZoneData* Zone)
{
	if(Zone)
	{
		return GetLoadedZones().Contains(Zone);
	}
	return false;
}

AOmegaZonePoint* UOmegaZoneSubsystem::GetZonePointFromID(FGameplayTag ID)
{
	for(auto* TempPoint : ZonePoints)
	{
		if(TempPoint && (TempPoint->ZonePointID.MatchesTagExact(ID)))
		{
			return TempPoint;
		}
	}
	return nullptr;
}

//#########################################################################################################
// TRANSIT
//#########################################################################################################

void UOmegaZoneSubsystem::TransitPlayerToPointID(FGameplayTag PointID, APlayerController* Player)
{
	TransitPlayerToPoint(GetZonePointFromID(PointID), Player);
}

void UOmegaZoneSubsystem::TransitPlayerToLevel(FSoftObjectPath Level, FGameplayTag SpawnID)
{
	UOmegaZoneGameInstanceSubsystem* InstSubsys = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaZoneGameInstanceSubsystem>();
	InstSubsys->IsInlevelTransit = true;
	InstSubsys->TargetSpawnPointTag = SpawnID;

	const FString StartPath = Level.ToString();
	FString EmptyPath;
	FString targetLevel;
	StartPath.Split(TEXT("."),&EmptyPath,&targetLevel);

	UGameplayStatics::OpenLevel(this, FName(targetLevel));
}

void UOmegaZoneSubsystem::TransitPlayerToPoint(AOmegaZonePoint* Point, APlayerController* Player)
{
	if(Point)
	{
		APlayerController* TargetPlayer = UGameplayStatics::GetPlayerController(this, 0);
		if(Player)
		{
			TargetPlayer = Player;
		}

		if(Point->ZoneToLoad)
		{
			LoadZone(Point->ZoneToLoad);
		}
	}
}


void UOmegaZoneSubsystem::Local_FinishPlayerTransit()
{
	IsMidPlayerTransit=false;
}

//------------------------------------
// ADVANCED
//------------------------------------

void UOmegaZoneSubsystem::Local_FinishZoneLoad()
{
	Local_IsWaitForLoad = false;
	Local_OnBeginLoadTaskList(IncomingZone_Load->StreamedLevels, false);
}

void UOmegaZoneSubsystem::Local_OnBeginLoadTaskList(TArray<FName> Levels, bool Loaded)
{
	Incoming_LoadList = Levels;
	Incoming_LoadState = Loaded;
	Local_OnNextLoadEvent();
	
}

void UOmegaZoneSubsystem::Local_OnNextLoadEvent()
{
	FName Local_Name;
	//End if List is empty
	if(Incoming_LoadList.IsValidIndex(0))
	{
		Local_Name = Incoming_LoadList[0];
	}
	else
	{
		Local_OnFinishLoadTask(Incoming_LoadState);
		return;
	}

	// Setup Latant action
	FLatentActionInfo Local_LatentLoad;
	Local_LatentLoad.CallbackTarget = this;
	Local_LatentLoad.ExecutionFunction = FName("Local_OnNextLoadEvent");
	Local_LatentLoad.Linkage = 0;
	
	if(Incoming_LoadState)
	{
		UGameplayStatics::LoadStreamLevel(this, Local_Name, true, false, Local_LatentLoad);
	}
	else
	{
		UGameplayStatics::UnloadStreamLevel(this, Local_Name, FLatentActionInfo(), true);
	}
}

void UOmegaZoneSubsystem::Local_OnFinishLoadTask(bool LoadState)
{
	if(LoadState)
	{
		OnZoneLoaded.Broadcast(Incoming_LoadTaskZone);
	}
	else
	{
		OnZoneUnloaded.Broadcast(Incoming_LoadTaskZone);
	}

	if(Local_IsWaitForLoad)
	{
		Local_FinishZoneLoad();
	}
}



