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




void UOmegaSaveFunctions::SetEntity_ByAsset(const UObject* WorldContextObject, UPrimaryDataAsset* Key,
	FOmegaEntity Entity, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Entities.Entities_Asset.Add(Key,Entity);
	}
}

FOmegaEntity UOmegaSaveFunctions::GetEntity_ByAsset(const UObject* WorldContextObject, UPrimaryDataAsset* Key,
	bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		return _sav->Entities.Entities_Asset.FindOrAdd(Key);
	}
	return FOmegaEntity();
}

void UOmegaSaveFunctions::SetEntity_ByGuid(const UObject* WorldContextObject, FGuid Key, FOmegaEntity Entity,
	bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Entities.Entities_Guid.Add(Key,Entity);
	}
}

FOmegaEntity UOmegaSaveFunctions::GetEntity_ByGuid(const UObject* WorldContextObject, FGuid Key, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		return _sav->Entities.Entities_Guid.FindOrAdd(Key);
	}
	return FOmegaEntity();
}





bool UOmegaSaveFunctions::Custom_SaveGame(USaveGame* SaveGameObject, const FString& path, const FString& file)
{
	return OGF_Save::SaveGame(SaveGameObject,path,file);
}

USaveGame* UOmegaSaveFunctions::Custom_LoadGame(const FString& path, const FString& file)
{
	return OGF_Save::LoadGame(path,file);

}

bool UOmegaSaveFunctions::GetSaveParam_Bool(const UObject* WorldContextObject, FName Param, bool bGlobal, bool Fallback)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		if (_sav->Prop_bool.Contains(Param))
		{
			return _sav->Prop_bool.FindOrAdd(Param);
		}
	}
	return Fallback;
}

int32 UOmegaSaveFunctions::GetSaveParam_Int(const UObject* WorldContextObject, FName Param, bool bGlobal, int32 Fallback)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		if (_sav->Prop_int.Contains(Param))
		{
			return _sav->Prop_int.FindOrAdd(Param);
		}
	}
	return Fallback;
}

float UOmegaSaveFunctions::GetSaveParam_Float(const UObject* WorldContextObject, FName Param, bool bGlobal, float Fallback)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		if (_sav->Prop_float.Contains(Param))
		{
			return _sav->Prop_float.FindOrAdd(Param);
		}
	}
	return Fallback;
}

FString UOmegaSaveFunctions::GetSaveParam_String(const UObject* WorldContextObject, FName Param, bool bGlobal,
	const FString& Fallback)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		if (_sav->Prop_string.Contains(Param))
		{
			return _sav->Prop_string.FindOrAdd(Param);
		}
	}
	return Fallback;
}

FVector UOmegaSaveFunctions::GetSaveParam_Vector(const UObject* WorldContextObject, FName Param, bool bGlobal, FVector Fallback)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		if (_sav->Prop_Vector.Contains(Param))
		{
			return _sav->Prop_Vector.FindOrAdd(Param);
		}
	}
	return Fallback;
}

UPrimaryDataAsset* UOmegaSaveFunctions::GetSaveParam_DataAsset(const UObject* WorldContextObject, FName Param,
                                                               bool bGlobal, UPrimaryDataAsset* Fallback)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		if (_sav->Prop_Asset.Contains(Param))
		{
			return _sav->Prop_Asset.FindOrAdd(Param);
		}
	}
	return Fallback;
}

void UOmegaSaveFunctions::SetSaveParam_Bool(const UObject* WorldContextObject, bool Value, FName Param, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Prop_bool.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_Int(const UObject* WorldContextObject, int32 Value, FName Param, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Prop_int.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_Float(const UObject* WorldContextObject, float Value, FName Param, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Prop_float.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_String(const UObject* WorldContextObject, const FString& Value, FName Param,
	bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Prop_string.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_Vector(const UObject* WorldContextObject, FVector Value, FName Param,
                                              bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Prop_Vector.Add(Param,Value);
	}
}

void UOmegaSaveFunctions::SetSaveParam_DataAsset(const UObject* WorldContextObject, UPrimaryDataAsset* Value,
	FName Param, bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		_sav->Prop_Asset.Add(Param,Value);
	}
}

