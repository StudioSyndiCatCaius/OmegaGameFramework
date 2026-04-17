// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_DamageType.h"
#include "DataAssets/DA_Attribute.h"
#include "Components/Component_Combatant.h"



//################################################################
// DAMAGE SCRIPT
//################################################################
float UOmegaDamageTypeScript::OnDamageApplied_Implementation(float BaseDamage) const
{
	return BaseDamage;
}

void UOmegaDamageTypeScript::OnEffectApplied_Implementation(AOmegaGameplayEffect* Effect) const
{
	return;
}
