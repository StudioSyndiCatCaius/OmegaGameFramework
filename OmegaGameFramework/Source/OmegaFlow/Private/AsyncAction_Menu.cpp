// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_Menu.h"

#include "Player/OmegaPlayerSubsystem.h"

void UAsyncAction_Menu::NativeShutdown(FGameplayTagContainer CloseTags, const FString OutFlag)
{
	Closed.Broadcast(CloseTags, OutFlag);
	SetReadyToDestroy();
}

void UAsyncAction_Menu::Activate()
{
	UOmegaPlayerSubsystem* SubsystemRef = PlayerRef->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
	bool IsMenuOpen;
	SubsystemRef->GetMenu(MenuRef, IsMenuOpen);
	if(!IsMenuOpen)
	{
		UMenu* LocalMenu = SubsystemRef->OpenMenu(MenuRef, ContextRef, TagsRef, FlagRef);
		LocalMenu->OnClosed.AddDynamic(this, &UAsyncAction_Menu::UAsyncAction_Menu::NativeShutdown);
	}
	else
	{
		Failed.Broadcast();
		SetReadyToDestroy();
	}
}

UAsyncAction_Menu* UAsyncAction_Menu::OpenMenu(APlayerController* Player, const TSubclassOf<UMenu> MenuClass, UObject* Context, const FGameplayTagContainer OpenTags, const FString& OpenFlag)
{
	UAsyncAction_Menu* NewMenuNode = NewObject<UAsyncAction_Menu>();
	NewMenuNode->MenuRef = MenuClass;
	NewMenuNode->TagsRef = OpenTags;
	NewMenuNode->PlayerRef = Player;
	NewMenuNode->ContextRef = Context;
	NewMenuNode->FlagRef = OpenFlag;
	return NewMenuNode;
}
