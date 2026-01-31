// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Save.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Subsystems/Subsystem_Save.h"

UOmegaSaveBase* _getEntitySaveObj(const UObject* context,bool bGlobal)
{
	if(context) 
	{
		return context->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(bGlobal);
	}
	return nullptr;
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

FJsonObjectWrapper UOmegaSaveFunctions::DataAsset_GetJson(const UObject* WorldContextObject, UPrimaryDataAsset* Asset,
	bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		return _sav->Entities.Entities_Asset.FindOrAdd(Asset).JsonData;
	}
	return FJsonObjectWrapper();
}

void UOmegaSaveFunctions::DataAsset_SetJson(const UObject* WorldContextObject, UPrimaryDataAsset* Asset,
	FJsonObjectWrapper Json, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Entities.Entities_Asset.FindOrAdd(Asset).JsonData=Json;
	}
}



FJsonObjectWrapper UOmegaSaveFunctions::GUID_GetJson(const UObject* WorldContextObject, FGuid Guid, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		return _sav->Entities.Entities_Guid.FindOrAdd(Guid).JsonData;
	}
	return FJsonObjectWrapper();
}

void UOmegaSaveFunctions::GUID_SetJson(const UObject* WorldContextObject, FGuid Guid, FJsonObjectWrapper Json,
	bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
 	{
 		_sav->Entities.Entities_Guid.FindOrAdd(Guid).JsonData=Json;
 	}
}





bool UOmegaSaveFunctions::Custom_SaveGame(USaveGame* SaveGameObject, const FString& path, const FString& file)
{
	return OGF_Save::SaveGame(SaveGameObject,path,file);
}

USaveGame* UOmegaSaveFunctions::Custom_LoadGame(const FString& path, const FString& file)
{
	return OGF_Save::LoadGame(path,file);

}
