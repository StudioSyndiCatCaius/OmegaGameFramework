// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DA_AssetLib.h"
#include "Functions/F_Component.h"
#include "Functions/F_Preferences.h"
#include "GameFramework/Character.h"
#include "Misc/GeneralDataObject.h"
#include "DA_GamePreference.generated.h"

class UComboBoxString;
class UComboBox;

UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreference : public UOmegaDataAsset
{
	GENERATED_BODY()
public:
	
	FVector L_GetValue(const UOmegaSubsystem_GameInstance* subsys, UOmegaSaveBase* save);
	void L_SetValue(const UOmegaSubsystem_GameInstance* subsys, UOmegaSaveBase* save,FVector _Value);
	
	UFUNCTION(BlueprintCallable,Category="Preference",meta=(WorldContext="WorldContextObject"))
	void Configure_ComboBox(UObject* WorldContextObject, UComboBoxString* Widget);
	
	//Should the value be saved/loaded from the "OmegaPreferences.ini" file?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General") bool bSaveToConfig;
	
	//Is this preference saved globally save file?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General") bool bGlobal;


	UFUNCTION(BlueprintCallable,Category="Preference")
	EGamePreferenceType GetPreferenceType() const;
	UFUNCTION(BlueprintCallable,Category="Preference")
	TArray<FString> GetPreferenceStringOptions() const;
	//#############################################
	// SCRIPT
	//#############################################
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "General")
	UGamePreferenceScript* PreferenceScript;
	
};

// ============================================================================================================
// Preference Script
// ============================================================================================================
UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UGamePreferenceScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Preference")
	EGamePreferenceType GetPreferenceType() const;
	
	UFUNCTION(BlueprintNativeEvent, Category="Preference",DisplayName="Set Value (OVERRIDE)")
	void OnPreferenceValueUpdated(const UOmegaSubsystem_GameInstance* subsys, UOmegaSaveBase* save, UGamePreference* Preference, FVector Value) const;

	UFUNCTION(BlueprintNativeEvent, Category="Preference",DisplayName="Get Value (OVERRIDE)")
	FVector GetCurrentValue(const UOmegaSubsystem_GameInstance* subsystem, UOmegaSaveBase* save, UGamePreference* Preference) const;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Preference",DisplayName="Get Value (Default)")
	FVector GetDefaultValue() const;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Preference",DisplayName="Get Value (Max)")
	FVector GetMaxValue() const;
	
	
	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	FText GetValueText(FVector Value) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	FString GetValueString(FVector Value) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	TArray<FString> GetValueStringOptions() const;
};
