// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Save.generated.h"


class UOmegaModifier_Save;
class UOmegaSaveCondition;

UCLASS(DisplayName="💾Once Per Instance?",Category="Save")
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
	
	UPROPERTY(EditAnywhere,Category="Save") TEnumAsByte<EOmegaGlobalParamTarget> Target=SAVE_GAME;
};


UCLASS(DisplayName="💾 Save Tags - Edit",Category="Save")
class OMEGADEMO_API UFlowNode_TagsEdit : public UFlowNode
{
	GENERATED_BODY()


public:
	UFlowNode_TagsEdit();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Save"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Blue); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Save",meta=(Categories="SAVE,STORY")) FGameplayTagContainer TagsAdded;
	UPROPERTY(EditAnywhere,Category="Save",meta=(Categories="SAVE,STORY")) FGameplayTagContainer TagsRemoved;
	UPROPERTY(EditAnywhere,Category="Save") bool bGlobal;
};

UCLASS(DisplayName="💾 Save Tags - Check?",Category="Save")
class OMEGADEMO_API UFlowNode_TagsCheck : public UFlowNode
{
	GENERATED_BODY()


public:
	UFlowNode_TagsCheck();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Save"; };
	virtual bool GetDynamicTitleColor(FLinearColor& OutColor) const override{ OutColor=FLinearColor(FColor::Blue); return true;};
	
#endif

	UPROPERTY(EditAnywhere,Category="Save",meta=(Categories="SAVE,STORY")) FGameplayTagContainer HasTags;
	UPROPERTY(EditAnywhere,Category="Save") bool bExact=true;
	UPROPERTY(EditAnywhere,Category="Save") bool bGlobal;
};
