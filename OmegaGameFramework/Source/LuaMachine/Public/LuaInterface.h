// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LuaValue.h"

#include "LuaInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULuaInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LUAMACHINE_API ILuaInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Lua")
	void SetValue(FLuaValue Value,const FString& Field="");

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Lua")
	void SetKey(FLuaValue Key);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Lua")
	FLuaValue GetValue(const FString& Field);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Lua")
	FLuaValue GetKey();
};
