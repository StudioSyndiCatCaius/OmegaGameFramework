// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/Struct_CustomLevel.h"

#include "F_Level.generated.h"



class ALevelInstance;

UCLASS()
class UOmegaLevelFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	static void LoadSublevelFromStateParam(UObject* WorldContextObject, FName param, int32 NewValue, int32 OldValue=-1);

	UFUNCTION(BlueprintPure,Category="Omega|Level")
	static bool IsLevelInstance_ReferenceValid(const ALevelInstance* LevelInstance);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Level", meta=(WorldContext="WorldContextObject"))
	static bool SetWorldPaused(UObject* WorldContextObject, bool bPaused);

	// Soft reference - doesn't force load
	UFUNCTION(BlueprintPure, Category="Omega|World", meta=(WorldContext="WorldContextObject"),DisplayName="🌎Level - World Asset From Name")
	static TSoftObjectPtr<UWorld> GetLevelSoftRefFromName(FName LevelName);
	
	
	// Hard reference - loads and keeps in memory
	UFUNCTION(BlueprintCallable, Category="Omega|World", meta=(WorldContext="WorldContextObject"),DisplayName="🌎Level - Get Current World Asset (Hard)")
	static UWorld* GetPersistentWorldAsset(const UObject* WorldContextObject);

	// Soft reference - doesn't force load
	UFUNCTION(BlueprintPure, Category="Omega|World", meta=(WorldContext="WorldContextObject"),DisplayName="🌎Level - Get Current World Asset (Soft)")
	static TSoftObjectPtr<UWorld> GetPersistentWorldAssetSoft(const UObject* WorldContextObject);
	
	
	//WARNING: This will duplicate the entire level, and is VERY SLOW
	UFUNCTION(BlueprintPure, Category="Omega|Level|Custom", meta=(WorldContext="WorldContextObject"))
	static FOmegaCustomLevelWrapper DuplicateCurrentLevelAsCustom(UObject* WorldContextObject, bool& bSuccess);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Level|Custom", meta=(WorldContext="WorldContextObject"))
	static FOmegaCustomLevelWrapper LoadCustomLevelFromJson(UObject* WorldContextObject, const FString& JsonString, bool& bSuccess);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Level|Custom")
	static FString SaveCustomLevelToJson(FOmegaCustomLevelWrapper CustomLevel, FOmegaCustomLevelSaveConfig Config, bool& bSuccess);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Level|Custom", meta=(WorldContext="WorldContextObject"))
	static bool OpenCustomLevel(FOmegaCustomLevelWrapper CustomLevel, UObject* WorldContextObject, FName ContainerLevelName);
	
	UFUNCTION(BlueprintPure, Category="Omega|Level|Sublevel", meta=(WorldContext="WorldContextObject"),DisplayName="🌎Sublevel - Get All")
	static TArray<FName> Sublevel_GetAll(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Level|Sublevel", meta=(WorldContext="WorldContextObject"),DisplayName="🌎Sublevel - Set Loaded")
	static void Sublevel_SetLoaded(UObject* WorldContextObject, FName Sublevel, bool bLoaded);
};
