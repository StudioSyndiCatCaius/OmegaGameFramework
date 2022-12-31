// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/CombatantComponent.h"
#include "CombatantTargetIndicator.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API ACombatantTargetIndicator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACombatantTargetIndicator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UCombatantComponent* CombatantOwner;
	
	UFUNCTION(BlueprintPure, Category="Combatant")
	UCombatantComponent* GetOwningCombatant();
	
	UFUNCTION(BlueprintPure, Category="Combatant")
	UCombatantComponent* GetTargetCombatant();

	UFUNCTION()
	void Native_Updatetarget(UCombatantComponent* Combatant, bool bValid);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTargetCombatantUpdated(UCombatantComponent* Combatant);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCombatantSetActive(bool bActive);
};
