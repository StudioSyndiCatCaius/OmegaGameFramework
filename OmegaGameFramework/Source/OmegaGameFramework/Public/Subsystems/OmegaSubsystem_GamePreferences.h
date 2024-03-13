// Copyright Studio Syndicat 2021. All Rights Reserved.

// GAME PREFERENCES: Options that can be modified by the end-user to customize their gameplay experience. (E.G. Graphics, Sound, Controls, etc)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Engine/DataAsset.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "OmegaSubsystem_GamePreferences.generated.h"

// ============================================================================================================
// Preference Asset
// ============================================================================================================

UENUM(BlueprintType)
enum class EGamePreferenceType : uint8
{
	PrefType_Bool        UMETA(DisplayName = "Bool"),
	PrefType_Float        UMETA(DisplayName = "Float"),
	PrefType_Int        UMETA(DisplayName = "Int"),
	PrefType_String        UMETA(DisplayName = "String"),
	PrefType_Tag        UMETA(DisplayName = "Tag"),
};

UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreference : public UPrimaryDataAsset, public IGameplayTagsInterface, public IDataInterface_General
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
	FText PrefernceName;

	UPROPERTY(BlueprintReadOnly, Category="GamePreference")
	EGamePreferenceType PreferenceType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
	FString PreferenceLabel;

	//Is this preference saved globally save file?
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
	bool bGlobal;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
	FGameplayTag PreferenceCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Tags")
	FGameplayTagContainer PreferenceTags;

	//#############################################
	// SCRIPT
	//#############################################
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "General")
	UGamePreferenceScript* PreferenceScript;
	
//Interface

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
		FGameplayTag GetObjectGameplayCategory();
		virtual FGameplayTag GetObjectGameplayCategory_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameplayTags")
		FGameplayTagContainer GetObjectGameplayTags();
		virtual FGameplayTagContainer GetObjectGameplayTags_Implementation();
		
		
	//DataInterface

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

	UFUNCTION(BlueprintNativeEvent, Category="Preference")
	void OnPreferenceValueUpdated(UGameUserSettings* GameSettings, FVector Value) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Preference")
	FVector GetDefaultValue() const;
};

inline void UGamePreferenceScript::OnPreferenceValueUpdated_Implementation(UGameUserSettings* GameSettings, FVector Value) const
{
	
}

// ============================================================================================================
// Preference Types
// ============================================================================================================

UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreferenceBool : public UGamePreference
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bool")
	bool bDefaultValue;
};

UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreferenceFloat : public UGamePreference
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	float DefaultValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	float MaxValue = 1.0;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UGamePreferenceInt : public UGamePreference
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	int32 DefaultValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	int32 MaxValue = 1;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceBoolUpdated, class UGamePreferenceBool*, Preference, bool, bValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceFloatUpdated, class UGamePreferenceFloat*, Preference, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceIntUpdated, class UGamePreferenceInt*, Preference, int32, Value);

UCLASS(DisplayName="Omega Subsystem: Preferences")
class OMEGAGAMEFRAMEWORK_API UGamePreferenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:

	void PreloadPrefs();

	UFUNCTION()
	void local_SetPref(UGamePreference* Preference, FVector value);
	UFUNCTION()
	FVector local_GetPref(UGamePreference* Preference);
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	//virtual void Deinitialize() override;

	UPROPERTY()
	TArray<UGamePreference*> PreloadedPreferences;
	
	UFUNCTION(BlueprintPure, Category="Omega|GamePreferences|Subsystem")
	TArray<UGamePreference*> GetAllGamePreferences();
	
	UFUNCTION()
	UOmegaSaveSubsystem* GetSaveSubsystem();

	UFUNCTION()
	void Local_PreferenceUpdate(class UGamePreference* Preference);
	UFUNCTION()
	void Local_PreferenceUpdateAll();
	
	//Bool
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences|Subsystem",DisplayName="Get Game preference (As Bool)")
		bool GetGamePreferenceBool(class UGamePreference* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences|Subsystem",DisplayName="Set Game preference (As Bool)")
		void SetGamePreferenceBool(class UGamePreference* Preference, bool bValue);

	UPROPERTY()
		TMap<class UGamePreferenceBool*, bool> BoolPrefs;

	UPROPERTY(BlueprintAssignable)
		FOnPrefernceBoolUpdated OnBoolPreferenceUpdated;

	//Float
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences",DisplayName="Get Game preference (As Float)")
		float GetGamePreferenceFloat(class UGamePreference* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences",DisplayName="Set Game preference (As Float)")
		void SetGamePreferenceFloat(class UGamePreference* Preference, float Value);

	UPROPERTY()
		TMap<class UGamePreferenceFloat*, float> FloatPrefs;

	UPROPERTY(BlueprintAssignable)
		FOnPrefernceFloatUpdated OnFloatPreferenceUpdated;

	//Float
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences",DisplayName="Get Game preference (As Int)")
		int32 GetGamePreferenceInt(class UGamePreference* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences",DisplayName="Set Game preference (As Int)")
		void SetGamePreferenceInt(class UGamePreference* Preference, int32 Value);

	UPROPERTY()
	TMap<class UGamePreferenceInt*, int32> IntPrefsList;

	UPROPERTY(BlueprintAssignable)
	FOnPrefernceIntUpdated OnIntPreferenceUpdated;

};

