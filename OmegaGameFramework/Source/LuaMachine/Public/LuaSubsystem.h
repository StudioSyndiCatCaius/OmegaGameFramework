// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LuaObject.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LuaSubsystem.generated.h"

class ULuaSettings;
/**
 * 
 */
UCLASS()
class LUAMACHINE_API ULuaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	
	UPROPERTY()
	ULuaSettings* settings_ref;

public:
	bool b_IsInitialized=false;
	UPROPERTY()
	TMap<FString, ULuaObject*> globalLuaObjects;
	
	UFUNCTION(BlueprintPure,Category="Lua")
	FString GetLocalFilesPath();
	
	UFUNCTION(BlueprintCallable,Category="Lua")
	FLuaValue RunLocalFile(const FString& file,bool bNonLocal);
	
	UFUNCTION(BlueprintCallable,Category="Lua")
	void RunLocalFilesInPath(const FString& path,bool bRecursive,bool bNonLocal);
	
};

UCLASS()
class LUAMACHINE_API ULuaEngineSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:

};

UCLASS()
class LUAMACHINE_API ULuaWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	TArray<FName> GetGlobalKeys(FString global);
	void RerunLua();
};

UCLASS()
class LUAMACHINE_API ULuaGlobalObjectFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Lua|Object",DisplayName="Get Global Lua Asset (From Tag)",meta=(WorldContext="WorldContextObject",AdvancedDisplay="State"))
	static ULuaObject* GetGlobalLuaObject_FromTag(UObject* WorldContextObject, FGameplayTag name, TSubclassOf<ULuaState> State);

	UFUNCTION(BlueprintCallable,Category="Lua|Object",DisplayName="Get Global Lua Asset (From String)",meta=(WorldContext="WorldContextObject",AdvancedDisplay="State"))
	static ULuaObject* GetGlobalLuaObject_FromString(UObject* WorldContextObject, const FString& name, TSubclassOf<ULuaState> State);
};
