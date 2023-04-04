// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Zone/OmegaZoneGameInstanceSubsystem.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Zone/OmegaZoneSubsystem.h"

void UOmegaZoneGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &UOmegaZoneGameInstanceSubsystem::OnLevelChanged);
	
}

void UOmegaZoneGameInstanceSubsystem::Deinitialize()
{
	FWorldDelegates::OnPostWorldInitialization.RemoveAll(this);
}

void UOmegaZoneGameInstanceSubsystem::OnLevelChanged(UWorld* World, const UWorld::InitializationValues)
{
	if(IsInlevelTransit)
	{
		IsInlevelTransit=false;
		World->GetSubsystem<UOmegaZoneSubsystem>()->TransitPlayerToPointID(TargetSpawnPointTag, UGameplayStatics::GetPlayerController(this, 0));
	}
}
