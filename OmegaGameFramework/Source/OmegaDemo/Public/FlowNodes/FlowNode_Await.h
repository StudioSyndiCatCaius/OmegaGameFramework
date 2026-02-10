// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDemo_Const.h"
#include "Nodes/FlowNode.h"
//#include "FlowNode_Await.generated.h"


/*

// ==============================================================================================================
// -
// ==============================================================================================================

UCLASS(DisplayName="Await - Global Event",Category="Await")
class OMEGADEMO_API UFlowNode_AwaitGlobalEvent : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_AwaitGlobalEvent();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Await"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_AWAIT; return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Debug") FName EventName;
	
};

	
// ==============================================================================================================
// -
// ==============================================================================================================

// ==============================================================================================================
// -
// ==============================================================================================================

UCLASS(DisplayName="Await - Spawn At Point",Category="Await")
class OMEGADEMO_API UFlowNode_AwaitSpawn : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_AwaitSpawn();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Await"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=COLOR_DEMO_AWAIT; return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Debug") FName EventName;
	
};

	*/

