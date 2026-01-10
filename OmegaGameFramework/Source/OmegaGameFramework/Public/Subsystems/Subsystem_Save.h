// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/I_Common.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Engine/World.h"
#include "JsonObjectWrapper.h"
#include "LuaValue.h"
#include "Misc/Paths.h"
#include "Misc/Timespan.h"
#include "GameFramework/SaveGame.h"
#include "Interfaces/I_BitFlag.h"
#include "Misc/GeneralDataObject.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Subsystem_Save.generated.h"

class UOmegaBGM;
class UOAsset_Campaign;
class UOmegaQuest;
class UOmegaSaveBase;
class UOmegaSaveGame;
class UOmegaSaveGlobal;
class UOmegaSaveCondition;
class UOmegaZoneData;
class UGamePreference;

// ====================================================================================================
// ENUMS
// ====================================================================================================

USTRUCT(BlueprintType)
struct FOmegaSaveConditions
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="OmegaSaveConditions")
	TEnumAsByte<EBoolType> CheckType=BoolType_And;
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", instanced, EditAnywhere)
	TArray<class UOmegaSaveCondition*> Conditions;
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", EditAnywhere)
	TArray<class UOmegaSaveConditionCollection*> ConditionCollections;
};

// ====================================================================================================
// Subsystem
// ====================================================================================================
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewGameStarted, UOmegaSaveGame*, NewGame, FGameplayTagContainer, Tags);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSaveStateChanged, FGameplayTag, NewState, bool, bGlobal);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSaveTagsEdited, FGameplayTagContainer, EditedTags, bool, Added, bool, bGlobal);

UCLASS(DisplayName = "Omega Subsystem: Save")
class OMEGAGAMEFRAMEWORK_API UOmegaSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UFUNCTION() bool L_SaveGame(FString SlotName,FGameplayTag SaveCategory, const FString& alt_path);
	UFUNCTION() void OnPlaytimeUpdate();
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;
	
	
	UPROPERTY(BlueprintReadOnly, Category = "Omega|SaveSubsystem")
	class UOmegaSaveGame* ActiveSaveData;
	UPROPERTY(BlueprintReadOnly, Category = "Omega|SaveSubsystem")
	class UOmegaSaveGlobal* GlobalSaveData;
	
	UFUNCTION(BlueprintPure, Category = "Omega|SaveSubsystem")
	static void GetSaveSlotName(int32 Slot, FString& OutName);

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
	TArray<UOmegaSaveGame*> GetSaveSlotList(int32 FirstIndex, int32 LastIndex = 1,const FString& alternate_path="");

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem|Load",DisplayName="Load Game Object (From Slot)")
	UOmegaSaveGame* LoadGame(int32 Slot, bool& Success, const FString& alt_path);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem|Load",DisplayName="Load Game Object (From Name)")
	UOmegaSaveGame* LoadGame_Named(FString Slot, bool& Success, const FString& alt_path);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem|Load")
	TArray<UOmegaSaveGame*> ListSavedGames(const FString& alt_path,int32 number, bool retain_size);
	//###############################################################################################
	// Playtime
	//###############################################################################################
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem")
	FTimespan GetSavePlaytime(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem")
	FString GetSavePlaytimeString(bool bGlobal, bool bIncludeMilliseconds);
	//###############################################################################################
	// SAVING
	//###############################################################################################
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem", DisplayName="Save Game (Unique Format)")
	bool SaveGameUnique(EUniqueSaveFormats Format);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem",DisplayName="Save Active Game (To Slot)",meta=(AdvancedDisplay="AlternatePath"))
	void SaveActiveGame(int32 Slot,FGameplayTag SaveCategory, bool& Success, const FString& AlternatePath="");

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem",DisplayName="Save Active Game (To Name)",meta=(AdvancedDisplay="AlternatePath"))
	void SaveActiveGame_Named(FString Slot,FGameplayTag SaveCategory, bool& Success, const FString& AlternatePath="");
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
	UOmegaSaveGame* CreateNewGame();

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem", meta = (AdvancedDisplay = "Tags, NewGame, NewCampaign"))
	void StartGame(class UOmegaSaveGame* GameData, bool LoadSavedLevel, FGameplayTagContainer Tags,
	bool NewGame=false, UOAsset_Campaign* NewCampaign=nullptr);


private:

	void Local_InitializeSaveObjects();
	void local_SaveLuaFields(TArray<FString> fields, UOmegaSaveBase* save);
	void local_LoadLuaFields(TArray<FString> fields, UOmegaSaveBase* save);
	
	UPROPERTY()
	bool Local_JsonSave;

public:
	
	UFUNCTION()
	UOmegaSaveBase* GetSaveObject(bool Global) const;

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem")
	void SaveGlobalGame();

	UPROPERTY(BlueprintAssignable) FOnSaveStateChanged OnSaveStateChanged;
	UPROPERTY(BlueprintAssignable) FOnSaveTagsEdited OnSaveTagsEdited;
	UPROPERTY(BlueprintAssignable) FOnNewGameStarted OnNewGameStarted;
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Tags", DisplayName="Set Save State Tag")
	void SetStoryState(FGameplayTag StateTag, bool Global);
	
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Tags")
	FGameplayTag GetSaveState(bool Global);
	
	UFUNCTION(BlueprintCallable, DisplayName="Add Save Tags", Category="Omega|SaveSubsystem|Tags")
	void AddStoryTags(FGameplayTagContainer Tags, bool Global);

	UFUNCTION(BlueprintCallable, DisplayName="Remove Save Tags", Category="Omega|SaveSubsystem|Tags")
	void RemoveStoryTags(FGameplayTagContainer Tags, bool Global);

	UFUNCTION(BlueprintPure, DisplayName="Get Active Save Tags", Category="Omega|SaveSubsystem|Tags")
	FGameplayTagContainer GetStoryTags(bool Global);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Tags")
	bool SaveTagsMatchQuery(FGameplayTagQuery Query, bool Global);
	
	//###############################################################################################
	// Actor
	//###############################################################################################

	UFUNCTION() void SetSavedActorState(AActor* Actor, FGameplayTag StateTag);
	UFUNCTION() void AddSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);
	UFUNCTION() void RemoveSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	//Clears the state tag from any actors with the given state.
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Actor", meta=(Keywords="remove"))
	void ClearSavedStateFromActors(FGameplayTag SavedState);

	//###############################################################################################
	// Data Assets
	//###############################################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"),DisplayName="DataAsset - Set Collected")
	void SetDataAssetCollected(UPrimaryDataAsset* Asset, bool bGlobal, bool Collected);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"),DisplayName="DataAsset - Set Collected (List)")
	void SetDataAssetsCollected(TArray<UPrimaryDataAsset*> Assets, bool bGlobal, bool Collected);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"),DisplayName="DataAsset - Is Collected?")
	bool IsDataAssetInSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal) const;

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets",DisplayName="DataAsset - Get Collected")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssets(bool bGlobal) const;

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets",DisplayName="DataAsset - Get Collected (of Category Tag)")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsOfCategory(FGameplayTag CategoryTag, bool bGlobal) const;

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bExclude, bExact"),DisplayName="DataAsset - Get Collected (w/ Tags)")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsWithTags(FGameplayTagContainer Tags, bool bGlobal, bool bExclude, bool bExact = true) const;

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets",DisplayName="DataAsset - Edit SaveTags")
	void SetSaveTagsOnDataAsset(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bHasTags, bool bGlobal);
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets",DisplayName="DataAsset - Edit SaveTags (List)")
	void SetSaveTagsOnDataAsset_List(TArray<UPrimaryDataAsset*> Assets, FGameplayTagContainer Tags, bool bHasTags, bool bGlobal);
	
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets",DisplayName="DataAsset - Has SaveTags?")
	bool DoesDataAssetHaveSaveTags(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bExact, bool bGlobal) const;

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"),DisplayName="DataAsset - Get w/ SaveTags")
	TArray<UPrimaryDataAsset*> GetSaveAssets_WithTags(FGameplayTagContainer Tags, bool bExact, bool bGlobal) const;
	
	//###############################################################################################
	// Guids
	//###############################################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"),DisplayName="Guid - Set Collected")
	void SetGuidCollected(FGuid Guid, bool Collected, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"),DisplayName="Guid - Is Collected?")
	bool GetIsGuidCollected(FGuid Guid, bool bGlobal) const;

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"),DisplayName="Guid - Edit SaveTags")
	void SetGuidHasTags(FGuid Guid, FGameplayTagContainer Tags, bool HasTags, bool bGlobal);
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"),DisplayName="Guid - Edit SaveTags (List)")
	void SetGuidHasTags_List(TArray<FGuid> Guids, FGameplayTagContainer Tags, bool HasTags, bool bGlobal);
	
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"),DisplayName="Guid - Has Tag?")
	bool GetDoesGuidHaveTags(FGuid Guid, FGameplayTagContainer Tags, bool bExact, bool bGlobal) const;
	
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"),DisplayName="Guid - Get w/ Tags")
	TArray<FGuid> GetSaveGuids_WithTags(FGameplayTagContainer Tags, bool bExact, bool bGlobal) const;
	
	//###############################################################################################
	// Soft Properties
	//###############################################################################################
	
		//bool
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Bool")
	void SetSoftProperty_Bool(const FString& Property, bool Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Bool")
	bool GetSoftProperty_Bool(const FString& Property, bool bGlobal);
		//float
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Float")
	void SetSoftProperty_Float(const FString& Property, float Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Float")
	float GetSoftProperty_Float(const FString& Property, bool bGlobal);
		//int
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Int32")
	void SetSoftProperty_Int32(const FString& Property, int32 Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Int32")
	int32 GetSoftProperty_Int32(const FString& Property, bool bGlobal);
		//string
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | String")
	void SetSoftProperty_String(const FString& Property, FString Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | String")
	FString GetSoftProperty_String(const FString& Property, bool bGlobal);
		//tag
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Tag")
	void SetSoftProperty_Tag(const FString& Property, FGameplayTag Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Tag")
	FGameplayTag GetSoftProperty_Tag(const FString& Property, bool bGlobal);
		//vec
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Vector")
	void SetSoftProperty_Vector(const FString& Property, FVector Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Vector")
	FVector GetSoftProperty_Vector(const FString& Property, bool bGlobal);
		//rot
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Rotator")
	void SetSoftProperty_Rotator(const FString& Property, FRotator Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Rotator")
	FRotator GetSoftProperty_Rotator(const FString& Property, bool bGlobal);
		//transform
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | Transform")
	void SetSoftProperty_Transform(const FString& Property, FTransform Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | Transform")
	FTransform GetSoftProperty_Transform(const FString& Property, bool bGlobal);
		//transform
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Set Save Property | DataAsset")
	void SetSoftProperty_DataAsset(const FString& Property, UPrimaryDataAsset* Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties", DisplayName="Get Save Property | DataAsset")
	UPrimaryDataAsset* GetSoftProperty_DataAsset(const FString& Property, bool bGlobal);
		//guid
	
	///MESSAGE LOGGING
	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem")
	bool CustomSaveConditionsMet(FOmegaSaveConditions Conditions);

	//###############################################################################################
	// SAVING Json
	//###############################################################################################
	
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem")
	void SaveObjectJsonData(UObject* Object, bool Global);
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem")
	void LoadObjectJsonData(UObject* Object, bool Global);

	UPROPERTY()
	TArray<UObject*> JsonSaveSources;
	
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem")
	void SetSaveSourceRegistered(UObject* Source, bool Registered);

	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem")
	TArray<UObject*> GetSaveSources();
	
	//###############################################################################################
	// Screenshot
	//###############################################################################################
	FString Local_GetScreenshotPath(FString SlotName)
	{
		FString fileName = FPaths::ProjectSavedDir();
		fileName = fileName + "/SaveGames/" + SlotName + ".png";
		return  fileName;
	}

	//###############################################################################################
	// Story State
	//###############################################################################################
	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem|StoryState")
	TArray<UOmegaStoryStateAsset*> GetActiveStoryStates();
	
	UPROPERTY() TArray<UOmegaStoryStateAsset*> ActiveStoryStates;
	
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem|StoryState")
	void SetStoryStateActive(UOmegaStoryStateAsset* State, bool bActive,bool bGlobalSave);

	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem|StoryState")
	void ClearAllStoryStates(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem|StoryState")
	bool IsStoryStateActive(UOmegaStoryStateAsset* State);


};


UCLASS( ClassGroup=("Omega Game Framework"), DisplayName="Visibility On Save", meta=(BlueprintSpawnableComponent) )
class OMEGAGAMEFRAMEWORK_API UOmegaSaveStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void LocalStateChanged(FGameplayTag TagState, bool bGlobal);
	UFUNCTION()
	void LocalTagsEdited(FGameplayTagContainer Tags,  bool Added, bool bGlobal);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	bool bGlobalSave;

	UFUNCTION()
	void Refresh();

	//Displays this actor only if the save state is one of the given tags.
	UPROPERTY()
	FGameplayTagContainer VisibleOnStateTags;
	
	UPROPERTY()
	FGameplayTagContainer HiddenOnStateTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags", DisplayName="Visible (On Save Query)")
	FGameplayTagQuery VisibleOnSaveQuery;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags", DisplayName="Hidden (On Save Query)")
	FGameplayTagQuery HiddenOnSaveQuery;
	
};

// ====================================================================================================
// Save Object
// ====================================================================================================
USTRUCT()
struct FOmegaSaveAssetList
{
	GENERATED_BODY()
	UPROPERTY()
	TArray<UPrimaryDataAsset*> AssetList;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveBase : public USaveGame, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION() void Local_OnLoaded();
	
	FLuaValue Lua_LoadTable(UObject* context) const;
	void Lua_SaveTable(UObject* context, FLuaValue LuaValue);
	
	UPROPERTY()  FOmegaGlobalVarsContainer GlobalVars;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Base")  FGuid SaveGuid;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Base")  int32 SaveSeed;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save") FOmegaEntitySet Entities;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save") TArray<UOmegaStoryStateAsset*> ActiveStoryStates;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Save") TArray<UPrimaryDataAsset*> CollectedDataAssets;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Save") TArray<FGuid> CollectedGuids;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save") TMap<UOmegaQuest*,FOmegaQuestData> quest_data;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save") TMap<FGameplayTag,FOmegaList_DataAsset> Lists_Assets;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save") TMap<FGameplayTag,FOmegaList_Guids> Lists_Guids;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Save",DisplayName="Json: Named") TMap<FName, FJsonObjectWrapper> Prop_Json;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Save") TMap<FGameplayTag, int32> TagVars_int;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Preferences") TMap<UGamePreference*, FVector> PreferenceValues;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save",DisplayName="Flags (Common Save)") FOmegaBitflagsBase Flags;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Save") FJsonObjectWrapper JsonSaveObject;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Save") FJsonObjectWrapper LuaSavedTable;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Save") FGameplayTag StoryState;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Save") FGameplayTag SaveCategory;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Save") FGameplayTagContainer SaveTags;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame,Category="Save") FTimespan Playtime;
	
	//Soft Property
	UPROPERTY(EditAnywhere,Category="Properties") TMap<FName, bool> Prop_bool;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, float> Prop_float;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, int32> Prop_int;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, FString> Prop_string;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, FGameplayTag> Prop_Tag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, FGameplayTagContainer> Prop_Tags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, UPrimaryDataAsset*> Prop_Asset;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, FVector> Prop_Vector;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, FRotator> Prop_Rotator;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Properties") TMap<FName, FTransform> Prop_Transform;
	
	UFUNCTION(BlueprintPure, Category="Playtime")
	FString GetPlaytimeString(bool bIncludeMilliseconds);

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override {return SaveCategory;};
	
	UFUNCTION(BlueprintImplementableEvent, Category="Save")
	void OnSaveCreated(UGameInstance* GameInstance);
	
	// ======================================================================================
	// Json
	// ======================================================================================
	
	UFUNCTION(BlueprintCallable,Category="Save|BitFlag")
	void SetBitFlag(uint8 flag, bool value);
	UFUNCTION(BlueprintPure,Category="Save|BitFlag")
	bool GetBitFlag(uint8 flag);
	
	UFUNCTION(BlueprintCallable,Category="Save|BitFlag")
	void SetBitFlag_Named(FName key, uint8 flag, bool value);
	UFUNCTION(BlueprintPure,Category="Save|BitFlag")
	bool GetBitFlag_Named(FName key, uint8 flag);

	UFUNCTION(BlueprintCallable,Category="Save|BitFlag")
	void SetBitFlag_Guid(FGuid key, uint8 flag, bool value);
	UFUNCTION(BlueprintPure,Category="Save|BitFlag")
	bool GetBitFlag_Guid(FGuid key, uint8 flag);
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveGame : public UOmegaSaveBase
{
	GENERATED_BODY()

public:

	UPROPERTY() FString ActiveLevelName;
	UPROPERTY() FTransform SavedPlayerTransform;
	UPROPERTY() UOmegaZoneData* ActiveZone;
	
	UPROPERTY(BlueprintReadOnly, Category="Save")
	FDateTime SaveDate;

	UFUNCTION(BlueprintImplementableEvent, Category="Save")
	void OnGameStarted(FGameplayTagContainer Tags);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Save")
	FText GetDisplayName();

	UPROPERTY(BlueprintReadWrite, Category="Tags")
	TMap<TSoftObjectPtr<AActor>, FGameplayTag> ActorStates;
	
	UPROPERTY(BlueprintReadWrite, Category="Tags")
	TMap<TSoftObjectPtr<AActor>, FGameplayTagContainer> ActorTags;

	UPROPERTY(BlueprintReadOnly, Category="Save")
	UTexture2D* SaveScreenshot;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Save")
	TMap<FGameplayTag,UOmegaBGM*> BgmOverrides;

};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveGlobal : public UOmegaSaveBase
{
	GENERATED_BODY()

public:
};

// ====================================================================================================
// Save Conditions
// ====================================================================================================

UCLASS(BlueprintType, Blueprintable, Const, abstract, editinlinenew, hidecategories=Object, CollapseCategories,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaSaveCondition : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, Category="OmegaSaveCondition")
	bool CheckSaveCondition(UOmegaSaveSubsystem* SaveSubsystem) const;
};


UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaSaveConditionCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", instanced, EditAnywhere)
	TArray<UOmegaSaveCondition*> Conditions;
};


// ====================================================================================================
// Interface
// ====================================================================================================

// This class does not need to be modified.
UINTERFACE()
class UOmegaSaveInterface : public UInterface
{
	GENERATED_BODY()
};

class OMEGAGAMEFRAMEWORK_API IOmegaSaveInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save") bool OnGameFileSaved(UOmegaSaveGame* SaveFile);
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save") void OnGameFileStarted(UOmegaSaveGame* SaveFile);
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json") bool UseJsonSaveData();
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json") FString GetJsonPropertyName();
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json") FJsonObjectWrapper SaveJsonData(FJsonObjectWrapper CurrentData);
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json") bool LoadJsonData(FJsonObjectWrapper SaveFile);
};



// ====================================================================================================
// Story State
// ====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStoryStateAsset : public UOmegaDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="State")
	TArray<UOmegaStoryStateScript*> Scripts;
	
};

UCLASS(Blueprintable, Abstract, BlueprintType, CollapseCategories, EditInlineNew, meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaStoryStateScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category="State Script")
	bool CanActivateState(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State);

	UFUNCTION(BlueprintNativeEvent, Category="State Script")
	void OnStateBegin(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State);

	UFUNCTION(BlueprintNativeEvent, Category="State Script")
	void OnStateEnd(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State);

	UFUNCTION(BlueprintNativeEvent, Category="State Script")
	void OnLevelChange(UOmegaSaveSubsystem* SaveSubsystem, UOmegaStoryStateAsset* State, const FString& LevelName);
	
};