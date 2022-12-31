// Fill out your copyright notice in the Description page of Project Settings.

#include "Formulas/DamageFormula_AttributeDifference.h"

#include "Gameplay/CombatantComponent.h"


void UDamageFormula_AttributeDifference::GetDamageAmount_Implementation(UCombatantComponent* Instigator, UCombatantComponent* Target,
                                                         float& DamageOut)
{
	if(InstigatorAttribute && TargetAttribute)
	{
		float TempVal;
		float TempMax;

		Instigator->GetAttributeValue(InstigatorAttribute, TempVal, TempMax);
		float LocalPower_Inst = TempVal * InstigatorPower;

		Instigator->GetAttributeValue(TargetAttribute, TempVal, TempMax);
		float LocalPower_Targ = TempVal * TargetPower;
		
		DamageOut = (LocalPower_Inst)-(LocalPower_Targ);
		FMath::Clamp(DamageOut, 0, MaxDamage);
	}
	
}

