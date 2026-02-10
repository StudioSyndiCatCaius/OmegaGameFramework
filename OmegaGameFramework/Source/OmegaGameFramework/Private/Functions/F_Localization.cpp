// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Localization.h"

#include "OmegaSettings_Localization.h"
#include "Functions/F_Common.h"
#include "Functions/F_File.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Statics/OMEGA_File.h"


TArray<FString> UOmegaLocalizationFunctions::GetVoiceLineDirectories(FString subpath, FString file)
{
	TArray<FString> out;
	
	//Add file name to search through preset paths
	out.Add(file);
	
	out.Add(OMEGA_File::PathCorrect(OGF_CFG_LOC()->Internal_Voice_Path+subpath+file+"."+file));
	
	//add external file paths to check
	for (FString dir : UOmegaFileFunctions::GetExternalContentDirectories())
	{
		FString new_path=dir+"/"+subpath;
		
		out.Add(OMEGA_File::PathCorrect(new_path+file));
	}
		
	return out;
}

USoundBase* UOmegaLocalizationFunctions::GetVoiceSoundByPath(FString subpath, FString file)
{
	UE_LOG(LogTemp,Log,TEXT("- BEGIN TRY Loaded Voice sound: %s"),*file);
	for (FString dir : GetVoiceLineDirectories(subpath,file))
	{
		UE_LOG(LogTemp,Log,TEXT("		- TRY Loaded Voice sound from: %s"),*dir);
		for (TSoftClassPtr<USoundBase> soundClass : GetMutableDefault<UOmegaSettings_Localization>()->VoiceSoundClasses)
		{
			bool found=false;
			if (USoundBase* s=Cast<USoundBase>(UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(dir,soundClass.LoadSynchronous(),found)))
			{
				UE_LOG(LogTemp,Log,TEXT("			✅ SUCCESS"));
				return s;
			}
		}
	}
	UE_LOG(LogTemp,Log,TEXT("		❌ FAILED Loaded Voice sound from: %s"),*file);
	return nullptr;
}

void UOmegaLocalizationFunctions::PlayVoiceClip(AActor* Instigator, FString VoiceClip)
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

USoundBase* UOmegaLocalizationFunctions::VoiceLine_Get(FName Line)
{
	return GetVoiceSoundByPath(OGF_CFG_LOC()->Subpath_Line,Line.ToString()); 
}

USoundBase* UOmegaLocalizationFunctions::GetVoiceClip_ByID(FName ID, FString VoiceClip)
{
	FString path=OGF_CFG_LOC()->VoiceClip_Prefex;
	path=path.Replace(TEXT("{id}"),*ID.ToString());
	path=path+VoiceClip;
	return GetVoiceSoundByPath(OGF_CFG_LOC()->Subpath_Clip+ID.ToString()+"/",path);
}

