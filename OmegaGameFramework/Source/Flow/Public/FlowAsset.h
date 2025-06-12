// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "Interfaces/OmegaInterface_Common.h"
#include "FlowSave.h"
#include "FlowTypes.h"
#include "Templates/SubclassOf.h"
#include "FlowAsset.generated.h"

class UFlowNode;
class UFlowNode_CustomInput;
class UFlowNode_Start;
class UFlowAssetTrait;
class UFlowNode_SubGraph;
class UFlowSubsystem;

class UEdGraph;
class UEdGraphNode;
class UFlowAsset;
class UGameInstance;

#if WITH_EDITOR

/** Interface for calling the graph editor methods */
class FLOW_API IFlowGraphInterface
{
public:
	IFlowGraphInterface() {}
	virtual ~IFlowGraphInterface() {}

	virtual void OnInputTriggered(UEdGraphNode* GraphNode, const int32 Index) const {}
	virtual void OnOutputTriggered(UEdGraphNode* GraphNode, const int32 Index) const {}
};

DECLARE_DELEGATE(FFlowAssetEvent);
#endif

/**
 * Single asset containing flow nodes.
 */
UCLASS(BlueprintType, hideCategories = Object)
class FLOW_API UFlowAsset : public UObject, public IGameplayTagsInterface, public IDataInterface_General, public IDataInterface_GUID
{
	GENERATED_UCLASS_BODY()

	friend class UFlowNode;
	friend class UFlowNode_CustomOutput;
	friend class UFlowNode_SubGraph;
	friend class UFlowSubsystem;

	friend class FFlowAssetDetails;
	friend class UFlowGraphSchema;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flow Asset")
	FGuid AssetGuid;
public:

	UPROPERTY() TMap<FName, FVector> FlowParams;

	virtual FGuid GetObjectGuid_Implementation() const  override { return AssetGuid; };

	
	// Set it to False, if this asset is instantiated as Root Flow for owner that doesn't live in the world
	// This allow to SaveGame support works properly, if owner of Root Flow would be Game Instance or its subsystem
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flow Asset")
	bool bWorldBound;
	
//////////////////////////////////////////////////////////////////////////
// Graph

#if WITH_EDITOR
	friend class UFlowGraph;

	// UObject
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PostDuplicate(bool bDuplicateForPIE) override;
	virtual EDataValidationResult IsDataValid(TArray<FText>& ValidationErrors) override;
	// --
#endif

	// IFlowGraphInterface
#if WITH_EDITORONLY_DATA
private:
	UPROPERTY()
	UEdGraph* FlowGraph;

	static TSharedPtr<IFlowGraphInterface> FlowGraphInterface;
#endif

public:
#if WITH_EDITOR
	UEdGraph* GetGraph() const { return FlowGraph; };

	static void SetFlowGraphInterface(TSharedPtr<IFlowGraphInterface> InFlowAssetEditor);
	static TSharedPtr<IFlowGraphInterface> GetFlowGraphInterface() { return FlowGraphInterface; };
#endif
	// -- 

//////////////////////////////////////////////////////////////////////////
// Nodes

protected:
	TArray<TSubclassOf<UFlowNode>> AllowedNodeClasses;	
	TArray<TSubclassOf<UFlowNode>> DeniedNodeClasses;

	bool bStartNodePlacedAsGhostNode;

private:
	UPROPERTY()
	TMap<FGuid, UFlowNode*> Nodes;

	/**
	 * Custom Inputs define custom entry points in graph, it's similar to blueprint Custom Events
	 * Sub Graph node using this Flow Asset will generate context Input Pin for every valid Event name on this list
	 */
	UPROPERTY(EditAnywhere, Category = "Sub Graph")
	TArray<FName> CustomInputs;

	/**
	 * Custom Outputs define custom graph outputs, this allow to send signals to the parent graph while executing this graph
	 * Sub Graph node using this Flow Asset will generate context Output Pin for every valid Event name on this list
	 */
	UPROPERTY(EditAnywhere, Category = "Sub Graph")
	TArray<FName> CustomOutputs;

public:
#if WITH_EDITOR
	FFlowAssetEvent OnSubGraphReconstructionRequested;

	UFlowNode* CreateNode(const UClass* NodeClass, UEdGraphNode* GraphNode);

	void RegisterNode(const FGuid& NewGuid, UFlowNode* NewNode);
	void UnregisterNode(const FGuid& NodeGuid);

	// Processes all nodes and creates map of all pin connections
	void HarvestNodeConnections();
#endif

	TMap<FGuid, UFlowNode*> GetNodes() const { return Nodes; }
    UFlowNode* GetNode(const FGuid& Guid) const { return Nodes.FindRef(Guid); }

    template <class T>
    T* GetNode(const FGuid& Guid) const
    {
        static_assert(TPointerIsConvertibleFromTo<T, const UFlowNode>::Value, "'T' template parameter to GetNode must be derived from UFlowNode");
        
        if (UFlowNode* Node = Nodes.FindRef(Guid))
        {
            return Cast<T>(Node);
        }

        return nullptr;
    }

	TArray<FName> GetCustomInputs() const { return CustomInputs; }
	TArray<FName> GetCustomOutputs() const { return CustomOutputs; }

//////////////////////////////////////////////////////////////////////////
// Instances of the template asset

private:
	// Original object holds references to instances
	UPROPERTY(Transient)
	TArray<UFlowAsset*> ActiveInstances;

#if WITH_EDITORONLY_DATA
	TWeakObjectPtr<UFlowAsset> InspectedInstance;
#endif

public:
	void AddInstance(UFlowAsset* Instance);
	int32 RemoveInstance(UFlowAsset* Instance);

	void ClearInstances();
	int32 GetInstancesNum() const { return ActiveInstances.Num(); }

#if WITH_EDITOR
	void GetInstanceDisplayNames(TArray<TSharedPtr<FName>>& OutDisplayNames) const;

	void SetInspectedInstance(const FName& NewInspectedInstanceName);
	UFlowAsset* GetInspectedInstance() const { return InspectedInstance.IsValid() ? InspectedInstance.Get() : nullptr; }

	DECLARE_EVENT(UFlowAsset, FRefreshDebuggerEvent);
	FRefreshDebuggerEvent& OnDebuggerRefresh() { return RefreshDebuggerEvent; }
	FRefreshDebuggerEvent RefreshDebuggerEvent;

private:
	void BroadcastDebuggerRefresh() const { RefreshDebuggerEvent.Broadcast(); }
#endif

//////////////////////////////////////////////////////////////////////////
// Executing asset instance

private:
	UPROPERTY()
	UFlowAsset* TemplateAsset;

	// Object that spawned Root Flow instance, i.e. World Settings or Player Controller
	// This pointer is passed to child instances: Flow Asset instances created by the SubGraph nodes
	TWeakObjectPtr<UObject> Owner;

	// SubGraph node that created this Flow Asset instance
	TWeakObjectPtr<UFlowNode_SubGraph> NodeOwningThisAssetInstance;

	// Flow Asset instances created by SubGraph nodes placed in the current graph
	TMap<TWeakObjectPtr<UFlowNode_SubGraph>, TWeakObjectPtr<UFlowAsset>> ActiveSubGraphs;

	// Execution of the graph always starts from this node, there can be only one StartNode in the graph
	UPROPERTY()
	UFlowNode_Start* StartNode;

	// Optional entry points to the graph, similar to blueprint Custom Events
	UPROPERTY()
	TSet<UFlowNode_CustomInput*> CustomInputNodes;

	UPROPERTY()
	TSet<UFlowNode*> PreloadedNodes;

	// Nodes that have any work left, not marked as Finished yet
	UPROPERTY()
	TArray<UFlowNode*> ActiveNodes;

	// All nodes active in the past, done their work
	UPROPERTY()
	TArray<UFlowNode*> RecordedNodes;

	EFlowFinishPolicy FinishPolicy;

public:
	virtual void InitializeInstance(const TWeakObjectPtr<UObject> InOwner, UFlowAsset* InTemplateAsset);
	virtual void DeinitializeInstance();

	UFlowAsset* GetTemplateAsset() const { return TemplateAsset; }
	
	// Object that spawned Root Flow instance, i.e. World Settings or Player Controller
	// This pointer is passed to child instances: Flow Asset instances created by the SubGraph nodes
	UFUNCTION(BlueprintPure, Category = "Flow")
	UObject* GetOwner() const { return Owner.Get(); }

	template <class T>
	TWeakObjectPtr<T*> GetOwner() const
	{
		return Owner.IsValid() ? Cast<T>(Owner) : nullptr;
	}

	virtual void PreloadNodes();

	virtual void PreStartFlow();
	virtual void StartFlow(UGameInstance* GameInstance, FFlowAssetOverrideData OverrideData, const FName InputName);
	
	virtual void FinishFlow(const EFlowFinishPolicy InFinishPolicy, const bool bRemoveInstance = true);

	// Get Flow Asset instance created by the given SubGraph node
	TWeakObjectPtr<UFlowAsset> GetFlowInstance(UFlowNode_SubGraph* SubGraphNode) const;

private:
	void TriggerCustomEvent(UFlowNode_SubGraph* Node, const FName& EventName) const;
	void TriggerCustomOutput(const FName& EventName) const;

public:
	void TriggerInput(const FGuid& NodeGuid, const FName& PinName, bool bForce = false);
	void FinishNode(UFlowNode* Node);
	
private:
	void ResetNodes();

public:
	UFlowSubsystem* GetFlowSubsystem() const;
	FName GetDisplayName() const;

	UFlowNode_SubGraph* GetNodeOwningThisAssetInstance() const;
	UFlowAsset* GetParentInstance() const;

	// Are there any active nodes?
	UFUNCTION(BlueprintPure, Category = "Flow")
	bool IsActive() const { return ActiveNodes.Num() > 0; }

	// Returns nodes that have any work left, not marked as Finished yet
	UFUNCTION(BlueprintPure, Category = "Flow")
	TArray<UFlowNode*> GetActiveNodes() const { return ActiveNodes; }
	
	// Returns nodes active in the past, done their work
	UFUNCTION(BlueprintPure, Category = "Flow")
	TArray<UFlowNode*> GetRecordedNodes() const { return RecordedNodes; }
	
//////////////////////////////////////////////////////////////////////////
// SaveGame
	
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	FFlowAssetSaveData SaveInstance(TArray<FFlowAssetSaveData>& SavedFlowInstances);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void LoadInstance(const FFlowAssetSaveData& AssetRecord);

private:
	void OnActivationStateLoaded(UFlowNode* Node);

protected:
	UFUNCTION(BlueprintNativeEvent, Category = "SaveGame")
	void OnSave();
	
	UFUNCTION(BlueprintNativeEvent, Category = "SaveGame")
	void OnLoad();

public:	
	UFUNCTION(BlueprintNativeEvent, Category = "SaveGame")
	bool IsBoundToWorld();
	
	//#############################################################################################################
	// OMEGA ADDITIONS
	//#############################################################################################################
	
	UFUNCTION(BlueprintPure, Category = "Flow")
	TArray<UFlowNode*> GetAllNodes();
	
	UFUNCTION(BlueprintPure, Category = "Flow")
	UFlowNode* GetNodeFromGuid(FGuid Guid);
	
	UFUNCTION(BlueprintPure, Category = "Flow")
	TArray<FGuid> GetActiveNodeGuids();

	UFUNCTION(BlueprintCallable, Category="Flow")
	void ForceActivateNode(FGuid NodeGuid, FName InputName);
	
	//--------------------------------------------------------//
	// General
	//--------------------------------------------------------//
	UPROPERTY(EditAnywhere, Category="General", DisplayName="Name")
	FText DisplayName;
	UPROPERTY(EditAnywhere, Category="General", DisplayName="Description")
	FText AssetDescription;
	UPROPERTY(EditAnywhere, Category="General")
	FSlateBrush Icon;
	UPROPERTY(EditAnywhere, Category="General", AdvancedDisplay)
	FString CustomLabel;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	
	//--------------------------------------------------------//
	// Gameplay Tags
	//--------------------------------------------------------//

	UPROPERTY(EditAnywhere, Category="GameplayTags")
	FGameplayTag GameplayCategory;
	UPROPERTY(EditAnywhere, Category="GameplayTags")
	FGameplayTagContainer GameplayTags;

	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override;

	//--------------------------------------------------------//
	// TRAITS
	//--------------------------------------------------------//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Traits")
	TArray<UFlowAssetTrait*> Traits;
	
	//--------------------------------------------------------//
	// NOTIFY
	//--------------------------------------------------------//
	UFUNCTION(BlueprintCallable, Category="FlowAsset")
	void NotifyFlow(FName Notify, UObject* Context = nullptr);
};


UINTERFACE(MinimalAPI) class UDataInterface_FlowAsset : public UInterface { GENERATED_BODY() };
class FLOW_API IDataInterface_FlowAsset
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="FlowAsset")
	UFlowAsset* GetFlowAsset(FGameplayTag Tag);
};
