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
	UPROPERTY() TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> cached_ClassPaths;
	
	UPROPERTY() TMap<FString, UObject*> SortedAssets;
	
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


