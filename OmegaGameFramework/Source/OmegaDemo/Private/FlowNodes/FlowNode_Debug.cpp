// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Debug.h"

#include "Misc/OmegaUtils_Methods.h"

UFlowNode_DebugModeCheck::UFlowNode_DebugModeCheck()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Release")));
	OutputPins.Add(FFlowPin(TEXT("Debug")));
}

void UFlowNode_DebugModeCheck::ExecuteInput(const FName& PinName)
{
	
	//if(!InDebugMode || OGF_Build::IsBuild_Shipping())
	if(!InDebugMode)
	{
		TriggerOutput(TEXT("Release"),true);
	}
	else
	{
		TriggerOutput(TEXT("Debug"),true);
	}
	Super::ExecuteInput(PinName);
}
