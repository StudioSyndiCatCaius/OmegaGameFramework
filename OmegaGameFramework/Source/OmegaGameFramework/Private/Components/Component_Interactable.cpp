// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_Interactable.h"

#include "OmegaSettings.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Functions/F_Common.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Gameplay.h"

#define LOCAL_LOG_ERROR(string) OGF_Log::Error("- INTERACT COMPONENT: " string)

TSubclassOf<AOmegaGameplaySystem> UOmegaComponent_Interactable::GetContext_System(FGameplayTag Tag) const
{
	if (OverrideSystem) { return OverrideSystem; }
	UOmegaSettings* set=OGF_CFG();
	if (Tag.IsValid() && set->System_Interaction_ByTag.Contains(Tag))
	{
		return set->System_Interaction_ByTag[Tag].LoadSynchronous();
	}
	if (Tag==set->Default_InteractTag)
	{
		if (TSubclassOf<AOmegaGameplaySystem> sys=set->System_Interaction.LoadSynchronous())
		{
			return sys;
		}
	}
	
	return nullptr;
}

void UOmegaComponent_Interactable::OnInteractSystemEnded(UObject* Context, FString Flag)
{
	OnInteractionEnd.Broadcast(this);
}

UOmegaComponent_Interactable::UOmegaComponent_Interactable()
{
}

void UOmegaComponent_Interactable::OnInteraction_Implementation(AActor* InteractInstigator, FGameplayTag Tag,
	FOmegaCommonMeta Context)
{
	if(TSubclassOf<AOmegaGameplaySystem> sys=GetContext_System(Tag))
	{
		if (AOmegaGameplaySystem* interact_sys=GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(sys,GetOwner(),"",Context))
		{
			OnInteractionBegin.Broadcast(this);
			interact_sys->OnSystemShutdown.AddDynamic(this,&UOmegaComponent_Interactable::OnInteractSystemEnded);
		}
		else
		{
			LOCAL_LOG_ERROR("Could not activate interact system");
		}
	}
	else
	{
		LOCAL_LOG_ERROR("No valid Interact system found in OmegaSettings");
	}
}
