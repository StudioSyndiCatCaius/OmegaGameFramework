// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"

#include "OmegaSaveSubsystem.generated.h"

class UOmegaSaveGame;
class OmegaSaveGlobal;

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

	UFUNCTION(BlueprintPure, Category = "Ω|SaveLoad")
	void GetSaveSlotName(int32 Slot, FString& OutName);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveLoad")
	TArray<UOmegaSaveGame*> GetSaveSlotList(int32 FirstIndex, int32 LastIndex = 1);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveLoad")
		UOmegaSaveGame* LoadGame(int32 Slot, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveLoad")
		void SaveActiveGame(int32 Slot, bool& Success);

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveLoad")
		UOmegaSaveGame* CreateNewGame();

	UFUNCTION(BlueprintCallable, Category = "Ω|SaveLoad", meta = (AdvancedDisplay = "Tags"))
		void StartGame(class UOmegaSaveGame* GameData, FGameplayTagContainer Tags);

	UPROPERTY(BlueprintReadOnly, Category = "Save")
		class UOmegaSaveGame* ActiveSaveData;

	UPROPERTY(BlueprintReadOnly, Category = "Save")
		class UOmegaSaveGlobal* GlobalSaveData;

	//GameplayTags

	UFUNCTION(BlueprintCallable, Category="Ω|SaveLoad|Tags")
	void SetStoryState(FGameplayTag StateTag);

	UFUNCTION(BlueprintCallable, Category="Ω|SaveLoad|Tags")
	void AddStoryTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="Ω|SaveLoad|Tags")
	void RemoveStoryTags(FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="Ω|SaveLoad|Tags")
	void SetSavedActorState(AActor* Actor, FGameplayTag StateTag);

	UFUNCTION(BlueprintCallable, Category="Ω|SaveLoad|Tags")
	void AddSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	UFUNCTION(BlueprintCallable, Category="Ω|SaveLoad|Tags")
	void RemoveSavedActorTags(AActor* Actor, FGameplayTagContainer Tags);

	
};
