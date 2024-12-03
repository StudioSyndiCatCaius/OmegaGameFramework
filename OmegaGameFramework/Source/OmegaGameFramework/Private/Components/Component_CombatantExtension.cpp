// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_CombatantExtension.h"

#include "Actors/Actor_Ability.h"

// Sets default values for this component's properties
UCombatantExtensionComponent::UCombatantExtensionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatantExtensionComponent::BeginPlay()
{
	Super::BeginPlay();

	// Retrieve the component and class once and store them in local variables
	UCombatantComponent* FoundCombatantComp = Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()));
	const UClass* OwnerClass = GetOwner()->GetClass();

	// Check if the component exists and assign it to CombatantRef
	if (FoundCombatantComp)
	{
		CombatantRef = FoundCombatantComp;
	}
	// Check if the owner is a child of AOmegaAbility and assign CombatantOwner to CombatantRef
	else if (OwnerClass && OwnerClass->IsChildOf(AOmegaAbility::StaticClass()))
	{
		if (const AOmegaAbility* OmegaAbility = Cast<AOmegaAbility>(GetOwner()))
		{
			CombatantRef = OmegaAbility->CombatantOwner;
		}
	}

	if(CombatantRef)
	{
		SetCombatant(CombatantRef);
	}
	// ...
	
}

void UCombatantExtensionComponent::BeginDestroy()
{
	ClearCombatant();
	Super::BeginDestroy();
}


// Called every frame
void UCombatantExtensionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCombatantExtensionComponent::SetCombatant(UCombatantComponent* Combatant)
{
	if(Combatant)
	{
		ClearCombatant();
		CombatantRef=Combatant;
		CombatantRef->OnDamaged.AddDynamic(this, &UCombatantExtensionComponent::OnAttributeDamaged);
		CombatantRef->OnCombatantNotify.AddDynamic(this, &UCombatantExtensionComponent::OnCombatantNotify);
		
		if(bIsAttributeModifier)
		{
			CombatantRef->AddAttrbuteModifier(this);
		}
		if(bIsDamageModifier)
		{
			CombatantRef->SetDamageModifierActive(this, true);
		}
		if(bIsSkillSource)
		{
			CombatantRef->SetSkillSourceActive(this, true);
		}

		OnCombatantSetup(Combatant);
	}
}

void UCombatantExtensionComponent::ClearCombatant()
{
	if(CombatantRef)
	{
		if(bIsAttributeModifier)
		{
			CombatantRef->RemoveAttributeModifier(this);
		}
		if(bIsDamageModifier)
		{
			CombatantRef->SetDamageModifierActive(this, false);
		}
		if(bIsSkillSource)
		{
			CombatantRef->SetSkillSourceActive(this, false);
		}
		CombatantRef=nullptr;
	}
}

