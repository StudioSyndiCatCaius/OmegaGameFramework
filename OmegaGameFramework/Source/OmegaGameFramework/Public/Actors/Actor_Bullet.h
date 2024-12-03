// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Functions/OmegaFunctions_ScriptedEffects.h"
#include "Actors/Actor_GameplayCue.h"
#include "Actor_Bullet.generated.h"

class USphereComponent;
class UCombatantComponent;
class UProjectileMovementComponent;
class UBillboardComponent;

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaBulletActor : public AActor
{
	GENERATED_BODY()

public:    
	AOmegaBulletActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION(BlueprintCallable, Category="Bullet", DisplayName="Trigget Impact")
	void TriggerImpact(AActor* ImpactedActor);

	UFUNCTION(BlueprintImplementableEvent, Category="Bullet")
	void OnImpact(AActor* Actor, UCombatantComponent* Combatant);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UCombatantComponent* InstigatorCombatant=nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UBillboardComponent* BillboardComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* ProjectileComponent;

	// Cues

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	TSubclassOf<AOmegaGameplayCue> CueOnSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	TSubclassOf<AOmegaGameplayCue> CueOnImpact;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	FOmegaCustomScriptedEffects ImpactEffects;
	
private:
	UFUNCTION()
	void local_spawnCue(TSubclassOf<AOmegaGameplayCue> cue);
	
	UCombatantComponent* local_getCombatant(AActor* actor);
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBulletFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Omega|Cues", meta=(WorldContext="WorldContextObject"))
	static void SpawnBullet(UObject* WorldContextObject, TSubclassOf<AOmegaBulletActor> Bullet, FTransform Origin, FOmegaCustomScriptedEffects Effects, UCombatantComponent* Instigator=nullptr);
};