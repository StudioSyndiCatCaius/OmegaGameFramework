// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/OmegaGameplaySystem.h"
#include "OmegaDemo_Systems.generated.h"

class ULevelingComponent;
class ALevelSequenceActor;
class UTurnBasedManagerComponent;
class UDataAssetCollectionComponent;
class UOmegaCombatEncounter_Component;

UCLASS(Abstract)
class OMEGADEMO_API ASystemBASE_CombatInstance : public AOmegaGameplaySystem
{
	GENERATED_BODY()

	UFUNCTION() void L_SeqFinished_PreStart();
	UFUNCTION() void L_SeqFinished_PostStart();

	UPROPERTY() ALevelSequenceActor* seqPlayer_preStart;
	UPROPERTY() ALevelSequenceActor* seqPlayer_postStart;
	
public:
	ASystemBASE_CombatInstance();
	virtual void N_BattleStart();
	virtual void SystemActivated_Implementation(UObject* Context, const FString& Flag) override;
	
	UFUNCTION(BlueprintImplementableEvent,Category="CombatInstance") ULevelSequence* GetSequence_PreSetup();
	UFUNCTION(BlueprintImplementableEvent,Category="CombatInstance") ULevelSequence* GetSequence_PostSetup();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UOmegaCombatEncounter_Component* Encounter_Component;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UDataAssetCollectionComponent* Scores_Component;	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") ULevelingComponent* XP_Component;	
};


UCLASS(Abstract)
class OMEGADEMO_API ASystemBASE_Combat_TurnBased : public ASystemBASE_CombatInstance
{
	GENERATED_BODY()

	UPROPERTY() AOmegaGameplaySystem* l_sysTurnFail;

	UFUNCTION() void L_SystemFailEnd(UObject* Context, FString Flag);
	
public:
	ASystemBASE_Combat_TurnBased();
	
	virtual void N_BattleStart() override;
	
	UFUNCTION() void N_TurnFail(FString Reason);

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="SYSTEM") TMap<FString,TSubclassOf<AOmegaGameplaySystem>> TurnFailSystems; 
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components") UTurnBasedManagerComponent* TurnManager_Component;	
	
};
