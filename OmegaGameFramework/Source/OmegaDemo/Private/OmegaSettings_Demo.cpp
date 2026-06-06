// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Demo.h"
#include "Actors/OmegaGameplaySystem.h"
#include "Widget/Menu.h"

UOmegaSettings_Demo::UOmegaSettings_Demo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	System_DialogueFlow=TSoftClassPtr<AOmegaGameplaySystem>(FSoftClassPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_Dialog.sys_OMEGA_E_Dialog_C")));
	
	Menu_Choice=TSoftClassPtr<UMenu>(FSoftClassPath(TEXT("/OmegaGameFramework/Blueprints/Menus/Menu_OMEGA_Choice.Menu_OMEGA_Choice_C")));
	Menu_Confirmation=TSoftClassPtr<UMenu>(FSoftClassPath(TEXT("/OmegaGameFramework/Blueprints/Menus/Menu_OMEGA_Confirmation.Menu_OMEGA_Confirmation_C")));
	Menu_Info=TSoftClassPtr<UMenu>(FSoftClassPath(TEXT("/OmegaGameFramework/Blueprints/Menus/Menu_OMEGA_Info.Menu_OMEGA_Info_C")));
	
}


void UOmegaFunctions_DEMO::GetOmegaDemo_Systems(TSubclassOf<AOmegaGameplaySystem>& DialogFlow,TSubclassOf<AOmegaGameplaySystem>& Encounter)
{
	UOmegaSettings_Demo* set=GetMutableDefault<UOmegaSettings_Demo>();
	DialogFlow=set->System_DialogueFlow.LoadSynchronous();
	Encounter=set->System_Encounter.LoadSynchronous();
}

void UOmegaFunctions_DEMO::GetOmegaDemo_Menus(TSubclassOf<UMenu>& Confirm, TSubclassOf<UMenu>& Info,
	TSubclassOf<UMenu>& Choice)
{
	UOmegaSettings_Demo* set=GetMutableDefault<UOmegaSettings_Demo>();
	Confirm=set->Menu_Confirmation.LoadSynchronous();
	Info=set->Menu_Info.LoadSynchronous();
	Choice=set->Menu_Choice.LoadSynchronous();
}


