// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "OmegaSettings.h"
#include "OmegaGameSettings.h"
#include "Gameplay/OmegaGameMode.h"

#include "OmegaGameManager.generated.h"

class UOmegaSettings;
class UOmegaGameSettings;
class UOmegaGameplayModule;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalEvent, FName, Event, UObject*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewLevel, FString, LevelName, AOmegaGameMode*, GameMode);
/**
 * 
 */
UCLASS(Category = "OmegaSubsystems|Instance")
class OMEGAGAMEFRAMEWORK_API UOmegaGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

public:
		UPROPERTY(BlueprintReadOnly, Category = "Ω|Settings")
		class UOmegaGameSettings* CustomGameSettings;

		// Temp class holder for settings
		class TSubclassOf<UOmegaGameSettings> LocalSettingsClass;

	///GAMEPLAY MODULES
	///
		UPROPERTY()
		TArray<UOmegaGameplayModule*> ActiveModules;
	
		UFUNCTION(BlueprintPure, meta = (CompactNodeTitle="Gameplay Module", DeterminesOutputType="Module"), Category="Ω|GameManager")
		UOmegaGameplayModule* GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module);

	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle="Gameplay Modules", DeterminesOutputType="Module"), Category="Ω|GameManager")
		TArray<UOmegaGameplayModule*> GetGameplayModules();

	UFUNCTION(BlueprintCallable, Category="Ω|GameManager", meta=(AdvancedDisplay="Context"))
	void FireGlobalEvent(FName Event, UObject* Context);
	
	UPROPERTY(BlueprintAssignable)
	FOnGlobalEvent OnGlobalEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnNewLevel OnNewLevel;

	//Flags
	UPROPERTY(BlueprintReadOnly, Category="Ω|GameManager")
	TArray<FString> Flags;

	UFUNCTION(BlueprintCallable, Category="Ω|GameManager")
	void SetFlagActive(FString Flag, bool bActive);
	/*
	// Playtime
	UPROPERTY(BlueprintReadOnly, Category="Ω|Playtime")
	FTimecode Playtime;

	UFUNCTION(BlueprintCallable, Category="Ω|Playtime")
	void SetPlaytimeActive(bool bActive);

	UPROPERTY(BlueprintReadOnly, Category="Ω|Playtime")
	bool bIsPlaytimeActive;

	UFUNCTION(BlueprintCallable, Category="Ω|Playtime")
	void ResetPlaytime();

	UPROPERTY()
	FTimerHandle PlaytimeUpdateHandle;

	UFUNCTION()
	void UpdatePlaytime();
*/
};
