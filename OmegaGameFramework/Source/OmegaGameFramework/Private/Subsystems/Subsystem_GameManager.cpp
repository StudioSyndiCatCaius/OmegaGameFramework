// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_GameManager.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "LuaSettings.h"
#include "LuaSubsystem.h"
#include "MetasoundSource.h"
#include "OmegaSettings.h"
#include "Misc/OmegaGameplayModule.h"
#include "OmegaGameplayConfig.h"
#include "OmegaGameManager.h"
#include "Components/AudioComponent.h"
#include "DataAssets/DA_BGM.h"
#include "DataAssets/DA_GamePreference.h"
#include "Engine/GameInstance.h"
#include "Functions/F_Common.h"
#include "Functions/F_File.h"
#include "Functions/F_Machina.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Types/Struct_InputConfig.h"
#include "Statics/OMEGA_File.h"
#include "Subsystems/Subsystem_Engine.h"
#include "Subsystems/Subsystem_World.h"


UOmegaSaveBase* UOmegaSubsystem_GameInstance::L_GetSaveObject(bool bGlobal) const
{
	if(GetWorld()->GetGameInstance())
	{
		return GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(bGlobal);
	}
	return nullptr;
}

void UOmegaSubsystem_GameInstance::Initialize(FSubsystemCollectionBase& Colection)
{
	Subsys_Engine=GEngine->GetEngineSubsystem<UOmegaSubsystem_Engine>();
	Subsys_Engine->OnGameInitialized();
	
	// -----------------------------------------------------------------------------------------------------------------
	// Iterate over game configs for caching
	// -----------------------------------------------------------------------------------------------------------------
	
	
	auto _HandleInputConfig = [this](TMap<FGameplayTag,FOmegaInputConfig> _InputConfig)
	{
		TArray<FGameplayTag> inputActionList;
		_InputConfig.GetKeys(inputActionList);
		for (FGameplayTag inputAction : inputActionList)
		{
			FOmegaInputConfig input_config=_InputConfig[inputAction];
			TArray<FKey> keys;
			input_config.KeyInputs.GetKeys(keys);
			for (FKey key : keys)
			{
				FOmegaKeyConfig _keyConfig=input_config.KeyInputs[key];
				FOmegaInputKeyCacheData _newCach=InputKeyCacheData.FindOrAdd(key);
				_newCach.KeyInputs.Add(inputAction,_keyConfig);
				InputKeyCacheData.Add(key,_newCach);
			}
		}
	};
	
	for (TSoftObjectPtr<UOmegaGameplayConfig> c : OGF_CFG()->Imported_GameplaySettings)
	{
		if (UOmegaGameplayConfig* _c=c.LoadSynchronous())
		{
			_HandleInputConfig(_c->InputActionConfigs);
			cachedAxisKeys.Append(c->PesistentAxisKeys);
		}
	}
	_HandleInputConfig(OGF_CFG()->InputActionConfigs);
	
	UOmegaSettings* settings_omega=GetMutableDefault<UOmegaSettings>();

#if !PLATFORM_ANDROID
	//subsys_asset->ClearSortedAssets_All();
#endif
	
	OGF_GAME_CORE()->OnGame_PreBegin(GetGameInstance());
	
	OGF_LUA_DOCODE(OGF_CFG_LUA()->Code_Init)
	// -----------------------------------------------------------------------------------------------------------------
	// ACTIVATE & REGISTER MODULES
	// -----------------------------------------------------------------------------------------------------------------
	
	TArray<UOmegaGameplayModule*> _tempModules=OGF_GAME_CORE()->GameplayModules;
	for(UOmegaGameplayConfig* _set : GetMutableDefault<UOmegaSettings>()->GetAllGameplaySettings())
	{
		_tempModules.Append(_set->GetModules());
	}
	
	for (auto* _module: _tempModules)
	{
		if(_module)
		{
			SetLoadStateString("Initializing Gameplay Module: "+_module->GetClass()->GetName());
			UOmegaGameplayModule* new_mod=DuplicateObject(_module,GetGameInstance());
			
			ActiveModules.Add(new_mod);
			new_mod->Native_Initialize(this);
			
		
			UE_LOG(LogTemp, Display, TEXT("%hs_%p"),"Gameplay Module Activated: ", new_mod->GetClass());

		}
	}
	
	// -----------------------------------------------------------------------------------------------------------------
	// Run auto lua files
	// -----------------------------------------------------------------------------------------------------------------
	
	ULuaSettings* settings_ref = GetMutableDefault<ULuaSettings>();
	ULuaSubsystem* lsub=GetGameInstance()->GetSubsystem<ULuaSubsystem>();
	if(settings_ref->bAutorunFiles)
	{
		SetLoadStateString("Running Main Lua autorun Script");
		lsub->RunLocalFile(settings_ref->Autorun_InitFile,false);
	}
	
	//this old method of autorunning lua files should be removed. Autorun should only be done from GameData folders.
	for (FString f : settings_ref->Autorun_FilePaths)
	{
	//	lsub->RunLocalFilesInPath(FPaths::ProjectContentDir()+"/"+OMEGA_File::PathCorrect(f),true,true);
	}
	
	for(TSoftObjectPtr<ULuaCode> temp_asset: settings_ref->AutorunCodeAssets)
	{
		if (ULuaCode* lc=temp_asset.LoadSynchronous())
		{
			SetLoadStateString("Running Lua autorun asset: "+lc->GetClass()->GetName());
			ULuaBlueprintFunctionLibrary::LuaRunCodeAsset(GetWorld(),ULuaBlueprintFunctionLibrary::GetDefaultLuaState(),lc);	
		}
		
	}
	
	//OGF_GAME_CORE()->OnGame_InitStateChange(GetWorld()->GetGameInstance(),EOmegaGameInitState::GameInitState_PostLuaAutorun);
	
	// -----------------------------------------------------------------------------------------------------------------
	// Load Mods
	// -----------------------------------------------------------------------------------------------------------------

	UE_LOG(LogInit, Log, TEXT("======================================================"));
	UE_LOG(LogInit, Log, TEXT("	LOADING MODS"));
	UE_LOG(LogInit, Log, TEXT("======================================================"));
	for (FString mod_folder : OMEGA_File::GetAllSubfolders(FPaths::ProjectModsDir(),false))
	{
		FString mod_name=FPaths::GetCleanFilename(mod_folder);
		OGF_Log::LogInfo("		Try load mod from folder:"+mod_name);
		FString mod_lua_path=mod_folder+"/"+mod_name+".lua";
		if (FPaths::FileExists(mod_lua_path))
		{
			FLuaValue v=ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(this,nullptr,mod_lua_path,true);
			TSubclassOf<UOmegaMod> in_mod_class=UOmegaMod::StaticClass();
			if (TSubclassOf<UOmegaMod> new_class=OGF_CFG()->ModClass.LoadSynchronous())
			{
				in_mod_class=new_class;
			}
			UOmegaMod* new_mod=NewObject<UOmegaMod>(this,in_mod_class);
			new_mod->LuaValue=v;
			mods_loaded.Add(new_mod);
		}
	}
	
	//OGF_GAME_CORE()->OnGame_InitStateChange(GetWorld()->GetGameInstance(),EOmegaGameInitState::GameInitState_PostModLoad);
	// -----------------------------------------------------------------------------------------------------------------
	// setup external file mapping - this will speed up importing files from GameData and Mods
	// -----------------------------------------------------------------------------------------------------------------
	
	for (auto c : OGF_CFG()->Imported_GameplaySettings)
	{
		if (UOmegaGameplayConfig* a=c.LoadSynchronous())
		{
			int32 config_index=OGF_CFG()->Imported_GameplaySettings.Find(c);
			for (auto* _script : a->FileImportScripts)
			{
				int32 script_index=a->FileImportScripts.Find(_script);
				for (FString _ext : _script->ValidExtensions)
				{
					external_file_script_map.Add(*_ext,MakeTuple(config_index,script_index));	
				}
			}
		}
	}
	
	
	// -----------------------------------------------------------------------------------------------------------------
	// External GameData Import
	// -----------------------------------------------------------------------------------------------------------------
	if (settings_omega->bAutoImportGameData)
	{
		UE_LOG(LogInit, Log, TEXT("======================================================"));
		UE_LOG(LogInit, Log, TEXT("	STARTING RUNTIME FILE IMPORT"));
		UE_LOG(LogInit, Log, TEXT("======================================================"));
			
		// FIRST - do base game
		
		FString full_path=FPaths::ProjectDir()+OGF_CFG()->GameData_Base_Directory;
		GameData_Init(full_path);
		
		if(settings_omega->bEnableMods)
		{
			// THEN - do mods
			for (UOmegaMod* m : mods_loaded)
			{
				if (m)
				{
					GameData_Init(m->GetGameDataDirectory());
				}
			}
		}
	}
	
	//OGF_GAME_CORE()->OnGame_InitStateChange(GetWorld()->GetGameInstance(),EOmegaGameInitState::GameInitState_PostGamedataInit);
	
	// -----------------------------------------------------------------------------------------------------------------
	// Generate Assets from Lua
	// -----------------------------------------------------------------------------------------------------------------
	UE_LOG(LogInit, Log, TEXT("======================================================"));
	UE_LOG(LogInit, Log, TEXT("	STARTING LUA OBJECT GENERATION"));
	UE_LOG(LogInit, Log, TEXT("======================================================"));
	TArray<UObject*> generated_lua_objects;
	TMap<UObject*,FLuaValue> generated_lua_object_data;
	for (TSoftObjectPtr<ULuaSettings_Preset> sp : GetMutableDefault<ULuaSettings>()->Settings_Presets)
	{
		if (ULuaSettings_Preset* p=Cast<ULuaSettings_Preset>(sp.LoadSynchronous()))
		{
			TArray<FName> table_keys;
			p->AutoGeneratedDataAssets.GetKeys(table_keys);
			for (FName _key : table_keys)
			{
				if (TSubclassOf<UPrimaryDataAsset> dac=p->AutoGeneratedDataAssets[_key])
				{
					FLuaValue gTabl=ULuaBlueprintFunctionLibrary::LuaGetGlobal(this,nullptr,_key.ToString());
					TArray<FLuaValue> gKeys=ULuaBlueprintFunctionLibrary::LuaTableGetKeys(gTabl);
					for (FLuaValue _gKey : gKeys)
					{
						FString o_name=_key.ToString()+"."+_gKey.ToString();
						SetLoadStateString("Generating object from lua key: "+_gKey.ToString());
						
						// if alreadye exists
						bool result=false;
						UObject* original_object=UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(_gKey.ToString(),dac,result);
						UObject* new_obj=nullptr;
						if (result)
						{
							new_obj=original_object;
						}
						else
						{
							new_obj=OGF_Subsystems::oEngine()->SortedAssets.FindOrAdd(_gKey.ToString());
							if (new_obj && new_obj->GetClass()->IsChildOf(dac))
							{
								new_obj->Rename(nullptr,this);
							}
							else
							{
								new_obj=NewObject<UObject>(this,dac);
								if (new_obj)
								{
									new_obj->Rename(*o_name);
									UE_LOG(LogInit, Log, TEXT("	Generated lua object %s"),*new_obj->GetName());
								}
							}
						}
						if (new_obj) //*o_name
						{
							generated_lua_objects.Add(new_obj);
							generated_lua_object_data.Add(new_obj,gTabl.GetField(_gKey.ToString()));
							ILuaInterface::Execute_SetKey(new_obj,_gKey);
							OGF_Subsystems::oEngine()->SortedAssets.Add(_gKey.ToString(),new_obj);
						}
					}
				}
			}
		}
	}
	//After generating all, do lua init
	for (auto* l : generated_lua_objects)
	{
		if (l && l->GetClass()->ImplementsInterface(ULuaInterface::StaticClass()))
		{
			ILuaInterface::Execute_SetValue(l,generated_lua_object_data.FindOrAdd(l),"");
		}
	}
	
	//OGF_GAME_CORE()->OnGame_InitStateChange(GetWorld()->GetGameInstance(),EOmegaGameInitState::GameInitState_PostGamedataLuaAutorun);
	
	// -----------------------------------------------------------------------------------------------------------------
	// Do mod init function
	// -----------------------------------------------------------------------------------------------------------------
	
	for (auto* m : mods_loaded)
	{
		if (m)
		{
			m->OnModInitialized();
		}
	}
	
	//OGF_GAME_CORE()->OnGame_InitStateChange(GetWorld()->GetGameInstance(),EOmegaGameInitState::GameInitState_PostModuleInit);
	settings_omega->GetGameCore()->OnGame_Begin(GetWorld()->GetGameInstance());
	
	
}

void UOmegaSubsystem_GameInstance::Deinitialize()
{
	UOmegaSettings* _set=GetMutableDefault<UOmegaSettings>();
	_set->GetGameCore()->OnGame_Begin(GetWorld()->GetGameInstance());
	
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		TempModule->Shutdown();
	}
	
	Super::Deinitialize();
}

void UOmegaSubsystem_GameInstance::Tick(float DeltaTime)
{
	TArray<UObject*> machina_objects;
	machina_states.GetKeys(machina_objects);
	
	for (auto* l : machina_objects)
	{
		if (l && !machina_states[l].current_state.IsNone())
		{
			FOmegaMachinaState _stateData=machina_states[l];
			IObjectInterface_Machina::Execute_Machina_StateTick(l,_stateData.current_state,DeltaTime);
		}
		else
		{
			machina_states.Remove(l);
		}
	}
}

void UOmegaSubsystem_GameInstance::GameData_Init(FString Directory)
{
	FString inDir=OMEGA_File::PathCorrect(Directory);
	UE_LOG(LogInit, Log, TEXT("GAME DATA:	📁 IMPORTING DIRECTORY:  %s"), *Directory);
	for (FString path : OMEGA_File::ListFilesInDirectory(inDir,true))
	{
		// load external files to assets
		FName _ext=*FPaths::GetExtension(path);
		if (external_file_script_map.Contains(_ext))
		{
			auto& _mapping=external_file_script_map[_ext];
			int32 i_cfg=_mapping.Get<0>();
			int32 i_script=_mapping.Get<1>();
			if (UOmegaFileImportScript* _script=OGF_CFG()->Imported_GameplaySettings[i_cfg].LoadSynchronous()->FileImportScripts[i_script])
			{
				FString import_filename=FPaths::GetBaseFilename(path);
				SetLoadStateString("Importing GameData file: "+import_filename);
				if (UObject* _importedObject= _script->ImportAsObject(path,import_filename,FPaths::GetExtension(path),GetGameInstance()))
				{
					UE_LOG(LogInit, Log, TEXT("GAME DATA:		📥 Imported File:  %s -- as %s"), *path, *_importedObject->GetName());
					Subsys_Engine->SortedAssets.Add(import_filename,_importedObject);
				}
			}
		}
		
		//autorun lua files
		TArray<FString> lua_files=OMEGA_File::ListFilesInDirectory(inDir+OGF_CFG()->GameData_LuaAutorun_Directory,true);
		lua_files.Sort();
		for (FString lua_file : lua_files)
		{
			FString lPath=OMEGA_File::PathCorrect(lua_file);
			if (FPaths::GetExtension(lua_file)=="lua")
			{
				SetLoadStateString("Run GameData lua file: "+lPath);
				ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(this,nullptr,lPath,true);	
			}
		}
	}
}



//############################################################################
// Gameplay Modules
//############################################################################


UOmegaGameplayModule* UOmegaSubsystem_GameInstance::GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module)
{
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		if(TempModule->GetClass()->IsChildOf(Module))
		{
			return TempModule;
		}
	}
	return nullptr;
}

TArray<UOmegaGameplayModule*> UOmegaSubsystem_GameInstance::GetGameplayModules()
{
	return ActiveModules;
}

void UOmegaSubsystem_GameInstance::SetLoadStateString(FString LoadState)
{
	LoadStateString=LoadState;
	UE_LOG(LogTemp, Display, TEXT("%s"), *LoadState);
	f_loadStringCooldown=2.5; //cooldown before cleaing the
}

void UOmegaSubsystem_GameInstance::L_InitBgmComponent()
{
	if (!BgmPlayer)
	{
		//create BGM component
		if (UMetaSoundSource* _msBgm=OGF_CFG()->BgmMetasound.LoadSynchronous())
		{
			bgm_UsesMetasound=true;
			USoundBase* _dummySound=NewObject<USoundBase>(this,USoundWave::StaticClass());
			if (this->GetWorld())
			{
				BgmPlayer=UGameplayStatics::CreateSound2D(this,_dummySound,1,1,0,nullptr,true,false);
				if (BgmPlayer)
				{
					BgmPlayer->SetSound(_msBgm);
				}
				else
				{
					OGF_Log::Error("Failed to create BGM Audio Component: Unknown Reason");	
				}
			}
			else
			{
				OGF_Log::Error("Failed to create BGM Audio Component: No Valid World");	
			}
		
		}
		else
		{
			OGF_Log::Error("Failed to create BGM Audio Component: Not valid BGM Metasound Source");
		}
	
	}
}


FVector UOmegaSubsystem_GameInstance::Pref_Get(UGamePreference* pref) const
{
	if (pref)
	{
		if (UOmegaSaveBase* s=L_GetSaveObject(pref->bGlobal))
		{
			return pref->L_GetValue(this,s);
		}
	}
	return FVector();
}

void UOmegaSubsystem_GameInstance::Pref_Set(UGamePreference* pref, FVector Value) const
{
	if (pref)
	{
		if (UOmegaSaveBase* s=L_GetSaveObject(pref->bGlobal))
		{
			return pref->L_SetValue(this,s,Value);
		}
	}
}

void UOmegaSubsystem_GameInstance::FireGlobalEvent(FName Event, UObject* Context,FOmegaCommonMeta meta)
{
	OGF_GAME_CORE()->OnGlobalEvent_Named(GetGameInstance(),Event,Context,meta);
	OnGlobalEvent.Broadcast(Event, Context,meta);
}

void UOmegaSubsystem_GameInstance::FireTaggedGlobalEvent(FGameplayTag Event, UObject* Context,FOmegaCommonMeta meta)
{
	OGF_GAME_CORE()->OnGlobalEvent_Tagged(GetGameInstance(),Event,Context,meta);
	OnTaggedGlobalEvent.Broadcast(Event,Context,meta);
}

void UOmegaSubsystem_GameInstance::SetFlagActive(FString Flag, bool bActive)
{
	if(IsFlagActive(Flag) != bActive)
	{
		if(bActive)
		{
			Flags.AddUnique(Flag);
		}
		else
		{
			Flags.Remove(Flag);
		}
		OnFlagStateChange.Broadcast(Flag, bActive);
	}
}

bool UOmegaSubsystem_GameInstance::IsFlagActive(FString Flag)
{
	return Flags.Contains(Flag);
}

void UOmegaSubsystem_GameInstance::ClearAllFlags()
{
	TArray<FString> LocalFlags = Flags;
	for(FString TempFlag : LocalFlags)
	{
		SetFlagActive(TempFlag, false);	
	}
	Flags.Empty();
}



void UOmegaSubsystem_GameInstance::AddGameplayLog(const FString& String, const FString& LogCategory)
{
	FGameplayLogEntry TempEntry;
	TempEntry.Log = String;
	TempEntry.LogCategory = LogCategory;
	LocalLog.Add(TempEntry);
}

void UOmegaSubsystem_GameInstance::ClearLog()
{
	LocalLog.Empty();
}

TArray<FString> UOmegaSubsystem_GameInstance::GetGameplayLog()
{
	TArray<FString> LocalStrings;
	for(FGameplayLogEntry TempEntry : LocalLog)
	{
		LocalStrings.Add(TempEntry.Log);
	}
	LocalStrings.SetNum(MaxLogEntry);
	return LocalStrings;
}

TArray<FString> UOmegaSubsystem_GameInstance::GetGameplayLogOfCategory(const FString& LogCategory)
{TArray<FString> LocalStrings;
	for(FGameplayLogEntry TempEntry : LocalLog)
	{
		if(TempEntry.LogCategory == LogCategory)
		{
			LocalStrings.Add(TempEntry.Log);
		}
	}
	LocalStrings.SetNum(MaxLogEntry);
	return LocalStrings;
	
}


// ----------------------------------------------------------------------------------------------------
// BGM
// ----------------------------------------------------------------------------------------------------


void UOmegaSubsystem_GameInstance::BGM_Play(UOmegaBGM* BGM, FGameplayTag Slot, bool bFadePrevious)
{
	if(bgm_isLocked) { return; }
	if (BgmPlayer && BGM && (BgmPlaying!=BGM || bgm_state!=OGF_BGM_STATE_PLAYING))
	{
		BgmPlaying=BGM;
		auto _PlayNextBgm = [this, BGM, Slot]()
		{
			if (bgm_UsesMetasound)
			{
				BgmPlayer->SetWaveParameter("Wav",BGM->Sound);
				BgmPlayer->SetFloatParameter("Loop_Start",BGM->LoopBeginTime);
				BgmPlayer->SetFloatParameter("Loop_End",BGM->LoopEndTime);
			}
			else
			{
				BgmPlayer->SetSound(BGM->Sound);
			}
			float start_position=0.0;
			FOmegaBGM_SlotData _SlotData=BgmSlotData.FindOrAdd(Slot);
			if (_SlotData.lastBgm==BGM)
			{
				start_position=_SlotData.SavedPlaybackPosition;
			}
			BgmPlayer->Play(start_position);
			bgm_state=OGF_BGM_STATE_PLAYING;
		};
		
		if (bFadePrevious)
		{
			BGM_Stop(true,bgm_DefaultFadeTime);
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(_PlayNextBgm), bgm_DefaultFadeTime, false);
		}
		else
		{
			BGM_Stop(false);
			_PlayNextBgm();
		}
	}
}

void UOmegaSubsystem_GameInstance::BGM_Stop(bool bFade, float FadeTime)
{
	if (!BgmPlayer) { return; }
	if(bgm_isLocked) { return; }
	if (BgmPlayer->IsPlaying() && bgm_state==OGF_BGM_STATE_PLAYING)
	{
		bgm_state=OGF_BGM_STATE_NONE;
		FOmegaBGM_SlotData* _slotdata=&BgmSlotData.FindOrAdd(BgmPlayingSlot);
		_slotdata->lastBgm=BgmPlaying;
		_slotdata->SavedPlaybackPosition=bgm_playbackTime;
		
		if (bFade)
		{
			BgmPlayer->FadeOut(FadeTime,0.0);
		}
		else
		{
			BgmPlayer->Stop();
		}
	}
}

void UOmegaSubsystem_GameInstance::BGM_Pause(bool bPaused)
{
	if (!BgmPlayer) { return; }
	if(bgm_isLocked) { return; }
	if (bPaused && bgm_state==OGF_BGM_STATE_PLAYING)
	{
		bgm_state=OGF_BGM_STATE_PAUSED;
		BgmPlayer->FadeOut(bgm_DefaultFadeTime,0.0);
	}
	else if (!bPaused && bgm_state==OGF_BGM_STATE_PAUSED)
	{
		bgm_state=OGF_BGM_STATE_PLAYING;
		BgmPlayer->Play(bgm_playbackTime);
		BgmPlayer->FadeIn(bgm_DefaultFadeTime);
	}
}

void UOmegaSubsystem_GameInstance::BGM_Lock(bool bLocked)
{
	if (bLocked != bgm_isLocked)
	{
		bgm_isLocked=bLocked;
		if (bLocked)
		{
			
		}
		else
		{
			
		}
	}
}




//##################################################################################################################
// Game Mod
//##################################################################################################################
FString UOmegaMod::GetGameDataDirectory() const
{
	return FPaths::ProjectModsDir()+"/"+ModLabel+"/"+OGF_CFG()->GameData_Base_Directory;
}


UOmegaMod::UOmegaMod()
{
}

void UOmegaMod::GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description)
{
	Name=LuaValue.GetField("name").ToText();
	Description=LuaValue.GetField("description").ToText();
}
