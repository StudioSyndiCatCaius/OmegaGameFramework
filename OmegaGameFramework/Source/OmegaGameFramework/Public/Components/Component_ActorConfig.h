// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Actors/Actor_ActorProcessor.h"

#include "Component_ActorConfig.generated.h"

// =======================================================================================================================
// COMPONENT
// =======================================================================================================================


UCLASS(Blueprintable,BlueprintType,Const,EditInlineNew,Abstract,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfigScript : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent,Category="ActorConfig")
	void OnActorConfigured(AActor* Actor) const;
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaActorConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	TArray<TSoftClassPtr<AOmegaActorProcessor>> TargetProcessors;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actors")
	TArray<FGameplayTag> AutoregisterToGroups;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Actors")
	TArray<UOmegaActorConfigScript*> Scripts;
};

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UActorConfigComponent : public UActorComponent
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere,Category="Config")
	UOmegaActorConfig* DefaultConfig;

	UFUNCTION(BlueprintCallable,Category="Config")
	void SetConfig(UOmegaActorConfig* Config);

};
