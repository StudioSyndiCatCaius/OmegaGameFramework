// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaSettings.h"

UOmegaSettings::UOmegaSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TArray<TSubclassOf<UOmegaGameplayModule>> UOmegaSettings::GetGameplayModuleClasses() const
{
	TArray<TSubclassOf<UOmegaGameplayModule>> ModuleClasses;
	for(FSoftClassPath TempPath : RegisteredGameplayModules)
	{
		UClass* const LocalClass = TempPath.IsValid() ? LoadObject<UClass>(NULL, *TempPath.ToString()) : nullptr;
		ModuleClasses.Add(LocalClass);
	}
	return ModuleClasses;
}

UClass* UOmegaSettings::GetOmegaGameSaveClass() const
{
	UClass* const LocalSaveClass = GameSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GameSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGame::StaticClass();
}

UClass* UOmegaSettings::GetOmegaGlobalSaveClass() const
{
	UClass* const LocalSaveClass = GlobalSaveClass.IsValid() ? LoadObject<UClass>(NULL, *GlobalSaveClass.ToString()) : nullptr;
	return (LocalSaveClass != nullptr) ? LocalSaveClass : UOmegaSaveGlobal::StaticClass();
}
