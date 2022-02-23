// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Save/OmegaSaveSubsystem.h"

#include "OmegaGameManager.h"
#include "Save/OmegaSaveGame.h"
#include "Save/OmegaSaveGlobal.h"
#include "OmegaGameplaySystem.h"
#include "Save/OmegaSaveInterface.h"

#include "Preferences/Asset/GamePreferenceBool.h"
#include "Preferences/Asset/GamePreferenceFloat.h"
#include "OmegaSettings.h"
#include "Gameplay/OmegaGameplayModule.h"

void UOmegaSaveSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	const FString LocalGlSaveName = GetMutableDefault<UOmegaSettings>()->GlobalSaveName;
	const TSubclassOf<UOmegaSaveGlobal> LocalGlobalSaveClass = GetMutableDefault<UOmegaSettings>()->GetOmegaGlobalSaveClass(); //Get Global Settings class

	ActiveSaveData = CreateNewGame();

	if (UGameplayStatics::DoesSaveGameExist(LocalGlSaveName, 0))		//Is there is already a Global Save File?
	{
		GlobalSaveData = Cast<UOmegaSaveGlobal>(UGameplayStatics::LoadGameFromSlot(LocalGlSaveName, 0)); //If yes, load it
	}
	else
	{
		GlobalSaveData = Cast<UOmegaSaveGlobal>(UGameplayStatics::CreateSaveGameObject(LocalGlobalSaveClass)); //If no, create a new one.
	}
}

void UOmegaSaveSubsystem::Deinitialize()
{
	const FString LocalGlSaveName = GetMutableDefault<UOmegaSettings>()->GlobalSaveName;
	UGameplayStatics::SaveGameToSlot(GlobalSaveData, LocalGlSaveName, 0);
}

void UOmegaSaveSubsystem::GetSaveSlotName(int32 Slot, FString& OutName)
{
	FString LocalString = GetMutableDefault<UOmegaSettings>()->SaveGamePrefex;
	LocalString.Append(FString::FromInt(Slot));
	OutName = LocalString;
}

TArray<UOmegaSaveGame*> UOmegaSaveSubsystem::GetSaveSlotList(int32 FirstIndex, int32 LastIndex)
{
	TArray<UOmegaSaveGame*> OutList;
	for (int i = FirstIndex; i <= LastIndex; ++i)
	{
		bool bIsLoaded;
		if(LoadGame(i, bIsLoaded))
		{
			OutList.Add(LoadGame(i, bIsLoaded));
		}
	}
	return OutList;
}

UOmegaSaveGame* UOmegaSaveSubsystem::LoadGame(int32 Slot, bool& Success)
{
	FString SlotName;
	GetSaveSlotName(Slot, SlotName);
	const bool ValidSave = UGameplayStatics::DoesSaveGameExist(SlotName, 0);
	Success = ValidSave;
	
	if (ValidSave == true)
	{
		
		return Cast<UOmegaSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	}
	return nullptr;
}
//ON SAVE
void UOmegaSaveSubsystem::SaveActiveGame(int32 Slot, bool& Success)
{
	FString SlotName;
	GetSaveSlotName(Slot, SlotName);
	UOmegaSaveGame* LocalActiveData = Cast<UOmegaSaveGame>(ActiveSaveData);

	//LocalActiveData->ActiveLevelName = UGameplayStatics::GetCurrentLevelName(this);

	TArray<AActor*> ActorsForSaving;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UOmegaSaveInterface::StaticClass(), ActorsForSaving);
	
	//SaveFileFromActorsWithSaveData
	for(AActor* TempActor : ActorsForSaving)
	{
		IOmegaSaveInterface::Execute_OnGameFileSaved(TempActor, ActiveSaveData);
	}
	//SaveGameplayModuleData
	for(UOmegaGameplayModule* TempModule : GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActiveModules)
	{
		TempModule->GameFileSaved(ActiveSaveData);
	}
	
	if (IsValid(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		LocalActiveData->SavedPlayerTransform = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorTransform();
	}
	
	UGameplayStatics::SaveGameToSlot(LocalActiveData, SlotName, 0);
}

//Create a new Save File Object
UOmegaSaveGame* UOmegaSaveSubsystem::CreateNewGame()
{
	const TSubclassOf<UOmegaSaveGame> LocalSaveClass = GetMutableDefault<UOmegaSettings>()->GetOmegaGameSaveClass(); //Get Save Game Class

	UOmegaSaveGame* CreatedGame = Cast<UOmegaSaveGame>(UGameplayStatics::CreateSaveGameObject(LocalSaveClass)); // Create a new file from that save class
	
	return CreatedGame;
}

void UOmegaSaveSubsystem::StartGame(class UOmegaSaveGame* GameData, FGameplayTagContainer Tags)
{
	if (!GameData)
	{
		return;
	}
	
	ActiveSaveData = GameData;
	ActiveSaveData->OnGameStarted(Tags);
	
	TArray<AActor*> ActorsForSaving;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UOmegaSaveInterface::StaticClass(), ActorsForSaving);
	
	//SaveFileFromActorsWithSaveData
	for(AActor* TempActor : ActorsForSaving)
	{
		IOmegaSaveInterface::Execute_OnGameFileStarted(TempActor, ActiveSaveData);
	}
	
	for(UOmegaGameplayModule* TempModule : GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActiveModules)
	{
		TempModule->GameFileStarted(ActiveSaveData);
	}

}

void UOmegaSaveSubsystem::SetStoryState(FGameplayTag StateTag)
{
	ActiveSaveData->StoryState = StateTag;
}

void UOmegaSaveSubsystem::AddStoryTags(FGameplayTagContainer Tags)
{
	ActiveSaveData->StoryTags.AppendTags(Tags);
}

void UOmegaSaveSubsystem::RemoveStoryTags(FGameplayTagContainer Tags)
{
	ActiveSaveData->StoryTags.RemoveTags(Tags);
}

void UOmegaSaveSubsystem::SetSavedActorState(AActor* Actor, FGameplayTag StateTag)
{

}

void UOmegaSaveSubsystem::AddSavedActorTags(AActor* Actor, FGameplayTagContainer Tags)
{
	
}

void UOmegaSaveSubsystem::RemoveSavedActorTags(AActor* Actor, FGameplayTagContainer Tags)
{
}

