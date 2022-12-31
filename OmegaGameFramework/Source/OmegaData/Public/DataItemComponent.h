// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDataItem.h"
#include "Components/ActorComponent.h"
#include "DataItemComponent.generated.h"


UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent) )
class OMEGADATA_API UDataItemComponent : public UActorComponent, public IDataInterface_AttributeModifier, public IDataInterface_SkillSource
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDataItemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="DataItem")
	UOmegaDataItem* DataItem;

	UPROPERTY(EditAnywhere, Category="DataItem")
	FString FlagOnApplied;

	UPROPERTY(EditAnywhere, Category="DataItem")
	FGameplayTagContainer TagsOnApplied;
	
	UFUNCTION(BlueprintCallable, Category="DataItem")
	void SetDataItem(UOmegaDataItem* NewDataItem);
	
	UFUNCTION(BlueprintPure, Category="DataItem")
	UOmegaDataItem* GetDataItem();

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation() override;
		
};
