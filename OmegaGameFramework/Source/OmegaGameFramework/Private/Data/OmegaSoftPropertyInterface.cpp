// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/OmegaSoftPropertyInterface.h"


// Add default functionality here for any IOmegaSoftPropertyInterface functions that are not pure virtual.
bool IOmegaSoftPropertyInterface::NativeGetSoftProperty_Bool(const FString& Property)
{
	FSoftPropertyCollection LocalProps = Native_GetSoftProperties();
	return LocalProps.SoftProp_bool.FindOrAdd(Property);
}

int32 IOmegaSoftPropertyInterface::NativeGetSoftProperty_Int32(const FString& Property)
{
	FSoftPropertyCollection LocalProps = Native_GetSoftProperties();
	return LocalProps.SoftProp_int.FindOrAdd(Property);
}

float IOmegaSoftPropertyInterface::NativeGetSoftProperty_Float(const FString& Property)
{
	FSoftPropertyCollection LocalProps = Native_GetSoftProperties();
	return LocalProps.SoftProp_float.FindOrAdd(Property);
}

FString IOmegaSoftPropertyInterface::NativeGetSoftProperty_String(const FString& Property)
{
	FSoftPropertyCollection LocalProps = Native_GetSoftProperties();
	return LocalProps.SoftProp_string.FindOrAdd(Property);
}

UObject* IOmegaSoftPropertyInterface::NativeGetSoftProperty_Object(const FString& Property)
{
	FSoftPropertyCollection LocalProps = Native_GetSoftProperties();
	return LocalProps.SoftProp_object.FindOrAdd(Property);
}

FSoftPropertyCollection IOmegaSoftPropertyInterface::Native_GetSoftProperties()
{
	FSoftPropertyCollection EmptyProps = {};
	return EmptyProps;
}

void IOmegaSoftPropertyInterface::Native_SetSoftProperties(FSoftPropertyCollection Properties)
{
	
}
