// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Lua.h"

#include "LuaInterface.h"
#include "OmegaSettings.h"
#include "OmegaGameCore.h"

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
