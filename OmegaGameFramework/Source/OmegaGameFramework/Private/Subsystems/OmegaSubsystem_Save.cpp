// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_Save.h"

#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Subsystems/OmegaSubsystem_Zone.h"

#include "UnrealClient.h"
#include "TimerManager.h"
#include "Dom/JsonObject.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectWrapper.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "Functions/OmegaFunctions_Common.h"
#include "Engine/EngineTypes.h"
#include "OmegaSettings.h"
#include "Misc/OmegaGameplayModule.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"

// ====================================================================================================
// Initialize
// ====================================================================================================

void UOmegaSaveSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	Local_InitializeSaveObjects();

	//Setup play timer
	FTimerHandle GameTimeHandle;
	GetWorld()->GetTimerManager().SetTimer(GameTimeHandle, this, &UOmegaSaveSubsystem::OnPlaytimeUpdate, 0.001f, true);
}

void UOmegaSaveSubsystem::OnPlaytimeUpdate()
{
	ActiveSaveData->Playtime += FTimespan::FromMilliseconds(1);
	GlobalSaveData->Playtime += FTimespan::FromMilliseconds(1);
}

FTimespan UOmegaSaveSubsystem::GetSavePlaytime(bool bGlobal)
{
	return GetSaveObject(bGlobal)->Playtime;
}

FString UOmegaSaveSubsystem::GetSavePlaytimeString(bool bGlobal, bool bIncludeMilliseconds)
{
	return GetSaveObject(bGlobal)->GetPlaytimeString(bIncludeMilliseconds);
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
	return LoadGame_Named(SlotName,Success);
}

UOmegaSaveGame* UOmegaSaveSubsystem::LoadGame_Named(FString Slot, bool& Success)
{
	const bool ValidSave = UGameplayStatics::DoesSaveGameExist(Slot, 0);
	Success = ValidSave;
	
	if (ValidSave)
	{
		UOmegaSaveGame* LocalGameSave = Cast<UOmegaSaveGame>(UGameplayStatics::LoadGameFromSlot(Slot, 0));
		LocalGameSave->SaveScreenshot = UKismetRenderingLibrary::ImportFileAsTexture2D(this, Local_GetScreenshotPath(Slot));
		return LocalGameSave;
	}
	
	return nullptr;
}


//ON SAVE
void UOmegaSaveSubsystem::SaveActiveGame(int32 Slot, FGameplayTag SaveCategory, bool& Success)
{
	FString SlotName;
	GetSaveSlotName(Slot, SlotName);
	Success = Local_SaveGame(SlotName,SaveCategory);
}

void UOmegaSaveSubsystem::SaveActiveGame_Named(FString Slot, FGameplayTag SaveCategory, bool& Success)
{
	Success = Local_SaveGame(Slot,SaveCategory);
}


bool UOmegaSaveSubsystem::SaveGameUnique(EUniqueSaveFormats Format)
{
	return false;
}



bool UOmegaSaveSubsystem::Local_SaveGame(FString SlotName,FGameplayTag SaveCategory)
{
	//LocalActiveData->ActiveLevelName = UGameplayStatics::GetCurrentLevelName(this);

	TArray<AActor*> ActorsForSaving;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UOmegaSaveInterface::StaticClass(), ActorsForSaving);
	
	//Save Json Sources
	for(auto* TempSource : GetSaveSources())
	{
		SaveObjectJsonData(TempSource,false);
	}
	//SaveFileFromActorsWithSaveData
	for(AActor* TempActor : ActorsForSaving)
	{
		IOmegaSaveInterface::Execute_OnGameFileSaved(TempActor, ActiveSaveData);
		SaveObjectJsonData(TempActor,false);
	}
	//SaveGameplayModuleData
	for(UOmegaGameplayModule* TempModule : GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActiveModules)
	{
		TempModule->GameFileSaved(ActiveSaveData);
	}
	//Save Lua Data
	// local_SaveLuaFields(GetMutableDefault<UOmegaSettings>()->LuaFields_AutoSavedToGame,GetSaveObject(false));
	
	if (IsValid(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		ActiveSaveData->SavedPlayerTransform = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorTransform();
	}
	ActiveSaveData->ActiveZone = GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->GetTopLoadedZones();
	ActiveSaveData->ActiveLevelName = UGameplayStatics::GetCurrentLevelName(this);

	//SaveDate
	ActiveSaveData->SaveDate = UKismetMathLibrary::Now();
	ActiveSaveData->SaveCategory=SaveCategory;
	
	//Save Playtime
	//LocalActiveData->SavedPlaytime = GetGameInstance()->GetSubsystem<UOmegaGameManager>()->Playtime;

	const FString fileName = Local_GetScreenshotPath(SlotName);
	FScreenshotRequest::RequestScreenshot(fileName, false, false);
	
	return UGameplayStatics::SaveGameToSlot(ActiveSaveData, SlotName, 0);
}


//Create a new Save File Object
UOmegaSaveGame* UOmegaSaveSubsystem::CreateNewGame()
{
	const TSubclassOf<UOmegaSaveGame> LocalSaveClass = GetMutableDefault<UOmegaSettings>()->GetOmegaGameSaveClass(); //Get Save Game Class

	UOmegaSaveGame* CreatedGame = Cast<UOmegaSaveGame>(UGameplayStatics::CreateSaveGameObject(LocalSaveClass)); // Create a new file from that save class
	CreatedGame->SaveGuid=FGuid::NewGuid();
	CreatedGame->SaveSeed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
	return CreatedGame;
}

void UOmegaSaveSubsystem::StartGame(class UOmegaSaveGame* GameData, bool LoadSavedLevel, FGameplayTagContainer Tags)
{
	if (!GameData) { return; }
	
	ActiveSaveData = GameData;
	ActiveSaveData->OnGameStarted(Tags);
	
	TArray<AActor*> ActorsForSaving;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UOmegaSaveInterface::StaticClass(), ActorsForSaving);

	//Load Json Data
	for(auto* TempSource : GetSaveSources())
	{
		LoadObjectJsonData(TempSource,false);
	}
	//SaveFileFromActorsWithSaveData
	for(AActor* TempActor : ActorsForSaving)
	{
		IOmegaSaveInterface::Execute_OnGameFileStarted(TempActor, ActiveSaveData);
		LoadObjectJsonData(TempActor,false);
	}
	
	for(UOmegaGameplayModule* TempModule : GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActiveModules)
	{
		TempModule->GameFileStarted(ActiveSaveData, Tags);
	}

	//LASTLY, Try and load saved level if chosen
	if(LoadSavedLevel)
	{
		const FGameplayTag EmptyPoint;
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaZoneGameInstanceSubsystem>()->bIsLoadingGame=true;
		GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->TransitPlayerToLevel_Name(*ActiveSaveData->ActiveLevelName,EmptyPoint);
	}
	OnNewGameStarted.Broadcast(GameData,Tags);
	//GetGameInstance()->GetSubsystem<UGamePreferenceSubsystem>()->Local_PreferenceUpdateAll();
}

void UOmegaSaveSubsystem::Local_InitializeSaveObjects()
{
	if(!GlobalSaveData)
	{
		const FString LocalGlSaveName = GetMutableDefault<UOmegaSettings>()->GlobalSaveName;
		const TSubclassOf<UOmegaSaveGlobal> LocalGlobalSaveClass = GetMutableDefault<UOmegaSettings>()->GetOmegaGlobalSaveClass(); //Get Global Settings class
		
		if (UGameplayStatics::DoesSaveGameExist(LocalGlSaveName, 0))		//Is there is already a Global Save File?
		{
			GlobalSaveData = Cast<UOmegaSaveGlobal>(UGameplayStatics::LoadGameFromSlot(LocalGlSaveName, 0)); //If yes, load it
		}
		else
		{
			GlobalSaveData = Cast<UOmegaSaveGlobal>(UGameplayStatics::CreateSaveGameObject(LocalGlobalSaveClass)); //If no, create a new one.
			GlobalSaveData->SaveGuid=FGuid::NewGuid();
			GlobalSaveData->SaveSeed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
		}
		
	}
	if(!ActiveSaveData)
	{
		ActiveSaveData = CreateNewGame();
	}
}

void UOmegaSaveSubsystem::local_SaveLuaFields(TArray<FString> fields, UOmegaSaveBase* save)
{
	for(FString temp_field: fields)
	{
		const FLuaValue lua_data = ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,GetMutableDefault<ULuaSettings>()->DefaultState.LoadSynchronous(), temp_field);
		FJsonObjectWrapper new_json;
		new_json.JsonObjectFromString(ULuaBlueprintFunctionLibrary::LuaValueToJson(lua_data));
		save->SetSaveProperty_Json(temp_field,new_json);
	}
}

void UOmegaSaveSubsystem::local_LoadLuaFields(TArray<FString> fields, UOmegaSaveBase* save)
{
	for(FString temp_field: fields)
	{
		TSubclassOf<ULuaState> lua_state = GetMutableDefault<ULuaSettings>()->DefaultState.LoadSynchronous();
		FString json_string;
		save->GetSaveProperty_Json(temp_field).JsonObjectToString(json_string);
		FLuaValue lua_data;
		ULuaBlueprintFunctionLibrary::LuaValueFromJson(this, lua_state, json_string,lua_data);
		ULuaBlueprintFunctionLibrary::LuaSetGlobal(this,lua_state,temp_field,lua_data);
	}
}

UOmegaSaveBase* UOmegaSaveSubsystem::GetSaveObject(bool Global) const
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
	// local_SaveLuaFields(GetMutableDefault<UOmegaSettings>()->LuaFields_AutoSavedToGlobal,GetSaveObject(true));
	const FString LocalGlSaveName = GetMutableDefault<UOmegaSettings>()->GlobalSaveName;
	UGameplayStatics::SaveGameToSlot(GlobalSaveData, LocalGlSaveName, 0);
}
/*
bool UOmegaSaveSubsystem::SetJsonSaveProperty(const FString& Property, const int32& Value, bool Global)
{
	FJsonObjectWrapper TempWraper = GetSaveObject(Global)->JsonSaveObject;
	const bool IsSuccess = UJsonBlueprintFunctionLibrary::SetField(TempWraper,Property,Value);
	GetSaveObject(Global)->JsonSaveObject = TempWraper;
	return IsSuccess;
}

bool UOmegaSaveSubsystem::GetJsonSaveProperty(const FString& Property, int32& Value, bool Global)
{
	return UJsonBlueprintFunctionLibrary::GetField(GetSaveObject(Global)->JsonSaveObject,Property,Value);
}
*/
void UOmegaSaveSubsystem::SetStoryState(FGameplayTag StateTag, bool Global)
{
	GetSaveObject(Global)->StoryState = StateTag;
	OnSaveStateChanged.Broadcast(StateTag, Global);
}

FGameplayTag UOmegaSaveSubsystem::GetSaveState(bool Global)
{
	return GetSaveObject(Global)->StoryState;
}

void UOmegaSaveSubsystem::AddStoryTags(FGameplayTagContainer Tags, bool Global)
{
	GetSaveObject(Global)->StoryTags.AppendTags(Tags);
	OnSaveTagsEdited.Broadcast(Tags,true,Global);
}

void UOmegaSaveSubsystem::RemoveStoryTags(FGameplayTagContainer Tags, bool Global)
{
	GetSaveObject(Global)->StoryTags.RemoveTags(Tags);
	OnSaveTagsEdited.Broadcast(Tags,false,Global);
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

void UOmegaSaveSubsystem::ClearSavedStateFromActors(FGameplayTag SavedState)
{
	TArray<TSoftObjectPtr<AActor>> ActorList;

	ActiveSaveData->ActorStates.GetKeys(ActorList);
	
	for(TSoftObjectPtr<AActor> TempActor : ActorList)
	{
		if(ActiveSaveData->ActorStates.FindOrAdd(TempActor).MatchesTag(SavedState))
		{
			ActiveSaveData->ActorStates.Add(TempActor, FGameplayTag());
		}
	}
}

void UOmegaSaveSubsystem::SetDataAssetCollected(UPrimaryDataAsset* Asset, bool bGlobal, bool Collected)
{
	if(Collected)
	{
		GetSaveObject(bGlobal)->CollectedDataAssets.AddUnique(Asset);
	}
	else
	{
		UOmegaSaveBase* _sav=GetSaveObject(bGlobal);
		if(_sav->CollectedDataAssets.Contains(Asset))
		{
			_sav->CollectedDataAssets.Remove(Asset);
		}
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

bool UOmegaSaveSubsystem::IsDataAssetInSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal) const
{
	return GetSaveObject(bGlobal)->CollectedDataAssets.Contains(Asset);
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetCollectedDataAssets(bool bGlobal) const
{
	return GetSaveObject(bGlobal)->CollectedDataAssets;
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetCollectedDataAssetsOfCategory(FGameplayTag CategoryTag, bool bGlobal) const
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
	bool bExclude, bool bExact) const
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

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetDataAssetsWithSavedTags(FGameplayTagContainer Tags, bool bExact,
	 bool bGlobal)
{
	TArray<UPrimaryDataAsset*> out;
	TArray<UPrimaryDataAsset*> list;
	GetSaveObject(bGlobal)->Vars_Assets.GetKeys(list);
	for(auto* asset : list)
	{
		if(asset && DoesDataAssetHaveSaveTags(asset,Tags,bExact,bGlobal))
		{
			out.Add(asset);
		}
	}
	return out;
}

// ------------------------------------------------------------------------------------------------------------
// Data Assets
// ------------------------------------------------------------------------------------------------------------

void UOmegaSaveSubsystem::SetSaveTagsOnDataAsset(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bHasTags,
	bool bGlobal)
{
	if(Asset)
	{
		FOmegaSaveVars asset_data=GetSaveObject(bGlobal)->Vars_Assets.FindOrAdd(Asset);
		if(bHasTags)
		{
			asset_data.Tags.AppendTags(Tags);
		}
		else
		{
			asset_data.Tags.RemoveTags(Tags);
		}
		GetSaveObject(bGlobal)->Vars_Assets[Asset]=asset_data;
	}
}

void UOmegaSaveSubsystem::SetSaveTagsOnDataAsset_List(TArray<UPrimaryDataAsset*> Assets, FGameplayTagContainer Tags,
	bool bHasTags, bool bGlobal)
{
	for(auto* i : Assets)
	{
		SetSaveTagsOnDataAsset(i,Tags,bHasTags,bGlobal);
	}
}


bool UOmegaSaveSubsystem::DoesDataAssetHaveSaveTags(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bExact, bool bGlobal) const
{
	if(Asset)
	{
		FOmegaSaveVars asset_data=GetSaveObject(bGlobal)->Vars_Assets.FindOrAdd(Asset);
		if(bExact)
		{
			return asset_data.Tags.HasAllExact(Tags);
		}
		else
		{
			return asset_data.Tags.HasAny(Tags);
		}
	}
	return false;
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetSaveAssets_WithTags(FGameplayTagContainer Tags, bool bExact, bool bGlobal) const
{
	TArray<UPrimaryDataAsset*> out;
	TArray<UPrimaryDataAsset*> keys;
	GetSaveObject(bGlobal)->Vars_Assets.GetKeys(keys);
	for(UPrimaryDataAsset* i : keys)
	{
		if(DoesDataAssetHaveSaveTags(i,Tags,bExact,bGlobal))
		{
			out.Add(i);
		}
	}
	return out;
}

void UOmegaSaveSubsystem::SetGuidCollected(FGuid Guid, bool Collected, bool bGlobal)
{
	if(Collected)
	{
		GetSaveObject(bGlobal)->CollectedGuids.AddUnique(Guid);
	}
	else
	{
		GetSaveObject(bGlobal)->CollectedGuids.Remove(Guid);
	}
}

bool UOmegaSaveSubsystem::GetIsGuidCollected(FGuid Guid, bool bGlobal) const
{
	return GetSaveObject(bGlobal)->CollectedGuids.Contains(Guid);
}

void UOmegaSaveSubsystem::SetGuidHasTags(FGuid Guid, FGameplayTagContainer Tags, bool HasTags, bool bGlobal)
{
	FOmegaSaveVars asset_data=GetSaveObject(bGlobal)->Vars_Guid.FindOrAdd(Guid);
	if(HasTags)
	{
		asset_data.Tags.AppendTags(Tags);
	}
	else
	{
		asset_data.Tags.RemoveTags(Tags);
	}
	GetSaveObject(bGlobal)->Vars_Guid[Guid]=asset_data;
}

void UOmegaSaveSubsystem::SetGuidHasTags_List(TArray<FGuid> Guids, FGameplayTagContainer Tags, bool HasTags,
	bool bGlobal)
{
	for(FGuid i : Guids)
	{
		SetGuidHasTags(i,Tags,HasTags,bGlobal);
	}
}


bool UOmegaSaveSubsystem::GetDoesGuidHaveTags(FGuid Guid, FGameplayTagContainer Tags, bool bExact, bool bGlobal) const
{
	const FGameplayTagContainer TempTags = GetSaveObject(bGlobal)->Vars_Guid.FindOrAdd(Guid).Tags;
	if(bExact)
	{
		return TempTags.HasAllExact(Tags);
	}
	return TempTags.HasAll(Tags);
}

TArray<FGuid> UOmegaSaveSubsystem::GetSaveGuids_WithTags(FGameplayTagContainer Tags, bool bExact, bool bGlobal) const
{
	TArray<FGuid> out;
	TArray<FGuid> keys;
	GetSaveObject(bGlobal)->Vars_Guid.GetKeys(keys);
	for(FGuid i : keys)
	{
		if(GetDoesGuidHaveTags(i,Tags,bExact,bGlobal))
		{
			out.Add(i);
		}
	}
	return out;
}

//////////////
// Soft Properties
//////////////

void UOmegaSaveSubsystem::SetSoftProperty_Bool(const FString& Property, bool Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Bool(Property, Value);}

bool UOmegaSaveSubsystem::GetSoftProperty_Bool(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Bool(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Float(const FString& Property, float Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Float(Property, Value);}

float UOmegaSaveSubsystem::GetSoftProperty_Float(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Float(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Int32(const FString& Property, int32 Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Int(Property, Value);}

int32 UOmegaSaveSubsystem::GetSoftProperty_Int32(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Int(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_String(const FString& Property, FString Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_String(Property, Value);}

FString UOmegaSaveSubsystem::GetSoftProperty_String(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_String(Property);;}

void UOmegaSaveSubsystem::SetSoftProperty_Tag(const FString& Property, FGameplayTag Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Tag(Property, Value);}

FGameplayTag UOmegaSaveSubsystem::GetSoftProperty_Tag(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Tag(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Vector(const FString& Property, FVector Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Vector(Property, Value);}

FVector UOmegaSaveSubsystem::GetSoftProperty_Vector(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Vector(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Rotator(const FString& Property, FRotator Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Rotator(Property, Value);}

FRotator UOmegaSaveSubsystem::GetSoftProperty_Rotator(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Rotator(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Transform(const FString& Property, FTransform Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Transform(Property, Value);}

FTransform UOmegaSaveSubsystem::GetSoftProperty_Transform(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Transform(Property);}

void UOmegaSaveSubsystem::SetSoftProperty_DataAsset(const FString& Property, UPrimaryDataAsset* Value, bool bGlobal)
{GetSaveObject(bGlobal)->SetSaveProperty_Asset(Property, Value);}

UPrimaryDataAsset* UOmegaSaveSubsystem::GetSoftProperty_DataAsset(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->GetSaveProperty_Asset(Property);}

bool UOmegaSaveSubsystem::CustomSaveConditionsMet(FOmegaSaveConditions Conditions)
{
	TArray<UOmegaSaveCondition*> LocalConditionList = Conditions.Conditions;
	if(LocalConditionList.IsEmpty()) { return true; }
	for(const auto* TempCol : Conditions.ConditionCollections)
	{
		LocalConditionList.Append(TempCol->Conditions);
	}

	switch (Conditions.CheckType) {
	case BoolType_And:
		for(const UOmegaSaveCondition* TempCondition : LocalConditionList)
		{
			if(!TempCondition || !TempCondition->CheckSaveCondition(this))
			{
				return false;
			}
		}
		break;
	case BoolType_Or:
		for(const UOmegaSaveCondition* TempCondition : LocalConditionList)
		{
			if(TempCondition && TempCondition->CheckSaveCondition(this))
			{
				return true;
			}
			return false;
		}
		break;
	case BoolType_NONE:
		for(const UOmegaSaveCondition* TempCondition : LocalConditionList)
		{
			if(TempCondition && TempCondition->CheckSaveCondition(this))
			{
				return false;
			}
		}
		break;
	}
	
	return true;
}

void UOmegaSaveSubsystem::SaveObjectJsonData(UObject* Object, bool Global)
{
	
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()))
	{
		if(IOmegaSaveInterface::Execute_UseJsonSaveData(Object))
		{
			const FString LocalPropName = IOmegaSaveInterface::Execute_GetJsonPropertyName(Object);
			const FJsonObjectWrapper CurrentData = GetSaveObject(Global)->GetSaveProperty_Json(LocalPropName);
			const FJsonObjectWrapper LocalJsonData = IOmegaSaveInterface::Execute_SaveJsonData(Object,CurrentData);
			
			GetSaveObject(Global)->SetSaveProperty_Json(LocalPropName, LocalJsonData);
		}
	}
}

void UOmegaSaveSubsystem::LoadObjectJsonData(UObject* Object, bool Global)
{
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaSaveInterface::StaticClass()))
	{
		if(IOmegaSaveInterface::Execute_UseJsonSaveData(Object))
		{
			const FString LocalPropName = IOmegaSaveInterface::Execute_GetJsonPropertyName(Object);
			const FJsonObjectWrapper LocalJsonData = GetSaveObject(Global)->GetSaveProperty_Json(LocalPropName);
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

TArray<UOmegaStoryStateAsset*> UOmegaSaveSubsystem::GetActiveStoryStates()
{

	TArray<UOmegaStoryStateAsset*> out;
	out.Append(ActiveSaveData->ActiveStoryStates);
	out.Append(GlobalSaveData->ActiveStoryStates);
	return out;
}


void UOmegaSaveSubsystem::SetStoryStateActive(UOmegaStoryStateAsset* State, bool bActive,bool bGlobalSave)
{
	if(State)
	{
		if(IsStoryStateActive(State)!=bActive)
		{
			if(bActive)
			{
				//Check if the state can be activated
				for(auto* TempScript : State->Scripts)
				{
					if(!TempScript->CanActivateState(this,State))
					{
						return;
					}
				}
				GetSaveObject(bGlobalSave)->ActiveStoryStates.AddUnique(State);
				for(auto* TempScript : State->Scripts)
				{
					TempScript->OnStateBegin(this,State);
				}
			}
			else
			{
				GetSaveObject(bGlobalSave)->ActiveStoryStates.Remove(State);
				for(auto* TempScript : State->Scripts)
				{
					TempScript->OnStateEnd(this,State);
				}
			}
		}
	}
}

void UOmegaSaveSubsystem::ClearAllStoryStates(bool bGlobal)
{
	for(auto* TempState : GetActiveStoryStates())
	{
		SetStoryStateActive(TempState,false,bGlobal);
	}
}

bool UOmegaSaveSubsystem::IsStoryStateActive(UOmegaStoryStateAsset* State)
{
	return GetActiveStoryStates().Contains(State);
}

void UOmegaSaveSubsystem::SetDynamicVariableValue(UOmegaDynamicSaveVariable* Variable, int32 value, bool bGlobal)
{
	GetSaveObject(bGlobal)->DynamicVariableValues.Add(Variable,FString::FromInt(value));
	
}

int32 UOmegaSaveSubsystem::GetDynamicVariableValue(UOmegaDynamicSaveVariable* Variable, bool bGlobal)
{
	return FCString::Atoi(*GetSaveObject(bGlobal)->DynamicVariableValues.FindOrAdd(Variable));
}


// ====================================================================================================
// Story State
// ====================================================================================================

FString UOmegaSaveBase::GetPlaytimeString(bool bIncludeMilliseconds)
{
	FString TempString = Playtime.ToString(TEXT("%h:%m:%s"));
	if(bIncludeMilliseconds)
	{
		TempString = Playtime.ToString(TEXT("%h:%m:%s:%f"));
	}
	
	return TempString.Replace(TEXT("+"), TEXT(""));
}

void UOmegaSaveBase::Local_OnLoaded()
{
	
}

// ====================================================================================================
// Story State Script
// ====================================================================================================



//bool
void UOmegaSaveBase::SetSaveProperty_Bool(const FString& Name, bool Value)
{
	Prop_bool.Add(FName(Name), Value);
}

bool UOmegaSaveBase::GetSaveProperty_Bool(const FString& Name)
{
	return Prop_bool.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Float(const FString& Name, float Value)
{
	Prop_float.Add(FName(Name), Value);
}

float UOmegaSaveBase::GetSaveProperty_Float(const FString& Name)
{
	return Prop_float.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Int(const FString& Name, int32 Value)
{
	Prop_int.Add(FName(Name), Value);
}

int32 UOmegaSaveBase::GetSaveProperty_Int(const FString& Name)
{
	return Prop_int.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_String(const FString& Name, const FString& Value)
{
	Prop_string.Add(FName(Name), Value);
}

FString UOmegaSaveBase::GetSaveProperty_String(const FString& Name)
{
	return Prop_string.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Tag(const FString& Name, FGameplayTag Value)
{
	Prop_Tag.Add(FName(Name), Value);
}

FGameplayTag UOmegaSaveBase::GetSaveProperty_Tag(const FString& Name)
{
	return Prop_Tag.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Tags(const FString& Name, FGameplayTagContainer Value)
{
	Prop_Tags.Add(FName(Name), Value);
}

FGameplayTagContainer UOmegaSaveBase::GetSaveProperty_Tags(const FString& Name)
{
	return Prop_Tags.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Asset(const FString& Name, UPrimaryDataAsset* Value)
{
	Prop_Asset.Add(FName(Name), Value);
}

UPrimaryDataAsset* UOmegaSaveBase::GetSaveProperty_Asset(const FString& Name)
{
	return Prop_Asset.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Vector(const FString& Name, FVector Value)
{
	Prop_Vector.Add(FName(Name), Value);
}

FVector UOmegaSaveBase::GetSaveProperty_Vector(const FString& Name)
{
	return Prop_Vector.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Rotator(const FString& Name, FRotator Value)
{
	Prop_Rotator.Add(FName(Name), Value);
}

FRotator UOmegaSaveBase::GetSaveProperty_Rotator(const FString& Name)
{
	return Prop_Rotator.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Transform(const FString& Name, FTransform Value)
{
	Prop_Transform.Add(FName(Name), Value);
}

FTransform UOmegaSaveBase::GetSaveProperty_Transform(const FString& Name)
{
	return Prop_Transform.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Json(const FString& Name, FJsonObjectWrapper Value)
{
	Prop_Json.Add(FName(Name), Value);
}

FJsonObjectWrapper UOmegaSaveBase::GetSaveProperty_Json(const FString& Name)
{
	return Prop_Json.FindOrAdd(FName(Name));

}

// ====================================================================================================
// Save Condition
// ====================================================================================================

bool UOmegaSaveCondition::CheckSaveCondition_Implementation(UOmegaSaveSubsystem* SaveSubsystem) const
{
	return true;
}


//#############################################################################################################################################
// SAVE STATE COMPONENT
//#############################################################################################################################################

void UOmegaSaveStateComponent::BeginPlay()
{
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->OnSaveStateChanged.AddDynamic(this, &UOmegaSaveStateComponent::LocalStateChanged);
	GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->OnSaveTagsEdited.AddDynamic(this, &UOmegaSaveStateComponent::LocalTagsEdited);
	Refresh();
	Super::BeginPlay();
}

void UOmegaSaveStateComponent::LocalStateChanged(FGameplayTag TagState, bool bGlobal)
{
	
}

void UOmegaSaveStateComponent::LocalTagsEdited(FGameplayTagContainer Tags, bool Added, bool bGlobal)
{
	if(bGlobalSave == bGlobal)
	{
		UOmegaSaveSubsystem* SaveSubsystemRef = GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>();
		if(bGlobalSave == bGlobal)
		{
			if(!(VisibleOnSaveQuery.IsEmpty() || SaveSubsystemRef->SaveTagsMatchQuery(VisibleOnSaveQuery,bGlobalSave))	//If visible query is not empty & is valid
				|| (!HiddenOnSaveQuery.IsEmpty() && SaveSubsystemRef->SaveTagsMatchQuery(HiddenOnSaveQuery,bGlobalSave)))	//OR if hidden is valid...
			{
				UOmegaGameFrameworkBPLibrary::SetActorActive(GetOwner(),false);	//...this hide this actor
			}
			else
			{
				UOmegaGameFrameworkBPLibrary::SetActorActive(GetOwner(),true);
			}
		}
	}
}

void UOmegaSaveStateComponent::Refresh()
{
	LocalStateChanged(GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveState(bGlobalSave),bGlobalSave);
	LocalTagsEdited(FGameplayTagContainer(),false,bGlobalSave);
}

// ##############################################################################################################################
// State Asset
// ##############################################################################################################################

bool UOmegaStoryStateScript::CanActivateState_Implementation(UOmegaSaveSubsystem* SaveSubsystem,
	UOmegaStoryStateAsset* State)
{
	return true;
}

void UOmegaStoryStateScript::OnStateBegin_Implementation(UOmegaSaveSubsystem* SaveSubsystem,UOmegaStoryStateAsset* State)
{
}

void UOmegaStoryStateScript::OnStateEnd_Implementation(UOmegaSaveSubsystem* SaveSubsystem,UOmegaStoryStateAsset* State)
{
}

void UOmegaStoryStateScript::OnLevelChange_Implementation(UOmegaSaveSubsystem* SaveSubsystem,UOmegaStoryStateAsset* State, const FString& LevelName)
{
}

