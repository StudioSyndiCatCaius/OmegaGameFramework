// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "Choice/OmegaLinearChoice.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "UObject/Object.h"
#include "LinearChoice_SimpleChoice.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Choice | Simple")
class OMEGADEMO_API ULinearChoice_SimpleChoice : public UOmegaLinearChoice
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditInstanceOnly, Category="Choice", meta=(MultiLine))
	FText ChoiceText;
	UPROPERTY(EditInstanceOnly, Category="Choice")
	FOmegaSaveConditions Conditions;
	
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual bool IsChoiceAvailable_Implementation() const override;
};
