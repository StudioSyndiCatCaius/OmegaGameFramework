// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "UObject/Class.h"
#include "LuaValue.h"
#include "UObject/Object.h"
#include "Subsystems/EngineSubsystem.h"
#include "Types/Struct_SortedClassPath.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Subsystem_Engine.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOmegaGenericEngineDelegate);


USTRUCT()
struct FOmegaObjectNameParseParam
{
	GENERATED_BODY()
	
	UPROPERTY() FString param_str;
	UPROPERTY() int32 param_int;
};

USTRUCT()
struct FOmegaObjectNameParseCache
{
	GENERATED_BODY()
	
	UPROPERTY() TArray<FOmegaObjectNameParseParam> params;
};



UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSubsystem_Engine : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	UFUNCTION(BlueprintCallable,Category="Omega") void GlobalRefresh();
	
	UPROPERTY(BlueprintAssignable, Category="Omega") FOmegaGenericEngineDelegate OnGlobalRefresh;
	
	// ---------------------------------------------------------------
	// spawnables
	// ---------------------------------------------------------------
	UFUNCTION(BlueprintCallable,Category="Engine")
	void LoadDevConfig();
	
	FLuaValue Spawnable_GetData(FName key);
	
	TArray<FName> keys_spawnables;
	UPROPERTY(BlueprintReadWrite,Category="Engine") FLuaValue devconfig_table;
	UPROPERTY() TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> cache_ClassPaths;
	
	UPROPERTY() TMap<FString, UObject*> SortedAssets;
	//cache of params parsed from an object name (only works for Data assets currently)
	
	FOmegaObjectNameParseCache GetObjectNameParamCache(UObject* Object);
	FOmegaObjectNameParseParam GetObjectNameParam(UObject* Object, uint32 param_index);
	
	UPROPERTY() TMap<UObject*,FOmegaObjectNameParseCache> cache_objectNameParams;
	
	UFUNCTION() void OnGameInitialized();
	
	UFUNCTION(BlueprintCallable,Category="Omega|AssetHandler|Lua")
	void GenerateLuaTableDataAssets();
private:
	
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Engine : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	
	UFUNCTION(BlueprintPure,Category="Omega|SortedAssets",DisplayName="Sorted Asset - Get All")
	static TArray<UObject*> SortedAsset_GetAll();
	
	UFUNCTION(BlueprintPure,Category="Omega|SortedAssets",DisplayName="Sorted Asset - Get")
	static UObject* SortedAsset_Get(FString AssetLabel);
	
	UFUNCTION(BlueprintCallable,Category="Omega|SortedAssets",DisplayName="Sorted Asset - Set")
	static bool SortedAsset_Set(UObject* Asset, FString AssetLabel,bool bOverwrite);
};


