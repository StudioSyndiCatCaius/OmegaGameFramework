// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Component_Combatant.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameFramework/Actor.h"
#include "Actor_CombatantSelector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatantSelectionFinished,TArray<UCombatantComponent*>, Targets, FName, FinishNotify);

UCLASS()
class OMEGAGAMEFRAMEWORK_API AOmegaCombatantSelector : public APawn
{
	GENERATED_BODY()

	UPROPERTY() bool bConfirming;
	UPROPERTY() FName outputNotify;

	UPROPERTY() TArray<UCombatantComponent*> registered_combatants;
	
public:
	// Sets default values for this actor's properties
	//ATimelineActor();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY() UCombatantComponent* instigator_combatant;

	UPROPERTY(BlueprintAssignable) FOnCombatantSelectionFinished OnSelectionFinished;
	
	UFUNCTION(BlueprintCallable,Category="Omega|CombatantSelector")
	void SetCombatantRegistered(UCombatantComponent* Combatant, bool bRegister);

	UFUNCTION(BlueprintCallable,Category="Omega|CombatantSelector")
	TArray<UCombatantComponent*> GetRegisteredCombatants();

	UFUNCTION(BlueprintCallable,Category="Omega|CombatantSelector")
	void SetCombatantRegistered_List(TArray<UCombatantComponent*> Combatants, bool bRegister, bool bClearListFirst);

	UFUNCTION(BlueprintCallable,Category="Omega|CombatantSelector")
	void UnregisterAllCombatants();

	UFUNCTION(BlueprintCallable,Category="Omega|CombatantSelector")
	void EndSelection(FName FinishNotify="Complete");
};

// ==========================================================================================
// Async Action
// ==========================================================================================


UCLASS()
class OMEGAGAMEFRAMEWORK_API UAsyncAction_CombatantSelector : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FOnCombatantSelectionFinished OnFinished;
	
	UFUNCTION() void local_Finish(TArray<UCombatantComponent*> Targets, FName FinishNotify);
	
	UPROPERTY() UObject* local_worldContext;
	UPROPERTY() AOmegaCombatantSelector* ref_actor;
	UPROPERTY() TSubclassOf<AOmegaCombatantSelector> local_Class;
	UPROPERTY() UCombatantComponent* local_instigator;
	UPROPERTY() FTransform local_transform;
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="")) 
	static UAsyncAction_CombatantSelector* AsyncSelectCombatant(UObject* WorldContextObject, TSubclassOf<AOmegaCombatantSelector> Class, const FTransform Transform, UCombatantComponent* instigator);

	
};
