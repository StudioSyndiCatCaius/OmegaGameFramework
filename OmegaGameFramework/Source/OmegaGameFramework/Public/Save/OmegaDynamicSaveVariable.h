// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DataInterface_General.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "Engine/DataAsset.h"


#include "OmegaDynamicSaveVariable.generated.h"


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicSaveVariable : public UPrimaryDataAsset, public IDataInterface_General, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FText DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Description")
	FSlateBrush Icon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FText VariableDescription;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
	FGameplayTagContainer GameplayTags;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="General")
	TArray<UOmegaDynamicSaveVariableState*> States;
	
};

UCLASS(EditInlineNew,Blueprintable,BlueprintType,CollapseCategories)
class OMEGAGAMEFRAMEWORK_API UOmegaDynamicSaveVariableState : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", DisplayName="Name")
	FString StateLabel;
};
