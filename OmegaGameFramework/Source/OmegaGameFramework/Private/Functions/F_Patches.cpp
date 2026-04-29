// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_Patches.h"

void UOmegaGamePatch::OnGame_Start_Implementation(UGameInstance* GameInstance)
{
}

void UOmegaGamePatch::OnGame_End_Implementation(UGameInstance* GameInstance)
{
}

void UOmegaGamePatch::OnLevel_Start_Implementation(UGameInstance* GameInstance)
{
}

void UOmegaGamePatch::OnLevel_End_Implementation(UGameInstance* GameInstance)
{
}

void UOmegaGamePatch::OnFirstApplied_Implementation(UGameInstance* GameInstance, UOmegaSaveGame* Save)
{
}

void UOmegaGamePatch::OnSave_Created_Implementation(UGameInstance* GameInstance, UOmegaSaveGame* Save)
{
}

void UOmegaGamePatch::OnSave_Started_Implementation(UGameInstance* GameInstance, UOmegaSaveGame* Save)
{
}

UOmegaGamePatch::UOmegaGamePatch()
{
	if (!GUID.IsValid())
	{
		GUID=FGuid::NewGuid();
	}
}
