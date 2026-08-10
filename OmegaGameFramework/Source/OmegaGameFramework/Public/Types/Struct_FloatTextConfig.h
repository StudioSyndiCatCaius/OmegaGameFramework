
#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetTextLibrary.h"
#include "Runtime/Launch/Resources/Version.h"
#include "UObject/SoftObjectPtr.h"
#include "Struct_FloatTextConfig.generated.h"

class UMaterialInterface;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FOmegaFloatTextConfig
{
	GENERATED_BODY()

	// Rounding rule used when formatting XP values for display in widgets.
	UPROPERTY(EditAnywhere, Category="Widget")
	TEnumAsByte<ERoundingMode> RoundingMode = ERoundingMode::HalfToEven;

	// When true, always show a sign (+ or -) on displayed XP values.
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bAlwaysSign;
	// When true, digit grouping separators (e.g. commas) are used in displayed values.
	UPROPERTY(EditAnywhere, Category="Widget")
	bool bUseGrouping = true;

	// Minimum number of digits shown before the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinIntegralDigits = 1;
	// Maximum number of digits shown before the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxIntegralDigits = 324;
	// Minimum number of digits shown after the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MinFractionalDigits;
	// Maximum number of digits shown after the decimal point.
	UPROPERTY(EditAnywhere, Category="Widget")
	int32 MaxFractionalDigits = 0;

	/** Rounds Value to MaxFractionalDigits using RoundingMode. */
	float RoundValue(float Value) const
	{
		const int32 FracDigits = FMath::Max(0, MaxFractionalDigits);
		const double Scale = FMath::Pow(10.0, FracDigits);
		const double Scaled = static_cast<double>(Value) * Scale;

		double Rounded = 0.0;
		switch (RoundingMode.GetValue())
		{
		case ERoundingMode::HalfFromZero:
			Rounded = FMath::RoundHalfFromZero(Scaled);
			break;
		case ERoundingMode::HalfToZero:
			Rounded = FMath::RoundHalfToZero(Scaled);
			break;
		case ERoundingMode::FromZero:
			Rounded = FMath::RoundFromZero(Scaled);
			break;
		case ERoundingMode::ToZero:
			Rounded = FMath::RoundToZero(Scaled);
			break;
		case ERoundingMode::ToNegativeInfinity:
			Rounded = FMath::RoundToNegativeInfinity(Scaled);
			break;
		case ERoundingMode::ToPositiveInfinity:
			Rounded = FMath::RoundToPositiveInfinity(Scaled);
			break;
		case ERoundingMode::HalfToEven:
		default:
			Rounded = FMath::RoundHalfToEven(Scaled);
			break;
		}

		return static_cast<float>(Rounded / Scale);
	}

	/** Formats Value as FText using this config's rounding and digit options. */
	FText ToText(float Value) const
	{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 7
		return UKismetTextLibrary::Conv_FloatToText(
			Value, RoundingMode, bAlwaysSign, bUseGrouping,
			MinIntegralDigits, MaxIntegralDigits, MinFractionalDigits, MaxFractionalDigits);
#else
		return UKismetTextLibrary::Conv_DoubleToText(
			Value, RoundingMode, bAlwaysSign, bUseGrouping,
			MinIntegralDigits, MaxIntegralDigits, MinFractionalDigits, MaxFractionalDigits);
#endif
	}
};