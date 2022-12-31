// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageFormula.h"

#include "DamageFormula_AttributeDifference.generated.h"

class UOmegaAttribute;

UCLASS(DisplayName="Formula (Attribute Difference)")
class OMEGADEMO_API UDamageFormula_AttributeDifference : public UDamageFormula
{
	GENERATED_BODY()

public:
	virtual void GetDamageAmount_Implementation(UCombatantComponent* Instigator, UCombatantComponent* Target, float& DamageOut) override;
	
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	UOmegaAttribute* InstigatorAttribute;
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	float InstigatorPower = 1;
	
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	UOmegaAttribute* TargetAttribute;
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	float TargetPower = 0.75;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	float MaxDamage = 999999;
};
