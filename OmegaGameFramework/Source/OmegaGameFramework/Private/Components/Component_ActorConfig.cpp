// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_ActorConfig.h"

#include "Subsystems/OmegaSubsystem_Actors.h"

void UActorConfigComponent::BeginPlay()
{
	if(DefaultConfig)
	{
		for(TSubclassOf<AOmegaActorProcessor> p : DefaultConfig->TargetProcessors)
		{
			if(p)
			{
				GetWorld()->GetSubsystem<UOmegaActorSubsystem>()->RegisterActorToProcessor(GetOwner(),p);
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
