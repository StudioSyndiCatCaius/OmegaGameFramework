// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_GameplaySystem.h"

#include "Subsystems/Subsystem_Gameplay.h"


UAsyncAction_GameplaySystem* UAsyncAction_GameplaySystem::ActivateGameplaySystem
	(const UObject* WorldContextObject, const TSubclassOf<AOmegaGameplaySystem> SystemClass, UObject* Context, const FString Flag, FOmegaCommonMeta meta)
{
	UAsyncAction_GameplaySystem* NewSysNode = NewObject<UAsyncAction_GameplaySystem>();
	if(SystemClass)
	{
		NewSysNode->LocalSystemClass = SystemClass;
		NewSysNode->LocalOpenFlag = Flag;
		NewSysNode->Local_WorldContext = WorldContextObject;
		NewSysNode->in_meta = meta;
		if(Context)
		{
			NewSysNode->LocalContext = Context;
		}
	}

	return NewSysNode;
}

void UAsyncAction_GameplaySystem::NativeShutdown(UObject* Context, const FString Flag)
{
	OnShutdown.Broadcast(Context, Flag);
	SetReadyToDestroy();
}

void UAsyncAction_GameplaySystem::Native_Notify(UObject* Context, const FString Flag)
{
	Notify.Broadcast(Context,Flag);
}

void UAsyncAction_GameplaySystem::Activate()
{
	if(Local_WorldContext && Local_WorldContext->GetWorld())
	{
		if(LocalSystemClass)
		{
			bool IsAlreadyActiveSystem;
			SubSysRef = Local_WorldContext->GetWorld()->GetSubsystem<UOmegaGameplaySubsystem>();
			SubSysRef->GetGameplaySystem(LocalSystemClass, IsAlreadyActiveSystem);
		
			if(!IsAlreadyActiveSystem)
			{
				AOmegaGameplaySystem* NewSystem = SubSysRef->ActivateGameplaySystem(LocalSystemClass, LocalContext, LocalOpenFlag,in_meta);
				NewSystem->OnSystemShutdown.AddDynamic(this, &UAsyncAction_GameplaySystem::NativeShutdown);
				NewSystem->OnSystemNotify.AddDynamic(this, &UAsyncAction_GameplaySystem::Native_Notify);
			}
			else
			{
				Failed.Broadcast();
				SetReadyToDestroy();
			}
		}
		else
		{
			Failed.Broadcast();
			SetReadyToDestroy();
		}
	}
	else
	{
		Failed.Broadcast();
		SetReadyToDestroy();
	}
	
}
