// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInterface_General.h"
#include "UObject/Object.h"
#include "OmegaLinearChoice.generated.h"

class UWorld;
class UOmegaLinearEventSubsystem;

UCLASS(BlueprintType, Blueprintable, Const, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGASEQUENCE_API UOmegaLinearChoice : public UObject, public IDataInterface_General
{
	GENERATED_BODY()

public:

	UOmegaLinearChoice(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;

	UPROPERTY()
	UWorld* WorldPrivate = nullptr;
	UPROPERTY()
	UGameInstance* GameInstanceRef = nullptr;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	UPROPERTY()
	UOmegaLinearEventSubsystem* SubsystemRef;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Choice")
	bool IsChoiceAvailable() const;
	
};
