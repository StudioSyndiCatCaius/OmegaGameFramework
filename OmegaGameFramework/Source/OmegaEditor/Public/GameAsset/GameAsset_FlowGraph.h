#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphSchema.h"
#include "SGraphNode.h"
#include "EdGraphUtilities.h"
#include "OmegaGameAsset.h"
#include "GameAsset_FlowGraph.generated.h"


// ──────────────────────────────────────────────────────────────────────────────
// EdGraphNode — one per UGameplayAsset_FlowNode in the asset
// ──────────────────────────────────────────────────────────────────────────────
UCLASS()
class UGameplayAssetGraphNode : public UEdGraphNode
{
    GENERATED_BODY()

public:
    // The runtime node this editor node mirrors
    UPROPERTY()
    TObjectPtr<UOmegaGameAsset_FlowNode> RuntimeNode;

    // UEdGraphNode interface
    virtual void AllocateDefaultPins() override;
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
    virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(0.1f, 0.4f, 0.9f); }
    virtual bool CanDuplicateNode() const override { return true; }
    virtual bool CanUserDeleteNode() const override { return true; }
    virtual void NodeConnectionListChanged() override;
    virtual void OnUpdateCommentText(const FString& NewComment) override;
    virtual void AutowireNewNode(UEdGraphPin* FromPin) override;
    virtual void PrepareForCopying() override;
    virtual void PostPasteNode() override;

    UEdGraphPin* GetInputPin()  const;
    UEdGraphPin* GetOutputPin() const;
};


// ──────────────────────────────────────────────────────────────────────────────
// The UEdGraph subclass stored on-disk inside the asset (editor-only)
// ──────────────────────────────────────────────────────────────────────────────
UCLASS()
class UGameplayAssetGraph : public UEdGraph
{
    GENERATED_BODY()

public:
    // Back-pointer so nodes can reach the asset
    UPROPERTY()
    TObjectPtr<UOmegaGameAsset> OwningAsset;

    /** Sync graph nodes → runtime FlowNodes (call before saving) */
    void CommitToAsset();

    /** Rebuild graph nodes from FlowNodes (call when opening editor) */
    void RebuildFromAsset();
};


// ──────────────────────────────────────────────────────────────────────────────
// Schema
// ──────────────────────────────────────────────────────────────────────────────
UCLASS()
class UGameplayAssetGraphSchema : public UEdGraphSchema
{
    GENERATED_BODY()

public:
    static const FName PC_Flow;

    // UEdGraphSchema interface
    virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
    virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
    virtual bool TryCreateConnection(UEdGraphPin* A, UEdGraphPin* B) const override;
    virtual void BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotification) const override;
    virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
    virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
};


// ──────────────────────────────────────────────────────────────────────────────
// Custom Slate node widget
// ──────────────────────────────────────────────────────────────────────────────
class SGameplayAssetGraphNode : public SGraphNode
{
public:
    SLATE_BEGIN_ARGS(SGameplayAssetGraphNode) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UGameplayAssetGraphNode* InNode);
    virtual ~SGameplayAssetGraphNode();

    // SGraphNode interface
    virtual void UpdateGraphNode()  override;
    virtual void CreatePinWidgets() override;

private:
    FSlateColor        GetNodeTitleColor()  const;
    const FSlateBrush* GetNodeIcon()        const;
    const FSlateBrush* GetNodePortrait()    const;
    FText              GetNodeDescription() const;

    UGameplayAssetGraphNode*   AssetGraphNode  = nullptr;
    mutable FSlateBrush        CachedIcon;
    mutable FSlateBrush        CachedPortrait;
    FDelegateHandle            OnPropertyChangedHandle;
};


// ──────────────────────────────────────────────────────────────────────────────
// Visual node factory — tells the graph editor to use our widget
// ──────────────────────────────────────────────────────────────────────────────
class FGameplayAssetGraphNodeFactory : public FGraphPanelNodeFactory
{
    virtual TSharedPtr<SGraphNode> CreateNode(UEdGraphNode* Node) const override
    {
        if (UGameplayAssetGraphNode* AssetNode = Cast<UGameplayAssetGraphNode>(Node))
        {
            return SNew(SGameplayAssetGraphNode, AssetNode);
        }
        return nullptr;
    }
};
