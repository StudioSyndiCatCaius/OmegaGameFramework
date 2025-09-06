// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_WidgetDisplay.h"

#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/SpringArmComponent.h"

AOmegaWidgetDisplayActor::AOmegaWidgetDisplayActor()
{
	RootComponent=CreateDefaultSubobject<USceneComponent>("Root");
	SpringArm=CreateOptionalDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SceneCapture=CreateOptionalDefaultSubobject<USceneCaptureComponent2D>("SceneCapture");
	SceneCapture->SetupAttachment(SpringArm);
}

void AOmegaWidgetDisplayActor::OnConstruction(const FTransform& Transform)
{
	if(SceneCapture)
	{
		SceneCapture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
		for(auto* c : GetRendered_Components())
		{
			if(c){ SceneCapture->ShowOnlyComponents.AddUnique(c);}
		}
		for(auto* c : GetRendered_Components())
		{
			if(c){ SceneCapture->ShowOnlyComponents.AddUnique(c);}
		}
	}
	Super::OnConstruction(Transform);
}

TArray<AActor*> AOmegaWidgetDisplayActor::GetRendered_Actors_Implementation()
{
	TArray<AActor*> out;
	out.Add(this);
	return out;
}

TArray<UPrimitiveComponent*> AOmegaWidgetDisplayActor::GetRendered_Components_Implementation()
{
	TArray<UPrimitiveComponent*> out;
	return out;
}
