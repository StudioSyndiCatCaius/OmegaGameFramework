#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Misc/NotifyHook.h"
#include "OmegaGameAsset.h"

class SGameplayAsset3DViewport;
class SGraphEditor;
class UGameplayAssetGraph;
class IDetailsView;


class FGameplayAssetEditorToolkit : public FAssetEditorToolkit, public FNotifyHook
{
public:
    static const FName ToolkitAppIdentifier;
    static const FName Tab_Details;
    static const FName Tab_3DViewport;
    static const FName Tab_FlowGraph;

    // FAssetEditorToolkit interface
    virtual FName   GetToolkitFName()                  const override { return TEXT("GameplayAssetEditor"); }
    virtual FText   GetBaseToolkitName()               const override;
    virtual FText   GetToolkitName()                   const override;
    virtual FString GetWorldCentricTabPrefix()         const override { return TEXT("GameplayAsset"); }
    virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor(0.3f, 0.2f, 0.5f, 0.5f); }

    virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)   override;
    virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

    void InitGameplayAssetEditor(const EToolkitMode::Type Mode,
                                 const TSharedPtr<IToolkitHost>& InitToolkitHost,
                                 UOmegaGameAsset* InAsset);

    UOmegaGameAsset* GetAsset() const { return Asset.Get(); }

    void OnCommitAll();

    // Clipboard actions
    void OnCopyNodes();
    void OnCutNodes();
    void OnPasteNodes();
    void OnDuplicateNodes();
    bool CanCopyNodes()    const;
    bool CanPasteNodes()   const;

    // FNotifyHook interface
    virtual void NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent,
                                  FProperty* PropertyThatChanged) override;

private:
    TSharedRef<SDockTab> SpawnTab_Details    (const FSpawnTabArgs& Args);
    TSharedRef<SDockTab> SpawnTab_3DViewport (const FSpawnTabArgs& Args);
    TSharedRef<SDockTab> SpawnTab_FlowGraph  (const FSpawnTabArgs& Args);

    void BindCommands();
    void ExtendToolbar();

    void OnNodeTitleCommitted(const FText& NewText, ETextCommit::Type CommitType, UEdGraphNode* NodeBeingChanged);
    void OnFlowGraphSelectionChanged(const FGraphPanelSelectionSet& Selection);

    TObjectPtr<UOmegaGameAsset>          Asset;
    TSharedPtr<IDetailsView>             DetailsView;
    TSharedPtr<IDetailsView>             FlowNodeDetailsView;
    TSharedPtr<SGameplayAsset3DViewport> Viewport3D;
    TSharedPtr<SGraphEditor>             FlowGraphEditor;
    TObjectPtr<UGameplayAssetGraph>      EditorGraph;

    bool bEnable3D   = false;
    bool bEnableFlow = false;
};
