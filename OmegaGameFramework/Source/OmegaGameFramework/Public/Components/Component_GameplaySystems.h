// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_GameplaySystems.generated.h"

class AOmegaGameplaySystem;

UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UGameplaySystemsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	float f_lastFeq;

	UGameplaySystemsComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	void Local_ActivateSystems();
	void Local_ShutdownSystems();
	
public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	TArray<TSubclassOf<AOmegaGameplaySystem>> GameplaySystems;
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FString ActivationFlag;
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	TArray<TSubclassOf<AOmegaGameplaySystem>> PersistentSystems;
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	float PersistentSystems_Frequency=0.2;
	
};
