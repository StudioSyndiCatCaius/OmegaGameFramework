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

	//Save Playtime
	//LocalActiveData->SavedPlaytime = GetGameInstance()->GetSubsystem<UOmegaGameManager>()->Playtime;
	
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

UOmegaSaveBase* UOmegaSaveSubsystem::GetSaveObject(bool Global)
{
	if(Global)
	{
		return GlobalSaveData;
	}
	else
	{
		return ActiveSaveData;
	}
}

void UOmegaSaveSubsystem::SetStoryState(FGameplayTag StateTag, bool Global)
{
	GetSaveObject(Global)->StoryState = StateTag;
}

void UOmegaSaveSubsystem::AddStoryTags(FGameplayTagContainer Tags, bool Global)
{
	GetSaveObject(Global)->StoryTags.AppendTags(Tags);
}

void UOmegaSaveSubsystem::RemoveStoryTags(FGameplayTagContainer Tags, bool Global)
{
	GetSaveObject(Global)->StoryTags.RemoveTags(Tags);
}

FGameplayTagContainer UOmegaSaveSubsystem::GetStoryTags(bool Global)
{
	FGameplayTagContainer FinalTags = GetSaveObject(Global)->StoryTags;

	FinalTags.AppendTags(IGameplayTagsInterface::Execute_GetObjectGameplayTags(ActiveSaveData));

	return FinalTags;
	
}

bool UOmegaSaveSubsystem::SaveTagsMatchQuery(FGameplayTagQuery Query, bool Global)
{
	if(Query.IsEmpty())
	{
		return true;
	}
	else
	{
		return Query.Matches(GetStoryTags(Global));
	}
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

void UOmegaSaveSubsystem::AddDataAssetToSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal)
{
	GetSaveObject(bGlobal)->CollectedDataAssets.AddUnique(Asset);
}

void UOmegaSaveSubsystem::RemoveDataAssetFromSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal)
{
	GetSaveObject(bGlobal)->CollectedDataAssets.Remove(Asset);
}

bool UOmegaSaveSubsystem::IsDataAssetInSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal)
{
	return GetSaveObject(bGlobal)->CollectedDataAssets.Contains(Asset);
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetCollectedDataAssets(bool bGlobal)
{
	return GetSaveObject(bGlobal)->CollectedDataAssets;
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetCollectedDataAssetsOfCategory(FGameplayTag CategoryTag, bool bGlobal)
{
	TArray<UPrimaryDataAsset*> OutAssets;

	for(auto* TempAsset : GetSaveObject(bGlobal)->CollectedDataAssets)
	{
		if(TempAsset->Implements<UGameplayTagsInterface>())
		{
			if(IGameplayTagsInterface::Execute_GetObjectGameplayCategory(TempAsset) == CategoryTag)
			{
				OutAssets.Add(TempAsset);
			}
		}
	}

	return OutAssets;
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetCollectedDataAssetsWithTags(FGameplayTagContainer Tags, bool bGlobal,
	bool bExclude, bool bExact)
{
	TArray<UPrimaryDataAsset*> OutAssets;

	for(auto* TempAsset : GetSaveObject(bGlobal)->CollectedDataAssets)
	{
		if(TempAsset->Implements<UGameplayTagsInterface>())
		{
			FGameplayTagContainer TempTags = IGameplayTagsInterface::Execute_GetObjectGameplayTags(TempAsset);
			if(((TempTags.HasAnyExact(Tags) && bExact) || (TempTags.HasAny(Tags) && !bExact)) == !bExclude) 
			{
				OutAssets.Add(TempAsset);
			}
		}
	}
	return OutAssets;
}

//////////////
// Soft Properties
//////////////

void UOmegaSaveSubsystem::SetSoftProperty_Bool(FName Property, bool Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->Prop_bool.Add(Property, Value);
}

bool UOmegaSaveSubsystem::GetSoftProperty_Bool(FName Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->Prop_bool.FindOrAdd(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Float(FName Property, float Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->Prop_float.Add(Property, Value);
}

float UOmegaSaveSubsystem::GetSoftProperty_Float(FName Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->Prop_float.FindOrAdd(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Int32(FName Property, int32 Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->Prop_int.Add(Property, Value);
}

int32 UOmegaSaveSubsystem::GetSoftProperty_Int32(FName Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->Prop_int.FindOrAdd(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_String(FName Property, FString Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->Prop_string.Add(Property, Value);
}

FString UOmegaSaveSubsystem::GetSoftProperty_String(FName Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->Prop_string.FindOrAdd(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Tag(FName Property, FGameplayTag Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->Prop_Tag.Add(Property, Value);
}

FGameplayTag UOmegaSaveSubsystem::GetSoftProperty_Tag(FName Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->Prop_Tag.FindOrAdd(Property);
}

