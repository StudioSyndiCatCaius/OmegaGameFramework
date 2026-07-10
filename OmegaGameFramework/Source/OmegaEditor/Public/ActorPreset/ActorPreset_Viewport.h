// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SEditorViewport.h"
#include "AdvancedPreviewScene.h"
#include "EditorViewportClient.h"
#include "UnrealWidget.h"

class UPrimaryDataAsset;


// ──────────────────────────────────────────────────────────────────────────────
// Viewport Client
// ──────────────────────────────────────────────────────────────────────────────

class FActorPreset_ViewportClient : public FEditorViewportClient
{
public:
	FActorPreset_ViewportClient(UPrimaryDataAsset*                       InAsset,
	                             TWeakPtr<SEditorViewport>                InViewport,
	                             const TSharedRef<FAdvancedPreviewScene>& InPreviewScene);
	virtual ~FActorPreset_ViewportClient() override;

	// FEditorViewportClient interface
	virtual void    Tick(float DeltaSeconds) override;
	virtual UWorld* GetWorld() const override;

	// ── Property widget editing ───────────────────────────────────────────────
	// Any FVector / FTransform property on the DataAsset with
	// meta=(MakeEditWidget) gets an interactive handle in this viewport.

	virtual void                   Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	virtual void                   DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas) override;
	virtual UE::Widget::EWidgetMode GetWidgetMode() const override;
	virtual FVector                 GetWidgetLocation() const override;
	virtual bool                    InputWidgetDelta(FViewport* InViewport,
	                                                  EAxisList::Type CurrentAxis,
	                                                  FVector& Drag, FRotator& Rot,
	                                                  FVector& Scale) override;
	virtual void                    TrackingStopped() override;
	virtual void                    ProcessClick(FSceneView& View, HHitProxy* HitProxy,
	                                              FKey Key, EInputEvent Event,
	                                              uint32 HitX, uint32 HitY) override;

	/** Destroy the current preview actor and respawn it from the interface config. */
	void RespawnPreviewActor();

	/** Update the asset pointer (e.g. after Blueprint reinstancing) then respawn. */
	void UpdateAsset(UPrimaryDataAsset* NewAsset);

private:
	// ── Helpers ───────────────────────────────────────────────────────────────
	TArray<FProperty*> CollectEditWidgetProperties() const;
	FProperty*         FindProperty(FName PropertyName) const;
	bool               IsTransformProperty(const FProperty* Prop) const;
	FVector            ReadPropertyLocation(const FProperty* Prop) const;
	FQuat              ReadPropertyRotation(const FProperty* Prop) const;

	TObjectPtr<UPrimaryDataAsset>     Asset;
	TWeakPtr<SEditorViewport>         OwnerViewport;
	TSharedPtr<FAdvancedPreviewScene> PreviewScene;
	TWeakObjectPtr<AActor>            PreviewActor;

	/** Name of the DataAsset property currently selected for widget editing. */
	FName ActiveWidgetProperty;
};


// ──────────────────────────────────────────────────────────────────────────────
// Slate Viewport Widget
// ──────────────────────────────────────────────────────────────────────────────

class SActorPreset_Viewport : public SEditorViewport
{
public:
	SLATE_BEGIN_ARGS(SActorPreset_Viewport) {}
		SLATE_ARGUMENT(TObjectPtr<UPrimaryDataAsset>, Asset)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual ~SActorPreset_Viewport() override;

	void RefreshPreview();
	void UpdateAsset(UPrimaryDataAsset* NewAsset);

private:
	FReply      OnOpenBlueprintClicked();
	EVisibility GetOpenBlueprintVisibility() const;

protected:
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	virtual void PopulateViewportOverlays(TSharedRef<SOverlay> Overlay) override;

private:
	TObjectPtr<UPrimaryDataAsset>     Asset;
	TSharedPtr<FAdvancedPreviewScene> PreviewScene;
};
