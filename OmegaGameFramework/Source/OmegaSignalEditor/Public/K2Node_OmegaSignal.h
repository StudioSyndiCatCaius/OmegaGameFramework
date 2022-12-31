// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaSignalAsset.h"
#include "K2Node_Event.h"
#include "Engine/DynamicBlueprintBinding.h"
#include "K2Node_OmegaSignal.generated.h"



UCLASS()
class OMEGASIGNALEDITOR_API UK2Node_OmegaSignal : public UK2Node_Event
{
	GENERATED_BODY()

	UPROPERTY()
	const UOmegaSignalAsset* SignalAsset;
	FName Local_GetEventName() const;
	FNodeTextCache CachedNodeTitle;
	
	//~ Begin UEdGraphNode Interface.
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual bool IsCompatibleWithGraph(UEdGraph const* Graph) const override;


	//~ End UEdGraphNode Interface.

	
	//~ Begin UK2Node Interface
	//			virtual UClass* GetDynamicBindingClass() const override;
	//			virtual void RegisterDynamicBinding(UDynamicBlueprintBinding* BindingObject) const override;

	virtual void ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	virtual FBlueprintNodeSignature GetSignature() const override;
	virtual void PostReconstructNode() override;
	
	//~ End UK2Node Interface
	virtual void AllocateDefaultPins() override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	UEdGraphPin* GetThenPin() const;

	//~ Begin UK2Node Interface

	//~ End UK2Node Interface
};

