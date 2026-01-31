// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Types/Struct_CustomNamedList.h"
#include "I_NamedLists.generated.h"

// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_NamedLists : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_NamedLists
{
	GENERATED_BODY()

	public:

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="NamedList")
	FOmegaClassNamedLists GetClassNamedLists();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="NamedList")
	TArray<FName> Override_ObjectLists();
};

UCLASS()
class UOmegaFunctions_NamedLists : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|NamedList")
    static FName GetObjectNamedListOption(UObject* object, FName List);

	UFUNCTION(BlueprintCallable,Category="Omega|NamedList",meta=(DeterminesOutputType="Class"))
	static TArray<UObject*> FilterObjectsWithNamedListValue(TArray<UObject*> object, TSubclassOf<UObject> Class, FName List, FName Value);
};

inline FName UOmegaFunctions_NamedLists::GetObjectNamedListOption(UObject* object, FName List)
{
	if (object && object->GetClass()->ImplementsInterface(UDataInterface_NamedLists::StaticClass()))
	{
		FOmegaClassNamedLists NamedLists=IDataInterface_NamedLists::Execute_GetClassNamedLists(object);
		return NamedLists.CustomNamedList.FindOrAdd(List).Option;
	}
	return FName();
}

inline TArray<UObject*> UOmegaFunctions_NamedLists::FilterObjectsWithNamedListValue(TArray<UObject*> object,
	TSubclassOf<UObject> Class, FName List, FName Value)
{
	TArray<UObject*> out; 
	for (auto* item : object)
	{
		if (item)
		{
			if (GetObjectNamedListOption(item, List)==Value && (!Class || item->GetClass()->IsChildOf(Class)))
			{
				out.Add(item);
			}
		}
	}
	return out;
}

