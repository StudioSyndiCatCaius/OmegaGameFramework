// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "ActionsSubsystem.h"
#include <GameFramework/WorldSettings.h>

#include "Action.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebugger_Actions.h"
#endif // WITH_GAMEPLAY_DEBUGGER


void FActionsTickGroup::Tick(float DeltaTime)
{
	if (Actions.Num() <= 0)
	{
		return;
	}

	if (TickRate > KINDA_SMALL_NUMBER)
	{
		TickTimeElapsed += DeltaTime;
		if (TickTimeElapsed < TickRate)
		{
			return;
		}

		// Delayed Tick
		DelayedTick(TickTimeElapsed);

		TickTimeElapsed = 0.f;
	}
	else
	{
		//Normal Tick
		DelayedTick(DeltaTime);
	}
}

void FActionsTickGroup::DelayedTick(float DeltaTime)
{
	for (int32 i = 0; i < Actions.Num(); ++i)
	{
		auto* Action = Actions[i];

		if (!IsValid(Action))
		{
			Actions.RemoveAtSwap(i, 1, false);
			--i;
		}
		else if (Action->CanTick())
		{
			Action->DoTick(DeltaTime);
		}
	}
}

void FRootAction::CancelAll(bool bShouldShrink)
{
	for (auto* Action : Actions)
	{
		if (Action)
		{
			Action->Cancel();
		}
	}

	if (bShouldShrink)
		Actions.Empty();
	else
		Actions.Reset();
}

void FRootAction::CancelByPredicate(const TFunctionRef<bool(const UAction*)>& Predicate, bool bShouldShrink)
{
	for (int32 i = 0; i < Actions.Num(); ++i)
	{
		auto* Action = Actions[i];

		if (Action && Predicate(Action))
		{
			//Cancel action
			Action->Cancel();

			// Remove action
			Actions.RemoveAtSwap(i, 1, false);
			--i;
		}
	}

	if (bShouldShrink)
	{
		Actions.Shrink();
	}
}


void UActionsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UActionsSubsystem::Deinitialize()
{
	CancelAll();
	Super::Deinitialize();
}

void UActionsSubsystem::Tick(float DeltaTime)
{
	// Cancel destroyed object actions
	for (auto RootIt = RootActions.CreateIterator(); RootIt; ++RootIt)
	{
		if (!RootIt->Owner.IsValid())
		{
			RootIt->CancelAll(false);
			RootIt.RemoveCurrent();
		}
		else
		{
			// Remove garbage collected actions
			RootIt->Actions.RemoveAllSwap([](const UAction* Action) {
				return !Action;
			}, false);

			if (RootIt->Actions.Num() <= 0)
			{
				RootIt.RemoveCurrent();
			}
		}
	}

	// Tick all tick groups
	const float TimeDilation = GetWorld()->GetWorldSettings()->GetEffectiveTimeDilation();
	for (int32 i = 0; i < TickGroups.Num(); ++i)
	{
		auto& TickGroup = TickGroups[i];

		TickGroup.Tick(DeltaTime * TimeDilation);

		if(TickGroup.Actions.Num() <= 0)
		{
			// Tick group is empty so we remove and ignore it
			TickGroups.RemoveAtSwap(i, 1, false);
			--i;
		}
	}
	TickGroups.Shrink();
}

void UActionsSubsystem::CancelAll()
{
	for (auto& RootAction : RootActions)
	{
		RootAction.CancelAll(false);
	}
	RootActions.Reset();
}

void UActionsSubsystem::CancelAllByOwner(UObject* Object)
{
	const FSetElementId RootId = RootActions.FindId(Object);
	if (RootId.IsValidId())
	{
		RootActions[RootId].CancelAll(false);
		RootActions.Remove(RootId);
	}
}


void UActionsSubsystem::CancelByPredicate(TFunctionRef<bool(const UAction*)> Predicate)
{
	for (auto& RootAction : RootActions)
	{
		RootAction.CancelByPredicate(Predicate);
	}
}

void UActionsSubsystem::CancelByOwnerPredicate(UObject* Object, TFunctionRef<bool(const UAction*)> Predicate)
{
	if(FRootAction* const RootAction = RootActions.Find(Object))
	{
		RootAction->CancelByPredicate(Predicate);
	}
}

void UActionsSubsystem::AddRootAction(UAction* Child)
{
	check(Child);

	// Registry for GC Canceling
	UObject* Owner = Child->GetOuter();

	FSetElementId RootId = RootActions.FindId(Owner);
	if (!RootId.IsValidId())
	{
		RootId = RootActions.Add({ Owner });
	}

	RootActions[RootId].Actions.Add(Child);
}

void UActionsSubsystem::AddActionToTickGroup(UAction* Child)
{
	const float TickRate = Child->GetTickRate();

	// Registry for tick groups
	FActionsTickGroup* Group = TickGroups.FindByKey(TickRate);
	if (!Group)
	{
		TickGroups.Add({ TickRate });
		Group = &TickGroups.Last();
	}

	Group->Actions.Add(Child);
}

#if WITH_GAMEPLAY_DEBUGGER
void UActionsSubsystem::DescribeOwnerToGameplayDebugger(UObject* Owner, const FName& BaseName, FGameplayDebugger_Actions& Debugger) const
{
	static const FString StateColorText = TEXT("{green}");

	Debugger.AddTextLine(FString::Printf(TEXT("%s%s: %s"), *StateColorText, *BaseName.ToString(), *Owner->GetName()));

	if (const FRootAction* const RootAction = RootActions.Find(Owner))
	{
		for (const auto* Action : RootAction->Actions)
		{
			if (IsValid(Action))
			{
				Action->DescribeSelfToGameplayDebugger(Debugger, 1);
			}
		}
	}

	Debugger.AddTextLine(TEXT(""));
}
#endif // WITH_GAMEPLAY_DEBUGGER
