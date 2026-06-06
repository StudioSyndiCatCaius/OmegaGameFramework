// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "UObject/Interface.h"
#include "Types/Struct_CustomNamedList.h"
#include "F_NamedLists.generated.h"

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

#define GENERAL_INTERFACE_GETMETA() \
FText _n,_d; FSlateBrush _i; FLinearColor _c; FString _l; FOmegaObjectGeneralMetaconfig _meta; \
IDataInterface_General::Execute_GetGeneralDataText(object,FGameplayTag(),_n,_d,_i,_c,_l,_meta); \
FOmegaBitflagsBase& b=_meta.bitflags; \
FGuid& g=_meta.guid; \
int32& s=_meta.seed; \
FOmegaClassNamedLists& nl=_meta.named_lists; \

inline FName UOmegaFunctions_NamedLists::GetObjectNamedListOption(UObject* object, FName List)
{
	if (object && object->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
	{
		GENERAL_INTERFACE_GETMETA()
	
		return nl.CustomNamedList.FindOrAdd(List).Option;
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


#undef GENERAL_INTERFACE_GETMETA