// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"


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
		void StartGame(class UOmegaSaveGame* GameData, FGameplayTagContainer Tags);

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
	
	//GameplayTags

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

	UFUNCTION()
	void SetSavedActorState(AActor* Actor, FGameplayTag StateTag);

	UFUNCTION()
	void AddSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	UFUNCTION()
	void RemoveSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	//###############################################################################################
	// Data Assets
	//###############################################################################################

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void SetDataAssetCollected(UPrimaryDataAsset* Asset, bool bGlobal, bool Collected);

	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void SetDataAssetsCollected(TArray<UPrimaryDataAsset*> Assets, bool bGlobal, bool Collected);
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void AddDataAssetToSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|Assets")
	void RemoveDataAssetFromSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets")
	bool IsDataAssetInSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssets(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsOfCategory(FGameplayTag CategoryTag, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|Assets", meta=(AdvancedDisplay="bExclude, bExact"))
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsWithTags(FGameplayTagContainer Tags, bool bGlobal, bool bExclude, bool bExact = true);
	
	//////////////
	// Soft Properties
	//////////////

		//bool
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Bool(const FString& Property, bool Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	bool GetSoftProperty_Bool(const FString& Property, bool bGlobal);
		//float
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Float(const FString& Property, float Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	float GetSoftProperty_Float(const FString& Property, bool bGlobal);
		//int
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Int32(const FString& Property, int32 Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	int32 GetSoftProperty_Int32(const FString& Property, bool bGlobal);
		//string
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_String(const FString& Property, FString Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	FString GetSoftProperty_String(const FString& Property, bool bGlobal);
		//tag
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Tag(const FString& Property, FGameplayTag Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	FGameplayTag GetSoftProperty_Tag(const FString& Property, bool bGlobal);
		//vec
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Vector(const FString& Property, FVector Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	FVector GetSoftProperty_Vector(const FString& Property, bool bGlobal);
		//rot
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Rotator(const FString& Property, FRotator Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	FRotator GetSoftProperty_Rotator(const FString& Property, bool bGlobal);
		//transform
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Transform(const FString& Property, FTransform Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	FTransform GetSoftProperty_Transform(const FString& Property, bool bGlobal);
		//transform
	UFUNCTION(BlueprintCallable, Category="Omega|SaveSubsystem|SoftProperties")
	void SetSoftProperty_DataAsset(const FString& Property, UPrimaryDataAsset* Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Omega|SaveSubsystem|SoftProperties")
	UPrimaryDataAsset* GetSoftProperty_DataAsset(const FString& Property, bool bGlobal);

	///MESSAGE LOGGING
	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem")
	bool CustomSaveConditionsMet(FOmegaSaveConditions Conditions);

	//###############################################################################################
	// SAVING
	//###############################################################################################
	
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem")
	void SaveObjectJsonData(UObject* Object);
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem")
	void LoadObjectJsonData(UObject* Object);

	UPROPERTY()
	TArray<UObject*> JsonSaveSources;
	
	UFUNCTION(BlueprintCallable, Category="OmegaSaveSubsystem")
	void SetSaveSourceRegistered(UObject* Source, bool Registered);

	UFUNCTION(BlueprintPure, Category="OmegaSaveSubsystem")
	TArray<UObject*> GetSaveSources();
};
