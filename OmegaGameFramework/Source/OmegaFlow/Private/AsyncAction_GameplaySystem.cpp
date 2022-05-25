// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_GameplaySystem.h"

#include "OmegaGameplaySubsystem.h"


UAsyncAction_GameplaySystem* UAsyncAction_GameplaySystem::ActivateGameplaySystem
	(UOmegaGameplaySubsystem* Subsystem, const TSubclassOf<AOmegaGameplaySystem> SystemClass, UObject* Context, const FString Flag)
{
	UAsyncAction_GameplaySystem* NewSysNode = NewObject<UAsyncAction_GameplaySystem>();

	NewSysNode->SubSysRef = Subsystem;
	NewSysNode->LocalSystemClass = SystemClass;
	NewSysNode->LocalOpenFlag = Flag;
	if(Context)
	{
		NewSysNode->LocalContext = Context;
	}
	return NewSysNode;
}

void UAsyncAction_GameplaySystem::NativeShutdown(const FString Flag)
{
	OnShutdown.Broadcast(Flag);
	SetReadyToDestroy();
}

void UAsyncAction_GameplaySystem::Activate()
{
	bool IsAlreadyActiveSystem;
	SubSysRef->GetGameplaySystem(LocalSystemClass, IsAlreadyActiveSystem);
	
	if(!IsAlreadyActiveSystem)
	{
		AOmegaGameplaySystem* NewSystem = SubSysRef->ActivateGameplaySystem(LocalSystemClass, LocalContext, LocalOpenFlag);
		NewSystem->OnSystemShutdown.AddDynamic(this, &UAsyncAction_GameplaySystem::NativeShutdown);
	}
	else
	{
		Failed.Broadcast();
		SetReadyToDestroy();
	}
}
