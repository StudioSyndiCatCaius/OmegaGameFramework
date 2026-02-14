// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Landscape.h"
#include "GameFramework/Actor.h"
#include "Misc/GeneralDataObject.h"
#include "Subsystems/Subsystem_Save.h"
#include "Types/Struct_CustomNamedList.h"
#include "Actor_Environment.generated.h"

class UArrowComponent;
class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class USkyAtmosphereComponent;
class USkyLightComponent;
class UVolumetricCloudComponent;
class UPCGComponent;
class UOmegaBGM;
class UPostProcessComponent;
class UPCGGraphInterface;

UCLASS(DisplayName="Ω Environment")
class OMEGAGAMEFRAMEWORK_API AOmegaActorEnvironment : public AActor, public IOmegaSaveInterface
{
	GENERATED_BODY()

	void L_PresetSave();
	void L_PresetLoad();
	
public:
	// Sets default values for this actor's properties
	AOmegaActorEnvironment();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
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
	bool SaveCurrentPreset;
	
	UPROPERTY(EditAnywhere,Category="Environment")
	UPCGGraphInterface* PCGAsset;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Environment") FOmegaClassNamedLists NamedLists;
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Preset")
	UOmegaEnvironmentPreset* current_preset;
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Lock Preset?")
	bool lock_preset;
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Preset Save Field")
	FName SaveField_Preset="Environment";
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
class OMEGAGAMEFRAMEWORK_API UOmegaEnvironmentPreset : public UOmegaDataAsset
{
	GENERATED_BODY()
	

	void L_SetCompVis(USceneComponent* comp, bool b)
	{
		if(comp)
		{
			comp->SetVisibility(b);
		}
	};
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_SkyLight=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_SunLight=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Fog=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Atmosphere=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Clouds=true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Skybox=false;
	UPROPERTY(Instanced,EditAnywhere,BlueprintReadWrite,Category="Environment")
	TArray<UOmegaEnvironmentPresetScript*> Scripts;
	
	UFUNCTION()
	void Local_Update(AOmegaActorEnvironment* EnvironmentActor);
};
