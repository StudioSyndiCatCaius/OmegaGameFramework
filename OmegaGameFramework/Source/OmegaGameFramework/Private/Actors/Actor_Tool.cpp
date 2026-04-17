// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_Tool.h"

AOmegaToolActor::AOmegaToolActor()
{
}

void AOmegaToolActor::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaToolActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (f_recoilDur<=0)
	{
		f_recoilDur-=DeltaSeconds;
	}
	else
	{
		K2_ActiveTick(DeltaSeconds);
		if (b_isActive)
		{
			f_recoilDur=RecoilTile;
			K2_OnTrigger();
		}
	}
}

USkeletalMeshComponent* AOmegaToolActor::GetToolOwnerSkeletalMesh()
{
	if (GetAttachParentActor())
	{
		for (UActorComponent* s : GetAttachParentActor()->GetComponentsByTag(USkeletalMeshComponent::StaticClass(),SkeletalMeshTag))
		{
			if (s)
			{
				return Cast<USkeletalMeshComponent>(s);
			}
		}
	}
	return nullptr;
}

bool AOmegaToolActor::SetToolActive(bool bActive)
{
	if (bActive!=b_isActive)
	{
		b_isActive=bActive;
		
		K2_OnActivate(b_isActive);
		return true;	
	}
	return false;
}
