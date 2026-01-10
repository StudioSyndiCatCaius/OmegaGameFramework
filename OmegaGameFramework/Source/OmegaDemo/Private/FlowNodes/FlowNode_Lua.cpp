// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowNodes/FlowNode_Lua.h"

#include "LuaBlueprintFunctionLibrary.h"

void UFlowNode_LuaCall::FixCodeString()
{
	if (!Code.IsEmpty() && Script.LuaCode.IsEmpty())
	{
		Script.LuaCode=Code;
		Code="";
	}
}

UFlowNode_LuaCall::UFlowNode_LuaCall()
{
}

void UFlowNode_LuaCall::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	ULuaBlueprintFunctionLibrary::LuaRunString(this,State,Script.LuaCode);
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
void UFlowNode_LuaCall::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	FixCodeString();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UFlowNode_LuaCall::PostLoad()
{
	Super::PostLoad();
	FixCodeString();
}

void UFlowNode_LuaIf::PostLoad()
{
	Super::PostLoad();
	if (!Code.IsEmpty() && Condition.LuaCode.IsEmpty())
	{
		Condition.LuaCode=Code;
		Code="";
	}
}

#endif



UFlowNode_LuaIf::UFlowNode_LuaIf()
{
	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("true")));
	OutputPins.Add(FFlowPin(TEXT("false")));
}

void UFlowNode_LuaIf::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	FLuaValue out=ULuaBlueprintFunctionLibrary::LuaRunString(this,State,Condition.LuaCode);
	if(out.ToBool())
	{
		TriggerOutput(TEXT("false"),true);
	}
	else
	{
		TriggerOutput(TEXT("false"),true);
	}
}

