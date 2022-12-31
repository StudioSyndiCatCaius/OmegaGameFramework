// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaDataTrait.h"
#include "Gameplay/DataInterface_AttributeModifier.h"
#include "Trait_AttributeModifiers.generated.h"

/**
 * 
 */
UCLASS(DisplayName="Trait (Attribute Modifiers)")
class OMEGADEMO_API UTrait_AttributeModifiers : public UOmegaDataTrait, public IDataInterface_AttributeModifier
{
	GENERATED_BODY()

public:

	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attributes")
	TArray<FOmegaAttributeModifier> AttributeModifiers;
	
};
