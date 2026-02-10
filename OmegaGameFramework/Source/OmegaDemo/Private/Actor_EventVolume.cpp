// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor_EventVolume.h"

#include "OmegaSettings.h"
#include "Components/Component_Combatant.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Macros.h"


void UOmegaEventVolumeTriggerScript::TriggerEvent() const
{
	if(REF_Owner)
	{
		REF_Owner->Local_TryPlay();
	}
}

void UOmegaEventVolumeTriggerScript::OnBeginPlay_Implementation(AOmega_EventVolume* Owner)
{
}

FLinearColor UOmegaEventVolumeTriggerScript::GetVolumeColor_Implementation() const
{
	return FLinearColor::Black;
}

AOmega_EventVolume* UOmegaEventVolumeSequenceScript::GetOwningActor() const
{
	if(AOmega_EventVolume* TempVol = Cast<AOmega_EventVolume>(GetOuter()))
	{
		return TempVol;
	}
	return nullptr;
}

void UOmegaEventVolumeSequenceScript::OnEventTriggered_Implementation(AActor* Owner) const
{
}


AOmega_EventVolume::AOmega_EventVolume()
{
	Combatant = CreateDefaultSubobject<UCombatantComponent>("Combatant");
	Shape=EVolumeShape::OmegaVolume_Box;
}

void AOmega_EventVolume::Local_TryPlay()
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
	OGF_CFG()->OverrideActorLabel(this);
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

