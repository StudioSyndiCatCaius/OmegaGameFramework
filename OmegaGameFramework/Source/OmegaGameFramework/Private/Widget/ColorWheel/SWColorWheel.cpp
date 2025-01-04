// Copyright (c) W2.Wizard 2020-2021. All Rights Reserved.
// modified code of SColorWheel, Original by Copyright Epic Games, Inc. All Rights Reserved.

#include "Widget/ColorWheel/SWColorWheel.h"

/*===========================================================================*\
|                                Construct                                    |
\*===========================================================================*/

void SWColorWheel::Construct(const FArguments& InArgs)
{
	// Arguments passed onto the slate widget
	Image = InArgs._HueCircle;
	SelectorImage = InArgs._SelectorPin;
	SelectedColor = InArgs._SelectedColor;
	OnMouseCaptureBegin = InArgs._OnMouseCaptureBegin;
	OnMouseCaptureEnd = InArgs._OnMouseCaptureEnd;
	OnValueChanged = InArgs._OnValueChanged;
	OnPositionChanged = InArgs._OnPositionChanged;
}

void SWColorWheel::SetColorAndOpacity(FLinearColor InColorAndOpacity, TEnumAsByte<EWheelBrushTarget> TargetBrush)
{
	// TODO: Perhaps clean this up in some way?
	switch (TargetBrush)
	{
		case All:
			SetAttribute(HueCircleColorAndOpacity, TAttribute<FSlateColor>(InColorAndOpacity), EInvalidateWidgetReason::None);
			SetAttribute(PinColorAndOpacity, TAttribute<FSlateColor>(InColorAndOpacity), EInvalidateWidgetReason::Paint);
			break;

		case SelectorPin:
			SetAttribute(PinColorAndOpacity, TAttribute<FSlateColor>(InColorAndOpacity), EInvalidateWidgetReason::Paint);
			break;

		case HueCircle:
			SetAttribute(HueCircleColorAndOpacity, TAttribute<FSlateColor>(InColorAndOpacity), EInvalidateWidgetReason::Paint);
			break;
	}
}

/*===========================================================================*\
|                                Overrides                                    |
\*===========================================================================*/

FVector2D SWColorWheel::ComputeDesiredSize(float) const
{
	return Image->ImageSize + SelectorImage->ImageSize;
}

FReply SWColorWheel::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply SWColorWheel::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		OnMouseCaptureBegin.ExecuteIfBound();

		if (!ProcessMouseAction(MyGeometry, MouseEvent, false))
		{
			OnMouseCaptureEnd.ExecuteIfBound();
			return FReply::Unhandled();
		}

		return FReply::Handled().CaptureMouse(SharedThis(this));
	}

	return FReply::Unhandled();
}

FReply SWColorWheel::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && HasMouseCapture())
	{
		OnMouseCaptureEnd.ExecuteIfBound();

		return FReply::Handled().ReleaseMouseCapture();
	}

	return FReply::Unhandled();
}

FReply SWColorWheel::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!HasMouseCapture()) return FReply::Unhandled();

	ProcessMouseAction(MyGeometry, MouseEvent, true);

	return FReply::Handled();
}

int32 SWColorWheel::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const bool bIsEnabled = ShouldBeEnabled(bParentEnabled);
	const ESlateDrawEffect DrawEffects = bIsEnabled ? ESlateDrawEffect::None : ESlateDrawEffect::DisabledEffect;
	const FVector2f SelectorSize = SelectorImage->ImageSize;
	const FVector2f CircleSize = AllottedGeometry.GetLocalSize() - SelectorSize;

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId,
		AllottedGeometry.ToPaintGeometry(CircleSize, FSlateLayoutTransform(0.5f * SelectorSize)),
		Image,
		DrawEffects,
		InWidgetStyle.GetColorAndOpacityTint() * Image->GetTint(InWidgetStyle)
	);

	FSlateDrawElement::MakeBox(
		OutDrawElements,
		LayerId + 1,
		AllottedGeometry.ToPaintGeometry(SelectorSize, FSlateLayoutTransform(0.5f * (AllottedGeometry.GetLocalSize() + CalcRelativePositionFromCenter() * FVector2D(CircleSize - SelectorSize)))),
		SelectorImage,
		DrawEffects,
		InWidgetStyle.GetColorAndOpacityTint() * SelectorImage->GetTint(InWidgetStyle)
	);

	return LayerId + 1;
}

/*===========================================================================*\
|                            Main Implementation                              |
\*===========================================================================*/

FVector2D SWColorWheel::CalcRelativePositionFromCenter() const
{
	/**
	 * R = Hue
	 * G = Saturation / Radius
	 */
	float Angle = SelectedColor.Get().R / 180.0f * PI;
	return FVector2D(FMath::Cos(Angle), FMath::Sin(Angle)) * SelectedColor.Get().G;
}


bool SWColorWheel::ProcessMouseAction(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent, bool bProcessWhenOutsideColorWheel)
{
	const FVector2D LocalMouseCoordinate = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
	const FVector2D RelativePositionFromCenter = (2.0f * LocalMouseCoordinate - MyGeometry.GetLocalSize()) / (MyGeometry.GetLocalSize() - SelectorImage->ImageSize);
	
	OnPositionChanged.ExecuteIfBound(FVector2D(FMath::Clamp(RelativePositionFromCenter.X, -1.0, 1.0), -1.0 * FMath::Clamp(RelativePositionFromCenter.Y, -1.0, 1.0)));
	//UE_LOG(LogTemp, Warning, TEXT("X: %f - Y: %f"), RelativePositionFromCenter.X, RelativePositionFromCenter.Y)
	
	const float RelativeRadius = RelativePositionFromCenter.Size();

	if (RelativeRadius <= 1.0f || bProcessWhenOutsideColorWheel)
	{
		float Angle = FMath::Atan2(RelativePositionFromCenter.Y, RelativePositionFromCenter.X);

		if (Angle < 0.0f)
			Angle += 2.0f * PI;

		FLinearColor NewColor = SelectedColor.Get();
		{
			NewColor.R = Angle * 180.0f * INV_PI;
			NewColor.G = FMath::Min(RelativeRadius, 1.0f);
		}

		OnValueChanged.ExecuteIfBound(NewColor);
	}

	return (RelativeRadius <= 1.0f);
}
