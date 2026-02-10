// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "Engine/HitResult.h"
#include "GameFramework/Actor.h"
#include "Interfaces/I_Common.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Subsystems/WorldSubsystem.h"
#include "Actor_GameplayCue.generated.h"

class UPostProcessComponent;
class UNiagaraComponent;
class UAudioComponent;
class UCameraShakeSourceComponent;

UCLASS(DisplayName="Ω Cue")
class OMEGAGAMEFRAMEWORK_API AOmegaGameplayCue : public AActor, public IGameplayTagsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOmegaGameplayCue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnFinishParticle(UNiagaraComponent* Comp);
	UFUNCTION()
	void TryFinish();
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//If true, will destroy the cue automatically when no sound, particle, or camerashake is playing.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	bool bAttemptAutocomplete=true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	TArray<UNiagaraSystem*> NiagaraParticles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	TArray<USoundBase*> Sounds;

	UPROPERTY(BlueprintReadOnly, Category="Cue")
	FHitResult HitData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UNiagaraComponent* Niagara;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UAudioComponent* Audio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UPostProcessComponent* PostProcess;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cue")
	UCameraShakeSourceComponent* CameraShake;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayCueFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Omega|Cues", meta=(WorldContext="WorldContextObject"))
	static void PlayGameplayCue(UObject* WorldContextObject, TSubclassOf<AOmegaGameplayCue> Cue, FTransform Origin, FHitResult Hit, AActor* ActorOrigin=nullptr);
};

UCLASS(DisplayName="Omega Subsystem: Cues")
class OMEGAGAMEFRAMEWORK_API UOmegaGameplayCueSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<AOmegaGameplayCue*> ActiveCues;
	
public:
	UFUNCTION(BlueprintCallable, Category="Omega|Cues", meta=(WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	AOmegaGameplayCue* PlayGameplayCue(TSubclassOf<AOmegaGameplayCue> Cue, FTransform Origin, FHitResult Hit, AActor* ActorOrigin=nullptr);
};