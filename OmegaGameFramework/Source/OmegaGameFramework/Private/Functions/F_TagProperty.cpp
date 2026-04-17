// Fill out your copyright notice in the Description page of Project Settings.

#include "Functions/F_TagProperty.h"

bool UOmegaFunctions_TagProperty::ObjectUsesInterface(UObject* Object)
{
	return Object && Object->GetClass()->ImplementsInterface(UDataInterface_TagProperty::StaticClass());
}

FString UOmegaFunctions_TagProperty::Get_String(UObject* Object, FGameplayTag PropertyName, const FString& Fallback)
{
	if (ObjectUsesInterface(Object))
	{
		TMap<FGameplayTag, FString> Map=IDataInterface_TagProperty::Execute_GetTagPropertyMap(Object);
		if (Map.Contains(PropertyName))
		{
			return Map[PropertyName];
		}
		bool b_result;
		FString Result = IDataInterface_TagProperty::Execute_GetTagProperty(Object, PropertyName,b_result);
		if (b_result)
		{
			return Result;
		}
	}
	return Fallback;
}

bool UOmegaFunctions_TagProperty::Get_Bool(UObject* Object, FGameplayTag PropertyName, bool Fallback)
{
	FString Result = Get_String(Object, PropertyName);
	return Result.IsEmpty() ? Fallback : Result.ToBool();
}

float UOmegaFunctions_TagProperty::Get_Float(UObject* Object, FGameplayTag PropertyName, float Fallback)
{
	FString Result = Get_String(Object, PropertyName);
	return Result.IsEmpty() ? Fallback : FCString::Atof(*Result);
}

int32 UOmegaFunctions_TagProperty::Get_Int32(UObject* Object, FGameplayTag PropertyName, int32 Fallback)
{
	FString Result = Get_String(Object, PropertyName);
	return Result.IsEmpty() ? Fallback : FCString::Atoi(*Result);
}

FVector UOmegaFunctions_TagProperty::Get_Vector(UObject* Object, FGameplayTag PropertyName, FVector Fallback)
{
	FString Result = Get_String(Object, PropertyName);
	if (!Result.IsEmpty())
	{
		FVector ParsedVector;
		if (ParsedVector.InitFromString(Result))
		{
			return ParsedVector;
		}
	}
	return Fallback;
}

FRotator UOmegaFunctions_TagProperty::Get_Rotator(UObject* Object, FGameplayTag PropertyName, FRotator Fallback)
{
	FString Result = Get_String(Object, PropertyName);
	if (!Result.IsEmpty())
	{
		FRotator ParsedRotator;
		if (ParsedRotator.InitFromString(Result))
		{
			return ParsedRotator;
		}
	}
	return Fallback;
}

UObject* UOmegaFunctions_TagProperty::Get_Object(UObject* Object, FGameplayTag PropertyName, TSubclassOf<UObject> Class,
	UObject* Fallback)
{
	if (ObjectUsesInterface(Object))
	{
		if (UObject* found_obj=IDataInterface_TagProperty::Execute_GetTagProperty_Object(Object,PropertyName))
		{
			if (!Class || found_obj->GetClass()->IsChildOf(Class))
			{
				return found_obj;
			}
		}
	}
	return Fallback;
}
