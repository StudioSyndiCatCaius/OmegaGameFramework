// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/OmegaComponent.h"
#include "OmegaGameManager.h"
#include "OmegaSettings.h"

void UOmegaComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                    FActorComponentTickFunction* ThisTickFunction)
{
	if (IsActive())
	{
		ActivateTick(DeltaTime);
	}
	else
	{
		DectivateTick(DeltaTime);
	}
	if (bDebug)
	{
		DebugTick(IsActive(), DeltaTime);
	}
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UOmegaComponent::BeginPlay()
{
	OGF_GAME_CORE()->Component_BeginPlay(this, GetOwner());
	Super::BeginPlay();
}

void UOmegaComponent::Activate(bool bReset)
{
	Super::Activate(bReset);
	OnActivation(true);
}

void UOmegaComponent::Deactivate()
{
	Super::Deactivate();
	OnActivation(false);
}
