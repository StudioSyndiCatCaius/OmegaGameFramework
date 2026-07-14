// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_PlayerState.h"

#include "Components/Component_Combatant.h"

AOmegaPlayerState::AOmegaPlayerState()
{
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
}
