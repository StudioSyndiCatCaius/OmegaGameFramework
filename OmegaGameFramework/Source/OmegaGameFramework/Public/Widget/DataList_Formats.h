// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataList.h"
#include "UObject/Object.h"
#include "Widget/UI_Widgets.h"
#include "DataList_Formats.generated.h"

// ─────────────────────────────────────────────────────────────────────────────
// Box (Horizontal / Vertical) List
// ─────────────────────────────────────────────────────────────────────────────

UCLASS(DisplayName="(List Format) List")
class OMEGAGAMEFRAMEWORK_API UDataListFormat_List : public UDataListFormat
{
	GENERATED_BODY()

public:

	// Whether entries stack left-to-right or top-to-bottom.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EOrientation> Orientation = EOrientation::Orient_Vertical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment = EVerticalAlignment::VAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	FSlateChildSize EntrySize;

	virtual UPanelWidget* CreateWidget_Implementation(UDataList* OwningList) override;
	virtual void AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget) override;
};

// ─────────────────────────────────────────────────────────────────────────────
// Scroll Box List
// ─────────────────────────────────────────────────────────────────────────────

UCLASS(DisplayName="(List Format) Scroll List")
class OMEGAGAMEFRAMEWORK_API UDataListFormat_ScrollList : public UDataListFormat
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EOrientation> Orientation = EOrientation::Orient_Vertical;

	// Optional style asset applied to the created OmegaScrollBox.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	UOmegaSlateStyle_ScrollBox* Style = nullptr;

	virtual UPanelWidget* CreateWidget_Implementation(UDataList* OwningList) override;
	virtual void OnWidgetHovered_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget) override;
};

// ─────────────────────────────────────────────────────────────────────────────
// Uniform Grid List
// ─────────────────────────────────────────────────────────────────────────────

UCLASS(DisplayName="(List Format) Uniform Grid")
class OMEGAGAMEFRAMEWORK_API UDataListFormat_UniformGrid : public UDataListFormat
{
	GENERATED_BODY()
public:

	// Primary fill axis. Horizontal: fills left-to-right, wraps into new rows.
	// Vertical: fills top-to-bottom, wraps into new columns.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EOrientation> Orientation = EOrientation::Orient_Horizontal;

	// Number of columns (Horizontal) or rows (Vertical) before wrapping.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format", meta=(ClampMin=1))
	int32 MaxValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment = EVerticalAlignment::VAlign_Fill;

	virtual UPanelWidget* CreateWidget_Implementation(UDataList* OwningList) override;
	virtual void AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget) override;
	virtual UDataWidget* OnReceiveInput_Navigation_Implementation(FVector2D Input2D, int32 Input1D, UDataList* List) override;

private:
	// Running row/column cursor — reset each time CreateWidget is called.
	UPROPERTY()
	int32 CurrentA = 0;
	UPROPERTY()
	int32 CurrentB = 0;
};

// ─────────────────────────────────────────────────────────────────────────────
// Radial List  (entries placed in a circle on a Canvas Panel)
// ─────────────────────────────────────────────────────────────────────────────

UCLASS(DisplayName="(List Format) Radial")
class OMEGAGAMEFRAMEWORK_API UDataListFormat_Radial : public UDataListFormat
{
	GENERATED_BODY()
public:

	// Radius of the circle in slate units.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format", meta=(ClampMin=1.f))
	float Radius = 200.f;

	// Angle (degrees) of the first entry. 0 = right, 90 = down.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	float StartAngleDegrees = 0.f;

	// Fixed size of each entry widget on the canvas.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Format")
	FVector2D EntrySize = FVector2D(64.f, 64.f);

	virtual UPanelWidget* CreateWidget_Implementation(UDataList* OwningList) override;
	virtual void AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget) override;

private:
	// Tracks every widget added so positions can be recomputed after each add.
	UPROPERTY()
	TArray<UDataWidget*> RadialEntries;

	void RepositionAll(UPanelWidget* PanelWidget);
};
