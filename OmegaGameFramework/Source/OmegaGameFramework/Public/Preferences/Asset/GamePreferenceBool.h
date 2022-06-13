// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Preferences/GamePreference.h"
#include "GamePreferenceBool.generated.h"

class UGamePreferenceSubsystem;
class UCheckBox;

UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreferenceBool : public UGamePreference
{
	GENERATED_BODY()

public:

	UGamePreferenceBool();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bool")
	bool bDefaultValue;

	UFUNCTION(BlueprintCallable, Category="GamePreference Bool")
	void ApplyToCheckBox(UGamePreferenceSubsystem* Subsystem, UCheckBox* CheckBox);
};
