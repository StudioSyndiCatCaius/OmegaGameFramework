// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/GeneralDataObject.h"
#include "UObject/Interface.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "Types/Struct_FloatTextConfig.h"
#include "Component_Leveling.generated.h"

class UCurveFloat;

// Defines an XP/level progression curve and display formatting for a single type of leveling (e.g. combat rank, crafting skill).
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaLevelingAsset : public UOmegaDataAsset
{
	GENERATED_BODY()

public:

	// Display name shown in UI for this XP type (e.g. "Experience", "Crafting XP").
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FText XPName;

	// The highest level achievable on this leveling track.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	int32 MaxRank = 100;

	// Curve that maps XP value to level; the X axis is XP and the Y axis is the corresponding level.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FRuntimeFloatCurve ValueCurve;

	// Returns the level that corresponds to the given raw XP value.
	UFUNCTION(BlueprintPure, Category = "Leveling")
	int32 GetLevelFromXP(float XP);

	// Returns the minimum and maximum XP bounds for the given level.
	UFUNCTION(BlueprintPure, Category = "Leveling")
	void GetXPFromLevel(int32 Level, float& MinLevelXP, float& MaxLevelXP);

	FText GetTextFromValue(float Value) const;

	float CorrectXpValue(float Value) const;
	
	UPROPERTY(EditAnywhere, Category="Leveling")
	FOmegaFloatTextConfig ValueConfig;
};

