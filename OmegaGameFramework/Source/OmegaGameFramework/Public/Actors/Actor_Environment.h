// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Landscape.h"
#include "Actor_GameplayCue.h"
#include "PCGComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/VolumetricCloudComponent.h"
#include "GameFramework/Actor.h"
#include "Subsystems/OmegaSubsystem_BGM.h"
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
	virtual void BeginPlay() override;

public:
	//~ Begin AActor Interface
#if WITH_EDITOR
	virtual bool GetReferencedContentObjects(TArray<UObject*>& Objects) const override;
#endif // WITH_EDITOR
	//~ End AActor Interface


	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) USceneComponent* EnvironmentRoot;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) USkyLightComponent* SkyLight;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UDirectionalLightComponent* DirectionalLight;
	UPROPERTY() UArrowComponent* DirectionalLight_Arrow;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UExponentialHeightFogComponent* Fog;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UStaticMeshComponent* SkyBox;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) USkyAtmosphereComponent* Atmosphere;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UVolumetricCloudComponent* Clouds;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UPostProcessComponent* PostProcess;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UAudioComponent* Audio;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UPCGComponent* PCGComponent;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	URuntimeVirtualTextureComponent* GetVirtualTextureComponent();

	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|Environment") TArray<ALandscape*> Landscapes;
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Environment")
	void AutosetVirtualTextureFromLandscape();
	//UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Omega|Environment") TArray<ALandscape*> Landscapes;
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Environment")
	void SaveToPreset();

	UPROPERTY(EditAnywhere,Category="Environment")
	UPCGGraphInterface* PCGAsset;

	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Preset")
	UOmegaEnvironmentPreset* current_preset;
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Preset")
	bool lock_preset;
	UFUNCTION(BlueprintCallable,Category="Environment")
	void Set_Preset(UOmegaEnvironmentPreset* Preset);
	UFUNCTION(BlueprintCallable,Category="Environment")
	UOmegaEnvironmentPreset* Get_Preset(UOmegaEnvironmentPreset* Preset) const {if(current_preset){return current_preset;} return nullptr;}

	UPROPERTY(EditAnywhere,Category="Environment")
	USoundBase* DefaultAmbiantSound;

	UFUNCTION(BlueprintNativeEvent,Category="Environment")
	UOmegaBGM* GetEnvironmentBGM();
	UPROPERTY(EditAnywhere,Category="Environment|BGM")
	UOmegaBGM* BGM_to_autoplay;
	UPROPERTY(EditAnywhere,Category="Environment|BGM")
	FGameplayTag BGM_Slot;
};



UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaEnvironmentPresetScript : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	void OnSaved(AOmegaActorEnvironment* Actor);
	
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
