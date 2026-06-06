// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeEvaluatorBase.h"
#include "StateTreeExecutionContext.h"
#include "ST_Eval_Combatant.generated.h"

class UCombatantComponent;

// Per-instance data stored by the StateTree runtime
USTRUCT(BlueprintType)
struct OMEGAGAMEFRAMEWORK_API FST_Eval_CombatantInstanceData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Output")
	TObjectPtr<UCombatantComponent> CombatantComponent = nullptr;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Output")
	TObjectPtr<UCombatantComponent> ActiveTarget = nullptr;
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Alert")
	bool AlertAlliesToTarget=false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Alert")
	float AllyAlertDistance=500.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Alert")
	TArray<TSubclassOf<AActor>> AlertActorClasses;
};

// Evaluator — resolves the CombatantComponent from the StateTree owner actor and
// exposes it as bindable output data for tasks and conditions in the same tree.
USTRUCT(meta = (DisplayName = "Ω Combatant Evaluator"))
struct OMEGAGAMEFRAMEWORK_API FST_Eval_Combatant : public FStateTreeEvaluatorCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FST_Eval_CombatantInstanceData;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual void TreeStart(FStateTreeExecutionContext& Context) const override;
	virtual void Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

private:
	TStateTreeExternalDataHandle<AActor> OwnerActorHandle;
};
