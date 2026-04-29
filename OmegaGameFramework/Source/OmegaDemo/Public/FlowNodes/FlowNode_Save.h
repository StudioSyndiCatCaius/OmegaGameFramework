// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Save.generated.h"


class UOmegaModifier_Save;
class UOmegaSaveCondition;

UCLASS(DisplayName="💾Once Per Save?",Category="Save")
class OMEGADEMO_API UFlowNode_SaveOnce : public UFlowNode
{
	GENERATED_BODY()


public:
	UFlowNode_SaveOnce();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Save"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Red); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Save")
	FName SaveParam;
	UPROPERTY(EditAnywhere,Category="Save")
	bool bGlobal;
};
