// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Misc/OmegaFaction.h"
#include "Subsystems/OmegaSubsystem_BGM.h"
#include "Component_CombatEncounter.generated.h"



UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatEncounter_Stage : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Encounter Stage")
	FGameplayTag StageID;

	UFUNCTION(BlueprintNativeEvent,Category="Omega|Encounter|Stage")
	FTransform GetTransformForBattler(FGameplayTag FactionTag, int32 index);
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatEncounter_Instance : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Encounter")
	UOmegaBGM* OverrideBGM;
	
};

//
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UOmegaCombatEncounter_Component : public UActorComponent
{
	GENERATED_BODY()

private:
	// Sets default values for this component's properties
	UPROPERTY() TArray<AOmegaCombatEncounter_Stage*> REF_StageList;
	UPROPERTY() AOmegaCombatEncounter_Stage* REF_Stage;
	UPROPERTY() AOmegaCombatEncounter_Instance* REF_Instance;

	UPROPERTY()
	TArray<UCombatantComponent*> REF_BattlerCombatants;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UOmegaCombatEncounter_Component();

public:

	UFUNCTION(BlueprintCallable,Category="Encounter")
	TArray<AOmegaCombatEncounter_Stage*> GetAllStages();

	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Stage* GetStageFromID(FGameplayTag ID);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Encounter")
	TSubclassOf<ACharacter> BattlerCharacterClass;

	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Instance* StartEncounter(TSubclassOf<AOmegaCombatEncounter_Instance> EncounterClass,AOmegaCombatEncounter_Stage* Stage);

	UFUNCTION(BlueprintCallable,Category="Encounter")
	AOmegaCombatEncounter_Instance* StartEncounter_FromSource(UObject* Source);
	
	UFUNCTION(BlueprintCallable,Category="Encounter")
	bool EndEncounter();
	
	UFUNCTION(BlueprintCallable,Category="Encounter")
	ACharacter* SpawnBattler(UPrimaryDataAsset* DataAsset, UOmegaFaction* Faction, FTransform Transform);
	
};

UINTERFACE(MinimalAPI)
class UDataInterface_CombatEncounter : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_CombatEncounter
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent,Category="Encounter")
	TSubclassOf<AOmegaCombatEncounter_Instance> GetCombatEncounter_InstanceClass();
	UFUNCTION(BlueprintImplementableEvent,Category="Encounter")
	FGameplayTag GetCombatEncounter_StageID();

};