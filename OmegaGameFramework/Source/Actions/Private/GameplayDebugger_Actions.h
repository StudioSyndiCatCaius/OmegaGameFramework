// Copyright Studio Syndicat 2021. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebuggerCategory.h"
#endif

#if WITH_GAMEPLAY_DEBUGGER

class ACTIONS_API FGameplayDebugger_Actions : public FGameplayDebuggerCategory
{
public:
	FGameplayDebugger_Actions();

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

	virtual void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
};

#endif // WITH_GAMEPLAY_DEBUGGER
