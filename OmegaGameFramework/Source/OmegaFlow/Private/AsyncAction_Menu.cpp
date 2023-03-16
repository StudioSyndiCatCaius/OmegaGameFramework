// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_Menu.h"

#include "Kismet/GameplayStatics.h"
#include "Player/OmegaPlayerSubsystem.h"

void UAsyncAction_Menu::NativeShutdown(FGameplayTagContainer CloseTags, UObject* Context, const FString OutFlag)
{
	Closed.Broadcast(CloseTags, Context, OutFlag);
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
		if(LocalMenu)
		{
			LocalMenu->OnClosed.AddDynamic(this, &UAsyncAction_Menu::UAsyncAction_Menu::NativeShutdown);
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

UAsyncAction_Menu* UAsyncAction_Menu::OpenMenu(UObject* WorldContextObject, APlayerController* Player, const TSubclassOf<UMenu> MenuClass, UObject* Context, const FGameplayTagContainer OpenTags, const FString& OpenFlag)
{
	APlayerController* TempPlayer = nullptr;
	if(Player)
	{
		TempPlayer = Player;
	}
	else if(WorldContextObject)
	{
		TempPlayer = UGameplayStatics::GetPlayerController(WorldContextObject,0);
	}
	
	UAsyncAction_Menu* NewMenuNode = NewObject<UAsyncAction_Menu>();
	NewMenuNode->MenuRef = MenuClass;
	NewMenuNode->TagsRef = OpenTags;
	NewMenuNode->PlayerRef = TempPlayer;
	NewMenuNode->ContextRef = Context;
	NewMenuNode->FlagRef = OpenFlag;
	return NewMenuNode;
}
