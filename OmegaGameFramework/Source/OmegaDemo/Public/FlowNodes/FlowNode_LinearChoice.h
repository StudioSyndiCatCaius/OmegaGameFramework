// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Choice/OmegaLinearChoiceInstance.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_LinearChoice.generated.h"

/**
 * 
 */
UCLASS(DisplayName="LinearChoice")
class OMEGADEMO_API UFlowNode_LinearChoice : public UFlowNode
{
	GENERATED_BODY()

public:

	UFlowNode_LinearChoice();
	
	UPROPERTY(EditAnywhere, Category="Choice")
	FOmegaLinearChoices Choices;
	UPROPERTY(EditAnywhere, Category="Choice")
	TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass = AOmegaLinearChoiceInstance::StaticClass();

	UPROPERTY()
	AOmegaLinearChoiceInstance* ChoiceInst;
	UFUNCTION()
	void LocalChoiceSelect(UOmegaLinearChoice* Choice, int32 Index);

#if WITH_EDITOR
	virtual bool CanUserAddOutput() const override;
#endif
	
	virtual void ExecuteInput(const FName& PinName) override;
};
