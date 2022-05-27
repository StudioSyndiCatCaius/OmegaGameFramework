// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Preferences/GamePreference.h"
#include "GamePreferenceTag.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UGamePreferenceTag : public UGamePreference
{
	GENERATED_BODY()
	
public:

	UGamePreferenceTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Value")
	FGameplayTag DefaultValue;
};
