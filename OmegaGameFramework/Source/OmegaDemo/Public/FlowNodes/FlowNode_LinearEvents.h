// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaLinearEventSubsystem.h"
#include "GameplayTags.h"
#include "Flow/Public/Nodes/FlowNode.h"
#include "UObject/Object.h"
#include "Misc/OmegaUtils_Enums.h"
#include "FlowNode_LinearEvents.generated.h"

	
UCLASS(DisplayName="Linear Events")
class OMEGADEMO_API UFlowNode_LinearEvents : public UFlowNode, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	UFlowNode_LinearEvents();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif

	UPROPERTY(EditAnywhere,Category="General") FText NodeName;
	UPROPERTY(EditAnywhere,Category="General",meta=(MultiLine)) FText NodeDescription;
	UPROPERTY(EditAnywhere,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,Category="General") FGameplayTagContainer GameplayTags;

#if WITH_EDITOR
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
#endif
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override {return CategoryTag;};
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override {return GameplayTags;};
	
	UPROPERTY(EditAnywhere, Category="Events")
	FLinearEventSequence Events;

	UPROPERTY()
	UOmegaLinearEventInstance* LocalInst;

	UFUNCTION()
	void LocalFinish(const FString& Flag,UOmegaLinearEventInstance* Instance=nullptr);
};

UCLASS(DisplayName="Edit Save Tags",meta=(DeprecatedNode))
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
