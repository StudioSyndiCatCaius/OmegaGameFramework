// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDataTrait.h"
#include "Interfaces/I_Combatant.h"
#include "Trait_AttributeModifiers.generated.h"

/**
 * 
 */
UCLASS(DisplayName="(Trait) Attribute Modifiers")
class OMEGADEMO_API UTrait_AttributeModifiers : public UOmegaDataTrait, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()

public:

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation(UCombatantComponent* CombatantComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	TArray<FOmegaAttributeModifier> AttributeModifiers;
	
};

UCLASS()
class OMEGADEMO_API UDataTraitBASE_PrimitiveComponent : public UOmegaDataTrait
{
	GENERATED_BODY()

	UDataTraitBASE_PrimitiveComponent();

public:
	virtual void AppliedToActor_Implementation(AActor* Actor, const FString& Flag, FGameplayTagContainer Tags) const override;

	UFUNCTION(BlueprintImplementableEvent,Category="PrimitiveDataTrait")
	void ApplyToPrimitiveComponent(UPrimitiveComponent* Component, const FString& Flag) const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PrimitiveDataTrait")
	TArray<TSubclassOf<UPrimitiveComponent>> ValidClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PrimitiveDataTrait")
	TArray<FString> ApplyOnFlags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PrimitiveDataTrait")
	bool bFirstOnly;
	
};
