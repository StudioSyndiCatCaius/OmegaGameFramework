// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaVirtualInputPlayerSubsystem.h"

#include "OmegaAnalogCursor.h"

void UOmegaVirtualInputPlayerSubsystem::SetVirtualCursorEnabled(bool bEnabled)
{
	APlayerController* Local_PlayerRef = nullptr;
	if(GetLocalPlayer()->GetPlayerController(GetWorld()))
	{
		Local_PlayerRef = GetLocalPlayer()->GetPlayerController(GetWorld());
	}
	if(bEnabled)
	{
		FOmegaAnalogCursor::EnableAnalogCursor(Local_PlayerRef);
	}
	else
	{
		FOmegaAnalogCursor::DisableAnalogCursor(Local_PlayerRef);
	}
}
