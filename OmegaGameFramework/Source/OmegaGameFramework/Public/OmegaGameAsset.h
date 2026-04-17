#pragma once

#include "CoreMinimal.h"
#include "LuaInterface.h"
#include "Engine/DataAsset.h"
#include "Interfaces/I_Common.h"
#include "Misc/GeneralDataObject.h"
#include "OmegaGameAsset.generated.h"

USTRUCT(BlueprintType)
struct OMEGAGAMEFRAMEWORK_API FOmegaGameplayAssetFlowPin
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node") FName  PinName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node") FText  DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node") FLinearColor PinColor = FLinearColor::White;
};


// ──────────────────────────────────────────────────────────────────────────────
// Base Flow Node
// ──────────────────────────────────────────────────────────────────────────────
UCLASS(Abstract, Blueprintable, BlueprintType, EditInlineNew, meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaGameAsset_FlowNode : public UObject
{
    GENERATED_BODY()

public:
    // Stable identity used by the graph editor to match editor nodes to runtime nodes
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Node")
    FGuid NodeGuid;

    // Canvas position stored so the graph editor can restore layout
    UPROPERTY()
    FVector2D NodePosition = FVector2D::ZeroVector;

    // Human-readable label; defaults to class name but subclasses can override
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node")
    FText GetNodeTitle() const;
    virtual FText GetNodeTitle_Implementation() const;

    // ── Optional appearance — override in C++ or Blueprint ────────────────────

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Appearance")
    FLinearColor FlowNode_GetColor() const;
    virtual FLinearColor FlowNode_GetColor_Implementation() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Appearance")
    FSlateBrush FlowNode_GetIcon() const;
    virtual FSlateBrush FlowNode_GetIcon_Implementation() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Appearance")
    FSlateBrush FlowNode_GetPortrait() const;
    virtual FSlateBrush FlowNode_GetPortrait_Implementation() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Appearance")
    FString FlowNode_GetDescription() const;
    virtual FString FlowNode_GetDescription_Implementation() const;

    // ── Pins and connections ──────────────────────────────────────────────────

    /** Return the input and output pins for this node.
     *  Default provides a single "In" input and single "Out" output. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Pins")
    void FlowNode_GetConnectionPorts(TArray<FOmegaGameplayAssetFlowPin>& Inputs,
                                     TArray<FOmegaGameplayAssetFlowPin>& Outputs) const;
    virtual void FlowNode_GetConnectionPorts_Implementation(
        TArray<FOmegaGameplayAssetFlowPin>& Inputs,
        TArray<FOmegaGameplayAssetFlowPin>& Outputs) const;

    /** Return whether this node can accept an incoming connection from the given node. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Pins")
    bool FlowNode_CanAcceptConnectionInput(UOmegaGameAsset_FlowNode* Node) const;
    virtual bool FlowNode_CanAcceptConnectionInput_Implementation(UOmegaGameAsset_FlowNode* Node) const;

    /** Return whether this node can accept an outgoing connection to the given node. */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Node|Pins")
    bool FlowNode_CanAcceptConnectionOutput(UOmegaGameAsset_FlowNode* Node) const;
    virtual bool FlowNode_CanAcceptConnectionOutput_Implementation(UOmegaGameAsset_FlowNode* Node) const;

    // ── Runtime execution ─────────────────────────────────────────────────────

    /** Get the asset that owns this node. */
    UFUNCTION(BlueprintCallable, Category="Node|Runtime")
    UOmegaGameAsset* GetOwningGameplayAsset() const;

    /** Get the game instance from the owning asset (only valid on instances). */
    UFUNCTION(BlueprintCallable, Category="Node|Runtime")
    UGameInstance* GetGameInstance() const;

    /** Trigger an output pin. Connection=-1 triggers all connections on that pin. Returns true if at least one node was reached. */
    UFUNCTION(BlueprintCallable, Category="Node|Runtime")
    bool TriggerOutput(int32 OutputPin, int32 Connection = -1);

    /** Get all nodes connected to this node, optionally filtered by direction and class. */
    UFUNCTION(BlueprintCallable, Category="Node|Runtime",
              meta=(DeterminesOutputType="ClassFilter"))
    TArray<UOmegaGameAsset_FlowNode*> GetAllConnectedNodes(
        bool IncludeInput,
        bool IncludeOutput,
        TSubclassOf<UOmegaGameAsset_FlowNode> ClassFilter = nullptr) const;

    /** Called when an input pin is triggered. Override to implement node logic. */
    UFUNCTION(BlueprintNativeEvent, Category="Node|Runtime")
    void OnNodeInput(UGameInstance* GameInstance, int32 PinIndex);
    virtual void OnNodeInput_Implementation(UGameInstance* GameInstance, int32 PinIndex);

    /** Called when an output pin is triggered. Override to react to outputs. */
    UFUNCTION(BlueprintNativeEvent, Category="Node|Runtime")
    void OnNodeOutput(UGameInstance* GameInstance, int32 PinIndex);
    virtual void OnNodeOutput_Implementation(UGameInstance* GameInstance, int32 PinIndex);

    virtual void PostInitProperties() override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};


USTRUCT()
struct FGameplayAssetFlowConnectionList
{
    GENERATED_BODY()
    UPROPERTY()
    TArray<FGuid> Targets;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayAssetDelegate, UOmegaGameAsset*, Asset);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FGameplayAssetNodePinDelegate, UOmegaGameAsset*, Asset, UOmegaGameAsset_FlowNode*, Node, int32, PinIndex);

// ──────────────────────────────────────────────────────────────────────────────
// Primary Data Asset
// ──────────────────────────────────────────────────────────────────────────────
UCLASS(Blueprintable, BlueprintType,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGameAsset : public UPrimaryDataAsset, public IDataInterface_General, public ILuaInterface
{
    GENERATED_BODY()
    
public:
    
    UOmegaGameAsset();
    
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="Name") FText DisplayName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Icon") FSlateBrush Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",meta=(MultiLine),DisplayName="Description") FText DisplayDescription;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="🏷️Category") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",DisplayName="🏷️Tags") FGameplayTagContainer GameplayTags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General") FOmegaBitflagsBase Flags;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="General",AdvancedDisplay) FString CustomLabel;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="General",AdvancedDisplay) FGuid Guid;
	virtual FGuid GetObjectGuid_Implementation() { return Guid; }
	
	OMACRO_ADDPARAMS_GENERAL();
	
    // ── Flow graph data ───────────────────────────────────────────────────────
    UPROPERTY(Instanced, BlueprintReadOnly, Category="Asset|FlowGraph")
    TArray<TObjectPtr<UOmegaGameAsset_FlowNode>> FlowNodes;

    // Serialised connections: FromGuid → list of ToGuids (supports multiple outputs)
    UPROPERTY()
    TMap<FGuid, FGameplayAssetFlowConnectionList> FlowConnections;

    // ── Delegates ─────────────────────────────────────────────────────────────

    UPROPERTY(BlueprintAssignable) FGameplayAssetDelegate         OnInstanceCreated;
    UPROPERTY(BlueprintAssignable) FGameplayAssetDelegate         OnInstanceDestroyed;
    UPROPERTY(BlueprintAssignable) FGameplayAssetNodePinDelegate  OnInputInput;
    UPROPERTY(BlueprintAssignable) FGameplayAssetNodePinDelegate  OnInputOutput;

    // ── Runtime instance ──────────────────────────────────────────────────────

    /** Game instance reference — only valid on instanced assets, not original assets. */
    UPROPERTY(BlueprintReadOnly, Category="Asset|Runtime")
    TObjectPtr<UGameInstance> GameInstance;

    /** Create a transient duplicate of this asset owned by the GameInstance. */
    UFUNCTION(BlueprintCallable, Category="Asset|Runtime", meta=(WorldContext="WorldContext"),DisplayName="INSTANCE - Create New")
    UOmegaGameAsset* Instance_CreateNew(UObject* WorldContext);

    /** Destroy this instance. Only works on instanced assets, not original assets. */
    UFUNCTION(BlueprintCallable, Category="Asset|Runtime",DisplayName="INSTANCE - Destroy")
    bool Instance_Destroy();

    /** Returns true if this is a valid instance with a live GameInstance reference. */
    UFUNCTION(BlueprintCallable, Category="Asset|Runtime",DisplayName="INSTANCE - Is Valid?")
    bool Instance_IsValid() const;

    /** Trigger an input pin on a specific node by GUID. */
    UFUNCTION(BlueprintCallable, Category="Asset|Runtime",DisplayName="INSTANCE - Trigger Node Input")
    bool Instance_TriggerNodeInput(FGuid NodeGuid, int32 Input);

    // ── EDITOR appearance ──────────────────────────────────────────────────────

    /** Color used to tint the asset in the content browser and editor. */
    UFUNCTION(BlueprintNativeEvent, Category="Asset|Editor")
    FLinearColor GetAssetColor() const;

    /** Thumbnail image shown in the content browser. */
    UFUNCTION(BlueprintNativeEvent, Category="Asset|Editor")
    FSlateBrush GetAssetThumbnail() const;

    // ── Overridable editor queries ────────────────────────────────────────────

    /** Return which editors should be visible for THIS asset. */
    UFUNCTION(BlueprintNativeEvent, Category="Asset|Editor")
    void GetEnabledEditors(bool& Enable3DEditor, bool& FlowGraphEditor) const;

    /** Return node classes that can be placed in the flow graph for this asset. */
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Asset|FlowGraph")
    TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> FlowGraph_GetAvailableNodes() const;
    
    TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> L_GetAllAvailableNodes() const;

    /** Return the AActor class to spawn in the 3D preview scene. */
    UFUNCTION(BlueprintNativeEvent, Category="Asset|Editor3D")
    TSubclassOf<AActor> Scene3D_GetBaseActorClass() const;

    /** Called by the toolkit when the 3D scene editor commits its state. */
    UFUNCTION(BlueprintNativeEvent, Category="Asset|Editor3D")
    void Scene3D_OnAssetEdit(AActor* ReferenceActor);

    // ── Helpers called by the editor toolkit ─────────────────────────────────
    UOmegaGameAsset_FlowNode* AddFlowNode(TSubclassOf<UOmegaGameAsset_FlowNode> NodeClass);
    void RemoveFlowNode(const FGuid& NodeGuid);
    UOmegaGameAsset_FlowNode* FindFlowNode(const FGuid& NodeGuid) const;

    /** Get all flow nodes, optionally filtered by class. */
    UFUNCTION(BlueprintCallable, Category="Asset|FlowGraph",
              meta=(DeterminesOutputType="ClassFilter"))
    TArray<UOmegaGameAsset_FlowNode*> FlowNode_GetAll(
        TSubclassOf<UOmegaGameAsset_FlowNode> ClassFilter = nullptr) const;

    /** Get the first node of the given class, or nullptr if none exists. */
    UFUNCTION(BlueprintCallable, Category="Asset|FlowGraph",
              meta=(DeterminesOutputType="Class"))
    UOmegaGameAsset_FlowNode* FlowNode_GetFirstOfClass(
        TSubclassOf<UOmegaGameAsset_FlowNode> Class) const;};