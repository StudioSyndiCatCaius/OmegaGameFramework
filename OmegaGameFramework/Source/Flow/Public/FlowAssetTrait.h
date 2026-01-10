// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FlowAssetTrait.generated.h"

class UFlowNode;
class UFlowAsset;
class UWorld;
class UGameInstance;

UCLASS(Blueprintable, BlueprintType, Abstract, EditInlineNew,meta=(ShowWorldContextPin), const)
class FLOW_API UFlowAssetTrait : public UObject
{
	GENERATED_BODY()

public:
	
	
	void Native_FlowBegin(UFlowAsset* FlowInstance) const;
	void Native_FlowEnd(UFlowAsset* FlowInstance, FName Output, const FString& Flag) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Trait")
	void FlowBegin(UFlowAsset* FlowInstance) const; 
	UFUNCTION(BlueprintImplementableEvent, Category="Trait")
	void FlowEnd(UFlowAsset* FlowInstance,FName Output, const FString& Flag) const;
	UFUNCTION(BlueprintImplementableEvent, Category="Trait", DisplayName="On Flow Signal")
	void FlowNotified(UFlowAsset* FlowInstance,FName Notify, UObject* Context) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Trait")
	void NodeInput(UFlowNode* FlowNode,FName Pin) const;
	UFUNCTION(BlueprintImplementableEvent, Category="Trait")
	void NodeOutput(UFlowNode* FlowNode,FName Pin) const;
};

UCLASS()
class FLOW_API UFlowAssetTrait_Collection : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Misc")
	TArray<UFlowAssetTrait*> Traits;
};