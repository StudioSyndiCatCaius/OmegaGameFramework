// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Save.generated.h"


class UOmegaModifier_Save;
class UOmegaSaveCondition;

UCLASS(DisplayName="💾Save - Edit",Category="Save")
class OMEGADEMO_API UFlowNode_SaveEdit : public UFlowNode
{
	GENERATED_BODY()

public:
	//UFlowNode_SaveEdit();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Save"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Cyan); return true;};
	
#endif


	UPROPERTY(EditAnywhere,Instanced,Category="Save")
	TArray<UOmegaModifier_Save*> Modifiers;
	UPROPERTY(EditAnywhere,Category="Save")
	bool bGlobal;
};

	
UCLASS(DisplayName="💾Save - Condition?",Category="Save")
class OMEGADEMO_API UFlowNode_SaveCondition : public UFlowNode
{
	GENERATED_BODY()


public:
	UFlowNode_SaveCondition();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Save"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Red); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Instanced,Category="Save")
	TArray<UOmegaSaveCondition*> Conditions;
	UPROPERTY(EditAnywhere,Category="Save")
	bool bGlobal;
};

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
