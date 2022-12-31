// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaSaveSubsystem.h"
#include "UObject/Object.h"
#include "OmegaSaveCondition.generated.h"



UCLASS(BlueprintType, Blueprintable, Const, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSaveCondition : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category="OmegaSaveCondition")
	bool CheckSaveCondition(UOmegaSaveSubsystem* SaveSubsystem) const;
};
