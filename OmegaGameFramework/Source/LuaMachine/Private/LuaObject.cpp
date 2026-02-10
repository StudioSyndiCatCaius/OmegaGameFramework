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

ULuaObject* ULuaObjectFunctions::CreateLuaObject(UObject* WorldContextObject, FLuaValue key, FLuaValue value)
{
	TSubclassOf<ULuaObject> target_class = ULuaObject::StaticClass();
	if (const TSubclassOf<ULuaObject> temp_class = GetMutableDefault<ULuaSettings>()->DefaultObject.LoadSynchronous())
	{
		target_class=temp_class;
	}
	FName in_name;
	if(key.Type==ELuaValueType::String && !key.String.IsEmpty())
	{
		in_name=FName(key.String);
	}
	ULuaObject* new_object = NewObject<ULuaObject>(WorldContextObject,target_class,in_name);
	new_object->lua_key=key;
	new_object->lua_value=value;
	return new_object;
}

ULuaObject* ULuaObjectFunctions::CreateLuaObjectFromGlobal(UObject* WorldContextObject,const FString& field, TSubclassOf<ULuaState> State)
{
	FString out_l;
	FString out_r;
	UKismetStringLibrary::Split(field,".",out_l,out_r,ESearchCase::IgnoreCase,ESearchDir::FromEnd);
	if(out_r.IsEmpty())
	{
		out_r=field;
	}
	FLuaValue val = ULuaBlueprintFunctionLibrary::LuaGetGlobal(WorldContextObject,State,field);
	FLuaValue key = ULuaBlueprintFunctionLibrary::Conv_StringToLuaValue(out_r);
	if(val.IsNil())
	{
		return nullptr;
	}
	return CreateLuaObject(WorldContextObject,key,val);
}

TArray<ULuaObject*> ULuaObjectFunctions::CreateLuaObjectsFromGlobal(UObject* WorldContextObject,
	const TArray<FString>& fields, TSubclassOf<ULuaState> State)
{
	TArray<ULuaObject*> out;
	for(FString temp_field : fields)
	{
		if(ULuaObject* temp_obj = CreateLuaObjectFromGlobal(WorldContextObject,temp_field,State))
		{
			out.Add(temp_obj);
		}
	}
	return out;
}


TArray<ULuaObject*> ULuaObjectFunctions::CreateLuaObjectsFromTable(UObject* WorldContextObject, FLuaValue table)
{
	TArray<ULuaObject*> out;
	TArray<FLuaValue> list =  ULuaBlueprintFunctionLibrary::LuaTableGetValues(table);
	for (int i = 0; i < list.Num(); ++i)
	{
		FLuaValue index_key = ULuaBlueprintFunctionLibrary::LuaTableGetKeys(table)[i];
		ULuaObject* newobj= CreateLuaObject(WorldContextObject,index_key,list[i]);
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
