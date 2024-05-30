// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Paths.h"

#include "OmegaSettings.h"

UOmegaSettings_Paths* UOmegaSettings_PathFunctions::GetOmegaPathSettings()
{
	if(UOmegaSettings_Paths* out = Cast<UOmegaSettings_Paths>(GetMutableDefault<UOmegaSettings>()->DefaultSettings_Paths.TryLoad()))
	{
		return out;
	}
	return nullptr;
}
