// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Null.h"

#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"


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
