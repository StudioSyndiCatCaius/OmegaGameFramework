// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaSettings.h"
#include "JsonObjectWrapper.h"
#include "Misc/OmegaGameMode.h"
#include "OmegaSubsystem_GameManager.generated.h"

class UOmegaSettings;
class UOmegaGameSettings;
class UOmegaGameplayModule;

USTRUCT()
struct FGameplayLogEntry
{
	GENERATED_BODY()

	UPROPERTY()
	FString Log;
	UPROPERTY()
	FString LogCategory;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGlobalEvent, FName, Event, UObject*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTaggedGlobalEvent, FGameplayTag, Event, UObject*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNewLevel, FString, LevelName, AOmegaGameMode*, GameMode);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFlagStateChange, FString, Flag, bool, NewState);

UCLASS(Category = "OmegaSubsystems|Instance")
class OMEGAGAMEFRAMEWORK_API UOmegaGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Omega|Subsystem|Manager")
	FGameplayTagContainer StateTags;

	// Temp class holder for settings
	class TSubclassOf<UOmegaGameSettings> LocalSettingsClass;

	///GAMEPLAY MODULES

	UFUNCTION()
	UOmegaGameplayModule* ActivateModuleFromClass(const UClass* ModuleClass);
	
	UPROPERTY()
	TArray<UOmegaGameplayModule*> ActiveModules;
	
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle="Gameplay Module", DeterminesOutputType="Module"), Category="Omega|Game Manager")
	UOmegaGameplayModule* GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module);

	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle="Gameplay Modules", DeterminesOutputType="Module"), Category="Omega|Game Manager")
	TArray<UOmegaGameplayModule*> GetGameplayModules();
		
	UPROPERTY(BlueprintAssignable)
	FOnNewLevel OnNewLevel;
	
	//################################################################
	// Global Event
	//################################################################
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager", meta=(AdvancedDisplay="Context"),DisplayName="Fire Global Event (Name)")
	void FireGlobalEvent(FName Event, UObject* Context);
	
	UPROPERTY(BlueprintAssignable)
	FOnGlobalEvent OnGlobalEvent;
	
	UFUNCTION(BlueprintCallable, Category="Omega|Game Manager", meta=(AdvancedDisplay="Context"),DisplayName="Fire Global Event (Tag)")
	void FireTaggedGlobalEvent(FGameplayTag Event, UObject* Context);
	
	UPROPERTY(BlueprintAssignable)
	FOnTaggedGlobalEvent OnTaggedGlobalEvent;
	
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

	//################################################################
	// GlobalJson
	//################################################################

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="OmegaGameManager|GlobalJson")
	FJsonObjectWrapper GlobalJsonObject;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLuaValue LuaGameInstanceData;
	
	//UFUNCTION(BlueprintCallable, Category="OmegaGameManager|GlobalJson", meta = (CustomStructureParam = "Value", AutoCreateRefTerm = "Value"))
	//bool SetGlobalJsonProperty(const FString& Property, const int32& Value);

	//UFUNCTION(BlueprintCallable, Category="OmegaGameManager|GlobalJson", meta = (CustomStructureParam = "OutValue", AutoCreateRefTerm = "OutValue"))
	//bool GetGlobalJsonProperty(const FString& Property, int32& OutValue);
	
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
	

	
};
