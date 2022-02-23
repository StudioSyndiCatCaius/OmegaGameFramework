// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "BTT_RunAction.h"


EBTNodeResult::Type UBTT_RunAction::ExecuteTask(UBehaviorTreeComponent& InOwnerComp, uint8* NodeMemory)
{
	if(!ActionType) {
		return EBTNodeResult::Failed;
	}

	AActor* OwnerActor = InOwnerComp.GetTypedOuter<AActor>();
	check(OwnerActor);

	Action = UAction::Create(OwnerActor, ActionType, false);
	check(Action);

	Action->OnFinishedDelegate.AddDynamic(this, &UBTT_RunAction::OnRunActionFinished);
	Action->Activate();

	OwnerComp = &InOwnerComp;
	return Action? EBTNodeResult::InProgress : EBTNodeResult::Failed;
}

EBTNodeResult::Type UBTT_RunAction::AbortTask(UBehaviorTreeComponent& InOwnerComp, uint8* NodeMemory)
{
	if(IsValid(Action))
	{
		Action->Cancel();
	}
	return EBTNodeResult::Aborted;
}

void UBTT_RunAction::DescribeRuntimeValues(const UBehaviorTreeComponent& InOwnerComp, uint8* NodeMemory, EBTDescriptionVerbosity::Type Verbosity, TArray<FString>& Values) const
{
	Super::DescribeRuntimeValues(InOwnerComp, NodeMemory, Verbosity, Values);

	if (Action)
	{
		const FString State = ToString(Action->GetState());
		Values.Add(FString::Printf(TEXT("state: %s"), *State));
	}
}

FString UBTT_RunAction::GetStaticDescription() const
{
	FString ActionName = (ActionType)? ActionType->GetClass()->GetName() : "None";
	ActionName.RemoveFromEnd("_C", ESearchCase::CaseSensitive);
	return FString::Printf(TEXT("Action: %s"), *ActionName);
}

void UBTT_RunAction::OnRunActionFinished(const EActionState Reason)
{
	if (OwnerComp)
	{
		switch (Reason)
		{
		case EActionState::Success:
			FinishLatentTask(*OwnerComp, EBTNodeResult::Succeeded);
			break;
		case EActionState::Failure:
			FinishLatentTask(*OwnerComp, EBTNodeResult::Failed);
			break;
		case EActionState::Cancelled: //Do Nothing
			break;
		default:
			FinishLatentTask(*OwnerComp, EBTNodeResult::Aborted);
			break;
		}
	}
}