// Fill out your copyright notice in the Description page of Project Settings.


#include "Save/OmegaSaveBase.h"

void UOmegaSaveBase::Local_OnLoaded()
{
	
}



//bool
void UOmegaSaveBase::SetSaveProperty_Bool(const FString& Name, bool Value)
{
	Prop_bool.Add(FName(Name), Value);
}

bool UOmegaSaveBase::GetSaveProperty_Bool(const FString& Name)
{
	return Prop_bool.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Float(const FString& Name, float Value)
{
	Prop_float.Add(FName(Name), Value);
}

float UOmegaSaveBase::GetSaveProperty_Float(const FString& Name)
{
	return Prop_float.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Int(const FString& Name, int32 Value)
{
	Prop_int.Add(FName(Name), Value);
}

int32 UOmegaSaveBase::GetSaveProperty_Int(const FString& Name)
{
	return Prop_int.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_String(const FString& Name, const FString& Value)
{
	Prop_string.Add(FName(Name), Value);
}

FString UOmegaSaveBase::GetSaveProperty_String(const FString& Name)
{
	return Prop_string.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Tag(const FString& Name, FGameplayTag Value)
{
	Prop_Tag.Add(FName(Name), Value);
}

FGameplayTag UOmegaSaveBase::GetSaveProperty_Tag(const FString& Name)
{
	return Prop_Tag.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Tags(const FString& Name, FGameplayTagContainer Value)
{
	Prop_Tags.Add(FName(Name), Value);
}

FGameplayTagContainer UOmegaSaveBase::GetSaveProperty_Tags(const FString& Name)
{
	return Prop_Tags.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Asset(const FString& Name, UPrimaryDataAsset* Value)
{
	Prop_Asset.Add(FName(Name), Value);
}

UPrimaryDataAsset* UOmegaSaveBase::GetSaveProperty_Asset(const FString& Name)
{
	return Prop_Asset.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Vector(const FString& Name, FVector Value)
{
	Prop_Vector.Add(FName(Name), Value);
}

FVector UOmegaSaveBase::GetSaveProperty_Vector(const FString& Name)
{
	return Prop_Vector.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Rotator(const FString& Name, FRotator Value)
{
	Prop_Rotator.Add(FName(Name), Value);
}

FRotator UOmegaSaveBase::GetSaveProperty_Rotator(const FString& Name)
{
	return Prop_Rotator.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Transform(const FString& Name, FTransform Value)
{
	Prop_Transform.Add(FName(Name), Value);
}

FTransform UOmegaSaveBase::GetSaveProperty_Transform(const FString& Name)
{
	return Prop_Transform.FindOrAdd(FName(Name));
}

void UOmegaSaveBase::SetSaveProperty_Json(const FString& Name, FJsonObjectWrapper Value)
{
	Prop_Json.Add(FName(Name), Value);
}

FJsonObjectWrapper UOmegaSaveBase::GetSaveProperty_Json(const FString& Name)
{
	return Prop_Json.FindOrAdd(FName(Name));

}


