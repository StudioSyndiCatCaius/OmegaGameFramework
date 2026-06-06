#include "OmegaGameAsset.h"

#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Misc/Guid.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "FlowNodes/FlowNode_Util.h"
#include "Misc/OmegaUtils_Macros.h"
#include "UObject/UObjectGlobals.h"

// ── UGameplayAsset_FlowNode ───────────────────────────────────────────────────

void UOmegaGameAsset_FlowNode::PostInitProperties()
{
    Super::PostInitProperties();
    if (!NodeGuid.IsValid())
    {
        NodeGuid = FGuid::NewGuid();
    }
}

void UOmegaGameAsset_FlowNode::OnNodeInput_Implementation(UGameInstance* InGameInstance, int32 PinIndex)
{
    // Base: no-op — override in C++ or Blueprint to implement node logic
}

void UOmegaGameAsset_FlowNode::OnNodeOutput_Implementation(UGameInstance* InGameInstance, int32 PinIndex)
{
    // Base: no-op
}

UOmegaGameAsset* UOmegaGameAsset_FlowNode::GetOwningGameplayAsset() const
{
    return GetTypedOuter<UOmegaGameAsset>();
}

UGameInstance* UOmegaGameAsset_FlowNode::GetGameInstance() const
{
    UOmegaGameAsset* Owner = GetOwningGameplayAsset();
    return Owner ? Owner->GameInstance : nullptr;
}

TArray<UOmegaGameAsset_FlowNode*> UOmegaGameAsset_FlowNode::GetAllConnectedNodes(
    bool IncludeInput, bool IncludeOutput,
    TSubclassOf<UOmegaGameAsset_FlowNode> ClassFilter) const
{
    TArray<UOmegaGameAsset_FlowNode*> Result;
    UOmegaGameAsset* Owner = GetOwningGameplayAsset();
    if (!Owner) return Result;

    auto PassesFilter = [&](UOmegaGameAsset_FlowNode* Node) -> bool
    {
        return Node && (!ClassFilter || Node->IsA(ClassFilter));
    };

    // Outgoing connections — nodes this node points TO
    if (IncludeOutput)
    {
        if (const FGameplayAssetFlowConnectionList* List = Owner->FlowConnections.Find(NodeGuid))
        {
            for (const FGuid& TargetGuid : List->Targets)
            {
                UOmegaGameAsset_FlowNode* Target = Owner->FindFlowNode(TargetGuid);
                if (PassesFilter(Target)) Result.AddUnique(Target);
            }
        }
    }

    // Incoming connections — nodes that point TO this node
    if (IncludeInput)
    {
        for (const TPair<FGuid, FGameplayAssetFlowConnectionList>& Conn : Owner->FlowConnections)
        {
            if (Conn.Key == NodeGuid) continue;
            if (Conn.Value.Targets.Contains(NodeGuid))
            {
                UOmegaGameAsset_FlowNode* Source = Owner->FindFlowNode(Conn.Key);
                if (PassesFilter(Source)) Result.AddUnique(Source);
            }
        }
    }

    return Result;
}

bool UOmegaGameAsset_FlowNode::TriggerOutput(int32 OutputPin, int32 Connection)
{
    UOmegaGameAsset* Owner = GetOwningGameplayAsset();
    if (!Owner || !Owner->Instance_IsValid()) return false;

    TArray<FOmegaGameplayAssetFlowPin> Inputs, Outputs;
    FlowNode_GetConnectionPorts(Inputs, Outputs);

    if (!Outputs.IsValidIndex(OutputPin)) return false;

    const FGameplayAssetFlowConnectionList* ConnList = Owner->FlowConnections.Find(NodeGuid);
    if (!ConnList || ConnList->Targets.Num() == 0) return false;

    TArray<FGuid> ToTrigger;
    if (Connection == -1)
    {
        ToTrigger = ConnList->Targets;
    }
    else if (ConnList->Targets.IsValidIndex(Connection))
    {
        ToTrigger.Add(ConnList->Targets[Connection]);
    }

    if (ToTrigger.Num() == 0) return false;

    for (const FGuid& TargetGuid : ToTrigger)
    {
        UOmegaGameAsset_FlowNode* TargetNode = Owner->FindFlowNode(TargetGuid);
        if (TargetNode)
        {
            OnNodeOutput(Owner->GameInstance, OutputPin);
            Owner->OnInputOutput.Broadcast(Owner, this, OutputPin);
            Owner->Instance_TriggerNodeInput(TargetGuid, 0);
        }
    }

    return true;
}
FText UOmegaGameAsset_FlowNode::GetNodeTitle_Implementation() const
{
    return FText::FromString(GetClass()->GetName());
}

FLinearColor UOmegaGameAsset_FlowNode::FlowNode_GetColor_Implementation() const
{
    return FLinearColor(0.f, 0.f, 0.f, 0.f); // alpha 0 = use default blue
}

FSlateBrush UOmegaGameAsset_FlowNode::FlowNode_GetIcon_Implementation() const
{
    return FSlateBrush(); // empty = no icon
}

FSlateBrush UOmegaGameAsset_FlowNode::FlowNode_GetPortrait_Implementation() const
{
    return FSlateBrush(); // empty = no portrait
}

FString UOmegaGameAsset_FlowNode::FlowNode_GetDescription_Implementation() const
{
    return FString();
}

void UOmegaGameAsset_FlowNode::FlowNode_GetConnectionPorts_Implementation(
    TArray<FOmegaGameplayAssetFlowPin>& Inputs,
    TArray<FOmegaGameplayAssetFlowPin>& Outputs) const
{
    FOmegaGameplayAssetFlowPin InPin;
    InPin.PinName     = TEXT("In");
    InPin.DisplayName = FText::GetEmpty();
    Inputs.Add(InPin);

    FOmegaGameplayAssetFlowPin OutPin;
    OutPin.PinName     = TEXT("Out");
    OutPin.DisplayName = FText::GetEmpty();
    Outputs.Add(OutPin);
}

bool UOmegaGameAsset_FlowNode::FlowNode_CanAcceptConnectionInput_Implementation(UOmegaGameAsset_FlowNode* Node) const
{
    return true;
}

bool UOmegaGameAsset_FlowNode::FlowNode_CanAcceptConnectionOutput_Implementation(UOmegaGameAsset_FlowNode* Node) const
{
    return true;
}

#if WITH_EDITOR
void UOmegaGameAsset_FlowNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    if (UOmegaGameAsset* Owner = GetTypedOuter<UOmegaGameAsset>())
    {
        Owner->Modify();
    }
}


#endif

UOmegaGameAsset::UOmegaGameAsset()
{
    if (!Guid.IsValid())
    {
        Guid.NewGuid();
    }
}

// ── UGameplayAsset ────────────────────────────────────────────────────────────

UOmegaGameAsset* UOmegaGameAsset::Instance_CreateNew(UObject* WorldContext)
{
    if (!WorldContext) return nullptr;

    UGameInstance* GI = WorldContext->GetWorld()
        ? WorldContext->GetWorld()->GetGameInstance()
        : nullptr;
    if (!GI) return nullptr;

    // Duplicate the asset as a transient object owned by the GameInstance
    UOmegaGameAsset* NewInstance = DuplicateObject<UOmegaGameAsset>(this, GI);
    if (!NewInstance) return nullptr;

    NewInstance->GameInstance = GI;

    // Also fix up FlowNode outers so GetTypedOuter works correctly on instances
    for (TObjectPtr<UOmegaGameAsset_FlowNode>& Node : NewInstance->FlowNodes)
    {
        if (Node)
        {
            Node->Rename(nullptr, NewInstance, REN_DontCreateRedirectors);
        }
    }

    NewInstance->OnInstanceCreated.Broadcast(NewInstance);
    return NewInstance;
}

bool UOmegaGameAsset::Instance_Destroy()
{
    if (!Instance_IsValid()) return false;

    OnInstanceDestroyed.Broadcast(this);
    MarkAsGarbage();
    return true;
}

bool UOmegaGameAsset::Instance_IsValid() const
{
    // Valid instance = has a live GameInstance ref AND is owned by it (not the original asset)
    return IsValid(GameInstance) && GetOuter() == GameInstance;
}

bool UOmegaGameAsset::Instance_TriggerNodeInput(FGuid NodeGuid, int32 Input)
{
    if (!Instance_IsValid()) return false;

    UOmegaGameAsset_FlowNode* Node = FindFlowNode(NodeGuid);
    if (!Node) return false;

    OnInputInput.Broadcast(this, Node, Input);
    Node->OnNodeInput(GameInstance, Input);
    return true;
}

FLinearColor UOmegaGameAsset::GetAssetColor_Implementation() const
{
    return FLinearColor::White;
}

FSlateBrush UOmegaGameAsset::GetAssetThumbnail_Implementation() const
{
    return FSlateBrush(); // empty = no custom thumbnail
}

void UOmegaGameAsset::GetEnabledEditors_Implementation(bool& Enable3DEditor, bool& FlowGraphEditor) const
{
    Enable3DEditor  = false;
    FlowGraphEditor = false;
}

TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> UOmegaGameAsset::FlowGraph_GetAvailableNodes_Implementation() const
{
    TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> out;
    out.Add(UFlowNode_UTIL_Begin::StaticClass());
    out.Add(UFlowNode_UTIL_Finish::StaticClass());
    out.Add(UFlowNode_UTIL_HUB::StaticClass());
    out.Add(UFlowNode_UTIL_ToHUB::StaticClass());
    return out;
}

TSubclassOf<AActor> UOmegaGameAsset::Scene3D_GetBaseActorClass_Implementation() const
{
    return AActor::StaticClass();
}

void UOmegaGameAsset::Scene3D_OnAssetEdit_Implementation(AActor* ReferenceActor)
{
    // Base implementation intentionally empty; override to capture transform etc.
}

TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> UOmegaGameAsset::L_GetAllAvailableNodes() const
{
    TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> out = FlowGraph_GetAvailableNodes();
    out.Append(OGF_GAME_CORE()->GameAsset_AppendAcceptedNodes(this));
    return out;
}

UOmegaGameAsset_FlowNode* UOmegaGameAsset::AddFlowNode(TSubclassOf<UOmegaGameAsset_FlowNode> NodeClass)
{
    if (!NodeClass) return nullptr;

    Modify();
    UOmegaGameAsset_FlowNode* NewNode = NewObject<UOmegaGameAsset_FlowNode>(this, NodeClass, NAME_None, RF_Transactional);
    FlowNodes.Add(NewNode);
    return NewNode;
}

void UOmegaGameAsset::RemoveFlowNode(const FGuid& NodeGuid)
{
    Modify();
    FlowNodes.RemoveAll([&](const TObjectPtr<UOmegaGameAsset_FlowNode>& N)
    {
        return N && N->NodeGuid == NodeGuid;
    });

    // Remove as a source
    FlowConnections.Remove(NodeGuid);

    // Remove as a target from all other nodes' lists
    for (TPair<FGuid, FGameplayAssetFlowConnectionList>& Conn : FlowConnections)
    {
        Conn.Value.Targets.Remove(NodeGuid);
    }
}

UOmegaGameAsset_FlowNode* UOmegaGameAsset::FindFlowNode(const FGuid& NodeGuid) const
{
    const TObjectPtr<UOmegaGameAsset_FlowNode>* Found = FlowNodes.FindByPredicate(
        [&](const TObjectPtr<UOmegaGameAsset_FlowNode>& N){ return N && N->NodeGuid == NodeGuid; });
    return Found ? Found->Get() : nullptr;
}

TArray<UOmegaGameAsset_FlowNode*> UOmegaGameAsset::FlowNode_GetAll(
    TSubclassOf<UOmegaGameAsset_FlowNode> ClassFilter) const
{
    TArray<UOmegaGameAsset_FlowNode*> Result;
    for (const TObjectPtr<UOmegaGameAsset_FlowNode>& Node : FlowNodes)
    {
        if (!Node) continue;
        if (ClassFilter && !Node->IsA(ClassFilter)) continue;
        Result.Add(Node.Get());
    }
    return Result;
}

UOmegaGameAsset_FlowNode* UOmegaGameAsset::FlowNode_GetFirstOfClass(
    TSubclassOf<UOmegaGameAsset_FlowNode> Class) const
{
    if (!Class) return nullptr;

    for (const TObjectPtr<UOmegaGameAsset_FlowNode>& Node : FlowNodes)
    {
        if (Node && Node->IsA(Class))
        {
            return Node.Get();
        }
    }
    return nullptr;
}