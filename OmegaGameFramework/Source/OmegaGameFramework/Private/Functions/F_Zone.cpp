// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Zone.h"

#include "Actors/Actor_Zone.h"
#include "Components/Component_GameplayActor.h"
#include "Functions/F_Common.h"
#include "Kismet/GameplayStatics.h"
#include "Subsystems/Subsystem_World.h"

#define LOC_SUB WorldContextObject->GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetWorldManager()

bool UOmegaFunctions_Zone::ActorInZone(AActor* Actor, UOmegaZoneData* Zone)
{
	if (Actor && Zone)
	{
		if (UActorComponent* comp=Actor->GetComponentByClass(UGameplayActorComponent::StaticClass()))
		{
			if (Cast<UGameplayActorComponent>(comp)->Zone==Zone) { return true;}
		}
	}
	return false;
}

TArray<AActor*> UOmegaFunctions_Zone::FilterActorsInZone(TArray<AActor*> Actors, UOmegaZoneData* Zone)
{
	TArray<AActor*> out;
	for (auto* a : Actors)
	{
		if (ActorInZone(a,Zone))
		{
			out.Add(a);
		}
	}
	return out;
}

UOmegaLevelData* UOmegaFunctions_Zone::Level_GetData(UObject* WorldContextObject,TSoftObjectPtr<UWorld> Level)
{
	if (WorldContextObject && WorldContextObject->GetWorld())
	{
		return LOC_SUB->Zone_GetLevelData(Level);
	}
	return nullptr;
}

TArray<UOmegaLevelData*> UOmegaFunctions_Zone::Level_GetDataList(UObject* WorldContextObject,
	TArray<TSoftObjectPtr<UWorld>> Levels)
{
	TArray<UOmegaLevelData*> out;
	for (TSoftObjectPtr<UWorld> LevelPtr : Levels)
	{
		if (UOmegaLevelData* Level=Level_GetData(WorldContextObject,LevelPtr))
		{
			out.Add(Level);
		}
	}
	
	return out;
}

UOmegaLevelData* UOmegaFunctions_Zone::Level_GetDataCurrent(UObject* WorldContextObject)
{
	if (WorldContextObject && WorldContextObject->GetWorld())
	{
		return LOC_SUB->Zone_GetLevelData_Current();
	}
	return nullptr;
}

UOmegaZoneData* UOmegaFunctions_Zone::Zone_GetCurrentLoaded(UObject* WorldContextObject)
{
	
	if (WorldContextObject && WorldContextObject->GetWorld())
	{
		for (auto* i : LOC_SUB->Zone_GetLoaded())
		{
			if (i)
			{
				return i;
			}
		}
	}
	return nullptr;
}

void UOmegaFunctions_Zone::Transit_ToPoint(UObject* WorldContextObject,AOmegaZonePoint* Point,APlayerController* Player, bool bSkipFade)
{
	if (WorldContextObject && WorldContextObject->GetWorld())
	{
		return LOC_SUB->Zone_Transit(Point,Player,bSkipFade);
	}
}

void UOmegaFunctions_Zone::Transit_ToLevel(UObject* WorldContextObject,TSoftObjectPtr<UWorld> Level,FGameplayTag Tag, bool bSkipFade)
{
	if (WorldContextObject && WorldContextObject->GetWorld())
	{
		return LOC_SUB->Zone_TransitToLevel(Level,Tag,bSkipFade);
	}
}

void UOmegaFunctions_Zone::Transit_ToLevelNamed(UObject* WorldContextObject, FName Level, FGameplayTag Tag, bool bSkipFade)
{
	if (WorldContextObject && WorldContextObject->GetWorld())
	{
		return LOC_SUB->Zone_TransitToLevel_Name(Level,Tag,bSkipFade);
	}
}

AOmegaZonePoint* UOmegaFunctions_Zone::Point_GetFirstOfZone(UObject* WorldContextObject,UOmegaZoneData* Zone)
{
	if (WorldContextObject && Zone)
	{
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(WorldContextObject,AOmegaZonePoint::StaticClass(),Actors);
		for (auto* Actor : Actors)
		{
			if (AOmegaZonePoint* p=Cast<AOmegaZonePoint>(Actor))
			{
				if (p->ZoneToLoad==Zone)
				{
					return p;
				}
			}
		}
			
	}
	return nullptr;
}

bool UOmegaFunctions_Zone::IsLoading(UObject* WorldContextObject)
{
	if (AOmegaWorldManager* m= UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(WorldContextObject))
	{
		return m->Zone_IsLoading();
	}
	return false;
}

#undef LOC_SUB
