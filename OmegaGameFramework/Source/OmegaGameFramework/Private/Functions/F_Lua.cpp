// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Lua.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "LuaInterface.h"
#include "OmegaSettings.h"
#include "OmegaGameCore.h"

FString UOmegaLuaParser::TrimQuotes(const FString& Str)
{
	FString Trimmed = Str;
	if (Trimmed.StartsWith("\"") && Trimmed.EndsWith("\"") && Trimmed.Len() >= 2)
	{
		Trimmed = Trimmed.Mid(1, Trimmed.Len() - 2);
	}
	return Trimmed;
}

FLuaValue UOmegaLuaParser::CreateLuaTable() const
{
	return ULuaBlueprintFunctionLibrary::LuaCreateTable(WorldContextObject,nullptr);
}

FLuaValue UOmegaLuaParser::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	return FLuaValue();
}

FLuaValue UOmegaLuaFunctions::GetObjectLua_Value(UObject* Object,const FString& Flag)
{
	FLuaValue LuaObject;
	if (Object)
	{
		if (Object->GetClass()->ImplementsInterface(ULuaInterface::StaticClass()))
		{
			LuaObject=ILuaInterface::Execute_GetValue(Object,Flag);
		}
	}
	if (LuaObject.IsNil())
	{
		LuaObject=GetMutableDefault<UOmegaSettings>()->GetGameCore()->Lua_GetObjectValue(Object);
	}
	return LuaObject;
	
}

FName UOmegaLuaFunctions::GetObjectLua_Key(UObject* Object)
{
	if (Object)
	{
		if (Object->GetClass()->ImplementsInterface(ULuaInterface::StaticClass()))
		{
			return ILuaInterface::Execute_GetKey(Object).ToName();
		}
	}
	return FName();
}

AActor* UOmegaLuaFunctions::Conv_LuaToActor(FLuaValue LuaValue)
{
	if (UObject* _obj=LuaValue.Object)
	{
		if (AActor* actor=Cast<AActor>(_obj))
		{
			return actor;
		}
		if (UActorComponent* acomp=Cast<UActorComponent>(_obj))
		{
			return acomp->GetOwner();
		}
	}
	return nullptr;
}

FLuaValue UOmegaLuaFunctions::ParseStringToLuaTable(UObject* WorldContextObject, const FString& String,
	TSubclassOf<UOmegaLuaParser> Parser)
{
	if (WorldContextObject && Parser)
	{
		UOmegaLuaParser* _parser=Parser.GetDefaultObject();
		_parser->WorldContextObject=WorldContextObject;
		return _parser->ParseStringToTable(WorldContextObject,String);
	}
	return FLuaValue();
}
