// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameplaySystem.h"
#include "Components/ActorComponent.h"
#include "GameplaySystemsComponent.generated.h"


UCLASS(ClassGroup=("Omega Game Framework"), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UGameplaySystemsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGameplaySystemsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	void Local_ActivateSystems();
	void Local_ShutdownSystems();
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	TArray<TSubclassOf<AOmegaGameplaySystem>> GameplaySystems;
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FString ActivationFlag;

	
};
