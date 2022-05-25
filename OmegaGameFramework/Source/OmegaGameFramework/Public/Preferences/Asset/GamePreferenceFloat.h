// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Preferences/GamePreference.h"
#include "GamePreferenceFloat.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class OMEGAGAMEFRAMEWORK_API UGamePreferenceFloat : public UGamePreference
{
	GENERATED_BODY()
	
public:

	UGamePreferenceFloat();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	float DefaultValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	float MaxValue = 1.0;
};
