// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailRendering/DefaultSizedThumbnailRenderer.h"
#include "OmegaEffectFactory.generated.h"


UCLASS()
class UDataItemThumbnailRender: public UDefaultSizedThumbnailRenderer
{
	GENERATED_UCLASS_BODY()
	
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	virtual bool CanVisualizeAsset(UObject* Object) override;
};

UCLASS()
class USlateStyleThumbnailRender: public UDefaultSizedThumbnailRenderer
{
	GENERATED_UCLASS_BODY()
	
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	void DrawBrushToCanvas(
	const FSlateBrush& Brush, int32 X, int32 Y,
	uint32 Width, uint32 Height, FCanvas* Canvas);
};


