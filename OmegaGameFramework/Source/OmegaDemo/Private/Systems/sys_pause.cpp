// Fill out your copyright notice in the Description page of Project Settings.

#include "Systems/sys_pause.h"

#include "Functions/F_Actor.h"
#include "Kismet/GameplayStatics.h"

// ------------------------------------------------------------------------------------------------------------
// Pause
// ------------------------------------------------------------------------------------------------------------

AOmegaDemoSystem_Pause::AOmegaDemoSystem_Pause()
{
	BlockSystemTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("SYSTEM.Exploration")));
}

// ------------------------------------------------------------------------------------------------------------
// Menu
// ------------------------------------------------------------------------------------------------------------

AOmegaDemoSystem_Menu::AOmegaDemoSystem_Menu()
{
	BlockSystemTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("SYSTEM.Exploration")));
	PauseActorTags.AddTag(FGameplayTag::RequestGameplayTag(TEXT("Actor.Type.Character")));
}

void AOmegaDemoSystem_Menu::BeginPlay()
{
	Super::BeginPlay();
}

void AOmegaDemoSystem_Menu::SystemActivated_Implementation(UObject* Context, const FString& Flag)
{
	L_SetState(true);
	Super::SystemActivated_Implementation(Context, Flag);
}

void AOmegaDemoSystem_Menu::SystemShutdown_Implementation(UObject* Context, const FString& Flag)
{
	L_SetState(false);
	Super::SystemShutdown_Implementation(Context, Flag);
}

void AOmegaDemoSystem_Menu::L_SetState(bool bPause)
{
	if (bFullGamePause)
	{
		UGameplayStatics::SetGamePaused(this,bPause);
	}
	else
	{
		TArray<FGameplayTag> tags;
		PauseActorTags.GetGameplayTagArray(tags);
		for (FGameplayTag t : tags)
		{
			UOmegaActorFunctions::SetPaused(this,t,bPause);
		}
	}
}
