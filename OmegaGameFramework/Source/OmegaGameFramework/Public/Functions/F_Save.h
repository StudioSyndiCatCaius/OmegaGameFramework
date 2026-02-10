// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"

#include "F_Save.generated.h"


class UOmegaSaveGlobal;
class UOmegaSaveGame;
class USaveGame;


UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaSaveFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|Save", meta = (WorldContext = "WorldContextObject",DeterminesOutputType="Class"))
	static UOmegaSaveGame* GetSave_Game(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGame> Class=nullptr);

	UFUNCTION(BlueprintPure,Category="Omega|Save", meta = (WorldContext = "WorldContextObject",DeterminesOutputType="Class"))
	static UOmegaSaveGlobal* GetSave_Global(const UObject* WorldContextObject, TSubclassOf<UOmegaSaveGlobal> Class=nullptr);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Set TagParam <Int>")
	static void SetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 Value, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Set TagParam <Bool>")
	static void SetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool Value, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Get TagParam <Int>")
	static int32 GetSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);

	UFUNCTION(BlueprintPure, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Set TagParam <Bool>")
	static bool GetSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandBoolAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Check TagParam <Bool>")
	static bool CheckSaveParam_Tag_Bool(const UObject* WorldContextObject, FGameplayTag Param, bool bGlobal, bool& Outcome);
	
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",ExpandEnumAsExecs = "Outcome",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Check TagParam <Int>")
	static int32 CheckSaveParam_Tag_Int(const UObject* WorldContextObject, FGameplayTag Param, int32 CheckValue, bool bGlobal, TEnumAsByte<EOmegaComparisonMethodSimple>& Outcome);

	//Asset
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Data Asset - Get JSON")
	static FJsonObjectWrapper DataAsset_GetJson(const UObject* WorldContextObject, UPrimaryDataAsset* Asset, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) Data Asset - Set JSON")
	static void DataAsset_SetJson(const UObject* WorldContextObject, UPrimaryDataAsset* Asset, FJsonObjectWrapper Json, bool bGlobal);
	
	//GUID
	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) GUID - Get JSON")
	static FJsonObjectWrapper GUID_GetJson(const UObject* WorldContextObject, FGuid Guid, bool bGlobal);

	UFUNCTION(BlueprintCallable, Category="Omega|Save", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"),DisplayName="(SAVE) GUID - Set JSON")
	static void GUID_SetJson(const UObject* WorldContextObject, FGuid Guid, FJsonObjectWrapper Json, bool bGlobal);
	
	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="Save Game (Custom)")
	static bool Custom_SaveGame(USaveGame* SaveGameObject, const FString& path, const FString& file);

	UFUNCTION(BlueprintCallable, Category = "Omega|Save|Custom",DisplayName="Load Game (Custom)")
	static USaveGame* Custom_LoadGame(const FString& path, const FString& file);
	
};

