// Fill out your copyright notice in the Description page of Project Settings.


#include "Traits/Trait_AttributeModifiers.h"

TArray<FOmegaAttributeModifier> UTrait_AttributeModifiers::GetModifierValues_Implementation()
{
	return AttributeModifiers;
}

UDataTraitBASE_PrimitiveComponent::UDataTraitBASE_PrimitiveComponent()
{
	ApplyOnFlags.Add("SetMesh");

	ValidClasses.Add(UStaticMeshComponent::StaticClass());
	ValidClasses.Add(USkeletalMeshComponent::StaticClass());
}

void UDataTraitBASE_PrimitiveComponent::AppliedToActor_Implementation(AActor* Actor, const FString& Flag,
	FGameplayTagContainer Tags) const
{
	if(ApplyOnFlags.IsEmpty() || ApplyOnFlags.Contains(Flag))
	{
		for(auto* TempComp : Actor->K2_GetComponentsByClass(UPrimitiveComponent::StaticClass()))
		{
			ApplyToPrimitiveComponent(Cast<UPrimitiveComponent>(TempComp),Flag);
			if(bFirstOnly)
			{
				return;
			}
		}
	}
}
