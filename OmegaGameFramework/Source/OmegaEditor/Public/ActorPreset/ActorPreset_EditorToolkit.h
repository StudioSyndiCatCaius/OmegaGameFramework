// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Misc/NotifyHook.h"

class SActorPreset_Viewport;
class IDetailsView;
class UPrimaryDataAsset;
class UBlueprint;


class FActorPresetEditorToolkit : public FAssetEditorToolkit, public FNotifyHook
{
public:
	static const FName ToolkitAppIdentifier;
	static const FName Tab_Details;
	static const FName Tab_Viewport;

	virtual ~FActorPresetEditorToolkit() override;

	// FAssetEditorToolkit interface
	virtual FName        GetToolkitFName()              const override { return TEXT("ActorPresetEditor"); }
	virtual FText        GetBaseToolkitName()           const override;
	virtual FText        GetToolkitName()               const override;
	virtual FString      GetWorldCentricTabPrefix()     const override { return TEXT("ActorPreset"); }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor(0.2f, 0.5f, 0.3f, 0.5f); }

	virtual void RegisterTabSpawners  (const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	void InitActorPresetEditor(const EToolkitMode::Type        Mode,
	                           const TSharedPtr<IToolkitHost>& InitToolkitHost,
	                           UPrimaryDataAsset*               InAsset);

	// FNotifyHook interface
	virtual void NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent,
	                              FProperty* PropertyThatChanged) override;

private:
	TSharedRef<SDockTab> SpawnTab_Details (const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Viewport(const FSpawnTabArgs& Args);

	// ── Blueprint recompile safety ────────────────────────────────────────────
	// Called just before a Blueprint is compiled: clears the DetailsView so
	// Slate cannot interact with the soon-to-be-zombie object.
	void OnBlueprintPreCompile(UBlueprint* Blueprint);
	void OnObjectsReinstanced(const TMap<UObject*, UObject*>& OldToNew);

	void ExtendToolbar();
	void OnOpenBlueprintClicked();
	bool CanOpenBlueprint() const;

	TObjectPtr<UPrimaryDataAsset>     Asset;
	TSharedPtr<IDetailsView>          DetailsView;
	TSharedPtr<SActorPreset_Viewport> Viewport;
	bool bEnablePreview = false;

	FDelegateHandle BlueprintPreCompileHandle;
	FDelegateHandle ObjectsReinstancedHandle;
};
