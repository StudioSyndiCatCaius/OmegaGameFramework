// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_BitFlag.generated.h"

// Base struct with shared functionality
USTRUCT(BlueprintType)
struct FOmegaBitflagsBase
{
    GENERATED_BODY()
    virtual ~FOmegaBitflagsBase() = default;
    // Boolean bitmask (each bit is on/off) - supports 32 flags
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega")
    int32 Bitmask = 0;

    // Packed enum values - 16 flags with 4 bits each (values 0-15)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Omega")
    int64 BitEnums = 0;

    FOmegaBitflagsBase() : Bitmask(0), BitEnums(0) {}

    // Bitmask helper functions (32 flags)
    bool HasFlag(int32 BitIndex) const
    {
        return (Bitmask & (1 << BitIndex)) != 0;
    }

    void SetFlag(int32 BitIndex, bool bEnabled)
    {
        if (bEnabled)
        {
            Bitmask |= (1 << BitIndex);
        }
        else
        {
            Bitmask &= ~(1 << BitIndex);
        }
    }

    void ToggleFlag(int32 BitIndex)
    {
        Bitmask ^= (1 << BitIndex);
    }

    // BitEnums helper functions (16 flags, values 0-15)
    int32 GetBitEnum(int32 BitIndex) const
    {
        if (BitIndex < 0 || BitIndex >= 16)
        {
            return 0;
        }
        // Extract 4 bits at the correct position
        int32 Shift = BitIndex * 4;
        return (BitEnums >> Shift) & 0xF;
    }

    void SetBitEnum(int32 BitIndex, int32 Value)
    {
        if (BitIndex < 0 || BitIndex >= 16)
        {
            return;
        }
        // Clamp value to 0-15
        Value = FMath::Clamp(Value, 0, 15);
        
        int32 Shift = BitIndex * 4;
        // Clear the 4 bits at this position
        BitEnums &= ~(0xFLL << Shift);
        // Set the new value
        BitEnums |= ((int64)Value << Shift);
    }

};






// ===================================================================================================================
// IntState
// ===================================================================================================================
UINTERFACE(MinimalAPI) class UDataInterface_BitFlag : public UInterface { GENERATED_BODY() };
class OMEGAGAMEFRAMEWORK_API IDataInterface_BitFlag
{
	GENERATED_BODY()

	public:

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="BitFlag") void Bitflags_Set(FOmegaBitflagsBase bitmask);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="BitFlag") FOmegaBitflagsBase Bitflags_Get();
};

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
    
   // UFUNCTION(BlueprintPure,Category="Omega|BitFlags|Conv", DisplayName="Lua > Bitflag")
   // static FOmegaBitflagsBase Conv_LuaToBitflags(FLuaValue Lua);
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
    if(obj && obj->GetClass()->ImplementsInterface(UDataInterface_BitFlag::StaticClass()))
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
        bf=IDataInterface_BitFlag::Execute_Bitflags_Get(object);
        return bf.HasFlag(flag);
    }
    return false;
}

inline void UOmegaBitFlagFunctions::SetObjectBitflag(UObject* object, int32 flag, bool Value)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_BitFlag::Execute_Bitflags_Get(object);
        bf.SetFlag(flag,Value);
        IDataInterface_BitFlag::Execute_Bitflags_Set(object,bf);
    }
}

inline int32 UOmegaBitFlagFunctions::GetObjectBitenum(UObject* object, int32 id)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_BitFlag::Execute_Bitflags_Get(object);
        return bf.GetBitEnum(id);
    }
    return 0;
}

inline void UOmegaBitFlagFunctions::SetObjectBitenum(UObject* object, int32 id, int32 Value)
{
    if(obj_usesInterface(object))
    {
        FOmegaBitflagsBase bf;
        bf=IDataInterface_BitFlag::Execute_Bitflags_Get(object);
        bf.SetBitEnum(id,Value);
        IDataInterface_BitFlag::Execute_Bitflags_Set(object,bf);
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
