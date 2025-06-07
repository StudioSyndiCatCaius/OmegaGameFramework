// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Actor_AutoMenu.h"
#include "Components/Component_ActorConfig.h"
#include "Interfaces/OmegaInterface_ObjectTraits.h"
#include "Components/TextRenderComponent.h"
#include "Subsystems/OmegaSubsystem_Player.h"
#include "Subsystems/OmegaSubsystem_Zone.h"

void AOmegaAutoMenu::Native_OnMenuClosed(FGameplayTagContainer GameplayTags, UObject* Context, FString Flag)
{
	TSoftObjectPtr<UWorld> _inlevel=LevelOpenOnClose;
	if(LevelOpenOnCloseFlag.Contains(Flag))
	{
		_inlevel=LevelOpenOnCloseFlag.FindOrAdd(Flag);
	}
	if(_inlevel.IsValid())
	{
		GetWorld()->GetSubsystem<UOmegaZoneSubsystem>()->TransitPlayerToLevel(_inlevel,LevelTransitSpawnID);
	}
}

AOmegaAutoMenu::AOmegaAutoMenu()
{
	AutoPossessPlayer=EAutoReceiveInput::Player0;
}

void AOmegaAutoMenu::BeginPlay()
{
	UOmegaPlayerSubsystem* _sys = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>();
	REF_Menu=_sys->OpenMenu(Menu,MenuContext,MenuTags,MenuFlag);
	REF_Menu->OnClosed.AddDynamic(this, &AOmegaAutoMenu::Native_OnMenuClosed);
	Super::BeginPlay();
}
