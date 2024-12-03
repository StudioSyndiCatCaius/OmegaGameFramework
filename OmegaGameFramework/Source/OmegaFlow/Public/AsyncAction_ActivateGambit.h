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
	
	UPROPERTY(BlueprintAssignable)
	FAbilityGambitCompleted Completed;
	UPROPERTY(BlueprintAssignable)
	FAbilityGambitCancled Canceled;
	UPROPERTY(BlueprintAssignable)
	FAbilityGambitFailed Failed;
	
	UPROPERTY()
	UCombatantComponent* CombatantRef;
	UPROPERTY()
	UCombatantGambitAsset* LocalGambit;
	UPROPERTY()
	AOmegaAbility* LocalAbility;
	
	UFUNCTION()
	void NativeShutdown(bool bCancelled);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", DisplayName="Activate Gambit")
	static UAsyncAction_ActivateGambit* ActivateGambit(UCombatantComponent* Combatant, UCombatantGambitAsset* Gambit);

};
