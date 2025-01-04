// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "Component_GroupedActorSpawner.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGroupedActorSpawned, UGroupedActorSpawnerComponent*, Component, AActor*, SpawnedActor);

UCLASS(EditInlineNew,Blueprintable,BlueprintType, Abstract, Const, meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UGroupedActorSpawnerPossible : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Grouped Actor Spawner")
	bool OnActorSpawned(UGroupedActorSpawnerComponent* Component, AActor* Actor) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Grouped Actor Spawner")
	TSubclassOf<AActor> GetActorClass(UGroupedActorSpawnerComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Grouped Actor Spawner")
	bool CanSpawn(UGroupedActorSpawnerComponent* Component, int32 interation) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Grouped Actor Spawner")
	int32 GetSpawnInterationCount(UGroupedActorSpawnerComponent* Component) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Grouped Actor Spawner")
	FTransform GetLocalSpawnTransform(UGroupedActorSpawnerComponent* Component, int32 spawn_index, float spawn_ratio) const;
	
};


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UGroupedActorSpawnerComponent : public USceneComponent
{
	GENERATED_BODY()


	UPROPERTY() TArray<UChildActorComponent*> ref_childActors;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
public:

	UPROPERTY(BlueprintAssignable)
	FOnGroupedActorSpawned OnGroupedActorSpawned;
	
	UFUNCTION() UChildActorComponent* Local_GetChildACtorComp(int32 index);
	UFUNCTION() UChildActorComponent* Local_GetFirstEmptyChildACtorComp(int32& out_index);

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grouped Actor Spawner")
	bool bAutoSpawnOnBeginPlay;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Grouped Actor Spawner")
	bool bAutoShuffleSpawnOrder;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Instanced,Category="Grouped Actor Spawner")
	TArray<UGroupedActorSpawnerPossible*> Possibles;

	UFUNCTION(BlueprintCallable,Category="Grouped Actor Spawner")
	void SpawnAllPossibles(bool bShuffleSpawnOrder);
	
	UFUNCTION(BlueprintCallable,Category="Grouped Actor Spawner")
	void DestroyAllSpawnedActors();
};
