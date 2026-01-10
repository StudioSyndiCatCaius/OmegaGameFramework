// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "Nodes/FlowNode.h"
#include "FlowNode_LocalParam.generated.h"


static const FLinearColor col_node=FLinearColor(FColor::Cyan); 

UCLASS(NotBlueprintable, meta = (DisplayName = "🏠Local Param - CHECK"))
class FLOW_API UFlowNode_LocalParam_Check final : public UFlowNode
{
	GENERATED_BODY()
	
	UFUNCTION() TArray<FName> get_local_params();
	
public:
	UFlowNode_LocalParam_Check();
	virtual void ExecuteInput(const FName& PinName) override;
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Local"; };
	virtual FString GetNodeDescription() const override;
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override { OutColor=col_node; return true;}
#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param",meta=(GetOptions="get_local_params"))
	FName Param;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param")
	int32 CheckedValue=1;
};


UCLASS(NotBlueprintable, meta = (DisplayName = "🏠Local Param - IF"))
class FLOW_API UFlowNode_LocalParam_If final : public UFlowNode
{
	GENERATED_BODY()
	
	UFUNCTION() TArray<FName> get_local_params();
public:
	UFlowNode_LocalParam_If();
	virtual void ExecuteInput(const FName& PinName) override;
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Local"; };
	virtual FString GetNodeDescription() const override;
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override { OutColor=col_node; return true;}
#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param",meta=(GetOptions="get_local_params"))
	FName Param;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param")
	int32 CheckedValue=1;
};

UCLASS(NotBlueprintable, meta = (DisplayName = "🏠Local Param - SET"))
class FLOW_API UFlowNode_LocalParam_Set final : public UFlowNode
{
	GENERATED_BODY()
	UFUNCTION() TArray<FName> get_local_params();
public:
	UFlowNode_LocalParam_Set();
	virtual void ExecuteInput(const FName& PinName) override;
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Local"; };
	virtual FString GetNodeDescription() const override;
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override { OutColor=col_node; return true;}
#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param",meta=(GetOptions="get_local_params"))
	FName Param;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param")
	int32 Value=1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Local Param")
	bool bAdded;
};
