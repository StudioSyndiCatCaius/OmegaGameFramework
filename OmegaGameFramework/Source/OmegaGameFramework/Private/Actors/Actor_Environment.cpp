// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Environment.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/SkyAtmosphereComponent.h"

#if ENGINE_MAJOR_VERSION ==5

#include "PCGComponent.h"
#include "PCGGraph.h"

#endif

#include "Components/ArrowComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/VolumetricCloudComponent.h"
#include "Engine/TextureCube.h"
#include "Async/TaskGraphInterfaces.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "Functions/F_BGM.h"
#include "Functions/F_GlobalParam.h"
#include "Subsystems/Subsystem_World.h"


class UOmegaBGMSubsystem;

void AOmegaActorEnvironment::L_PresetSave()
{
	if(GetGameInstance() && current_preset)
	{
		UOmegaFunctions_GlobalVars::SetGlobalVariable_DataAsset(this,EOmegaGlobalParamTarget::SAVE_GAME,SaveField_Preset,current_preset);
	}
}

void AOmegaActorEnvironment::L_PresetLoad()
{
	if(UOmegaEnvironmentPreset* p=Cast<UOmegaEnvironmentPreset>(
			UOmegaFunctions_GlobalVars::GetGlobalVariable_DataAsset(this,EOmegaGlobalParamTarget::SAVE_GAME,SaveField_Preset)))
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
		DirectionalLight->SetRelativeLocation(FVector(0,0,50));
		DirectionalLight->SetRelativeRotation(FRotator(-45,-45,0.0));
	}
	DirectionalLight_Arrow = CreateOptionalDefaultSubobject<UArrowComponent>("DirectionalLight_Arrow");
	if(DirectionalLight_Arrow) { DirectionalLight_Arrow->SetupAttachment(DirectionalLight); }
	Fog= CreateOptionalDefaultSubobject<UExponentialHeightFogComponent>("Fog");
	if(Fog)
	{
		Fog->SetupAttachment(EnvironmentRoot);
		Fog->FogInscatteringLuminance=FLinearColor(0.15,0.3,0.6,1);
	}
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
	
#if ENGINE_MAJOR_VERSION ==5
	//PCGComponent= CreateOptionalDefaultSubobject<UPCGComponent>("PCG");
#endif
	

	if(SkyBox)
	{
		SkyBox->SetCollisionResponseToAllChannels(ECR_Ignore);
		SkyBox->SetCastShadow(false);
		if(UStaticMesh* _mesh=LoadObject<UStaticMesh>(this, TEXT("/OmegaGameFramework/Meshes/nature/sm_omega_Skybox_Cube.sm_omega_Skybox_Cube")))
		{
			SkyBox->SetStaticMesh(_mesh);
		}
		if (UMaterialInstance* _mat=LoadObject<UMaterialInstance>(this, TEXT("/OmegaGameFramework/Materials/Instances/HDRI/mi_Omega_Hdri_day.mi_Omega_Hdri_day")))
		{
			SkyBox->SetMaterial(0, _mat);
		}
		SkyBox->SetVisibility(false);
		SkyBox->SetComponentTickEnabled(false);
	}

	if (PostProcess)
	{
		PostProcess->Settings.bOverride_BloomIntensity=true;
		PostProcess->Settings.BloomIntensity=0.0;
		PostProcess->Settings.bOverride_AutoExposureMinBrightness=true;
		PostProcess->Settings.bOverride_AutoExposureMaxBrightness=true;
		PostProcess->Settings.AutoExposureMinBrightness=0.2;
		PostProcess->Settings.AutoExposureMaxBrightness=1;
		PostProcess->Settings.bOverride_AmbientCubemapIntensity=true;
		PostProcess->Settings.AmbientCubemapIntensity=0.15;
	}
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
#if ENGINE_MAJOR_VERSION ==5
	/*
	if(PCGComponent && PCGAsset)
	{
		PCGComponent->SetGraph(PCGAsset);
		//PCGComponent->Cleanup();
		//PCGComponent->Generate();
	}
	*/
#endif
	
}

void AOmegaActorEnvironment::BeginPlay()
{
	if(BGM_to_autoplay)
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle,FTimerDelegate::CreateLambda([this]()
		{
			UOmegaFunctions_BGM::Play(this,BGM_to_autoplay,BGM_Slot,true);
		}),0.1,false);
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

void L_SetCompValid(USceneComponent* Comp, bool Val)
{
	if(Comp)
	{
		Comp->SetVisibility(Val);
		Comp->SetComponentTickEnabled(Val);
	}
}

void AOmegaActorEnvironment::Quickset_Atmosphere()
{
	L_SetCompValid(SkyBox,false);
	L_SetCompValid(Atmosphere,true);
	L_SetCompValid(Clouds,true);
}

void AOmegaActorEnvironment::Quickset_Skybox()
{
	L_SetCompValid(SkyBox,true);
	L_SetCompValid(Atmosphere,false);
	L_SetCompValid(Clouds,false);
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
	
#if ENGINE_MAJOR_VERSION ==5
	/*
	if (PCGComponent)
	{
		if (UPCGGraph* PCGGraph = PCGComponent->GetGraph())
		{
			Objects.Add(PCGGraph);
		}
	}
	*/
#endif
	
	return true;
}
#endif // WITH_EDITOR