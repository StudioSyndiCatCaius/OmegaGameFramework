// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Actors.generated.h"

	
UCLASS(DisplayName="Actor - Modify",Category="Actor")
class OMEGADEMO_API UFlowNode_Actor_Modify : public UFlowNode
{
	GENERATED_BODY()

public:
	//UFlowNode_Actor_Modify();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Actor"; };
#endif

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor")
	UOmegaActorSelector* Actor;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor")
	TArray<UActorModifierScript*> Modifiers;

};


UCLASS(DisplayName="Actor - Condition",Category="Actor")
class OMEGADEMO_API UFlowNode_Actor_Condition : public UFlowNode
{
	GENERATED_BODY()

	bool L_CheckCondition();
public:
	UFlowNode_Actor_Condition();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Actor"; };
#endif

	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor")
	UOmegaActorSelector* Actor;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,Category="Actor")
	TArray<UOmegaCondition_Actor*> Conditions;

};