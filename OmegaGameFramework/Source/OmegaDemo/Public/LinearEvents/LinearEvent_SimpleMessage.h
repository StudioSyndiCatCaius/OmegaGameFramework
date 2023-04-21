// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "GameplayTagContainer.h"
#include "Event/OmegaLinearEvent.h"
#include "Nodes/FlowNode.h"
#include "LinearEvent_SimpleMessage.generated.h"

class UOmegaDataItem;

// Fires the GlobalEvent "SimpleMessage" with this event as the context. Uses GetGeneralDataTexts to get event text. Finishes on GlobalEvent "EndMessage";
UCLASS(DisplayName="Event | Simple Message")
class OMEGADEMO_API ULinearEvent_SimpleMessage : public UOmegaLinearEvent, public IDataInterface_General
{
	GENERATED_BODY()

public:
	virtual FString GetLogString_Implementation() const override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(ExposeOnSpawn="true"))
	UOmegaDataItem* Instigator;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(MultiLine, ExposeOnSpawn="true"))
	FText Message;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(MultiLine, ExposeOnSpawn="true"))
	FGameplayTagContainer Tags;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void Native_Begin() override;

	UFUNCTION()
	void LocalGEvent(FName Event, UObject* Context);
};

UCLASS(DisplayName="Gameplay Message")
class OMEGADEMO_API UFlowNode_SimpleMessage : public UFlowNode
{
	GENERATED_BODY()

public:
	UFlowNode_SimpleMessage();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	UOmegaDataItem* Instigator;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FText Message;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTagContainer Tags;
	
	UFUNCTION()
	void LocalFinish(const FString& Flag);
};

