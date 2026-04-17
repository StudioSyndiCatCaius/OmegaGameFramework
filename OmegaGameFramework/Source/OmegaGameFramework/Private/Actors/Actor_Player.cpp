// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Player.h"

#include "Components/AudioComponent.h"
#include "Components/Component_GameplayActor.h"
#include "Components/Component_AssetSquad.h"
#include "Components/Component_Combatant.h"
#include "Components/Component_InstancedActor.h"

void AOmegaPlayer::L_Print(const FString& str)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, str);
}

void AOmegaPlayer::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	LastPerSysCall+=DeltaTime;
	if(LastPerSysCall>=PersistentSystemFrequency)
	{
		LastPerSysCall=0.0;
		SetSystemsActive(Systems_Persistent,this,"Persistent",true);
	}
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}

void AOmegaPlayer::BeginPlay()
{
	SetSystemsActive(Systems_Auto,this,"Auto",true);
	Super::BeginPlay();
}

void AOmegaPlayer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(EndPlayReason==EEndPlayReason::Destroyed)
	{
		SystemStats.ShutdownAll(this,"OwnerDestroyed");
	}
	Super::EndPlay(EndPlayReason);
}

AOmegaPlayer::AOmegaPlayer()
{
	Combatant=CreateOptionalDefaultSubobject<UCombatantComponent>("Combatant");
	ActorID=CreateOptionalDefaultSubobject<UGameplayActorComponent>("ActorID");
	AssetSquad=CreateOptionalDefaultSubobject<UAssetSquadComponent>("AssetSquad");
	EntityInstances=CreateOptionalDefaultSubobject<UInstanceActorComponent>("Entity Instances");
}


void AOmegaPlayer::SetSystemsActive(TArray<TSubclassOf<AOmegaGameplaySystem>> Systems, UObject* Context,
	const FString& Flag, bool active,FOmegaCommonMeta meta)
{
	for(auto c : Systems)
	{
		if(c)
		{
			SetSystemActive(c,Context,Flag,active);
		}
	}
}

AOmegaGameplaySystem* AOmegaPlayer::SetSystemActive(TSubclassOf<AOmegaGameplaySystem> System, UObject* Context,
	const FString& Flag, bool active,FOmegaCommonMeta meta)
{
	if(System)
	{
		if(active)
		{
			UE_LOG(LogTemp, Log, TEXT("Player System %s - Attmeping activate "), *System->GetName());
			if(AOmegaGameplaySystem* s=Cast<AOmegaGameplaySystem>(SystemStats.Activate(System,Context,Flag,this,this,meta)))
			{
				return s;
			}
			return nullptr;
		}
		else
		{
			SystemStats.Shutdown(System,Context,Flag);
			return nullptr;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Failed to Start/Stop: system calss is null "));
	return nullptr;
}

bool AOmegaPlayer::IsSystemActive(TSubclassOf<AOmegaGameplaySystem> System)
{
	return SystemStats.IsSystemActive(System);
}
