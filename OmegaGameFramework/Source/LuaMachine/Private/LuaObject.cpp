// Fill out your copyright notice in the Description page of Project Settings.


#include "LuaObject.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "Kismet/KismetStringLibrary.h"

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

UObject* ULuaObjectFunctions::CreateLuaObject(UObject* WorldContextObject, FLuaValue key, FLuaValue value,TSubclassOf<UObject> Class)
{
	TSubclassOf<UObject> in_obj;
	if (Class && Class->ImplementsInterface(ULuaInterface::StaticClass()))
	{
		in_obj=Class;	
	}
	else
	{
		in_obj=ULuaObject::StaticClass();
	}
	FName in_name;
	if(key.Type==ELuaValueType::String && !key.String.IsEmpty())
	{
		in_name=FName(key.String);
	}
	UObject* new_object = NewObject<UObject>(WorldContextObject,in_obj,in_name);
	ILuaInterface::Execute_SetKey(new_object,key);
	ILuaInterface::Execute_SetValue(new_object,value,"");
	return new_object;
}


TArray<UObject*> ULuaObjectFunctions::CreateLuaObjectsFromTable(UObject* WorldContextObject, FLuaValue table,TSubclassOf<UObject> Class)
{
	TArray<UObject*> out;
	TArray<FLuaValue> list =  ULuaBlueprintFunctionLibrary::LuaTableGetValues(table);
	for (int i = 0; i < list.Num(); ++i)
	{
		FLuaValue index_key = ULuaBlueprintFunctionLibrary::LuaTableGetKeys(table)[i];
		if (UObject* newobj= CreateLuaObject(WorldContextObject,index_key,list[i],Class))
		{
			out.Add(newobj);	
		}
	}
	return out;
}

TArray<UObject*> ULuaObjectFunctions::CreateLuaObjectsFromKeysInTable(UObject* WorldContextObject, FLuaValue keys, FLuaValue table,TSubclassOf<UObject> Class)
{
	TArray<UObject*> out;
	for(FLuaValue i : ULuaBlueprintFunctionLibrary::LuaTableGetValues(keys))
	{
		FString local_key = ULuaBlueprintFunctionLibrary::Conv_LuaValueToString(i);
		if (UObject* newobj= CreateLuaObject(WorldContextObject,i,ULuaBlueprintFunctionLibrary::LuaTableGetField(table,local_key),Class))
		{
			out.Add(newobj);	
		}
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
