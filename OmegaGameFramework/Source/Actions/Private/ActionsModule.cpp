// Copyright Studio Syndicat 2021. All Rights Reserved. 

#include "ActionsModule.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebugger.h"
#include "GameplayDebugger_Actions.h"
#endif // WITH_GAMEPLAY_DEBUGGER


DEFINE_LOG_CATEGORY(LogActions)

#define LOCTEXT_NAMESPACE "ActionsModule"

void FActionsModule::StartupModule()
{
	UE_LOG(LogActions, Log, TEXT("ActionsExtension: Log Started"));

	// Register Gameplay debugger
#if WITH_GAMEPLAY_DEBUGGER
	IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
	GameplayDebuggerModule.RegisterCategory("Actions", IGameplayDebugger::FOnGetCategory::CreateStatic(&FGameplayDebugger_Actions::MakeInstance), EGameplayDebuggerCategoryState::EnabledInGameAndSimulate);
	GameplayDebuggerModule.NotifyCategoriesChanged();
#endif
}

void FActionsModule::ShutdownModule()
{
	UE_LOG(LogActions, Log, TEXT("ActionsExtension: Log Ended"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FActionsModule, Actions)