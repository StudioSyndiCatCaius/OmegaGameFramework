// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_GlobalParam.h"
#include "GameFramework/Actor.h"
#include "Actor_RandomSpawnable.generated.h"


USTRUCT(BlueprintType)
struct FOmegaRandomSpawnableConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	float SpawnChance=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spawnable")
	TMap<TSubclassOf<AActor>,float> SpawnableActors;
	
	TSubclassOf<AActor> RandomizeActorToSpawn(int32 seed);
	
};


UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmega_RandomSpawnable : public AActor
{
	GENERATED_BODY()



public:
	
	AOmega_RandomSpawnable();
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Spawnable")
	UChildActorComponent* ChildActorComponent;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawnable")
	FOmegaRandomSpawnableConfig SpawnableConfig;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawnable")
	TEnumAsByte<EOmegaGlobalParamTarget> Seed_GlobalParamSource;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawnable")
	FName Seed_GlobalParamName;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawnable")
	int32 Preview;
};
