// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Widget/DataList_Formats.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Kismet/KismetMathLibrary.h"

// ─────────────────────────────────────────────────────────────────────────────
// UDataListFormat_List
// ─────────────────────────────────────────────────────────────────────────────

UPanelWidget* UDataListFormat_List::CreateWidget_Implementation(UDataList* OwningList)
{
	if (Orientation == EOrientation::Orient_Horizontal)
	{
		return NewObject<UHorizontalBox>(OwningList);
	}
	return NewObject<UVerticalBox>(OwningList);
}

void UDataListFormat_List::AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget)
{
	if (!DataWidget || !PanelWidget) { return; }

	if (Orientation == EOrientation::Orient_Horizontal)
	{
		if (UHorizontalBox* HBox = Cast<UHorizontalBox>(PanelWidget))
		{
			UHorizontalBoxSlot* Slot = HBox->AddChildToHorizontalBox(DataWidget);
			Slot->SetHorizontalAlignment(HorizontalAlignment);
			Slot->SetVerticalAlignment(VerticalAlignment);
			Slot->SetSize(EntrySize);
		}
	}
	else
	{
		if (UVerticalBox* VBox = Cast<UVerticalBox>(PanelWidget))
		{
			UVerticalBoxSlot* Slot = VBox->AddChildToVerticalBox(DataWidget);
			Slot->SetHorizontalAlignment(HorizontalAlignment);
			Slot->SetVerticalAlignment(VerticalAlignment);
			Slot->SetSize(EntrySize);
		}
	}
}

// ─────────────────────────────────────────────────────────────────────────────
// UDataListFormat_ScrollList
// ─────────────────────────────────────────────────────────────────────────────

UPanelWidget* UDataListFormat_ScrollList::CreateWidget_Implementation(UDataList* OwningList)
{
	UOmegaScrollBox* ScrollBox = NewObject<UOmegaScrollBox>(OwningList);
	ScrollBox->SetOrientation(Orientation);
	if (Style)
	{
		ScrollBox->SetStyleAsset(Style);
	}
	return ScrollBox;
}

void UDataListFormat_ScrollList::OnWidgetHovered_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget)
{
	if (UOmegaScrollBox* ScrollBox = Cast<UOmegaScrollBox>(PanelWidget))
	{
		ScrollBox->ScrollWidgetIntoView(DataWidget);
	}
}

// ─────────────────────────────────────────────────────────────────────────────
// UDataListFormat_UniformGrid
// ─────────────────────────────────────────────────────────────────────────────

UPanelWidget* UDataListFormat_UniformGrid::CreateWidget_Implementation(UDataList* OwningList)
{
	CurrentA = 0;
	CurrentB = 0;
	return NewObject<UUniformGridPanel>(OwningList);
}

void UDataListFormat_UniformGrid::AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget)
{
	if (!DataWidget || !PanelWidget) { return; }

	UUniformGridPanel* Grid = Cast<UUniformGridPanel>(PanelWidget);
	if (!Grid) { return; }

	int32 InRow = 0;
	int32 InCol = 0;

	// Horizontal: fills columns first (left-to-right), then wraps to next row.
	// Vertical:   fills rows first (top-to-bottom), then wraps to next column.
	if (Orientation == EOrientation::Orient_Horizontal)
	{
		InRow = CurrentA;
		InCol = CurrentB;
	}
	else
	{
		InRow = CurrentB;
		InCol = CurrentA;
	}

	UUniformGridSlot* Slot = Grid->AddChildToUniformGrid(DataWidget, InRow, InCol);
	Slot->SetHorizontalAlignment(HorizontalAlignment);
	Slot->SetVerticalAlignment(VerticalAlignment);

	if (CurrentB >= (MaxValue - 1))
	{
		CurrentA++;
		CurrentB = 0;
	}
	else
	{
		CurrentB++;
	}
}

UDataWidget* UDataListFormat_UniformGrid::OnReceiveInput_Navigation_Implementation(
	FVector2D Input2D, int32 Input1D, UDataList* List)
{
	// Determine step amounts for primary and secondary axes.
	// Primary axis moves by 1 entry; secondary axis jumps a full row/column (MaxValue).
	int32 Amount = 0;
	const int32 ColStep = FMath::Max(1, MaxValue);

	if (Orientation == EOrientation::Orient_Horizontal)
	{
		// Primary = X axis (left/right = ±1), Secondary = Y axis (up/down = ±MaxValue)
		if (FMath::Abs(Input2D.X) >= FMath::Abs(Input2D.Y))
		{
			Amount = (Input2D.X > 0.f) ? 1 : -1;
		}
		else
		{
			Amount = (Input2D.Y > 0.f) ? -ColStep : ColStep;
		}
	}
	else
	{
		// Primary = Y axis (down/up = ±1), Secondary = X axis (right/left = ±MaxValue)
		if (FMath::Abs(Input2D.Y) >= FMath::Abs(Input2D.X))
		{
			Amount = (Input2D.Y > 0.f) ? -1 : 1;
		}
		else
		{
			Amount = (Input2D.X > 0.f) ? ColStep : -ColStep;
		}
	}

	int32 OutIndex;
	List->CycleEntry(Amount, OutIndex);
	return nullptr;
}

// ─────────────────────────────────────────────────────────────────────────────
// UDataListFormat_Radial
// ─────────────────────────────────────────────────────────────────────────────

UPanelWidget* UDataListFormat_Radial::CreateWidget_Implementation(UDataList* OwningList)
{
	RadialEntries.Empty();
	return NewObject<UCanvasPanel>(OwningList);
}

void UDataListFormat_Radial::AddDataWidget_Implementation(UDataWidget* DataWidget, UPanelWidget* PanelWidget)
{
	if (!DataWidget || !PanelWidget) { return; }

	UCanvasPanel* Canvas = Cast<UCanvasPanel>(PanelWidget);
	if (!Canvas) { return; }

	RadialEntries.Add(DataWidget);
	Canvas->AddChild(DataWidget);
	RepositionAll(PanelWidget);
}

void UDataListFormat_Radial::RepositionAll(UPanelWidget* PanelWidget)
{
	UCanvasPanel* Canvas = Cast<UCanvasPanel>(PanelWidget);
	if (!Canvas) { return; }

	const int32 Total = RadialEntries.Num();
	if (Total == 0) { return; }

	const float AngleStep = (Total > 1) ? 360.f / static_cast<float>(Total) : 0.f;

	for (int32 i = 0; i < Total; ++i)
	{
		UDataWidget* Entry = RadialEntries[i];
		if (!Entry) { continue; }

		UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(Entry->Slot);
		if (!Slot) { continue; }

		const float AngleRad = FMath::DegreesToRadians(StartAngleDegrees + AngleStep * i);
		const FVector2D Position(
			Radius * FMath::Cos(AngleRad) - EntrySize.X * 0.5f,
			Radius * FMath::Sin(AngleRad) - EntrySize.Y * 0.5f
		);

		Slot->SetPosition(Position);
		Slot->SetSize(EntrySize);
		Slot->SetAnchors(FAnchors(0.5f, 0.5f));
		Slot->SetAlignment(FVector2D(0.5f, 0.5f));
	}
}
