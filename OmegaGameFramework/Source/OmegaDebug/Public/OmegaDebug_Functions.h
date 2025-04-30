// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OmegaDebug_Functions.generated.h"


class UOmegaQuest;
class UGamePreference;

// ====================================================================================================================================
// Profile
// ====================================================================================================================================
UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract,Const,meta=(ShowWorldContextPin))
class UOmegaDebugProfileScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="DebugProfile")
	void OnProfileBegin(UOmegaDebugSubsystem* Subsystem) const;

};



UCLASS()
class UOmegaDebugProfile : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Category="Quests")
	bool bAutostartQuests;
	UPROPERTY(EditAnywhere,Category="Quests")
	TArray<TSoftObjectPtr<UOmegaQuest>> QuestsToAutostart;
	
	UPROPERTY(EditAnywhere,Category="Save")
	FGameplayTagContainer AutoSaveTags;
	
	UPROPERTY(EditAnywhere,Instanced,Category="DebugProfile")
	TArray<UOmegaDebugProfileScript*> Scripts;

};


// ====================================================================================================================================
// Settings
// ====================================================================================================================================
UCLASS()
class UOmegaSettings_Debug : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Profile")
	bool bRunDebugProfile;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Profile")
	UOmegaDebugProfile* DefaultSettingsProfile;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Settings")
    TArray<TSoftObjectPtr<UGamePreference>> DebugPreferences;
};

// ====================================================================================================================================
// DEV Settings
// ====================================================================================================================================
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Debug"))
class UOmegaDebugDevSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaSettings_Debug"))
	FSoftObjectPath DefaultSettings_Debug;

	UOmegaSettings_Debug* GetDefaultSettings() const
	{
		if(UObject* o=DefaultSettings_Debug.TryLoad())
		{
			return Cast<UOmegaSettings_Debug>(o);
		}
		return nullptr;
	}
};


// ====================================================================================================================================
// Subsystem
// ====================================================================================================================================
UCLASS()
class UOmegaDebugSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|Debug")
	void StartDebugProfile(UOmegaDebugProfile* Profile);

	UFUNCTION(BlueprintCallable,Category="Omega|Debug")
	void StartDebugProfile_Default();
};


// ====================================================================================================================================
// Functions
// ====================================================================================================================================
UCLASS()
class UOmegaDebugsFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Debug")
	static UOmegaSettings_Debug* GetOmegaDebugSettings();

};


