// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Functions/OmegaFunctions_ComponentMod.h"
#include "Misc/OmegaUtils_Actor.h"
#include "Nodes/FlowNode.h"
#include "FlowNode_Actors.generated.h"

class UOmegaSelector_Montage;

UCLASS(Abstract)
class OMEGADEMO_API UFlowNode_ActorBase : public UFlowNode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,Category="Flow")
	AActor* GetActor() const;
	UFUNCTION(BlueprintPure,Category="Flow")
	TArray<AActor*> GetActors() const; 
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,DisplayName="Actor (ID)",Category="Actor")
	UPrimaryDataAsset* Actor_Identity;
	UPROPERTY(EditAnywhere,Instanced,BlueprintReadWrite,DisplayName="Actor (Ref)",Category="Actor")
	UOmegaActorSelector* Actor;
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
/*
UCLASS(DisplayName="Character - Montage",Category="Actor")
class OMEGADEMO_API UFlowNode_Actor_Montage : public UFlowNode_ActorBase
{
	GENERATED_BODY()

public:
	UFlowNode_Actor_Montage();

	UFUNCTION() void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
	UFUNCTION() void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
	//virtual FString GetNodeDescription() const override;
	virtual FString GetNodeCategory() const override { return "Actor"; };
#endif
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor")
	UAnimMontage* Montage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor")
	float PlayRate=1.0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor")
	float StartingPosition;
};
*/