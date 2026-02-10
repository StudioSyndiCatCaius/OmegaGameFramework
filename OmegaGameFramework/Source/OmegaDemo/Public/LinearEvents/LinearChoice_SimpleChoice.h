// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "Choice/OmegaLinearChoice.h"
#include "Subsystems/Subsystem_Save.h"
#include "UObject/Object.h"
#include "LinearChoice_SimpleChoice.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Choice | Simple")
class OMEGADEMO_API ULinearChoice_SimpleChoice : public UOmegaLinearChoice, public IGameplayTagsInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice", meta=(MultiLine))
	FText ChoiceText;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice")
	FOmegaSaveConditions Conditions;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice")
	FGameplayTagContainer Tags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice")
	FOmegaBitflagsBase Flags;
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual bool IsChoiceAvailable_Implementation() const override;
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() override {return Tags;};
};
