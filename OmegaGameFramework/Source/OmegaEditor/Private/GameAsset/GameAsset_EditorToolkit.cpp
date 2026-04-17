#include "GameAsset/GameAsset_EditorToolkit.h"
#include "GameAsset/GameAsset_3DViewport.h"
#include "GameAsset/GameAsset_FlowGraph.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "GraphEditor.h"
#include "GraphEditorActions.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/GenericCommands.h"
#include "Widgets/Docking/SDockTab.h"
#include "Styling/AppStyle.h"
#include "ToolMenus.h"
#include "ScopedTransaction.h"
#include "EdGraphUtilities.h"
#include "HAL/PlatformApplicationMisc.h"

#define LOCTEXT_NAMESPACE "GameplayAssetEditor"

const FName FGameplayAssetEditorToolkit::ToolkitAppIdentifier(TEXT("GameplayAssetEditorApp"));
const FName FGameplayAssetEditorToolkit::Tab_Details    (TEXT("GA_Details"));
const FName FGameplayAssetEditorToolkit::Tab_3DViewport (TEXT("GA_3DViewport"));
const FName FGameplayAssetEditorToolkit::Tab_FlowGraph  (TEXT("GA_FlowGraph"));


void FGameplayAssetEditorToolkit::InitGameplayAssetEditor(
    const EToolkitMode::Type        Mode,
    const TSharedPtr<IToolkitHost>& InitToolkitHost,
    UOmegaGameAsset*                 InAsset)
{
    Asset = InAsset;
    check(Asset);

    Asset->GetEnabledEditors(bEnable3D, bEnableFlow);

    // ── Build editor graph ────────────────────────────────────────────────────
    if (bEnableFlow)
    {
        EditorGraph = NewObject<UGameplayAssetGraph>(Asset, UGameplayAssetGraph::StaticClass(),
                                                     NAME_None, RF_Transient);
        EditorGraph->Schema      = UGameplayAssetGraphSchema::StaticClass();
        EditorGraph->OwningAsset = Asset;
        EditorGraph->RebuildFromAsset();
    }

    // ── Layout ────────────────────────────────────────────────────────────────
    // Unique layout name per flag combination + version suffix so stale cached
    // layouts (from when tabs were disabled) are never restored incorrectly.
    const FString LayoutName = FString::Printf(TEXT("GameplayAssetEditor_v2_%d%d"),
        bEnable3D ? 1 : 0, bEnableFlow ? 1 : 0);

    TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout(*LayoutName)
    ->AddArea
    (
        FTabManager::NewPrimaryArea()->SetOrientation(Orient_Horizontal)
        ->Split
        (
            FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)->SetSizeCoefficient(0.25f)
            ->Split(FTabManager::NewStack()->AddTab(Tab_Details, ETabState::OpenedTab))
        )
        ->Split
        (
            FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)->SetSizeCoefficient(0.75f)
            ->Split(FTabManager::NewStack()
                ->AddTab(Tab_3DViewport, bEnable3D   ? ETabState::OpenedTab : ETabState::ClosedTab)
                ->AddTab(Tab_FlowGraph,  bEnableFlow  ? ETabState::OpenedTab : ETabState::ClosedTab))
        )
    );

    BindCommands();

    FAssetEditorToolkit::InitAssetEditor(
        Mode, InitToolkitHost, ToolkitAppIdentifier,
        Layout, true, true, Asset);

    ExtendToolbar();
    RegenerateMenusAndToolbars();
}

void FGameplayAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

    InTabManager->RegisterTabSpawner(Tab_Details,
        FOnSpawnTab::CreateSP(this, &FGameplayAssetEditorToolkit::SpawnTab_Details))
        .SetDisplayName(LOCTEXT("DetailsTab", "Details"))
        .SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));

    // Always register both — visibility is controlled by the layout open/closed state,
    // not by whether the spawner exists. Conditional registration caused stale layout
    // caches to permanently hide tabs even after the flags were enabled.
    InTabManager->RegisterTabSpawner(Tab_3DViewport,
        FOnSpawnTab::CreateSP(this, &FGameplayAssetEditorToolkit::SpawnTab_3DViewport))
        .SetDisplayName(LOCTEXT("ViewportTab", "3D Scene"))
        .SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"));

    InTabManager->RegisterTabSpawner(Tab_FlowGraph,
        FOnSpawnTab::CreateSP(this, &FGameplayAssetEditorToolkit::SpawnTab_FlowGraph))
        .SetDisplayName(LOCTEXT("FlowGraphTab", "Flow Graph"))
        .SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "GraphEditor.EventGraph_16x"));
}

void FGameplayAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
    InTabManager->UnregisterTabSpawner(Tab_Details);
    InTabManager->UnregisterTabSpawner(Tab_3DViewport);
    InTabManager->UnregisterTabSpawner(Tab_FlowGraph);
}

TSharedRef<SDockTab> FGameplayAssetEditorToolkit::SpawnTab_Details(const FSpawnTabArgs& Args)
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

TSharedRef<SDockTab> FGameplayAssetEditorToolkit::SpawnTab_3DViewport(const FSpawnTabArgs& Args)
{
    Viewport3D = SNew(SGameplayAsset3DViewport).Asset(Asset);

    return SNew(SDockTab)
        .Label(LOCTEXT("ViewportTab", "3D Scene"))
        [
            Viewport3D.ToSharedRef()
        ];
}

TSharedRef<SDockTab> FGameplayAssetEditorToolkit::SpawnTab_FlowGraph(const FSpawnTabArgs& Args)
{
    // ── Node details view ─────────────────────────────────────────────────────
    FPropertyEditorModule& PropModule =
        FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

    FDetailsViewArgs NodeDetailsArgs;
    NodeDetailsArgs.bAllowSearch             = false;
    NodeDetailsArgs.bHideSelectionTip        = true;
    NodeDetailsArgs.NameAreaSettings         = FDetailsViewArgs::HideNameArea;
    NodeDetailsArgs.bShowPropertyMatrixButton = false;
    NodeDetailsArgs.bAllowMultipleTopLevelObjects = true;

    FlowNodeDetailsView = PropModule.CreateDetailView(NodeDetailsArgs);
    FlowNodeDetailsView->SetObject(nullptr); // empty until a node is selected

    // ── Graph editor ──────────────────────────────────────────────────────────
    SGraphEditor::FGraphEditorEvents GraphEvents;
    GraphEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(
        this, &FGameplayAssetEditorToolkit::OnNodeTitleCommitted);
    GraphEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(
        this, &FGameplayAssetEditorToolkit::OnFlowGraphSelectionChanged);

    FlowGraphEditor = SNew(SGraphEditor)
        .AdditionalCommands(GetToolkitCommands())
        .GraphToEdit(EditorGraph)
        .GraphEvents(GraphEvents)
        .IsEditable(true)
        .TitleBar(SNullWidget::NullWidget);

    // ── Layout: graph on left, node details on right ──────────────────────────
    return SNew(SDockTab)
        .Label(LOCTEXT("FlowGraphTab", "Flow Graph"))
        [
            SNew(SSplitter)
            .Orientation(Orient_Horizontal)
            + SSplitter::Slot()
            .Value(0.75f)
            [
                FlowGraphEditor.ToSharedRef()
            ]
            + SSplitter::Slot()
            .Value(0.25f)
            [
                SNew(SBorder)
                .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
                [
                    FlowNodeDetailsView.ToSharedRef()
                ]
            ]
        ];
}

void FGameplayAssetEditorToolkit::OnFlowGraphSelectionChanged(const FGraphPanelSelectionSet& Selection)
{
    if (!FlowNodeDetailsView.IsValid()) return;

    TArray<UObject*> SelectedNodes;
    for (UObject* Obj : Selection)
    {
        if (UGameplayAssetGraphNode* GraphNode = Cast<UGameplayAssetGraphNode>(Obj))
        {
            if (GraphNode->RuntimeNode)
            {
                SelectedNodes.Add(GraphNode->RuntimeNode);
            }
        }
    }

    FlowNodeDetailsView->SetObjects(SelectedNodes);
}

void FGameplayAssetEditorToolkit::OnNodeTitleCommitted(const FText& NewText,
                                                        ETextCommit::Type CommitType,
                                                        UEdGraphNode* NodeBeingChanged)
{
    if (NodeBeingChanged)
    {
        const FScopedTransaction Transaction(LOCTEXT("RenameNode", "Rename Node"));
        NodeBeingChanged->Modify();
        NodeBeingChanged->OnRenameNode(NewText.ToString());
    }
}

void FGameplayAssetEditorToolkit::BindCommands()
{
    const FGenericCommands& Cmds = FGenericCommands::Get();

    GetToolkitCommands()->MapAction(Cmds.Copy,
        FExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::OnCopyNodes),
        FCanExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::CanCopyNodes));

    GetToolkitCommands()->MapAction(Cmds.Cut,
        FExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::OnCutNodes),
        FCanExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::CanCopyNodes));

    GetToolkitCommands()->MapAction(Cmds.Paste,
        FExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::OnPasteNodes),
        FCanExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::CanPasteNodes));

    GetToolkitCommands()->MapAction(Cmds.Duplicate,
        FExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::OnDuplicateNodes),
        FCanExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::CanCopyNodes));

    GetToolkitCommands()->MapAction(Cmds.Delete,
        FExecuteAction::CreateLambda([this]()
        {
            if (!FlowGraphEditor.IsValid()) return;
            const FGraphPanelSelectionSet Selected = FlowGraphEditor->GetSelectedNodes();
            for (UObject* Obj : Selected)
            {
                if (UGameplayAssetGraphNode* GraphNode = Cast<UGameplayAssetGraphNode>(Obj))
                {
                    const FScopedTransaction Transaction(LOCTEXT("DeleteNode", "Delete Node"));
                    if (GraphNode->RuntimeNode && Asset)
                    {
                        Asset->RemoveFlowNode(GraphNode->RuntimeNode->NodeGuid);
                    }
                    GraphNode->BreakAllNodeLinks();
                    FlowGraphEditor->GetCurrentGraph()->RemoveNode(GraphNode);
                }
            }
            if (EditorGraph) EditorGraph->CommitToAsset();
            if (FlowNodeDetailsView.IsValid()) FlowNodeDetailsView->SetObjects(TArray<UObject*>());
        }),
        FCanExecuteAction::CreateLambda([this]()
        {
            return FlowGraphEditor.IsValid() &&
                   FlowGraphEditor->GetSelectedNodes().Num() > 0;
        })
    );
}

bool FGameplayAssetEditorToolkit::CanCopyNodes() const
{
    if (!FlowGraphEditor.IsValid()) return false;
    return FlowGraphEditor->GetSelectedNodes().Num() > 0;
}

bool FGameplayAssetEditorToolkit::CanPasteNodes() const
{
    if (!FlowGraphEditor.IsValid()) return false;
    FString ClipboardContent;
    FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);
    return FEdGraphUtilities::CanImportNodesFromText(EditorGraph, ClipboardContent);
}

void FGameplayAssetEditorToolkit::OnCopyNodes()
{
    if (!FlowGraphEditor.IsValid()) return;

    // PrepareForCopying moves RuntimeNode outer to the graph node so it serialises
    const FGraphPanelSelectionSet Selected = FlowGraphEditor->GetSelectedNodes();
    for (UObject* Obj : Selected)
    {
        if (UGameplayAssetGraphNode* Node = Cast<UGameplayAssetGraphNode>(Obj))
        {
            Node->PrepareForCopying();
        }
    }

    FString ExportText;
    FEdGraphUtilities::ExportNodesToText(Selected, ExportText);
    FPlatformApplicationMisc::ClipboardCopy(*ExportText);

    // Restore RuntimeNode outers back to the asset after export
    for (UObject* Obj : Selected)
    {
        if (UGameplayAssetGraphNode* Node = Cast<UGameplayAssetGraphNode>(Obj))
        {
            if (Node->RuntimeNode)
            {
                Node->RuntimeNode->Rename(nullptr, Asset, REN_DontCreateRedirectors);
            }
        }
    }
}

void FGameplayAssetEditorToolkit::OnCutNodes()
{
    OnCopyNodes();

    // Delete selected after copying
    const FGraphPanelSelectionSet Selected = FlowGraphEditor->GetSelectedNodes();
    const FScopedTransaction Transaction(LOCTEXT("CutNodes", "Cut Nodes"));
    for (UObject* Obj : Selected)
    {
        if (UGameplayAssetGraphNode* GraphNode = Cast<UGameplayAssetGraphNode>(Obj))
        {
            if (GraphNode->RuntimeNode && Asset)
            {
                Asset->RemoveFlowNode(GraphNode->RuntimeNode->NodeGuid);
            }
            GraphNode->BreakAllNodeLinks();
            FlowGraphEditor->GetCurrentGraph()->RemoveNode(GraphNode);
        }
    }
    if (EditorGraph) EditorGraph->CommitToAsset();
    if (FlowNodeDetailsView.IsValid()) FlowNodeDetailsView->SetObjects(TArray<UObject*>());
}

void FGameplayAssetEditorToolkit::OnPasteNodes()
{
    if (!FlowGraphEditor.IsValid() || !EditorGraph || !Asset) return;

    const FScopedTransaction Transaction(LOCTEXT("PasteNodes", "Paste Nodes"));
    EditorGraph->Modify();
    Asset->Modify();

    // Deselect all before pasting so new nodes become the selection
    FlowGraphEditor->ClearSelectionSet();

    FString ClipboardContent;
    FPlatformApplicationMisc::ClipboardPaste(ClipboardContent);

    TSet<UEdGraphNode*> PastedNodes;
    FEdGraphUtilities::ImportNodesFromText(EditorGraph, ClipboardContent, PastedNodes);

    // Offset pasted nodes slightly so they don't land exactly on originals
    FVector2D AvgPos(0.f, 0.f);
    for (UEdGraphNode* Node : PastedNodes) { AvgPos.X += Node->NodePosX; AvgPos.Y += Node->NodePosY; }
    if (PastedNodes.Num() > 0) AvgPos /= PastedNodes.Num();

    for (UEdGraphNode* Node : PastedNodes)
    {
        Node->NodePosX += 30 + (Node->NodePosX - AvgPos.X);
        Node->NodePosY += 30 + (Node->NodePosY - AvgPos.Y);

        if (UGameplayAssetGraphNode* AssetNode = Cast<UGameplayAssetGraphNode>(Node))
        {
            // PostPasteNode gives the RuntimeNode a fresh GUID
            AssetNode->PostPasteNode();

            // Clear serialized pins before reallocating — paste serialises pins
            // into the node, so without this they get duplicated
            AssetNode->Pins.Empty();
            AssetNode->AllocateDefaultPins();

            // Register the runtime node with the asset
            if (AssetNode->RuntimeNode)
            {
                AssetNode->RuntimeNode->Rename(nullptr, Asset, REN_DontCreateRedirectors);
                Asset->FlowNodes.Add(AssetNode->RuntimeNode);
            }
        }

        FlowGraphEditor->SetNodeSelection(Node, true);
    }

    EditorGraph->CommitToAsset();
    FlowGraphEditor->NotifyGraphChanged();
}

void FGameplayAssetEditorToolkit::OnDuplicateNodes()
{
    // Duplicate = copy to clipboard then immediately paste
    OnCopyNodes();
    OnPasteNodes();
}

void FGameplayAssetEditorToolkit::ExtendToolbar()
{
    UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu(
        "AssetEditor.GameplayAssetEditor.ToolBar");

    FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("GameplayAssetActions");
    Section.AddEntry(FToolMenuEntry::InitToolBarButton(
        "CommitAll",
        FUIAction(FExecuteAction::CreateSP(this, &FGameplayAssetEditorToolkit::OnCommitAll)),
        LOCTEXT("CommitAll", "Commit"),
        LOCTEXT("CommitAllTooltip", "Commit 3D scene and flow graph changes to the asset"),
        FSlateIcon(FAppStyle::GetAppStyleSetName(), "AssetEditor.SaveAsset")));
}

void FGameplayAssetEditorToolkit::OnCommitAll()
{
    if (Viewport3D.IsValid())
    {
        Viewport3D->CommitScene();
    }
    if (EditorGraph)
    {
        EditorGraph->CommitToAsset();
    }
    if (Asset)
    {
        Asset->MarkPackageDirty();
    }
}

void FGameplayAssetEditorToolkit::NotifyPostChange(
    const FPropertyChangedEvent& PropertyChangedEvent,
    FProperty* PropertyThatChanged)
{
    if (!Asset) return;

    const bool bWas3D   = bEnable3D;
    const bool bWasFlow = bEnableFlow;
    Asset->GetEnabledEditors(bEnable3D, bEnableFlow);

    if (!bWas3D && bEnable3D)
    {
        TabManager->TryInvokeTab(Tab_3DViewport);
    }
    if (!bWasFlow && bEnableFlow)
    {
        TabManager->TryInvokeTab(Tab_FlowGraph);
    }
}

FText FGameplayAssetEditorToolkit::GetBaseToolkitName() const
{
    return LOCTEXT("AppLabel", "Gameplay Asset Editor");
}

FText FGameplayAssetEditorToolkit::GetToolkitName() const
{
    return FText::FromString(Asset ? Asset->GetName() : TEXT("GameplayAsset"));
}

#undef LOCTEXT_NAMESPACE
