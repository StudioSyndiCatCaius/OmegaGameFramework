// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Interfaces/I_ActorPreset.h"
#include "OmegaActorPresetAsset.generated.h"

/**
 * Abstract base class for DataAssets that describe how to spawn and configure a
 * preview/world actor.  Blueprint subclasses override the two BlueprintNativeEvents
 * to supply an actor class and to customise the spawned actor at construction time.
 *
 * Feature 1 – Preview viewport: opening this asset in the editor shows a live 3-D
 *             preview of the actor returned by ActorPreset_GetConfig (when
 *             bPreviewActor is true).
 *
 * Feature 2 – World drag-drop: dragging this asset from the Content Browser into a
 *             level spawns the configured actor and calls ActorPreset_PreviewConstruct
 *             on it (when bAllowWorldDrop is true).
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class OMEGAGAMEFRAMEWORK_API UOmegaActorPresetAsset : public UPrimaryDataAsset, public IDataInterface_ActorPreset
{
	GENERATED_BODY()

public:
	// ── IDataInterface_ActorPreset ────────────────────────────────────────────

	/**
	 * Return the actor class to spawn, and which features are enabled for this asset.
	 * Override in Blueprint or C++ to customise.  Default: AActor, both flags true.
	 */
	virtual void ActorPreset_GetConfig_Implementation(
		TSubclassOf<AActor>& ActorClass,
		bool& bPreviewActor,
		bool& bAllowWorldDrop,
		bool& bPreviewThumbnailFromActor) override;

	/**
	 * Called immediately after the actor is spawned (editor preview or world
	 * drag-drop).  Override to set mesh, materials, tags, etc.
	 * Return true if the construction succeeded.  Default returns true.
	 */
	virtual bool ActorPreset_PreviewConstruct_Implementation(AActor* Actor) override;
};
