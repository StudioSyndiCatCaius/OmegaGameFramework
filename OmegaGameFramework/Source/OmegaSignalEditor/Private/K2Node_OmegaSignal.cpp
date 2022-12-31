// Fill out your copyright notice in the Description page of Project Settings.


#include "K2Node_OmegaSignal.h"

#include "BlueprintActionDatabase.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "EdGraphSchema_K2.h"
#include "EdGraph/EdGraphSchema.h"
#include "EditorCategoryUtils.h"
#include "K2Node_CallFunction.h"
#include "K2Node_CreateDelegate.h"
#include "KismetCompiler.h"
#include "OmegaSignalSubsystem.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"

#define LOCTEXT_NAMESPACE "K2Node_OmegaSignal"


FName UK2Node_OmegaSignal::Local_GetEventName() const
{
	return  SignalAsset ? SignalAsset->GetFName() : FName();
}


FLinearColor UK2Node_OmegaSignal::GetNodeTitleColor() const
{
	return FLinearColor(0,0.75,1);
}

FText UK2Node_OmegaSignal::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	// TODO: Is Using InputAction->GetFName okay here? Full Asset path would be better for disambiguation.
	if (TitleType == ENodeTitleType::MenuTitle)
	{
		return FText::FromName(Local_GetEventName());
	}
	else if (CachedNodeTitle.IsOutOfDate(this))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("SignalName"), FText::FromName(Local_GetEventName()));

		FText LocFormat = LOCTEXT("OmegaSignal_Name", "Signal: {SignalName}");
		// FText::Format() is slow, so we cache this to save on performance
		CachedNodeTitle.SetCachedText(FText::Format(LocFormat, Args), this);
	}

	return CachedNodeTitle;
}

bool UK2Node_OmegaSignal::IsCompatibleWithGraph(UEdGraph const* Graph) const
{
	// This node expands into event nodes and must be placed in a Ubergraph
	EGraphType const GraphType = Graph->GetSchema()->GetGraphType(Graph);
	bool bIsCompatible = (GraphType == EGraphType::GT_Ubergraph);

	if (bIsCompatible)
	{
		UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraph(Graph);

		UEdGraphSchema_K2 const* K2Schema = Cast<UEdGraphSchema_K2>(Graph->GetSchema());
		bool const bIsConstructionScript = (K2Schema != nullptr) ? UEdGraphSchema_K2::IsConstructionScript(Graph) : false;

		bIsCompatible = (Blueprint != nullptr) && Blueprint->SupportsInputEvents() && !bIsConstructionScript && Super::IsCompatibleWithGraph(Graph);
	}
	return bIsCompatible;
}

void UK2Node_OmegaSignal::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	//CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);
	//CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

	
}

void UK2Node_OmegaSignal::ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	//SETUP DATA
	
	
	UEdGraphPin* ExecPin = GetExecPin();
	UEdGraphPin* ThenPin = GetThenPin();
	
	if (ExecPin && ThenPin) {

		// create a CallFunction node
		const FName MyFunctionName = GET_FUNCTION_NAME_CHECKED(UOmegaSignalSubsystem, FireGlobalSignal);

		UK2Node_CallFunction* CallFuncNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
		CallFuncNode->FunctionReference.SetExternalMember(MyFunctionName, UOmegaSignalSubsystem::StaticClass());
		CallFuncNode->AllocateDefaultPins();

		// move pins
		CompilerContext.MovePinLinksToIntermediate(*ExecPin, *(CallFuncNode->GetExecPin()));
		CompilerContext.MovePinLinksToIntermediate(*ThenPin, *(CallFuncNode->GetThenPin()));
	}

	// break any links to the expanded node
	BreakAllNodeLinks();
}

UEdGraphPin* UK2Node_OmegaSignal::GetThenPin() const
{
	UEdGraphPin* Pin = FindPin(UEdGraphSchema_K2::PN_Then);
	check(Pin == nullptr || Pin->Direction == EGPD_Output); // If pin exists, it must be output
	return Pin;
}


void UK2Node_OmegaSignal::ValidateNodeDuringCompilation(FCompilerResultsLog& MessageLog) const
{
	Super::ValidateNodeDuringCompilation(MessageLog);

	if (!SignalAsset)
	{
		MessageLog.Error(*LOCTEXT("EnhancedInputAction_ErrorFmt", "EnhancedInputActionEvent references invalid 'null' action for @@").ToString(), this);
	}
}

void UK2Node_OmegaSignal::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	auto CustomizeInputNodeLambda = [](UEdGraphNode* NewNode, bool bIsTemplateNode, TWeakObjectPtr<const UOmegaSignalAsset> Action)
	{
		UK2Node_OmegaSignal* InputNode = CastChecked<UK2Node_OmegaSignal>(NewNode);
		InputNode->SignalAsset = Action.Get();
	};

	// Do a first time registration using the node's class to pull in all existing actions
	if (ActionRegistrar.IsOpenForRegistration(GetClass()))
	{
		IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry")).Get();

		static bool bRegisterOnce = true;
		if (bRegisterOnce)
		{
			bRegisterOnce = false;
			if (AssetRegistry.IsLoadingAssets())
			{
				AssetRegistry.OnFilesLoaded().AddLambda([]() { FBlueprintActionDatabase::Get().RefreshClassActions(StaticClass()); });
			}
		}

		TArray<FAssetData> ActionAssets;
		AssetRegistry.GetAssetsByClass(UOmegaSignalAsset::StaticClass()->GetFName(), ActionAssets);
		for (const FAssetData& ActionAsset : ActionAssets)
		{
			UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
			check(NodeSpawner != nullptr);

			if (const UOmegaSignalAsset* Action = Cast<const UOmegaSignalAsset>(ActionAsset.GetAsset()))
			{
				NodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(CustomizeInputNodeLambda, TWeakObjectPtr<const UOmegaSignalAsset>(Action));
				ActionRegistrar.AddBlueprintAction(Action, NodeSpawner);	
			}
		}
	}
	else if (const UOmegaSignalAsset* Action = Cast<const UOmegaSignalAsset>(ActionRegistrar.GetActionKeyFilter()))
	{
		// If this is a specific UInputAction asset update it.
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner != nullptr);

		NodeSpawner->CustomizeNodeDelegate = UBlueprintNodeSpawner::FCustomizeNodeDelegate::CreateStatic(CustomizeInputNodeLambda, TWeakObjectPtr<const UOmegaSignalAsset>(Action));
		ActionRegistrar.AddBlueprintAction(Action, NodeSpawner);
	}
}

FText UK2Node_OmegaSignal::GetMenuCategory() const
{
	static FNodeTextCache CachedCategory;
	if (CachedCategory.IsOutOfDate(this))
	{
		// FText::Format() is slow, so we cache this to save on performance
		CachedCategory.SetCachedText(FEditorCategoryUtils::BuildCategoryString(FCommonEditorCategory::Input, LOCTEXT("SignalMenuCategory", "Signal Events")), this);	// TODO: Rename Action Events once old action system is removed
	}
	return CachedCategory;
}

FBlueprintNodeSignature UK2Node_OmegaSignal::GetSignature() const
{
	FBlueprintNodeSignature NodeSignature = Super::GetSignature();
	NodeSignature.AddKeyValue(Local_GetEventName().ToString());

	return NodeSignature;
}

void UK2Node_OmegaSignal::PostReconstructNode()
{
	Super::PostReconstructNode();
	//HideEventPins(nullptr);
}

//#######################################################################################################
// EVENT NODE
//#######################################################################################################

