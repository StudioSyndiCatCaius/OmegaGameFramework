// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/I_Common.h"
#include "UObject/Interface.h"
#include "Types/Struct_Bitflag.h"
#include "F_BitFlag.generated.h"


UCLASS()
class UOmegaBitFlagFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintPure,Category="Omega|BitFlags",DisplayName="Bitflag - Get")
    static bool GetObjectBitflag(UObject* object,int32 id);

    UFUNCTION(BlueprintPure,Category="Omega|BitFlags",DisplayName="BitEnum - Get")
    static int32 GetObjectBitenum(UObject* object,int32 id);

	UFUNCTION(BlueprintPure,Category="Omega|BitFlags",DisplayName="Bitflag (Struct) - Get")
    static bool GetBitflag(FOmegaBitflagsBase bitflags,int32 flag);

    UFUNCTION(BlueprintPure,Category="Omega|BitFlags",DisplayName="BitEnum (Struct) - Get")
    static int32 GetBitenum(FOmegaBitflagsBase bitflags,int32 flag);

    UFUNCTION(BlueprintCallable,Category="Omega|BitFlags",meta=(DeterminesOutputType="Class"))
    static TArray<UObject*> FilterObjectsWithBitFlag(TArray<UObject*> object,int32 flag, TSubclassOf<UObject> Class, bool Value=true);

};

inline bool UOmegaBitFlagFunctions::GetBitflag(FOmegaBitflagsBase bitflags, int32 flag)
{
    return bitflags.HasFlag(flag);
}

inline int32 UOmegaBitFlagFunctions::GetBitenum(FOmegaBitflagsBase bitflags, int32 id)
{
    return bitflags.GetBitEnum(id);
}


inline bool obj_usesInterface(UObject* obj)
{
    if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
    {
        return true;
    }
    return false;
}

#define GENERAL_INTERFACE_GETMETA() \
FOmegaBitflagsBase b; \
FGuid g; \
int32 s; \
FOmegaClassNamedLists nl; \
IDataInterface_General::Execute_GetMetaConfig(object,b,g,s,nl); \

inline bool UOmegaBitFlagFunctions::GetObjectBitflag(UObject* object, int32 flag)
{
    if(obj_usesInterface(object))
    {
        GENERAL_INTERFACE_GETMETA()
        return b.HasFlag(flag);
    }
    return false;
}


inline int32 UOmegaBitFlagFunctions::GetObjectBitenum(UObject* object, int32 id)
{
    if(obj_usesInterface(object))
    {
        GENERAL_INTERFACE_GETMETA()
        return b.GetBitEnum(id);
    }
    return 0;
}


inline TArray<UObject*> UOmegaBitFlagFunctions::FilterObjectsWithBitFlag(TArray<UObject*> object, int32 flag,
                                                                         TSubclassOf<UObject> Class, bool Value)
{
    TArray<UObject*> out;
    for(auto* a : object)
    {
        if(a && (!Class || a->GetClass()->IsChildOf(Class)))
        {
            if(GetObjectBitflag(a,flag)==Value)
            {
                out.Add(a);
            }
        }
    }
    return out;
}

#undef GENERAL_INTERFACE_GETMETA