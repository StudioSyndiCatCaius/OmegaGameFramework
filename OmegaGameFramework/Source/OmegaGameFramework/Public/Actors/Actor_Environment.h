// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Landscape.h"
#include "OmegaGameplayCue.h"
#include "Components/ArrowComponent.h"
#include "Components/VolumetricCloudComponent.h"
#include "GameFramework/Actor.h"
#include "Actor_Environment.generated.h"

UCLASS(DisplayName="OmegaActor: Environment")
class OMEGAGAMEFRAMEWORK_API AOmegaActorEnvironment : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AOmegaActorEnvironment();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	// Called every frame

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") USceneComponent* EnvironmentRoot;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") USkyLightComponent* SkyLight;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") UDirectionalLightComponent* DirectionalLight;
	UPROPERTY() UArrowComponent* DirectionalLight_Arrow;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") UExponentialHeightFogComponent* Fog;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") UStaticMeshComponent* SkyBox;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") USkyAtmosphereComponent* Atmosphere;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") UVolumetricCloudComponent* Clouds;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environemnt") UPostProcessComponent* PostProcess;

	
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	URuntimeVirtualTextureComponent* GetVirtualTextureComponent();

	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|Environment") TArray<ALandscape*> Landscapes;
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Environemnt")
	void AutosetVirtualTextureFromLandscape();

	UPROPERTY(EditAnywhere,Category="Environemnt",DisplayName="Preset")
	UOmegaEnvironmentPreset* current_preset;
	UFUNCTION(BlueprintCallable,Category="Environemnt")
	void Set_Preset(UOmegaEnvironmentPreset* Preset);
	UFUNCTION(BlueprintCallable,Category="Environemnt")
	UOmegaEnvironmentPreset* Get_Preset(UOmegaEnvironmentPreset* Preset) const {if(current_preset){return current_preset;} return nullptr;}
	
};



UCLASS(Blueprintable,BlueprintType,EditInlineNew,Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaEnvironmentPresetScript : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	void OnUpdated(AOmegaActorEnvironment* Actor) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaEnvironmentPreset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Instanced,EditAnywhere,BlueprintReadWrite,Category="Environment")
	TArray<UOmegaEnvironmentPresetScript*> Scripts;

	UFUNCTION()
	void Local_Update(AOmegaActorEnvironment* EnvironmentActor)
	{
		if(EnvironmentActor)
		{
			for(auto* Script: Scripts)
			{
				if(Script) {Script->OnUpdated(EnvironmentActor);}
			}
		}
	}
};
