// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "Engine/EngineTypes.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Hub.generated.h"

/**
 * A named node that you can reroute to from a "ToHub" node.
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "HUB"))
class FLOW_API UFlowNode_Hub : public UFlowNode
{
	GENERATED_UCLASS_BODY()

public:
	virtual void ExecuteInput(const FName& PinName) override;
	
	UPROPERTY(EditAnywhere, Category="Default")
	FName HubName;
	
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

/**
 * Reroutes to a named HUB node.
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "To HUB"))
class FLOW_API UFlowNode_ToHub : public UFlowNode
{
	GENERATED_UCLASS_BODY()

public:
	
	virtual void ExecuteInput(const FName& PinName) override;

	UPROPERTY(EditAnywhere, Category="Default")
	FName TargetHub;


#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
};

