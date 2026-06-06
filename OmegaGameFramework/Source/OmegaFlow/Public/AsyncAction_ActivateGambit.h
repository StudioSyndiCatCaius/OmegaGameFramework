// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Actor_Ability.h"
#include "Components/Component_Combatant.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_ActivateGambit.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityGambitCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityGambitCancled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityGambitFailed);

UCLASS()
class OMEGAFLOW_API UAsyncAction_ActivateGambit : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FAbilityGambitCompleted Completed;
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FAbilityGambitCancled Canceled;
	UPROPERTY(BlueprintAssignable, Category="Omega")
	FAbilityGambitFailed Failed;
	
	UPROPERTY() UCombatantComponent* CombatantRef;
	UPROPERTY() UOmegaGambit_Asset* LocalGambit;
	UPROPERTY() AOmegaAbility* LocalAbility;
	
	UFUNCTION()
	void NativeShutdown(bool bCancelled);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly), Category="Omega|AsyncGameplayTasks", DisplayName="Ω🔷 Run Combatant Gambit")
	static UAsyncAction_ActivateGambit* ActivateGambit(UCombatantComponent* Combatant, UOmegaGambit_Asset* Gambit);

};
