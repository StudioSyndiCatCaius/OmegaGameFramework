// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Spawnable.generated.h"

UCLASS(Blueprintable,BlueprintType,Const,meta=(ShowWorldContextPin),EditInlineNew,CollapseCategories,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaActorSpawnableModifer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent,Category="Spawnable")
	void OnActorSetup(AActor* Actor, AOmegaActorSpawnable* Spawnable) const;

	UFUNCTION(BlueprintNativeEvent,Category="Spawnable")
	void OnActorSpawned(AActor* Actor, AOmegaActorSpawnable* Spawnable) const;
};


UCLASS(Blueprintable,BlueprintType,CollapseCategories,EditInlineNew,Const,Abstract,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaActorSpawnableScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent,Category="Spawnable")
	AActor* AttemptSpawn(AOmegaActorSpawnable* OwningActor) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorSpawnableScript_Simple : public UOmegaActorSpawnableScript
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Category="Spawnable")
	TArray<TSoftClassPtr<AActor>> Possibles;
	
	virtual AActor* AttemptSpawn_Implementation(AOmegaActorSpawnable* OwningActor) const override;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaActorSpawnable : public AActor
{
	GENERATED_BODY()

	UPROPERTY() AActor* REF_linkedActor=nullptr;

public:
	AOmegaActorSpawnable();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Spawnable")
	UOmegaActorSpawnableScript* Script;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	float SpawnChance=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	bool Autospawn;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Spawnable")
	TArray<UOmegaActorSpawnableModifer*> Modifiers;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	ESpawnActorCollisionHandlingMethod CollisionMethod;
	
	UFUNCTION(BlueprintCallable,Category="Spawnable")
	bool AttemptSpawn(bool bForceRespawn,AActor*& Actor);
	
	UFUNCTION(BlueprintPure,Category="Spawnable",DisplayName="Is Linked Actor Alive?")
	bool LinkedActor_IsAlive() const ;
	UFUNCTION(BlueprintPure,Category="Spawnable",DisplayName="Get Linked Actor")
	AActor* LinkedActor_Get() const {return REF_linkedActor;};
};
