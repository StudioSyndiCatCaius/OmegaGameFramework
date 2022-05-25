// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Preferences/GamePreference.h"
#include "GamePreferenceString.generated.h"

/**
 * 
 */
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
};
