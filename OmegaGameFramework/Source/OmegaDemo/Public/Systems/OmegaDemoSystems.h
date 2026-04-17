// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "GameFramework/Actor.h"
#include "OmegaDemoSystems.generated.h"

class UCombatantComponent;
class UOmegaCombatEncounter_Component;
class UTurnBasedManagerComponent;

UCLASS(Abstract)
class OMEGADEMO_API AOmegaDemoSystems : public AOmegaGameplaySystem
{
	GENERATED_BODY()

public:

	AOmegaDemoSystems();

protected:

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
};



UCLASS()
class OMEGADEMO_API ADemoSystem_TurnBasedCombat : public AOmegaGameplaySystem
{
	GENERATED_BODY()
public:

	ADemoSystem_TurnBasedCombat();

	int32 sequence_state;
	
	UFUNCTION() void RandSequenceEnded();
	void PlayRandomSequence( TArray<TObjectPtr<ULevelSequence>> sequenceList, uint8 state);
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
	
	
	
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="⚔️Battle") TArray<TObjectPtr<ULevelSequence>> Sequences_BattleSplash;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="⚔️Battle") TArray<TObjectPtr<ULevelSequence>> Sequences_BattleIntro;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="⚔️Components") UCombatantComponent* Metadata;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="⚔️Components") UTurnBasedManagerComponent* TurnManager;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="⚔️Components") UOmegaCombatEncounter_Component* Encounter;

};
