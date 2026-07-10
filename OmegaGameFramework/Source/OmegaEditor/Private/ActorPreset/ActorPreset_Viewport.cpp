// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "ActorPreset/ActorPreset_Viewport.h"
#include "Interfaces/I_ActorPreset.h"
#include "AdvancedPreviewScene.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "Engine/DataAsset.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "Styling/AppStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "Editor.h"
#include "SceneManagement.h"

#define LOCTEXT_NAMESPACE "ActorPresetViewport"


// ── HitProxy for MakeEditWidget property handles ──────────────────────────────

struct HActorPresetWidgetProxy : public HHitProxy
{
	DECLARE_HIT_PROXY()
	FName PropertyName;
	explicit HActorPresetWidgetProxy(FName InName) : HHitProxy(HPP_UI), PropertyName(InName) {}
};
IMPLEMENT_HIT_PROXY(HActorPresetWidgetProxy, HHitProxy)


// ── FActorPreset_ViewportClient ───────────────────────────────────────────────

FActorPreset_ViewportClient::FActorPreset_ViewportClient(
	UPrimaryDataAsset*                       InAsset,
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

	RespawnPreviewActor();
}

FActorPreset_ViewportClient::~FActorPreset_ViewportClient()
{
	if (PreviewActor.IsValid())
	{
		PreviewActor->Destroy();
	}
}

UWorld* FActorPreset_ViewportClient::GetWorld() const
{
	return PreviewScene ? PreviewScene->GetWorld() : nullptr;
}

void FActorPreset_ViewportClient::RespawnPreviewActor()
{
	UWorld* World = GetWorld();
	if (!World || !Asset) return;

	if (PreviewActor.IsValid())
	{
		PreviewActor->Destroy();
		PreviewActor = nullptr;
	}

	if (!Asset->Implements<UDataInterface_ActorPreset>()) return;

	TSubclassOf<AActor> ActorClass;
	bool bPreviewActor = false, bAllowWorldDrop = false, bPreviewThumbnail = false;
	IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(
		Asset, ActorClass, bPreviewActor, bAllowWorldDrop, bPreviewThumbnail);

	if (!bPreviewActor || !ActorClass) return;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* Spawned = World->SpawnActor<AActor>(ActorClass, FTransform::Identity, Params);
	if (Spawned)
	{
		PreviewActor = Spawned;
		IDataInterface_ActorPreset::Execute_ActorPreset_PreviewConstruct(Asset, Spawned);
	}
}

void FActorPreset_ViewportClient::UpdateAsset(UPrimaryDataAsset* NewAsset)
{
	Asset = NewAsset;
	ActiveWidgetProperty = NAME_None;
	RespawnPreviewActor();
}

void FActorPreset_ViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	if (PreviewScene)
	{
		PreviewScene->GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
	}
}


// ── MakeEditWidget helpers ────────────────────────────────────────────────────

TArray<FProperty*> FActorPreset_ViewportClient::CollectEditWidgetProperties() const
{
	TArray<FProperty*> Result;
	if (!Asset) return Result;

	for (TFieldIterator<FStructProperty> It(Asset->GetClass()); It; ++It)
	{
		FStructProperty* Prop = *It;
		if (!Prop->HasMetaData(TEXT("MakeEditWidget"))) continue;

		const UScriptStruct* Struct = Prop->Struct;
		if (Struct == TBaseStructure<FVector>::Get() ||
		    Struct == TBaseStructure<FTransform>::Get())
		{
			Result.Add(Prop);
		}
	}
	return Result;
}

FProperty* FActorPreset_ViewportClient::FindProperty(FName PropertyName) const
{
	if (!Asset || PropertyName.IsNone()) return nullptr;
	return Asset->GetClass()->FindPropertyByName(PropertyName);
}

bool FActorPreset_ViewportClient::IsTransformProperty(const FProperty* Prop) const
{
	const FStructProperty* SP = CastField<const FStructProperty>(Prop);
	return SP && SP->Struct == TBaseStructure<FTransform>::Get();
}

FVector FActorPreset_ViewportClient::ReadPropertyLocation(const FProperty* Prop) const
{
	if (!Asset || !Prop) return FVector::ZeroVector;

	const FStructProperty* SP = CastField<const FStructProperty>(Prop);
	if (!SP) return FVector::ZeroVector;

	if (SP->Struct == TBaseStructure<FTransform>::Get())
	{
		const FTransform* T = SP->ContainerPtrToValuePtr<FTransform>(Asset);
		return T ? T->GetLocation() : FVector::ZeroVector;
	}
	else // FVector
	{
		const FVector* V = SP->ContainerPtrToValuePtr<FVector>(Asset);
		return V ? *V : FVector::ZeroVector;
	}
}

FQuat FActorPreset_ViewportClient::ReadPropertyRotation(const FProperty* Prop) const
{
	if (!Asset || !IsTransformProperty(Prop)) return FQuat::Identity;
	const FStructProperty* SP = CastField<const FStructProperty>(Prop);
	const FTransform* T = SP->ContainerPtrToValuePtr<FTransform>(Asset);
	return T ? T->GetRotation() : FQuat::Identity;
}


// ── Widget drawing ────────────────────────────────────────────────────────────

void FActorPreset_ViewportClient::Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	FEditorViewportClient::Draw(View, PDI);

	for (FProperty* Prop : CollectEditWidgetProperties())
	{
		const FVector      Location = ReadPropertyLocation(Prop);
		const bool         bSelected = Prop->GetFName() == ActiveWidgetProperty;
		const FLinearColor Color = bSelected
			? FLinearColor(1.f, 0.8f, 0.f)         // gold when selected
			: FLinearColor(0.4f, 0.8f, 1.f, 0.9f); // teal when idle

		PDI->SetHitProxy(new HActorPresetWidgetProxy(Prop->GetFName()));

		// Three orthogonal circles — forms a recognisable wireframe sphere
		const float R = 12.f;
		DrawCircle(PDI, Location, FVector::ForwardVector, FVector::RightVector, Color, R, 16, SDPG_Foreground);
		DrawCircle(PDI, Location, FVector::ForwardVector, FVector::UpVector,    Color, R, 16, SDPG_Foreground);
		DrawCircle(PDI, Location, FVector::RightVector,   FVector::UpVector,    Color, R, 16, SDPG_Foreground);

		PDI->SetHitProxy(nullptr);
	}
}

void FActorPreset_ViewportClient::DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas)
{
	FEditorViewportClient::DrawCanvas(InViewport, View, Canvas);

	UFont* Font = GEngine ? GEngine->GetSmallFont() : nullptr;
	if (!Font) return;

	const FIntPoint ViewportSize = InViewport.GetSizeXY();

	for (FProperty* Prop : CollectEditWidgetProperties())
	{
		const FVector WorldLocation = ReadPropertyLocation(Prop);

		// Project world position → clip space → pixels
		const FPlane Clip = View.Project(WorldLocation);
		if (Clip.W <= 0.f) continue; // behind camera

		const float PixelX = (Clip.X * 0.5f + 0.5f) * ViewportSize.X;
		const float PixelY = (0.5f - Clip.Y * 0.5f) * ViewportSize.Y;

		const bool         bSelected = Prop->GetFName() == ActiveWidgetProperty;
		const FLinearColor TextColor = bSelected
			? FLinearColor(1.f, 0.8f, 0.f)
			: FLinearColor::White;

		// Label offset slightly to the right and above the sphere handle
		FCanvasTextItem TextItem(
			FVector2D(PixelX + 15.f, PixelY - 10.f),
			Prop->GetDisplayNameText(),
			Font, TextColor);
		TextItem.EnableShadow(FLinearColor::Black);
		Canvas.DrawItem(TextItem);
	}
}


// ── Widget state ──────────────────────────────────────────────────────────────

UE::Widget::EWidgetMode FActorPreset_ViewportClient::GetWidgetMode() const
{
	if (ActiveWidgetProperty.IsNone()) return UE::Widget::WM_None;

	const FProperty* Prop = FindProperty(ActiveWidgetProperty);
	if (!Prop) return UE::Widget::WM_None;

	const UE::Widget::EWidgetMode Current = FEditorViewportClient::GetWidgetMode();

	// FVector only makes sense with translate; FTransform supports all modes
	if (!IsTransformProperty(Prop)) return UE::Widget::WM_Translate;

	return (Current == UE::Widget::WM_None) ? UE::Widget::WM_Translate : Current;
}

FVector FActorPreset_ViewportClient::GetWidgetLocation() const
{
	const FProperty* Prop = FindProperty(ActiveWidgetProperty);
	return Prop ? ReadPropertyLocation(Prop) : FEditorViewportClient::GetWidgetLocation();
}


// ── Widget interaction ────────────────────────────────────────────────────────

void FActorPreset_ViewportClient::ProcessClick(
	FSceneView& View, HHitProxy* HitProxy,
	FKey Key, EInputEvent Event,
	uint32 HitX, uint32 HitY)
{
	if (HitProxy && HitProxy->IsA(HActorPresetWidgetProxy::StaticGetType()))
	{
		ActiveWidgetProperty = static_cast<HActorPresetWidgetProxy*>(HitProxy)->PropertyName;
		return; // don't pass to base — we handled it
	}

	// Clicking empty space clears the selection
	if (Key == EKeys::LeftMouseButton)
	{
		ActiveWidgetProperty = NAME_None;
	}

	FEditorViewportClient::ProcessClick(View, HitProxy, Key, Event, HitX, HitY);
}

bool FActorPreset_ViewportClient::InputWidgetDelta(
	FViewport* InViewport, EAxisList::Type CurrentAxis,
	FVector& Drag, FRotator& Rot, FVector& Scale)
{
	if (ActiveWidgetProperty.IsNone() || !Asset) return false;

	FStructProperty* SP = CastField<FStructProperty>(FindProperty(ActiveWidgetProperty));
	if (!SP) return false;

	bool bHandled = false;

	if (SP->Struct == TBaseStructure<FTransform>::Get())
	{
		FTransform* T = SP->ContainerPtrToValuePtr<FTransform>(Asset);
		if (T)
		{
			if (!Drag.IsNearlyZero())  { T->SetLocation(T->GetLocation() + Drag);                        bHandled = true; }
			if (!Rot.IsNearlyZero())   { T->SetRotation(FQuat(Rot) * T->GetRotation());                  bHandled = true; }
			if (!Scale.IsNearlyZero()) { T->SetScale3D(T->GetScale3D() + Scale);                         bHandled = true; }
		}
	}
	else // FVector
	{
		FVector* V = SP->ContainerPtrToValuePtr<FVector>(Asset);
		if (V && !Drag.IsNearlyZero()) { *V += Drag; bHandled = true; }
	}

	if (bHandled)
	{
		// Refresh the preview actor so PreviewConstruct can react to the new values
		RespawnPreviewActor();
	}

	return bHandled;
}

void FActorPreset_ViewportClient::TrackingStopped()
{
	// Commit the property change so the details view and undo/redo pick it up
	if (!ActiveWidgetProperty.IsNone() && Asset)
	{
		if (FProperty* Prop = FindProperty(ActiveWidgetProperty))
		{
			Asset->Modify();
			FPropertyChangedEvent ChangeEvent(Prop, EPropertyChangeType::ValueSet);
			Asset->PostEditChangeProperty(ChangeEvent);
		}
	}

	FEditorViewportClient::TrackingStopped();
}


// ── SActorPreset_Viewport ─────────────────────────────────────────────────────

void SActorPreset_Viewport::Construct(const FArguments& InArgs)
{
	Asset = InArgs._Asset;

	FAdvancedPreviewScene::ConstructionValues CVS;
	CVS.bCreatePhysicsScene    = false;
	CVS.bShouldSimulatePhysics = false;
	PreviewScene = MakeShared<FAdvancedPreviewScene>(CVS);
	PreviewScene->SetFloorVisibility(true);

	SEditorViewport::Construct(SEditorViewport::FArguments());

	if (Client.IsValid())
	{
		Client->SetRealtime(true);
	}
}

SActorPreset_Viewport::~SActorPreset_Viewport()
{
}

TSharedRef<FEditorViewportClient> SActorPreset_Viewport::MakeEditorViewportClient()
{
	return MakeShared<FActorPreset_ViewportClient>(
		Asset,
		SharedThis(this),
		PreviewScene.ToSharedRef());
}

void SActorPreset_Viewport::PopulateViewportOverlays(TSharedRef<SOverlay> Overlay)
{
	SEditorViewport::PopulateViewportOverlays(Overlay);

	Overlay->AddSlot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Top)
		.Padding(FMargin(0.f, 4.f, 4.f, 0.f))
		[
			SNew(SButton)
			.ButtonStyle(FAppStyle::Get(), "SimpleButton")
			.ToolTipText(LOCTEXT("OpenBPTooltip", "Open Actor Blueprint"))
			.Visibility(this, &SActorPreset_Viewport::GetOpenBlueprintVisibility)
			.OnClicked(this, &SActorPreset_Viewport::OnOpenBlueprintClicked)
			.ContentPadding(2.f)
			[
				SNew(SImage)
				.Image(FAppStyle::GetBrush("Icons.Edit"))
				.ColorAndOpacity(FSlateColor::UseForeground())
			]
		];
}

// ── Blueprint navigation ──────────────────────────────────────────────────────

static UClass* GetPresetActorClass(UPrimaryDataAsset* InAsset)
{
	if (!InAsset || !InAsset->Implements<UDataInterface_ActorPreset>()) return nullptr;

	TSubclassOf<AActor> ActorClass;
	bool bPreview = false, bDrop = false, bThumbnail = false;
	IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(InAsset, ActorClass, bPreview, bDrop, bThumbnail);

	return ActorClass;
}

EVisibility SActorPreset_Viewport::GetOpenBlueprintVisibility() const
{
	UClass* ActorClass = GetPresetActorClass(Asset);
	return (ActorClass && ActorClass->ClassGeneratedBy)
		? EVisibility::Visible : EVisibility::Collapsed;
}

FReply SActorPreset_Viewport::OnOpenBlueprintClicked()
{
	UClass* ActorClass = GetPresetActorClass(Asset);
	if (ActorClass && ActorClass->ClassGeneratedBy && GEditor)
	{
		GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()
			->OpenEditorForAsset(ActorClass->ClassGeneratedBy);
	}
	return FReply::Handled();
}

void SActorPreset_Viewport::RefreshPreview()
{
	if (FActorPreset_ViewportClient* VC = static_cast<FActorPreset_ViewportClient*>(Client.Get()))
	{
		VC->RespawnPreviewActor();
	}
}

void SActorPreset_Viewport::UpdateAsset(UPrimaryDataAsset* NewAsset)
{
	Asset = NewAsset;
	if (FActorPreset_ViewportClient* VC = static_cast<FActorPreset_ViewportClient*>(Client.Get()))
	{
		VC->UpdateAsset(NewAsset);
	}
}

#undef LOCTEXT_NAMESPACE
