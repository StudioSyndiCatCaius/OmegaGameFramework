// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OmegaAbility.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncAction_ActivateAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityCancled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityFailed);

UCLASS()
class OMEGAFLOW_API UAsyncAction_ActivateAbility : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FAbilityCompleted Completed;
	UPROPERTY(BlueprintAssignable)
	FAbilityCancled Canceled;
	UPROPERTY(BlueprintAssignable)
	FAbilityFailed Failed;

	UPROPERTY()
	TSubclassOf<AOmegaAbility> LocalAbilityClass;
	UPROPERTY()
	UObject* LocalContext = nullptr;
	UPROPERTY()
	UCombatantComponent* CombatantRef;
	
	UFUNCTION()
	void NativeShutdown(bool bCancelled);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|GameplayTasks", DisplayName="Activate Ability")
	static UAsyncAction_ActivateAbility* ActivateAbility(UCombatantComponent* Combatant, const TSubclassOf<AOmegaAbility> Ability, UObject* Context);

};
