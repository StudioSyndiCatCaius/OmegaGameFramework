// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Environment.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "PCGComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/VolumetricCloudComponent.h"
#include "Engine/TextureCube.h"
#include "PCGGraph.h"
#include "Async/TaskGraphInterfaces.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "Subsystems/OmegaSubsystem_BGM.h"


class UOmegaBGMSubsystem;

void AOmegaActorEnvironment::L_PresetSave()
{
	if(GetGameInstance() && current_preset)
	{
		GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->SetSoftProperty_DataAsset(SaveField_Preset.ToString(),current_preset,false);
	}
}

void AOmegaActorEnvironment::L_PresetLoad()
{
	if(UOmegaEnvironmentPreset* p=Cast<UOmegaEnvironmentPreset>(
			GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSoftProperty_DataAsset(SaveField_Preset.ToString(),false)))
	{
		Set_Preset(p);
	}
}

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
	Audio= CreateOptionalDefaultSubobject<UAudioComponent>("Audio");
	if(Audio) { Audio->SetupAttachment(EnvironmentRoot); }
	//VirtualTextureComponent= CreateOptionalDefaultSubobject<URuntimeVirtualTextureComponent>("VirtualTexture");
	//if(VirtualTextureComponent) { VirtualTextureComponent->SetupAttachment(EnvironmentRoot); }
	
	PCGComponent= CreateOptionalDefaultSubobject<UPCGComponent>("PCG");

	if(SkyBox)
	{
		SkyBox->SetCollisionResponseToAllChannels(ECR_Ignore);
		SkyBox->SetCastShadow(false);
	}

	PostProcess->Settings.bOverride_BloomIntensity=true;
	PostProcess->Settings.BloomIntensity=0.0;
	PostProcess->Settings.bOverride_AutoExposureMinBrightness=true;
	PostProcess->Settings.bOverride_AutoExposureMaxBrightness=true;
	PostProcess->Settings.AutoExposureMinBrightness=0.2;
	PostProcess->Settings.AutoExposureMaxBrightness=1;
	PostProcess->Settings.bOverride_AmbientCubemapIntensity=true;
	PostProcess->Settings.AmbientCubemapIntensity=0.15;
	if(UTextureCube* c =LoadObject<UTextureCube>(this,TEXT("/Engine/EngineResources/GrayLightTextureCube.GrayLightTextureCube")))
	{
		PostProcess->Settings.AmbientCubemap=c;
	}
}

void AOmegaActorEnvironment::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(SkyLight)
	{
		SkyLight->RecaptureSky();
	}
	if(current_preset && !lock_preset)
	{
		for(auto* TempScript : current_preset->Scripts)
		{
			if(TempScript)
			{
				TempScript->OnUpdated(this);
			}
		}
	}
	if(DefaultAmbiantSound && Audio)
	{
		Audio->SetSound(DefaultAmbiantSound);
	}
	if(PCGComponent && PCGAsset)
	{
		PCGComponent->SetGraph(PCGAsset);
		//PCGComponent->Cleanup();
		//PCGComponent->Generate();
	}
}

void AOmegaActorEnvironment::BeginPlay()
{
	if(BGM_to_autoplay)
	{
		GetWorld()->GetSubsystem<UOmegaBGMSubsystem>()->PlayBGM(BGM_to_autoplay,BGM_Slot,false,true);
	}
	if(SaveField_Preset.IsValid() && SaveCurrentPreset)
	{
		L_PresetLoad();
	}
	Super::BeginPlay();
}

void AOmegaActorEnvironment::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::LevelTransition)
	{
		if(SaveField_Preset.IsValid() && current_preset && SaveCurrentPreset)
        {
        	L_PresetSave();
        }
	}
	
	Super::EndPlay(EndPlayReason);
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

void AOmegaActorEnvironment::SaveToPreset()
{
	if(current_preset)
	{
		for(auto* TempScript : current_preset->Scripts)
		{
			if(TempScript)
			{
				TempScript->OnSaved(this);
			}
		}
	}
}

void AOmegaActorEnvironment::Set_Preset(UOmegaEnvironmentPreset* Preset)
{
	if(Preset)
	{
		current_preset=Preset;
		current_preset->Local_Update(this);
	}
}

void UOmegaEnvironmentPreset::Local_Update(AOmegaActorEnvironment* EnvironmentActor)
{
	if(EnvironmentActor)
	{
		for(auto* Script: Scripts)
		{
			L_SetCompVis(EnvironmentActor->SkyLight,Use_SkyLight);
			L_SetCompVis(EnvironmentActor->DirectionalLight,Use_SunLight);
			L_SetCompVis(EnvironmentActor->Fog,Use_Fog);
			L_SetCompVis(EnvironmentActor->Atmosphere,Use_Atmosphere);
			L_SetCompVis(EnvironmentActor->Clouds,Use_Clouds);
			L_SetCompVis(EnvironmentActor->SkyBox,Use_Skybox);
			if(Script) {Script->OnUpdated(EnvironmentActor);}
		}
	}
}

UOmegaBGM* AOmegaActorEnvironment::GetEnvironmentBGM_Implementation()
{
	if(BGM_to_autoplay) {return BGM_to_autoplay;} return nullptr;
}

#if WITH_EDITOR
bool AOmegaActorEnvironment::GetReferencedContentObjects(TArray<UObject*>& Objects) const
{
	Super::GetReferencedContentObjects(Objects);
	
	if (PCGComponent)
	{
		if (UPCGGraph* PCGGraph = PCGComponent->GetGraph())
		{
			Objects.Add(PCGGraph);
		}
	}
	return true;
}
#endif // WITH_EDITOR