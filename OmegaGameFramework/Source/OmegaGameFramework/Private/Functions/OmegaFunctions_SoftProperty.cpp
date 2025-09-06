// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/OmegaFunctions_SoftProperty.h"

//#####################################################################################################
// Soft PROPERTY FUNCTIONS
//#####################################################################################################
FString UOmegaSoftPropertyFunctions::GetSoftProperty_String(UObject* Object, FName PropertyName)
{
	FString OutVal;
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaSoftPropertyInterface::StaticClass()))
	{
		TMap<FName, FString> SoftPropertyMap = IOmegaSoftPropertyInterface::Execute_GetSoftPropertyMap(Object);
        
		if(SoftPropertyMap.Contains(PropertyName))
		{
			OutVal = SoftPropertyMap.FindOrAdd(PropertyName);
		}
		else
		{
			OutVal = IOmegaSoftPropertyInterface::Execute_GetSoftProperty(Object, PropertyName);
		}
	}

	return OutVal;
}

bool UOmegaSoftPropertyFunctions::GetSoftProperty_bool(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return LocalVal.ToBool();
}

float UOmegaSoftPropertyFunctions::GetSoftProperty_float(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return FCString::Atof(*LocalVal);
}

int32 UOmegaSoftPropertyFunctions::GetSoftProperty_int32(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return FCString::Atoi(*LocalVal);
}

FVector UOmegaSoftPropertyFunctions::GetSoftProperty_Vector(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	FVector VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}

FRotator UOmegaSoftPropertyFunctions::GetSoftProperty_Rotator(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	FRotator  VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}

//#####################################################################################################
// Tag PROPERTY FUNCTIONS
//#####################################################################################################
FString UOmegaTagPropertyFunctions::GetTagProperty_String(UObject* Object,FGameplayTag PropertyName)
{
	FString OutVal;
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaTagPropertyInterface::StaticClass()))
	{
		TMap<FGameplayTag, FString> SoftPropertyMap = IOmegaTagPropertyInterface::Execute_GetTagPropertyMap(Object);
        
		if(SoftPropertyMap.Contains(PropertyName))
		{
			OutVal = SoftPropertyMap.FindOrAdd(PropertyName);
		}
		else
		{
			OutVal = IOmegaTagPropertyInterface::Execute_GetTagProperty(Object, PropertyName);
		}
	}

	return OutVal;
}

bool UOmegaTagPropertyFunctions::GetTagProperty_bool(UObject* Object,FGameplayTag PropertyName)
{
	const FString LocalVal = GetTagProperty_String(Object, PropertyName);
	return LocalVal.ToBool();
}

float UOmegaTagPropertyFunctions::GetTagProperty_float(UObject* Object, FGameplayTag PropertyName)
{
	const FString LocalVal = GetTagProperty_String(Object, PropertyName);
	return FCString::Atof(*LocalVal);
}

int32 UOmegaTagPropertyFunctions::GetTagProperty_int32(UObject* Object, FGameplayTag PropertyName)
{
	const FString LocalVal = GetTagProperty_String(Object, PropertyName);
	return FCString::Atoi(*LocalVal);
}

FVector UOmegaTagPropertyFunctions::GetTagProperty_Vector(UObject* Object, FGameplayTag PropertyName)
{
	const FString LocalVal = GetTagProperty_String(Object, PropertyName);
	FVector VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}

FRotator UOmegaTagPropertyFunctions::GetTagProperty_Rotator(UObject* Object, FGameplayTag PropertyName)
{
	const FString LocalVal = GetTagProperty_String(Object, PropertyName);
	FRotator  VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}
