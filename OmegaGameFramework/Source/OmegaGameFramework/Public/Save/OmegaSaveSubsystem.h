// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Components/ActorComponent.h"
#include "Misc/Paths.h"
#include "Misc/Timespan.h"
#include "OmegaSaveSubsystem.generated.h"

class UOmegaSaveBase;
class UOmegaSaveGame;
class UOmegaSaveGlobal;
class UOmegaSaveCondition;

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
	BoolType_And     UMETA(DisplayName = "AND"),
	BoolType_Or      UMETA(DisplayName = "OR"),
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSaveStateChanged, FGameplayTag, NewState, bool, bGlobal);


UCLASS(DisplayName = "Omega Subsystem: Save")
class OMEGAGAMEFRAMEWORK_API UOmegaSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure, Category = "Omega|SaveSubsystem")
	void GetSaveSlotName(int32 Slot, FString& OutName);

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
	TArray<UOmegaSaveGame*> GetSaveSlotList(int32 FirstIndex, int32 LastIndex = 1);

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
	UOmegaSaveGame* LoadGame(int32 Slot, bool& Success);
	
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
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
	void SaveActiveGame(int32 Slot, bool& Success);

	UFUNCTION()
	bool Local_SaveGame(FString SlotName);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem")
		UOmegaSaveGame* CreateNewGame();

	UFUNCTION(BlueprintCallable, Category = "Omega|SaveSubsystem", meta = (AdvancedDisplay = "Tags"))
		void StartGame(class UOmegaSaveGame* GameData, bool LoadSavedLevel, FGameplayTagContainer Tags);

	UPROPERTY(BlueprintReadOnly, Category = "Omega|SaveSubsystem")
		class UOmegaSaveGame* ActiveSaveData;

	UPROPERTY(BlueprintReadOnly, Category = "Omega|SaveSubsystem")
		class UOmegaSaveGlobal* GlobalSaveData;

	UPROPERTY()
	bool Local_JsonSave;
	
	UFUNCTION()
	UOmegaSaveBase* GetSaveObject(bool Global);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem")
	void SaveGlobalGame();

	//###############################################################################################
	// SAVING
	//###############################################################################################
	/*
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem", meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"))
	bool SetJsonSaveProperty(const FString& Property, const int32& Value, bool Global);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem", meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"))
	bool GetJsonSaveProperty(const FString& Property, int32& Value, bool Global);
	*/
	
	//GameplayTags

	UPROPERTY(BlueprintAssignable)
	FOnSaveStateChanged OnSaveStateChanged;
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Tags", DisplayName="Set Save State")
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
	// SAVING
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
	
};


UCLASS( ClassGroup=("Omega Game Framework"), DisplayName="Save State Manager", meta=(BlueprintSpawnableComponent) )
class OMEGAGAMEFRAMEWORK_API UOmegaSaveStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UFUNCTION()
	void LocalStateChanged(FGameplayTag TagState, bool bGlobal);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	bool bGlobalSave;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	FGameplayTagContainer VisibleOnStateTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	FGameplayTagContainer HiddenOnStateTags;
};