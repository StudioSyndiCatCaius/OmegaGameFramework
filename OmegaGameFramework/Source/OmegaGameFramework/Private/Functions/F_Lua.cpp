// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Lua.h"

#include "FileSDKBPLibrary.h"
#include "LuaBlueprintFunctionLibrary.h"
#include "LuaInterface.h"
#include "OmegaSettings.h"
#include "OmegaGameManager.h"
#include "Functions/F_File.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/OmegaUtils_Macros.h"
#include "Statics/OMEGA_File.h"

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
	if(WorldContextObject.IsValid())
	{
		return ULuaBlueprintFunctionLibrary::LuaCreateTable(WorldContextObject.Get(),nullptr);	
	}
	return FLuaValue();
}

FLuaValue UOmegaLuaParser::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	return FLuaValue();
}

TArray<FName> UOmegaLuaFunctions::L_GetExternalScriptList()
{
	TArray<FName> out;
	for (FString f : OMEGA_File::ListFilesInDirectory(UOmegaFileFunctions::GetPluginBaseDir("OmegaGameFramework")+"/lua/",true))
	{
		out.Add(*FPaths::GetBaseFilename(f));
	}
	return out;
}

FLuaValue UOmegaLuaFunctions::RunPluginExternalScript(UObject* WorldContextObject, FName Script,
                                                      TArray<FLuaValue> Args, TSubclassOf<ULuaState> State)
{
	FString file_string;
	FString script_path=UOmegaFileFunctions::GetPluginBaseDir("OmegaGameFramework")+"/lua/"+Script.ToString()+".lua";
	
	
	FFileHelper::LoadFileToString(file_string, *script_path);
	return ULuaBlueprintFunctionLibrary::LuaRunString_AsFunction(WorldContextObject,State,file_string,Args);
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

FString UOmegaLuaFunctions::Object_GetMetakey(UObject* object)
{
	if (object)
	{
		FString ClassName = object->GetClass()->GetName();
		if (ClassName.EndsWith(TEXT("_C")))
		{
			ClassName.LeftChopInline(2);
		}
		return OGF_CFG_LUA()->Object_MetakeyPrefex+ClassName+"."+object->GetName();
	}
	return FString();
}


FLuaValue UOmegaLuaFunctions::Object_GetMetadata(UObject* WorldContextObject, UObject* object)
{
	if (OGF_CFG_LUA()->bUseLuaObjectMetadata)
	{
		return ULuaBlueprintFunctionLibrary::LuaGetGlobal(WorldContextObject,nullptr,Object_GetMetakey(object));	
	}
	return FLuaValue();	
}

TArray<UObject*> UOmegaLuaFunctions::FilterObjects_ByParamValue(UObject* WorldContextObject, TArray<UObject*> objects,
                                                                TSubclassOf<UObject> Class, const FString& param, FLuaValue Value)
{
	TArray<UObject*> out;
	for (UObject* obj : objects)
	{
		if (obj && obj->GetClass()->ImplementsInterface(ULuaInterface::StaticClass()) && (!Class || obj->GetClass()->IsChildOf(Class)))
		{
			FLuaValue LuaValue=ILuaInterface::Execute_GetValue(obj,param);
			if(LuaValue.GetField(param).ToString()==Value.ToString())
			{
				out.Add(obj);	
			}
		}
	}
	
	return out;
}
