// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Choice/OmegaLinearChoiceInstance.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_LinearChoice.generated.h"

/**
 * 
 */
UCLASS(DisplayName="🗣️Choice")
class OMEGADEMO_API UFlowNode_LinearChoice : public UFlowNode
{
	GENERATED_BODY()

public:
	
	UFlowNode_LinearChoice();
	
	UPROPERTY(EditAnywhere, Category="Choice")
	FOmegaLinearChoices Choices;
	UPROPERTY(EditAnywhere, Category="Choice")
	TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass;
	UPROPERTY(EditAnywhere, Category="Choice")
	FGameplayTag SaveParamToSet;
	UPROPERTY(EditAnywhere, Category="Choice")
	FName LocalParamToSet;
	
	UPROPERTY()
	AOmegaLinearChoiceInstance* ChoiceInst;
	UFUNCTION()
	void LocalChoiceSelect(UOmegaLinearChoice* Choice, int32 Index);
	
	virtual void ExecuteInput(const FName& PinName) override;
#if WITH_EDITOR
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override { OutColor=FLinearColor::Green; return true;};
	
	virtual bool SupportsContextPins() const override { return true; }
	virtual TArray<FName> GetContextOutputs() override;
	
	// UObject
	virtual void PostLoad() override;
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	// --

private:
	void SubscribeToAssetChanges();
#endif
	
};
