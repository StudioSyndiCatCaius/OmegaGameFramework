// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LuaValue.h"

#include "LuaInterface.generated.h"

UINTERFACE(MinimalAPI)
class ULuaInterface : public UInterface { GENERATED_BODY() };


class LUAMACHINE_API ILuaInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="ΩI|Lua",DisplayName="Lua - Set Value")
	void SetValue(FLuaValue Value,const FString& Flag="");

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="ΩI|Lua",DisplayName="Lua - Set Key")
	void SetKey(FLuaValue Key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="ΩI|Lua",DisplayName="Lua - Get Value")
	FLuaValue GetValue(const FString& Field);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="ΩI|Lua",DisplayName="Lua - Get Value")
	FLuaValue GetKey();
};
