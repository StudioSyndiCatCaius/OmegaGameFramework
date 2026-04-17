// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Localization.h"

#include "OmegaGameManager.h"
#include "OmegaSettings.h"
#include "OmegaSettings_Localization.h"
#include "Algo/RandomShuffle.h"
#include "DataAssets/DA_Appearance.h"
#include "DataAssets/DA_AssetLib.h"
#include "Functions/F_Common.h"
#include "Functions/F_Config.h"
#include "Functions/F_File.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetInternationalizationLibrary.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Statics/OMEGA_File.h"

const FString ini_section="localization";
const FString ini_key_voicelang="lang_voice";



void UOmegaLocalizationFunctions::PlayVoiceClip(AActor* Instigator, FString VoiceClip, int32 RandomRange, bool bTryUseInstigatorSoundLibrary)
{
	FString clip_id=UDataInterface_General::GetObjectLabel(Instigator);
	bool found=false;
	if (bTryUseInstigatorSoundLibrary)
	{
		//try get voice id from sound library
		UOmegaAssetLibrary_Animation* anim = nullptr;
		UOmegaAssetLibrary_Sound* sound = nullptr;
		UOmegaAssetLibrary_SlateBrush* slate = nullptr;
		UOmegaAppearanceFunctions::GetAppearanceLibraries(Instigator,anim,sound,slate);
		if (sound)
		{
			FString lib_id=sound->VoiceID;
			if (!lib_id.IsEmpty())
			{
				clip_id=lib_id;
				found=true;
			}
		}
	}
	if (!found && UDataInterface_VoiceSource::Uses(Instigator))
	{
		FString _id=IDataInterface_VoiceSource::Execute_VoiceSource_GetID(Instigator);
		if (!_id.IsEmpty())
		{
			clip_id=_id;
		}
	}
	if(USoundBase* sound=GetVoice_Cue(Instigator,FName(clip_id),VoiceClip,RandomRange))
	{
		UGameplayStatics::PlaySoundAtLocation(Instigator,sound,Instigator->GetActorLocation(),Instigator->GetActorRotation());
	}
	else
	{
		//OGF_Log::Warning("Failed to load voice clip. No valid file found");
	}
}


bool UDataInterface_VoiceSource::Uses(UObject* object)
{
	if (object && object->GetClass()->ImplementsInterface(StaticClass()))
	{
		return true;
	}
	return false;
}

TArray<FString> UOmegaLocalizationFunctions::GetAllVoiceLineDirectories()
{
	TArray<FString> out;

	//add external file paths to check
	for (FString dir : UOmegaFileFunctions::GameData_GetDirectories(OGF_CFG_LOC()->VoiceClip_ExternalDirectory))
	{
		out.Add(OMEGA_File::PathCorrect(dir));
	}
		
	return out;
}

FString UOmegaLocalizationFunctions::GetLang_Voice()
{
	FString _got=UOmegaFunctions_Config::GetString(ini_section,ini_key_voicelang);
	if (_got.IsEmpty())
	{
		_got=UKismetInternationalizationLibrary::GetCurrentCulture();
		SetLang_Voice(_got);
	}
	return _got;
}

void UOmegaLocalizationFunctions::SetLang_Voice(const FString& language)
{
	UOmegaFunctions_Config::SetString(ini_section,ini_key_voicelang,language);
}

USoundBase* UOmegaLocalizationFunctions::GetVoiceSoundByPath(UObject* WorldContext, FString subpath, FString file, bool Internal, bool External)
{
	FString current_loc=GetLang_Voice();
	for (FString _baseDir : GetAllVoiceLineDirectories())
	{
		FString _checkFile=_baseDir+"/"+current_loc+"/"+subpath+"/"+file+"."+OGF_CFG_LOC()->VoiceClip_Extension;
		_checkFile=OMEGA_File::PathCorrect(_checkFile);
		
		// LOAD = from Game Manager override
		if (USoundBase* b=OGF_GAME_CORE()->Localization_GetClipFromPath(WorldContext,_checkFile,file))
		{
			return b;
		}
		UE_LOG(LogTemp,Log,TEXT("LOCALIZATION:	Trying load voice clip : %s"),*_checkFile);
		
		// LOAD = from external file
		if (External)
		{
			if (FPaths::FileExists(_checkFile))
			{
				FString _outError;
				if (USoundBase* _soundImport = UOmegaFileFunctions::OmegaImport_Sound(_checkFile,_outError))
				{
					return _soundImport;
				}
			}	
		}
	}

	if (Internal)
	{
		//LOAD direct
		TArray<FString> base_dirList=OGF_CFG_LOC()->InternalVoice_LocalePaths;
		
		for (FString _dir : base_dirList)
		{
			bool _result;
			
			FString search_dir=_dir+"/"+current_loc+"/"+subpath+"/";
			search_dir=OMEGA_File::PathCorrect(search_dir);
			UE_LOG(LogTemp,Log,TEXT("LOCALIZATION:	Trying load INTERNAL voice clip : %s"),*search_dir);
			FOmegaAssetSearchConfig search_config;
			search_config.bLogProcess=true;
			if (USoundBase* b=Cast<USoundBase>(UOmegaGameFrameworkBPLibrary::GetAsset_FromPath(file,USoundBase::StaticClass(),_result,search_dir,search_config)))
			{
				return b;
			}
		}
	}
	
	return nullptr;
}

USoundBase* UOmegaLocalizationFunctions::GetVoice_Line(UObject* WorldContext,FName Line)
{
	return GetVoiceSoundByPath(WorldContext, OGF_CFG_LOC()->Subpath_Line,Line.ToString()); 
}

USoundBase* UOmegaLocalizationFunctions::GetVoice_Cue(UObject* WorldContext,FName ID,const FString& VoiceClip, int32 RandomRange)
{
	FString _pref=OGF_CFG_LOC()->VoiceClip_Prefex;
	FString _strang=ID.ToString();
	FString path=_pref+_strang+"_"+VoiceClip;
	FString folder_path=OGF_CFG_LOC()->Subpath_Clip+"/"+ID.ToString()+"/";
	
	if (RandomRange>0)
	{
		TArray<int32> MyArray;
		MyArray.Reserve(RandomRange);

		for (int32 i = 0; i < RandomRange; i++)
		{
			MyArray.Add(i);  // Creates [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
		}

		// Shuffle it
		Algo::RandomShuffle(MyArray);
		
		for (int32 _i : MyArray)
		{
			if (USoundBase* _sound=GetVoiceSoundByPath(WorldContext,folder_path,path+"_"+FString::FromInt(_i),false))
			{
				return _sound;
			}
		}
	}
	return GetVoiceSoundByPath(WorldContext,folder_path,path);
}

