// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearEvents/LinearEvent_ActorBase.h"




AActor* UOmegaActorEventBase::GetEventActor()
{
	if(ActorSource && GetWorld())
	{
		return ActorSource->Private_GetActor(GetWorld());
	}
	return nullptr;
}

void UOmegaActorEvent_Teleport::Native_Begin()
{
	Super::Native_Begin();
	if(GetEventActor() && TargetPoint && TargetPoint->Private_GetActor(GetWorld()))
	{
		FHitResult dumphit;
		GetEventActor()->K2_SetActorLocationAndRotation(TargetPoint->Private_GetActor(GetWorld())->GetActorLocation(),TargetPoint->GetActor()->GetActorRotation(),false,dumphit,false);
	}
	Finish(" ");
}
