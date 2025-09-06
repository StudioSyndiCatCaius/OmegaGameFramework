// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor_EventVolume.h"

#include "Components/Component_Combatant.h"
#include "Kismet/KismetStringLibrary.h"


void UOmegaEventVolumeTriggerScript::TriggerEvent() const
{
	if(REF_Owner)
	{
		REF_Owner->Local_TryPlay();
	}
}

AOmega_EventVolume* UOmegaEventVolumeSequenceScript::GetOwningActor() const
{
	if(AOmega_EventVolume* TempVol = Cast<AOmega_EventVolume>(GetOuter()))
	{
		return TempVol;
	}
	return nullptr;
}

AOmega_EventVolume::AOmega_EventVolume()
{
	Combatant = CreateDefaultSubobject<UCombatantComponent>("Combatant");
	Shape=EVolumeShape::OmegaVolume_Box;
}

void AOmega_EventVolume::Local_TryPlay() const
{
	if(GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->CustomSaveConditionsMet(Conditions))
	{
		for(auto* a : Events)
		{
			if(a) { a->OnEventTriggered(this);}
		}
	}
}

void AOmega_EventVolume::OnConstruction(const FTransform& Transform)
{
	if(TriggerScript)
	{
		Color=TriggerScript->GetVolumeColor();
	}
	Super::OnConstruction(Transform);
}

void AOmega_EventVolume::BeginPlay()
{
	if(TriggerScript)
	{
		TriggerScript->REF_Owner=this;
		TriggerScript->OnBeginPlay(this);
	}
	Super::BeginPlay();
}

