// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_GameplayObject.h"
#include "Components/Component_ActorState.h"
#include "Subsystems/OmegaSubsystem_Save.h"

AOmegaGameplayObjectActor::AOmegaGameplayObjectActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	ActorState=CreateOptionalDefaultSubobject<UActorStateComponent>("ActorState");
	SaveVisibility=CreateOptionalDefaultSubobject<UOmegaSaveStateComponent>("SaveVisibility");
}
