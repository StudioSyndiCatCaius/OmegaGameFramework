// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "Save/OmegaSaveSubsystem.h"
#include "FlowNode_SaveCondition.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Save Condition Check")
class OMEGADEMO_API UFlowNode_SaveCondition : public UFlowNode
{
	GENERATED_BODY()

public:

	UFlowNode_SaveCondition();
	
	UPROPERTY(EditAnywhere, Category="Choice")
	FOmegaSaveConditions Conditions;

	virtual void ExecuteInput(const FName& PinName) override;
};
