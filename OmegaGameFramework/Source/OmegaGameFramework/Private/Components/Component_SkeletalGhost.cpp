// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_SkeletalGhost.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

void USkeletalGhostComponent::LinkSkeletalMeshComponents(USkeletalMeshComponent* DriverMesh,
	USkeletalMeshComponent* GhostMesh)
{
	if(DriverMesh && GhostMesh)
	{
		LinkedGhostMeshes.Add(DriverMesh,GhostMesh);
		GhostMesh->SetSkeletalMesh(DriverMesh->GetSkeletalMeshAsset());
		GhostMesh->SetMasterPoseComponent(DriverMesh,true);
		for(auto* i : Scripts)
		{
			if(i) { i->OnMeshLinked(DriverMesh,GhostMesh); }
		}
	}
}
