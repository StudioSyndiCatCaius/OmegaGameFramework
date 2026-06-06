// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "ActorPreset/ActorPreset_ThumbnailRenderer.h"
#include "Misc/GeneralDataObject.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "CanvasTypes.h"
#include "SceneView.h"
#include "ThumbnailRendering/ThumbnailManager.h"

// ──────────────────────────────────────────────────────────────────────────────
// FActorPresetThumbnailScene
// ──────────────────────────────────────────────────────────────────────────────

void FActorPresetThumbnailScene::SetPresetAsset(UPrimaryDataAsset* InAsset)
{
	// Destroy the previous actor
	if (PreviewActor.IsValid())
	{
		GetWorld()->DestroyActor(PreviewActor.Get());
		PreviewActor.Reset();
	}

	CurrentAsset = InAsset;
	if (!InAsset || !InAsset->Implements<UDataInterface_ActorPreset>()) return;

	TSubclassOf<AActor> ActorClass;
	bool bPreviewActor = false, bAllowWorldDrop = false, bPreviewThumbnail = false;
	IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(
		InAsset, ActorClass, bPreviewActor, bAllowWorldDrop, bPreviewThumbnail);

	if (!ActorClass || !bPreviewThumbnail) return;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	PreviewActor = GetWorld()->SpawnActor<AActor>(ActorClass, FTransform::Identity, Params);

	if (PreviewActor.IsValid())
	{
		IDataInterface_ActorPreset::Execute_ActorPreset_PreviewConstruct(InAsset, PreviewActor.Get());
	}
}

void FActorPresetThumbnailScene::GetViewMatrixParameters(
	const float InFOVDegrees,
	FVector&    OutOrigin,
	float&      OutOrbitPitch,
	float&      OutOrbitYaw,
	float&      OutOrbitZoom) const
{
	OutOrbitPitch = -15.f;
	OutOrbitYaw   =  45.f;

	if (PreviewActor.IsValid())
	{
		const FBoxSphereBounds Bounds = PreviewActor->GetComponentsBoundingBox(/*bNonColliding=*/true);

		// Orbit around the actual center of the actor, so offset meshes are framed correctly
		OutOrigin = Bounds.Origin;

		// Pull back far enough that the whole bounding sphere fits in the FOV, plus 15% padding
		const float HalfFOV = FMath::DegreesToRadians(InFOVDegrees * 0.5f);
		OutOrbitZoom = (Bounds.SphereRadius / FMath::Tan(HalfFOV)) * 1.15f;
	}
	else
	{
		OutOrigin    = FVector::ZeroVector;
		OutOrbitZoom = 300.f;
	}
}


// ──────────────────────────────────────────────────────────────────────────────
// UActorPreset_ThumbnailRenderer
// ──────────────────────────────────────────────────────────────────────────────

UActorPreset_ThumbnailRenderer::UActorPreset_ThumbnailRenderer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UActorPreset_ThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(Object);
	if (!Asset || !Asset->Implements<UDataInterface_ActorPreset>()) return false;

	TSubclassOf<AActor> ActorClass;
	bool bPreviewActor = false, bAllowWorldDrop = false, bPreviewThumbnail = false;
	IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(
		Asset, ActorClass, bPreviewActor, bAllowWorldDrop, bPreviewThumbnail);

	return bPreviewThumbnail && ActorClass != nullptr;
}

void UActorPreset_ThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y,
                                           uint32 Width, uint32 Height,
                                           FRenderTarget* RenderTarget,
                                           FCanvas* Canvas,
                                           bool bAdditionalViewFamily)
{
	UPrimaryDataAsset* Asset = Cast<UPrimaryDataAsset>(Object);
	if (!Asset) return;

	TSharedRef<FActorPresetThumbnailScene> Scene =
		ThumbnailScenes.EnsureThumbnailScene(Asset->GetClass());

	Scene->SetPresetAsset(Asset);

	FSceneViewFamilyContext ViewFamily(
		FSceneViewFamily::ConstructionValues(
			RenderTarget, Scene->GetScene(),
			FEngineShowFlags(ESFIM_Game))
		.SetTime(UThumbnailRenderer::GetTime())
		.SetRealtimeUpdate(true));

	RenderViewFamily(Canvas, &ViewFamily,
		Scene->CreateView(&ViewFamily, X, Y, Width, Height));
}

EThumbnailRenderFrequency UActorPreset_ThumbnailRenderer::GetThumbnailRenderFrequency(UObject* Object) const
{
	return EThumbnailRenderFrequency::Realtime;
}

void UActorPreset_ThumbnailRenderer::BeginDestroy()
{
	ThumbnailScenes.Clear();
	Super::BeginDestroy();
}
