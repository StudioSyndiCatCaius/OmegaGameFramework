// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaActors.h"

#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Subsystems/Subsystem_Save.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Functions/F_BitFlag.h"
#include "Functions/F_GlobalParam.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_World.h"

#define LOCAL_CONSTRUCT \
if (GetWorld() && GetWorld()->IsGameWorld()) { OGF_GAME_CORE()->Actor_OnConstruct(this); } \
if (!GameplayGuid.IsValid()) { GameplayGuid=FGuid::NewGuid(); } \
Super::OnConstruction(Transform); \

#define LOCAL_BEGINPLAY \
SS_Engine=OGF_Subsystems::oEngine(); \
SS_World=OGF_Subsystems::oWorld(this); \
SS_GI=OGF_Subsystems::oGameInstance(this); \
SS_Save=OGF_Subsystems::oSave(this); \
PreBeginPlay(); \
OGF_GAME_CORE()->Actor_OnBeginPlay(this); \
Super::BeginPlay(); \
PostBeginPlay(); \


void AOmegaActorBASE::SetGuidflagValue(uint8 Flag, bool bValue, TEnumAsByte<EOmegaGlobalParamTarget> Target)
{
	UOmegaFunctions_GlobalVars::Guidflag_Set(this,GameplayGuid,Flag,bValue,Target);
}

bool AOmegaActorBASE::GetGuidflagValue(uint8 Flag, TEnumAsByte<EOmegaGlobalParamTarget> Target)
{
	return UOmegaFunctions_GlobalVars::Guidflag_Get(this,GameplayGuid,Flag);
}

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