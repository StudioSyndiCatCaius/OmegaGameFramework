/*
	This code was written by Nick Darnell
	
	Plugin created by Rama
*/
#pragma once

#include "Engine/DeveloperSettings.h"
#include "Curves/CurveFloat.h"
#include "Curves/RichCurve.h"
#include "OmegaInputSettings.generated.h"

class FOmegaAnalogCursor;

UCLASS(config=Game, defaultconfig, DisplayName="Omega: Input")
class OMEGAINPUT_API UOmegaInputSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	//#################################################################################################################
	// ANALOG INPUT
	//#################################################################################################################
	UOmegaInputSettings()
	{
		MaxAnalogCursorSpeed = 1300.0f;
		MaxAnalogCursorSpeedWhenHovered = 650.0f;
		AnalogCursorDragCoefficient = 8.0f;
		AnalogCursorDragCoefficientWhenHovered = 14.0f;
		MinAnalogCursorSpeed = 5.0f;
		AnalogCursorDeadZone = 0.15f;
		AnalogCursorAccelerationMultiplier = 9000.0f;
		AnalogCursorSize = 40.0f;

		AnalogCursorAccelerationCurve.EditorCurveData.AddKey(0, 0);
		AnalogCursorAccelerationCurve.EditorCurveData.AddKey(1, 1);
	}

	FORCEINLINE const FRichCurve* GetAnalogCursorAccelerationCurve() const
	{
		return AnalogCursorAccelerationCurve.GetRichCurveConst();
	}
	
	FORCEINLINE float GetMaxAnalogCursorSpeed() const
	{
		return MaxAnalogCursorSpeed;
	}

	FORCEINLINE float GetMaxAnalogCursorSpeedWhenHovered() const
	{
		return MaxAnalogCursorSpeedWhenHovered;
	}

	FORCEINLINE float GetAnalogCursorDragCoefficient() const
	{
		return FMath::Min<float>(AnalogCursorDragCoefficientWhenHovered, AnalogCursorDragCoefficient);
	}

	FORCEINLINE float GetAnalogCursorDragCoefficientWhenHovered() const
	{
		return FMath::Max<float>(AnalogCursorDragCoefficientWhenHovered, AnalogCursorDragCoefficient);
	}

	FORCEINLINE float GetMinAnalogCursorSpeed() const
	{
		return MinAnalogCursorSpeed;
	}

	FORCEINLINE float GetAnalogCursorAccelerationMultiplier() const
	{
		return AnalogCursorAccelerationMultiplier;
	}

	FORCEINLINE float GetAnalogCursorDeadZone() const
	{
		return AnalogCursorDeadZone;
	}

	FORCEINLINE float GetAnalogCursorSize() const
	{
		return FMath::Max<float>(AnalogCursorSize, 1.0f);
	}

	FORCEINLINE FVector2D GetAnalogCursorSizeVector() const
	{
		return FVector2D(GetAnalogCursorSize(), GetAnalogCursorSize());
	}

	FORCEINLINE float GetAnalogCursorRadius() const
	{
		return GetAnalogCursorSize() / 2.0f;
	}

	FORCEINLINE bool GetUseEngineAnalogCursor() const
	{
		return bUseEngineAnalogCursor;
	}

	FORCEINLINE bool GetAnalogCursorNoAcceleration() const
	{
		return bAnalogCursorNoAcceleration;
	}

	FORCEINLINE void SetAnalogCursor(TSharedPtr<FOmegaAnalogCursor> InAnalogCursor)
	{
		AnalogCursor = InAnalogCursor;
	}

	FORCEINLINE TSharedPtr<FOmegaAnalogCursor> GetAnalogCursor() const
	{
		return AnalogCursor.Pin();
	}

private:
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta=(
		XAxisName="Strength",
		YAxisName="Acceleration" ))
	FRuntimeFloatCurve AnalogCursorAccelerationCurve;

	/** The max speed of the Analog Cursor */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "1.0"))
	float MaxAnalogCursorSpeed;

	/** The max speed of the Analog Cursor when hovering over a widget that is interactable */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "1.0"))
	float MaxAnalogCursorSpeedWhenHovered;

	/** The coefficient of drag applied to the cursor */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "0.0"))
	float AnalogCursorDragCoefficient;

	/** The coefficient of drag applied to the cursor when hovering */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "0.0"))
	float AnalogCursorDragCoefficientWhenHovered;

	/** The min speed of the analog cursor. If it goes below this value, the speed is set to 0. */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "0.0"))
	float MinAnalogCursorSpeed;

	/** Deadzone value for input from the analog stick */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float AnalogCursorDeadZone;

	/** Multiplied by the value spit out by the normalized acceleration curve */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "1.0"))
	float AnalogCursorAccelerationMultiplier;

	/** The size (on screen) of the analog cursor */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor", meta = (ClampMin = "1.0", ClampMax = "128.0"))
	float AnalogCursorSize;

	/** If true, defaults to the Engine's Analog Cursor */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor")
	bool bUseEngineAnalogCursor;

	/** If True, AnalogCursorAccelerationCurve will be used as a Velocity Curve */
	UPROPERTY(config, EditAnywhere, Category = "Analog Cursor")
	bool bAnalogCursorNoAcceleration;

	// Analog Cursor
	TWeakPtr<FOmegaAnalogCursor> AnalogCursor;
};