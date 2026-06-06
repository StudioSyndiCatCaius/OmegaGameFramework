// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "AITypes.h"
#include "ST_Task_MoveTo.generated.h"


enum class EStateTreeRunStatus : uint8;
struct FStateTreeTransitionResult;

USTRUCT()
struct OMEGAGAMEFRAMEWORK_API FOmegaStateTask_MoveTo_InstData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = Context) TObjectPtr<AActor> Pawn;
	
	UPROPERTY(EditAnywhere, Category = Parameter,meta = (EditCondition = "!bToActor")) FVector TargetLocation;
	UPROPERTY(EditAnywhere, Category = Parameter) bool bToActor;
	UPROPERTY(EditAnywhere, Category = Parameter,meta = (EditCondition = "bToActor")) TObjectPtr<AActor> TargetActor;
	
	//if > 0.0, edit move speed (walk speed if character). otherwise do nothing with
	UPROPERTY(EditAnywhere, Category = Parameter) float MoveSpeed;
	UPROPERTY(EditAnywhere, Category = Parameter) bool bStopMovementOnStateEnd;
	
	
	UPROPERTY(EditAnywhere, Category = Parameter) float RandomOffset_Min;
	UPROPERTY(EditAnywhere, Category = Parameter) float RandomOffset_Max;

	// Runtime — tracks the active move request so Tick can detect completion
	UPROPERTY() uint32 MoveRequestID = FAIRequestID::InvalidRequest;
};


USTRUCT(meta = (DisplayName = "Ω Move To"))
struct OMEGAGAMEFRAMEWORK_API FOmegaStateTask_MoveTo : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FOmegaStateTask_MoveTo_InstData;
	
	FOmegaStateTask_MoveTo() = default;

	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }

	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
#if WITH_EDITOR
	virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
	virtual FName GetIconName() const override
	{
		return FName("StateTreeEditorStyle|Node.Time");
	}
	virtual FColor GetIconColor() const override
	{
		return UE::StateTree::Colors::Blue;
	}
#endif
};
