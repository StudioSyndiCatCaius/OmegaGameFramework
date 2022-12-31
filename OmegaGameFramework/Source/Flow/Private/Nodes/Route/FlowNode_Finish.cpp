// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Nodes/Route/FlowNode_Finish.h"

#include "FlowSubsystem.h"

UFlowNode_Finish::UFlowNode_Finish(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Route");
	NodeStyle = EFlowNodeStyle::InOut;
#endif

	OutputPins = {};
}

void UFlowNode_Finish::ExecuteInput(const FName& PinName)
{
	// this will call FinishFlow()
	GetFlowSubsystem()->Native_EndFlow(GetFlowAsset(), "Finish",FinishFlag);
	Finish();
}
