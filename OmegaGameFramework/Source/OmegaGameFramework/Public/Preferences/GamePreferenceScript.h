// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/Object.h"
#include "GamePreferenceScript.generated.h"

class UGamePreference;
class UGamePreferenceSubsystem;
UCLASS(Blueprintable, BlueprintType, EditInlineNew, Const)
class OMEGAGAMEFRAMEWORK_API UGamePreferenceScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category="Preference")
	void OnPreferenceValueUpdated(UGameUserSettings* GameSettings, int32 Value) const;
};

inline void UGamePreferenceScript::OnPreferenceValueUpdated_Implementation(UGameUserSettings* GameSettings, int32 Value) const
{
	
}


