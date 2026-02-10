// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Event/OmegaLinearEvent.h"
#include "GameplayTags.h"
#include "UObject/Object.h"
#include "Interfaces/I_Common.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_LinearEvents.generated.h"

	
UCLASS(DisplayName="➡️Linear Events")
class OMEGADEMO_API UFlowNode_LinearEvents : public UFlowNode, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	UFlowNode_LinearEvents();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Gameplay"; };
#endif

	UPROPERTY(EditAnywhere,Category="General") FText NodeName;
	UPROPERTY(EditAnywhere,Category="General",meta=(MultiLine)) FText NodeDescription;
	UPROPERTY(EditAnywhere,Category="General") FGameplayTag CategoryTag;
	UPROPERTY(EditAnywhere,Category="General") FGameplayTagContainer GameplayTags;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() override {return CategoryTag;};
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override {return GameplayTags;};
	
	UPROPERTY(EditAnywhere, Category="Events")
	FLinearEventSequence Events;

	UPROPERTY(EditAnywhere,Category="Reader")
	FOmegaLinearEventReaderData ReaderData;
	//Will still import and use the reader LinearEvent data, event it it has 0 events.
	UPROPERTY(EditAnywhere,Category="Reader")
	bool StillImportIfEmpty;

	UFUNCTION(CallInEditor,Category="Reader")
	void ImportReaderEvents();
	
	UPROPERTY()
	UOmegaLinearEventInstance* LocalInst;

	UFUNCTION()
	void LocalFinish(const FString& Flag,UOmegaLinearEventInstance* Instance=nullptr);
};

