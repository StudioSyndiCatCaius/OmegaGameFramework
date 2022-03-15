// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventSequenceNode.generated.h"

class UGameInstance;
class UWorld;

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UEventSequenceNode : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UWorld* WorldPrivate = nullptr;

public:
	UEventSequenceNode(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;

	//Functions
	UFUNCTION(BlueprintImplementableEvent, Category = "EventSequence|Node")
	void OnEventBegin();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "EventSequence|Node")
	void OnEventFinished();

	UFUNCTION(BlueprintCallable, Category = "EventSequence|Node")
	void FinishEvent();
	
};
