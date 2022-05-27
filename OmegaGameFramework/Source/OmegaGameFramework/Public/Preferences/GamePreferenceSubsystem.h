// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayTagContainer.h"

#include "GamePreferenceSubsystem.generated.h"

class UOmegaSaveSubsystem;
class UGamePreferenceFloat;
class UGamePreferenceBool;
class UGamePreferenceString;
class UGamePreferenceTag;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceBoolUpdated, class UGamePreferenceBool*, Preference, bool, bValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceFloatUpdated, class UGamePreferenceFloat*, Preference, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceIntUpdated, class UGamePreferenceInt*, Preference, int32, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceStringUpdated, class UGamePreferenceString*, Preference, FString, bValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefernceTagUpdated, class UGamePreferenceTag*, Preference, FGameplayTag, Value);

/**
 * 
 */

UCLASS()
class OMEGAGAMEFRAMEWORK_API UGamePreferenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Colection) override;
	//virtual void Deinitialize() override;

	//UPROPERTY()
	//UOmegaSaveSubsystem* SaveSubsystemRef;

	UFUNCTION()
	UOmegaSaveSubsystem* GetSaveSubsystem();

	//Bool
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences")
		bool GetGamePreferenceBool(class UGamePreferenceBool* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences")
		void SetGamePreferenceBool(class UGamePreferenceBool* Preference, bool bValue);

	UPROPERTY()
		TMap<class UGamePreferenceBool*, bool> BoolPrefs;

	UPROPERTY(BlueprintAssignable)
		FOnPrefernceBoolUpdated OnBoolPreferenceUpdated;

	//Float
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences")
		float GetGamePreferenceFloat(class UGamePreferenceFloat* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences")
		void SetGamePreferenceFloat(class UGamePreferenceFloat* Preference, float Value);

	UPROPERTY()
		TMap<class UGamePreferenceFloat*, float> FloatPrefs;

	UPROPERTY(BlueprintAssignable)
		FOnPrefernceFloatUpdated OnFloatPreferenceUpdated;

	//Float
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences")
		int32 GetGamePreferenceInt(class UGamePreferenceInt* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences")
		void SetGamePreferenceInt(class UGamePreferenceInt* Preference, int32 Value);

	UPROPERTY()
	TMap<class UGamePreferenceInt*, int32> IntPrefsList;

	UPROPERTY(BlueprintAssignable)
	FOnPrefernceIntUpdated OnIntPreferenceUpdated;
	
	//String
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences")
		FString GetGamePreferenceString(class UGamePreferenceString* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences")
		void SetGamePreferenceString(class UGamePreferenceString* Preference, const FString& Value);

	UPROPERTY(BlueprintAssignable)
		FOnPrefernceStringUpdated OnStringPreferenceUpdated;

	//Tag
	UFUNCTION(BlueprintPure, Category = "Omega|GamePreferences")
		FGameplayTag GetGamePreferenceTag(class UGamePreferenceTag* Preference);

	UFUNCTION(BlueprintCallable, Category = "Omega|GamePreferences")
		void SetGamePreferenceTag(class UGamePreferenceTag* Preference, FGameplayTag Value);

	UPROPERTY(BlueprintAssignable)
		FOnPrefernceTagUpdated OnTagPreferenceUpdated;


};
