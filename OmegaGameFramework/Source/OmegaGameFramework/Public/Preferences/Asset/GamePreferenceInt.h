// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Preferences/GamePreference.h"
#include "GamePreferenceInt.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UGamePreferenceInt : public UGamePreference
{
	GENERATED_BODY()

	UGamePreferenceInt();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	int32 DefaultValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Float")
	int32 MaxValue = 1;
};
