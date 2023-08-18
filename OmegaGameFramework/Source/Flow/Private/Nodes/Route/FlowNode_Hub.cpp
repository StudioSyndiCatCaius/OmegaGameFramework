// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Nodes\Route\FlowNode_Hub.h"

#include "FlowAsset.h"
#include "Engine/World.h"

UFlowNode_Hub::UFlowNode_Hub(const FObjectInitializer& ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Route");
	NodeStyle = EFlowNodeStyle::InOut;
#endif
	InputPins.Empty();

	OutputPins.Empty();
	OutputPins.Add(FFlowPin(TEXT("Out")));
}


void UFlowNode_Hub::ExecuteInput(const FName& PinName)
{
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_Hub::GetNodeDescription() const
{
	return HubName.ToString();
}
#endif

UFlowNode_ToHub::UFlowNode_ToHub(const FObjectInitializer& ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Route");
	NodeStyle = EFlowNodeStyle::InOut;
#endif
	OutputPins.Empty();
	
	InputPins.Empty();
	InputPins.Add(FFlowPin(TEXT("In")));
}

void UFlowNode_ToHub::ExecuteInput(const FName& PinName)
{
	for(auto* TempNode : GetFlowAsset()->GetAllNodes())
	{
		if(TempNode->GetClass()->IsChildOf(UFlowNode_Hub::StaticClass()) && Cast<UFlowNode_Hub>(TempNode)->HubName==TargetHub)
		{
			TempNode->TriggerInput("In", EFlowPinActivationType::Forced);
			Finish();
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("Failed to find Hub."));
	}
}

#if WITH_EDITOR
FString UFlowNode_ToHub::GetNodeDescription() const
{
	return TargetHub.ToString();
}
#endif
