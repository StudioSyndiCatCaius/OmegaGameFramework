// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "LuaValue.h"

#include "F_Lua.generated.h"





UCLASS()
class UOmegaLuaFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|Lua")
	static FLuaValue GetObjectLua_Value(UObject* Object,const FString& Field="");

	UFUNCTION(BlueprintCallable,Category="Omega|Lua")
	static FName GetObjectLua_Key(UObject* Object);
	
	UFUNCTION(BlueprintPure,Category="Omega|Lua",DisplayName="Lua -> Actor")
	static AActor* Conv_LuaToActor(FLuaValue LuaValue);
	
};
