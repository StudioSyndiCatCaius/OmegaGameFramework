// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "I_Common.h"
#include "UObject/Interface.h"
#include "Types/Struct_Bitflag.h"
#include "F_BitFlag.generated.h"


UCLASS()
class UOmegaBitFlagFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure,Category="Omega|BitFlags")
    static bool GetBitflag(FOmegaBitflagsBase bitflags,int32 flag);
    UFUNCTION(BlueprintCallable,Category="Omega|BitFlags")
    static void SetBitflag(UPARAM(ref) FOmegaBitflagsBase& bitflags,int32 flag, bool Value);
    
    UFUNCTION(BlueprintPure,Category="Omega|BitFlags")
    static int32 GetBitenum(FOmegaBitflagsBase bitflags,int32 flag);
    UFUNCTION(BlueprintCallable,Category="Omega|BitFlags")
    static void SetBitenum(UPARAM(ref) FOmegaBitflagsBase& bitflags,int32 flag, int32 Value);
    
    UFUNCTION(BlueprintPure,Category="Omega|BitFlags")
    static bool GetObjectBitflag(UObject* object,int32 id);
    UFUNCTION(BlueprintCallable,Category="Omega|BitFlags")
    static void SetObjectBitflag(UObject* object,int32 id, bool Value);

    UFUNCTION(BlueprintPure,Category="Omega|BitFlags")
    static int32 GetObjectBitenum(UObject* object,int32 id);
    UFUNCTION(BlueprintCallable,Category="Omega|BitFlags")
    static void SetObjectBitenum(UObject* object,int32 id, int32 Value);
    
    UFUNCTION(BlueprintCallable,Category="Omega|BitFlags",meta=(DeterminesOutputType="Class"))
    static TArray<UObject*> FilterObjectsWithBitFlag(TArray<UObject*> object,int32 flag, TSubclassOf<UObject> Class, bool Value=true);

};

inline bool UOmegaBitFlagFunctions::GetBitflag(FOmegaBitflagsBase bitflags, int32 flag)
{
    return bitflags.HasFlag(flag);
}

inline void UOmegaBitFlagFunctions::SetBitflag(FOmegaBitflagsBase& bitflags, int32 flag, bool Value)
{
    bitflags.SetFlag(flag,Value);
}

inline int32 UOmegaBitFlagFunctions::GetBitenum(FOmegaBitflagsBase bitflags, int32 id)
{
    return bitflags.GetBitEnum(id);
}

inline void UOmegaBitFlagFunctions::SetBitenum(FOmegaBitflagsBase& bitflags, int32 id, int32 Value)
{
    bitflags.SetBitEnum(id,Value);
}

inline bool obj_usesInterface(UObject* obj)
{
    if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()))
    {
        return true;
    }
    return false;
}

inline bool UOmegaBitFlagFunctions::GetObjectBitflag(UObject* object, int32 flag)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_General::Execute_Bitflags_Get(object);
        return bf.HasFlag(flag);
    }
    return false;
}

inline void UOmegaBitFlagFunctions::SetObjectBitflag(UObject* object, int32 flag, bool Value)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_General::Execute_Bitflags_Get(object);
        bf.SetFlag(flag,Value);
        IDataInterface_General::Execute_Bitflags_Set(object,bf);
    }
}

inline int32 UOmegaBitFlagFunctions::GetObjectBitenum(UObject* object, int32 id)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_General::Execute_Bitflags_Get(object);
        return bf.GetBitEnum(id);
    }
    return 0;
}

inline void UOmegaBitFlagFunctions::SetObjectBitenum(UObject* object, int32 id, int32 Value)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_General::Execute_Bitflags_Get(object);
        bf.SetBitEnum(id,Value);
        IDataInterface_General::Execute_Bitflags_Set(object,bf);
    }
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
