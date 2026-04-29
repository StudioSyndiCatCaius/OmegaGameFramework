// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_GlobalScripting.h"

#include "Kismet/KismetStringLibrary.h"

UFlowNode_GlobalScript::UFlowNode_GlobalScript()
{
}

void UFlowNode_GlobalScript::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	UOmegaFunctions_GlobalScripting::RunGlobalScripts(this,scripts);
	TriggerFirstOutput(true);
}

FString UFlowNode_GlobalScript::GetNodeDescription() const
{
	TArray<FString> out;
	for (UOmegaGlobalScriptBASE* b : scripts.Scripts)
	{
		if (b)
		{
			out.Add(b->GetFunctionCall_Description());
		}
	}
	return UKismetStringLibrary::JoinStringArray(out,"\n");
}

UFlowNode_GlobalCondition::UFlowNode_GlobalCondition()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("true")));
	OutputPins.Add(FFlowPin(TEXT("false")));
}

void UFlowNode_GlobalCondition::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	
	if (UOmegaFunctions_GlobalScripting::RunGlobalConditions(this,conditions))
	{
		TriggerOutput(TEXT("true"),true);
	}
	else
	{
		TriggerOutput(TEXT("false"),true);
	}
}

FString UFlowNode_GlobalCondition::GetNodeDescription() const
{
	TArray<FString> out;
	for (UOmegaGlobalScriptBASE* b : conditions.Conditions)
	{
		if (b)
		{
			out.Add(b->GetFunctionCall_Description());
		}
	}
	return UKismetStringLibrary::JoinStringArray(out,"\n");
}
