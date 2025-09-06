// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Misc/OmegaUtils_Structs.h"
#include "OmegaInterface_SoftCondition.generated.h"



// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_SoftCondition : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_SoftCondition
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ΩI|Soft",DisplayName="Soft Condition - ChecK")
	bool CheckCondition(FName Condition, FOmegaCommonMeta meta, FText& ResultReason);
	
};

UCLASS()
class UOmegaSoftConditionFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|SoftCondition")
	bool CheckObjectSoftCondition(UObject* Object, FName Condition, FOmegaCommonMeta meta, FText& Reason);
	
	UFUNCTION(BlueprintCallable,Category="Omega|SoftCondition")
	TArray<UObject*> FilterObjectsBySoftCondition(TArray<UObject*> In, FName Condition, FOmegaCommonMeta meta);
	
};

inline bool UOmegaSoftConditionFunctions::CheckObjectSoftCondition(UObject* Object, FName Condition,
	FOmegaCommonMeta meta, FText& Reason)
{
	if(Object && Object->GetClass()->ImplementsInterface(UDataInterface_SoftCondition::StaticClass()))
	{
		return IDataInterface_SoftCondition::Execute_CheckCondition(Object,Condition,meta,Reason);
	}
	return false;
}

inline TArray<UObject*> UOmegaSoftConditionFunctions::FilterObjectsBySoftCondition(TArray<UObject*> In, FName Condition,
	FOmegaCommonMeta meta)
{
	TArray<UObject*> out;
	for(auto* o :In)
	{
		FText dum;
		if(CheckObjectSoftCondition(o,Condition,meta,dum))
		{
			out.Add(o);
		}
	}
	return out;
}

