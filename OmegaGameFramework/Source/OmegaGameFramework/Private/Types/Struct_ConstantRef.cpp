// Fill out your copyright notice in the Description page of Project Settings.

#include "Types/Struct_ConstantRef.h"
#include "OmegaSettings_Constants.h"

// ─── Byte ─────────────────────────────────────────────────────────────────────

TArray<FName> FOmegaGlobalConst_Byte::L_GetVals() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings_Constants>()->Constant_byte.GetKeys(out);
	return out;
}

uint8 FOmegaGlobalConst_Byte::GetValue() const
{
	if (UseConstant)
	{
		return GetMutableDefault<UOmegaSettings_Constants>()->Constant_byte.FindRef(Constant);
	}
	return Value;
}

// ─── Float ────────────────────────────────────────────────────────────────────

TArray<FName> FOmegaGlobalConst_Float::L_GetVals() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings_Constants>()->Constant_float.GetKeys(out);
	return out;
}

float FOmegaGlobalConst_Float::GetValue() const
{
	if (UseConstant)
	{
		return GetMutableDefault<UOmegaSettings_Constants>()->Constant_float.FindRef(Constant);
	}
	return Value;
}

// ─── Int32 ────────────────────────────────────────────────────────────────────

TArray<FName> FOmegaGlobalConst_Int32::L_GetVals() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings_Constants>()->Constant_int.GetKeys(out);
	return out;
}

int32 FOmegaGlobalConst_Int32::GetValue() const
{
	if (UseConstant)
	{
		return GetMutableDefault<UOmegaSettings_Constants>()->Constant_int.FindRef(Constant);
	}
	return Value;
}

// ─── String ───────────────────────────────────────────────────────────────────

TArray<FName> FOmegaGlobalConst_String::L_GetVals() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings_Constants>()->Constant_string.GetKeys(out);
	return out;
}

FString FOmegaGlobalConst_String::GetValue() const
{
	if (UseConstant)
	{
		return GetMutableDefault<UOmegaSettings_Constants>()->Constant_string.FindRef(Constant);
	}
	return Value;
}

// ─── Text ─────────────────────────────────────────────────────────────────────

TArray<FName> FOmegaGlobalConst_Text::L_GetVals() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings_Constants>()->Constant_Text.GetKeys(out);
	return out;
}

FText FOmegaGlobalConst_Text::GetValue() const
{
	if (UseConstant)
	{
		return GetMutableDefault<UOmegaSettings_Constants>()->Constant_Text.FindRef(Constant);
	}
	return Value;
}

// ─── DataAsset ────────────────────────────────────────────────────────────────

TArray<FName> FOmegaGlobalConst_DataAsset::L_GetVals() const
{
	TArray<FName> out;
	GetMutableDefault<UOmegaSettings_Constants>()->Constant_DataAsset.GetKeys(out);
	return out;
}

UPrimaryDataAsset* FOmegaGlobalConst_DataAsset::GetValue() const
{
	if (UseConstant)
	{
		return GetMutableDefault<UOmegaSettings_Constants>()->Constant_DataAsset.FindRef(Constant).LoadSynchronous();
	}
	return Value;
}
