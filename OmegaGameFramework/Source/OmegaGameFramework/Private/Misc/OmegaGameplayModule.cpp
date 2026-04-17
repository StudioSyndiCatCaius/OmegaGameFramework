// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Misc/OmegaGameplayModule.h"

#include "Components/Component_Combatant.h"
#include "Subsystems/Subsystem_World.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "UObject/Object.h"
#include "UObject/UObjectGlobals.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/GeneralDataObject.h"

UOmegaGameplayModule::UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
}
UWorld* UOmegaGameplayModule::GetWorld() const
{
	if(GetGameInstance()) { return GetGameInstance()->GetWorld(); } return nullptr;
}

void UOmegaGameplayModule::Native_Initialize(UOmegaSubsystem_GameInstance* Subsystem)
{
	if (Subsystem)
	{
		Ref_GamInst=Subsystem->GetGameInstance();
		REF_OwningManager=Subsystem;
		WorldPrivate=Subsystem->GetWorld();
	}
	if((REF_OwningManager = GetGameInstance()->GetSubsystem<UOmegaSubsystem_GameInstance>()) != nullptr)
	{
		REF_OwningManager->OnGlobalEvent.AddDynamic(this, &UOmegaGameplayModule::OnGlobalEvent);
		REF_OwningManager->OnTaggedGlobalEvent.AddDynamic(this, &UOmegaGameplayModule::OnTaggedGlobalEvent);
		REF_OwningManager->OnNewLevel.AddDynamic(this, &UOmegaGameplayModule::Native_OnLevelOpened);
	}
	if(UOmegaSaveSubsystem* _sys = GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>())
	{
		_sys->OnNewGameStarted.AddDynamic(this, &UOmegaGameplayModule::GameFileStarted);
		GameFileStarted(_sys->ActiveSaveData,FGameplayTagContainer());
	}

	
	Initialized();
}

TArray<AActor*> UOmegaGameplayModule::ActorGroup_Filter_Implementation(FGameplayTag Tag,
	const TArray<AActor*>& In) const
{
	return In;
}


void UOmegaGameplayModule::L_OnGameSystemChange(AOmegaGameplaySystem* system, UObject* context, const FString& flag,
                                                bool bActive)
{
	if(bActive)
	{
		OnGameplaySystem_Activate(system,context,flag,system->SystemMeta);
	}
	else
	{
		OnGameplaySystem_Shutdown(system,context,flag,system->SystemMeta);
	}
}

void UOmegaGameplayModule::Native_OnLevelOpened(FString LevelName, AOmegaGameMode* GameMode)
{
	//Activate Game Systems
	for (TSubclassOf<AOmegaGameplaySystem> TempSystem : GetAutoGameplaySystems())
	{
		GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->ActivateGameplaySystem(TempSystem, this, "None");
	}

	OnLevelOpened(LevelName, GameMode);

	
	if(UOmegaSubsystem_World* sub_a=GetWorld()->GetSubsystem<UOmegaSubsystem_World>())
	{
		sub_a->OnActorTagEvent.AddDynamic(this,&UOmegaGameplayModule::OnActor_TagEvent);
		sub_a->OnActorInteraction.AddDynamic(this,&UOmegaGameplayModule::OnActor_Interaction);
		sub_a->OnActorGroupChange.AddDynamic(this,&UOmegaGameplayModule::OnActor_RegisteredToGroup);
		sub_a->OnActorIdentityRegistered.AddDynamic(this,&UOmegaGameplayModule::L_ActorIdentityRegistered);
		
		sub_a->OnGameplaySystemActiveStateChange.AddDynamic(this,&UOmegaGameplayModule::L_OnGameSystemChange);
		sub_a->OnCombatantRegistered.AddDynamic(this,&UOmegaGameplayModule::L_CombatantInit);
		sub_a->OnCombatantUnegistered.AddDynamic(this,&UOmegaGameplayModule::L_CombatantUninit);
	}

}

void UOmegaGameplayModule::L_ActorIdentityRegistered(AActor* Actor, UGameplayActorComponent* Component, bool Registered)
{
	if(Actor)
	{
		if(Registered && !registered_GameplayActors.Contains(Component))
		{
			registered_GameplayActors.AddUnique(Component);
			Actor->OnActorBeginOverlap.AddDynamic(this,&UOmegaGameplayModule::OnActor_BeginOverlap);
			Actor->OnActorEndOverlap.AddDynamic(this,&UOmegaGameplayModule::OnActor_EndOverlap);
			Actor->OnActorHit.AddDynamic(this, &UOmegaGameplayModule::OnActor_Hit);
			Actor->OnBeginCursorOver.AddDynamic(this, &UOmegaGameplayModule::OnActor_BeginCursorOver);
			Actor->OnEndCursorOver.AddDynamic(this, &UOmegaGameplayModule::OnActor_EndCursorOver);
			Actor->OnClicked.AddDynamic(this, &UOmegaGameplayModule::OnActor_Clicked);
		}
		else if (!Registered && registered_GameplayActors.Contains(Component))
		{
			registered_GameplayActors.Remove(Component);
		}
	}
	OnActor_IdentityRegistered(Actor,Component,Registered);
}

void UOmegaGameplayModule::L_CombatantInit(UCombatantComponent* combatant)
{
	OnCombatant_Registered(combatant);
	if(combatant)
	{
		combatant->OnDamaged.AddDynamic(this,&UOmegaGameplayModule::OnCombatant_Damaged);
		combatant->OnCombatantNotify.AddDynamic(this,&UOmegaGameplayModule::OnCombatant_Notify);
	}
}

void UOmegaGameplayModule::L_CombatantUninit(UCombatantComponent* combatant)
{
	OnCombatant_Unregistered(combatant);
}


UGameInstance* UOmegaGameplayModule::GetGameInstance() const
{
	if (Ref_GamInst) { return Ref_GamInst; } return Cast<UGameInstance>(GetOuter());
}

bool UOmegaGameplayModule::GameFileSaved_Implementation(UOmegaSaveGame* SaveFile)
{
	return true;
}




