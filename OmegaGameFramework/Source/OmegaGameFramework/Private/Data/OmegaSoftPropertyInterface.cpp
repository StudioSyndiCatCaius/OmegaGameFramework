// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/OmegaSoftPropertyInterface.h"

//#####################################################################################################
// PROPERTY FUNCTIONS
//#####################################################################################################
FString UOmegaSoftPropertyFunctions::GetSoftProperty_String(UObject* Object, const FString& PropertyName)
{
	FString OutVal;
	if(Object && Object->GetClass()->ImplementsInterface(UOmegaSoftPropertyInterface::StaticClass()))
	{
		TMap<FString, FString> SoftPropertyMap = IOmegaSoftPropertyInterface::Execute_GetSoftPropertyMap(Object);
        
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

bool UOmegaSoftPropertyFunctions::GetSoftProperty_bool(UObject* Object, const FString& PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return LocalVal.ToBool();
}

float UOmegaSoftPropertyFunctions::GetSoftProperty_float(UObject* Object, const FString& PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return FCString::Atof(*LocalVal);
}

int32 UOmegaSoftPropertyFunctions::GetSoftProperty_int32(UObject* Object, const FString& PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return FCString::Atoi(*LocalVal);
}

FVector UOmegaSoftPropertyFunctions::GetSoftProperty_Vector(UObject* Object, const FString& PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	FVector VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}

FRotator UOmegaSoftPropertyFunctions::GetSoftProperty_Rotator(UObject* Object, const FString& PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	FRotator  VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}
