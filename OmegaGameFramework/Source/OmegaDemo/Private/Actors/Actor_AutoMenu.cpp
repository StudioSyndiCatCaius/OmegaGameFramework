// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_AutoMenu.h"
#include "Interfaces/I_ObjectTraits.h"
#include "Components/TextRenderComponent.h"
#include "Misc/OmegaGameMode.h"
#include "Subsystems/Subsystem_Player.h"
#include "Subsystems/Subsystem_World.h"
#include "Widget/Menu.h"

void AOmegaAutoMenu::Native_OnMenuClosed(FGameplayTagContainer GameplayTags, UObject* Context, FString Flag)
{
	TSoftObjectPtr<UWorld> _inlevel=LevelOpenOnClose;
	if(LevelOpenOnCloseFlag.Contains(Flag))
	{
		_inlevel=LevelOpenOnCloseFlag.FindOrAdd(Flag);
	}
	if(_inlevel.IsValid())
	{
		GetWorld()->GetSubsystem<UOmegaSubsystem_World>()->GetWorldManager()->Zone_TransitToLevel(_inlevel,LevelTransitSpawnID);
	}
}

void AOmegaAutoMenu::L_OpenMenu()
{
	UOmegaSubsystem_Player* _sys = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaSubsystem_Player>();
	REF_Menu=_sys->OpenMenu(Menu,MenuContext,MenuTags,MenuFlag);
	REF_Menu->OnClosed.AddDynamic(this, &AOmegaAutoMenu::Native_OnMenuClosed);
}

AOmegaAutoMenu::AOmegaAutoMenu()
{
	AutoPossessPlayer=EAutoReceiveInput::Player0;
}

void AOmegaAutoMenu::BeginPlay()
{
	if(AOmegaGameMode* _gm=Cast<AOmegaGameMode>(GetWorld()->GetAuthGameMode()))
	{
		_gm->OnLoadEventFinish.AddDynamic(this,&AOmegaAutoMenu::L_OpenMenu);
	}
	else
	{
		L_OpenMenu();
	}
	Super::BeginPlay();
}
