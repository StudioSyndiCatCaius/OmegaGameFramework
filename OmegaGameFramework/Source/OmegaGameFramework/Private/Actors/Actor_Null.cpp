// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Null.h"

#include "OmegaGameCore.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"

void AOmegaBASEActor::OnConstruction(const FTransform& Transform)
{
	OGF_GAME_CORE()->OmegaActor_OnConstruct(this);
	OGF_CFG()->OverrideActorLabel(this);
	Super::OnConstruction(Transform);
}

void AOmegaBASEActor::BeginPlay()
{
	OGF_GAME_CORE()->OmegaActor_OnBeginPlay(this);
	Super::BeginPlay();
}

void AOmegaBASEPawn::OnConstruction(const FTransform& Transform)
{
	OGF_GAME_CORE()->OmegaActor_OnConstruct(this);
	OGF_CFG()->OverrideActorLabel(this);
	Super::OnConstruction(Transform);
}

void AOmegaBASEPawn::BeginPlay()
{
	OGF_GAME_CORE()->OmegaActor_OnBeginPlay(this);
	Super::BeginPlay();
}

AOmegaNullActor::AOmegaNullActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("root");
}

void AOmegaNullActor::BeginPlay()
{
#if WITH_EDITOR
	if(NewActorLabel.IsValid())
	{
		SetActorLabel(NewActorLabel.ToString());
	}
#endif
	
	Super::BeginPlay();
}
