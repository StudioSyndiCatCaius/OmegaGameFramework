// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaGameplaySubsystem.h"

#include "OmegaGameplaySystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Gameplay/Combatant/CombatantFilter.h"


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

		//Fail if blocked
		if(IsSystemTagBlocked(GetMutableDefault<AOmegaGameplaySystem>(Class)->SystemTags) ||
			IsSystemTagActive(GetMutableDefault<AOmegaGameplaySystem>(Class)->BlockedOnSystemTags))
		{
			return nullptr;
		}
		
		if (!bSystemExists)
		{
			const FTransform SpawnWorldPoint;
			DummySystem = GetWorld()->SpawnActorDeferred<AOmegaGameplaySystem>(Class, SpawnWorldPoint, nullptr);
			if(!DummySystem)
			{
				return nullptr;
			}
			DummySystem->SubsysRef = this;
			UGameplayStatics::FinishSpawningActor(DummySystem, SpawnWorldPoint);
			ActiveSystems.Add(DummySystem);
			if(Context)
			{
				DummySystem->ContextObject = Context;
			}

			//Shutdown Blocked Systems
			for(auto* TempSys : GetActiveSystemsWithTags(DummySystem->BlockSystemTags))
			{
				TempSys->Shutdown(DummySystem, "Canceled");
			}
			
			//Finish & Activate
			DummySystem->SystemActivated(Context, Flag);
			
			return DummySystem;
		}
	}

	return nullptr;
}

bool UOmegaGameplaySubsystem::ShutdownGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context, FString Flag)
{
	bool bIsActive = false;
	AOmegaGameplaySystem* TempSystem = GetGameplaySystem(Class, bIsActive);
	if (TempSystem)
	{
		TempSystem->Shutdown(Context, Flag);
		return true;
	}
	return false;
}

AOmegaGameplaySystem* UOmegaGameplaySubsystem::GetGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, bool& bIsActive)
{
	AOmegaGameplaySystem* DummyObject = nullptr;

	for (class AOmegaGameplaySystem* TempSystem : ActiveSystems)
	{
		if (TempSystem->GetClass()->IsChildOf(Class) && !DummyObject)
		{
			DummyObject = TempSystem;
		}
	}
	
	if (DummyObject && !DummyObject->bIsInShutdown)
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

TArray<AOmegaGameplaySystem*> UOmegaGameplaySubsystem::GetActiveGameplaySystems()
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for(auto* TempSystem : ActiveSystems)
	{
		if(TempSystem && !TempSystem->bIsInShutdown)
		{
			OutSystems.AddUnique(TempSystem);
		}
	}
	return OutSystems;
}

TArray<AOmegaGameplaySystem*> UOmegaGameplaySubsystem::GetActiveGameplaySystemsWithInterface(
	TSubclassOf<UInterface> Interface)
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for(auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->GetClass()->ImplementsInterface(Interface))
		{
			OutSystems.Add(TempSys);
		}
	}
	return OutSystems;
}

bool UOmegaGameplaySubsystem::IsSystemTagBlocked(FGameplayTagContainer Tags)
{
	for(auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->BlockSystemTags.HasAnyExact(Tags))
		{
			return true;
		}
	}
	return false;
}

bool UOmegaGameplaySubsystem::IsSystemTagActive(FGameplayTagContainer Tags)
{
	for(auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->SystemTags.HasAnyExact(Tags))
		{
			return true;
		}
	}
	return false;
}

TArray<AOmegaGameplaySystem*> UOmegaGameplaySubsystem::GetActiveSystemsWithTags(FGameplayTagContainer Tags)
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for (auto* TempSys : GetActiveGameplaySystems())
	{
		if(TempSys->SystemTags.HasAnyExact(Tags))
		{
			OutSystems.AddUnique(TempSys);
		}
	}
	return OutSystems;
}

APlayerController* UOmegaGameplaySubsystem::GetPlayerController(int32 Index)
{
	return UGameplayStatics::GetPlayerController(this, Index);
}

void UOmegaGameplaySubsystem::SetGameplayState(FGameplayTag State)
{
	if(State != GameplayState)
	{
		GameplayState = State;
		OnGameplayStateChange.Broadcast(GameplayState);
	}
}

void UOmegaGameplaySubsystem::Native_RegisterCombatant(UCombatantComponent* Combatant, bool bRegistered)
{
	if(bRegistered)
	{
		ActiveCombatants.AddUnique(Combatant);
		Combatant->OnDamaged.AddDynamic(this, &UOmegaGameplaySubsystem::UOmegaGameplaySubsystem::Native_OnDamaged);
		OnCombatantRegistered.Broadcast(Combatant);
	}
	else
	{
		ActiveCombatants.Remove(Combatant);
		OnCombatantUnegistered.Broadcast(Combatant);
	}
		
}

void UOmegaGameplaySubsystem::Native_OnDamaged(UCombatantComponent* Combatant, UOmegaAttribute* Attribute,
	float FinalDamage, UCombatantComponent* Instigator, UOmegaDamageType* DamageType, FHitResult Hit)
{
	OnCombatantDamaged.Broadcast(Combatant, Attribute, FinalDamage, Instigator, DamageType, Hit);
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

TArray<UCombatantComponent*> UOmegaGameplaySubsystem::RunCustomCombatantFilter(TSubclassOf<UCombatantFilter> FilterClass,
	UCombatantComponent* Instigator, const TArray<UCombatantComponent*>& Combatants)
{
	TArray<UCombatantComponent*> OutCombatants;
	if(FilterClass)
	{
		
		OutCombatants = NewObject<UCombatantFilter>(this, FilterClass)->FilterCombatants(Instigator, Combatants);
	}
	return OutCombatants;
}

void UOmegaGameplaySubsystem::SetGlobalActorBinding(FName Binding, AActor* Actor)
{
	if(Actor)
	{
		GlobalActorBindingRefs.Add(Binding, Actor);
	}
}

void UOmegaGameplaySubsystem::ClearGlobalActorBinding(FName Binding)
{
	GlobalActorBindingRefs.Remove(Binding);
}

AActor* UOmegaGameplaySubsystem::GetGlobalActorBinding(FName Binding)
{
	if(GlobalActorBindingRefs.FindOrAdd(Binding))
	{
		return GlobalActorBindingRefs.FindOrAdd(Binding);
	}
	return nullptr;
}