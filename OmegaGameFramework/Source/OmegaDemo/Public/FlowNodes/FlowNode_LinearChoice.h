// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Choice/OmegaLinearChoiceInstance.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_LinearChoice.generated.h"


UCLASS(DisplayName="🗣️Choice")
class OMEGADEMO_API UFlowNode_LinearChoice : public UFlowNode
{
	GENERATED_BODY()

	UPROPERTY() TArray<UFlowNode_LinkedChoice*> cached_linkNodes; 
	UFlowNode_LinkedChoice* GetLinkedChoice_ByID(FName ID);
	
public:
	
	UFlowNode_LinearChoice();
	
	UFUNCTION() TArray<FName> L_LinkedNodes();
	
	UPROPERTY(EditAnywhere, Category="Choice",meta=(ShowOnlyInnerProperties))
	FOmegaLinearChoices Choices;
	UPROPERTY(EditAnywhere, Category="Choice")
	TSubclassOf<AOmegaLinearChoiceInstance> InstanceClass;
	UPROPERTY(EditAnywhere, Category="Choice")
	FGameplayTag SaveParamToSet;
	UPROPERTY(EditAnywhere, Category="Choice")
	FName LocalParamToSet;
	
	UPROPERTY(EditAnywhere, Category="Choice",DisplayName="🔀 Linked Choice Nodes",meta=(GetOptions="L_LinkedNodes"))
	TArray<FName> LinkedChoiceNodes;
	
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

	virtual void PostLoad() override;
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

private:
	void SubscribeToAssetChanges();
#endif
	
};


UCLASS(DisplayName="🔀Linked Choice")
class OMEGADEMO_API UFlowNode_LinkedChoice : public UFlowNode
{
	GENERATED_BODY()

public:
	
	UFlowNode_LinkedChoice();
	
	UPROPERTY(BlueprintReadOnly, Category="LinearEvents", EditAnywhere) FName LinkID;
	UPROPERTY(BlueprintReadOnly, Category="LinearEvents", instanced, EditAnywhere) UOmegaLinearChoice* Choice;
	
	virtual void ExecuteInput(const FName& PinName) override;
#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override { OutColor=FLinearColor::Green; return true;};
#endif
};