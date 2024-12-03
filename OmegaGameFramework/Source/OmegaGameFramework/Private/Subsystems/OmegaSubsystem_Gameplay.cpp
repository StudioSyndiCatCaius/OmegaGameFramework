// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_Gameplay.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Functions/OmegaFunctions_Combatant.h"


void UOmegaGameplaySubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	ActiveSystems.Empty();
}

AOmegaGameplaySystem* UOmegaGameplaySubsystem::ActivateGameplaySystem(TSubclassOf<AOmegaGameplaySystem> Class, UObject* Context, FString Flag)
{
	if (Class)
	{
		struct FActorSpawnParameters SystemParams;
		bool bSystemExists;
		AOmegaGameplaySystem* DummySystem = GetGameplaySystem(Class, bSystemExists);
		if(DummySystem && DummySystem->local_InRestart)
		{
			bSystemExists = false;
		}

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
			DummySystem->ActivationFlag=Flag;
			
			Local_RefreshSystemState();
			
			//Finish & Activate
			DummySystem->SystemActivated(Context, Flag);
			OnGameplaySystemActiveStateChange.Broadcast(DummySystem,Context,Flag,true);
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

TArray<AOmegaGameplaySystem*> UOmegaGameplaySubsystem::GetActiveGameplaySystems(bool bIncludeSystemsInShutdown)
{
	TArray<AOmegaGameplaySystem*> OutSystems;
	for(auto* TempSystem : ActiveSystems)
	{
		if(TempSystem && (!TempSystem->bIsInShutdown || bIncludeSystemsInShutdown))
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

FGameplayTagContainer UOmegaGameplaySubsystem::GetBlockedSystemTags()
{
	FGameplayTagContainer out = ExtraBlockedSystemTags;
	for(const auto* TempSys : GetActiveGameplaySystems(true))
	{
		out.AppendTags(TempSys->BlockSystemTags);
	}
	return out;
}

bool UOmegaGameplaySubsystem::IsSystemTagBlocked(FGameplayTagContainer Tags)
{
	return GetBlockedSystemTags().HasAnyExact(Tags);;
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

void UOmegaGameplaySubsystem::SetSystemTagsBlocked(FGameplayTagContainer Tags, bool bBlocked)
{
	if(bBlocked)
	{
		ExtraBlockedSystemTags.AppendTags(Tags);
	}
	else
	{
		ExtraBlockedSystemTags.RemoveTags(Tags);
	}
}

void UOmegaGameplaySubsystem::Local_RefreshSystemState()
{
	//Shutdown Blocked Systems
	for(auto* TempSys : GetActiveSystemsWithTags(GetBlockedSystemTags()))
	{
		TempSys->Shutdown(this, "Canceled");
	}
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
	if(GlobalActorBindingRefs.Contains(Binding))
	{
		return GlobalActorBindingRefs.FindOrAdd(Binding);
	}
	return nullptr;
}

void UOmegaGameplaySubsystem::SetActorsPaused(FGameplayTagContainer Tags, bool bIsPaused)
{
	for(auto* TempComp : PauseComps)
	{
		if(TempComp && (Tags.HasTag(TempComp->PauseCategory) || Tags.IsEmpty()))
		{
			TempComp->SetPausedActor(bIsPaused);
		}
	}
}


//############################################################################################################################################################
//------------------------------------------------------------------------------
// GAMEPLAY PAUSE COMPONENT
//------------------------------------------------------------------------------
//############################################################################################################################################################

void UGameplayPauseComponent::BeginPlay()
{
	if(GetSubsys())
	{
		GetSubsys()->PauseComps.AddUnique(this);
		Super::BeginPlay();
	}
}

void UGameplayPauseComponent::BeginDestroy()
{
	if(GetSubsys())
	{
		GetSubsys()->PauseComps.Remove(this);
		
	}
	Super::BeginDestroy();
}

UOmegaGameplaySubsystem* UGameplayPauseComponent::GetSubsys()
{
	if(!SubsysRef)
	{
		if(GetWorld())
		{
			SubsysRef = GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
		}
	}
	return  SubsysRef;
}

