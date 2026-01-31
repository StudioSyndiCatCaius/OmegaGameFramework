// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Localization.h"

#include "OmegaSettings.h"
#include "Functions/F_Localization.h"
#include "Internationalization/Culture.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Methods.h"



UOmegaSettings_Localization::UOmegaSettings_Localization(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}


TArray<UOmegaLocalizedVoice_Preset*> UOmegaSettings_Localization::L_GetVoicePresets() const
{
	TArray<UOmegaLocalizedVoice_Preset*> out;

	return out;
}

TArray<UOmegaLocalizedVoice_Script*> UOmegaSettings_Localization::L_GetVoiceScripts() const
{
	TArray<UOmegaLocalizedVoice_Script*> out;
	for(auto* a : L_GetVoicePresets())
	{
		if(a)
		{
			out.Append(a->Scripts);
		}
	}
	return out;
}


USoundBase* UOmegaSubsystem_Localization::GetVoiceClipByKey(FName key)
{
	
	return nullptr;
}
