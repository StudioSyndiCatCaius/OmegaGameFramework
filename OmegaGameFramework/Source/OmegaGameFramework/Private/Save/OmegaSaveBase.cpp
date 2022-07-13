// Fill out your copyright notice in the Description page of Project Settings.


#include "Save/OmegaSaveBase.h"

//bool
void UOmegaSaveBase::SetSaveProperty_Bool(FName Name, bool Value)
{
	Prop_bool.Add(Name, Value);
}

bool UOmegaSaveBase::GetSaveProperty_Bool(FName Name)
{
	return Prop_bool.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Float(FName Name, float Value)
{
	Prop_float.Add(Name, Value);
}

float UOmegaSaveBase::GetSaveProperty_Float(FName Name)
{
	return Prop_float.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Int(FName Name, int32 Value)
{
	Prop_int.Add(Name, Value);
}

int32 UOmegaSaveBase::GetSaveProperty_Int(FName Name)
{
	return Prop_int.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_String(FName Name, const FString& Value)
{
	Prop_string.Add(Name, Value);
}

FString UOmegaSaveBase::GetSaveProperty_String(FName Name)
{
	return Prop_string.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Tag(FName Name, FGameplayTag Value)
{
	Prop_Tag.Add(Name, Value);
}

FGameplayTag UOmegaSaveBase::GetSaveProperty_Tag(FName Name)
{
	return Prop_Tag.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Asset(FName Name, UPrimaryDataAsset* Value)
{
	Prop_Asset.Add(Name, Value);
}

UPrimaryDataAsset* UOmegaSaveBase::GetSaveProperty_Asset(FName Name)
{
	return Prop_Asset.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Vector(FName Name, FVector Value)
{
	Prop_Vector.Add(Name, Value);
}

FVector UOmegaSaveBase::GetSaveProperty_Vector(FName Name)
{
	return Prop_Vector.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Rotator(FName Name, FRotator Value)
{
	Prop_Rotator.Add(Name, Value);
}

FRotator UOmegaSaveBase::GetSaveProperty_Rotator(FName Name)
{
	return Prop_Rotator.FindOrAdd(Name);
}

void UOmegaSaveBase::SetSaveProperty_Transform(FName Name, FTransform Value)
{
	Prop_Transform.Add(Name, Value);
}

FTransform UOmegaSaveBase::GetSaveProperty_Transform(FName Name)
{
	return Prop_Transform.FindOrAdd(Name);
}
