// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaActors.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_ActorPreset.h"
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
class UOmegaBGM;
class UPostProcessComponent;
class UPCGGraphInterface;
class UAudioComponent;

#if ENGINE_MAJOR_VERSION==5
class UPCGComponent;
#endif


// Manages all environmental rendering components (sky, fog, atmosphere, clouds, post-process) in one place, with save binding and preset support.
UCLASS(DisplayName="Ω Environment")
class OMEGAGAMEFRAMEWORK_API AOmegaActorEnvironment : public AOmegaActorBASE, public IOmegaSaveInterface
{
	GENERATED_BODY()

	void L_PresetSave();
	void L_PresetLoad();

public:

	AOmegaActorEnvironment();

protected:

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

#if WITH_EDITOR
	virtual bool GetReferencedContentObjects(TArray<UObject*>& Objects) const override;
#endif

	// Override in Blueprint to return the virtual texture component used by this environment.
	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	URuntimeVirtualTextureComponent* GetVirtualTextureComponent();

	// Editor utility: quickly configures sky and atmosphere components from current settings.
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Environment",DisplayName="Quickset = Atmosphere") void Quickset_Atmosphere();
	// Editor utility: quickly configures the skybox mesh and material from current settings.
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Environment",DisplayName="Quickset = SKYBOX") void Quickset_Skybox();

	UFUNCTION()
	void AutosetVirtualTextureFromLandscape();
	// Captures current component states into the active preset asset and saves it to disk.
	UFUNCTION(BlueprintCallable,CallInEditor,Category="Environment")
	void SaveToPreset();

	// When true, the current preset is written to the save game automatically.
	UPROPERTY(EditAnywhere,Category="Environment")
	bool SaveCurrentPreset;

	// Named list collections available to Blueprint scripts on this environment actor.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Environment") FOmegaClassNamedLists NamedLists;
	// The environment preset currently applied to this actor.
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Preset")
	TScriptInterface<IDataInterface_Environment> current_preset;
	// When true, the preset cannot be changed at runtime via Set_Preset.
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Lock Preset?")
	bool lock_preset;
	// The save field key used to persist the active preset across sessions.
	UPROPERTY(EditAnywhere,Category="Environment",DisplayName="Preset Save Field")
	FName SaveField_Preset="Environment";
	// Applies the given environment preset, updating all managed components.
	UFUNCTION(BlueprintCallable,Category="Environment")
	void Set_Preset(TScriptInterface<IDataInterface_Environment> Preset);
	
	UFUNCTION(BlueprintCallable,Category="Environment",CallInEditor)
	void Refresh();
	// Returns the currently active environment preset.
	UFUNCTION(BlueprintCallable,Category="Environment")
	TScriptInterface<IDataInterface_Environment> Get_Preset() const {if(current_preset){return current_preset;} return nullptr;}

	// Default ambient sound played when the environment is active.
	UPROPERTY(EditAnywhere,Category="Environment")
	USoundBase* DefaultAmbiantSound;

	// Returns the BGM asset to play for this environment. Override in Blueprint for dynamic selection.
	UFUNCTION(BlueprintNativeEvent,Category="Environment")
	UOmegaBGM* GetEnvironmentBGM();
	// BGM asset played automatically when this environment becomes active.
	UPROPERTY(EditAnywhere,Category="Environment|BGM")
	UOmegaBGM* BGM_to_autoplay;
	// The BGM slot this environment's music occupies (allows layered music systems).
	UPROPERTY(EditAnywhere,Category="Environment|BGM")
	FGameplayTag BGM_Slot;

	// Root scene component that parents all environment sub-components.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) USceneComponent* EnvironmentRoot;
	// Sky light component providing ambient lighting from the sky.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) USkyLightComponent* SkyLight;
	// Directional light component representing the sun or moon.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UDirectionalLightComponent* DirectionalLight;
	UPROPERTY() UArrowComponent* DirectionalLight_Arrow;
	// Exponential height fog component for atmospheric depth.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment") UExponentialHeightFogComponent* Fog;
	// Skybox static mesh component for non-atmosphere sky rendering.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UStaticMeshComponent* SkyBox;
	// Sky atmosphere component for physically-based atmosphere rendering.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) USkyAtmosphereComponent* Atmosphere;
	// Volumetric cloud component for dynamic cloud rendering.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UVolumetricCloudComponent* Clouds;
	// Post-process component for global color grading and screen-space effects.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UPostProcessComponent* PostProcess;
	// Audio component for ambient environment sounds.
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Environment",AdvancedDisplay) UAudioComponent* Audio;

};



// Abstract inline script that can save and restore environment state when a preset is applied or saved.
UCLASS(Blueprintable,BlueprintType,EditInlineNew,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaEnvironmentPresetScript : public UObject
{
	GENERATED_BODY()

public:
	// Called in Blueprint when the environment's state is written into the preset.
	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	void OnSaved(AOmegaActorEnvironment* Actor);

	// Called in Blueprint when the preset is applied to the environment actor.
	UFUNCTION(BlueprintImplementableEvent,Category="Environment")
	void OnUpdated(AOmegaActorEnvironment* Actor) const;
};

USTRUCT(BlueprintType)
struct FOmegaEnvironmentConfig
{
	GENERATED_BODY()
	
	// When true, the sky light component is visible when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_SkyLight=true;
	// When true, the directional light component is visible when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_SunLight=true;
	// When true, the exponential height fog component is visible when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Fog=true;
	// When true, the sky atmosphere component is visible when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Atmosphere=true;
	// When true, the volumetric cloud component is visible when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Clouds=true;
	// When true, the skybox mesh component is visible when this preset is applied.
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components") bool Use_Skybox=false;
};

UINTERFACE(MinimalAPI, DisplayName="♎Data🔴 - Input Action") class UDataInterface_Environment : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_Environment
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent,Category="♎I|☁️Environment",DisplayName="Environment - GetConfig")
	FOmegaEnvironmentConfig Environment_GetConfig(AOmegaActorEnvironment* Actor);
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|☁️Environment",DisplayName="Environment - On Init")
	int32 Environment_OnInit(AOmegaActorEnvironment* Actor);

	UFUNCTION(BlueprintNativeEvent,Category="♎I|☁️Environment",DisplayName="Environment - On BeginPlay")
	int32 Environment_OnTagEvent(AOmegaActorEnvironment* Actor, FGameplayTag Event);
	
	UFUNCTION(BlueprintNativeEvent,Category="♎I|☁️Environment",DisplayName="Environment - Saved Changes from Actor")
	int32 Environment_OnSavedFromActor(AOmegaActorEnvironment* Actor);
};


// A data asset that enables/disables specific environment components and runs inline scripts when applied to an AOmegaActorEnvironment.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaEnvironmentPreset : public UOmegaDataAsset, public IDataInterface_ActorPreset, public IDataInterface_Environment
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Environment",meta=(ShowOnlyInnerProperties))
	FOmegaEnvironmentConfig EnvironmentConfig;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Environment")
	TArray<UOmegaEnvironmentPreset*> InheritedPresetScripts;
	// Inline scripts executed when this preset is applied to or saved from an environment actor.
	UPROPERTY(Instanced,EditAnywhere,BlueprintReadWrite,Category="Environment")
	TArray<UOmegaEnvironmentPresetScript*> Scripts;

	TArray<UOmegaEnvironmentPresetScript*> L_GetScripts() const;
	
	UFUNCTION()
	void Local_Update(AOmegaActorEnvironment* EnvironmentActor);
	
	virtual void ActorPreset_GetConfig_Implementation(TSubclassOf<AActor>& ActorClass, bool& bPreviewActor, bool& bAllowWorldDrop, bool& bPreviewThumbnailFromActor) override;
	virtual bool ActorPreset_PreviewConstruct_Implementation(AActor* Actor) override;
	
	virtual FOmegaEnvironmentConfig Environment_GetConfig_Implementation(AOmegaActorEnvironment* Actor) override { return EnvironmentConfig;};
	virtual int32 Environment_OnInit_Implementation(AOmegaActorEnvironment* Actor) override;
	virtual int32 Environment_OnSavedFromActor_Implementation(AOmegaActorEnvironment* Actor) override;
};
