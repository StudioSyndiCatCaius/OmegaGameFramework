// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Minimap.h"

#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Functions/F_Common.h"
#include "GameFramework/SpringArmComponent.h"
#include "Subsystems/Subsystem_World.h"


AOmegaMinimapActor::AOmegaMinimapActor()
{
}

void AOmegaMinimapActor::BeginPlay()
{
	Super::BeginPlay();
	if (RootComponent)
	{
		if (UPrimitiveComponent* primRoot=Cast<UPrimitiveComponent>(RootComponent))
		{
			UOmegaFunctions_Minimap::RegisterViewComponent(this,primRoot,true);	
		}
	}
}

UOmegaMinimapMeshComponent::UOmegaMinimapMeshComponent()
{
	CastShadow=false;
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UOmegaMinimapMeshComponent::BeginPlay()
{
	Super::BeginPlay();
	bVisibleInSceneCaptureOnly=true;
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if (AOmegaMinimap_Camera* cam=UOmegaFunctions_Minimap::GetCamera(this))
	{
		cam->SceneCaptureComponent->ShowOnlyComponents.Add(this);
	}
	L_Refresh();
}

void UOmegaMinimapMeshComponent::L_Refresh()
{
	if (bLockRotation)
	{
		SetWorldRotation(LockedRotation);
	}
}

// ------------------------------------------------------------------------------------------------------------
// Display Mesh
// ------------------------------------------------------------------------------------------------------------
AOmegaMinimap_Mesh::AOmegaMinimap_Mesh()
{
	AActor::SetActorHiddenInGame(true);

	StaticMeshComponent=CreateDefaultSubobject<UOmegaMinimapMeshComponent>(TEXT("Minimap Mesh"));
}

void AOmegaMinimap_Mesh::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
}

// ------------------------------------------------------------------------------------------------------------
// Cmaera
// ------------------------------------------------------------------------------------------------------------
AOmegaMinimap_Camera::AOmegaMinimap_Camera()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	SpringArm=CreateOptionalDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength=400;
	CameraComponent=CreateOptionalDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArm);
	SceneCaptureComponent=CreateOptionalDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene Capture"));
	SceneCaptureComponent->SetupAttachment(CameraComponent);
	SceneCaptureComponent->PrimitiveRenderMode=ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
}


void AOmegaMinimap_Camera::BeginPlay()
{
	Super::BeginPlay();
}

AOmegaMinimap_Camera* UOmegaFunctions_Minimap::GetCamera(UObject* WorldContextObject)
{
	if (AOmegaWorldManager* wm=UOmegaGameFrameworkBPLibrary::GetOmegaWorldManager(WorldContextObject))
	{
		return wm->minimap_camera;
	}
	return nullptr;
}

void UOmegaFunctions_Minimap::RegisterViewComponent(UObject* WorldContextObject, UPrimitiveComponent* Component,bool bRegistered)
{
	if (AOmegaMinimap_Camera* cam=GetCamera(WorldContextObject))
	{
		if (bRegistered && !cam->SceneCaptureComponent->ShowOnlyComponents.Contains(Component))
		{
			cam->SceneCaptureComponent->ShowOnlyComponents.Add(Component);
		}
		else if (!bRegistered && cam->SceneCaptureComponent->ShowOnlyComponents.Contains(Component))
		{
			cam->SceneCaptureComponent->ShowOnlyComponents.Remove(Component);
		}
	}

}

