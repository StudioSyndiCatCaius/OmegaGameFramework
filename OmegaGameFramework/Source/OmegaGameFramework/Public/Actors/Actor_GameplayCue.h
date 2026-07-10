// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Subsystems/WorldSubsystem.h"
#include "Actor_GameplayCue.generated.h"

class UNiagaraSystem;
class UPostProcessComponent;
class UNiagaraComponent;
class UAudioComponent;
class UCameraShakeSourceComponent;

// Bundles a cue class with optional sound and particle overrides for spawning a gameplay cue from Blueprint.
USTRUCT(BlueprintType)
struct FOmegaGameplayCueConfig
{
	GENERATED_BODY()

	// The cue actor class to spawn.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue") TSubclassOf<AOmegaGameplayCue> CueClass=nullptr;
	// Optional sound that replaces the cue's default sound when set.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue") TObjectPtr<USoundBase> OverrideSound;
	// Optional Niagara system that replaces the cue's default particle effect when set.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue") TObjectPtr<UNiagaraSystem> OverrideNiagara;

};

// A transient actor that plays a set of particles, sounds, and/or a camera shake, then destroys itself when all effects finish.
UCLASS(DisplayName="Ω Cue")
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayCue : public AActor
{
	GENERATED_BODY()
protected:
	AOmegaGameplayCue();
	virtual void BeginPlay() override;

	UFUNCTION() void OnFinishParticle(UNiagaraComponent* Comp);
	UFUNCTION() void TryFinish();
public:
	virtual void Tick(float DeltaTime) override;

	// When true, the cue destroys itself automatically once all sounds, particles, and camera shakes finish.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	bool bAttemptAutocomplete=true;

	// Niagara systems spawned as particles when the cue plays.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	TArray<UNiagaraSystem*> NiagaraParticles;
	// Sound assets played when the cue plays.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	TArray<USoundBase*> Sounds;

	// The hit result at the cue's spawn location, forwarded from the caller.
	UPROPERTY(BlueprintReadOnly, Category="Cue")
	FHitResult HitData;

	// Active Niagara component used by this cue.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UNiagaraComponent* Niagara;
	// Active audio component used by this cue.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UAudioComponent* Audio;
	// Post-process component applied during this cue's lifetime.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UPostProcessComponent* PostProcess;
	// Camera shake source component triggered when this cue plays.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UCameraShakeSourceComponent* CameraShake;
};

// Blueprint function library for spawning gameplay cue actors in the world.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayCueFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Spawns a gameplay cue at Origin with an optional hit result and attachment target.
	UFUNCTION(BlueprintCallable, Category="Omega|Cues", meta=(WorldContext="WorldContextObject",AdvancedDisplay="AttachComponent,AttachRules,Hit"))
	static AOmegaGameplayCue* PlayGameplayCue(UObject* WorldContextObject, TSubclassOf<AOmegaGameplayCue> Cue,
		FTransform Origin, FHitResult Hit, USceneComponent* AttachComponent=nullptr,EAttachmentRule AttachRules=EAttachmentRule::SnapToTarget);

	// Spawns a gameplay cue from a config struct (class + optional overrides) at Origin.
	UFUNCTION(BlueprintCallable, Category="Omega|Cues", meta=(WorldContext="WorldContextObject",AdvancedDisplay="AttachComponent,AttachRules,Hit"))
	static AOmegaGameplayCue* PlayGameplayCue_FromConfig(UObject* WorldContextObject, FOmegaGameplayCueConfig Cue,
		FTransform Origin, FHitResult Hit, USceneComponent* AttachComponent=nullptr,EAttachmentRule AttachRules=EAttachmentRule::SnapToTarget);
};
