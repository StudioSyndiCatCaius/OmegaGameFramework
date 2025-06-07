// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "FlowAsset.h"

#include "FlowAssetTrait.h"
#include "FlowSettings.h"
#include "FlowSubsystem.h"

#include "Nodes/FlowNode.h"
#include "Nodes/Route/FlowNode_CustomInput.h"
#include "Nodes/Route/FlowNode_Start.h"
#include "Nodes/Route/FlowNode_Finish.h"
#include "Nodes/Route/FlowNode_SubGraph.h"

#include "Engine/World.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"

UFlowAsset::UFlowAsset(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bWorldBound(true)
#if WITH_EDITOR
	, FlowGraph(nullptr)
#endif
	, AllowedNodeClasses({UFlowNode::StaticClass()})
	, bStartNodePlacedAsGhostNode(false)
	, TemplateAsset(nullptr)
	, StartNode(nullptr)
	, FinishPolicy(EFlowFinishPolicy::Keep)
{
	if (!AssetGuid.IsValid())
	{
		AssetGuid = FGuid::NewGuid();
	}
}

#if WITH_EDITOR
void UFlowAsset::AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector)
{
	UFlowAsset* This = CastChecked<UFlowAsset>(InThis);
	Collector.AddReferencedObject(This->FlowGraph, This);

	Super::AddReferencedObjects(InThis, Collector);
}

void UFlowAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UFlowAsset, CustomInputs)
		|| PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UFlowAsset, CustomOutputs)))
	{
		OnSubGraphReconstructionRequested.ExecuteIfBound();
	}
}

void UFlowAsset::PostDuplicate(bool bDuplicateForPIE)
{
	Super::PostDuplicate(bDuplicateForPIE);

	if (!bDuplicateForPIE)
	{
		AssetGuid = FGuid::NewGuid();
		Nodes.Empty();
	}
}

EDataValidationResult UFlowAsset::IsDataValid(TArray<FText>& ValidationErrors)
{
	for (const TPair<FGuid, UFlowNode*>& Node : Nodes)
	{
		if (Node.Value == nullptr || Node.Value->IsDataValid(ValidationErrors) == EDataValidationResult::Invalid)
		{
			// refresh data if Node is missing, i.e. its class has been deleted
			if (Node.Value == nullptr)
			{
				HarvestNodeConnections();
			}

			return EDataValidationResult::Invalid;
		}
	}

	return EDataValidationResult::Valid;
}

TSharedPtr<IFlowGraphInterface> UFlowAsset::FlowGraphInterface = nullptr;

void UFlowAsset::SetFlowGraphInterface(TSharedPtr<IFlowGraphInterface> InFlowAssetEditor)
{
	check(!FlowGraphInterface.IsValid());
	FlowGraphInterface = InFlowAssetEditor;
}

UFlowNode* UFlowAsset::CreateNode(const UClass* NodeClass, UEdGraphNode* GraphNode)
{
	UFlowNode* NewNode = NewObject<UFlowNode>(this, NodeClass, NAME_None, RF_Transactional);
	NewNode->SetGraphNode(GraphNode);

	RegisterNode(GraphNode->NodeGuid, NewNode);
	return NewNode;
}

void UFlowAsset::RegisterNode(const FGuid& NewGuid, UFlowNode* NewNode)
{
	NewNode->SetGuid(NewGuid);
	Nodes.Emplace(NewGuid, NewNode);

	HarvestNodeConnections();
}

void UFlowAsset::UnregisterNode(const FGuid& NodeGuid)
{
	Nodes.Remove(NodeGuid);
	Nodes.Compact();

	HarvestNodeConnections();
	MarkPackageDirty();
}

void UFlowAsset::HarvestNodeConnections()
{
	TMap<FName, FConnectedPin> Connections;
	bool bGraphDirty = false;

	// last moment to remove invalid nodes
	
	/*
	TArray<FGuid> NodeGuids_Local;
	Nodes.GetKeys(NodeGuids_Local);
	
	for(FGuid TempGuid : NodeGuids_Local)
	{
		if(!Nodes.Contains(TempGuid) || !Nodes[TempGuid])
		{
			Nodes.Remove(TempGuid);
			bGraphDirty = true;
		}
	}
	*/
	
	for (auto NodeIt = Nodes.CreateIterator(); NodeIt; ++NodeIt)
	{
		const TPair<FGuid, UFlowNode*>& Pair = *NodeIt;
		if (Pair.Value == nullptr)
		{
			NodeIt.RemoveCurrent();
			bGraphDirty = true;
		}
	}


	for (const TPair<FGuid, UFlowNode*>& Pair : Nodes)
	{
		UFlowNode* Node = Pair.Value;
		TMap<FName, FConnectedPin> FoundConnections;

		for (const UEdGraphPin* ThisPin : Node->GetGraphNode()->Pins)
		{
			if (ThisPin->Direction == EGPD_Output && ThisPin->LinkedTo.Num() > 0)
			{
				if (const UEdGraphPin* LinkedPin = ThisPin->LinkedTo[0])
				{
					const UEdGraphNode* LinkedNode = LinkedPin->GetOwningNode();
					FoundConnections.Add(ThisPin->PinName, FConnectedPin(LinkedNode->NodeGuid, LinkedPin->PinName));
				}
			}
		}

		// This check exists to ensure that we don't mark graph dirty, if none of connections changed
		// Optimization: we need check it only until the first node would be marked dirty, as this already marks Flow Asset package dirty
		if (bGraphDirty == false)
		{
			if (FoundConnections.Num() != Node->Connections.Num())
			{
				bGraphDirty = true;
			}
			else
			{
				for (const TPair<FName, FConnectedPin>& FoundConnection : FoundConnections)
				{
					if (const FConnectedPin* OldConnection = Node->Connections.Find(FoundConnection.Key))
					{
						if (FoundConnection.Value != *OldConnection)
						{
							bGraphDirty = true;
							break;
						}
					}
					else
					{
						bGraphDirty = true;
						break;
					}
				}
			}
		}

		if (bGraphDirty)
		{
			Node->SetFlags(RF_Transactional);
			Node->Modify();

			Node->SetConnections(FoundConnections);
			Node->PostEditChange();
		}
	}
}
#endif

void UFlowAsset::AddInstance(UFlowAsset* Instance)
{
	ActiveInstances.Add(Instance);
}

int32 UFlowAsset::RemoveInstance(UFlowAsset* Instance)
{
#if WITH_EDITOR
	if (InspectedInstance.IsValid() && InspectedInstance.Get() == Instance)
	{
		SetInspectedInstance(NAME_None);
	}
#endif

	ActiveInstances.Remove(Instance);
	return ActiveInstances.Num();
}

void UFlowAsset::ClearInstances()
{
#if WITH_EDITOR
	if (InspectedInstance.IsValid())
	{
		SetInspectedInstance(NAME_None);
	}
#endif

	for (int32 i = ActiveInstances.Num() - 1; i >= 0; i--)
	{
		if (ActiveInstances.IsValidIndex(i) && ActiveInstances[i])
		{
			ActiveInstances[i]->FinishFlow(EFlowFinishPolicy::Keep);
		}
	}

	ActiveInstances.Empty();
}

#if WITH_EDITOR
void UFlowAsset::GetInstanceDisplayNames(TArray<TSharedPtr<FName>>& OutDisplayNames) const
{
	for (const UFlowAsset* Instance : ActiveInstances)
	{
		OutDisplayNames.Emplace(MakeShareable(new FName(Instance->GetDisplayName())));
	}
}

void UFlowAsset::SetInspectedInstance(const FName& NewInspectedInstanceName)
{
	if (NewInspectedInstanceName.IsNone())
	{
		InspectedInstance = nullptr;
	}
	else
	{
		for (UFlowAsset* ActiveInstance : ActiveInstances)
		{
			if (ActiveInstance && ActiveInstance->GetDisplayName() == NewInspectedInstanceName)
			{
				if (!InspectedInstance.IsValid() || InspectedInstance != ActiveInstance)
				{
					InspectedInstance = ActiveInstance;
				}
				break;
			}
		}
	}

	BroadcastDebuggerRefresh();
}
#endif

void UFlowAsset::InitializeInstance(const TWeakObjectPtr<UObject> InOwner, UFlowAsset* InTemplateAsset)
{
	Owner = InOwner;
	TemplateAsset = InTemplateAsset;

	for (TPair<FGuid, UFlowNode*>& Node : Nodes)
	{
		UFlowNode* NewNodeInstance = NewObject<UFlowNode>(this, Node.Value->GetClass(), NAME_None, RF_Transient, Node.Value, false, nullptr);
		Node.Value = NewNodeInstance;

		// there can be only one, automatically added while creating graph
		if (UFlowNode_Start* InNode = Cast<UFlowNode_Start>(NewNodeInstance))
		{
			StartNode = InNode;
		}

		if (UFlowNode_CustomInput* CustomInput = Cast<UFlowNode_CustomInput>(NewNodeInstance))
		{
			if (!CustomInput->EventName.IsNone())
			{
				CustomInputNodes.Emplace(CustomInput);
			}
		}

		NewNodeInstance->InitializeInstance();
	}
}

void UFlowAsset::DeinitializeInstance()
{
	if (TemplateAsset)
	{
		const int32 ActiveInstancesLeft = TemplateAsset->RemoveInstance(this);
		if (ActiveInstancesLeft == 0 && GetFlowSubsystem())
		{
			GetFlowSubsystem()->RemoveInstancedTemplate(TemplateAsset);
		}
	}
}

void UFlowAsset::PreloadNodes()
{
	TArray<UFlowNode*> GraphEntryNodes = {StartNode};
	for (UFlowNode_CustomInput* CustomInput : CustomInputNodes)
	{
		GraphEntryNodes.Emplace(CustomInput);
	}

	// NOTE: this is just the example algorithm of gathering nodes for pre-load
	for (UFlowNode* EntryNode : GraphEntryNodes)
	{
		for (const TPair<TSubclassOf<UFlowNode>, int32>& Node : UFlowSettings::Get()->DefaultPreloadDepth)
		{
			if (Node.Value > 0)
			{
				TArray<UFlowNode*> FoundNodes;
				UFlowNode::RecursiveFindNodesByClass(EntryNode, Node.Key, Node.Value, FoundNodes);

				for (UFlowNode* FoundNode : FoundNodes)
				{
					if (!PreloadedNodes.Contains(FoundNode))
					{
						FoundNode->TriggerPreload();
						PreloadedNodes.Emplace(FoundNode);
					}
				}
			}
		}
	}
}

void UFlowAsset::PreStartFlow()
{
	ResetNodes();

#if WITH_EDITOR
	if (TemplateAsset->ActiveInstances.Num() == 1)
	{
		// this instance is the only active one, set it directly as Inspected Instance
		TemplateAsset->SetInspectedInstance(GetDisplayName());
	}
	else
	{
		// request to refresh list to show newly created instance
		TemplateAsset->BroadcastDebuggerRefresh();
	}
#endif
}

void UFlowAsset::StartFlow(UGameInstance* GameInstance, FFlowAssetOverrideData OverrideData, const FName InputName)
{
	PreStartFlow();

	//Run Traits
	for(UFlowAssetTrait* TempTrait : Traits)
	{
		if(TempTrait)
		{
			TempTrait->Native_FlowBegin(this);
		}
	}
	
	ensureAlways(StartNode);
	RecordedNodes.Add(StartNode);

	//Try Override Nodes
	if(OverrideData.bOverrideStartingNodes)
	{
		for (FGuid TempGuid : OverrideData.StartingNodes)
		{
			if(GetNodeFromGuid(TempGuid))
			{
				TriggerInput(TempGuid, InputName,true);
			}
		}
	}
	else
	{
		StartNode->TriggerFirstOutput(true);
	}
	
}

void UFlowAsset::FinishFlow(const EFlowFinishPolicy InFinishPolicy, const bool bRemoveInstance /*= true*/)
{
	FinishPolicy = InFinishPolicy;

	for(UFlowAssetTrait* TempTrait : Traits)
	{
		if(TempTrait)
		{
			TempTrait->Native_FlowEnd(this,"Finish","");
		}
	}
	
	// end execution of this asset and all of its nodes
	for (UFlowNode* Node : ActiveNodes)
	{
		Node->Deactivate();
	}
	ActiveNodes.Empty();

	// flush preloaded content
	for (UFlowNode* PreloadedNode : PreloadedNodes)
	{
		PreloadedNode->TriggerFlush();
	}
	PreloadedNodes.Empty();

	// provides option to finish game-specific logic prior to removing asset instance 
	if (bRemoveInstance)
	{
		DeinitializeInstance();
	}
}

TWeakObjectPtr<UFlowAsset> UFlowAsset::GetFlowInstance(UFlowNode_SubGraph* SubGraphNode) const
{
	return ActiveSubGraphs.FindRef(SubGraphNode);
}

void UFlowAsset::TriggerCustomEvent(UFlowNode_SubGraph* Node, const FName& EventName) const
{
	const TWeakObjectPtr<UFlowAsset> FlowInstance = ActiveSubGraphs.FindRef(Node);
	if (FlowInstance.IsValid())
	{
		for (UFlowNode_CustomInput* CustomInput : FlowInstance->CustomInputNodes)
		{
			if (CustomInput->EventName == EventName)
			{
				FlowInstance->RecordedNodes.Add(CustomInput);
				CustomInput->TriggerFirstOutput(true);
			}
		}
	}
}

void UFlowAsset::TriggerCustomOutput(const FName& EventName) const
{
	NodeOwningThisAssetInstance->TriggerOutput(EventName);
}

void UFlowAsset::TriggerInput(const FGuid& NodeGuid, const FName& PinName, bool bForce)
{
	if (UFlowNode* Node = Nodes.FindRef(NodeGuid))
	{
		if (!ActiveNodes.Contains(Node))
		{
			ActiveNodes.Add(Node);
			RecordedNodes.Add(Node);
		}
		for(auto* t : Traits)
		{
			if(t)
			{
				t->NodeInput(Node,PinName);
			}
		}
		if(bForce && !Node->HasPin(PinName,true))
		{
			if(Node->InputPins.IsValidIndex(0))
			{
				Node->TriggerInput(Node->InputPins[0].PinName);
			}
		}
		else
		{
			Node->TriggerInput(PinName);
		}
	}
}

void UFlowAsset::FinishNode(UFlowNode* Node)
{
	if (ActiveNodes.Contains(Node))
	{
		ActiveNodes.Remove(Node);

		// if graph reached Finish and this asset instance was created by SubGraph node
		if (Node->CanFinishGraph())
		{
			if (NodeOwningThisAssetInstance.IsValid())
			{
				NodeOwningThisAssetInstance.Get()->TriggerFirstOutput(true);
			}
			else
			{
				FinishFlow(EFlowFinishPolicy::Keep);
			}
		}
	}
}

void UFlowAsset::ResetNodes()
{
	for (UFlowNode* Node : RecordedNodes)
	{
		Node->ResetRecords();
	}

	RecordedNodes.Empty();
}

UFlowSubsystem* UFlowAsset::GetFlowSubsystem() const
{
	return Cast<UFlowSubsystem>(GetOuter());
}

FName UFlowAsset::GetDisplayName() const
{
	return GetFName();
}

UFlowNode_SubGraph* UFlowAsset::GetNodeOwningThisAssetInstance() const
{
	return NodeOwningThisAssetInstance.Get();
}

UFlowAsset* UFlowAsset::GetParentInstance() const
{
	return NodeOwningThisAssetInstance.IsValid() ? NodeOwningThisAssetInstance.Get()->GetFlowAsset() : nullptr;
}

FFlowAssetSaveData UFlowAsset::SaveInstance(TArray<FFlowAssetSaveData>& SavedFlowInstances)
{
	FFlowAssetSaveData AssetRecord;
	AssetRecord.WorldName = IsBoundToWorld() ? GetWorld()->GetName() : FString();
	AssetRecord.InstanceName = GetName();

	// opportunity to collect data before serializing asset
	OnSave();

	// iterate SubGraphs
	for (const TPair<FGuid, UFlowNode*>& Node : Nodes)
	{
		if (Node.Value && Node.Value->ActivationState == EFlowNodeState::Active)
		{
			if (UFlowNode_SubGraph* SubGraphNode = Cast<UFlowNode_SubGraph>(Node.Value))
			{
				const TWeakObjectPtr<UFlowAsset> SubFlowInstance = GetFlowInstance(SubGraphNode);
				if (SubFlowInstance.IsValid())
				{
					const FFlowAssetSaveData SubAssetRecord = SubFlowInstance->SaveInstance(SavedFlowInstances);
					SubGraphNode->SavedAssetInstanceName = SubAssetRecord.InstanceName;
				}
			}

			FFlowNodeSaveData NodeRecord;
			Node.Value->SaveInstance(NodeRecord);

			AssetRecord.NodeRecords.Emplace(NodeRecord);
		}
	}

	// serialize asset
	FMemoryWriter MemoryWriter(AssetRecord.AssetData, true);
	FFlowArchive Ar(MemoryWriter);
	Serialize(Ar);

	// write archive to SaveGame
	SavedFlowInstances.Emplace(AssetRecord);

	return AssetRecord;
}

void UFlowAsset::LoadInstance(const FFlowAssetSaveData& AssetRecord)
{
	FMemoryReader MemoryReader(AssetRecord.AssetData, true);
	FFlowArchive Ar(MemoryReader);
	Serialize(Ar);

	PreStartFlow();

	for (const FFlowNodeSaveData& NodeRecord : AssetRecord.NodeRecords)
	{
		if (UFlowNode* Node = Nodes.FindRef(NodeRecord.NodeGuid))
		{
			Node->LoadInstance(NodeRecord);
		}
	}

	OnLoad();
}

void UFlowAsset::OnActivationStateLoaded(UFlowNode* Node)
{
	if (Node->ActivationState != EFlowNodeState::NeverActivated)
	{
		RecordedNodes.Emplace(Node);
	}

	if (Node->ActivationState == EFlowNodeState::Active)
	{
		ActiveNodes.Emplace(Node);
	}
}

void UFlowAsset::OnSave_Implementation()
{
}

void UFlowAsset::OnLoad_Implementation()
{
}

bool UFlowAsset::IsBoundToWorld_Implementation()
{
	return bWorldBound;
}

//######################################################################################################
// Omega Additions
//######################################################################################################

void UFlowAsset::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name = DisplayName;
	Description = AssetDescription;
}

void UFlowAsset::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture,
	UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = Icon;
}

void UFlowAsset::GetGeneralAssetLabel_Implementation(FString& Label)
{
	if(CustomLabel.IsEmpty())
	{
		Label = this->GetDisplayName().ToString();
	}
	else
	{
		Label = CustomLabel;
	}
}

FGameplayTag UFlowAsset::GetObjectGameplayCategory_Implementation()
{
	return GameplayCategory;
}

FGameplayTagContainer UFlowAsset::GetObjectGameplayTags_Implementation()
{
	return GameplayTags;
}

TArray<UFlowNode*> UFlowAsset::GetAllNodes()
{
	TArray<UFlowNode*> OutNodes;
	TArray<FGuid> TempGuidArray;
	GetNodes().GetKeys(TempGuidArray);
	for(FGuid TempGuid : TempGuidArray)
	{
		if(GetNodes()[TempGuid])
		{
			OutNodes.Add(GetNodes()[TempGuid]);
		}
	}
	return OutNodes;
}

UFlowNode* UFlowAsset::GetNodeFromGuid(FGuid Guid)
{
	if(Nodes.FindOrAdd(Guid))
	{
		UFlowNode* OutNode = Nodes.FindOrAdd(Guid);
		return OutNode;
	}
	return nullptr;
}

TArray<FGuid> UFlowAsset::GetActiveNodeGuids()
{
	TArray<FGuid> OutGuid;
	for(const UFlowNode* TempNode : GetActiveNodes())
	{
		OutGuid.Add(TempNode->GetGuid());
	}
	return OutGuid;
}

void UFlowAsset::ForceActivateNode(FGuid NodeGuid, FName InputName)
{
	TriggerInput(NodeGuid, InputName);
}

void UFlowAsset::NotifyFlow(FName Notify, UObject* Context)
{
	for(auto* TempTrait : Traits)
	{
		if(TempTrait)
		{
			TempTrait->FlowNotified(this,Notify,Context);
		}
	}
	for(auto* TempNode : GetAllNodes())
	{
		if(TempNode)
		{
			TempNode->FlowNotified(Notify,Context);
		}
	}
}
