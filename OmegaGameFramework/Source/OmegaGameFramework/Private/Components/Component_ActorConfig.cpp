// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorConfig.h"

#include "OmegaSettings.h"
#include "OmegaSettings_Gameplay.h"
#include "Subsystems/Subsystem_Actors.h"

void UActorConfigComponent::L_TimerEnd()
{
	if(UOmegaActorSubsystem* sub=GetWorld()->GetSubsystem<UOmegaActorSubsystem>())
	{
		for(FGameplayTag t : DefaultConfig->AutoregisterToGroups)
		{
			sub->SetActorRegisteredToGroup(t,GetOwner(),true);
		}
			
		FActorModifiers amods;
		amods.Script=DefaultConfig->BeginPlay_Modifiers;
		amods.ApplyMods(GetOwner());
	}
}

UOmegaActorConfig* UActorConfigComponent::L_GetConfig()
{
	if (UOmegaActorConfig* _Newconfig= GetMutableDefault<UOmegaSettings>()->ActorConfig_PerClass
		.FindOrAdd(TSoftClassPtr<AActor>(GetOwner()->GetClass())).LoadSynchronous())
	{
		return _Newconfig;
	}
	return DefaultConfig;
}

void UActorConfigComponent::BeginPlay()
{
	SetConfig(L_GetConfig());
	Super::BeginPlay();
}

void UActorConfigComponent::SetConfig(UOmegaActorConfig* Config)
{
	if(Config)
	{
		DefaultConfig=Config;
	}
	else
	{
		DefaultConfig=nullptr;
	}
	if(DefaultConfig)
	{
		float _inVal=DefaultConfig->BeginPlayMod_Delay.GetValue();
		if(_inVal>0.0)
		{
			GetWorld()->GetTimerManager().SetTimer(timer_modDelay,this, &UActorConfigComponent::L_TimerEnd,_inVal);	
		}
		else
		{
			L_TimerEnd();
		}
		
	}
}
