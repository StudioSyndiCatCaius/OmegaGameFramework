// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Gameplay/AttributeModifierContainer.h"



TArray<FOmegaAttributeModifier> UAttributeModifierContainer::GetModifierValues_Implementation()
{
	FOmegaAttributeModifier LocalMod;
	LocalMod.Attribute = Attribute;
	LocalMod.Incrementer = IncValue;
	LocalMod.Multiplier = MultiValue;
	
	TArray<FOmegaAttributeModifier> ModifierList;
	ModifierList.Add(LocalMod);
	
	return ModifierList;
}

FGameplayTagContainer UAttributeModifierContainer::GetObjectGameplayTags_Implementation()
{
	return Tags;
}
