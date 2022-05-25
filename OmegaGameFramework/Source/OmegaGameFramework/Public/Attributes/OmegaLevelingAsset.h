// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Curves/CurveFloat.h"
#include "OmegaLevelingAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaLevelingAsset : public UDataAsset
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling", DisplayName="Level Name")
	FText RankName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FText XPName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	int32 MaxRank = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Leveling")
	FRuntimeFloatCurve ValueCurve;

	UFUNCTION(BlueprintPure, Category = "Leveling")
	int32 GetLevelFromXP(float XP);

	UFUNCTION(BlueprintPure, Category = "Leveling")
	void GetXPFromLevel(int32 Level, float& MinLevelXP, float& MaxLevelXP);

	///Widget
	UPROPERTY(EditAnywhere, Category="Widget")
	TEnumAsByte<ERoundingMode> RoundingMode = ERoundingMode::HalfToEven;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bAlwaysSign;
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bUseGrouping = true;
	
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinIntegralDigits = 1;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxIntegralDigits = 324;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinFractionalDigits;
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxFractionalDigits = 0;
};
