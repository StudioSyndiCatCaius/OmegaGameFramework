// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowAsset.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_StartFlowAsset.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFlowTaskFinish, FName, Node, FString, Flag);

UCLASS()
class OMEGAFLOW_API UAsyncAction_StartFlowAsset : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnFlowTaskFinish OnFinish;

	UPROPERTY() const UObject* LocalWorldContext;
	UPROPERTY() FFlowAssetOverrideData Local_StartNode;
	UPROPERTY() bool Local_OverrideStart;
	UPROPERTY() FName Local_Input;
	UPROPERTY() bool Local_MultiInst;
	UPROPERTY() UFlowAsset* Local_FlowAsset;

	UFUNCTION()
	void Native_OnFinishFlow(UFlowAsset* FlowAsset, FName Output, const FString& Flag);
	
	virtual void Activate() override;
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|AsyncGameplayTasks", meta = (WorldContext = "WorldContextObject",
		AdvancedDisplay="bOverrideStartingNode,NewStartingNode,Input,AllowMultipleInstances"),DisplayName="Ω🔷 Start Flow Asset") 
	static UAsyncAction_StartFlowAsset* StartFlowAsset(UObject* WorldContextObject, UFlowAsset* Asset, FFlowAssetOverrideData OverrideData, FName Input, bool AllowMultipleInstances);
	
};
