// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Save/OmegaSaveSubsystem.h"

#include "OmegaGameManager.h"
#include "Save/OmegaSaveGame.h"
#include "Save/OmegaSaveGlobal.h"
#include "OmegaGameplaySystem.h"
#include "Save/OmegaSaveInterface.h"
#include "Dom/JsonObject.h"

#include "Preferences/Asset/GamePreferenceBool.h"
#include "Preferences/Asset/GamePreferenceFloat.h"
#include "OmegaSettings.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "Kismet/KismetMathLibrary.h"
#include "Preferences/GamePreferenceSubsystem.h"
#include "Save/OmegaSaveCondition.h"


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
	SaveGlobalGame();
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
	
	if (ValidSave)
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
	//UOmegaSaveGame* LocalActiveData = Cast<UOmegaSaveGame>(ActiveSaveData);
	
	
	
	Success = Local_SaveGame(SlotName);
}


bool UOmegaSaveSubsystem::SaveGameUnique(EUniqueSaveFormats Format)
{
	FString LocalSaveName;
	
	switch (Format) {
	case EUniqueSaveFormats::SaveFormat_Quicksave:
		LocalSaveName = "quicksave";
		break;
	case EUniqueSaveFormats::SaveFormat_Autosave:
		LocalSaveName = "autosave";
		break;
	default: ;
	}

	return Local_SaveGame(LocalSaveName);
}

bool UOmegaSaveSubsystem::Local_SaveGame(FString SlotName)
{
	//LocalActiveData->ActiveLevelName = UGameplayStatics::GetCurrentLevelName(this);

	TArray<AActor*> ActorsForSaving;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UOmegaSaveInterface::StaticClass(), ActorsForSaving);

	//Save Json Sources
	for(auto* TempSource : GetSaveSources())
	{
		SaveObjectJsonData(TempSource);
	}
	//SaveFileFromActorsWithSaveData
	for(AActor* TempActor : ActorsForSaving)
	{
		IOmegaSaveInterface::Execute_OnGameFileSaved(TempActor, ActiveSaveData);
		SaveObjectJsonData(TempActor);
	}
	//SaveGameplayModuleData
	for(UOmegaGameplayModule* TempModule : GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActiveModules)
	{
		TempModule->GameFileSaved(ActiveSaveData);
	}
	
	if (IsValid(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		ActiveSaveData->SavedPlayerTransform = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorTransform();
	}

	//SaveDate
	ActiveSaveData->SaveDate = UKismetMathLibrary::Now();
	
	//Save Playtime
	//LocalActiveData->SavedPlaytime = GetGameInstance()->GetSubsystem<UOmegaGameManager>()->Playtime;
	
	return UGameplayStatics::SaveGameToSlot(ActiveSaveData, SlotName, 0);
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

	//Load Json Data
	for(auto* TempSource : GetSaveSources())
	{
		LoadObjectJsonData(TempSource);
	}
	//SaveFileFromActorsWithSaveData
	for(AActor* TempActor : ActorsForSaving)
	{
		IOmegaSaveInterface::Execute_OnGameFileStarted(TempActor, ActiveSaveData);
		LoadObjectJsonData(TempActor);
	}
	
	for(UOmegaGameplayModule* TempModule : GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActiveModules)
	{
		TempModule->GameFileStarted(ActiveSaveData, Tags);
	}
	
	//GetGameInstance()->GetSubsystem<UGamePreferenceSubsystem>()->Local_PreferenceUpdateAll();
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

void UOmegaSaveSubsystem::SaveGlobalGame()
{
	const FString LocalGlSaveName = GetMutableDefault<UOmegaSettings>()->GlobalSaveName;
	UGameplayStatics::SaveGameToSlot(GlobalSaveData, LocalGlSaveName, 0);
}

void UOmegaSaveSubsystem::SetStoryState(FGameplayTag StateTag, bool Global)
{
	GetSaveObject(Global)->StoryState = StateTag;
}

FGameplayTag UOmegaSaveSubsystem::GetSaveState(bool Global)
{
	return GetSaveObject(Global)->StoryState;
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

void UOmegaSaveSubsystem::SetDataAssetCollected(UPrimaryDataAsset* Asset, bool bGlobal, bool Collected)
{
	if(Collected)
	{
		AddDataAssetToSaveCollection(Asset, bGlobal);
	}
	else
	{
		RemoveDataAssetFromSaveCollection(Asset, bGlobal);
	}
}

void UOmegaSaveSubsystem::SetDataAssetsCollected(TArray<UPrimaryDataAsset*> Assets, bool bGlobal, bool Collected)
{
	for (auto* TempAsset: Assets)
	{
		if(TempAsset)
		{
			SetDataAssetCollected(TempAsset, bGlobal, Collected);
		}
	}
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

void UOmegaSaveSubsystem::SetSoftProperty_Bool(const FString& Property, bool Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Bool(Property, Value);
}

bool UOmegaSaveSubsystem::GetSoftProperty_Bool(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Bool(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Float(const FString& Property, float Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Float(Property, Value);
}

float UOmegaSaveSubsystem::GetSoftProperty_Float(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Float(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Int32(const FString& Property, int32 Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Int(Property, Value);
}

int32 UOmegaSaveSubsystem::GetSoftProperty_Int32(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Int(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_String(const FString& Property, FString Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_String(Property, Value);
}

FString UOmegaSaveSubsystem::GetSoftProperty_String(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_String(Property);;
}

void UOmegaSaveSubsystem::SetSoftProperty_Tag(const FString& Property, FGameplayTag Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Tag(Property, Value);
}

FGameplayTag UOmegaSaveSubsystem::GetSoftProperty_Tag(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Tag(Property);;
}

void UOmegaSaveSubsystem::SetSoftProperty_Vector(const FString& Property, FVector Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Vector(Property, Value);
}

FVector UOmegaSaveSubsystem::GetSoftProperty_Vector(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Vector(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Rotator(const FString& Property, FRotator Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Rotator(Property, Value);
}

FRotator UOmegaSaveSubsystem::GetSoftProperty_Rotator(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Rotator(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_Transform(const FString& Property, FTransform Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Transform(Property, Value);
}

FTransform UOmegaSaveSubsystem::GetSoftProperty_Transform(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Transform(Property);
}

void UOmegaSaveSubsystem::SetSoftProperty_DataAsset(const FString& Property, UPrimaryDataAsset* Value, bool bGlobal)
{
	GetSaveObject(bGlobal)->SetSaveProperty_Asset(Property, Value);
}

UPrimaryDataAsset* UOmegaSaveSubsystem::GetSoftProperty_DataAsset(const FString& Property, bool bGlobal)
{
	return GetSaveObject(bGlobal)->GetSaveProperty_Asset(Property);
}

bool UOmegaSaveSubsystem::CustomSaveConditionsMet(FOmegaSaveConditions Conditions)
{
	TArray<UOmegaSaveCondition*> LocalConditionList = Conditions.Conditions;

	for(const auto* TempCol : Conditions.ConditionCollections)
	{
		LocalConditionList.Append(TempCol->Conditions);
	}
	
	for(const UOmegaSaveCondition* TempCondition : LocalConditionList)
	{
		if(TempCondition)
		{
			TempCondition->WorldPrivate = GetWorld();
		}
	}
	
	if(Conditions.CheckType == EBoolType::BoolType_And)
	{
		for(const UOmegaSaveCondition* TempCondition : LocalConditionList)
		{
			if(!TempCondition || !TempCondition->CheckSaveCondition(this))
			{
				return false;
			}
		}
	}
	else
	{
		for(const UOmegaSaveCondition* TempCondition : LocalConditionList)
		{
			if(TempCondition && TempCondition->CheckSaveCondition(this))
			{
				return true;
			}
			return false;
		}
	}
	
	return true;
}

void UOmegaSaveSubsystem::SaveObjectJsonData(UObject* Object)
{
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()))
	{
		if(IOmegaSaveInterface::Execute_UseJsonSaveData(Object))
		{
			const FString LocalPropName = IOmegaSaveInterface::Execute_GetJsonPropertyName(Object);
			const FJsonObjectWrapper LocalJsonData = IOmegaSaveInterface::Execute_SaveJsonData(Object);
			GetSaveObject(false)->SetSaveProperty_Json(LocalPropName, LocalJsonData);
		}
	}
}

void UOmegaSaveSubsystem::LoadObjectJsonData(UObject* Object)
{
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()))
	{
		if(IOmegaSaveInterface::Execute_UseJsonSaveData(Object))
		{
			const FString LocalPropName = IOmegaSaveInterface::Execute_GetJsonPropertyName(Object);
			const FJsonObjectWrapper LocalJsonData = GetSaveObject(false)->GetSaveProperty_Json(LocalPropName);
			IOmegaSaveInterface::Execute_LoadJsonData(Object, LocalJsonData);
			
		}
	}
}

void UOmegaSaveSubsystem::SetSaveSourceRegistered(UObject* Source, bool Registered)
{
	if(Source && Source->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()))
	{
		JsonSaveSources.Add(Source);
	}
}

TArray<UObject*> UOmegaSaveSubsystem::GetSaveSources()
{
	TArray<UObject*> OutSources;
	for(auto* TempSource : JsonSaveSources)
	{
		if(TempSource)
		{
			OutSources.Add(TempSource);
		}
	}
	return OutSources;
}

