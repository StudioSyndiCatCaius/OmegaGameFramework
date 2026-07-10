// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/sys_dialogue.h"
#include "Misc/EngineVersionComparison.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "Components/AudioComponent.h"
#include "Components/SceneCaptureComponent2D.h"


AOmegaDemoSystem_Dialogue::AOmegaDemoSystem_Dialogue()
{
	PrimaryActorTick.bCanEverTick = true;
	CaptureComponent=CreateOptionalDefaultSubobject<USceneCaptureComponent2D>("SceneCapture");
	CaptureComponent->SetupAttachment(RootComponent);
	
	VoiceComponent=CreateOptionalDefaultSubobject<UAudioComponent>("Voice");
	ImagesComponent=CreateOptionalDefaultSubobject<UInstanceActorComponent>("Images");
	if (ImagesComponent)
	{
		ImagesComponent->InstancedActorClass=AInstanceActor_Image::StaticClass();
	}
	SpeakersComponent=CreateOptionalDefaultSubobject<UInstanceActorComponent>("Speakers");
	if (SpeakersComponent)
	{
		SpeakersComponent->InstancedActorClass=AInstanceActor_Speaker::StaticClass();
	}
}

void AOmegaDemoSystem_Dialogue::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOmegaDemoSystem_Dialogue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AOmegaDemoSystem_Dialogue::Image_SetTexture(UTexture* Texture, int32 ImageIndex)
{
	if (!ImagesComponent) return false;
	if (AInstanceActor_Image* imgA=Cast<AInstanceActor_Image>(ImagesComponent->GetInstanceByIndex(ImageIndex)))
	{
		return imgA->SetImageTexture(Texture);
	}
	return false;
}

UMaterialInstanceDynamic* AInstanceActor_Image::L_GetDynaMat()
{
	return DynaMat;
}

bool AInstanceActor_Image::SetImageTexture(UTexture* Texture)
{
	if (Mesh)
	{
		if (UMaterialInstanceDynamic* mat=L_GetDynaMat())
		{
			mat->SetTextureParameterValue("Texture", Texture);
		}
	}
	return false;
}

UMaterialInstanceDynamic* AInstanceActor_Speaker::L_GetDynaMat()
{
	return DynaMat;
}

// ---------------------------------------------------------------------------------------------------------------------
// Actor Instances
// ---------------------------------------------------------------------------------------------------------------------
