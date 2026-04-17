// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Object.h"

#include "LuaBlueprintFunctionLibrary.h"


FLuaValue* FOmegaObjectMeta::ValidateMeta(UObject* WorldContext, UObject* TargetObject)
{
	if (TargetObject)
	{
		if (ObjectMap.Contains(TargetObject))
		{
			return &ObjectMap[TargetObject];
		}
		if (WorldContext)
		{
			FLuaValue new_tbl=ULuaBlueprintFunctionLibrary::LuaCreateTable(WorldContext,nullptr);
			ObjectMap.Add(TargetObject,new_tbl);
			return &ObjectMap[TargetObject];
		}
	}
	return nullptr;
}

FLuaValue FOmegaObjectMeta::GetParam(UObject* WC, UObject* obj, FName param)
{
	if (FLuaValue* l=ValidateMeta(WC,obj))
	{
		FLuaValue out=l->GetField(param.ToString());
		return out;
	}
	return FLuaValue();
}

void UOmegaObjectFunctions::Rename_Object(UObject* object, FString NewName)
{
	if(object)
	{
		object->Rename(*NewName);
	}
}

UObject* UOmegaObjectFunctions::Duplicate_Object(UObject* object,UObject* NewOuter, UClass* Class)
{
	if(object && Class && NewOuter)
	{
		UObject* new_obj=DuplicateObject(object,NewOuter);
		if(new_obj && new_obj->GetClass()==Class)
		{
			return new_obj;
		}
	}
	return nullptr;
}


UObject* UOmegaObjectFunctions::RunSelector_Object(UObject* WorldContextObject, FOmegaSelect_Object Selector)
{
	if(WorldContextObject && Selector.Selector)
	{
		return Selector.Selector->GetSelected_Obj(WorldContextObject);
	}
	return nullptr;
}

UPrimaryDataAsset* UOmegaObjectFunctions::RunSelector_DataAsset(UObject* WorldContextObject,
	FOmegaSelect_DataAsset Selector)
{
	if(WorldContextObject && Selector.Selector)
	{
		return Selector.Selector->Get_DataAsset(WorldContextObject);
	}
	return nullptr;
}

bool UOmegaObjectFunctions::CheckCondition_DataAsset(UPrimaryDataAsset* Asset, FOmegaConditions_DataAsset Selector,TArray<FText>& Reasons)
{
	if(Asset)
	{
		return Selector.CheckConditions(Asset,Reasons);
	}
	return false;
}

FLuaValue UOmegaObjectFunctions::Meta_GetTable(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		return *l;
	}
	return FLuaValue();
}

void UOmegaObjectFunctions::Meta_SetBool(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param,
                                         bool NewValue)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		l->SetField(param.ToString(), NewValue);
	}
}

void UOmegaObjectFunctions::Meta_SetInt(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param,
	int32 NewValue)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		l->SetField(param.ToString(), NewValue);
	}
}

void UOmegaObjectFunctions::Meta_SetFloat(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param,
	float NewValue)
{
	if (FLuaValue* l=Meta.ValidateMeta(WorldContextObject,Object))
	{
		l->SetField(param.ToString(), NewValue);
	}
}

bool UOmegaObjectFunctions::Meta_GetBool(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param, bool Fallback)
{
	FLuaValue l=Meta.GetParam(WorldContextObject,Object,param);
	if (!l.IsNil())
	{
		return l.ToBool();
	}
	return Fallback;
}

int32 UOmegaObjectFunctions::Meta_GetInt(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param, int32 Fallback)
{
	FLuaValue l=Meta.GetParam(WorldContextObject,Object,param);
	if (!l.IsNil())
	{
		return l.ToInteger();
	}
	return Fallback;
}

float UOmegaObjectFunctions::Meta_GetFloat(UObject* WorldContextObject, FOmegaObjectMeta& Meta, UObject* Object, FName param, float Fallback)
{
	FLuaValue l=Meta.GetParam(WorldContextObject,Object,param);
	if (!l.IsNil())
	{
		return l.ToFloat();
	}
	return Fallback;
}
