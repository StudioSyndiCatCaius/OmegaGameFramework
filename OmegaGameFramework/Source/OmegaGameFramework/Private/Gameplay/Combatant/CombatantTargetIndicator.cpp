// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Combatant/CombatantTargetIndicator.h"

// Sets default values


ACombatantTargetIndicator::ACombatantTargetIndicator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ACombatantTargetIndicator::BeginPlay()
{
	Super::BeginPlay();
	CombatantOwner->OnActiveTargetChanged.AddDynamic(this, &ACombatantTargetIndicator::ACombatantTargetIndicator::Native_Updatetarget);
	SetActorHiddenInGame(true);
}

// Called every frame
void ACombatantTargetIndicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UCombatantComponent* ACombatantTargetIndicator::GetOwningCombatant()
{
	return CombatantOwner;
}

UCombatantComponent* ACombatantTargetIndicator::GetTargetCombatant()
{
	if(CombatantOwner->ActiveTarget)
	{
		return CombatantOwner->ActiveTarget;
	}
	
	return nullptr;
}

void ACombatantTargetIndicator::Native_Updatetarget(UCombatantComponent* Combatant, bool bValid)
{
	if(bValid)
	{
		OnTargetCombatantUpdated(Combatant);
		AttachToActor(Combatant->GetOwner(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	SetActorHiddenInGame(!bValid);
	OnCombatantSetActive(bValid);
}

