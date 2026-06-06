// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ThumbnailHelpers.h"
#include "ThumbnailRendering/DefaultSizedThumbnailRenderer.h"
#include "Interfaces/I_ActorPreset.h"
#include "Engine/DataAsset.h"
#include "ActorPreset_ThumbnailRenderer.generated.h"

// ──────────────────────────────────────────────────────────────────────────────
// Preview Scene
// ──────────────────────────────────────────────────────────────────────────────

/** A thumbnail preview scene that spawns the configured actor and calls PreviewConstruct. */
class FActorPresetThumbnailScene : public FThumbnailPreviewScene
{
public:
	FActorPresetThumbnailScene() = default;

	/** Spawn (or replace) the preview actor for the given preset asset. */
	void SetPresetAsset(UPrimaryDataAsset* InAsset);

protected:
	// FThumbnailPreviewScene interface
	virtual void GetViewMatrixParameters(float InFOVDegrees, FVector& OutOrigin,
	                                     float& OutOrbitPitch, float& OutOrbitYaw,
	                                     float& OutOrbitZoom) const override;

private:
	TWeakObjectPtr<AActor>            PreviewActor;
	TWeakObjectPtr<UPrimaryDataAsset> CurrentAsset;
};


// ──────────────────────────────────────────────────────────────────────────────
// Thumbnail Renderer
// ──────────────────────────────────────────────────────────────────────────────

/**
 * Renders a live 3-D actor preview as the content-browser thumbnail for any
 * UOmegaMinimalDataAsset that implements IDataInterface_ActorPreset and returns
 * bPreviewThumbnailFromActor = true from ActorPreset_GetConfig.
 */
UCLASS()
class UActorPreset_ThumbnailRenderer : public UDefaultSizedThumbnailRenderer
{
	GENERATED_UCLASS_BODY()

	// UThumbnailRenderer interface
	virtual bool CanVisualizeAsset(UObject* Object) override;
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height,
	                  FRenderTarget* RenderTarget, FCanvas* Canvas,
	                  bool bAdditionalViewFamily) override;
	virtual EThumbnailRenderFrequency GetThumbnailRenderFrequency(UObject* Object) const override;

	// UObject interface
	virtual void BeginDestroy() override;

private:
	TClassInstanceThumbnailScene<FActorPresetThumbnailScene, 40> ThumbnailScenes;
};
