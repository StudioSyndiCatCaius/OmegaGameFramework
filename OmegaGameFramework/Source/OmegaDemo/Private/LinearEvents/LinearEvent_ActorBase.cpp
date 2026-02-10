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

TArray<AActor*> UOmegaActorEventBase::GetEventActorList()
{
	TArray<AActor*> out;
	if(ActorSource && GetWorld())
	{
		return ActorSource->Private_GetActorList(GetWorld());
	}
	return out;
}

void UOmegaActorEvent_Teleport::OnEventBegin_Implementation(const FString& Flag)
{
	if(GetEventActor() && TargetPoint && TargetPoint->Private_GetActor(GetWorld()))
	{
		FHitResult dumphit;
		GetEventActor()->K2_SetActorLocationAndRotation(TargetPoint->Private_GetActor(GetWorld())->GetActorLocation(),TargetPoint->Private_GetActor(GetWorld())->GetActorRotation(),false,dumphit,false);
	}
	Finish(" ");
}



