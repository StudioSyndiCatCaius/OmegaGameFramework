// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventSequenceNode.h"
#include "Engine/DataAsset.h"
#include "EventSequence.generated.h"

/**
 * 
 */
UCLASS()
class OMEGAGAMEFRAMEWORK_API UEventSequence : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EventSequence")
	TArray<FName> EventsOnBegin;
	
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, Category = "EventSequence")
	TArray<UEventSequenceNode*> SequenceNodes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EventSequence")
	TArray<FName> EventsOnEnd;
};
