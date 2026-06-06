// Fill out your copyright notice in the Description page of Project Settings.

#include "StateTree/ST_Task_MoveTo.h"
#include "StateTreeExecutionContext.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"

#if WITH_EDITOR
#include "StateTreePropertyRef.h"
#endif

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static AAIController* GetAIController(AActor* Actor)
{
	if (APawn* Pawn = Cast<APawn>(Actor))
	{
		return Cast<AAIController>(Pawn->GetController());
	}
	return nullptr;
}

// ---------------------------------------------------------------------------
// EnterState
// ---------------------------------------------------------------------------

EStateTreeRunStatus FOmegaStateTask_MoveTo::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	AAIController* AIC = GetAIController(InstanceData.Pawn);
	if (!AIC)
	{
		return EStateTreeRunStatus::Failed;
	}

	// Optionally override move speed
	if (InstanceData.MoveSpeed > 0.0f)
	{
		if (ACharacter* Char = Cast<ACharacter>(InstanceData.Pawn))
		{
			if (UCharacterMovementComponent* CMC = Char->GetCharacterMovement())
			{
				CMC->MaxWalkSpeed = InstanceData.MoveSpeed;
			}
		}
	}

	// Resolve the base target location
	FVector GoalLocation = InstanceData.TargetLocation;
	bool bUseActorGoal = InstanceData.bToActor && InstanceData.TargetActor != nullptr;
	if (bUseActorGoal)
	{
		GoalLocation = InstanceData.TargetActor->GetActorLocation();
	}

	// Apply random offset in the XY plane if a range is configured
	const bool bHasOffset = InstanceData.RandomOffset_Max > 0.0f;
	if (bHasOffset)
	{
		const float Angle  = FMath::RandRange(0.0f, 2.0f * PI);
		const float Radius = FMath::RandRange(InstanceData.RandomOffset_Min, InstanceData.RandomOffset_Max);
		GoalLocation += FVector(FMath::Cos(Angle) * Radius, FMath::Sin(Angle) * Radius, 0.0f);
		bUseActorGoal = false; // must use location once offset is applied
	}

	// Build and issue the move request
	FAIMoveRequest MoveReq;
	MoveReq.SetUsePathfinding(true);
	MoveReq.SetAllowPartialPath(false);

	if (bUseActorGoal)
	{
		MoveReq.SetGoalActor(InstanceData.TargetActor);
	}
	else
	{
		MoveReq.SetGoalLocation(GoalLocation);
	}

	const FPathFollowingRequestResult Result = AIC->MoveTo(MoveReq);

	if (Result.Code == EPathFollowingRequestResult::Failed)
	{
		return EStateTreeRunStatus::Failed;
	}
	if (Result.Code == EPathFollowingRequestResult::AlreadyAtGoal)
	{
		return EStateTreeRunStatus::Succeeded;
	}

	InstanceData.MoveRequestID = Result.MoveId.GetID();
	return EStateTreeRunStatus::Running;
}

void FOmegaStateTask_MoveTo::ExitState(FStateTreeExecutionContext& Context,
	const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (ACharacter* Char = Cast<ACharacter>(InstanceData.Pawn))
	{
		if (UCharacterMovementComponent* CMC = Char->GetCharacterMovement())
		{
			if(InstanceData.bStopMovementOnStateEnd)
			{
				CMC->StopMovementImmediately();
			}
		}
	}
	
	FStateTreeTaskCommonBase::ExitState(Context, Transition);
}

// ---------------------------------------------------------------------------
// Tick
// ---------------------------------------------------------------------------

EStateTreeRunStatus FOmegaStateTask_MoveTo::Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	AAIController* AIC = GetAIController(InstanceData.Pawn);
	if (!AIC)
	{
		return EStateTreeRunStatus::Failed;
	}

	UPathFollowingComponent* PFC = AIC->GetPathFollowingComponent();
	if (!PFC)
	{
		return EStateTreeRunStatus::Failed;
	}

	// Still actively following the path we issued
	if (PFC->GetStatus() == EPathFollowingStatus::Moving
		&& PFC->GetCurrentRequestId().GetID() == InstanceData.MoveRequestID)
	{
		return EStateTreeRunStatus::Running;
	}

	// Idle means the move completed or was aborted
	return EStateTreeRunStatus::Succeeded;
}

// ---------------------------------------------------------------------------
// Editor
// ---------------------------------------------------------------------------

#if WITH_EDITOR
FText FOmegaStateTask_MoveTo::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	if (!InstanceData)
	{
		return FText::FromString(TEXT("Move To"));
	}

	if (InstanceData->bToActor)
	{
		const FString ActorName = InstanceData->TargetActor
			? InstanceData->TargetActor->GetActorLabel()
			: TEXT("None");
		return FText::FromString(FString::Printf(TEXT("Move To Actor: %s"), *ActorName));
	}

	return FText::FromString(FString::Printf(TEXT("Move To (%.0f, %.0f, %.0f)"),
		InstanceData->TargetLocation.X,
		InstanceData->TargetLocation.Y,
		InstanceData->TargetLocation.Z));
}
#endif
