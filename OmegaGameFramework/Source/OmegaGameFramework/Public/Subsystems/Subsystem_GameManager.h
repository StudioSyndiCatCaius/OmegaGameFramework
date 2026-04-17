// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "JsonObjectWrapper.h"
#include "Interfaces/I_Common.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Tickable.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Types/Struct_Bitflag.h"
#include "Types/Struct_CustomLevel.h"
#include "Types/Struct_InputConfig.h"
#include "Types/Struct_SoftParams.h"
#include "Subsystem_GameManager.generated.h"


class UOmegaSaveBase;
class UGamePreference;
class UOmegaSettings;
class UOmegaGameSettings;
class UOmegaGameplayModule;
class AOmegaGameMode;
class UAudioComponent;
class UOmegaBGM;
class UOmegaMod;
class UOmegaSubsystem_Engine;

// ===================================================================================================================
// STRUCTS
// ===================================================================================================================

const uint8 OGF_BGM_STATE_NONE=0;
const uint8 OGF_BGM_STATE_PLAYING=1;
const uint8 OGF_BGM_STATE_PAUSED=2;


USTRUCT()
struct FGameplayLogEntry
{
	GENERATED_BODY()

	UPROPERTY() FString Log;
	UPROPERTY() FString LogCategory;
};


USTRUCT()
struct FOmegaBGM_SlotData
{
	GENERATED_BODY()

	UPROPERTY() float SavedPlaybackPosition=0.0f;
	UPROPERTY() UOmegaBGM* lastBgm;

};

USTRUCT(BlueprintType)
struct FOmegaMachinaState
{
	GENERATED_BODY()
	
	FName current_state;
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOmegaSubsystemGIDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGlobalEvent, FName, Event, UObject*, Instigator, FOmegaCommonMeta, meta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTaggedGlobalEvent, FGameplayTag, Event, UObject*, Instigator, FOmegaCommonMeta, meta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewLevel, FString, LevelName, AOmegaGameMode*, GameMode);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFlagStateChange, FString, Flag, bool, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPreferenceValueUpdated, UGamePreference*, Preference, FVector, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOmegaMachinaStateChance,UObject*, TargetObject, FName, State,FOmegaCommonMeta, Meta);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOmegaGlobalParamDelegate,FName, Param, int32, Value,int32, OldValue,EOmegaGlobalParamTarget, Target);

UCLASS(Category = "OmegaSubsystems|Instance")
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_GameInstance : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
	
	UOmegaSaveBase* L_GetSaveObject(bool bGlobal) const;
	TMap<FName, TTuple<int32,int32>> external_file_script_map;
	
	UPROPERTY() UOmegaSubsystem_Engine* Subsys_Engine;
	
protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;
	void OnLevelChanged(UWorld* World, const UWorld::InitializationValues);

	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT( FMyTickableThing, STATGROUP_Tickables ); }
	virtual bool IsTickableWhenPaused() const { return true; }
	virtual bool IsTickableInEditor() const { return false; }

public:
	
	TArray<FKey> cachedAxisKeys;
	TMap<FKey,FOmegaInputKeyCacheData> InputKeyCacheData;

	//################################################################
	// GameData
	//################################################################
	void GameData_Init(FString Directory);
	
	// ------------------------------------------------------
	// Blueprint HIDDEN
	// ------------------------------------------------------
	UPROPERTY() FOmegaCustomLevelWrapper CurrentCustomLevel;
	//0=none | 1=FromLevel | 2=FromSave
	uint8 Zone_ZoneTransitState=0;
	UPROPERTY() TSoftObjectPtr<UWorld> Zone_LevelTransitingFrom;
	FGameplayTag Zone_LevelTransitingTag;
	
	UPROPERTY() TArray<UOmegaGameplayModule*> ActiveModules;
	UPROPERTY() TArray<UOmegaMod*> ModList;
	UPROPERTY() FOmegaSoftParams GlobalVars;
	class TSubclassOf<UOmegaGameSettings> LocalSettingsClass;
	
	UPROPERTY(BlueprintAssignable) FOmegaGlobalParamDelegate OnGlobalParamEdit;
	
	// ------------------------------------------------------
	// Blueprint VISIBLE
	// ------------------------------------------------------
	
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle="Gameplay Module", DeterminesOutputType="Module"), Category="Omega|Game Manager")
	UOmegaGameplayModule* GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module);

	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle="Gameplay Modules", DeterminesOutputType="Module"), Category="Omega|Game Manager")
	TArray<UOmegaGameplayModule*> GetGameplayModules();
		
	UPROPERTY(BlueprintAssignable)
	FOnNewLevel OnNewLevel;
	
	// ────────────────────────────────────────────────────────────────────
	// Load
	// ────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintCallable,Category="Omega|Load")
	void SetLoadStateString(FString LoadState);
	
	UPROPERTY(BlueprintReadOnly,Category="Omega") FString LoadStateString;
	
	float f_loadStringCooldown=0.0;
	
	
	// ────────────────────────────────────────────────────────────────────
	// BGM
	// ────────────────────────────────────────────────────────────────────
	void L_InitBgmComponent();
	
	UPROPERTY(BlueprintReadOnly,Category="Components") UAudioComponent* BgmPlayer;
	UPROPERTY() UOmegaBGM* BgmPlaying=nullptr;
	UPROPERTY() FGameplayTag BgmPlayingSlot;
	
	//0=stopped | 1=playing | 2=paused
	uint8 bgm_state;

	bool bgm_UsesMetasound;
	float bgm_playbackTime;
	float bgm_DefaultFadeTime=0.5;
	bool bgm_isLocked;
	
	UPROPERTY() TMap<FGameplayTag,FOmegaBGM_SlotData> BgmSlotData;
	
	UFUNCTION() void BGM_Play(UOmegaBGM* BGM, FGameplayTag Slot, bool bFadePrevious);
	UFUNCTION() void BGM_Stop(bool bFade,float FadeTime=0.5);
	UFUNCTION() void BGM_Pause(bool bPaused);
	UFUNCTION() void BGM_Lock(bool bLocked);
	
	//################################################################
	// MODS
	//################################################################
	
	UPROPERTY() TArray<UOmegaMod*> mods_loaded;
	
	//################################################################
	// Preferences
	//################################################################
	
	UPROPERTY(BlueprintAssignable) FOnPreferenceValueUpdated OnPreferenceValueUpdated;
	
	FVector Pref_Get(UGamePreference* pref) const;
	void Pref_Set(UGamePreference* pref, FVector Value) const;
	
	//################################################################
	// Global Event
	//################################################################
	UPROPERTY(BlueprintAssignable) FOnGlobalEvent OnGlobalEvent;
	UPROPERTY(BlueprintAssignable) FOnTaggedGlobalEvent OnTaggedGlobalEvent;
	
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager", meta=(AdvancedDisplay="Context"),DisplayName="Fire Global Event (Name)")
	void FireGlobalEvent(FName Event, UObject* Context, FOmegaCommonMeta meta);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager", meta=(AdvancedDisplay="Context"),DisplayName="Fire Global Event (Tag)")
	void FireTaggedGlobalEvent(FGameplayTag Event, UObject* Context, FOmegaCommonMeta meta);
	
	//################################################################
	// FLAGS
	//################################################################
	UPROPERTY(BlueprintReadOnly, Category="Omega|Game Manager")
	TArray<FString> Flags;
	
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager")
	void SetFlagActive(FString Flag, bool bActive);

	UFUNCTION(BlueprintPure, Category="Omega|Game Manager")
	bool IsFlagActive(FString Flag);

	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager")
	void ClearAllFlags();

	UPROPERTY(BlueprintAssignable)
	FOnFlagStateChange OnFlagStateChange;
	
	//################################################################
	// GlobalJson
	//################################################################

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="OmegaGameManager|GlobalJson")
	FJsonObjectWrapper GlobalJsonObject;
	
	//##################################################################################################################
	// LOG
	//##################################################################################################################

	UPROPERTY()
	int32 MaxLogEntry;
	
	UFUNCTION(BlueprintCallable, Category="OmegaGameManager")
	void AddGameplayLog(const FString& String, const FString& LogCategory);
	
	UFUNCTION(BlueprintCallable, Category="OmegaGameManager")
	void ClearLog();
	
	UPROPERTY()
	TArray<FGameplayLogEntry> LocalLog;
	
	UFUNCTION(BlueprintPure, Category="OmegaGameManager")
	TArray<FString> GetGameplayLog();
	UFUNCTION(BlueprintPure, Category="OmegaGameManager")
	TArray<FString> GetGameplayLogOfCategory(const FString& LogCategory);
	
	// ------------------------------------------------------
	// Machina
	// ------------------------------------------------------
	UPROPERTY() FOmegaMachinaStateChance OnMachinaState_Begin;
	UPROPERTY() FOmegaMachinaStateChance OnMachinaState_End;
	
	UPROPERTY() TMap<UObject*,FOmegaMachinaState> machina_states;
};


//##################################################################################################################
// Game Mod
//##################################################################################################################

UCLASS(Blueprintable,BlueprintType,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaMod : public UObject, public IDataInterface_General
{
	GENERATED_BODY()
	

public:
	UOmegaMod();
	FString GetGameDataDirectory() const;
	
	UPROPERTY() FLuaValue LuaValue;
	UPROPERTY() FString ModLabel;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Mods")
	bool OnModInitialized();
	
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override { Label = ModLabel; };
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description) override;
};
