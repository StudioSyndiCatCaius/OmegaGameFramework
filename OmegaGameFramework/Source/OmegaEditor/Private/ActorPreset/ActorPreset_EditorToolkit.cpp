// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "ActorPreset/ActorPreset_EditorToolkit.h"
#include "ActorPreset/ActorPreset_Viewport.h"
#include "Interfaces/I_ActorPreset.h"
#include "Engine/DataAsset.h"
#include "Engine/Blueprint.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "Widgets/Docking/SDockTab.h"
#include "Styling/AppStyle.h"
#include "Editor.h"
#include "UObject/UObjectGlobals.h"
#include "Subsystems/AssetEditorSubsystem.h"
#include "ToolMenus.h"
#include "Containers/Ticker.h"

#define LOCTEXT_NAMESPACE "ActorPresetEditor"

const FName FActorPresetEditorToolkit::ToolkitAppIdentifier(TEXT("ActorPresetEditorApp"));
const FName FActorPresetEditorToolkit::Tab_Details (TEXT("AP_Details"));
const FName FActorPresetEditorToolkit::Tab_Viewport(TEXT("AP_Viewport"));


FActorPresetEditorToolkit::~FActorPresetEditorToolkit()
{
	if (GEditor)
	{
		GEditor->OnBlueprintPreCompile().Remove(BlueprintPreCompileHandle);
	}
	FCoreUObjectDelegates::OnObjectsReinstanced.Remove(ObjectsReinstancedHandle);
}


void FActorPresetEditorToolkit::InitActorPresetEditor(
	const EToolkitMode::Type        Mode,
	const TSharedPtr<IToolkitHost>& InitToolkitHost,
	UPrimaryDataAsset*               InAsset)
{
	Asset = InAsset;
	check(Asset);

	// Guard against Blueprint recompile while the editor is open
	if (GEditor)
	{
		BlueprintPreCompileHandle = GEditor->OnBlueprintPreCompile().AddRaw(
			this, &FActorPresetEditorToolkit::OnBlueprintPreCompile);
	}

	ObjectsReinstancedHandle = FCoreUObjectDelegates::OnObjectsReinstanced.AddRaw(
		this, &FActorPresetEditorToolkit::OnObjectsReinstanced);

	// Query which features are enabled for this asset
	if (Asset->Implements<UDataInterface_ActorPreset>())
	{
		TSubclassOf<AActor> ActorClass;
		bool bAllowWorldDrop = false, bPreviewThumbnail = false;
		IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(Asset, ActorClass, bEnablePreview, bAllowWorldDrop, bPreviewThumbnail);
	}

	const FString LayoutName = FString::Printf(TEXT("ActorPresetEditor_v1_%d"), bEnablePreview ? 1 : 0);

	TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout(*LayoutName)
	->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)
		->Split
		(
			FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)->SetSizeCoefficient(0.3f)
			->Split(FTabManager::NewStack()->AddTab(Tab_Details, ETabState::OpenedTab))
		)
		->Split
		(
			FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)->SetSizeCoefficient(0.7f)
			->Split(FTabManager::NewStack()
				->AddTab(Tab_Viewport, bEnablePreview ? ETabState::OpenedTab : ETabState::ClosedTab))
		)
	);

	FAssetEditorToolkit::InitAssetEditor(
		Mode, InitToolkitHost, ToolkitAppIdentifier,
		Layout, true, true, Asset);

	ExtendToolbar();
	RegenerateMenusAndToolbars();
}

void FActorPresetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(Tab_Details,
		FOnSpawnTab::CreateSP(this, &FActorPresetEditorToolkit::SpawnTab_Details))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"))
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(Tab_Viewport,
		FOnSpawnTab::CreateSP(this, &FActorPresetEditorToolkit::SpawnTab_Viewport))
		.SetDisplayName(LOCTEXT("ViewportTab", "Preview"))
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"));
}

void FActorPresetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner(Tab_Details);
	InTabManager->UnregisterTabSpawner(Tab_Viewport);
}

TSharedRef<SDockTab> FActorPresetEditorToolkit::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	FPropertyEditorModule& PropModule =
		FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs DetailsArgs;
	DetailsArgs.bAllowSearch      = true;
	DetailsArgs.bHideSelectionTip = true;
	DetailsArgs.NotifyHook        = this;
	DetailsArgs.NameAreaSettings  = FDetailsViewArgs::HideNameArea;

	DetailsView = PropModule.CreateDetailView(DetailsArgs);
	DetailsView->SetObject(Asset);

	return SNew(SDockTab)
		.Label(LOCTEXT("DetailsTab", "Details"))
		[
			DetailsView.ToSharedRef()
		];
}

TSharedRef<SDockTab> FActorPresetEditorToolkit::SpawnTab_Viewport(const FSpawnTabArgs& Args)
{
	Viewport = SNew(SActorPreset_Viewport).Asset(Asset);

	return SNew(SDockTab)
		.Label(LOCTEXT("ViewportTab", "Preview"))
		[
			Viewport.ToSharedRef()
		];
}

void FActorPresetEditorToolkit::NotifyPostChange(
	const FPropertyChangedEvent& /*Event*/,
	FProperty*                   /*Property*/)
{
	// Guard: asset may be temporarily invalid during Blueprint reinstancing
	if (!Asset || !IsValid(Asset) || !IsValid(Asset->GetClass())) return;

	const bool bWasPreview = bEnablePreview;
	if (Asset->Implements<UDataInterface_ActorPreset>())
	{
		TSubclassOf<AActor> ActorClass;
		bool bAllowWorldDrop = false, bPreviewThumbnail = false;
		IDataInterface_ActorPreset::Execute_ActorPreset_GetConfig(Asset, ActorClass, bEnablePreview, bAllowWorldDrop, bPreviewThumbnail);
	}

	if (!bWasPreview && bEnablePreview)
	{
		TabManager->TryInvokeTab(Tab_Viewport);
	}

	if (Viewport.IsValid())
	{
		// Defer the refresh to the next tick. Property changes (especially to
		// NiagaraSystem references) may leave Niagara's parameter store in a
		// transitional state during this callback, causing SetAsset to crash.
		TWeakPtr<SActorPreset_Viewport> WeakViewport = Viewport;
		FTSTicker::GetCoreTicker().AddTicker(
			FTickerDelegate::CreateLambda([WeakViewport](float) -> bool
			{
				if (TSharedPtr<SActorPreset_Viewport> VP = WeakViewport.Pin())
				{
					VP->RefreshPreview();
				}
				return false;
			}), 0.0f);
	}
}

// ── Blueprint recompile safety ────────────────────────────────────────────────

void FActorPresetEditorToolkit::OnBlueprintPreCompile(UBlueprint* Blueprint)
{
	if (!Asset || !Blueprint) return;

	UClass* AssetClass = Asset->GetClass();
	if (!AssetClass) return;

	// ClassGeneratedBy links a generated class back to its source Blueprint
	if (AssetClass->ClassGeneratedBy != Blueprint) return;

	// Clear the DetailsView BEFORE compilation invalidates the class so that
	// Slate widgets (e.g. SpinBox pending commits) cannot reach the zombie object.
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject(nullptr);
	}
}

void FActorPresetEditorToolkit::OnObjectsReinstanced(const TMap<UObject*, UObject*>& OldToNew)
{
	if (!Asset) return;

	// Check if our Asset was replaced by a new instance
	UObject* const* NewObj = OldToNew.Find(Asset);
	if (NewObj && *NewObj)
	{
		Asset = Cast<UPrimaryDataAsset>(*NewObj);
	}

	// Restore the DetailsView with whichever instance is now live
	if (DetailsView.IsValid() && Asset && IsValid(Asset))
	{
		DetailsView->SetObject(Asset);
	}

	// Push the new asset pointer into the viewport (its client has its own copy)
	// then respawn the preview actor for the new instance
	if (Viewport.IsValid() && Asset)
	{
		Viewport->UpdateAsset(Asset);
	}
}

// ── Toolbar ───────────────────────────────────────────────────────────────────

void FActorPresetEditorToolkit::ExtendToolbar()
{
	UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu(
		"AssetEditor.ActorPresetEditor.ToolBar");

	FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("ActorPresetActions");
	Section.AddEntry(FToolMenuEntry::InitToolBarButton(
		"OpenBlueprintParent",
		FUIAction(
			FExecuteAction::CreateSP(this, &FActorPresetEditorToolkit::OnOpenBlueprintClicked),
			FCanExecuteAction::CreateSP(this, &FActorPresetEditorToolkit::CanOpenBlueprint)),
		LOCTEXT("OpenBP", "Edit Data Asset Blueprint"),
		LOCTEXT("OpenBPTooltip", "Open the Blueprint class used for this Data Asset"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Edit")));
}

bool FActorPresetEditorToolkit::CanOpenBlueprint() const
{
	return Asset && Asset->GetClass() && Asset->GetClass()->ClassGeneratedBy != nullptr;
}

void FActorPresetEditorToolkit::OnOpenBlueprintClicked()
{
	if (!CanOpenBlueprint() || !GEditor) return;

	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()
		->OpenEditorForAsset(Asset->GetClass()->ClassGeneratedBy);
}

FText FActorPresetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Actor Preset Editor");
}

FText FActorPresetEditorToolkit::GetToolkitName() const
{
	return FText::FromString(Asset ? Asset->GetName() : TEXT("ActorPreset"));
}

#undef LOCTEXT_NAMESPACE
