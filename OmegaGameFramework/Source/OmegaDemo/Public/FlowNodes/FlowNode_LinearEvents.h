// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLinearEventSubsystem.h"
#include "GameplayTags.h"
#include "Flow/Public/Nodes/FlowNode.h"
#include "UObject/Object.h"
#include "Utils/OmegaUtils_General.h"
#include "FlowNode_LinearEvents.generated.h"

	
UCLASS(DisplayName="Linear Events")
class OMEGADEMO_API UFlowNode_LinearEvents : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_LinearEvents();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
	
	UPROPERTY(EditAnywhere, Category="Events")
	FLinearEventSequence Events;

	UPROPERTY()
	UOmegaLinearEventInstance* LocalInst;

	UFUNCTION()
	void LocalFinish(const FString& Flag);
};

UCLASS(DisplayName="Edit Save Tags")
class OMEGADEMO_API UFlowNode_EditSaveTags : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_EditSaveTags();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
#endif
	
	UPROPERTY(EditInstanceOnly, Category="Event")
	FGameplayTagContainer Tags;
	UPROPERTY(EditInstanceOnly, Category="Event")
	EAddRemove Action;
	UPROPERTY(EditInstanceOnly, Category="Event")
	bool GlobalSave;
};
