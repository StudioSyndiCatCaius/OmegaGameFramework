// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "Choice/OmegaLinearChoice.h"
#include "Functions/F_GlobalScripting.h"
#include "Subsystems/Subsystem_Save.h"
#include "UObject/Object.h"
#include "LinearChoice_SimpleChoice.generated.h"


UCLASS(DisplayName="(🔀Choice) Common")
class OMEGADEMO_API ULinearChoice_SimpleChoice : public UOmegaLinearChoice
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice", meta=(MultiLine))
	FText ChoiceText;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice")
	FGameplayTagContainer Tags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice")
	FOmegaBitflagsBase Flags;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice",meta=(ShowOnlyInnerProperties))
	FGameplayTagQuery SaveTagsQuery;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Choice",meta=(ShowOnlyInnerProperties))
	FOmegaGlobalConditions Conditions;
	virtual void GetGeneralDataText_Implementation(FGameplayTag Tag, FText& Name, FText& Description, FSlateBrush& iconBrush, FLinearColor& Color, FString& Label, FOmegaObjectGeneralMetaconfig& MetaConfig) override
	{
		Name=ChoiceText;
	};
	virtual bool IsChoiceAvailable_Implementation() const override;
	virtual void GetObjectGameplayTags_Implementation(FGameplayTag& OutCategoryTag, FGameplayTagContainer& OutGameplayTags) override { OutGameplayTags=Tags; };
};
