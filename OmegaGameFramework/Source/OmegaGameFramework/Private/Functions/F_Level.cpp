// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Level.h"

#include "OmegaSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "LevelInstance/LevelInstanceActor.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_GameManager.h"



void UOmegaLevelFunctions::LoadSublevelFromStateParam(UObject* WorldContextObject, FName param, int32 NewValue,
	int32 OldValue)
{
	
	FString subName=OGF_CFG()->SublevelSave_Prefix+param.ToString();
	FString s_new=subName+"_"+FString::FromInt(NewValue);
	if (OldValue>=0)
	{
		FString s_old=subName+"_"+FString::FromInt(OldValue);
		Sublevel_SetLoaded(WorldContextObject,*s_old,false);	
	}
	Sublevel_SetLoaded(WorldContextObject,*s_new,true);
	
}


bool UOmegaLevelFunctions::IsLevelInstance_ReferenceValid(const ALevelInstance* LevelInstance)
{
	if(LevelInstance)
	{
		return LevelInstance->GetWorldAsset().IsValid();
	}
	return false;
}

bool UOmegaLevelFunctions::SetWorldPaused(UObject* WorldContextObject, bool bPaused)
{
	if (WorldContextObject)
	{
		float time_dil=WorldContextObject->GetWorld()->GetWorldSettings()->TimeDilation;
		bool curentlyPaused= (time_dil <= 0.01f);
		if (curentlyPaused!=bPaused)
		{
			float pauseVal=1.0;
			if (bPaused){ pauseVal=0.0; }
			WorldContextObject->GetWorld()->bIsCameraMoveableWhenPaused=false;
			WorldContextObject->GetWorld()->GetWorldSettings()->SetTimeDilation(pauseVal);
			
			return true;
		}
	}
	return false;
}

UWorld* UOmegaLevelFunctions::GetPersistentWorldAsset(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}
	if(UWorld* w=GetPersistentWorldAssetSoft(WorldContextObject).LoadSynchronous())
	{
		return w;
	}
	
	return nullptr;
}

TSoftObjectPtr<UWorld> UOmegaLevelFunctions::GetPersistentWorldAssetSoft(const UObject* WorldContextObject)
{
	if (!WorldContextObject)
	{
		return nullptr;
	}

	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull);
	if (!World)
	{
		return nullptr;
	}

	// Get the streaming level's actual asset reference, not the PIE instance
	FString PackageName = World->PersistentLevel->GetOutermost()->GetName();
    
	// Strip PIE prefix
	PackageName = UWorld::RemovePIEPrefix(PackageName);

	// For UWorld assets, the path format is: /Game/Path/MapName.MapName
	FString AssetName = FPackageName::GetShortName(PackageName);
	FString FullPath = PackageName + TEXT(".") + AssetName;

	return TSoftObjectPtr<UWorld>(FSoftObjectPath(FullPath));
}

FOmegaCustomLevelWrapper UOmegaLevelFunctions::DuplicateCurrentLevelAsCustom(UObject* WorldContextObject, bool& bSuccess)
{
    FOmegaCustomLevelWrapper Wrapper;
    bSuccess = false;

    if (!WorldContextObject) return Wrapper;

    UWorld* World = WorldContextObject->GetWorld();
    if (!World) return Wrapper;

    // Keep original world for actor iteration — no duplication needed
    Wrapper.WorldReference = World;
    Wrapper.WorldName = World->GetName();

    // Generate a unique temp path — this is where the world will live when loaded
    Wrapper.WorldPackagePath = FString::Printf(TEXT("/Temp/CustomLevels/%s_%d"),
        *World->GetName(), FMath::RandRange(0, 99999));

    bSuccess = true;
    return Wrapper;
}
FOmegaCustomLevelWrapper UOmegaLevelFunctions::LoadCustomLevelFromJson(UObject* WorldContextObject, const FString& JsonString, bool& bSuccess)
{
	FOmegaCustomLevelWrapper Wrapper;
	bSuccess = false;

	if (!WorldContextObject) return Wrapper;

	TArray<TSharedPtr<FJsonValue>> ActorArray;
	if (!Wrapper.DeserializeFromJson(JsonString, ActorArray)) return Wrapper;

	// Create a new in-memory package at the deserialized path
	UPackage* NewPackage = CreatePackage(*Wrapper.WorldPackagePath);
	NewPackage->SetFlags(RF_Transient | RF_Public);

	// Create the world and populate it — nothing more
	UWorld* NewWorld = UWorld::CreateWorld(EWorldType::Inactive, false, *Wrapper.WorldName, NewPackage);
	NewWorld->SetFlags(RF_Transient | RF_Public);

	Wrapper.WorldReference = NewWorld;
	bSuccess = Wrapper.SpawnActors(ActorArray);

	return Wrapper;
}

FString UOmegaLevelFunctions::SaveCustomLevelToJson(FOmegaCustomLevelWrapper CustomLevel, FOmegaCustomLevelSaveConfig Config, bool& bSuccess)
{
	FString JsonString;
	bSuccess = CustomLevel.SaveToJson(JsonString, Config);
	return JsonString;
}

bool UOmegaLevelFunctions::OpenCustomLevel(FOmegaCustomLevelWrapper CustomLevel, UObject* WorldContextObject, FName ContainerLevelName)
{
	if (!WorldContextObject || CustomLevel.WorldPackagePath.IsEmpty())
		return false;

	UWorld* CurrentWorld = WorldContextObject->GetWorld();
	if (!CurrentWorld) return false;

	UGameInstance* GI = CurrentWorld->GetGameInstance();
	if (!GI) return false;

	// Stash in subsystem before travel
	GI->GetSubsystem<UOmegaSubsystem_GameInstance>()->CurrentCustomLevel = CustomLevel;
	TSoftObjectPtr<UWorld> _inWorld = CustomLevel.WorldReference;
	
	CurrentWorld->GetTimerManager().SetTimerForNextTick([CurrentWorld, _inWorld]()
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(CurrentWorld, _inWorld, true);
		//UGameplayStatics::OpenLevel(CurrentWorld, ContainerLevelName);
	});

	return true;
}

TArray<FName> UOmegaLevelFunctions::Sublevel_GetAll(UObject* WorldContextObject)
{
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		TArray<FName> SublevelNames;
    
		if (!World)
		{
			return SublevelNames;
		}
    
		const TArray<ULevelStreaming*>& StreamingLevels = World->GetStreamingLevels();
    
		for (const ULevelStreaming* StreamingLevel : StreamingLevels)
		{
			if (StreamingLevel)
			{
				SublevelNames.Add(StreamingLevel->GetWorldAssetPackageFName());
			}
		}
    
		return SublevelNames;
	}
	return TArray<FName>();
}

void UOmegaLevelFunctions::Sublevel_SetLoaded(UObject* WorldContextObject, FName Sublevel, bool bLoaded)
{
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		if (!World)
		{
			return;
		}

		ULevelStreaming* StreamingLevel = UGameplayStatics::GetStreamingLevel(WorldContextObject, Sublevel);
		if (!StreamingLevel)
		{
			return;
		}

		if (bLoaded)
		{
			StreamingLevel->SetShouldBeLoaded(true);
			StreamingLevel->SetShouldBeVisible(true);
		}
		else
		{
			StreamingLevel->SetShouldBeVisible(false);
			StreamingLevel->SetShouldBeLoaded(false);
		}
	}
	
}
