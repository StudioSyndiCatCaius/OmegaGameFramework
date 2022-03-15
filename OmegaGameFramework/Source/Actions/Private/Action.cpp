// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "Action.h"

#include "Engine/EngineTypes.h"
#include "TimerManager.h"
#include "Engine/World.h"

#include "GameplayTaskOwnerInterface.h"
#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebugger_Actions.h"
#endif // WITH_GAMEPLAY_DEBUGGER

DEFINE_LOG_CATEGORY(ActionLog);


void UAction::Activate()
{
	UActionsSubsystem* Subsystem = GetSubsystem();

	if (IsPendingKill() || !IsValid(GetOuter()) || State != EActionState::Preparing)
	{
		UE_LOG(ActionLog, Warning, TEXT("Action '%s' is already running or pending destruction."), *GetName());
		Destroy();
		return;
	}

	if(!CanActivate())
	{
		UE_LOG(ActionLog, Log, TEXT("Could not activate. CanActivate() Failed."));
		Destroy();
		return;
	}

	// Add this action to its parent
	if (auto* ParentAction = GetParentAction())
	{
		ParentAction->AddChildren(this);
	}
	else
	{
		Subsystem->AddRootAction(this);
	}

	Subsystem->AddActionToTickGroup(this);


	State = EActionState::Running;
	OnActivation();
}

void UAction::Cancel()
{
	if (IsPendingKill())
		return;

	if (!IsRunning())
	{
		Destroy();
		return;
	}

	OnFinish(State = EActionState::Cancelled);
	Destroy();
}

void UAction::OnFinish(const EActionState Reason)
{
	// Stop any timers or latent actions for the action
	if (UWorld * World = GetWorld())
	{
		World->GetLatentActionManager().RemoveActionsForObject(this);
		World->GetTimerManager().ClearAllTimersForObject(this);
	}

	OnFinishedDelegate.Broadcast(Reason);

	if(Reason==EActionState::Success)
	{
		OnSuccess.Broadcast();
	}
	if(Reason==EActionState::Failure)
	{
		OnFailure.Broadcast();
	}
	
	const UObject* Parent = GetParent();
	// If we're in the process of being garbage collected it is unsafe to call out to blueprints
	if (Parent && !Parent->HasAnyFlags(RF_BeginDestroyed) && !Parent->IsUnreachable())
	{
		if(Reason==EActionState::Cancelled)
		{
			ReceiveCancel();
		}
		else
		{
			ReceiveFinished(Reason);
		}
	}
}

void UAction::Finish(bool bSuccess) {
	if (!IsRunning() || IsPendingKill())
		return;

	State = bSuccess ? EActionState::Success : EActionState::Failure;
	
	OnFinish(State);

	//Remove from parent action
	if (auto* ParentAction = GetParentAction())
	{
		ParentAction->RemoveChildren(this);
	}

	Destroy();
}

void UAction::Destroy()
{
	if (IsPendingKill())
		return;

	//Cancel and destroy all children tasks
	for (auto* Children : ChildrenActions)
	{
		if (Children) {
			Children->Cancel();
		}
	}
	ChildrenActions.Reset();

	//Mark for destruction
	MarkPendingKill();
}

void UAction::AddChildren(UAction* Child)
{
	ChildrenActions.Add(Child);
}

void UAction::RemoveChildren(UAction* Child)
{
	ChildrenActions.Remove(Child);
}

bool UAction::ReceiveCanActivate_Implementation()
{
	return true;
}

UObject* UAction::GetOwner() const
{
	UObject* Outer = nullptr;
	const UAction* Current = this;

	// #TODO: Ensure this works
	while (Current)
	{
		Outer = Current->GetOuter();
		Current = Cast<UAction>(Outer);
	}
	return Outer;
}

AActor* UAction::GetOwnerActor() const
{
	UObject* const Owner = GetOwner();
	if (auto * Component = Cast<UActorComponent>(Owner))
	{
		return Component->GetOwner();
	}
	return Cast<AActor>(Owner);
}

#if WITH_GAMEPLAY_DEBUGGER
void UAction::DescribeSelfToGameplayDebugger(FGameplayDebugger_Actions& Debugger, int8 Indent) const
{
	FString ColorText = TEXT("");
	switch (State)
	{
	case EActionState::Running:
		ColorText = TEXT("{cyan}");
		break;
	case EActionState::Success:
		ColorText = TEXT("{green}");
		break;
	default:
		ColorText = TEXT("{red}");
	}

	FString IndentString = "";
	for (int32 I = 0; I < Indent; ++I)
	{
		IndentString += "  ";
	}

	const FString CanceledSuffix = (State == EActionState::Cancelled) ? TEXT("CANCELLED") : FString{};

	if (IsRunning())
	{
		Debugger.AddTextLine(FString::Printf(TEXT("%s%s>%s %s"), *IndentString, *ColorText, *GetName(), *CanceledSuffix));

		for (const auto* ChildAction : ChildrenActions)
		{
			if (ChildAction)
			{
				ChildAction->DescribeSelfToGameplayDebugger(Debugger, Indent + 1);
			}
			else
			{
				ensureMsgf(false, TEXT("Invalid child on action %s while debugging"), *GetName());
			}
		}
	}
}
#endif // WITH_GAMEPLAY_DEBUGGER

UAction* UAction::Create(UObject* Owner, const TSubclassOf<class UAction> Type, bool bAutoActivate /*= false*/)
{
	if (!IsValid(Owner) || !Type.Get() || Type == UAction::StaticClass())
	{
		return nullptr;
	}

	UAction* Action = NewObject<UAction>(Owner, Type);
	if (bAutoActivate)
	{
		Action->Activate();
	}
	return Action;
}

UAction* UAction::Create(UObject* Owner, UAction* Template, bool bAutoActivate /*= false*/)
{
	if (!IsValid(Owner) || !Template)
	{
		return nullptr;
	}

	UClass* const Type = Template->GetClass();
	check(Type);

	if (Type == UAction::StaticClass())
	{
		return nullptr;
	}

	UAction* Action = NewObject<UAction>(Owner, Type, NAME_None, RF_NoFlags, Template);
	if (bAutoActivate)
	{
		Action->Activate();
	}
	return Action;
}
