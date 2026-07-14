// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DA_DemoEnvironment.h"

#include "UObject/ConstructorHelpers.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/StaticMeshComponent.h"

UOAsset_EasyEnvironment::UOAsset_EasyEnvironment()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SkyboxMeshFinder(TEXT("/OmegaGameFramework/Meshes/nature/sm_omega_Skybox_Cube.sm_omega_Skybox_Cube"));
	if (SkyboxMeshFinder.Succeeded()) SkyMesh = SkyboxMeshFinder.Object;
}

FOmegaEnvironmentConfig UOAsset_EasyEnvironment::Environment_GetConfig_Implementation(AOmegaActorEnvironment* Actor)
{
	FOmegaEnvironmentConfig out;
	out.Use_Clouds=false;
	out.Use_Atmosphere=false;
	out.Use_Skybox=true;
	return out;
}

int32 UOAsset_EasyEnvironment::Environment_OnInit_Implementation(AOmegaActorEnvironment* Actor)
{
	if (Actor)
	{
		if (Actor->DirectionalLight)
		{
			Actor->DirectionalLight->SetLightColor(SunColor);
			Actor->DirectionalLight->SetIntensity(SunIntensity);
			Actor->DirectionalLight->SetWorldRotation(SunRotation);
		}
		if (Actor->SkyLight)
		{
			Actor->SkyLight->SetLightColor(SkyColor);
			Actor->SkyLight->SetIntensity(SkyIntensity);
		}
		if (Actor->SkyBox)
		{
			if (SkyMesh) { Actor->SkyBox->SetStaticMesh(SkyMesh); }
			if (SkyMaterial) { Actor->SkyBox->SetMaterial(0, SkyMaterial); }
		}
		if (Actor->Fog)
		{
			Actor->Fog->FogInscatteringLuminance = FogColor;
			Actor->Fog->SetFogDensity(FogDensity);
			Actor->Fog->SetFogHeightFalloff(FogFalloff);
		}
	}
	return 0;
}
