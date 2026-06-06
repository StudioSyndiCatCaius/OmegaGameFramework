// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "ST_Task_UseAbility.generated.h"

enum class EStateTreeRunStatus : uint8;
struct FStateTreeTransitionResult;

class UCombatantComponent;
class AOmegaAbility;

// ---------------------------------------------------------------------------
// Instance Data
// ---------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct OMEGAGAMEFRAMEWORK_API FST_Task_UseAbility_InstData
{
	GENERATED_BODY()

	// Combatant that owns and activates the ability.
	// Bind this to the output of an FST_Eval_Combatant evaluator.
	UPROPERTY(EditAnywhere, Category = Context) TObjectPtr<AActor> Pawn;

	// The ability class to activate.
	UPROPERTY(EditAnywhere, Category = "Parameter")
	TSubclassOf<AOmegaAbility> AbilityClass;

	// Optional context object forwarded to the ability.
	UPROPERTY(EditAnywhere, Category = "Parameter")
	TObjectPtr<UObject> AbilityContext;

	// If true the task stays Running until the ability finishes naturally.
	// If false the task Succeeds as soon as the ability is activated.
	UPROPERTY(EditAnywhere, Category = "Parameter")
	bool bWaitForCompletion = true;

	// Cancel the ability when this state exits early (e.g. a transition interrupts it).
	UPROPERTY(EditAnywhere, Category = "Parameter")
	bool bCancelOnExit = true;
};

// ---------------------------------------------------------------------------
// Task
// ---------------------------------------------------------------------------

USTRUCT(meta = (DisplayName = "Ω Use Ability"))
struct OMEGAGAMEFRAMEWORK_API FST_Task_UseAbility : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FST_Task_UseAbility_InstData;

	UCombatantComponent* GetCombatant(AActor* a) const;
	
	FST_Task_UseAbility() = default;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

#if WITH_EDITOR
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
	virtual FName GetIconName() const override { return FName("StateTreeEditorStyle|Node.Event"); }
	virtual FColor GetIconColor() const override { return UE::StateTree::Colors::Red; }
#endif
};
