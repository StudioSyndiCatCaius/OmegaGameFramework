// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Nodes/Utils/FlowNode_Bindings.h"

#include "FlowAsset.h"
#include "FlowModule.h"

#include "Engine/Engine.h"

UFlowNode_Bindings::UFlowNode_Bindings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Utils");
#endif
}

void UFlowNode_Bindings::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);
	TArray<UPrimaryDataAsset*> keys_a;
	NewBindings_ByAsset.GetKeys(keys_a);
	for(auto* a : keys_a)
	{
		if(a && NewBindings_ByAsset[a])
		{
			GetFlowAsset()->ActorBindings_ByAsset.Add(a,NewBindings_ByAsset[a]);
		}
	}
	TArray<FName> keys_N;
	NewBindings_ByName.GetKeys(keys_N);
	for(FName a : keys_N)
	{
		if(NewBindings_ByName[a])
		{
			GetFlowAsset()->ActorBindings_ByName.Add(a,NewBindings_ByName[a]);
		}
	}
	TriggerFirstOutput(true);
}
