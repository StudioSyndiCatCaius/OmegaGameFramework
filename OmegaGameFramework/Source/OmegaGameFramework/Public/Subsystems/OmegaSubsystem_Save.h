// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "Engine/World.h"
#include "JsonObjectWrapper.h"
#include "LuaValue.h"
#include "Misc/Paths.h"
#include "Misc/Timespan.h"
#include "GameFramework/SaveGame.h"
#include "Misc/OmegaUtils_Structs.h"
#include "OmegaSubsystem_Save.generated.h"

class UOmegaSaveBase;
class UOmegaSaveGame;
class UOmegaSaveGlobal;
class UOmegaSaveCondition;
class UOmegaZoneData;
class UGamePreference;

// ====================================================================================================
// ENUMS
// ====================================================================================================
UENUM(BlueprintType)
enum class ELevelOpenType : uint8
{
	LvlOp_None		UMETA(DisplayName = "N/A"),
	LvlOp_Save		UMETA(DisplayName = "Saved"),
	LvlOp_Custom	UMETA(DisplayName = "Custom"),
};

UENUM(BlueprintType)
enum class EUniqueSaveFormats : uint8
{
	SaveFormat_Quicksave		UMETA(DisplayName = "Quicksave"),
	SaveFormat_Autosave			UMETA(DisplayName = "Autosave"),
	
};

UENUM(BlueprintType)
enum EBoolType 
{
	BoolType_And     UMETA(DisplayName = "All True"),
	BoolType_Or      UMETA(DisplayName = "One True"),
	BoolType_NONE     UMETA(DisplayName = "None True"),
};


USTRUCT(BlueprintType)
struct FOmegaSaveConditions
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="OmegaSaveConditions")
	TEnumAsByte<EBoolType> CheckType;
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", instanced, EditAnywhere)
	TArray<class UOmegaSaveCondition*> Conditions;
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", EditAnywhere)
	TArray<class UOmegaSaveConditionCollection*> ConditionCollections;
};

// ====================================================================================================
// Subsystem
// ====================================================================================================
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewGameStarted, UOmegaSaveGame*, NewGame);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSaveStateChanged, FGameplayTag, NewState, bool, bGlobal);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSaveTagsEdited, FGameplayTagContainer, EditedTags, bool, Added, bool, bGlobal);

UCLASS(DisplayName = "Omega Subsystem: Save")
class OMEGAGAMEFRAMEWORK_API UOmegaSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;
	void OnLevelChanged(UWorld* World, const UWorld::InitializationValues);
	
	UFUNCTION(BlueprintPure, Category = "Omega|SaveSubsystem")
	void GetSaveSlotName(int32 Slot, FString& OutName);

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
	TArray<UOmegaSaveGame*> GetSaveSlotList(int32 FirstIndex, int32 LastIndex = 1);

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem|Load",DisplayName="Load Game Object (From Slot)")
	UOmegaSaveGame* LoadGame(int32 Slot, bool& Success);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem|Load",DisplayName="Load Game Object (From Name)")
	UOmegaSaveGame* LoadGame_Named(FString Slot, bool& Success);
    	
	//###############################################################################################
	// Playtime
	//###############################################################################################
	UFUNCTION()
	void OnPlaytimeUpdate();

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem")
	FTimespan GetSavePlaytime(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem")
	FString GetSavePlaytimeString(bool bGlobal, bool bIncludeMilliseconds);
	//###############################################################################################
	// SAVING
	//###############################################################################################
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem", DisplayName="Save Game (Unique Format)")
	bool SaveGameUnique(EUniqueSaveFormats Format);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem",DisplayName="Save Active Game (To Slot)")
	void SaveActiveGame(int32 Slot,FGameplayTag SaveCategory, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem",DisplayName="Save Active Game (To Name)")
	void SaveActiveGame_Named(FString Slot,FGameplayTag SaveCategory, bool& Success);

	
	UFUNCTION()
	bool Local_SaveGame(FString SlotName,FGameplayTag SaveCategory);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
		UOmegaSaveGame* CreateNewGame();

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem", meta = (AdvancedDisplay = "Tags"))
		void StartGame(class UOmegaSaveGame* GameData, bool LoadSavedLevel, FGameplayTagContainer Tags);

	UPROPERTY(BlueprintReadOnly, Category = "Omega|SaveSubsystem")
		class UOmegaSaveGame* ActiveSaveData;
	UPROPERTY(BlueprintReadOnly, Category = "Omega|SaveSubsystem")
		class UOmegaSaveGlobal* GlobalSaveData;

private:

	void Local_InitializeSaveObjects();
	void local_SaveLuaFields(TArray<FString> fields, UOmegaSaveBase* save);
	void local_LoadLuaFields(TArray<FString> fields, UOmegaSaveBase* save);
	
	UPROPERTY()
	bool Local_JsonSave;

public:
	
	UFUNCTION()
	UOmegaSaveBase* GetSaveObject(bool Global);

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

	UFUNCTION()
	void SetSavedActorState(AActor* Actor, FGameplayTag StateTag);

	UFUNCTION()
	void AddSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	UFUNCTION()
	void RemoveSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	//Clears the state tag from any actors with the given state.
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Actor", meta=(Keywords="remove"))
	void ClearSavedStateFromActors(FGameplayTag SavedState);

	//###############################################################################################
	// Data Assets
	//###############################################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"))
	void SetDataAssetCollected(UPrimaryDataAsset* Asset, bool bGlobal, bool Collected);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"))
	void SetDataAssetsCollected(TArray<UPrimaryDataAsset*> Assets, bool bGlobal, bool Collected);
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"))
	void AddDataAssetToSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"))
	void RemoveDataAssetFromSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bGlobal"))
	bool IsDataAssetInSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssets(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsOfCategory(FGameplayTag CategoryTag, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bExclude, bExact"))
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsWithTags(FGameplayTagContainer Tags, bool bGlobal, bool bExclude, bool bExact = true);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void SetSaveTagsOnDataAsset(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bHasTags, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void AddSaveTagsToDataAsset(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void RemoveSaveTagsFromDataAsset(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bGlobal);
	
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets")
	bool DoesDataAssetHaveSaveTags(UPrimaryDataAsset* Asset, FGameplayTagContainer Tags, bool bExact, bool bGlobal);

	//###############################################################################################
	// Guids
	//###############################################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"))
	void SetGuidCollected(FGuid Guid, bool Collected, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"))
	bool GetIsGuidCollected(FGuid Guid, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"))
	void SetGuidHasTags(FGuid Guid, FGameplayTagContainer Tags, bool HasTags, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|GUID", meta=(AdvancedDisplay="bGlobal"))
	bool GetDoesGuidHaveTags(FGuid Guid, FGameplayTagContainer Tags, bool bGlobal);
	
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
	// GuiSon
	//###############################################################################################
	
	
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
	
	UPROPERTY()
	TArray<UOmegaStoryStateAsset*> ActiveStoryStates;
	
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem|StoryState")
	void SetStoryStateActive(UOmegaStoryStateAsset* State, bool bActive,bool bGlobalSave);

	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem|StoryState")
	void ClearAllStoryStates(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem|StoryState")
	bool IsStoryStateActive(UOmegaStoryStateAsset* State);

	//###############################################################################################
	// Dynamic Variables
	//###############################################################################################

	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem|StoryState", meta=(AdvancedDisplay="bGlobal"))
	void SetDynamicVariableValue(UOmegaDynamicSaveVariable* Variable, int32 value, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem|StoryState", meta=(AdvancedDisplay="bGlobal"))
	int32 GetDynamicVariableValue(UOmegaDynamicSaveVariable* Variable, bool bGlobal);
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

	//Displays this actor only if the the save state is one of the given tags.
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
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame) FGuid SaveGuid;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, SaveGame) int32 SaveSeed;
	UPROPERTY(SaveGame) FOmegaGlobalVarsContainer GlobalVars;
	UPROPERTY(BlueprintReadOnly, Category="Playtime") FTimespan Playtime;

	UFUNCTION(BlueprintPure, Category="Playtime")
	FString GetPlaytimeString(bool bIncludeMilliseconds);

	UFUNCTION()
	void Local_OnLoaded();
	
	UPROPERTY(SaveGame)
	TArray<UOmegaStoryStateAsset*> ActiveStoryStates;
	
	//GamePreferences
	UPROPERTY(EditAnywhere,Category="Preferences")
	TMap<UGamePreference*, FVector> PreferenceValues;

	//olf pref values. will be removed long term
	UPROPERTY()
	TMap<class UGamePreferenceBool*, bool> BoolPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceFloat*, float> FloatPrefs;
	UPROPERTY()
	TMap<class UPrimaryDataAsset*, FString> StringPrefs;
	UPROPERTY()
	TMap<class UPrimaryDataAsset*, FGameplayTag> TagPrefs;
	UPROPERTY()
	TMap<class UGamePreferenceInt*, int32> IntPrefs;

	//
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Omega|Save")
	FJsonObjectWrapper JsonSaveObject;
	UPROPERTY(BlueprintReadWrite, Category="Omega|Save")
	FLuaValue LuaSaveData;
	
	//Tags
	UPROPERTY(EditAnywhere,BlueprintReadOnly, DisplayName="Save State", Category="Omega|Save")
	FGameplayTag StoryState;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, DisplayName="Save State", Category="Omega|Save")
	FGameplayTag SaveCategory;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, DisplayName="Save Tags", Category="Omega|Save")
	FGameplayTagContainer StoryTags;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override {return SaveCategory;};
	
	//DataAssets
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save")
	TArray<UPrimaryDataAsset*> CollectedDataAssets;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save")
	TMap<UPrimaryDataAsset*, FGameplayTagContainer> SaveAssetTags;

	//DataAssets
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save")
	TArray<FGuid> CollectedGuids;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save")
	TMap<FGuid, FGameplayTagContainer> GuidTags;


	
	//Soft Property
	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, bool> Prop_bool;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Bool(const FString& Name, bool Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	bool GetSaveProperty_Bool(const FString& Name);
	
	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, float> Prop_float;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Float(const FString& Name, float Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	float GetSaveProperty_Float(const FString& Name);
	
	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, int32> Prop_int;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Int(const FString& Name, int32 Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	int32 GetSaveProperty_Int(const FString& Name);
	
	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, FString> Prop_string;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_String(const FString& Name, const FString& Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FString GetSaveProperty_String(const FString& Name);
	
	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, FGameplayTag> Prop_Tag;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Tag(const FString& Name, FGameplayTag Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FGameplayTag GetSaveProperty_Tag(const FString& Name);

	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, FGameplayTagContainer> Prop_Tags;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Tags(const FString& Name, FGameplayTagContainer Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FGameplayTagContainer GetSaveProperty_Tags(const FString& Name);
	
	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FName, UPrimaryDataAsset*> Prop_Asset;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Asset(const FString& Name, UPrimaryDataAsset* Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	UPrimaryDataAsset* GetSaveProperty_Asset(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FVector> Prop_Vector;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Vector(const FString& Name, FVector Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FVector GetSaveProperty_Vector(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FRotator> Prop_Rotator;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Rotator(const FString& Name, FRotator Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FRotator GetSaveProperty_Rotator(const FString& Name);
	
	UPROPERTY()
	TMap<FName, FTransform> Prop_Transform;
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Transform(const FString& Name, FTransform Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FTransform GetSaveProperty_Transform(const FString& Name);

	// ======================================================================================
	// Json
	// ======================================================================================

	// JsonSave : FName
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save",DisplayName="Json: Named") TMap<FName, FJsonObjectWrapper> Prop_Json;
	// JsonSave : Guid
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save",DisplayName="Json: Guid") TMap<FGuid, FJsonObjectWrapper> GuidJson;
	// JsonSave : DataAsset
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Omega|Save",DisplayName="Json: DataAsset") TMap<UPrimaryDataAsset*, FJsonObjectWrapper> DataAsset_Json;
	
	UFUNCTION(BlueprintCallable, Category="OmegaSave")
	void SetSaveProperty_Json(const FString& Name, FJsonObjectWrapper Value);
	UFUNCTION(BlueprintPure, Category="OmegaSave")
	FJsonObjectWrapper GetSaveProperty_Json(const FString& Name);
	
	UPROPERTY()
	TMap<UOmegaDynamicSaveVariable*, FString> DynamicVariableValues;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveGame : public UOmegaSaveBase
{
	GENERATED_BODY()

public:

	// UPROPERTY(BlueprintReadOnly, Category="Playtime")
	// FTimecode SavedPlaytime;
	
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

	UPROPERTY(EditAnywhere,Category="Save")
	TMap<FString,FString> bgm_styles;
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

UCLASS(BlueprintType, Blueprintable, Const, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSaveCondition : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(Transient)
	mutable UWorld* WorldPrivate = nullptr;
	
	UOmegaSaveCondition(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	
	UFUNCTION(BlueprintNativeEvent, Category="OmegaSaveCondition")
	bool CheckSaveCondition(UOmegaSaveSubsystem* SaveSubsystem) const;
};


UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaSaveConditionCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", instanced, EditAnywhere)
	TArray<class UOmegaSaveCondition*> Conditions;
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

/**
 * 
 */
class OMEGAGAMEFRAMEWORK_API IOmegaSaveInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:

	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save")
	bool OnGameFileSaved(UOmegaSaveGame* SaveFile);

	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save")
	void OnGameFileStarted(UOmegaSaveGame* SaveFile);


	// JSON
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	bool UseJsonSaveData();
	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	FString GetJsonPropertyName();
	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	FJsonObjectWrapper SaveJsonData(FJsonObjectWrapper CurrentData);
	
	UFUNCTION(BlueprintNativeEvent, Category ="Omega|Save|Json")
	bool LoadJsonData(FJsonObjectWrapper SaveFile);
};

// ====================================================================================================
// Dynamic Save Variable
// ====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicSaveVariable : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Description")
	FSlateBrush Icon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FText VariableDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FGameplayTagContainer GameplayTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="General")
	TArray<UOmegaDynamicSaveVariableState*> States;
	
};

UCLASS(EditInlineNew,Blueprintable,BlueprintType,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicSaveVariableState : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FString StateLabel;
};


// ====================================================================================================
// Story State
// ====================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaStoryStateAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="State")
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="State")
	FText SateDescription;

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