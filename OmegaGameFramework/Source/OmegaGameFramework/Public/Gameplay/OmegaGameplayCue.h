// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/GameplayTagsInterface.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaGameplayCue.generated.h"

class UPostProcessComponent;
class UNiagaraComponent;
class UAudioComponent;
class UCameraShakeSourceComponent;

UCLASS()
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
	static void PlayGameplayCue(UObject* WorldContextObject, TSubclassOf<AOmegaGameplayCue> Cue, FTransform Origin, AActor* ActorOrigin=nullptr);
};