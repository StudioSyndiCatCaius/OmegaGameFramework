// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaActors.h"

#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Subsystems/Subsystem_Save.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

#define LOCAL_CONSTRUCT \
OGF_GAME_CORE()->Actor_OnConstruct(this); \
Super::OnConstruction(Transform); \

#define LOCAL_BEGINPLAY \
SS_Engine=OGF_Subsystems::oEngine(); \
SS_World=OGF_Subsystems::oWorld(this); \
SS_GI=OGF_Subsystems::oGameInstance(this); \
SS_Save=GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>(); \
PreBeginPlay(); \
OGF_GAME_CORE()->Actor_OnBeginPlay(this); \
Super::BeginPlay(); \
PostBeginPlay(); \

void AOmegaActorBASE::OnConstruction(const FTransform& Transform)
{
	LOCAL_CONSTRUCT
}

void AOmegaActorBASE::BeginPlay()
{
	LOCAL_BEGINPLAY
}

void AOmegaPawnBASE::OnConstruction(const FTransform& Transform)
{
	LOCAL_CONSTRUCT
}

void AOmegaPawnBASE::BeginPlay()
{
	LOCAL_BEGINPLAY
}

void AOmegaBaseCharacter::OnConstruction(const FTransform& Transform)
{
	LOCAL_CONSTRUCT
}

void AOmegaBaseCharacter::BeginPlay()
{
	LOCAL_BEGINPLAY
}

#undef LOCAL_BEGINPLAY
#undef LOCAL_CONSTRUCT