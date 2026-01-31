// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "JsonObjectWrapper.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_SoftParams.h"
#include "Subsystem_GameManager.generated.h"

class UOmegaSettings;
class UOmegaGameSettings;
class UOmegaGameplayModule;
class AOmegaGameMode;
class UOmegaMod;

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
	
	UOmegaGameplayModule* ModuleInit(UOmegaGameplayModule* NewModule);
	
protected:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	virtual void Deinitialize() override;
	void OnLevelChanged(UWorld* World, const UWorld::InitializationValues);


public:
	
	UPROPERTY() TArray<UOmegaMod*> ModList;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Omega|Subsystem|Manager")
	FGameplayTagContainer StateTags;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Omega") FOmegaEntitySet Entities;
	
	UPROPERTY() FOmegaSoftParams GlobalVars;
	class TSubclassOf<UOmegaGameSettings> LocalSettingsClass;
	
	UFUNCTION() UOmegaGameplayModule* ActivateModuleFromClass(const UClass* ModuleClass);
	
	UPROPERTY() TArray<UOmegaGameplayModule*> ActiveModules;
	
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
