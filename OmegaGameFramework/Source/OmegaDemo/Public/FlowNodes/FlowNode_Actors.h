// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/F_Component.h"
#include "Functions/F_ScriptedAnim.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Actors.generated.h"

class UOmegaSelector_Montage;

UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_ActorBase : public UFlowNode
{
	GENERATED_BODY()

public:

	virtual AActor* GetNodeInstigator() override;
	
	UFUNCTION(BlueprintPure,Category="Flow")
	AActor* GetActor() const;
	UFUNCTION(BlueprintPure,Category="Flow")
	TArray<AActor*> GetActors() const; 
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,DisplayName="Actor Identity",Category="Actor")
	UPrimaryDataAsset* Actor_Identity;
};

	
UCLASS(DisplayName="Actor - Modify",Category="Actor")
class OMEGADEMO_API UFlowNode_Actor_Modify : public UFlowNode_ActorBase
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
	TArray<UActorModifierScript*> Modifiers;

};


UCLASS(DisplayName="Actor - Condition",Category="Actor")
class OMEGADEMO_API UFlowNode_Actor_Condition : public UFlowNode_ActorBase
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
	TArray<UOmegaCondition_Actor*> Conditions;

};


UCLASS(DisplayName="Actor - Play Scripted Anim",Category="Actor")
class OMEGADEMO_API UFlowNode_ScriptedAnim : public UFlowNode_ActorBase
{
	GENERATED_BODY()

public:
	//UFlowNode_Actor_Modify();

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Actor"; };
#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor",meta=(ShowOnlyInnerProperties))
	FOmegaScriptedAnimationData AnimData;

};