// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaAnalogCursor.h"
//#include "GamepadUMGPluginPrivatePCH.h"
#include "OmegaInputSettings.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Engine/UserInterfaceSettings.h"

bool IsWidgetInteractable(const TSharedPtr<SWidget> Widget)
{
	return Widget.IsValid() && Widget->IsInteractable();
}

////////////////////////////////////////////////////////////////////////////
// FOmegaAnalogCursor
////////////////////////////////////////////////////////////////////////////

void FOmegaAnalogCursor::EnableAnalogCursor(class APlayerController* PC)
{
	if (PC)
	{
		const float CursorRadius = GetDefault<UOmegaInputSettings>()->GetAnalogCursorRadius();
		const TSharedPtr<FOmegaAnalogCursor> AnalogCursor = MakeShareable(new FOmegaAnalogCursor(PC, CursorRadius));
		FSlateApplication::Get().RegisterInputPreProcessor(AnalogCursor);
		FSlateApplication::Get().SetCursorRadius(CursorRadius);

		GetMutableDefault<UOmegaInputSettings>()->SetAnalogCursor(AnalogCursor);
		
	}
}

void FOmegaAnalogCursor::DisableAnalogCursor(class APlayerController* PC)
{
	if (PC)
	{
		if (FSlateApplication::IsInitialized())
		{
			FSlateApplication::Get().UnregisterInputPreProcessor(GetMutableDefault<UOmegaInputSettings>()->GetAnalogCursor());
			FSlateApplication::Get().SetCursorRadius(0.0f);
		}
	}
}

FOmegaAnalogCursor::FOmegaAnalogCursor(class APlayerController* PC, float _Radius)
: Velocity(FVector2D::ZeroVector)
, CurrentPosition(FLT_MAX, FLT_MAX)
, LastCursorDirection(FVector2D::ZeroVector)
, HoveredWidgetName(NAME_None)
, bIsUsingAnalogCursor(false)
, Radius(FMath::Max<float>(_Radius, 16.0f))
, PlayerContext(PC)
{
	ensure(PlayerContext.IsValid());
}

void FOmegaAnalogCursor::Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor)
{
	if (PlayerContext.IsValid())
	{
		const FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(PlayerContext.GetPlayerController());
		const float DPIScale = GetDefault<UUserInterfaceSettings>()->GetDPIScaleBasedOnSize(FIntPoint(FMath::RoundToInt(ViewportSize.X), FMath::RoundToInt(ViewportSize.Y)));

		const UOmegaInputSettings* Settings = GetDefault<UOmegaInputSettings>();

		//if we have no acceleration curve, then move on;
		if (Settings->GetUseEngineAnalogCursor())
		{
			FAnalogCursor::Tick(DeltaTime, SlateApp, Cursor);
			return;
		}

		//set the current position if we haven't already
		static const float MouseMoveSizeBuffer = 2.0f;
		const FVector2D CurrentPositionTruc = FVector2D(FMath::TruncToFloat(CurrentPosition.X), FMath::TruncToFloat(CurrentPosition.Y));
		if (CurrentPositionTruc != Cursor->GetPosition())
		{
			CurrentPosition = Cursor->GetPosition();
			Velocity = FVector2D::ZeroVector;
			LastCursorDirection = FVector2D::ZeroVector;
			bIsUsingAnalogCursor = false;
			FSlateApplication::Get().SetCursorRadius(0.0f);
		}

		//cache the old position
		const FVector2D OldPosition = CurrentPosition;

		//figure out if we should clamp the speed or not
		const float MaxSpeedNoHover = Settings->GetMaxAnalogCursorSpeed()*DPIScale;
		const float MaxSpeedHover = Settings->GetMaxAnalogCursorSpeedWhenHovered()*DPIScale;
		const float DragCoNoHover = Settings->GetAnalogCursorDragCoefficient()*DPIScale;
		const float DragCoHovered = Settings->GetAnalogCursorDragCoefficientWhenHovered()*DPIScale;
		const float MinCursorSpeed = Settings->GetMinAnalogCursorSpeed()*DPIScale;

		HoveredWidgetName = NAME_None;
		float DragCo = DragCoNoHover;
		
		//Part of base class now
		MaxSpeed = MaxSpeedNoHover;

		//see if we are hovered over a widget or not
		FWidgetPath WidgetPath = SlateApp.LocateWindowUnderMouse(OldPosition, SlateApp.GetInteractiveTopLevelWindows());
		if (WidgetPath.IsValid())
		{
			for (int32 i = WidgetPath.Widgets.Num() - 1; i >= 0; --i)
			{
				//grab the widget
				FArrangedWidget& ArrangedWidget = WidgetPath.Widgets[i];
				TSharedRef<SWidget> Widget = ArrangedWidget.Widget;

				//see if it is acceptable or not
				if (IsWidgetInteractable(Widget))
				{
					HoveredWidgetName = Widget->GetType();
					DragCo = DragCoHovered;
					MaxSpeed = MaxSpeedHover;
					break;
				}
			}
		}

		//grab the cursor acceleration
		const FVector2D AccelFromAnalogStick = GetAnalogCursorAccelerationValue(GetAnalogValues(), DPIScale);

		FVector2D NewAccelerationThisFrame = FVector2D::ZeroVector;
		if (!Settings->GetAnalogCursorNoAcceleration())
		{
			//Calculate a new velocity. RK4.
			if (!AccelFromAnalogStick.IsZero() || !Velocity.IsZero())
			{
				const FVector2D A1 = (AccelFromAnalogStick - (DragCo * Velocity)) * DeltaTime;
				const FVector2D A2 = (AccelFromAnalogStick - (DragCo * (Velocity + (A1 * 0.5f)))) * DeltaTime;
				const FVector2D A3 = (AccelFromAnalogStick - (DragCo * (Velocity + (A2 * 0.5f)))) * DeltaTime;
				const FVector2D A4 = (AccelFromAnalogStick - (DragCo * (Velocity + A3))) * DeltaTime;
				NewAccelerationThisFrame = (A1 + (2.0f * A2) + (2.0f * A3) + A4) / 6.0f;
				Velocity += NewAccelerationThisFrame;
			}
		}
		else
		{
			//else, use what is coming straight from the analog stick
			Velocity = AccelFromAnalogStick;
		}

		//if we are smaller than out min speed, zero it out
		const float VelSizeSq = Velocity.SizeSquared();
		if (VelSizeSq < (MinCursorSpeed * MinCursorSpeed))
		{
			Velocity = FVector2D::ZeroVector;
		}
		else if (VelSizeSq > (MaxSpeed * MaxSpeed))
		{
			//also cap us if we are larger than our max speed
			Velocity = Velocity.GetSafeNormal() * MaxSpeed;
		}

		//store off the last cursor direction
		if (!Velocity.IsZero())
		{
			LastCursorDirection = Velocity.GetSafeNormal();
		}

		//update the new position
		CurrentPosition += (Velocity * DeltaTime);

		//update the cursor position
		UpdateCursorPosition(SlateApp, Cursor, CurrentPosition);
	
		//if we get here, and we are moving the stick, then hooray
		if (!AccelFromAnalogStick.IsZero())
		{
			bIsUsingAnalogCursor = true;
			FSlateApplication::Get().SetCursorRadius(Settings->GetAnalogCursorRadius()*DPIScale);
		}
	}
}

FVector2D FOmegaAnalogCursor::GetAnalogCursorAccelerationValue(const FVector2D& InAnalogValues, float DPIScale)
{
	const UOmegaInputSettings* Settings = GetDefault<UOmegaInputSettings>();

	FVector2D RetValue = FVector2D::ZeroVector;
	if ( const FRichCurve* AccelerationCurve = Settings->GetAnalogCursorAccelerationCurve() )
	{
		const float DeadZoneSize = Settings->GetAnalogCursorDeadZone();
		const float AnalogValSize = InAnalogValues.Size();
		if (AnalogValSize > DeadZoneSize)
		{
			RetValue = AccelerationCurve->Eval(AnalogValSize) * InAnalogValues.GetSafeNormal() * DPIScale;
			RetValue *= Settings->GetAnalogCursorAccelerationMultiplier()*DPIScale;
		}
	}
	return RetValue;
}


