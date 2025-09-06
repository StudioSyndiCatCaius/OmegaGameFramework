// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Actor_Player.h"

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
}


void AOmegaPlayer::SetSystemsActive(TArray<TSubclassOf<AOmegaPlayerSystem>> Systems, UObject* Context,
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

AOmegaPlayerSystem* AOmegaPlayer::SetSystemActive(TSubclassOf<AOmegaPlayerSystem> System, UObject* Context,
	const FString& Flag, bool active,FOmegaCommonMeta meta)
{
	if(System)
	{
		if(active)
		{
			UE_LOG(LogTemp, Log, TEXT("Player System %s - Attmeping activate "), *System->GetName());
			if(AOmegaPlayerSystem* s=Cast<AOmegaPlayerSystem>(SystemStats.Activate(System,Context,Flag,this,this,meta)))
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
	UE_LOG(LogTemp, Warning, TEXT("Failed to Start/Stop: %s -- system calss is null "), *System->GetName());
	return nullptr;
}

bool AOmegaPlayer::IsSystemActive(TSubclassOf<AOmegaPlayerSystem> System)
{
	return SystemStats.IsSystemActive(System);
}
