// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OmegaLinearChoice.h"
#include "OmegaLinearChoiceInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChoiceSelected, UOmegaLinearChoice*, Choice, int32, SelectedChoice);

USTRUCT(BlueprintType)
struct FOmegaLinearChoices
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="LinearEvents", instanced, EditAnywhere)
	TArray<class UOmegaLinearChoice*> Choices;
	
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGASEQUENCE_API AOmegaLinearChoiceInstance : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOmegaLinearChoices ChoiceData;
	
	UPROPERTY(BlueprintAssignable)
	FOnChoiceSelected OnChoiceSelected;
	
	UFUNCTION(BlueprintCallable, Category="LinearChoice")
	bool SelectChoice(int32 Index);

	UFUNCTION(BlueprintPure, Category="LinearChoice")
	TArray<UOmegaLinearChoice*> GetChoices();
};
