// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorConfig.h"

#include "Subsystems/OmegaSubsystem_Actors.h"

void UActorConfigComponent::BeginPlay()
{
	if(DefaultConfig)
	{
		if(UOmegaActorSubsystem* sub=GetWorld()->GetSubsystem<UOmegaActorSubsystem>())
		{
			for(FGameplayTag t : DefaultConfig->AutoregisterToGroups)
			{
				sub->SetActorRegisteredToGroup(t,GetOwner(),true);
			}
			
			for(TSoftClassPtr<AOmegaActorProcessor> p : DefaultConfig->TargetProcessors)
			{
				if(p)
				{
					sub->RegisterActorToProcessor(GetOwner(),p.LoadSynchronous());
				}
			}
		}
	}
	
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
}
