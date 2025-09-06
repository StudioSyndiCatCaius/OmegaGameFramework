// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Component_UtilMesh.h"

#include "Kismet/GameplayStatics.h"

UUtilMeshComponent::UUtilMeshComponent()
{
	
	bIsEditorOnly=true;
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	bHiddenInSceneCapture=true;
	bHiddenInGame=true;
	CastShadow=false;
	PrimaryComponentTick.bStartWithTickEnabled=false;
	
}

void UUtilMeshComponent::SetupUtilMesh(FLinearColor Color)
{
	if(GetStaticMesh())
	{
		//UMaterialInstanceDynamic* dyanMat=CreateDynamicMaterialInstance(0,GetStaticMesh()->GetMaterial(0));
		//dyanMat->SetVectorParameterValue("Tint",Color);
	}
}

void UUtilMeshComponent::SetBoundsZ(USceneComponent* baseComp, float ExtraZ)
{
	float initz=0;
	if(baseComp)
	{
		FVector origin;
		FVector ext;
		float rad;
		UKismetSystemLibrary::GetComponentBounds(baseComp,origin,ext,rad);
		initz=ext.Z;
	}
	SetRelativeLocation(FVector(0,0,initz+ExtraZ));
}
