// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "Nodes/FlowNode.h"
#include "FlowNode_LogicalAND.generated.h"

/**
 * Logical AND
 * Output will be triggered only once
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "AND"))
class FLOW_API UFlowNode_LogicalAND final : public UFlowNode
{
	GENERATED_UCLASS_BODY()

private:
	UPROPERTY(SaveGame)
	TArray<FName> ExecutedInputNames;
	
#if WITH_EDITOR
public:
	virtual FText GetNodeTitle() const override;
	virtual bool CanUserAddInput() const override { return true; }
#endif

protected:
	virtual void ExecuteInput(const FName& PinName) override;
	virtual void Cleanup() override;
	
public:
	
	UPROPERTY(EditAnywhere, Category = "Defaults")
	bool bSaved;
};
