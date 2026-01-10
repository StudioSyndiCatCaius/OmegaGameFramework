// Fill out your copyright notice in the Description page of Project Settings.


#include "OmegaSettings_Localization.h"

#include "OmegaSettings.h"
#include "Internationalization/Culture.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OmegaUtils_Methods.h"

TArray<UOmegaLocalizedVoice_Preset*> UOmegaSettings_Localization::L_GetVoicePresets() const
{
	TArray<UOmegaLocalizedVoice_Preset*> out=VoiceScript_Preset;
	if(VoiceScript_custom)
	{
		out.Add(VoiceScript_custom);
	}
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

void UOmegaLocalizationFunctions::PlayVoiceClip(AActor* Instigator, FString VoiceClip)
{
	if(Instigator && GetCurrentSettings_Localization())
	{
		if(USoundBase* sound=GetVoiceClip_ByID(FName(UDataInterface_General::GetObjectLabel(Instigator)),VoiceClip))
		{
			UGameplayStatics::PlaySoundAtLocation(Instigator,sound,Instigator->GetActorLocation(),Instigator->GetActorRotation());
		}
		else
		{
			//OGF_Log::Warning("Failed to load voice clip. No valid file found");
		}
	}
}

USoundBase* UOmegaLocalizationFunctions::GetVoiceClip_ByID(FName ID, FString VoiceClip)
{
	if(GetCurrentSettings_Localization())
	{
		
		FString LanguageCode=FInternationalization::Get().GetCurrentLanguage()->GetName();
		FString assetName=GetCurrentSettings_Localization()->VoiceClip_Prefex+VoiceClip;
		FString clip_path=GetCurrentSettings_Localization()->Default_VoiceCue_Path+LanguageCode+"/"+ID.ToString()+"/"+assetName+"."+assetName;
		clip_path=UKismetStringLibrary::Replace(clip_path,"{id}",ID.ToString());
		
		//OGF_Log::Info("Attempting to load voice clip at : "+clip_path);
	
		UE_LOG(LogTemp, Log, TEXT("Attempting to load voice clip at : %s"), *clip_path);
		TSoftObjectPtr<USoundBase> MySoundCue = TSoftObjectPtr<USoundBase>(FSoftObjectPath(*clip_path));
		if(USoundBase* LoadedSound = MySoundCue.LoadSynchronous())
		{
			return LoadedSound;
		}
		UE_LOG(LogTemp, Warning, TEXT("Failed to load voice clip. No valid file found"));
		//OGF_Log::Warning("Failed to load voice clip. No valid file found");
	}
	else
	{
		OGF_Log::Error("Trying to load a voice clip requires a valid Localization Settings asset");
	}
	return nullptr;
}

UOmegaSettings_Localization* UOmegaLocalizationFunctions::GetCurrentSettings_Localization()
{
	if(UObject* style_ref = GetMutableDefault<UOmegaSettings>()->DefaultSettings_Localization.TryLoad())
	{
		return Cast<UOmegaSettings_Localization>(style_ref);
	}
	return nullptr;
}

USoundBase* UOmegaSubsystem_Localization::GetVoiceClipByKey(FName key)
{
	if(UOmegaSettings_Localization* set=UOmegaLocalizationFunctions::GetCurrentSettings_Localization())
	{
		for(auto* a : set->L_GetVoiceScripts())
		{
			if(a)
			{
				if(USoundBase* s=a->GetVoiceClipByKey(this,key))
				{
					return s;
				}
			}
		}
	}
	return nullptr;
}
