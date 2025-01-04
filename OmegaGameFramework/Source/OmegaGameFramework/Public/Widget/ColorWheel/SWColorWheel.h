// Copyright (c) W2.Wizard 2020-2021. All Rights Reserved.
// modified code of SColorWheel, Original by Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

// Core Include
#include "CoreMinimal.h"
#include "Widgets/SLeafWidget.h"

// Misc Includes
#include "Misc/Attribute.h"
#include "Input/Reply.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Framework/SlateDelegates.h"
#include "Rendering/DrawElements.h"
#include "Styling/CoreStyle.h"
#include "Widget/ColorWheel/ColorWheelHelper.h"

class FPaintArgs;
class FSlateWindowElementList;
struct FSlateBrush;

DECLARE_DELEGATE_OneParam(FOnPositionChanged, FVector2D)

// Used for some of the Color wheels UFUNCTIONS to specify the target brush.
UENUM()
enum EWheelBrushTarget
{
    // Apply brush to pin and wheel
    All,

    // Apply only to the pin
    SelectorPin,

    // Apply only to the wheel
    HueCircle
};

/**
 * Just like SColorWheel except it adds a slate argument for the selector pin to be changed
 * 
 * @Note: Because someone thought hardcoding it is reasonable?
 */
class OMEGAGAMEFRAMEWORK_API SWColorWheel : public SLeafWidget
{
public:

    SLATE_BEGIN_ARGS(SWColorWheel)
        : _SelectedColor()
        , _SelectorPin()
        , _HueCircle()
        , _OnMouseCaptureBegin()
        , _OnMouseCaptureEnd()
        , _OnValueChanged()
        , _OnPositionChanged()
        { }

        /// Attributes ///
    
        /** The current color selected by the user. */
        SLATE_ATTRIBUTE(FLinearColor, SelectedColor)

        /// Arguments ///
    
        /** The brush used for the selector pin */
        SLATE_ARGUMENT(const FSlateBrush*, SelectorPin)
    
        /** The brush used for the selector HueCircle */
        SLATE_ARGUMENT(const FSlateBrush*, HueCircle)

        /// Events ///
    
        /** Invoked when the mouse is pressed and a capture begins. */
        SLATE_EVENT(FSimpleDelegate, OnMouseCaptureBegin)

        /** Invoked when the mouse is released and a capture ends. */
        SLATE_EVENT(FSimpleDelegate, OnMouseCaptureEnd)

        /** Invoked when a new value is selected on the color wheel. */
        SLATE_EVENT(FOnLinearColorValueChanged, OnValueChanged)

        /** Invoked when a new value is selected on the widget wheel. */
        SLATE_EVENT(FOnPositionChanged, OnPositionChanged);

    SLATE_END_ARGS()

public:

    /**
     * Construct this widget.
     *
     * @param InArgs The declaration data for this widget.
     */
    void Construct(const FArguments& InArgs);
	
    /** See the ColorAndOpacity attribute */
    void SetColorAndOpacity(FLinearColor InColorAndOpacity, TEnumAsByte<EWheelBrushTarget> TargetBrush);
    
#pragma region Overrides
    
    // SWidget overrides
    virtual FVector2D ComputeDesiredSize(float) const override;
    
    virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;
    
    virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
    
    virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
    
    virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
    
    virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
                          FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
                          bool bParentEnabled) const override;

#pragma endregion Overrides
    
protected:

    /**
     * Calculates the position of the color selection indicator.
     *
     * @return The position relative to the widget.
     */
    FVector2D CalcRelativePositionFromCenter() const;

    /**
     * Performs actions according to mouse click / move
     *
     * @return True if the mouse action occurred within the color wheel radius
     */
    bool ProcessMouseAction(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent, bool bProcessWhenOutsideColorWheel);

private:

    /** The color wheel image to show. */
    const FSlateBrush* Image;
    
    /** The color selector pin brush */
    const FSlateBrush* SelectorImage;
    
    /** The current color selected by the user. */
    TAttribute<FLinearColor> SelectedColor;

    /** Color and opacity scale for the selector pin */
    TAttribute<FSlateColor> PinColorAndOpacity = FLinearColor::White;

    /** Color and opacity scale for the hue circle */
    TAttribute<FSlateColor> HueCircleColorAndOpacity = FLinearColor::White;


private:

    /** Invoked when the mouse is pressed and a capture begins. */
    FSimpleDelegate OnMouseCaptureBegin;

    /** Invoked when the mouse is let up and a capture ends. */
    FSimpleDelegate OnMouseCaptureEnd;

    /** Invoked when a new value is selected on the color wheel. */
    FOnLinearColorValueChanged OnValueChanged;

	/** Invoked when a new value is selected on the color wheel. */
    FOnPositionChanged OnPositionChanged;
    
};
