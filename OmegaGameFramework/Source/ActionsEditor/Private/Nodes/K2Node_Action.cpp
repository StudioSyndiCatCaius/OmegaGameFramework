// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "K2Node_Action.h"

#include <BlueprintNodeSpawner.h>
#include <BlueprintFunctionNodeSpawner.h>
#include <BlueprintActionDatabaseRegistrar.h>
#include <EditorCategoryUtils.h>
#include <K2Node_CallFunction.h>
#include <K2Node_AssignmentStatement.h>
#include <KismetCompiler.h>
#include <Kismet2/BlueprintEditorUtils.h>

#include "ActionsEditor.h"
#include "ActionNodeHelpers.h"

#include "ActionLibrary.h"
#include "Action.h"


#define LOCTEXT_NAMESPACE "ActionEditor"

const FName UK2Node_Action::ClassPinName{ "__Class" };
const FName UK2Node_Action::OwnerPinName{ UEdGraphSchema_K2::PN_Self };

//DECLARE ACTUAL NODE
UK2Node_Action::UK2Node_Action()
	: Super()
{
	NodeTooltip = LOCTEXT("NodeTooltip", "Creates a new action");
}


void UK2Node_Action::PostLoad()
{
	Super::PostLoad();
	BindBlueprintCompile();
	
}

///////////////////////////////////////////////////////////////////////////////
// UEdGraphNode Interface

void UK2Node_Action::AllocateDefaultPins()
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	// Add execution pins
	CreatePin(EGPD_Input, K2Schema->PC_Exec, K2Schema->PN_Execute);
	CreatePin(EGPD_Output, K2Schema->PC_Exec, K2Schema->PN_Then);

	// Action Owner
	UEdGraphPin* SelfPin = CreatePin(EGPD_Input, K2Schema->PC_Object, UObject::StaticClass(), OwnerPinName);
	SelfPin->PinFriendlyName = LOCTEXT("Owner", "Owner");


	//If we are not using a predefined class
	if (ShowClass())
	{
		CreateClassPin();
	}

	// Result pin
	UClass* ReturnClass = ActionClass? ActionClass : GetClassPinBaseClass();
	UEdGraphPin* ResultPin = CreatePin(EGPD_Output, K2Schema->PC_Object, ReturnClass, K2Schema->PN_ReturnValue);

	//Update class pins if we have an assigned class
	if (ActionClass)
	{
		OnClassPinChanged();
		BindBlueprintCompile();
	}

	Super::AllocateDefaultPins();
}

FLinearColor UK2Node_Action::GetNodeTitleColor() const
{
	if(ActionClass)
	{
		return Cast<UAction>(ActionClass->ClassDefaultObject)->NodeColor;
	}
	return FColor{ 10, 10, 10 };
}

FText UK2Node_Action::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (ShowClass() && (TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle))
	{
		return GetBaseNodeTitle();
	}
	else if (ActionClass)
	{
		if (CachedNodeTitle.IsOutOfDate(this))
		{
			FFormatNamedArguments Args;
			Args.Add(TEXT("ClassName"), ActionClass->GetDisplayNameText());
			// FText::Format() is slow, so we cache this to save on performance
			CachedNodeTitle.SetCachedText(FText::Format(GetNodeTitleFormat(), Args), this);
		}
		return CachedNodeTitle;
	}
	return NSLOCTEXT("K2Node", "Action_Title_None", "No Action");
}

void UK2Node_Action::PinDefaultValueChanged(UEdGraphPin* ChangedPin)
{
	// Class changed
	if (ChangedPin && (ChangedPin->PinName == ClassPinName))
	{
		ActionClass = GetActionClassFromPin();
		OnClassPinChanged();
		BindBlueprintCompile();
	}
}

FText UK2Node_Action::GetTooltipText() const
{
	return NodeTooltip;
}

bool UK2Node_Action::HasExternalDependencies(TArray<class UStruct*>* OptionalOutput) const
{
	const UBlueprint* SourceBlueprint = GetBlueprint();
	const bool bResult = ActionClass && ActionClass->ClassGeneratedBy != SourceBlueprint;
	if (bResult && OptionalOutput)
	{
		OptionalOutput->AddUnique(ActionClass);
	}
	const bool bSuperResult = Super::HasExternalDependencies(OptionalOutput);
	return bSuperResult || bResult;
}

bool UK2Node_Action::IsCompatibleWithGraph(const UEdGraph* TargetGraph) const
{
	UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForGraph(TargetGraph);
	return Super::IsCompatibleWithGraph(TargetGraph) && (!Blueprint || FBlueprintEditorUtils::FindUserConstructionScript(Blueprint) != TargetGraph);
}

void UK2Node_Action::PinConnectionListChanged(UEdGraphPin* Pin)
{
	if (Pin && (Pin->PinName == ClassPinName))
	{
		ActionClass = GetActionClassFromPin();
		OnClassPinChanged();
	}
}

void UK2Node_Action::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
	UEdGraphPin* ClassPin = GetClassPin();
	if (ClassPin)
	{
		SetPinToolTip(*ClassPin, LOCTEXT("ClassPinDescription", "The object class you want to construct"));
	}
	UEdGraphPin* ResultPin = GetResultPin();
	if (ResultPin)
	{
		SetPinToolTip(*ResultPin, LOCTEXT("ResultPinDescription", "The constructed action"));
	}

	if (UEdGraphPin* OwnerPin = GetOwnerPin())
	{
		SetPinToolTip(*OwnerPin, LOCTEXT("OwnerPinDescription", "Parent of the action"));
	}

	return Super::GetPinHoverText(Pin, HoverTextOut);
}

//This will expand node for our custom object, with properties
//which are set as EditAnywhere and meta=(ExposeOnSpawn), or equivalent in blueprint.
void UK2Node_Action::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(SourceGraph && Schema);

	//Get static function
	static FName Create_FunctionName = GET_FUNCTION_NAME_CHECKED(UActionLibrary, CreateAction);
	static FName Activate_FunctionName = GET_FUNCTION_NAME_CHECKED(UAction, Activate);

	//Set function parameter names
	static FString ParamName_Type = FString(TEXT("Type"));


	/* Retrieve Pins */
	//Exec
	UEdGraphPin* ExecPin = GetExecPin();	   // Exec pins are those big arrows, connected with thick white lines.
	UEdGraphPin* ThenPin = GetThenPin();	   // Then pin is the same as exec pin, just on the other side (the out arrow).

	//Inputs
	UEdGraphPin* OwnerPin = GetOwnerPin();
	UEdGraphPin* ClassPin = GetClassPin();	 // Get class pin which is used to determine which class to spawn.

	//Outputs
	UEdGraphPin* ResultPin = GetResultPin();   // Result pin, which will output our spawned object.

	if (!HasWorldContext())
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("CreateActionNodeMissingClass_Error", "@@ node requires world context.").ToString(), this);
		// we break exec links so this is the only error we get, don't want the CreateItemData node being considered and giving 'unexpected node' type warnings
		BreakAllNodeLinks();
		return;
	}

	if (!ActionClass)
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("CreateActionNodeMissingClass_Error", "Create Action node @@ must have a class specified.").ToString(), this);
		// we break exec links so this is the only error we get, don't want the CreateItemData node being considered and giving 'unexpected node' type warnings
		BreakAllNodeLinks();
		return;
	}

	bool bIsErrorFree = true;

	//////////////////////////////////////////////////////////////////////////
	// create 'UActionFunctionLibrary::CreateAction' call node
	UK2Node_CallFunction* CreateActionNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	//Attach function
	CreateActionNode->FunctionReference.SetExternalMember(Create_FunctionName, UActionLibrary::StaticClass());
	CreateActionNode->AllocateDefaultPins();

	//allocate nodes for created widget.
	UEdGraphPin* CreateAction_Exec   = CreateActionNode->GetExecPin();
	UEdGraphPin* CreateAction_Owner	 = CreateActionNode->FindPinChecked(TEXT("Owner"));
	UEdGraphPin* CreateAction_Type   = CreateActionNode->FindPinChecked(ParamName_Type);
	UEdGraphPin* CreateAction_Result = CreateActionNode->GetReturnValuePin();

	// Move 'exec' pin to 'UActionFunctionLibrary::CreateAction'
	CompilerContext.MovePinLinksToIntermediate(*ExecPin, *CreateAction_Exec);

	//TODO: Create local variable for PrestatedClass

	//Move pin if connected else, copy the value
	if (ShowClass() && ClassPin->LinkedTo.Num() > 0)
	{
		// Copy the 'blueprint' connection from the spawn node to 'UActionLibrary::CreateAction'
		CompilerContext.MovePinLinksToIntermediate(*ClassPin, *CreateAction_Type);
	}
	else
	{
		// Copy blueprint literal onto 'UActionLibrary::CreateAction' call
		CreateAction_Type->DefaultObject = ActionClass;
	}

	// Copy Owner pin to 'UActionFunctionLibrary::CreateAction' if necessary
	if (OwnerPin)
	{
		CompilerContext.MovePinLinksToIntermediate(*OwnerPin, *CreateAction_Owner);
	}

	// Move Result pin to 'UActionFunctionLibrary::CreateAction'
	CreateAction_Result->PinType = ResultPin->PinType; // Copy type so it uses the right actor subclass
	CompilerContext.MovePinLinksToIntermediate(*ResultPin, *CreateAction_Result);


	//////////////////////////////////////////////////////////////////////////
	// create 'set var' nodes

	// Set all properties of the object
	UEdGraphPin* LastThenPin = FKismetCompilerUtilities::GenerateAssignmentNodes(CompilerContext, SourceGraph, CreateActionNode, this, CreateAction_Result, ActionClass);

	// For each delegate, define an event, bind it to delegate and implement a chain of assignments
	for (TFieldIterator<FMulticastDelegateProperty> PropertyIt(ActionClass, EFieldIteratorFlags::IncludeSuper); PropertyIt && bIsErrorFree; ++PropertyIt)
	{
		FMulticastDelegateProperty* Property = *PropertyIt;

		if (Property && Property->HasAllPropertyFlags(CPF_BlueprintAssignable) && Property->SignatureFunction)
		{
			const UFunction* DelegateSignatureFunction = Property->SignatureFunction;
			if (DelegateSignatureFunction->NumParms < 1)
			{
				bIsErrorFree &= FHelper::HandleDelegateImplementation(Property, CreateAction_Result, LastThenPin, this, SourceGraph, CompilerContext);
			}
			else
			{
				bIsErrorFree &= FHelper::HandleDelegateBindImplementation(Property, CreateAction_Result, LastThenPin, this, SourceGraph, CompilerContext);
			}
		}
	}

	if (!bIsErrorFree)
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("CreateActionNodeMissingClass_Error", "There was a compile error while binding delegates.").ToString(), this);
		// we break exec links so this is the only error we get, don't want the CreateAction node being considered and giving 'unexpected node' type warnings
		BreakAllNodeLinks();
		return;
	}


	//////////////////////////////////////////////////////////////////////////
	// create 'UAction::Activate' call node
	UK2Node_CallFunction* ActivateActionNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	//Attach function
	ActivateActionNode->FunctionReference.SetExternalMember(Activate_FunctionName, UAction::StaticClass());
	ActivateActionNode->AllocateDefaultPins();

	//allocate nodes for created widget.
	UEdGraphPin* ActivateAction_Exec = ActivateActionNode->GetExecPin();
	UEdGraphPin* ActivateAction_Self = ActivateActionNode->FindPinChecked(Schema->PN_Self);
	UEdGraphPin* ActivateAction_Then = ActivateActionNode->GetThenPin();

	bIsErrorFree &= Schema->TryCreateConnection(LastThenPin, ActivateAction_Exec);
	bIsErrorFree &= Schema->TryCreateConnection(CreateAction_Result, ActivateAction_Self);

	CompilerContext.MovePinLinksToIntermediate(*ThenPin, *ActivateAction_Then);


	if (!bIsErrorFree)
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("CreateActionNodeMissingClass_Error", "There was a compile error while activating the action.").ToString(), this);
		// we break exec links so this is the only error we get, don't want the CreateAction node being considered and giving 'unexpected node' type warnings
		BreakAllNodeLinks();
		return;
	}

	// Break any links to the expanded node
	BreakAllNodeLinks();
}

///////////////////////////////////////////////////////////////////////////////
// UK2Node Interface

void UK2Node_Action::ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins)
{
	AllocateDefaultPins();
	if (ActionClass)
	{
		CreatePinsForClass(ActionClass);
	}
	RestoreSplitPins(OldPins);
}

void UK2Node_Action::GetNodeAttributes(TArray<TKeyValuePair<FString, FString>>& OutNodeAttributes) const
{
	const FString ClassToSpawnStr = ActionClass? ActionClass->GetName() : TEXT("InvalidClass");
	OutNodeAttributes.Add(TKeyValuePair<FString, FString>(TEXT("Type"), TEXT("CreateAction")));
	OutNodeAttributes.Add(TKeyValuePair<FString, FString>(TEXT("Class"), GetClass()->GetName()));
	OutNodeAttributes.Add(TKeyValuePair<FString, FString>(TEXT("Name"), GetName()));
	OutNodeAttributes.Add(TKeyValuePair<FString, FString>(TEXT("ObjectClass"), ClassToSpawnStr));
}

void UK2Node_Action::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	UClass* ActionKey = GetClass();

	FActionNodeHelpers::RegisterActionClassActions(ActionRegistrar, ActionKey);

	if (ActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner != nullptr);

		NodeSpawner->DefaultMenuSignature.Keywords = LOCTEXT("MenuKeywords", "Create Action");
		ActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
	}
}

//Set context menu category in which our node will be present.
FText UK2Node_Action::GetMenuCategory() const
{
	return FText::FromString("Actions");
}

void UK2Node_Action::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	Super::GetNodeContextMenuActions(Menu, Context);

	if (!Context->bIsDebugging)
	{
		if (!Context->Pin || Context->Pin == GetClassPin())
		{
			FText Text;
			if(ShowClass())
			{
				Text = LOCTEXT("HideClass", "Hide Class pin");
			}
			else
			{
				Text = LOCTEXT("ShowClass", "Show Class pin");
			}

			auto& Section = Menu->AddSection("ActionNode", LOCTEXT("ActionNodeMenuSection", "Action Node"));
			Section.AddMenuEntry("ClassPinVisibility",
				Text,
				LOCTEXT("HideClassTooltip", "Hides the Class input pin"),
				FSlateIcon(),
				FUIAction(
					FExecuteAction::CreateUObject(const_cast<UK2Node_Action*>(this), &UK2Node_Action::ToogleShowClass)
				)
			);
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
// UK2Node_Action

void UK2Node_Action::CreatePinsForClass(UClass* InClass, TArray<UEdGraphPin*>* OutClassPins)
{
	check(InClass != nullptr);

	if(!ActionReflection::GetVisibleProperties(InClass, CurrentProperties))
	{
		return;
	}

	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	const UObject* const CDO = InClass->GetDefaultObject(false);
	for(const auto& Property : CurrentProperties.Variables)
	{
		UEdGraphPin* Pin = CreatePin(EGPD_Input, Property.GetType(), Property.GetFName());
		if(!Pin) { continue; }

		if (OutClassPins)
		{
			OutClassPins->Add(Pin);
		}

		if (CDO && K2Schema->PinDefaultValueIsEditable(*Pin))
		{
			FString DefaultValueAsString;
			const bool bDefaultValueSet = FBlueprintEditorUtils::PropertyValueToString(Property.GetProperty(), reinterpret_cast<const uint8*>(CDO), DefaultValueAsString);
			check(bDefaultValueSet);
			K2Schema->TrySetDefaultValue(*Pin, DefaultValueAsString);
		}

		// Copy tooltip from the property.
		K2Schema->ConstructBasicPinTooltip(*Pin, Property.GetProperty()->GetToolTipText(), Pin->PinToolTip);
	}

	for(const auto& Property : CurrentProperties.ComplexDelegates)
	{
		if (!Property.GetFunction())
		{
			UE_LOG(LogActionsEd, Error, TEXT("Delegate '%s' may be corrupted"), *Property.GetFName().ToString());
		}

		UEdGraphNode::FCreatePinParams Params{};
		Params.bIsConst = true;
		Params.bIsReference = true;
		UEdGraphPin* Pin = CreatePin(EGPD_Input, K2Schema->PC_Delegate, Property.GetFName(), Params);
		if(!Pin) { continue; }

		Pin->PinFriendlyName = FText::Format(NSLOCTEXT("K2Node", "PinFriendlyDelegateName", "{0}"), FText::FromName(Property.GetFName()));

		//Update PinType with the delegate's signature
		FMemberReference::FillSimpleMemberReference<UFunction>(Property.GetFunction(), Pin->PinType.PinSubCategoryMemberReference);

		if (OutClassPins)
		{
			OutClassPins->Add(Pin);
		}
	}

	for(const auto& Property : CurrentProperties.SimpleDelegates)
	{
		if (!Property.GetFunction())
		{
			UE_LOG(LogActionsEd, Error, TEXT("Delegate '%s' may be corrupted"), *Property.GetFName().ToString());
		}

		UEdGraphPin* Pin = CreatePin(EGPD_Output, K2Schema->PC_Exec, Property.GetFName());
		if(!Pin) { continue; }

		if (OutClassPins)
		{
			OutClassPins->Add(Pin);
		}
	}

	// Change class of output pin
	UEdGraphPin* ResultPin = GetResultPin();
	ResultPin->PinType.PinSubCategoryObject = InClass;
}

bool UK2Node_Action::IsActionVarPin(UEdGraphPin* Pin)
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	return(Pin->PinName != K2Schema->PN_Execute &&
		Pin->PinName != K2Schema->PN_Then &&
		Pin->PinName != K2Schema->PN_ReturnValue &&
		Pin->PinName != ClassPinName &&
		Pin->PinName != OwnerPinName);
}

UEdGraphPin* UK2Node_Action::GetThenPin()const
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	UEdGraphPin* Pin = FindPinChecked(K2Schema->PN_Then);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

UEdGraphPin* UK2Node_Action::GetClassPin(const TArray<UEdGraphPin*>* InPinsToSearch /*= nullptr*/) const
{
	const TArray<UEdGraphPin*>* PinsToSearch = InPinsToSearch? InPinsToSearch : &Pins;

	UEdGraphPin* Pin = nullptr;
	for (auto PinIt = PinsToSearch->CreateConstIterator(); PinIt; ++PinIt)
	{
		UEdGraphPin* TestPin = *PinIt;
		if (TestPin && TestPin->PinName == ClassPinName)
		{
			Pin = TestPin;
			break;
		}
	}
	check(!Pin || Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_Action::GetResultPin() const
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	UEdGraphPin* Pin = FindPinChecked(K2Schema->PN_ReturnValue);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

UEdGraphPin* UK2Node_Action::GetOwnerPin() const
{
	UEdGraphPin* Pin = FindPin(OwnerPinName);
	ensure(nullptr == Pin || Pin->Direction == EGPD_Input);
	return Pin;
}

UClass* UK2Node_Action::GetActionClassFromPin() const
{
	if (!ShowClass())
	{
		return ActionClass;
	}

	if(UEdGraphPin* ClassPin = GetClassPin())
	{
		if (ClassPin->DefaultObject && ClassPin->LinkedTo.Num() == 0)
		{
			return CastChecked<UClass>(ClassPin->DefaultObject);
		}
		else if (ClassPin->LinkedTo.Num())
		{
			auto ClassSource = ClassPin->LinkedTo[0];
			return ClassSource? Cast<UClass>(ClassSource->PinType.PinSubCategoryObject.Get()) : nullptr;
		}
	}
	return nullptr;
}

UBlueprint* UK2Node_Action::GetActionBlueprint() const
{
	if (!ActionClass)
	{
		return nullptr;
	}

	FString ClassPath = ActionClass->GetPathName();
	ClassPath.RemoveFromEnd(TEXT("_C"), ESearchCase::CaseSensitive);
	const FString BPPath = FString::Printf(TEXT("Blueprint'%s'"), *ClassPath);

	return Cast<UBlueprint>(
		StaticFindObject(UBlueprint::StaticClass(), nullptr, *BPPath)
	);
}

bool UK2Node_Action::UseWorldContext() const
{
	auto BP = GetBlueprint();
	const UClass* ParentClass = BP ? BP->ParentClass : nullptr;
	return ParentClass ? ParentClass->HasMetaDataHierarchical(FBlueprintMetadata::MD_ShowWorldContextPin) != nullptr : false;
}

bool UK2Node_Action::HasWorldContext() const
{
	return FBlueprintEditorUtils::ImplementsGetWorld(GetBlueprint());
}

FText UK2Node_Action::GetBaseNodeTitle() const
{
	return LOCTEXT("Action_BaseTitle", "GameplayAction");
}

FText UK2Node_Action::GetNodeTitleFormat() const
{
	return LOCTEXT("Action_ClassTitle", "{ClassName}");
}

//which class can be used with this node to create objects. All childs of class can be used.
UClass* UK2Node_Action::GetClassPinBaseClass() const
{
	return UAction::StaticClass();
}

void UK2Node_Action::SetPinToolTip(UEdGraphPin& MutatablePin, const FText& PinDescription) const
{
	MutatablePin.PinToolTip = UEdGraphSchema_K2::TypeToText(MutatablePin.PinType).ToString();

	if (const auto* K2Schema = Cast<const UEdGraphSchema_K2>(GetSchema()))
	{
		MutatablePin.PinToolTip += TEXT(" ");
		MutatablePin.PinToolTip += K2Schema->GetPinDisplayName(&MutatablePin).ToString();
	}

	MutatablePin.PinToolTip += FString(TEXT("\n")) + PinDescription.ToString();
}

void UK2Node_Action::OnClassPinChanged()
{
	bool bClassVisibilityChanged = false;

	UEdGraphPin* ClassPin = GetClassPin();
	if(ShowClass() && !ClassPin)
	{
		CreateClassPin();
	}
	else if(!ShowClass() && ClassPin)
	{
		// Class pin should exist, destroy it
		UBlueprint* Blueprint = GetBlueprint();

		ClassPin->Modify();
		Pins.Remove(ClassPin);
		ClassPin->BreakAllPinLinks(!Blueprint->bIsRegeneratingOnLoad);

		UEdGraphNode::DestroyPin(ClassPin);
	}
	else // Class pin visibility doesnt change
	{
		// Node will only refresh if the exposed variables and delegates changed
		FActionProperties Properties;
		const bool bFoundProperties = ActionReflection::GetVisibleProperties(ActionClass, Properties);
		if(!bFoundProperties || Properties == CurrentProperties)
		{
			return;
		}
	}


	// Remove all pins related to archetype variables
	TArray<UEdGraphPin*> OldPins = Pins;
	TArray<UEdGraphPin*> OldClassPins;
	for (UEdGraphPin* OldPin : OldPins)
	{
		if (IsActionVarPin(OldPin))
		{
			Pins.Remove(OldPin);
			OldClassPins.Add(OldPin);
		}
	}

	CachedNodeTitle.MarkDirty();

	TArray<UEdGraphPin*> NewClassPins;
	if (ActionClass)
	{
		CreatePinsForClass(ActionClass, &NewClassPins);
	}

	RestoreSplitPins(OldPins);

	// Rewire return pin
	{
		UEdGraphPin* ResultPin = GetResultPin();
		// Cache all the pin connections to the ResultPin, we will attempt to recreate them
		TArray<UEdGraphPin*> ResultPinConnectionList = ResultPin->LinkedTo;
		// Because the archetype has changed, we break the output link as the output pin type will change
		ResultPin->BreakAllPinLinks(true);

		// Recreate any pin links to the Result pin that are still valid
		for (UEdGraphPin* Connections : ResultPinConnectionList)
		{
			const auto* K2Schema = GetDefault<UEdGraphSchema_K2>();
			K2Schema->TryCreateConnection(ResultPin, Connections);
		}
	}

	// Rewire the old pins to the new pins so connections are maintained if possible
	RewireOldPinsToNewPins(OldClassPins, Pins, nullptr);

	// Refresh the UI for the graph so the pin changes show up
	GetGraph()->NotifyGraphChanged();

	// Mark dirty
	FBlueprintEditorUtils::MarkBlueprintAsModified(GetBlueprint());
}

void UK2Node_Action::OnBlueprintCompiled(UBlueprint* CompiledBP)
{
	if (ActionBlueprint == CompiledBP)
	{
		OnClassPinChanged();
	}
}

void UK2Node_Action::BindBlueprintCompile()
{
	if (ActionBlueprint)
	{
		ActionBlueprint->OnCompiled().RemoveAll(this);
		ActionBlueprint = nullptr;
	}

	if (UBlueprint* BPToSpawn = GetActionBlueprint())
	{
		BPToSpawn->OnCompiled().AddUObject(this, &UK2Node_Action::OnBlueprintCompiled);
		ActionBlueprint = BPToSpawn;
	}
}

void UK2Node_Action::ToogleShowClass()
{
	if(!ShowClass())
	{
		FScopedTransaction Transaction( LOCTEXT("ShowClassPin", "Show class pin") );
		Modify();

		bShowClass = !bShowClass;
		OnClassPinChanged();
	}
	else
	{
		FScopedTransaction Transaction( LOCTEXT("HideClassPin", "Hide class pin") );
		Modify();

		bShowClass = !bShowClass;
		OnClassPinChanged();
	}

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(GetBlueprint());
}

UEdGraphPin* UK2Node_Action::CreateClassPin()
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	// Add blueprint pin
	UEdGraphPin* ClassPin = CreatePin(EGPD_Input, K2Schema->PC_Class, GetClassPinBaseClass(), ClassPinName);
	ClassPin->PinFriendlyName = LOCTEXT("PinClassName", "Class");
	if(ActionClass)
	{
		ClassPin->DefaultObject = ActionClass;
	}
	return ClassPin;
}

bool UK2Node_Action::FHelper::ValidDataPin(const UEdGraphPin* Pin, EEdGraphPinDirection Direction, const UEdGraphSchema_K2* Schema)
{
	check(Schema);
	const bool bValidDataPin = Pin
		&& (Pin->PinName != Schema->PN_Execute)
		&& (Pin->PinName != Schema->PN_Then)
		&& (Pin->PinType.PinCategory != Schema->PC_Exec);

	const bool bProperDirection = Pin && (Pin->Direction == Direction);

	return bValidDataPin && bProperDirection;
}

bool UK2Node_Action::FHelper::CreateDelegateForNewFunction(UEdGraphPin* DelegateInputPin, FName FunctionName, UK2Node* CurrentNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext)
{
	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(DelegateInputPin && Schema && CurrentNode && SourceGraph && (FunctionName != NAME_None));
	bool bResult = true;

	// WORKAROUND, so we can create delegate from nonexistent function by avoiding check at expanding step
	// instead simply: Schema->TryCreateConnection(AddDelegateNode->GetDelegatePin(), CurrentCENode->FindPinChecked(UK2Node_CustomEvent::DelegateOutputName));
	UK2Node_Self* SelfNode = CompilerContext.SpawnIntermediateNode<UK2Node_Self>(CurrentNode, SourceGraph);
	SelfNode->AllocateDefaultPins();

	UK2Node_CreateDelegate* CreateDelegateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CreateDelegate>(CurrentNode, SourceGraph);
	CreateDelegateNode->AllocateDefaultPins();
	bResult &= Schema->TryCreateConnection(DelegateInputPin, CreateDelegateNode->GetDelegateOutPin());
	bResult &= Schema->TryCreateConnection(SelfNode->FindPinChecked(Schema->PN_Self), CreateDelegateNode->GetObjectInPin());
	CreateDelegateNode->SetFunction(FunctionName);

	return bResult;
}

bool UK2Node_Action::FHelper::CopyEventSignature(UK2Node_CustomEvent* CENode, UFunction* Function, const UEdGraphSchema_K2* Schema)
{
	check(CENode && Function && Schema);

	bool bResult = true;
	for (TFieldIterator<FProperty> PropIt(Function); PropIt && (PropIt->PropertyFlags & CPF_Parm); ++PropIt)
	{
		const FProperty* Param = *PropIt;
		if (!Param->HasAnyPropertyFlags(CPF_OutParm) || Param->HasAnyPropertyFlags(CPF_ReferenceParm))
		{
			FEdGraphPinType PinType;
			bResult &= Schema->ConvertPropertyToPinType(Param, /*out*/ PinType);
			bResult &= (nullptr != CENode->CreateUserDefinedPin(Param->GetFName(), PinType, EGPD_Output));
		}
	}
	return bResult;
}

bool UK2Node_Action::FHelper::HandleDelegateImplementation(
	FMulticastDelegateProperty* CurrentProperty,
	UEdGraphPin* ProxyObjectPin, UEdGraphPin*& InOutLastThenPin,
	UK2Node* CurrentNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext)
{
	bool bIsErrorFree = true;
	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	check(CurrentProperty && ProxyObjectPin && InOutLastThenPin && CurrentNode && SourceGraph && Schema);

	UEdGraphPin* PinForCurrentDelegateProperty = CurrentNode->FindPin(CurrentProperty->GetName());
	if (!PinForCurrentDelegateProperty || (Schema->PC_Exec != PinForCurrentDelegateProperty->PinType.PinCategory))
	{
		FText ErrorMessage = FText::Format(LOCTEXT("WrongDelegateProperty", "BaseAsyncConstructObject: Cannot find execution pin for delegate "), FText::FromString(CurrentProperty->GetName()));
		CompilerContext.MessageLog.Error(*ErrorMessage.ToString(), CurrentNode);
		return false;
	}

	UK2Node_CustomEvent* CurrentCENode = CompilerContext.SpawnIntermediateEventNode<UK2Node_CustomEvent>(CurrentNode, PinForCurrentDelegateProperty, SourceGraph);
	{
		UK2Node_AddDelegate* AddDelegateNode = CompilerContext.SpawnIntermediateNode<UK2Node_AddDelegate>(CurrentNode, SourceGraph);

		UBlueprint* Blueprint = FBlueprintEditorUtils::FindBlueprintForNodeChecked(CurrentNode);
		bool const bIsSelfContext = Blueprint->SkeletonGeneratedClass->IsChildOf(CurrentProperty->GetOwnerClass());

		AddDelegateNode->SetFromProperty(CurrentProperty, bIsSelfContext, CurrentProperty->GetOwnerClass());
		AddDelegateNode->AllocateDefaultPins();

		bIsErrorFree &= Schema->TryCreateConnection(AddDelegateNode->FindPinChecked(Schema->PN_Self), ProxyObjectPin);
		bIsErrorFree &= Schema->TryCreateConnection(InOutLastThenPin, AddDelegateNode->FindPinChecked(Schema->PN_Execute));
		InOutLastThenPin = AddDelegateNode->FindPinChecked(Schema->PN_Then);
		CurrentCENode->CustomFunctionName = *FString::Printf(TEXT("%s_%s"), *CurrentProperty->GetName(), *CompilerContext.GetGuid(CurrentNode));
		CurrentCENode->AllocateDefaultPins();

		bIsErrorFree &= FHelper::CreateDelegateForNewFunction(AddDelegateNode->GetDelegatePin(), CurrentCENode->GetFunctionName(), CurrentNode, SourceGraph, CompilerContext);
		bIsErrorFree &= FHelper::CopyEventSignature(CurrentCENode, AddDelegateNode->GetDelegateSignature(), Schema);
	}

	UEdGraphPin* LastActivatedNodeThen = CurrentCENode->FindPinChecked(Schema->PN_Then);

	bIsErrorFree &= CompilerContext.MovePinLinksToIntermediate(*PinForCurrentDelegateProperty, *LastActivatedNodeThen).CanSafeConnect();
	return bIsErrorFree;
}


bool UK2Node_Action::FHelper::HandleDelegateBindImplementation(
	FMulticastDelegateProperty* CurrentProperty,
	UEdGraphPin* ObjectPin, UEdGraphPin*& InOutLastThenPin,
	UK2Node* CurrentNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext)
{
	bool bIsErrorFree = true;
	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();

	check(CurrentProperty && Schema);
	UEdGraphPin* DelegateRefPin = CurrentNode->FindPinChecked(CurrentProperty->GetName());
	check(DelegateRefPin);

	UK2Node_AddDelegate* AddDelegateNode = CompilerContext.SpawnIntermediateNode<UK2Node_AddDelegate>(CurrentNode, SourceGraph);
	check(AddDelegateNode);


	AddDelegateNode->SetFromProperty(CurrentProperty, false, CurrentProperty->GetOwnerClass());
	AddDelegateNode->AllocateDefaultPins();

	bIsErrorFree &= Schema->TryCreateConnection(AddDelegateNode->FindPinChecked(Schema->PN_Self), ObjectPin);
	bIsErrorFree &= Schema->TryCreateConnection(InOutLastThenPin, AddDelegateNode->FindPinChecked(Schema->PN_Execute));
	InOutLastThenPin = AddDelegateNode->FindPinChecked(Schema->PN_Then);

	UEdGraphPin* AddDelegate_DelegatePin = AddDelegateNode->GetDelegatePin();
	bIsErrorFree &= CompilerContext.MovePinLinksToIntermediate(*DelegateRefPin, *AddDelegate_DelegatePin).CanSafeConnect();
	DelegateRefPin->PinType = AddDelegate_DelegatePin->PinType;

	return bIsErrorFree;
}

#undef LOCTEXT_NAMESPACE