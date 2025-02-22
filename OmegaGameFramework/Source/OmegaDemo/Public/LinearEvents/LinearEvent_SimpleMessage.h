// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Event/OmegaLinearEvent.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "Styling/SlateBrush.h"
#include "UObject/Object.h"
#include "LinearEvent_SimpleMessage.generated.h"

class UOmegaDataItem;

// Fires the GlobalEvent "SimpleMessage" with this event as the context. Uses GetGeneralDataTexts to get event text. Finishes on GlobalEvent "EndMessage";
UCLASS(DisplayName="Event | Simple Message")
class OMEGADEMO_API ULinearEvent_SimpleMessage : public UOmegaLinearEvent, public IDataInterface_General
{
	GENERATED_BODY()
	
	UObject* local_GetInstigator() const;
	
public:
	virtual FString GetLogString_Implementation() const override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(ExposeOnSpawn="true"),DisplayName="Instigator (Asset)")
	UPrimaryDataAsset* Instigator_Asset;
	UPROPERTY(Instanced, EditInstanceOnly, BlueprintReadOnly, Category="Event",DisplayName="Instigator (Actor)")
	UOmegaActorSelector* Instigator_Actor;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Event", meta=(MultiLine, ExposeOnSpawn="true"))
	FText Message;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message",meta=(MultiLine))
	FSlateBrush Brush;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTag MessageCategory  = FGameplayTag::RequestGameplayTag(FName("Message.Event"));
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTagContainer Tags;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void Native_Begin(const FString& Flag) override;

	UFUNCTION()
	void LocalGEvent(FName Event, UObject* Context);
};

UCLASS(DisplayName="Simple Message")
class OMEGADEMO_API UFlowNode_SimpleMessage : public UFlowNode, public IDataInterface_General
{
	GENERATED_BODY()

	UObject* local_GetInstigator() const;
	
public:
	UFlowNode_SimpleMessage();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	virtual FString GetNodeDescription() const override;
#endif
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message", meta=(ExposeOnSpawn="true"),DisplayName="Instigator (Asset)")
	UPrimaryDataAsset* Instigator_Asset;
	UPROPERTY(Instanced, EditInstanceOnly, BlueprintReadOnly, Category="Message",DisplayName="Instigator (Actor)")
	UOmegaActorSelector* Instigator_Actor;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message",meta=(MultiLine))
	FText Message;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message",meta=(MultiLine))
	FSlateBrush Brush;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTag MessageCategory  = FGameplayTag::RequestGameplayTag(FName("Message.Event"));
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message")
	FGameplayTagContainer Tags;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Message",AdvancedDisplay)
	FString MessageLabel;

	virtual void GetGeneralAssetLabel_Implementation(FString& Label) override;
	
	UFUNCTION()
	void LocalFinish(UOmegaLinearEvent* Event, const FString& Flag);
};
