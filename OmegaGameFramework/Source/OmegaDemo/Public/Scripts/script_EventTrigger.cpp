// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "script_EventTrigger.h"

#include "FlowAsset.h"
#include "FlowSubsystem.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Subsystems/Subsystem_Gameplay.h"


void UEventTrigger_ActorOverlap::Local_OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OverlappedActor && 
		(Allowed_Classes.IsEmpty() || Allowed_Classes.Contains(OverlappedActor->GetClass())))
	{
		if (APawn* Pawn = Cast<APawn>(OverlappedActor))
		{
			if (!Allowed_Classes.IsEmpty() && !Allowed_Classes.Contains(Pawn->GetController()->GetClass()))
			{
				return;
			}
		}
		
		TriggerEvent();
	}
}

void UEventTrigger_ActorOverlap::OnBeginPlay_Implementation(AOmega_EventVolume* Owner)
{
	Owner->OnActorBeginOverlap.AddDynamic(this,&UEventTrigger_ActorOverlap::Local_OnOverlap);
}

void UEventTrigger_Timer::Local_TimerFinish()
{
	TriggerEvent();
}

void UEventTrigger_Timer::OnBeginPlay_Implementation(AOmega_EventVolume* Owner)
{
	Owner->GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&UEventTrigger_Timer::Local_TimerFinish,Time);
}

void UEventScript_ActorModify::OnEventTriggered_Implementation(AActor* Owner) const
{
	UOmegaComponentModifierFunctions::ApplyModifierTo_Actor(Modifiers,Owner);
}

void UEventScript_PlayFlow::OnEventTriggered_Implementation(AActor* Owner) const
{
	if (UseFlowSystem)
	{
		GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>()->ActivateGameplaySystem(OGF_CFG()->GetSystem_FlowAsset(),FlowAsset);
	}
	else
	{
		FFlowAssetOverrideData override_data;
		OGF_SUB_FLOW()->StartRootFlow(Owner,FlowAsset,override_data);
	}
}


void UEventScript_SetLifetime::OnEventTriggered_Implementation(AActor* Owner) const
{
	Owner->SetLifeSpan(NewLifetime);
}
