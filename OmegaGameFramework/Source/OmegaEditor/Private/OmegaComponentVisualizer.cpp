// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaComponentVisualizer.h"

#include "CanvasItem.h"
#include "CanvasTypes.h"

void FOmegaComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
                                                  FPrimitiveDrawInterface* PDI)
{
	FComponentVisualizer::DrawVisualization(Component, View, PDI);
}

void FOmegaComponentVisualizer::DrawVisualizationHUD(const UActorComponent* Component, const FViewport* Viewport,
	const FSceneView* View, FCanvas* Canvas)
{
	if (!Component || !Canvas || !View)
	{
		return;
	}

	// Get the actor that owns this component
	AActor* Owner = Component->GetOwner();
	if (!Owner)
	{
		return;
	}

	// Get the world location of the actor
	FVector WorldLocation = Owner->GetActorLocation();

	// Project world location to screen space
	FVector2D ScreenPosition;
	if (View->WorldToPixel(WorldLocation, ScreenPosition))
	{
		// Get the display name
		FString DisplayName = Owner->GetActorLabel();

		// Set up text properties
		FCanvasTextItem TextItem(ScreenPosition, FText::FromString(DisplayName), GEngine->GetMediumFont(), FLinearColor::White);
		TextItem.EnableShadow(FLinearColor::Black);
        
		// Center the text horizontally
		TextItem.Position.X -= TextItem.DrawnSize.X * 0.5f;
        
		// Draw the text
		Canvas->DrawItem(TextItem);
	}
}
