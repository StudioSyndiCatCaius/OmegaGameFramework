// Fill out your copyright notice in the Description page of Project Settings.

#include "Functions/F_PropertyAccess.h"

#include "LuaSettings.h"
#include "LuaValue.h"
#include "Functions/F_Lua.h"
#include "Misc/OmegaUtils_Macros.h"

FLuaValue L_TryGetLuaValue(UObject* Object, const FString& Property)
{
	if (OGF_CFG_LUA()->bPropertyAccessFromObjectLuaValue)
	{
		FLuaValue val=UOmegaLuaFunctions::GetObjectLua_Value(Object, Property);
		return val.GetField(Property);
	}
	return  FLuaValue();
}


FString UOmegaFunctions_PropertyAccess::Get_String(UObject* Object, const FString& Property, const FString& Fallback)
{
	if (!Object) return Fallback;
	FLuaValue lua=L_TryGetLuaValue(Object, Property); 
	if (!lua.IsNil()) { return lua.ToString(); }
	if (FProperty* Prop = FindFProperty<FStrProperty>(Object->GetClass(), *Property))
	{
		return *Prop->ContainerPtrToValuePtr<FString>(Object);
	}
	return Fallback;
}

bool UOmegaFunctions_PropertyAccess::Get_bool(UObject* Object, const FString& Property, bool Fallback)
{
	if (!Object) return Fallback;
	FLuaValue lua=L_TryGetLuaValue(Object, Property); 
	if (!lua.IsNil()) { return lua.ToBool(); }
	if (FBoolProperty* Prop = FindFProperty<FBoolProperty>(Object->GetClass(), *Property))
	{
		return Prop->GetPropertyValue_InContainer(Object);
	}
	return Fallback;
}

double UOmegaFunctions_PropertyAccess::Get_Double(UObject* Object, const FString& Property, double Fallback)
{
	if (!Object) return Fallback;
	FLuaValue lua=L_TryGetLuaValue(Object, Property); 
	if (!lua.IsNil()) { return lua.ToFloat(); }
	if (FProperty* Prop = FindFProperty<FDoubleProperty>(Object->GetClass(), *Property))
	{
		return *Prop->ContainerPtrToValuePtr<double>(Object);
	}
	return Fallback;
}

int64 UOmegaFunctions_PropertyAccess::Get_Int64(UObject* Object, const FString& Property, int64 Fallback)
{
	if (!Object) return Fallback;
	FLuaValue lua=L_TryGetLuaValue(Object, Property); 
	if (!lua.IsNil()) { return lua.ToInteger(); }
	if (FProperty* Prop = FindFProperty<FInt64Property>(Object->GetClass(), *Property))
	{
		return *Prop->ContainerPtrToValuePtr<int64>(Object);
	}
	return Fallback;
}

UObject* UOmegaFunctions_PropertyAccess::Get_Object(UObject* Object, const FString& Property, TSubclassOf<UObject> Class, UObject* Fallback)
{
	if (!Object) return Fallback;
	//FLuaValue lua=L_TryGetLuaValue(Object, Property); 
	//if (!lua.IsNil()) { return lua.ToString(); }
	if (FObjectProperty* Prop = FindFProperty<FObjectProperty>(Object->GetClass(), *Property))
	{
		UObject* Result = Prop->GetObjectPropertyValue_InContainer(Object);
		if (Result && (!Class || Result->IsA(Class)))
		{
			return Result;
		}
	}
	return Fallback;
}