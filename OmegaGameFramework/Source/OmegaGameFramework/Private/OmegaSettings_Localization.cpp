// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Localization.h"

#include "OmegaSettings.h"
#include "Kismet/KismetStringLibrary.h"

UOmegaSettings_Localization* UOmegaLocalizationFunctions::GetCurrentSettings_Localization()
{
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultSettings_Localization.TryLoad())
	{
		return Cast<UOmegaSettings_Localization>(style_ref);
	}
	return nullptr;
}
