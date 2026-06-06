#include "GameAsset/GameAsset_FlowGraph.h"
#include "NodeFactory.h"
#include "EdGraph/EdGraphPin.h"
#include "Framework/Commands/GenericCommands.h"
#include "GraphEditorActions.h"
#include "ScopedTransaction.h"
#include "SGraphPin.h"

// ── Pin category ──────────────────────────────────────────────────────────────
const FName UGameplayAssetGraphSchema::PC_Flow(TEXT("FlowExec"));

// ── UGameplayAssetGraphNode ───────────────────────────────────────────────────

void UGameplayAssetGraphNode::AllocateDefaultPins()
{
    if (!RuntimeNode) return;

    TArray<FOmegaGameplayAssetFlowPin> Inputs, Outputs;
    RuntimeNode->FlowNode_GetConnectionPorts(Inputs, Outputs);

    for (const FOmegaGameplayAssetFlowPin& Pin : Inputs)
    {
        UEdGraphPin* NewPin = CreatePin(EGPD_Input, UGameplayAssetGraphSchema::PC_Flow, Pin.PinName);
        NewPin->PinFriendlyName = Pin.DisplayName;
        NewPin->PinType.PinSubCategory = NAME_None;
    }

    for (const FOmegaGameplayAssetFlowPin& Pin : Outputs)
    {
        UEdGraphPin* NewPin = CreatePin(EGPD_Output, UGameplayAssetGraphSchema::PC_Flow, Pin.PinName);
        NewPin->PinFriendlyName = Pin.DisplayName;
        NewPin->PinType.PinSubCategory = NAME_None;
    }
}

FText UGameplayAssetGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    if (RuntimeNode)
    {
        return RuntimeNode->GetNodeTitle();
    }
    return NSLOCTEXT("GameplayAsset", "UnknownNode", "Unknown Node");
}

UEdGraphPin* UGameplayAssetGraphNode::GetInputPin() const
{
    for (UEdGraphPin* Pin : Pins)
    {
        if (Pin->Direction == EGPD_Input) return Pin;
    }
    return nullptr;
}

UEdGraphPin* UGameplayAssetGraphNode::GetOutputPin() const
{
    for (UEdGraphPin* Pin : Pins)
    {
        if (Pin->Direction == EGPD_Output) return Pin;
    }
    return nullptr;
}

void UGameplayAssetGraphNode::NodeConnectionListChanged()
{
    UEdGraphNode::NodeConnectionListChanged();
    if (UGameplayAssetGraph* G = Cast<UGameplayAssetGraph>(GetGraph()))
    {
        G->CommitToAsset();
    }
}

void UGameplayAssetGraphNode::AutowireNewNode(UEdGraphPin* FromPin)
{
    if (!FromPin) return;
    UEdGraphPin* ToPin = (FromPin->Direction == EGPD_Output) ? GetInputPin() : GetOutputPin();
    if (ToPin && GetSchema()->TryCreateConnection(FromPin, ToPin))
    {
        FromPin->GetOwningNode()->NodeConnectionListChanged();
    }
}

void UGameplayAssetGraphNode::PrepareForCopying()
{
    if (RuntimeNode)
    {
        RuntimeNode->Rename(nullptr, this, REN_DontCreateRedirectors);
    }
}

void UGameplayAssetGraphNode::PostPasteNode()
{
    UEdGraphNode::PostPasteNode();
    if (RuntimeNode)
    {
        RuntimeNode->NodeGuid = FGuid::NewGuid();
        RuntimeNode->Rename(nullptr, GetGraph()->GetOuter(), REN_DontCreateRedirectors);
    }
}

void UGameplayAssetGraphNode::OnUpdateCommentText(const FString& NewComment)
{
    if (RuntimeNode)
    {
        FScopedTransaction Transaction(NSLOCTEXT("GameplayAsset", "UpdateComment", "Update Node Comment"));
        Modify();
        NodeComment = NewComment;
    }
}


// ── UGameplayAssetGraph ───────────────────────────────────────────────────────

void UGameplayAssetGraph::CommitToAsset()
{
    if (!OwningAsset) return;

    OwningAsset->Modify();
    OwningAsset->FlowConnections.Empty();

    for (UEdGraphNode* GraphNode : Nodes)
    {
        UGameplayAssetGraphNode* FlowGraphNode = Cast<UGameplayAssetGraphNode>(GraphNode);
        if (!FlowGraphNode || !FlowGraphNode->RuntimeNode) continue;

        FlowGraphNode->RuntimeNode->NodePosition = FVector2D(GraphNode->NodePosX, GraphNode->NodePosY);

        for (UEdGraphPin* Pin : FlowGraphNode->Pins)
        {
            if (Pin->Direction != EGPD_Output) continue;

            for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
            {
                if (UGameplayAssetGraphNode* TargetNode = Cast<UGameplayAssetGraphNode>(LinkedPin->GetOwningNode()))
                {
                    if (TargetNode->RuntimeNode)
                    {
                        FGameplayAssetFlowConnectionList& List = OwningAsset->FlowConnections.FindOrAdd(
                            FlowGraphNode->RuntimeNode->NodeGuid);
                        List.Targets.AddUnique(TargetNode->RuntimeNode->NodeGuid);
                    }
                }
            }
        }
    }
}

void UGameplayAssetGraph::RebuildFromAsset()
{
    if (!OwningAsset) return;

    for (int32 i = Nodes.Num() - 1; i >= 0; --i)
    {
        Nodes[i]->BreakAllNodeLinks();
        RemoveNode(Nodes[i]);
    }

    TMap<FGuid, UGameplayAssetGraphNode*> GuidToGraphNode;
    for (UOmegaGameAsset_FlowNode* RuntimeNode : OwningAsset->FlowNodes)
    {
        if (!RuntimeNode) continue;

        UGameplayAssetGraphNode* GraphNode = NewObject<UGameplayAssetGraphNode>(this);
        GraphNode->RuntimeNode = RuntimeNode;
        GraphNode->NodePosX    = RuntimeNode->NodePosition.X;
        GraphNode->NodePosY    = RuntimeNode->NodePosition.Y;
        GraphNode->CreateNewGuid();
        GraphNode->PostPlacedNewNode();
        GraphNode->AllocateDefaultPins();
        AddNode(GraphNode, false, false);

        GuidToGraphNode.Add(RuntimeNode->NodeGuid, GraphNode);
    }

    for (const TPair<FGuid, FGameplayAssetFlowConnectionList>& Conn : OwningAsset->FlowConnections)
    {
        UGameplayAssetGraphNode** FromNode = GuidToGraphNode.Find(Conn.Key);
        if (!FromNode) continue;

        UEdGraphPin* OutPin = (*FromNode)->GetOutputPin();
        if (!OutPin) continue;

        for (const FGuid& TargetGuid : Conn.Value.Targets)
        {
            UGameplayAssetGraphNode** ToNode = GuidToGraphNode.Find(TargetGuid);
            if (!ToNode) continue;

            UEdGraphPin* InPin = (*ToNode)->GetInputPin();
            if (InPin)
            {
                OutPin->MakeLinkTo(InPin);
            }
        }
    }
}


// ── UGameplayAssetGraphSchema ─────────────────────────────────────────────────

void UGameplayAssetGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
}

void UGameplayAssetGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
    const UGameplayAssetGraph* AssetGraph = Cast<UGameplayAssetGraph>(ContextMenuBuilder.CurrentGraph);
    if (!AssetGraph || !AssetGraph->OwningAsset) return;

    bool bEnable3D, bEnableFlow;
    AssetGraph->OwningAsset->GetEnabledEditors(bEnable3D, bEnableFlow);
    if (!bEnableFlow) return;

    TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> AvailableClasses =
        AssetGraph->OwningAsset->L_GetAllAvailableNodes();

    for (TSubclassOf<UOmegaGameAsset_FlowNode> NodeClass : AvailableClasses)
    {
        if (!NodeClass) continue;

        // Resolve display name: GetNodeTitle CDO call > BlueprintDisplayName meta > class name
        FText NodeName;
        if (const UOmegaGameAsset_FlowNode* CDO = NodeClass->GetDefaultObject<UOmegaGameAsset_FlowNode>())
        {
            const FText TitleText = CDO->GetNodeTitle();
            if (!TitleText.IsEmpty() && !TitleText.EqualTo(FText::FromString(NodeClass->GetName())))
            {
                NodeName = TitleText;
            }
        }
        if (NodeName.IsEmpty())
        {
            const FString& DisplayName = NodeClass->GetMetaData(TEXT("BlueprintDisplayName"));
            if (!DisplayName.IsEmpty())
            {
                NodeName = FText::FromString(DisplayName);
            }
        }
        if (NodeName.IsEmpty())
        {
            NodeName = FText::FromString(NodeClass->GetName());
        }

        const FString ClassCategory= NodeClass->GetMetaData(TEXT("Category"));
        const FText ActionCategory  = ClassCategory.IsEmpty()
            ? NSLOCTEXT("GameplayAsset", "DefaultFlowNodeCategory", "Flow Node")
            : FText::FromString(ClassCategory);
        
        struct FAddNodeAction : public FEdGraphSchemaAction
        {
            TSubclassOf<UOmegaGameAsset_FlowNode> Class;

            FAddNodeAction(TSubclassOf<UOmegaGameAsset_FlowNode> InClass, FText InName, FText InCategory)
                : FEdGraphSchemaAction(
                    InCategory,
                    InName, FText::GetEmpty(), 0)
                , Class(InClass) {}

            virtual UEdGraphNode* PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
                                                 const FVector2D Location, bool bSelectNewNode) override
            {
                UGameplayAssetGraph* G = Cast<UGameplayAssetGraph>(ParentGraph);
                if (!G || !G->OwningAsset) return nullptr;

                FScopedTransaction Transaction(NSLOCTEXT("GameplayAsset", "AddNode", "Add Flow Node"));
                G->Modify();
                G->OwningAsset->Modify();

                UOmegaGameAsset_FlowNode* RuntimeNode = G->OwningAsset->AddFlowNode(Class);
                if (!RuntimeNode) return nullptr;

                UGameplayAssetGraphNode* GraphNode = NewObject<UGameplayAssetGraphNode>(G);
                GraphNode->RuntimeNode    = RuntimeNode;
                GraphNode->NodePosX       = Location.X;
                GraphNode->NodePosY       = Location.Y;
                RuntimeNode->NodePosition = Location;
                GraphNode->CreateNewGuid();
                GraphNode->PostPlacedNewNode();
                GraphNode->AllocateDefaultPins();
                G->AddNode(GraphNode, true, bSelectNewNode);

                if (FromPin)
                {
                    GraphNode->AutowireNewNode(FromPin);
                }
                return GraphNode;
            }
        };

        ContextMenuBuilder.AddAction(MakeShared<FAddNodeAction>(NodeClass, NodeName,ActionCategory));
    }
}

const FPinConnectionResponse UGameplayAssetGraphSchema::CanCreateConnection(
    const UEdGraphPin* A, const UEdGraphPin* B) const
{
    if (A->GetOwningNode() == B->GetOwningNode())
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW,
            NSLOCTEXT("GameplayAsset", "SameNode", "Cannot connect a node to itself"));
    }
    if (A->Direction == B->Direction)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW,
            NSLOCTEXT("GameplayAsset", "SameDir", "Cannot connect pins of the same direction"));
    }

    // Determine which pin is output and which is input
    const UEdGraphPin* OutPin = (A->Direction == EGPD_Output) ? A : B;
    const UEdGraphPin* InPin  = (A->Direction == EGPD_Input)  ? A : B;

    const UGameplayAssetGraphNode* FromGraphNode = Cast<UGameplayAssetGraphNode>(OutPin->GetOwningNode());
    const UGameplayAssetGraphNode* ToGraphNode   = Cast<UGameplayAssetGraphNode>(InPin->GetOwningNode());

    if (FromGraphNode && ToGraphNode && FromGraphNode->RuntimeNode && ToGraphNode->RuntimeNode)
    {
        UOmegaGameAsset_FlowNode* FromRuntime = FromGraphNode->RuntimeNode;
        UOmegaGameAsset_FlowNode* ToRuntime   = ToGraphNode->RuntimeNode;

        if (!FromRuntime->FlowNode_CanAcceptConnectionOutput(ToRuntime))
        {
            return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW,
                NSLOCTEXT("GameplayAsset", "OutputRefused", "Source node refuses this output connection"));
        }
        if (!ToRuntime->FlowNode_CanAcceptConnectionInput(FromRuntime))
        {
            return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW,
                NSLOCTEXT("GameplayAsset", "InputRefused", "Target node refuses this input connection"));
        }
    }

    return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, FText::GetEmpty());
}

bool UGameplayAssetGraphSchema::TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const
{
    const bool bResult = UEdGraphSchema::TryCreateConnection(A, B);
    if (bResult)
    {
        if (UGameplayAssetGraph* G = Cast<UGameplayAssetGraph>(A->GetOwningNode()->GetGraph()))
        {
            G->CommitToAsset();
        }
    }
    return bResult;
}

void UGameplayAssetGraphSchema::BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotification) const
{
    UEdGraphSchema::BreakPinLinks(TargetPin, bSendsNodeNotification);
    if (UGameplayAssetGraph* G = Cast<UGameplayAssetGraph>(TargetPin.GetOwningNode()->GetGraph()))
    {
        G->CommitToAsset();
    }
}

FLinearColor UGameplayAssetGraphSchema::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
    // PinSubCategory stores the pin's FName so we can look up its color from the owning node.
    // Fall back to white for the default exec-style appearance.
    return FLinearColor::White;
}


// ── SGameplayAssetGraphNode ───────────────────────────────────────────────────

void SGameplayAssetGraphNode::Construct(const FArguments& InArgs, UGameplayAssetGraphNode* InNode)
{
    AssetGraphNode  = InNode;
    this->GraphNode = InNode;  // CRITICAL — base SGraphNode::GraphNode must be set or SetOwner crashes
    SetCursor(EMouseCursor::CardinalCross);
    UpdateGraphNode();

    // Rebuild the widget whenever any property on the RuntimeNode changes
    OnPropertyChangedHandle = FCoreUObjectDelegates::OnObjectPropertyChanged.AddLambda(
        [this](UObject* Object, const FPropertyChangedEvent&)
        {
            if (AssetGraphNode && Object == AssetGraphNode->RuntimeNode)
            {
                UpdateGraphNode();
            }
        });
}

SGameplayAssetGraphNode::~SGameplayAssetGraphNode()
{
    FCoreUObjectDelegates::OnObjectPropertyChanged.Remove(OnPropertyChangedHandle);
}

FSlateColor SGameplayAssetGraphNode::GetNodeTitleColor() const
{
    if (AssetGraphNode && AssetGraphNode->RuntimeNode)
    {
        const FLinearColor C = AssetGraphNode->RuntimeNode->FlowNode_GetColor();
        if (C.A > 0.f) return C;
    }
    return FLinearColor(0.1f, 0.4f, 0.9f);
}

const FSlateBrush* SGameplayAssetGraphNode::GetNodeIcon() const
{
    if (AssetGraphNode && AssetGraphNode->RuntimeNode)
    {
        CachedIcon = AssetGraphNode->RuntimeNode->FlowNode_GetIcon();
        if (CachedIcon.GetResourceObject()) return &CachedIcon;
    }
    return nullptr;
}

const FSlateBrush* SGameplayAssetGraphNode::GetNodePortrait() const
{
    if (AssetGraphNode && AssetGraphNode->RuntimeNode)
    {
        CachedPortrait = AssetGraphNode->RuntimeNode->FlowNode_GetPortrait();
        if (CachedPortrait.GetResourceObject()) return &CachedPortrait;
    }
    return nullptr;
}

FText SGameplayAssetGraphNode::GetNodeDescription() const
{
    if (AssetGraphNode && AssetGraphNode->RuntimeNode)
    {
        return FText::FromString(AssetGraphNode->RuntimeNode->FlowNode_GetDescription());
    }
    return FText::GetEmpty();
}

void SGameplayAssetGraphNode::CreatePinWidgets()
{
    if (!AssetGraphNode || !AssetGraphNode->RuntimeNode) return;

    // Build a name→color lookup from the runtime node's pin definitions
    TMap<FName, FLinearColor> PinColorMap;
    TArray<FOmegaGameplayAssetFlowPin> Inputs, Outputs;
    AssetGraphNode->RuntimeNode->FlowNode_GetConnectionPorts(Inputs, Outputs);
    for (const FOmegaGameplayAssetFlowPin& P : Inputs)  PinColorMap.Add(P.PinName, P.PinColor);
    for (const FOmegaGameplayAssetFlowPin& P : Outputs) PinColorMap.Add(P.PinName, P.PinColor);

    for (UEdGraphPin* Pin : AssetGraphNode->Pins)
    {
        TSharedPtr<SGraphPin> PinWidget = FNodeFactory::CreatePinWidget(Pin);
        if (!PinWidget.IsValid()) continue;

        // Apply the color defined in the struct
        if (const FLinearColor* Color = PinColorMap.Find(Pin->PinName))
        {
            PinWidget->SetPinColorModifier(*Color);
        }

        AddPin(PinWidget.ToSharedRef());
    }
}

void SGameplayAssetGraphNode::UpdateGraphNode()
{
    InputPins.Empty();
    OutputPins.Empty();
    RightNodeBox.Reset();
    LeftNodeBox.Reset();

    const FSlateBrush* IconBrush     = GetNodeIcon();
    const FSlateBrush* PortraitBrush = GetNodePortrait();
    const FText        Description   = GetNodeDescription();
    const bool         bHasIcon      = (IconBrush     != nullptr);
    const bool         bHasPortrait  = (PortraitBrush != nullptr);
    const bool         bHasDesc      = !Description.IsEmpty();
    const bool         bHasBodyRow   = bHasPortrait || bHasDesc;

    // ── Title bar ─────────────────────────────────────────────────────────────
    TSharedRef<SHorizontalBox> TitleContent = SNew(SHorizontalBox);

    if (bHasIcon)
    {
        TitleContent->AddSlot()
            .AutoWidth()
            .VAlign(VAlign_Center)
            .Padding(FMargin(4.f, 0.f, 6.f, 0.f))
            [
                SNew(SImage)
                .Image(IconBrush)
                .DesiredSizeOverride(FVector2D(20.f, 20.f))
            ];
    }

    TitleContent->AddSlot()
        .AutoWidth()
        .VAlign(VAlign_Center)
        [
            // Outline: slightly larger dark border behind the title text
            SNew(SOverlay)

            // Shadow layer — offset dark copy drawn first
            + SOverlay::Slot()
            .Padding(FMargin(1.5f, 1.5f, 0.f, 0.f))
            [
                SNew(STextBlock)
                .Text_Lambda([this]()
                {
                    return AssetGraphNode ? AssetGraphNode->GetNodeTitle(ENodeTitleType::FullTitle)
                                          : FText::GetEmpty();
                })
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.55f))
                .WrapTextAt(200.f)
            ]

            // Outline layer — drawn at 1px offsets in all four directions
            + SOverlay::Slot()
            .Padding(FMargin(-1.f, 0.f, 0.f, 0.f))
            [
                SNew(STextBlock)
                .Text_Lambda([this]()
                {
                    return AssetGraphNode ? AssetGraphNode->GetNodeTitle(ENodeTitleType::FullTitle)
                                          : FText::GetEmpty();
                })
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.4f))
                .WrapTextAt(200.f)
            ]
            + SOverlay::Slot()
            .Padding(FMargin(1.f, 0.f, 0.f, 0.f))
            [
                SNew(STextBlock)
                .Text_Lambda([this]()
                {
                    return AssetGraphNode ? AssetGraphNode->GetNodeTitle(ENodeTitleType::FullTitle)
                                          : FText::GetEmpty();
                })
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.4f))
                .WrapTextAt(200.f)
            ]
            + SOverlay::Slot()
            .Padding(FMargin(0.f, -1.f, 0.f, 0.f))
            [
                SNew(STextBlock)
                .Text_Lambda([this]()
                {
                    return AssetGraphNode ? AssetGraphNode->GetNodeTitle(ENodeTitleType::FullTitle)
                                          : FText::GetEmpty();
                })
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.4f))
                .WrapTextAt(200.f)
            ]
            + SOverlay::Slot()
            .Padding(FMargin(0.f, 1.f, 0.f, 0.f))
            [
                SNew(STextBlock)
                .Text_Lambda([this]()
                {
                    return AssetGraphNode ? AssetGraphNode->GetNodeTitle(ENodeTitleType::FullTitle)
                                          : FText::GetEmpty();
                })
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.4f))
                .WrapTextAt(200.f)
            ]

            // Actual title text on top
            + SOverlay::Slot()
            [
                SNew(STextBlock)
                .Text_Lambda([this]()
                {
                    return AssetGraphNode ? AssetGraphNode->GetNodeTitle(ENodeTitleType::FullTitle)
                                          : FText::GetEmpty();
                })
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .WrapTextAt(200.f)
            ]
        ];

    // ── Portrait + description row ────────────────────────────────────────────
    // Portrait ImageSize drives the node body size directly — no fixed override.
    TSharedRef<SHorizontalBox> BodyRow = SNew(SHorizontalBox);

    if (bHasPortrait)
    {
        const FVector2D PortraitSize = PortraitBrush->ImageSize.IsZero()
            ? FVector2D(64.f, 64.f)   // safe fallback if ImageSize was not set on the brush
            : PortraitBrush->ImageSize;

        BodyRow->AddSlot()
            .AutoWidth()
            .VAlign(VAlign_Top)
            .Padding(FMargin(6.f, 6.f, 4.f, 6.f))
            [
                SNew(SBox)
                .WidthOverride(PortraitSize.X)
                .HeightOverride(PortraitSize.Y)
                [
                    SNew(SImage)
                    .Image(PortraitBrush)
                ]
            ];
    }

    if (bHasDesc)
    {
        BodyRow->AddSlot()
            .FillWidth(1.f)
            .VAlign(VAlign_Center)
            .Padding(FMargin(bHasPortrait ? 2.f : 8.f, 6.f, 8.f, 6.f))
            [
                SNew(STextBlock)
                .Text(this, &SGameplayAssetGraphNode::GetNodeDescription)
                .TextStyle(FAppStyle::Get(), "Graph.Node.NodeTitle")
                .ColorAndOpacity(FLinearColor(0.7f, 0.7f, 0.7f, 1.f))
                // Narrower wrap when a portrait is stealing horizontal space
                .WrapTextAt(bHasPortrait ? 140.f : 200.f)
                .AutoWrapText(false)
            ];
    }

    // ── Full node widget ──────────────────────────────────────────────────────
    this->ContentScale.Bind(this, &SGraphNode::GetContentScale);

    GetOrAddSlot(ENodeZone::Center)
    .HAlign(HAlign_Center)
    .VAlign(VAlign_Center)
    [
        SNew(SBorder)
        .BorderImage(FAppStyle::GetBrush("Graph.Node.Body"))
        .Padding(0.f)
        [
            SNew(SVerticalBox)

            // Title bar with outline border
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SBorder)
                .BorderImage(FAppStyle::GetBrush("Graph.Node.TitleBackground"))
                .BorderBackgroundColor(FLinearColor(0.f, 0.f, 0.f, 0.6f))
                .Padding(FMargin(1.f))
                [
                    SNew(SBorder)
                    .BorderImage(FAppStyle::GetBrush("Graph.Node.TitleBackground"))
                    .BorderBackgroundColor(this, &SGameplayAssetGraphNode::GetNodeTitleColor)
                    .Padding(FMargin(8.f, 4.f))
                    [
                        TitleContent
                    ]
                ]
            ]

            // Portrait + description (collapsed entirely when neither is set)
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SBorder)
                .Visibility(bHasBodyRow ? EVisibility::Visible : EVisibility::Collapsed)
                .BorderImage(FAppStyle::GetBrush("NoBorder"))
                .Padding(0.f)
                [
                    BodyRow
                ]
            ]

            // Pins row
            + SVerticalBox::Slot()
            .AutoHeight()
            [
                SNew(SHorizontalBox)
                + SHorizontalBox::Slot()
                .FillWidth(1.f)
                [
                    SAssignNew(LeftNodeBox, SVerticalBox)
                ]
                + SHorizontalBox::Slot()
                .FillWidth(1.f)
                [
                    SAssignNew(RightNodeBox, SVerticalBox)
                ]
            ]
        ]
    ];

    CreatePinWidgets();
}
