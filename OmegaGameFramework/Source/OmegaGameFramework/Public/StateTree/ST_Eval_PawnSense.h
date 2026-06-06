// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeEvaluatorBase.h"
#include "UObject/Object.h"
#include "ST_Eval_PawnSense.generated.h"

class UPawnSensingComponent;
/**
 * 
 */
// Per-instance data stored by the StateTree runtime
USTRUCT(BlueprintType)
struct OMEGAGAMEFRAMEWORK_API FST_Eval_PawnSenseData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Output")
	TObjectPtr<UPawnSensingComponent> PawnSensingComponent = nullptr;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Output")
	bool bAddPawnSenseIfNotValid;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Output")
	bool bOverridePeripheralVision;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Output")
	float PeripheralVision;
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Alert")
	bool AlertAlliesToTarget=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Alert")
	float AllyAlertDistance=500.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Alert")
	TArray<TSubclassOf<AActor>> AlertActorClasses;
};


USTRUCT(meta = (DisplayName = "Ω Combatant Evaluator"))
struct OMEGAGAMEFRAMEWORK_API FST_Eval_PawnSense : public FStateTreeEvaluatorCommonBase
{
	GENERATED_BODY()
};