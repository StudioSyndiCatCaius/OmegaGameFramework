// Copyright (c) W2.Wizard 2020-2021. All Rights Reserved.

#pragma once

// Core
#include "CoreMinimal.h"
#include "Components/Widget.h"

// Misc
#include "SWColorWheel.h"
#include "Styling/CoreStyle.h"
#include "ColorWheelHelper.h"

// Generated.h
#include "ColorWidget.generated.h"

class SWColorWheel;

/*
   Delegate: Broadcasted when a color change has occured.
   Param 1: FLinearColor | The new Color that has been set.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FColorChangedEvent, const FLinearColor&, NewColor);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPositionUpdatedEvent, const FVector2D&, NewPosition);

/** Delegate: Broadcasted when the mouse is down on the Wheel. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMouseDownEvent);

/** Delegate: Broadcasted when the mouse is lifted from the Wheel. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMouseUpEvent);

/**
 * A simple color wheel that can be used to select a specific color using a Pin
 *
 * * No Children
 */
UCLASS(meta=(DisplayName="Color Wheel"))
class OMEGAGAMEFRAMEWORK_API UColorWidget final : public UWidget
{
	GENERATED_BODY()

public:

	/*============================================================================\
	|                                Properties                                   |
	\============================================================================*/

	/** The image used for the pin */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FSlateBrush SelectorPin = *FCoreStyle::Get().GetBrush("ColorWheel.Selector");

	/** The image used for the wheel */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Style")
	FSlateBrush HueCircle = *FCoreStyle::Get().GetBrush("ColorWheel.HueValueCircle");
	
	/*============================================================================\
	|                                  Events                                     |
	\============================================================================*/
	
	/** Event called when color value is changed */
	UPROPERTY(BlueprintAssignable, Category="Color Wheel|Event")
	FColorChangedEvent OnColorChanged;

	/** Event called when value is changed */
	UPROPERTY(BlueprintAssignable, Category = "Color Wheel|Event")
	FPositionUpdatedEvent OnPositionChanged;

	/** Event called when the mouse is being pressed on the wheel */
	UPROPERTY(BlueprintAssignable, Category="Color Wheel|Event")
	FMouseDownEvent OnMouseDown;

	/** Event called when the mouse is being lifted from the wheel */
	UPROPERTY(BlueprintAssignable, Category="Color Wheel|Event")
	FMouseUpEvent OnMouseUp;

	/*============================================================================\
	|                            Blueprint Functions                              |
	\============================================================================*/
	
	/**
	*	Sets the color of the colorwheel
	*	@param NewColor			A new linear color value
	*/
	UFUNCTION(BlueprintCallable, Category = "Color Wheel|Functions", meta=(DisplayName="Set Color", Keywords = "set color wheel"))
    void SetColor(const FLinearColor NewColor);

	/**
	*	Gets the color of the colorwheel
	*	@return 				The current color of the colorwheel
	*/
	UFUNCTION(BlueprintPure, Category = "Color Wheel|Functions", meta=(DisplayName="Get Color", Keywords = "get color wheel"))
    FLinearColor GetCurrentColor();

	///Generics///
	
	/** Sets the color and opacity of the specified brush */
	UFUNCTION(BlueprintCallable, Category = "Appearance")
    void SetColorAndOpacity(FLinearColor InColorAndOpacity, TEnumAsByte<EWheelBrushTarget> Target);

	/*============================================================================\
	|                          Misc Unreal Engine Slate                           |
	\============================================================================*/
	
protected:
	
	// Construct the widget
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	// Destroy the widget
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	
#if WITH_EDITOR
	
	// For the editor to set the name category in the Widget Explorer.
	virtual inline const FText GetPaletteCategory() override { return NSLOCTEXT("Input", "Input", "Input"); };
	
#endif
	
	/*============================================================================\
	|                              Private Variables                              |
	\============================================================================*/
	
private:

	/*
	 * TODO: Hack to avoid inactive colorwheel.
	 * In order to avoid a issue where when we detect that the color is completely null we send in a false value to the color wheel
	 * while when we retrieve the value we return actually the null value.
	 *
	 * For now this helps avoid this issue, but I must look deeper into it.
	 */
	bool IsNull;
	
	// Shared Ptr to the colorwheel.
	TSharedPtr<SWColorWheel> ColorWheel;

	// Default color the widget gets constructed with.
	FLinearColor Color = FLinearColor::White;

	// Callback Function: Handles the broadcasting of the delegate once a color changes.
	void OnValueChanged(FLinearColor NewValue);

	void OnPositionUpdated(FVector2D NewPosition);

	// Callback Function: Handles the broadcasting for when the Mouse is lifted from the wheel.
	inline void MouseUp() { OnMouseUp.Broadcast(); };

	// Callback Function: Handles the broadcasting once the Mouse is held down on the wheel.
	inline void MouseDown()  { OnMouseDown.Broadcast(); };

	// Callback Function: For when the widget gets constructed, passes the color, gets set on line 102.
	inline FLinearColor GetColor() const { return Color.LinearRGBToHSV(); };


};
