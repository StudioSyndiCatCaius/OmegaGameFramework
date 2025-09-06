// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Debug.generated.h"


class UOmegaModifier_Save;
class UOmegaSaveCondition;

//
UCLASS(DisplayName="Debug - In Debug Mode?",Category="Debug")
class OMEGADEMO_API UFlowNode_DebugModeCheck : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_DebugModeCheck();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Debug"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Cyan); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Debug") bool InDebugMode;
	
};

	