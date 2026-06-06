// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_Entity.h"

#include "OmegaSettings.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Subsystems/Subsystem_Save.h"
#include "Subsystems/Subsystem_World.h"

TArray<FName> UOmegaFunctions_Entity::opts_entity_int32()
{
	return GetMutableDefault<UOmegaSettings>()->EntityParams_int32;
}

TArray<FName> UOmegaFunctions_Entity::opts_entity_string()
{
	return GetMutableDefault<UOmegaSettings>()->EntityParams_string;
}


FOmegaEntity* UOmegaFunctions_Entity::getEntityRefById(const UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target)
{
	if (FOmegaEntitySet* _set = _getEntitySaveObj(WorldContextObject, Target))
	{
		switch (ID.entity_type)
		{
		case 0: return &_set->Entities_Asset.FindOrAdd(Conv_EntityID_2_DataAsset(ID));
		case 1: return &_set->Entities_Named.FindOrAdd(Conv_EntityID_2_Name(ID));
		case 2: return &_set->Entities_Guid.FindOrAdd(Conv_EntityID_2_GUID(ID));
		default: ;
		}
	}
	return nullptr;
}

FOmegaEntitySet* UOmegaFunctions_Entity::_getEntitySaveObj(const UObject* context, EOmegaGlobalParamTarget Target)
{
	if (!context) { return nullptr; }
	UWorld* World = context->GetWorld();
	if (!World) { return nullptr; }
	switch (Target)
	{
	case WORLD:
		if (UOmegaSubsystem_World* ws = World->GetSubsystem<UOmegaSubsystem_World>())
			return &ws->Entities;
		return nullptr;
	case GAME_INSTANCE:
		if (UGameInstance* GI = World->GetGameInstance())
			if (UOmegaSubsystem_GameInstance* gi = GI->GetSubsystem<UOmegaSubsystem_GameInstance>())
				return &gi->Entities;
		return nullptr;
	case SAVE_GAME:
		if (UGameInstance* GI = World->GetGameInstance())
			if (UOmegaSaveBase* sav = GI->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(false))
				return &sav->Entities;
		return nullptr;
	case SAVE_GLOBAL:
		if (UGameInstance* GI = World->GetGameInstance())
			if (UOmegaSaveBase* sav = GI->GetSubsystem<UOmegaSaveSubsystem>()->GetSaveObject(true))
				return &sav->Entities;
		return nullptr;
	}
	return nullptr;
}


void UOmegaFunctions_Entity::SetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, FOmegaEntity Entity,
	EOmegaGlobalParamTarget Target)
{
	if (FOmegaEntitySet* _set = _getEntitySaveObj(WorldContextObject, Target))
	{
		switch (ID.entity_type)
		{
		case 0: _set->Entities_Asset.Add(Conv_EntityID_2_DataAsset(ID), Entity); break;
		case 1: _set->Entities_Named.Add(Conv_EntityID_2_Name(ID), Entity);      break;
		case 2: _set->Entities_Guid.Add(Conv_EntityID_2_GUID(ID), Entity);       break;
		default: ;
		}
	}
}

FOmegaEntity UOmegaFunctions_Entity::GetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target)
{
	if(FOmegaEntity* _entity = getEntityRefById(WorldContextObject, ID, Target))
	{
		return *_entity;
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

FTransform UOmegaFunctions_Entity::GetTransform(UObject* WorldContextObject, FOmegaEntityID ID, EOmegaGlobalParamTarget Target)
{
	return GetEntity_ByID(WorldContextObject, ID, Target).Transform;
}

void UOmegaFunctions_Entity::SetTransform(UObject* WorldContextObject, FOmegaEntityID ID, FTransform Value,
	EOmegaGlobalParamTarget Target)
{
	FOmegaEntity E = GetEntity_ByID(WorldContextObject, ID, Target);
	E.Transform = Value;
	SetEntity_ByID(WorldContextObject, ID, E, Target);
}

int32 UOmegaFunctions_Entity::GetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	EOmegaGlobalParamTarget Target)
{
	return GetEntity_ByID(WorldContextObject, ID, Target).params_int32.FindOrAdd(param);
}

void UOmegaFunctions_Entity::SetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	int32 Value, bool bAdded, EOmegaGlobalParamTarget Target)
{
	FOmegaEntity E = GetEntity_ByID(WorldContextObject, ID, Target);
	int32 base_int = 0;
	if (bAdded)
	{
		base_int = E.params_int32.FindOrAdd(param);
	}
	E.params_int32.Add(param, Value + base_int);
	SetEntity_ByID(WorldContextObject, ID, E, Target);
}

void UOmegaFunctions_Entity::AddSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	int32 Value, EOmegaGlobalParamTarget Target)
{
	FOmegaEntity E = GetEntity_ByID(WorldContextObject, ID, Target);
	E.params_int32.Add(param, E.params_int32.FindOrAdd(param) + Value);
	SetEntity_ByID(WorldContextObject, ID, E, Target);
}

FString UOmegaFunctions_Entity::GetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	EOmegaGlobalParamTarget Target)
{
	return GetEntity_ByID(WorldContextObject, ID, Target).params_string.FindOrAdd(param);
}

void UOmegaFunctions_Entity::SetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, FName param,
	FString Value, EOmegaGlobalParamTarget Target)
{
	FOmegaEntity E = GetEntity_ByID(WorldContextObject, ID, Target);
	E.params_string.Add(param, Value);
	SetEntity_ByID(WorldContextObject, ID, E, Target);
}

void UOmegaFunctions_Entity::SetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID,
	FGameplayTagContainer tags, bool bActive, EOmegaGlobalParamTarget Target)
{
	FOmegaEntity E = GetEntity_ByID(WorldContextObject, ID, Target);
	if (bActive)
	{
		E.Tags.AppendTags(tags);
	}
	else
	{
		E.Tags.RemoveTags(tags);
	}
	SetEntity_ByID(WorldContextObject, ID, E, Target);
}

FGameplayTagContainer UOmegaFunctions_Entity::GetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID,
	EOmegaGlobalParamTarget Target)
{
	return GetEntity_ByID(WorldContextObject, ID, Target).Tags;
}

bool UOmegaFunctions_Entity::SaveEntity_HasTags(UObject* WorldContextObject, FOmegaEntityID ID,
	FGameplayTagContainer tag, EOmegaGlobalParamTarget Target)
{
	return GetEntity_ByID(WorldContextObject, ID, Target).Tags.HasAll(tag);
}

bool UOmegaFunctions_Entity::SaveEntity_CheckTag(UObject* WorldContextObject, FOmegaEntityID ID,
	FGameplayTagContainer tag, EOmegaGlobalParamTarget Target, bool& Result, bool AddIfFalse)
{
	if (SaveEntity_HasTags(WorldContextObject, ID, tag, Target))
	{
		Result = true;
		return true;
	}
	if (AddIfFalse)
	{
		SetSaveEntity_Tags(WorldContextObject, ID, tag, true, Target);
	}
	Result = false;
	return false;
}





