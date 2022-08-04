// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaGameplaySystem.h"
#include "GameFramework/Actor.h"
#include "Gameplay/TurnBased/TurnBasedManagerComponent.h"

#include "GameSystem_TurnBasedCombat.generated.h"

UCLASS(Abstract)
class OMEGADEMO_API AGameSystem_TurnBasedCombat : public AOmegaGameplaySystem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGameSystem_TurnBasedCombat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//COMPONENTS
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="TurnBasedCombat")
	UTurnBasedManagerComponent* TurnManager;


	//----TURN----//
	UPROPERTY(EditDefaultsOnly, Category="TurnBasedCombat")
	TSubclassOf<AOmegaAbility> TurnAbility;
	
	UFUNCTION()
	void OnTurnBegin(UCombatantComponent* Combatant, FString Flag, FGameplayTagContainer GameplayTags);

	UFUNCTION()
	void TurnAbilityFinish(bool Cancelled);
	UFUNCTION()
	void TryAdvanceTurn();

	//---Sub Systems--//
	UPROPERTY(EditDefaultsOnly, Category="TurnBasedCombat")
	TSubclassOf<AOmegaGameplaySystem> BattleEndSystem;
};
