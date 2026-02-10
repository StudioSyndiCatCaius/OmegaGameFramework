// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_SoftProperty.h"

#include "OmegaSettings.h"
#include "OmegaGameCore.h"
#include "Functions/F_GlobalParam.h"

//#####################################################################################################
// Soft PROPERTY FUNCTIONS
//#####################################################################################################
FString UOmegaSoftPropertyFunctions::GetSoftProperty_String(UObject* Object, FName PropertyName)
{
	FString temp_val=GetMutableDefault<UOmegaSettings>()->GetGameCore()->Object_OverrideSoftProperty(Object, PropertyName);
	if (!temp_val.IsEmpty())
	{
		return temp_val;
	}

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
