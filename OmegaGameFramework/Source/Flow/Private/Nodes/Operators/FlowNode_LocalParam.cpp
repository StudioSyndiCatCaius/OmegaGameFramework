// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Nodes/Operators/FlowNode_LocalParam.h"

#include "FlowAsset.h"

UFlowNode_LocalParam_Check::UFlowNode_LocalParam_Check()
{
	InputPins.Empty();
	OutputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));

	OutputPins.Add(FFlowPin(TEXT(">")));
	OutputPins.Add(FFlowPin(TEXT("=")));
	OutputPins.Add(FFlowPin(TEXT("<")));
	
}

void UFlowNode_LocalParam_Check::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if(GetFlowAsset()->GetLocalParam_Int(Param)>CheckedValue)
	{
		TriggerOutput(TEXT(">"));
	}
	else if(GetFlowAsset()->GetLocalParam_Int(Param)==CheckedValue)
	{
		TriggerOutput(TEXT("="));	
	}
	else
	{
		TriggerOutput(TEXT("<"));	
	}
}

#if WITH_EDITOR
FString UFlowNode_LocalParam_Check::GetNodeDescription() const
{
	return "if '"+Param.ToString()+" ?? "+FString::FromInt(CheckedValue);
}
#endif

UFlowNode_LocalParam_If::UFlowNode_LocalParam_If()
{
	InputPins.Empty();
	OutputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	
	OutputPins.Add(FFlowPin(TEXT("true")));
	OutputPins.Add(FFlowPin(TEXT("false")));
}

void UFlowNode_LocalParam_If::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	if(GetFlowAsset()->GetLocalParam_Int(Param)==CheckedValue)
	{
		TriggerOutput(TEXT("true"));
	}
	else
	{
		TriggerOutput(TEXT("false"));	
	}
}

#if WITH_EDITOR
FString UFlowNode_LocalParam_If::GetNodeDescription() const
{
	return "if '"+Param.ToString()+" == "+FString::FromInt(CheckedValue);
}
#endif

UFlowNode_LocalParam_Set::UFlowNode_LocalParam_Set()
{
	InputPins.Empty();
	OutputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
	OutputPins.Add(FFlowPin(TEXT("Out")));
}

void UFlowNode_LocalParam_Set::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	GetFlowAsset()->SetLocalParam_Int(Param,Value,bAdded);
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_LocalParam_Set::GetNodeDescription() const
{
	FString oper="=";
	if(bAdded) { oper="+=";}
	return "Set '"+Param.ToString()+oper+FString::FromInt(Value);
}
#endif