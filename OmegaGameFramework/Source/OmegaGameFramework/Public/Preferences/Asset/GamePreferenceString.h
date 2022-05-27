// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ComboBoxString.h"
#include "Preferences/GamePreference.h"
#include "GamePreferenceString.generated.h"

class UGamePreferenceSubsystem;
class UComboBoxString;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UGamePreferenceString : public UGamePreference
{
	GENERATED_BODY()
	
public:

	UGamePreferenceString();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Value")
	FString DefaultValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Value")
	TArray<FString> Options;

	UFUNCTION(BlueprintCallable, Category="GamePreference String")
	void ApplyToComboBox(UGamePreferenceSubsystem* Subsystem, UComboBoxString* ComboBox);

};
