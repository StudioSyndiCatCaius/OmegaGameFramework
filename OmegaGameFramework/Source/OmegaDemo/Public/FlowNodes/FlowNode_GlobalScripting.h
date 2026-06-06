// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "Functions/F_GlobalScripting.h"
#include "FlowNode_GlobalScripting.generated.h"


class UOmegaModifier_Save;
class UOmegaSaveCondition;

//
UCLASS(DisplayName="➕RUN Global Script",Category="Gameplay")
class OMEGADEMO_API UFlowNode_GlobalScript : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_GlobalScript();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Cyan); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Scripting",meta=(ShowOnlyInnerProperties)) FOmegaGlobalScripts scripts;
	
};

UCLASS(DisplayName="❓RUN Global Condition",Category="Gameplay")
class OMEGADEMO_API UFlowNode_GlobalCondition : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_GlobalCondition();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Cyan); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Scripting", meta=(ShowOnlyInnerProperties)) FOmegaGlobalConditions conditions;
	
};

	