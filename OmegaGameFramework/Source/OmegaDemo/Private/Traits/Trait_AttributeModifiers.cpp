// Fill out your copyright notice in the Description page of Project Settings.


#include "Traits/Trait_AttributeModifiers.h"

TArray<FOmegaAttributeModifier> UTrait_AttributeModifiers::GetModifierValues_Implementation()
{
	return AttributeModifiers;
}
