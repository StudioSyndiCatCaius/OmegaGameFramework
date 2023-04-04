// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaSaveSubsystem.h"
#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "OmegaSaveCondition.generated.h"

class UGameInstance;
class UWorld;

UCLASS(BlueprintType, Blueprintable, Const, abstract, editinlinenew, hidecategories=Object, CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaSaveCondition : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(Transient)
	mutable UWorld* WorldPrivate = nullptr;
	
	UOmegaSaveCondition(const FObjectInitializer& ObjectInitializer);
	virtual UWorld* GetWorld() const override;
	UFUNCTION()
	virtual UGameInstance* GetGameInstance() const;
	
	UFUNCTION(BlueprintNativeEvent, Category="OmegaSaveCondition")
	bool CheckSaveCondition(UOmegaSaveSubsystem* SaveSubsystem) const;
};


UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaSaveConditionCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category="OmegaSaveConditions", instanced, EditAnywhere)
	TArray<class UOmegaSaveCondition*> Conditions;
};