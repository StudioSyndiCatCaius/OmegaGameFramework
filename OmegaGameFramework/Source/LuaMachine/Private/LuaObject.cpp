// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaObject.h"

#include "LuaBlueprintFunctionLibrary.h"

void ULuaObject::SetKey_Implementation(FLuaValue Key)
{
	lua_key=Key;
}

void ULuaObject::SetValue_Implementation(FLuaValue Value, const FString& Field)
{
	lua_value=Value;
}

FLuaValue ULuaObject::GetKey_Implementation()
{
	return lua_key;
}

FLuaValue ULuaObject::GetValue_Implementation(const FString& Field)
{
	return lua_value;
}

ULuaObject* ULuaObjectFunctions::CreateLuaObject(UObject* WorldContextObject, FLuaValue key, FLuaValue value)
{
	TSubclassOf<ULuaObject> target_class = ULuaObject::StaticClass();
	if (const TSubclassOf<ULuaObject> temp_class = GetMutableDefault<ULuaSettings>()->DefaultObject.LoadSynchronous())
	{
		target_class=temp_class;
	}
	ULuaObject* new_object = NewObject<ULuaObject>(WorldContextObject,target_class);
	new_object->lua_key=key;
	new_object->lua_value=value;
	return new_object;
}

TArray<ULuaObject*> ULuaObjectFunctions::CreateLuaObjectsFromTable(UObject* WorldContextObject, FLuaValue table)
{
	TArray<ULuaObject*> out;
	for(FLuaValue i : ULuaBlueprintFunctionLibrary::LuaTableGetKeys(table))
	{
		FString local_key = ULuaBlueprintFunctionLibrary::Conv_LuaValueToString(i);
		ULuaObject* newobj= CreateLuaObject(WorldContextObject,i,ULuaBlueprintFunctionLibrary::LuaTableGetField(table,local_key));
		out.Add(newobj);
	}
	return out;
}

TArray<ULuaObject*> ULuaObjectFunctions::CreateLuaObjectsFromKeysInTable(UObject* WorldContextObject, FLuaValue keys, FLuaValue table)
{
	TArray<ULuaObject*> out;
	for(FLuaValue i : ULuaBlueprintFunctionLibrary::LuaTableGetValues(keys))
	{
		FString local_key = ULuaBlueprintFunctionLibrary::Conv_LuaValueToString(i);
		ULuaObject* newobj= CreateLuaObject(WorldContextObject,i,ULuaBlueprintFunctionLibrary::LuaTableGetField(table,local_key));
		out.Add(newobj);
	}
	return out;
}

FLuaValue ULuaObjectFunctions::ConvertTableKeysToValues(UObject* WorldContextObject, FLuaValue table)
{
	FLuaValue new_table = ULuaBlueprintFunctionLibrary::LuaCreateTable(WorldContextObject,ULuaBlueprintFunctionLibrary::GetDefaultLuaState());
	int32 Tempindex=0;
	for(FLuaValue i: ULuaBlueprintFunctionLibrary::LuaTableGetKeys(table))
	{
		Tempindex+=1;
		new_table=ULuaBlueprintFunctionLibrary::LuaTableSetByIndex(new_table,Tempindex,i);
	}
	return new_table;
}

FLuaValue ULuaObjectFunctions::RunLuaScriptContainer(UObject* WorldContextObject, FLuaScriptContainer Script,
	TSubclassOf<ULuaState> State)
{
	if(Script.code_asset)
	{
		return ULuaBlueprintFunctionLibrary::LuaRunCodeAsset(WorldContextObject, State,Script.code_asset);
	}
	return ULuaBlueprintFunctionLibrary::LuaRunString(WorldContextObject, State,Script.code_string);
}

void ULuaObjectFunctions::GetObjectKeyAndValue(UObject* Object, FLuaValue& Key, FLuaValue& Value)
{
	if(Object && Object->GetClass()->ImplementsInterface(ULuaInterface::StaticClass()))
	{
		Key=ILuaInterface::Execute_GetKey(Object);
		Value=ILuaInterface::Execute_GetValue(Object,"");
	}
}

void ULuaObjectFunctions::SetObjectKeyAndValue(UObject* Object, FLuaValue Key, FLuaValue Value)
{
	if(Object && Object->GetClass()->ImplementsInterface(ULuaInterface::StaticClass()))
	{
		ILuaInterface::Execute_SetKey(Object,Key);
		ILuaInterface::Execute_SetValue(Object,Value,"");
	}
}
