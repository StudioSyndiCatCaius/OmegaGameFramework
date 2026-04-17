// Fill out your copyright notice in the Description page of Project Settings.


#include "Functions/F_SoftProperty.h"

#include "OmegaSettings.h"
#include "OmegaGameManager.h"
#include "Functions/F_GlobalParam.h"

//#####################################################################################################
// Soft PROPERTY FUNCTIONS
//#####################################################################################################
FString UOmegaFunctions_SoftProperty::GetSoftProperty_String(UObject* Object, FName PropertyName)
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

bool UOmegaFunctions_SoftProperty::GetSoftProperty_bool(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return LocalVal.ToBool();
}

float UOmegaFunctions_SoftProperty::GetSoftProperty_float(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return FCString::Atof(*LocalVal);
}

int32 UOmegaFunctions_SoftProperty::GetSoftProperty_int32(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	return FCString::Atoi(*LocalVal);
}

FVector UOmegaFunctions_SoftProperty::GetSoftProperty_Vector(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	FVector VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}

FRotator UOmegaFunctions_SoftProperty::GetSoftProperty_Rotator(UObject* Object, FName PropertyName)
{
	const FString LocalVal = GetSoftProperty_String(Object, PropertyName);
	FRotator  VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}
