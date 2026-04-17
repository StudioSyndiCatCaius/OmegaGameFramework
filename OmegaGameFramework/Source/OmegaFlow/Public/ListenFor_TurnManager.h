// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ListenFor_TurnManager.generated.h"

class UTurnBasedManagerComponent;
class UCombatantComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOListenTurnManagerDelegate, UTurnBasedManagerComponent*, Component, UCombatantComponent*,
                                               TurnCombatant, FString, Flag);


UCLASS()
class OMEGAFLOW_API UListenFor_TurnManager : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable) FOListenTurnManagerDelegate TurnStart;
	UPROPERTY(BlueprintAssignable) FOListenTurnManagerDelegate TurnEnd;
	UPROPERTY(BlueprintAssignable) FOListenTurnManagerDelegate TurnFail;
	UPROPERTY(BlueprintAssignable) FOListenTurnManagerDelegate TurnOrderGenerated;
	
	UPROPERTY() UTurnBasedManagerComponent* TurnManager;

	UFUNCTION() void L_OnTurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant);
	UFUNCTION() void L_OnTurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant);
	UFUNCTION() void L_OnTurnFail(FString Reason);
	UFUNCTION() void L_OnTurnOrderGenerated(UTurnBasedManagerComponent* Component);
	
	virtual void Activate() override;
	
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly = "true"), Category="Omega|ListenFor", meta = (WorldContext = "WorldContextObject"),DisplayName="👂Listen For - Turn Manager") 
	static UListenFor_TurnManager* ListenFor_TurnManager(UTurnBasedManagerComponent* Component);
	
};

