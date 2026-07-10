// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Gambit.h"


float UCombatantGambit_Evaluator::Check_Implementation(const UCombatantComponent* Combatant) const
{
	return 0.0;
}

bool UOmegaGambit_Task::Begin_Implementation(const UCombatantComponent* Combatant) const
{
	return false;
}

bool UOmegaGambit_Task::Tick_Implementation(const UCombatantComponent* Combatant, float DeltaSeconds) const
{
	return false;
}

bool UOmegaGambit_Task::End_Implementation(const UCombatantComponent* Combatant) const
{
	return false;
}

bool UOmegaGambit_Task_Gambit::Begin_Implementation(const UCombatantComponent* Combatant) const
{
	return Super::Begin_Implementation(Combatant);
}

bool UOmegaGambit_Task_Gambit::End_Implementation(const UCombatantComponent* Combatant) const
{
	return Super::End_Implementation(Combatant);
}

bool UOmegaGambit_Task_Gambit::Tick_Implementation(const UCombatantComponent* Combatant, float DeltaSeconds) const
{
	return Super::Tick_Implementation(Combatant, DeltaSeconds);
}
