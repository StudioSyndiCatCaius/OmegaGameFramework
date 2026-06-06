// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_GameplayCue.h"
#include "GameFramework/Actor.h"
#include "Functions/F_ScriptedEffects.h"
#include "Actor_Bullet.generated.h"

struct FOmegaGameplayCueConfig;
class USphereComponent;
class UCombatantComponent;
class UProjectileMovementComponent;
class UBillboardComponent;
class AOmegaGameplayCue;

// A projectile actor that travels via UProjectileMovementComponent and triggers impact effects on overlap or hit.
UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaBulletActor : public AActor
{
	GENERATED_BODY()

public:

	AOmegaBulletActor();

protected:
	virtual void BeginPlay() override;


	UFUNCTION() void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION() void OnSphereHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void Native_Impact(AActor* ImpactedActor, FHitResult HitResult);

	// Manually triggers the bullet's impact logic against the given actor, bypassing collision detection.
	UFUNCTION(BlueprintCallable, Category="Bullet", DisplayName="Trigget Impact")
	void TriggerImpact(AActor* ImpactedActor, FHitResult HitResult);

	// Called in Blueprint when the bullet impacts something; provides the hit actor and its combatant (if any).
	UFUNCTION(BlueprintImplementableEvent, Category="Bullet")
	void OnImpact(AActor* Actor, UCombatantComponent* Combatant);

public:
	// The combatant that fired this bullet, used when applying damage effects on impact.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UCombatantComponent* InstigatorCombatant=nullptr;

	// Sphere collision component used for overlap and hit detection.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereComponent;

	// Editor billboard to show the bullet's spawn point in the viewport.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UBillboardComponent* BillboardComponent;

	// Drives the bullet's velocity and trajectory in the world.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* ProjectileComponent;

	// Cues
	int32 impactCount;

	// When true, the bullet triggers its impact logic on physics hit events.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	bool bImpactOnHit=true;
	// When true, the bullet triggers its impact logic on overlap events.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	bool bImpactOnOverlap=false;

	// Number of impacts after which the bullet destroys itself. Set to 0 for unlimited.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	int32 ImpactDestroy=1;

	// Gameplay cue spawned when the bullet is created (e.g. muzzle flash, trail).
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	FOmegaGameplayCueConfig CueOnSpawn;

	// Gameplay cue spawned at the point of impact (e.g. hit spark, explosion).
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	FOmegaGameplayCueConfig CueOnImpact;

	// Scripted effects (damage, attribute changes, etc.) applied to the target on impact.
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Bullet")
	FOmegaCustomScriptedEffects ImpactEffects;

private:
	UFUNCTION()
	void local_spawnCue(FOmegaGameplayCueConfig cue, FHitResult HitResult);

	UCombatantComponent* local_getCombatant(AActor* actor);

	bool bHandlingImpact = false;
};

// Blueprint function library for spawning bullet actors.
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaBulletFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Spawns a bullet of the given class at Origin with the supplied effects and optional instigating combatant.
	UFUNCTION(BlueprintCallable, Category="Omega|Cues", meta=(WorldContext="WorldContextObject"))
	static void SpawnBullet(UObject* WorldContextObject, TSubclassOf<AOmegaBulletActor> Bullet, FTransform Origin, FOmegaCustomScriptedEffects Effects, UCombatantComponent* Instigator=nullptr);
};
