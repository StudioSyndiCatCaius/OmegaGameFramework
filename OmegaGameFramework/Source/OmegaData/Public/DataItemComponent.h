// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDataItem.h"
#include "Components/ActorComponent.h"
#include "Delegates/DelegateCombinations.h"
#include "Functions/OmegaFunctions_TagEvent.h"
#include "DataItemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataItemChanged, UOmegaDataItem*, Item);

UCLASS( ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent) )
class OMEGADATA_API UDataItemComponent : public UActorComponent, public IDataInterface_AttributeModifier, public IDataInterface_SkillSource, public IActorTagEventInterface
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
	FGameplayTagContainer EntityTags;
	
	UPROPERTY(EditAnywhere, Category="Applied")
	FString FlagOnApplied;
	
	UPROPERTY(EditAnywhere, Category="Applied")
	FGameplayTagContainer TagsOnApplied;

	UPROPERTY(BlueprintAssignable)
	FOnDataItemChanged OnDataItemChanged;
	
	
	UFUNCTION(BlueprintCallable, Category="DataItem")
	void SetDataItem(UOmegaDataItem* NewDataItem);
	
	UFUNCTION(BlueprintPure, Category="DataItem")
	UOmegaDataItem* GetDataItem();

	UFUNCTION(BlueprintCallable, Category="DataItem")
	void ApplyToActor(const FString& Flag, FGameplayTagContainer Tags);

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;
	virtual TArray<UPrimaryDataAsset*> GetSkills_Implementation(UCombatantComponent* Combatant) override;

	virtual void OnTagEvent_Implementation(FGameplayTag Event) override;
		
};
