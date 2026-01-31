// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Config.h"
#include "JsonBlueprintFunctionLibrary.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "JsonObjectConverter.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Macros.h"

FJsonObject UOmegaFunctions_Config::GetOmegaConfigJsonObject()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	const FString FilePath = FPaths::ProjectDir() + TEXT("OmegaConfig.json");
	FString FileContent;
	if (!FFileHelper::LoadFileToString(FileContent, *FilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *FilePath);
	}


	const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(FileContent);
    
	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse JSON file: %s"), *FilePath);
	}

	return *JsonObject;
}

FJsonObjectWrapper UOmegaFunctions_Config::GetOmegaConfigJson()
{

	FJsonObjectWrapper JsonObjectWrapper;

	//TSharedPtr<FJsonObject> JsonObjectCopy = MakeShareable(GetOmegaConfigJsonObject());

	// Use the function from JsonUtilities to populate the wrapper
	//FJsonObjectConverter::JsonObjectToUStruct(JsonObjectCopy.ToSharedRef(), &JsonObjectWrapper, 0, 0);

	return JsonObjectWrapper;
}

bool UOmegaFunctions_Config::GetCustom_Bool(const FName Param)
{
	return OGF_CFG()->CustomParams_Bool.FindOrAdd(Param);
}

float UOmegaFunctions_Config::GetCustom_float(const FName Param)
{
	return OGF_CFG()->CustomParams_Float.FindOrAdd(Param);
}

int32 UOmegaFunctions_Config::GetCustom_Int32(const FName Param)
{
	return OGF_CFG()->CustomParams_Int32.FindOrAdd(Param);
}

FString UOmegaFunctions_Config::GetCustom_String(const FName Param)
{
	return OGF_CFG()->CustomParams_String.FindOrAdd(Param);
}



FString UOmegaFunctions_Config::GetOmegaConfigProperty_String(const FString Property)
{
	FString FieldValue;
	if (GetOmegaConfigJsonObject().TryGetStringField(Property, FieldValue))
	{
		return FieldValue;
	}

	return FString();
}

bool UOmegaFunctions_Config::GetOmegaConfigProperty_Bool(const FString Property)
{
	const FString FieldValue = GetOmegaConfigProperty_String(Property);
	if (!FieldValue.IsEmpty())
	{
		return (FieldValue == TEXT("true") || FieldValue == TEXT("1"));
	}

	return false;
}

int32 UOmegaFunctions_Config::GetOmegaConfigProperty_Int(const FString Property)
{
	const FString FieldValue = GetOmegaConfigProperty_String(Property);
	if (!FieldValue.IsEmpty())
	{
		return FCString::Atoi(*FieldValue);
	}

	return 0;
}
