// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Entity.h"

#include "Subsystems/Subsystem_Save.h"




UOmegaSaveBase* UOmegaFunctions_Entity:: _getEntitySaveObj(const UObject* context,bool bGlobal)
{
	if(context) 
	{
		return context->GetWorld()->GetGameInstance()->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(bGlobal);
	}
	return nullptr;
}


void UOmegaFunctions_Entity::SetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, FOmegaEntity Entity,
	bool bGlobal)
{
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		switch (ID.entity_type)
		{
			case 0:
				_sav->Entities.Entities_Asset.Add(Conv_EntityID_2_DataAsset(ID),Entity);
			;
			case 1:
				_sav->Entities.Entities_Named.Add(Conv_EntityID_2_Name(ID),Entity);
			;
			case 2:
				_sav->Entities.Entities_Guid.Add(Conv_EntityID_2_GUID(ID),Entity);
			;
		default: ;
		}
	}
}

FOmegaEntity UOmegaFunctions_Entity::GetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, bool bGlobal)
{ 
	if(UOmegaSaveBase* _sav = _getEntitySaveObj(WorldContextObject,bGlobal))
	{
		switch (ID.entity_type)
		{
		case 0:
			return  _sav->Entities.Entities_Asset.FindOrAdd(Conv_EntityID_2_DataAsset(ID));
			;
		case 1:
			return _sav->Entities.Entities_Named.FindOrAdd(Conv_EntityID_2_Name(ID));
			;
		case 2:
			return _sav->Entities.Entities_Guid.FindOrAdd(Conv_EntityID_2_GUID(ID));
			;
		default: ;
		}
	}
	return FOmegaEntity();
}

FOmegaEntityID UOmegaFunctions_Entity::Conv_DataAsset_2_EntityID(UPrimaryDataAsset* Key)
{
	FOmegaEntityID EntityID;
	EntityID.entity_type = 0;
	if (Key)
	{
		EntityID.entity_string=Key->GetPathName();	
	}
	return EntityID;
}

FOmegaEntityID UOmegaFunctions_Entity::Conv_Name_2_EntityID(FName Key)
{
	FOmegaEntityID EntityID;
	EntityID.entity_type = 1;
	EntityID.entity_string=Key.ToString();
	return EntityID;
}

FOmegaEntityID UOmegaFunctions_Entity::Conv_GUID_2_EntityID(FGuid Key)
{
	FOmegaEntityID EntityID;
	EntityID.entity_type = 2;
	EntityID.entity_string=Key.ToString();
	return EntityID;
}


UPrimaryDataAsset* UOmegaFunctions_Entity::Conv_EntityID_2_DataAsset(FOmegaEntityID Key)
{
	if (Key.entity_type == 0)
	{
		TSoftObjectPtr<UPrimaryDataAsset> SoftRef = TSoftObjectPtr<UPrimaryDataAsset>(FSoftObjectPath(Key.entity_string));
		if (UPrimaryDataAsset* asset_out=SoftRef.LoadSynchronous())
		{
			return asset_out;
		}
	}
	return nullptr;
}

FName UOmegaFunctions_Entity::Conv_EntityID_2_Name(FOmegaEntityID Key)
{
	return FName(Key.entity_string);
}

FGuid UOmegaFunctions_Entity::Conv_EntityID_2_GUID(FOmegaEntityID Key)
{
	return FGuid(Key.entity_string);
}

int32 UOmegaFunctions_Entity::GetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	bool bGlobalSave)
{
	return GetEntity_ByID(WorldContextObject,ID,bGlobalSave).params_int32.FindOrAdd(param);
}

void UOmegaFunctions_Entity::SetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	int32 Value, bool bAdded, bool bGlobalSave)
{
	FOmegaEntity E=GetEntity_ByID(WorldContextObject,ID,bGlobalSave);
	int32 base_int=0;
	if (bAdded)
	{
		base_int=E.params_int32.FindOrAdd(param);
	}
	E.params_int32.Add(param,Value+base_int);
	SetEntity_ByID(WorldContextObject,ID,E,bGlobalSave);
}

FString UOmegaFunctions_Entity::GetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	bool bGlobalSave)
{
	return GetEntity_ByID(WorldContextObject,ID,bGlobalSave).params_string.FindOrAdd(param);
}

void UOmegaFunctions_Entity::SetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	FString Value, bool bGlobalSave)
{
	FOmegaEntity E=GetEntity_ByID(WorldContextObject,ID,bGlobalSave);
	E.params_string.Add(param,Value);
	SetEntity_ByID(WorldContextObject,ID,E,bGlobalSave);
}

void UOmegaFunctions_Entity::SetSaveEntity_Tag(UObject* WorldContextObject, FOmegaEntityID ID, FName tag, bool bActive,
	bool bGlobalSave)
{
	FOmegaEntity E=GetEntity_ByID(WorldContextObject,ID,bGlobalSave);
	
	if (bActive && !E.Tags_Named.Contains(tag))
	{
		E.Tags_Named.Add(tag);
	}
	else
	{
		E.Tags_Named.Remove(tag);
	}
	
	SetEntity_ByID(WorldContextObject,ID,E,bGlobalSave);
}

void UOmegaFunctions_Entity::SetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID, TArray<FName> tags,
	bool bActive, bool bGlobalSave)
{
	for (FName n : tags)
	{
		SetSaveEntity_Tag(WorldContextObject,ID,n,bActive,bGlobalSave);
	}
}

TArray<FName> UOmegaFunctions_Entity::GetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID,
	bool bGlobalSave)
{
	FOmegaEntity E=GetEntity_ByID(WorldContextObject,ID,bGlobalSave);
	
	return E.Tags_Named;
}

bool UOmegaFunctions_Entity::SaveEntity_HasTag(UObject* WorldContextObject, FOmegaEntityID ID, FName tag,
	bool bGlobalSave)
{
	FOmegaEntity E=GetEntity_ByID(WorldContextObject,ID,bGlobalSave);
	
	return E.Tags_Named.Contains(tag);
}


