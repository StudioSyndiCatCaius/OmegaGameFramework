
#pragma once

#include "CoreMinimal.h"
#include "Struct_Bitflag.generated.h"


//// Single entry for a bitflag
USTRUCT(BlueprintType)
struct FOmegaBitmaskEditorEntry
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	FText Title;
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega",meta=(MultiLine))
	FText Description;
	
	FOmegaBitmaskEditorEntry() : Title(FText::GetEmpty()) {}
};

// Data for a single BitEnum entry (has its own title and list of options)
USTRUCT(BlueprintType)
struct FOmegaBitmaskEditorEnumData
{
	GENERATED_BODY()
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	FText Title;
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega",meta=(MultiLine))
	FText Description;

	// Options for this enum (max 16 options, values 0-15)
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TArray<FOmegaBitmaskEditorEntry> Options;

	FOmegaBitmaskEditorEnumData() : Title(FText::GetEmpty()) {}
};

// Complete editor data for a bitflag type
USTRUCT(BlueprintType)
struct FOmegaBitmaskEditorData
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TSoftClassPtr<UObject> CopyFrom;
	
	// Bitflags section (up to 32 entries)
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TArray<FOmegaBitmaskEditorEntry> Bitflags;

	// BitEnums section (up to 16 entries, each with up to 16 options)
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TArray<FOmegaBitmaskEditorEnumData> BitEnums;
};

USTRUCT(BlueprintType)
struct FOmegaBitflagsBase
{
	GENERATED_BODY()
	
	FOmegaBitmaskEditorData GetConfig(UClass* OuterObject);
	
	UPROPERTY(Transient) bool override_config;
	UPROPERTY(Transient) FOmegaBitmaskEditorData override_configData;
	UPROPERTY(Transient) TWeakObjectPtr<UObject> override_source;
	
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

