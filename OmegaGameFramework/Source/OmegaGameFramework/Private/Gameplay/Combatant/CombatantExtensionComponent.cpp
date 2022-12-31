// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Combatant/CombatantExtensionComponent.h"

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

	if (GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()))
	{
		CombatantRef = Cast<UCombatantComponent>(GetOwner()->GetComponentByClass(UCombatantComponent::StaticClass()));
		CombatantRef->OnDamaged.AddDynamic(this, &UCombatantExtensionComponent::OnAttributeDamaged);
		CombatantRef->OnCombatantNotify.AddDynamic(this, &UCombatantExtensionComponent::OnCombatantNotify);
	}
	
	if(CombatantRef)
	{
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
	}
	// ...
	
}

void UCombatantExtensionComponent::BeginDestroy()
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
	}
	Super::BeginDestroy();
}


// Called every frame
void UCombatantExtensionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

