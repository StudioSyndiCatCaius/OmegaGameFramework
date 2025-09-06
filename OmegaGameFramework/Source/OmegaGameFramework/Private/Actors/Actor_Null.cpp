// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Null.h"

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
