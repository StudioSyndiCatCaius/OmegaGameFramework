// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "Nodes/FlowNode.h"
#include "FlowNode_Bindings.generated.h"

class UOmegaActorSelector;

UCLASS(NotBlueprintable, meta = (DisplayName = "Bindings"))
class FLOW_API UFlowNode_Bindings : public UFlowNode
{
	GENERATED_UCLASS_BODY()
	
private:
	UPROPERTY(EditAnywhere,Instanced, Category = "Flow")
	TMap<UPrimaryDataAsset*,UOmegaActorSelector*> NewBindings_ByAsset;
	UPROPERTY(EditAnywhere,Instanced, Category = "Flow")
	TMap<FName,UOmegaActorSelector*> NewBindings_ByName;

protected:
	virtual void ExecuteInput(const FName& PinName) override;

};
