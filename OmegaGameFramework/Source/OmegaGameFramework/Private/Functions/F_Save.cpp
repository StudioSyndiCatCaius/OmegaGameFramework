// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Save.h"

#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Methods.h"
#include "Statics/OMEGA_File.h"
#include "Subsystems/Subsystem_Save.h"
#include "HAL/PlatformProcess.h"
#include "Misc/App.h"

UOmegaSaveBase* _getEntitySaveObj(const UObject* context,bool bGlobal)
{
	if(context) 
	{
		return context->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(bGlobal);
	}
	return nullptr;
}


FString UOmegaSaveFunctions::GetSaveDirectoryPath(TEnumAsByte<EOmegaSaveDirectory> Directory)
{
	TEnumAsByte<EOmegaSaveDirectory> dir=Directory;	
	
#if WITH_EDITOR
	if (GetMutableDefault<UOmegaSettings>()->EditorUseProjectSaveForUserSave)
	{
		dir=EOmegaSaveDirectory::OmegaSaveDir_GameData;
	}
#endif
	
	switch(dir)
	{
	case OmegaSaveDir_UserData:
		
		return FString(FPlatformProcess::UserSettingsDir()) / FApp::GetProjectName() / TEXT("Saved/SaveGames/");
		
	case OmegaSaveDir_GameData:
	default:
		return FPaths::ProjectSavedDir() / TEXT("SaveGames/");
	}
}

FString UOmegaSaveFunctions::MakeSaveFilePath_Name(TEnumAsByte<EOmegaSaveDirectory> Directory, const FString& Name)
{
	return GetSaveDirectoryPath(Directory)+OGF_CFG()->SaveGamePrefex+Name+".sav";
}

FString UOmegaSaveFunctions::MakeSaveFilePath_Slot(TEnumAsByte<EOmegaSaveDirectory> Directory, int32 Slot)
{
	return MakeSaveFilePath_Name(Directory,FString::FromInt(Slot));
}

UOmegaSaveGame* UOmegaSaveFunctions::GetSave_Game(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGame> Class)
{
	if(UOmegaSaveGame* _sav =Cast<UOmegaSaveGame>(_getEntitySaveObj(WorldContextObject,false)))
	{
		if(!Class || _sav->GetClass()->IsChildOf(Class))
		{
			return _sav;
		}
	}
	return nullptr;
}

UOmegaSaveGlobal* UOmegaSaveFunctions::GetSave_Global(const UObject* WorldContextObject,
	TSubclassOf<UOmegaSaveGlobal> Class)
{
	if(UOmegaSaveGlobal* _sav =Cast<UOmegaSaveGlobal>(_getEntitySaveObj(WorldContextObject,true)))
	{
		if(!Class || _sav->GetClass()->IsChildOf(Class))
		{
			return _sav;
		}
	}
	return nullptr;
}

void UOmegaSaveFunctions::SetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 Value, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->TagVars_int.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool Value, bool bGlobal)
{
	if (Value)
	{
		SetSaveParam_Tag_Int(WorldContextObject,Param,1,bGlobal);
	}
	else
	{
		SetSaveParam_Tag_Int(WorldContextObject,Param,0,bGlobal);
	}
}

int32 UOmegaSaveFunctions::GetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		return _sav->TagVars_int.FindOrAdd(Param);
	}
	return 0;
}

bool UOmegaSaveFunctions::GetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal)
{
	return static_cast<bool>(GetSaveParam_Tag_Int(WorldContextObject,Param,bGlobal));
}

bool UOmegaSaveFunctions::CheckSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal,
                                                  bool& Outcome)
{
	bool _out=GetSaveParam_Tag_Bool(WorldContextObject,Param,bGlobal);
	if(_out){ Outcome=true; } else { Outcome=false; }
	return _out;
}

int32 UOmegaSaveFunctions::CheckSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param,
	int32 CheckValue, bool bGlobal, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome)
{
	int32 _out=GetSaveParam_Tag_Int(WorldContextObject,Param,bGlobal);

	if(_out<CheckValue) { Outcome=IsLess; }
	else if(_out==CheckValue) { Outcome=IsEqual; }
	else if(_out>CheckValue) { Outcome=IsGreater; }
	
	return _out;
}


UOmegaSaveGame* UOmegaSaveFunctions::CreateGame(const UObject* WorldContextObject)
{
	if (UOmegaSaveSubsystem* ss=OGF_Subsystems::oSave(WorldContextObject))
	{
		return ss->CreateNewGame();
	}
	return nullptr;
}

bool UOmegaSaveFunctions::StartGame(const UObject* WorldContextObject, UOmegaSaveGame* Game, bool bLoadSaveLevel)
{
	if (!Game) { return false;}
	if (UOmegaSaveSubsystem* ss=OGF_Subsystems::oSave(WorldContextObject))
	{
		ss->StartGame(Game,bLoadSaveLevel,FGameplayTagContainer());
		return true;
	}
	return false;
}


bool UOmegaSaveFunctions::Custom_SaveGame(USaveGame* SaveGameObject, const FString& path, const FString& file)
{
	return OGF_Save::SaveGame(SaveGameObject,path,file);
}

USaveGame* UOmegaSaveFunctions::Custom_LoadGame(const FString& path, const FString& file)
{
	return OGF_Save::LoadGame(path,file);

}

TArray<USaveGame*> UOmegaSaveFunctions::Custom_LoadGame_AllInPath(const FString& path)
{
	TArray<USaveGame*> out;
	for (FString _file : OMEGA_File::ListFilesInDirectory(path,false))
	{
		if (FPaths::GetExtension(_file)=="sav")
		{
			if (USaveGame* s=OGF_Save::LoadGame(path,FPaths::GetBaseFilename(_file)))
			{
				out.Add(s);
			}
		}
	}
	return out;
}
