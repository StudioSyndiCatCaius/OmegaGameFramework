#include "GameAsset/GameAsset_3DViewport.h"
#include "OmegaGameAsset.h"
#include "AdvancedPreviewScene.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// ── FGameplayAsset3DViewportClient ────────────────────────────────────────────

FGameplayAsset3DViewportClient::FGameplayAsset3DViewportClient(
    UOmegaGameAsset*                          InAsset,
    TWeakPtr<SEditorViewport>                InViewport,
    const TSharedRef<FAdvancedPreviewScene>& InPreviewScene)
    : FEditorViewportClient(nullptr, &InPreviewScene.Get(), InViewport)
    , Asset(InAsset)
    , OwnerViewport(InViewport)
    , PreviewScene(InPreviewScene)
{
    bSetListenerPosition = false;

    SetViewLocation(FVector(0.f, -300.f, 150.f));
    SetViewRotation(FRotator(-15.f, 90.f, 0.f));

    EngineShowFlags.SetGrid(true);
    EngineShowFlags.SetDynamicShadows(true);

    RespawnReferenceActor();
}

FGameplayAsset3DViewportClient::~FGameplayAsset3DViewportClient()
{
    if (ReferenceActor.IsValid())
    {
        ReferenceActor->Destroy();
    }
}

UWorld* FGameplayAsset3DViewportClient::GetWorld() const
{
    return PreviewScene ? PreviewScene->GetWorld() : nullptr;
}

void FGameplayAsset3DViewportClient::RespawnReferenceActor()
{
    UWorld* World = GetWorld();
    if (!World || !Asset) return;

    if (ReferenceActor.IsValid())
    {
        ReferenceActor->Destroy();
        ReferenceActor = nullptr;
    }

    TSubclassOf<AActor> ActorClass = Asset->Scene3D_GetBaseActorClass();
    if (!ActorClass) ActorClass = AActor::StaticClass();

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ReferenceActor = World->SpawnActor<AActor>(ActorClass, FTransform::Identity, Params);
}

void FGameplayAsset3DViewportClient::CommitSceneToAsset()
{
    if (Asset && ReferenceActor.IsValid())
    {
        Asset->Modify();
        Asset->Scene3D_OnAssetEdit(ReferenceActor.Get());
    }
}

void FGameplayAsset3DViewportClient::Tick(float DeltaSeconds)
{
    FEditorViewportClient::Tick(DeltaSeconds);

    if (PreviewScene)
    {
        PreviewScene->GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
    }
}


// ── SGameplayAsset3DViewport ──────────────────────────────────────────────────

void SGameplayAsset3DViewport::Construct(const FArguments& InArgs)
{
    Asset = InArgs._Asset;

    FAdvancedPreviewScene::ConstructionValues CVS;
    CVS.bCreatePhysicsScene    = false;
    CVS.bShouldSimulatePhysics = false;
    PreviewScene = MakeShared<FAdvancedPreviewScene>(CVS);
    PreviewScene->SetFloorVisibility(true);

    SEditorViewport::Construct(SEditorViewport::FArguments());

    // Set realtime AFTER base Construct so the viewport exists
    if (Client.IsValid())
    {
        Client->SetRealtime(true);
    }
}

SGameplayAsset3DViewport::~SGameplayAsset3DViewport()
{
}

TSharedRef<FEditorViewportClient> SGameplayAsset3DViewport::MakeEditorViewportClient()
{
    return MakeShared<FGameplayAsset3DViewportClient>(
        Asset,
        SharedThis(this),
        PreviewScene.ToSharedRef());
}

void SGameplayAsset3DViewport::PopulateViewportOverlays(TSharedRef<SOverlay> Overlay)
{
    SEditorViewport::PopulateViewportOverlays(Overlay);
    // Add custom toolbar widgets to the overlay here if needed
}

void SGameplayAsset3DViewport::CommitScene()
{
    if (FGameplayAsset3DViewportClient* VC = GetViewportClient())
    {
        VC->CommitSceneToAsset();
    }
}
