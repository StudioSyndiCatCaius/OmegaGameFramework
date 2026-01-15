// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Gameplay.h"

#include "MaterialKeyGeneratorContext.h"
#include "Subsystems/Subsystem_Gameplay.h"
#include "OmegaSettings.h"

UOmegaSettings_Gameplay::UOmegaSettings_Gameplay()
{
	//DefaultInteractionType=FGameplayTag::RequestGameplayTag("Event.Actor.Interact");
}

TArray<UOmegaGameplayModule*> UOmegaSettings_Gameplay::GetModules()
{
	TArray<UOmegaGameplayModule*> out;
	for(auto* a : ModuleSets)
	{
		if(a)
		{
			out.Append(a->GetModules());
		}
	}
	out.Append(ScriptedModules);
	return out;
}





