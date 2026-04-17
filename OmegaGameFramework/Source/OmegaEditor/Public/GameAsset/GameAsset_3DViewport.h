#pragma once

#include "CoreMinimal.h"
#include "SEditorViewport.h"
#include "AdvancedPreviewScene.h"
#include "EditorViewportClient.h"

class UOmegaGameAsset;


// ──────────────────────────────────────────────────────────────────────────────
// Viewport Client
// ──────────────────────────────────────────────────────────────────────────────
class FGameplayAsset3DViewportClient : public FEditorViewportClient
{
public:
    FGameplayAsset3DViewportClient(UOmegaGameAsset* InAsset,
                                   TWeakPtr<SEditorViewport> InViewport,
                                   const TSharedRef<FAdvancedPreviewScene>& InPreviewScene);
    virtual ~FGameplayAsset3DViewportClient() override;

    // FEditorViewportClient interface
    virtual void Tick(float DeltaSeconds) override;
    virtual UWorld* GetWorld() const override;

    void RespawnReferenceActor();
    void CommitSceneToAsset();

    AActor* GetReferenceActor() const { return ReferenceActor.Get(); }

private:
    TObjectPtr<UOmegaGameAsset>          Asset;
    TWeakPtr<SEditorViewport>           OwnerViewport;
    TSharedPtr<FAdvancedPreviewScene>   PreviewScene;
    TWeakObjectPtr<AActor>              ReferenceActor;
};


// ──────────────────────────────────────────────────────────────────────────────
// Slate Viewport Widget
// ──────────────────────────────────────────────────────────────────────────────
class SGameplayAsset3DViewport : public SEditorViewport
{
public:
    SLATE_BEGIN_ARGS(SGameplayAsset3DViewport) {}
        SLATE_ARGUMENT(TObjectPtr<UOmegaGameAsset>, Asset)
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
    virtual ~SGameplayAsset3DViewport() override;

    FGameplayAsset3DViewportClient* GetViewportClient() const
    {
        return static_cast<FGameplayAsset3DViewportClient*>(Client.Get());
    }

    void CommitScene();

protected:
    // SEditorViewport interface
    virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
    virtual void PopulateViewportOverlays(TSharedRef<SOverlay> Overlay) override;

private:
    TObjectPtr<UOmegaGameAsset>          Asset;
    TSharedPtr<FAdvancedPreviewScene>   PreviewScene;
};
