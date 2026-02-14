// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Entity.generated.h"

class UOmegaSaveBase;

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFunctions_Entity : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static UOmegaSaveBase* _getEntitySaveObj(const UObject* context,bool bGlobal);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static void SetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, FOmegaEntity Entity, bool bGlobal);
	UFUNCTION(BlueprintCallable,Category="Omega|Save|Entity", meta = (WorldContext = "WorldContextObject",AdvancedDisplay="bGlobal"))
	static FOmegaEntity GetEntity_ByID(const UObject* WorldContextObject, FOmegaEntityID ID, bool bGlobal);
	
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Data Asset > Entity ID")
	static FOmegaEntityID Conv_DataAsset_2_EntityID(UPrimaryDataAsset* Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Name > Entity ID")
	static FOmegaEntityID Conv_Name_2_EntityID(FName Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="GUID > Entity ID")
	static FOmegaEntityID Conv_GUID_2_EntityID(FGuid Key);
	
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Entity ID > Data Asset")
	static UPrimaryDataAsset* Conv_EntityID_2_DataAsset(FOmegaEntityID Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Entity ID >  Name")
	static FName Conv_EntityID_2_Name(FOmegaEntityID Key);
	UFUNCTION(BlueprintPure,Category="Omega|Save|Entity",DisplayName="Entity ID >  GUID")
	static FGuid Conv_EntityID_2_GUID(FOmegaEntityID Key);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Get Param (Int)")
	static int32 GetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param, bool bGlobalSave);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Set Param (Int)")
	static void SetSaveEntity_Param(UObject* WorldContextObject, FOmegaEntityID ID, FName param, int32 Value, bool bAdded, bool bGlobalSave);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Get Param (String)")
	static FString GetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, FName param, bool bGlobalSave);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Set Param (String)")
	static void SetSaveEntity_ParamString(UObject* WorldContextObject, FOmegaEntityID ID, FName param, FString Value, bool bGlobalSave);
	
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Set Tag")
	static void SetSaveEntity_Tag(UObject* WorldContextObject, FOmegaEntityID ID, FName tag, bool bActive, bool bGlobalSave);
	UFUNCTION(BlueprintCallable,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Set Tags")
	static void SetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID, TArray<FName> tags, bool bActive, bool bGlobalSave);
	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Get Tags")
	static TArray<FName> GetSaveEntity_Tags(UObject* WorldContextObject, FOmegaEntityID ID, bool bGlobalSave);
	UFUNCTION(BlueprintPure,Category="Omega|Entities",meta=(WorldContext="WorldContextObject",AdvancedDisplay="bGlobalSave"),DisplayName="Entity - Has Tag?")
	static bool SaveEntity_HasTag(UObject* WorldContextObject, FOmegaEntityID ID, FName tag, bool bGlobalSave);
};
