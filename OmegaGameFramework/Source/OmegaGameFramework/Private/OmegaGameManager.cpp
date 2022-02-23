// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameManager.h"
#include "Gameplay/OmegaGameplayModule.h"
#include "Engine/GameInstance.h"

void UOmegaGameManager::Initialize(FSubsystemCollectionBase& Colection)
{
	for(TSubclassOf<UOmegaGameplayModule> TempModule : GetMutableDefault<UOmegaSettings>()->GetGameplayModuleClasses())
	{
		if(TempModule)
		{
			//UObject* TempOuter = GetGameInstance();
			UOmegaGameplayModule* NewModule = NewObject<UOmegaGameplayModule>(GetGameInstance(), TempModule);
			ActiveModules.Add(NewModule);
			NewModule->Native_Initialize();
		}
	}
}

void UOmegaGameManager::Deinitialize()
{
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		TempModule->Shutdown();
	}
	Super::Deinitialize();
}

UOmegaGameplayModule* UOmegaGameManager::GetGameplayModule(TSubclassOf<UOmegaGameplayModule> Module)
{
	for(UOmegaGameplayModule* TempModule : ActiveModules)
	{
		if(TempModule->GetClass() == Module)
		{
			return TempModule;
		}
	}
	return nullptr;
}

TArray<UOmegaGameplayModule*> UOmegaGameManager::GetGameplayModules()
{
	return ActiveModules;
}
