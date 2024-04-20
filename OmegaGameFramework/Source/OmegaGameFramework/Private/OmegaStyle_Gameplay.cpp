// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaStyle_Gameplay.h"
#include "OmegaSettings.h"

UOmegaGameplayStyle* UOmegaGameplayStyleFunctions::GetCurrentGameplayStyle()
{
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultGameplayStyle.TryLoad())
	{
		return Cast<UOmegaGameplayStyle>(style_ref);
	}
	return nullptr;
}
