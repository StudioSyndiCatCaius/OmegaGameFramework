// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Event/OmegaLinearEvent.h"
#include "UObject/Object.h"
#include "Utils/OmegaUtils_General.h"
#include "LinearEvent_EditSaveTags.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Event (Modify Save Tags)")
class OMEGADEMO_API ULinearEvent_EditSaveTags : public UOmegaLinearEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="Event")
	FGameplayTagContainer Tags;
	UPROPERTY(EditInstanceOnly, Category="Event")
	EAddRemove Action;
	UPROPERTY(EditInstanceOnly, Category="Event")
	bool GlobalSave;

	

	virtual void Native_Begin() override;
};
