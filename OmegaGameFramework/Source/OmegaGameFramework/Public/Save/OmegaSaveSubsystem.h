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

UENUM()
enum class ELevelOpenType : uint8
{
	LvlOp_None		UMETA(DisplayName = "N/A"),
	LvlOp_Save		UMETA(DisplayName = "Saved"),
	LvlOp_Custom	UMETA(DisplayName = "Custom"),
};


UCLASS(DisplayName = "OmegaSaveSubsystem")
class OMEGAGAMEFRAMEWORK_API UOmegaSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()	

public:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure, Category = "Ω|SaveSubsystem")
	void GetSaveSlotName(int32 Slot, FString& OutName);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveSubsystem")
	TArray<UOmegaSaveGame*> GetSaveSlotList(int32 FirstIndex, int32 LastIndex = 1);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveSubsystem")
		UOmegaSaveGame* LoadGame(int32 Slot, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveSubsystem")
		void SaveActiveGame(int32 Slot, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveSubsystem")
		UOmegaSaveGame* CreateNewGame();

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveSubsystem", meta = (AdvancedDisplay = "Tags"))
		void StartGame(class UOmegaSaveGame* GameData, FGameplayTagContainer Tags);

	UPROPERTY(BlueprintReadOnly, Category = "Ω|SaveSubsystem")
		class UOmegaSaveGame* ActiveSaveData;

	UPROPERTY(BlueprintReadOnly, Category = "Ω|SaveSubsystem")
		class UOmegaSaveGlobal* GlobalSaveData;

	UPROPERTY()
	bool Local_JsonSave;
	
	UFUNCTION()
	UOmegaSaveBase* GetSaveObject(bool Global);
	
	//GameplayTags

	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|Tags", DisplayName="Set Save State")
	void SetStoryState(FGameplayTag StateTag, bool Global);
	
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|Tags")
	FGameplayTag GetSaveState(bool Global);
	
	UFUNCTION(BlueprintCallable, DisplayName="Add Save Tags", Category="Ω|SaveSubsystem|Tags")
	void AddStoryTags(FGameplayTagContainer Tags, bool Global);

	UFUNCTION(BlueprintCallable, DisplayName="Remove Save Tags", Category="Ω|SaveSubsystem|Tags")
	void RemoveStoryTags(FGameplayTagContainer Tags, bool Global);

	UFUNCTION(BlueprintPure, DisplayName="Get Active Save Tags", Category="Ω|SaveSubsystem|Tags")
	FGameplayTagContainer GetStoryTags(bool Global);

	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|Tags")
	bool SaveTagsMatchQuery(FGameplayTagQuery Query, bool Global);

	UFUNCTION()
	void SetSavedActorState(AActor* Actor, FGameplayTag StateTag);

	UFUNCTION()
	void AddSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	UFUNCTION()
	void RemoveSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	//DataAssets
	
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|Assets")
	void AddDataAssetToSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|Assets")
	void RemoveDataAssetFromSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|Assets")
	bool IsDataAssetInSaveCollection(UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|Assets")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssets(bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|Assets")
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsOfCategory(FGameplayTag CategoryTag, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|Assets", meta=(AdvancedDisplay="bExclude, bExact"))
	TArray<UPrimaryDataAsset*> GetCollectedDataAssetsWithTags(FGameplayTagContainer Tags, bool bGlobal, bool bExclude, bool bExact = true);
	
	//////////////
	// Soft Properties
	//////////////

		//bool
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Bool(FName Property, bool Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	bool GetSoftProperty_Bool(FName Property, bool bGlobal);
		//float
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Float(FName Property, float Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	float GetSoftProperty_Float(FName Property, bool bGlobal);
		//int
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Int32(FName Property, int32 Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	int32 GetSoftProperty_Int32(FName Property, bool bGlobal);
		//string
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_String(FName Property, FString Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	FString GetSoftProperty_String(FName Property, bool bGlobal);
		//tag
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Tag(FName Property, FGameplayTag Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	FGameplayTag GetSoftProperty_Tag(FName Property, bool bGlobal);
		//vec
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Vector(FName Property, FVector Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	FVector GetSoftProperty_Vector(FName Property, bool bGlobal);
		//rot
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Rotator(FName Property, FRotator Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	FRotator GetSoftProperty_Rotator(FName Property, bool bGlobal);
		//transform
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_Transform(FName Property, FTransform Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	FTransform GetSoftProperty_Transform(FName Property, bool bGlobal);
		//transform
	UFUNCTION(BlueprintCallable, Category="Ω|SaveSubsystem|SoftProperties")
	void SetSoftProperty_DataAsset(FName Property, UPrimaryDataAsset* Value, bool bGlobal);
	UFUNCTION(BlueprintPure, Category="Ω|SaveSubsystem|SoftProperties")
	UPrimaryDataAsset* GetSoftProperty_DataAsset(FName Property, bool bGlobal);
};
