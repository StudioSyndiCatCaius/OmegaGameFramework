// Copyright Studio Syndicat 2021. All Rights Reserved.

// GAME PREFERENCES: Options that can be modified by the end-user to customize their gameplay experience. (E.G. Graphics, Sound, Controls, etc)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Engine/DataAsset.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "OmegaSubsystem_GamePreferences.generated.h"

// ============================================================================================================
// Preference Asset
// ============================================================================================================

UENUM(BlueprintType)
enum class EGamePreferenceType : uint8
{
	PrefType_Bool		UMETA(DisplayName = "Bool"),
	PrefType_Float		UMETA(DisplayName = "Float"),
	PrefType_Int        UMETA(DisplayName = "Int"),
	PrefType_String		UMETA(DisplayName = "Option"),
};

UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreference : public UPrimaryDataAsset, public IGameplayTagsInterface, public IDataInterface_General
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General",DisplayName="Name")	FText PrefernceName;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")	FString PreferenceLabel;

	//Should the value be saved/loaded from the "OmegaPreferences.ini" file?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")	bool bSaveToConfig;
	
	//Is this preference saved globally save file?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")	bool bGlobal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")		FGameplayTag PreferenceCategory;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")		FGameplayTagContainer PreferenceTags;


	UFUNCTION(BlueprintCallable,Category="Preference")
	EGamePreferenceType GetPreferenceType() const;
	UFUNCTION(BlueprintCallable,Category="Preference")
	TArray<FString> GetPreferenceStringOptions() const;
	//#############################################
	// SCRIPT
	//#############################################
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "General")
	UGamePreferenceScript* PreferenceScript;
	
//Interface

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
		FGameplayTag GetObjectGameplayCategory();
		virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
		FGameplayTagContainer GetObjectGameplayTags();
		virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();

	//Texts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralDataText(const FString& Label, const class UObject* Context,	FText& Name, FText& Description);
	virtual void GetGeneralDataText_Implementation(const FString& Label, const class UObject* Context, FText& Name, FText& Description) override;

	//AssetLabel
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Data|General")
	void GetGeneralAssetLabel(FString& Label);
	virtual void GetGeneralAssetLabel_Implementation(FString& Label);
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
	
	UFUNCTION(BlueprintNativeEvent, Category="Preference")
	void OnPreferenceValueUpdated(UGameUserSettings* GameSettings, FVector Value) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Preference",DisplayName="Get Value (Default)")
	FVector GetDefaultValue() const;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Preference",DisplayName="Get Value (Max)")
	FVector GetMaxValue() const;
	
	UFUNCTION(BlueprintNativeEvent, Category="Preference",DisplayName="Override Value (Current)")
	FVector GetCurrentValue(FVector Value) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	FText GetValueText(FVector Value) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	FString GetValueString(FVector Value) const;
	
	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	TArray<FString> GetValueStringOptions() const;
};

inline void UGamePreferenceScript::OnPreferenceValueUpdated_Implementation(UGameUserSettings* GameSettings, FVector Value) const
{
	
}

// ============================================================================================================
// Preference Types
// ============================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPreferenceUpdated, class UGamePreference*, Preference, FVector, Value);

UCLASS(DisplayName="Omega Subsystem: Preferences")
class OMEGAGAMEFRAMEWORK_API UGamePreferenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	FString ConfigFilePath = FConfigCacheIni::NormalizeConfigIniPath(FPaths::ProjectConfigDir() + TEXT("/OmegaPreferences.ini")); 
protected:

	void PreloadPrefs();

	UPROPERTY() TArray<UGamePreference*> PreloadedPreferences;

	UFUNCTION() void local_SetPref(UGamePreference* Preference, FVector value);
	UFUNCTION() FVector local_GetPref(UGamePreference* Preference);
	UFUNCTION() UOmegaSaveSubsystem* GetSaveSubsystem();
	UFUNCTION() void Local_PreferenceUpdate(class UGamePreference* Preference);
	UFUNCTION() void Local_PreferenceUpdateAll();
	
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	
	UPROPERTY(BlueprintAssignable,Category="Preferences") FOnPreferenceUpdated OnPreferenceUpdated;

	UFUNCTION(BlueprintPure, Category="Omega|GamePreferences|Subsystem")
	TArray<UGamePreference*> GetAllGamePreferences();
	
	//Bool
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences|Subsystem",DisplayName="Get Game preference (As Bool)")
	bool GetGamePreferenceBool(class UGamePreference* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences|Subsystem",DisplayName="Set Game preference (As Bool)")
	void SetGamePreferenceBool(class UGamePreference* Preference, bool bValue);
	
	//Float
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences",DisplayName="Get Game preference (As Float)")
	float GetGamePreferenceFloat(class UGamePreference* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences",DisplayName="Set Game preference (As Float)")
	void SetGamePreferenceFloat(class UGamePreference* Preference, float Value);
	

	//Float
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences",DisplayName="Get Game preference (As Int)")
		int32 GetGamePreferenceInt(class UGamePreference* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences",DisplayName="Set Game preference (As Int)")
		void SetGamePreferenceInt(class UGamePreference* Preference, int32 Value);


	//String
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences",DisplayName="Get Game preference (As String)")
	FString GetGamePreference_String(class UGamePreference* Preference);

	
	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences",DisplayName="Set Game preference (As String)")
	void SetGamePreference_String(class UGamePreference* Preference, FString Value);

	
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences",DisplayName="Get Game preference (As Text)")
	FText GetGamePreference_Text(class UGamePreference* Preference);

};

// ========================================================================================================================
// Function Lib
// ========================================================================================================================

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaPreferencesFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	 
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs = "Outcome"),DisplayName="Ω🔴 Check Preference (Bool)")
	static bool CheckGamePreference_Bool(const UObject* WorldContextObject, UGamePreference* Preference, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega Gameplay", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome"),DisplayName="Ω🔴 Check Preference (Int)")
	static int32 CheckGamePreference_Int(const UObject* WorldContextObject, UGamePreference* Preference, int32 CheckValue, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome);

};