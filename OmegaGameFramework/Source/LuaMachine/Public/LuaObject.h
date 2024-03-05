// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaCode.h"
#include "LuaInterface.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LuaObject.generated.h"

USTRUCT(BlueprintType)
struct FLuaScriptContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lua",meta=(MultiLine))
	FString code_string;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lua",meta=(MultiLine))
	ULuaCode* code_asset;
};

UCLASS()
class LUAMACHINE_API ULuaObject : public UPrimaryDataAsset, public ILuaInterface
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FLuaValue lua_key;
	UPROPERTY()
	FLuaValue lua_value;
	virtual void SetKey_Implementation(FLuaValue Key) override;
	virtual void SetValue_Implementation(FLuaValue Value, const FString& Field) override;
	virtual FLuaValue GetKey_Implementation() override;
	virtual FLuaValue GetValue_Implementation(const FString& Field) override;
};


UCLASS()
class LUAMACHINE_API ULuaObjectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject"))
	static ULuaObject* CreateLuaObject(UObject* WorldContextObject, FLuaValue key, FLuaValue value);

	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject"))
	static TArray<ULuaObject*> CreateLuaObjectsFromTable(UObject* WorldContextObject,FLuaValue table);

	//Will create a list of objects with the keys from the "key" table, and their values from their corresponding "table" value.
	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject"))
	static TArray<ULuaObject*> CreateLuaObjectsFromKeysInTable(UObject* WorldContextObject,FLuaValue keys,FLuaValue table);

	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject"))
	static FLuaValue ConvertTableKeysToValues(UObject* WorldContextObject, FLuaValue table);

	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject", AdvancedDisplay="State"))
	static FLuaValue RunLuaScriptContainer(UObject* WorldContextObject,FLuaScriptContainer Script,TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject", AdvancedDisplay="State"))
	static void GetObjectKeyAndValue(UObject* Object, FLuaValue& Key,FLuaValue& Value);
	
	UFUNCTION(BlueprintCallable, Category="Lua|Object", meta=(WorldContext="WorldContextObject", AdvancedDisplay="State"))
	static void SetObjectKeyAndValue(UObject* Object, FLuaValue Key,FLuaValue Value);
};