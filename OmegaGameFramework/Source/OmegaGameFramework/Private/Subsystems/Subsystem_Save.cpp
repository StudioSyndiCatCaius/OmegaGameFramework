// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_Save.h"

#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Zone.h"

#include "UnrealClient.h"
#include "TimerManager.h"
#include "Dom/JsonObject.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectWrapper.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "Functions/F_Common.h"
#include "Engine/EngineTypes.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Global.h"
#include "DataAssets/DA_Campaign.h"
#include "Misc/OmegaGameplayModule.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"

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
	FString str_pref = GetMutableDefault<UOmegaSettings>()->SaveGamePrefex;
	FString str_slot = FString::Printf(TEXT("%04d"), Slot);
	OutName = str_pref+str_slot;
}

TArray<UOmegaSaveGame*> UOmegaSaveSubsystem::GetSaveSlotList(int32 FirstIndex, int32 LastIndex,const FString& alternate_path)
{
	TArray<UOmegaSaveGame*> OutList;
	for (int i = FirstIndex; i <= LastIndex; ++i)
	{
		bool bIsLoaded;
		if(UOmegaSaveGame* sav= LoadGame(i, bIsLoaded,alternate_path))
		{
			OutList.Add(sav);
		}
	}
	return OutList;
}

UOmegaSaveGame* UOmegaSaveSubsystem::LoadGame(int32 Slot, bool& Success, const FString& alt_path)
{
	FString SlotName;
	GetSaveSlotName(Slot, SlotName);
	return LoadGame_Named(SlotName,Success,alt_path);
}

UOmegaSaveGame* UOmegaSaveSubsystem::LoadGame_Named(FString Slot, bool& Success, const FString& alt_path)
{
	if(alt_path.IsEmpty())
	{
		const bool ValidSave = UGameplayStatics::DoesSaveGameExist(Slot, 0);
		Success = ValidSave;
	
		if (ValidSave)
		{
			UOmegaSaveGame* LocalGameSave = Cast<UOmegaSaveGame>(UGameplayStatics::LoadGameFromSlot(Slot, 0));
			LocalGameSave->SaveScreenshot = UKismetRenderingLibrary::ImportFileAsTexture2D(this, Local_GetScreenshotPath(Slot));
			return LocalGameSave;
		}
	}
	else if (USaveGame* _sav=OGF_Save::LoadGame(alt_path,Slot))
	{
		if(UOmegaSaveGame* sav_gam=Cast<UOmegaSaveGame>(_sav))
		{
			return sav_gam;
		}
	}
	return nullptr;
}

TArray<UOmegaSaveGame*> UOmegaSaveSubsystem::ListSavedGames(const FString& alt_path, int32 number, bool retain_size)
{
	TArray<UOmegaSaveGame*> out;
	for (int i = 0; i < number; ++i)
	{
		bool is_suc;
		if(UOmegaSaveGame* sav= LoadGame(i,is_suc,alt_path))
		{
			out.Add(sav);
		}
		else if(retain_size)
		{
			out.Add(nullptr);
		}
	}
	return out;
}



//ON SAVE
void UOmegaSaveSubsystem::SaveActiveGame(int32 Slot, FGameplayTag SaveCategory, bool& Success, const FString& AlternatePath)
{
	FString SlotName;
	GetSaveSlotName(Slot, SlotName);
	SaveActiveGame_Named(SlotName,SaveCategory,Success,AlternatePath);
}

void UOmegaSaveSubsystem::SaveActiveGame_Named(FString Slot, FGameplayTag SaveCategory, bool& Success, const FString& AlternatePath)
{
	Success = L_SaveGame(Slot,SaveCategory,AlternatePath);
}


bool UOmegaSaveSubsystem::SaveGameUnique(EUniqueSaveFormats Format)
{
	return false;
}



bool UOmegaSaveSubsystem::L_SaveGame(FString SlotName,FGameplayTag SaveCategory, const FString& alt_path)
{
	//LocalActiveData->ActiveLevelName = UGameplayStatics::GetCurrentLevelName(this);
	OGF_GLOBAL_SETTINGS()->OnSave_Saved(ActiveSaveData,GetGameInstance());
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
	
	if (IsValid(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		ActiveSaveData->SavedPlayerTransform = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorTransform();
	}
	ActiveSaveData->ActiveZone = GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->GetTopLoadedZones();
	ActiveSaveData->ActiveLevelName = UGameplayStatics::GetCurrentLevelName(this);
	ActiveSaveData->SaveDate = UKismetMathLibrary::Now();
	ActiveSaveData->SaveCategory=SaveCategory;

	//Save lua table
	ActiveSaveData->Lua_SaveTable(this,
		ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,nullptr,GetMutableDefault<ULuaSettings>()->GameSave_Table));
	
	
	const FString fileName = Local_GetScreenshotPath(SlotName);
	FScreenshotRequest::RequestScreenshot(fileName, false, false);

	// WRITE TO DISK
	if(alt_path.IsEmpty())
	{
		return UGameplayStatics::SaveGameToSlot(ActiveSaveData, SlotName, 0);
	}
	else
	{
		return OGF_Save::SaveGame(ActiveSaveData,alt_path,SlotName);
	}
	
}


//Create a new Save File Object
UOmegaSaveGame* UOmegaSaveSubsystem::CreateNewGame()
{
	const TSubclassOf<UOmegaSaveGame> LocalSaveClass = GetMutableDefault<UOmegaSettings>()->GetOmegaGameSaveClass(); //Get Save Game Class

	UOmegaSaveGame* CreatedGame = Cast<UOmegaSaveGame>(UGameplayStatics::CreateSaveGameObject(LocalSaveClass)); // Create a new file from that save class
	CreatedGame->SaveGuid=FGuid::NewGuid();
	CreatedGame->SaveSeed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
	CreatedGame->OnSaveCreated(GetWorld()->GetGameInstance());
	OGF_GLOBAL_SETTINGS()->OnSave_Created(CreatedGame,GetGameInstance());
	return CreatedGame;
}

void UOmegaSaveSubsystem::StartGame(class UOmegaSaveGame* GameData, bool LoadSavedLevel, FGameplayTagContainer Tags, bool NewGame, UOAsset_Campaign* NewCampaign)
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
	
	//Load saved lua table
	ULuaBlueprintFunctionLibrary::LuaSetGlobal(this,nullptr,GetMutableDefault<ULuaSettings>()->GameSave_Table,ActiveSaveData->Lua_LoadTable(this));
	OGF_GLOBAL_SETTINGS()->OnSave_Started(ActiveSaveData,GetGameInstance());
	//LASTLY, Try and load saved level if chosen
	if(LoadSavedLevel)
	{
		const FGameplayTag EmptyPoint;
		GetWorld()->GetGameInstance()->GetSubsystem<UOmegaZoneGameInstanceSubsystem>()->bIsLoadingGame=true;
		GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->TransitPlayerToLevel_Name(*ActiveSaveData->ActiveLevelName,EmptyPoint);
	}
	OnNewGameStarted.Broadcast(GameData,Tags);
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
			//If no, create a new one.
			GlobalSaveData = Cast<UOmegaSaveGlobal>(UGameplayStatics::CreateSaveGameObject(LocalGlobalSaveClass)); 
			GlobalSaveData->SaveGuid=FGuid::NewGuid();
			GlobalSaveData->SaveSeed=UKismetMathLibrary::RandomIntegerInRange(0,999999999);
			GlobalSaveData->OnSaveCreated(GetWorld()->GetGameInstance());
		}
		
	}
	if(!ActiveSaveData)
	{
		ActiveSaveData = CreateNewGame();
	}
	//Load saved lua table
	ULuaBlueprintFunctionLibrary::LuaSetGlobal(this,nullptr,GetMutableDefault<ULuaSettings>()->GlobalSave_Table,
		GlobalSaveData->Lua_LoadTable(this));

}

void UOmegaSaveSubsystem::local_SaveLuaFields(TArray<FString> fields, UOmegaSaveBase* save)
{
	for(FString temp_field: fields)
	{
		const FLuaValue lua_data = ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,GetMutableDefault<ULuaSettings>()->DefaultState.LoadSynchronous(), temp_field);
		FJsonObjectWrapper new_json;
		new_json.JsonObjectFromString(ULuaBlueprintFunctionLibrary::LuaValueToJson(lua_data));
		save->Prop_Json.Add(*temp_field,new_json);
	}
}

void UOmegaSaveSubsystem::local_LoadLuaFields(TArray<FString> fields, UOmegaSaveBase* save)
{
	for(FString temp_field: fields)
	{
		TSubclassOf<ULuaState> lua_state = GetMutableDefault<ULuaSettings>()->DefaultState.LoadSynchronous();
		FString json_string;
		save->Prop_Json.FindOrAdd(*temp_field).JsonObjectToString(json_string);
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
	//Save lua table
	GlobalSaveData->Lua_SaveTable(this,
		ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,nullptr,GetMutableDefault<ULuaSettings>()->GlobalSave_Table));
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
	GetSaveObject(Global)->SaveTags.AppendTags(Tags);
	OnSaveTagsEdited.Broadcast(Tags,true,Global);
}

void UOmegaSaveSubsystem::RemoveStoryTags(FGameplayTagContainer Tags, bool Global)
{
	GetSaveObject(Global)->SaveTags.RemoveTags(Tags);
	OnSaveTagsEdited.Broadcast(Tags,false,Global);
}

FGameplayTagContainer UOmegaSaveSubsystem::GetStoryTags(bool Global)
{
	FGameplayTagContainer FinalTags = GetSaveObject(Global)->SaveTags;

	FinalTags.AppendTags(IGameplayTagsInterface::Execute_GetObjectGameplayTags(ActiveSaveData));

	return FinalTags;
	
}

bool UOmegaSaveSubsystem::SaveTagsMatchQuery(FGameplayTagQuery Query, bool Global)
{
	if(Query.IsEmpty())
	{
		return true;
	}
	return Query.Matches(GetStoryTags(Global));
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

// ------------------------------------------------------------------------------------------------------------
// Data Assets
// ------------------------------------------------------------------------------------------------------------

void UOmegaSaveSubsystem::SetSaveTagsOnDataAsset(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bHasTags,
	bool bGlobal)
{
	GetSaveObject(bGlobal)->Entities.Asset_SetTags(Asset,Tags,bHasTags);
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
	return GetSaveObject(bGlobal)->Entities.Asset_HasTags(Asset,Tags,bExact);
}

TArray<UPrimaryDataAsset*> UOmegaSaveSubsystem::GetSaveAssets_WithTags(FGameplayTagContainer Tags, bool bExact, bool bGlobal) const
{
	return GetSaveObject(bGlobal)->Entities.Asset_GetWithTags(Tags,bExact);
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
	GetSaveObject(bGlobal)->Entities.Guid_SetTags(Guid,Tags,HasTags);
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
	return  GetSaveObject(bGlobal)->Entities.Guid_HasTags(Guid,Tags,bExact);
}

TArray<FGuid> UOmegaSaveSubsystem::GetSaveGuids_WithTags(FGameplayTagContainer Tags, bool bExact, bool bGlobal) const
{
	
	return GetSaveObject(bGlobal)->Entities.Guid_GetWithTags(Tags,bExact);
}

//////////////
// Soft Properties
//////////////

void UOmegaSaveSubsystem::SetSoftProperty_Bool(const FString& Property, bool Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_bool.Add(*Property, Value);}

bool UOmegaSaveSubsystem::GetSoftProperty_Bool(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_bool.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Float(const FString& Property, float Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_float.Add(*Property, Value);}

float UOmegaSaveSubsystem::GetSoftProperty_Float(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_float.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Int32(const FString& Property, int32 Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_int.Add(*Property, Value);}

int32 UOmegaSaveSubsystem::GetSoftProperty_Int32(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_int.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_String(const FString& Property, FString Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_string.Add(*Property, Value);}

FString UOmegaSaveSubsystem::GetSoftProperty_String(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_string.FindOrAdd(*Property);;}

void UOmegaSaveSubsystem::SetSoftProperty_Tag(const FString& Property, FGameplayTag Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_Tag.Add(*Property, Value);}

FGameplayTag UOmegaSaveSubsystem::GetSoftProperty_Tag(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_Tag.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Vector(const FString& Property, FVector Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_Vector.Add(*Property, Value);}

FVector UOmegaSaveSubsystem::GetSoftProperty_Vector(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_Vector.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Rotator(const FString& Property, FRotator Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_Rotator.Add(*Property, Value);}

FRotator UOmegaSaveSubsystem::GetSoftProperty_Rotator(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_Rotator.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_Transform(const FString& Property, FTransform Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_Transform.Add(*Property, Value);}

FTransform UOmegaSaveSubsystem::GetSoftProperty_Transform(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_Transform.FindOrAdd(*Property);}

void UOmegaSaveSubsystem::SetSoftProperty_DataAsset(const FString& Property, UPrimaryDataAsset* Value, bool bGlobal)
{GetSaveObject(bGlobal)->Prop_Asset.Add(*Property, Value);}

UPrimaryDataAsset* UOmegaSaveSubsystem::GetSoftProperty_DataAsset(const FString& Property, bool bGlobal)
{return GetSaveObject(bGlobal)->Prop_Asset.FindOrAdd(*Property);}

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
			const FJsonObjectWrapper CurrentData = GetSaveObject(Global)->Prop_Json.FindOrAdd(*LocalPropName);
			const FJsonObjectWrapper LocalJsonData = IOmegaSaveInterface::Execute_SaveJsonData(Object,CurrentData);
			
			GetSaveObject(Global)->Prop_Json.Add(*LocalPropName, LocalJsonData);
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
			const FJsonObjectWrapper LocalJsonData = GetSaveObject(Global)->Prop_Json.FindOrAdd(*LocalPropName);
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

void UOmegaSaveBase::SetBitFlag(uint8 flag, bool value)
{
	OGF_SoftParam::Bitmask_Set(Flags.Bitmask,flag,value);
}

bool UOmegaSaveBase::GetBitFlag(uint8 flag)
{
	return OGF_SoftParam::Bitmask_Get(Flags.Bitmask,flag);
}

void UOmegaSaveBase::SetBitFlag_Named(FName key, uint8 flag, bool value)
{
	FOmegaEntity& _e=Entities.Entities_Named.FindOrAdd(key);
	OGF_SoftParam::Bitmask_Set(_e.BitFlags,flag,value);
}

bool UOmegaSaveBase::GetBitFlag_Named(FName key, uint8 flag)
{
	return OGF_SoftParam::Bitmask_Get(Entities.Entities_Named.FindOrAdd(key).BitFlags,flag);
}

void UOmegaSaveBase::SetBitFlag_Guid(FGuid key, uint8 flag, bool value)
{
	FOmegaEntity& _e=Entities.Entities_Guid.FindOrAdd(key);
	OGF_SoftParam::Bitmask_Set(_e.BitFlags,flag,value);
}

bool UOmegaSaveBase::GetBitFlag_Guid(FGuid key, uint8 flag)
{
	return OGF_SoftParam::Bitmask_Get(Entities.Entities_Guid.FindOrAdd(key).BitFlags,flag);
}

void UOmegaSaveBase::Local_OnLoaded()
{
	
}

FLuaValue UOmegaSaveBase::Lua_LoadTable(UObject* context) const
{
	FLuaValue LuaValue;
	FString in_str;
	LuaSavedTable.JsonObjectToString(in_str);
	ULuaBlueprintFunctionLibrary::LuaValueFromJson(context,nullptr,in_str,LuaValue);
	return LuaValue;
}

void UOmegaSaveBase::Lua_SaveTable(UObject* context, FLuaValue LuaValue)
{
	FString l=ULuaBlueprintFunctionLibrary::LuaValueToJson(LuaValue);
	LuaSavedTable.JsonObjectFromString(l);
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

