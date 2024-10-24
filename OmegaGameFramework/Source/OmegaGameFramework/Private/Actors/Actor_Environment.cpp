// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Environment.h"

#include "Components/BoxComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/RuntimeVirtualTextureComponent.h"
#include "Components/SkyLightComponent.h"
#include "Async/TaskGraphInterfaces.h"
#include "Kismet/KismetMathLibrary.h"


AOmegaActorEnvironment::AOmegaActorEnvironment()
{
	EnvironmentRoot = CreateDefaultSubobject<USceneComponent>("VolumeRoot");


	SkyLight = CreateOptionalDefaultSubobject<USkyLightComponent>("SkyLight");
	if(SkyLight)
	{
		SkyLight->SetupAttachment(EnvironmentRoot);
		SkyLight->SetIntensity(2.0);
	}
	DirectionalLight = CreateOptionalDefaultSubobject<UDirectionalLightComponent>("DirectionalLight");
	if(DirectionalLight)
	{
		DirectionalLight->SetupAttachment(EnvironmentRoot);
		DirectionalLight->SetIntensity(5.0);
	}
	DirectionalLight_Arrow = CreateOptionalDefaultSubobject<UArrowComponent>("DirectionalLight_Arrow");
	if(DirectionalLight_Arrow) { DirectionalLight_Arrow->SetupAttachment(DirectionalLight); }
	Fog= CreateOptionalDefaultSubobject<UExponentialHeightFogComponent>("Fog");
	if(Fog) { Fog->SetupAttachment(EnvironmentRoot); }
	Atmosphere= CreateOptionalDefaultSubobject<USkyAtmosphereComponent>("Atmosphere");
	if(Atmosphere) { Atmosphere->SetupAttachment(EnvironmentRoot); }
	Clouds= CreateOptionalDefaultSubobject<UVolumetricCloudComponent>("Clouds");
	if(Clouds) { Clouds->SetupAttachment(EnvironmentRoot); }
	PostProcess= CreateOptionalDefaultSubobject<UPostProcessComponent>("PostProcessing");
	if(PostProcess) { PostProcess->SetupAttachment(EnvironmentRoot); }
	SkyBox= CreateOptionalDefaultSubobject<UStaticMeshComponent>("SkyBox");
	if(SkyBox) { SkyBox->SetupAttachment(EnvironmentRoot); }
	//VirtualTextureComponent= CreateOptionalDefaultSubobject<URuntimeVirtualTextureComponent>("VirtualTexture");
	//if(VirtualTextureComponent) { VirtualTextureComponent->SetupAttachment(EnvironmentRoot); }

	if(SkyBox)
	{
		SkyBox->SetCollisionResponseToAllChannels(ECR_Ignore);
		SkyBox->SetCastShadow(false);
	}
}

void AOmegaActorEnvironment::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(SkyLight)
	{
		SkyLight->RecaptureSky();
	}
	if(current_preset)
	{
		for(auto* TempScript : current_preset->Scripts)
		{
			if(TempScript)
			{
				TempScript->OnUpdated(this);
			}
		}
	}
}


void AOmegaActorEnvironment::AutosetVirtualTextureFromLandscape()
{
	/*
	if(Landscapes.IsValidIndex(0) && Landscapes[0])
	{
		VirtualTextureManager->SetBoundsAlignActor(Landscapes[0]);
		VirtualTextureManager->UpdateBounds();
	}
	
	for(auto* TempLandscape: Landscapes)
	{
		if(TempLandscape && VirtualTextureManager->GetVirtualTexture())
		{
			TempLandscape->RuntimeVirtualTextures.Empty();
			TempLandscape->RuntimeVirtualTextures.AddUnique(VirtualTextureManager->GetVirtualTexture());
		}
	}
	*/
}

void AOmegaActorEnvironment::Set_Preset(UOmegaEnvironmentPreset* Preset)
{
	if(Preset)
	{
		current_preset=Preset;
		current_preset->Local_Update(this);
	}
}

