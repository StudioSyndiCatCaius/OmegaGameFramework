// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "GameplayDebugger_Actions.h"

#include <Engine/World.h>
#include <GameFramework/Actor.h>
#include <GameFramework/Pawn.h>
#include <GameFramework/PlayerController.h>

#include "ActionsSubsystem.h"


#if WITH_GAMEPLAY_DEBUGGER

FGameplayDebugger_Actions::FGameplayDebugger_Actions()
{}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebugger_Actions::MakeInstance()
{
	return MakeShareable(new FGameplayDebugger_Actions());
}

void FGameplayDebugger_Actions::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	UWorld* World = OwnerPC->GetWorld();

	UGameInstance* GI = World? World->GetGameInstance() : nullptr;
	if (!GI)
	{
		return;
	}

	auto* Subsystem = GI->GetSubsystem<UActionsSubsystem>();
	check(Subsystem);

	Subsystem->DescribeOwnerToGameplayDebugger(OwnerPC, TEXT("Player Controller"), *this);

	if (DebugActor)
	{
		Subsystem->DescribeOwnerToGameplayDebugger(DebugActor, TEXT("Actor"), *this);

		if (const APawn* DebugPawn = Cast<APawn>(DebugActor))
		{
			AController* DebugController = DebugPawn->GetController();
			if (DebugController && OwnerPC != DebugController)
			{
				Subsystem->DescribeOwnerToGameplayDebugger(DebugController, TEXT("Controller"), *this);
			}
		}
	}
}
#endif // ENABLE_GAMEPLAY_DEBUGGER
