// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UserWidget_ActorDisplay.h"

#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/KismetMathLibrary.h"



void UActorUIDisplay_Widget::_destroyRefActor()
{
	if(REF_Actor){ REF_Actor->K2_DestroyActor(); }
}

void UActorUIDisplay_Widget::NativeConstruct()
{
	_destroyRefActor();
	if(ActorClass)
	{
		REF_Actor=GetWorld()->SpawnActor(ActorClass);
	}
	Super::NativeConstruct();
}

void UActorUIDisplay_Widget::NativeDestruct()
{
	_destroyRefActor();
	Super::NativeDestruct();
}
