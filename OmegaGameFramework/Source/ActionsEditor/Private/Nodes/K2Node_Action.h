// Copyright Studio Syndicat 2021. All Rights Reserved. 

#pragma once

#include <CoreMinimal.h>
#include <UObject/ObjectMacros.h>
#include <EdGraph/EdGraphNodeUtils.h>
#include <EdGraphSchema_K2.h>

#include <K2Node.h>
#include <K2Node_AddDelegate.h>
#include <K2Node_CreateDelegate.h>
#include <K2Node_Self.h>
#include <K2Node_CustomEvent.h>
#include <K2Node_TemporaryVariable.h>
#include <ToolMenu.h>

#include "ActionReflection.h"
#include "K2Node_Action.generated.h"


UCLASS(Blueprintable)
class ACTIONSEDITOR_API UK2Node_Action : public UK2Node
{
	GENERATED_BODY()

	static const FName ClassPinName;
	static const FName OwnerPinName;

public:

	UPROPERTY()
	UClass* ActionClass;

	UPROPERTY()
	bool bShowClass = true;

protected:

	/** Output pin visibility control */
	UPROPERTY(EditAnywhere, Category = PinOptions, EditFixedSize)
	TArray<FOptionalPinFromProperty> ShowPinForProperties;

	/** Tooltip text for this node. */
	FText NodeTooltip;

private:

	UPROPERTY()
	FActionProperties CurrentProperties;

	/** Blueprint that is binded OnCompile */
	UPROPERTY()
	UBlueprint* ActionBlueprint;

	/** Constructing FText strings can be costly, so we cache the node's title */
	FNodeTextCache CachedNodeTitle;


public:

	UK2Node_Action();

protected:

	virtual void PostLoad() override;

	//~ Begin UEdGraphNode Interface.
	virtual void AllocateDefaultPins() override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;
	virtual FText GetTooltipText() const override;
	virtual bool HasExternalDependencies(TArray<class UStruct*>* OptionalOutput) const override;
	virtual bool IsCompatibleWithGraph(const UEdGraph* TargetGraph) const override;
	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	// End UEdGraphNode interface.

	//~ Begin UK2Node Interface
	virtual bool IsNodeSafeToIgnore() const override { return true; }
	virtual void ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins) override;
	virtual void GetNodeAttributes(TArray<TKeyValuePair<FString, FString>>& OutNodeAttributes) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;
	//~ End UK2Node Interface


	/** Create new pins to show properties on archetype */
	void CreatePinsForClass(UClass* InClass, TArray<UEdGraphPin*>* OutClassPins = nullptr);

	/** See if this is a spawn variable pin, or a 'default' pin */
	virtual bool IsActionVarPin(UEdGraphPin* Pin);

	UEdGraphPin* GetThenPin() const;
	UEdGraphPin* GetClassPin(const TArray<UEdGraphPin*>* InPinsToSearch = nullptr) const;
	UEdGraphPin* GetResultPin() const;
	UEdGraphPin* GetOwnerPin() const;

	/** Get the class that we are going to spawn, if it's defined as default value */
	UClass* GetActionClassFromPin() const;

	/** Get the class that we are going to spawn, if it's defined as default value */
	UBlueprint* GetActionBlueprint() const;

	/** Returns if the node uses World Object Context input */
	virtual bool UseWorldContext() const;

	/** Returns if the node has World Context */
	virtual bool HasWorldContext() const;

	/** Returns if the node uses Owner input */
	virtual bool UseOwner() const { return true; }
	virtual bool ShowClass() const { return bShowClass; }

	/** Gets the default node title when no class is selected */
	virtual FText GetBaseNodeTitle() const;
	/** Gets the node title when a class has been selected. */
	virtual FText GetNodeTitleFormat() const;
	/** Gets base class to use for the 'class' pin.  UObject by default. */
	virtual UClass* GetClassPinBaseClass() const;

	/**
	* Takes the specified "MutatablePin" and sets its 'PinToolTip' field (according
	* to the specified description)
	*
	* @param   MutatablePin	The pin you want to set tool-tip text on
	* @param   PinDescription	A string describing the pin's purpose
	*/
	void SetPinToolTip(UEdGraphPin& MutatablePin, const FText& PinDescription) const;

	/** Refresh pins when class was changed */
	void OnClassPinChanged();

	void OnBlueprintCompiled(UBlueprint*);

private:

	void BindBlueprintCompile();

	void ToogleShowClass();

	UEdGraphPin* CreateClassPin();

protected:

	struct ACTIONSEDITOR_API FHelper
	{
		struct FOutputPinAndLocalVariable
		{
			UEdGraphPin* OutputPin;
			UK2Node_TemporaryVariable* TempVar;

			FOutputPinAndLocalVariable(UEdGraphPin* Pin, UK2Node_TemporaryVariable* Var) : OutputPin(Pin), TempVar(Var) {}
		};

		static bool ValidDataPin(const UEdGraphPin* Pin, EEdGraphPinDirection Direction, const UEdGraphSchema_K2* Schema);

		static bool CreateDelegateForNewFunction(UEdGraphPin* DelegateInputPin, FName FunctionName, UK2Node* CurrentNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext);

		static bool CopyEventSignature(UK2Node_CustomEvent* CENode, UFunction* Function, const UEdGraphSchema_K2* Schema);

		static bool HandleDelegateImplementation(
			FMulticastDelegateProperty* CurrentProperty,
			UEdGraphPin* ProxyObjectPin, UEdGraphPin*& InOutLastThenPin,
			UK2Node* CurrentNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext);

		static bool HandleDelegateBindImplementation(
			FMulticastDelegateProperty* CurrentProperty,
			UEdGraphPin* ProxyObjectPin, UEdGraphPin*& InOutLastThenPin,
			UK2Node* CurrentNode, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext);
	};
};