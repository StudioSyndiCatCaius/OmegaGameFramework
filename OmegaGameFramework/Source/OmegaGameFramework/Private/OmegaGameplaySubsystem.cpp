// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameplaySubsystem.h"

#include "OmegaGameplaySystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"

void UOmegaGameplaySubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	ActiveSystems.Empty();
	//TArray<class TSubclassOf<AOmegaGameplaySystem>> PrepGameSys = GetMutableDefault<UOmegaSettings>()->AutoActivatedGameplaySystems;
	//static bool ValidGlobalSave;
	//AOmegaGameplaySystem* DummySystem;

	
	//if (UGameplayStatics::GetGameInstance(this))
	//{
		//for (TSubclassOf<AOmegaGameplaySystem> TempSys : PrepGameSys)
		//{
		//	ActivateGameplaySystem(TempSys, this, "none", DummySystem);
		//}
	//}

}

AOmegaGameplaySystem* UOmegaGameplaySubsystem::ActivateGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context, FString Flag)
{
	if (Class)
	{
		struct FActorSpawnParameters SystemParams;
		bool bSystemExists;
		AOmegaGameplaySystem* DummySystem = GetGameplaySystem(Class, bSystemExists);;

		if (!bSystemExists)
		{
			FTransform SpawnWorldPoint;
			DummySystem = GetWorld()->SpawnActorDeferred<AOmegaGameplaySystem>(Class, SpawnWorldPoint, nullptr);
			DummySystem->SubsysRef = this;
			UGameplayStatics::FinishSpawningActor(DummySystem, SpawnWorldPoint);
			ActiveSystems.Add(DummySystem);
			DummySystem->SystemActivated(Context, Flag);
			return DummySystem;
		}
	}

	return nullptr;
}

bool UOmegaGameplaySubsystem::ShutdownGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, FString Flag)
{
	bool bIsActive = false;
	AOmegaGameplaySystem* TempSystem = GetGameplaySystem(Class, bIsActive);
	if (TempSystem)
	{
		TempSystem->Shutdown(Flag);
		return true;
	}
	return false;
}

AOmegaGameplaySystem* UOmegaGameplaySubsystem::GetGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive)
{
	AOmegaGameplaySystem* DummyObject = nullptr;

	for (class AOmegaGameplaySystem* TempSystem : ActiveSystems)
	{
		if (TempSystem->GetClass() == Class && !DummyObject)
		{
			DummyObject = TempSystem;
		}
	}
	
	if (DummyObject)
	{
		bIsActive = true;
		return DummyObject;
	}
	else
	{
		bIsActive = false;
		return nullptr;
	}
}

APlayerController* UOmegaGameplaySubsystem::GetPlayerController(int32 Index)
{
	return UGameplayStatics::GetPlayerController(this, Index);
}

void UOmegaGameplaySubsystem::Native_RegisterCombatant(UCombatantComponent* Combatant, bool bRegistered)
{
	if(bRegistered)
	{
		ActiveCombatants.AddUnique(Combatant);
		OnCombatantRegistered.Broadcast(Combatant);
	}
	else
	{
		ActiveCombatants.Remove(Combatant);
		OnCombatantUnegistered.Broadcast(Combatant);
	}
		
}


TArray<UCombatantComponent*> UOmegaGameplaySubsystem::GetAllCombatants()
{
	TArray<UCombatantComponent*> OutCombatants;
	for(UCombatantComponent* TempCombatant : ActiveCombatants)
	{
		if(TempCombatant->IsValidLowLevel())
		{
			OutCombatants.Add(TempCombatant);
		}
	}
	return OutCombatants;
}

void UOmegaGameplaySubsystem::NativeRemoveSystem(AOmegaGameplaySystem* System)
{
	if (ActiveSystems.Contains(System))
	{
		ActiveSystems.Remove(System);
	}
}
