// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncAction_Menu.h"

#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Player.h"

void UAsyncAction_Menu::NativeShutdown(FGameplayTagContainer CloseTags, UObject* Context, const FString OutFlag)
{
	if (SubmenuMetaRef.ParentMenu && SubmenuMetaRef.ParentMenu->bIsOpen)
	{
		SubmenuMetaRef.ParentMenu->SetSubstate_Index(SubmenuMetaRef.ParentSubstate_OnClose);
	}
	Closed.Broadcast(CloseTags, Context, OutFlag);
	SetReadyToDestroy();
}

void UAsyncAction_Menu::Activate()
{
	UOmegaSubsystem_Player* SubsystemRef = PlayerRef->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
	bool IsMenuOpen;
	SubsystemRef->GetMenu(MenuRef, IsMenuOpen);
	if(!IsMenuOpen)
	{
		if(UMenu* LocalMenu = SubsystemRef->OpenMenu(MenuRef, ContextRef, TagsRef, FlagRef,true,in_meta))
		{
			
			if (SubmenuMetaRef.ParentMenu)
			{
				SubmenuMetaRef.ParentMenu->SetSubstate_Index(SubmenuMetaRef.ParentSubstate_OnOpen);
				LocalMenu->Priority = SubmenuMetaRef.ParentMenu->Priority + SubmenuMetaRef.OffsetPriorityFromParent;
			}
			else if (SubmenuMetaRef.OffsetPriorityFromParent != 0)
			{
				LocalMenu->Priority += SubmenuMetaRef.OffsetPriorityFromParent;
			}
			LocalMenu->OnClosed.AddDynamic(this, &UAsyncAction_Menu::NativeShutdown);
		}
		else
		{
			Failed.Broadcast(FGameplayTagContainer(), nullptr, "");
			SetReadyToDestroy();
		}

	}
	else
	{
		Failed.Broadcast(FGameplayTagContainer(), nullptr, "");
		SetReadyToDestroy();
	}
}

UAsyncAction_Menu* UAsyncAction_Menu::OpenMenu(UObject* WorldContextObject, APlayerController* Player, const TSubclassOf<UMenu> MenuClass, UObject* Context, const FGameplayTagContainer OpenTags, const FString& OpenFlag,
	FOmegaCommonMeta meta, FOmegaAsyncSubmenuConfig SubmenuConfig)
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
	NewMenuNode->RegisterWithGameInstance(WorldContextObject);
	NewMenuNode->MenuRef = MenuClass;
	NewMenuNode->in_meta = meta;
	NewMenuNode->SubmenuMetaRef = SubmenuConfig;
	NewMenuNode->TagsRef = OpenTags;
	NewMenuNode->PlayerRef = TempPlayer;
	NewMenuNode->ContextRef = Context;
	NewMenuNode->FlagRef = OpenFlag;
	return NewMenuNode;
}
