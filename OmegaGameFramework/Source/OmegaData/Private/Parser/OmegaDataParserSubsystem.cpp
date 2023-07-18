// Fill out your copyright notice in the Description page of Project Settings.


#include "Parser/OmegaDataParserSubsystem.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

FString UOmegaDataParserReader::GetParsedDataProperty_String(const FString& Property)
{
	/*
	TMap<FString, FString> ParsedVals = ParseStringValues(LoadedString);
	if(ParsedVals.Contains(Property))
	{
		return  ParsedVals[Property];
	}
	*/
	return OnGetProperty(Property);
}

FString UOmegaDataParserReader::OnGetProperty_Implementation(const FString& Property)
{
	return "";
}

bool UOmegaDataParserReader::GetParsedDataProperty_Bool(const FString& Property)
{
	const FString LocalVal = GetParsedDataProperty_String(Property);
	return LocalVal.ToBool();
}

float UOmegaDataParserReader::GetParsedDataProperty_Float(const FString& Property)
{
	const FString LocalVal = GetParsedDataProperty_String(Property);
	return FCString::Atof(*LocalVal);
}

int32 UOmegaDataParserReader::GetParsedDataProperty_Int32(const FString& Property)
{
	const FString LocalVal = GetParsedDataProperty_String(Property);
	return FCString::Atoi(*LocalVal);
}

FText UOmegaDataParserReader::GetParsedDataProperty_Text(const FString& Property)
{
	const FString LocalVal = GetParsedDataProperty_String(Property);
	return FText::FromString(LocalVal);
}

FVector UOmegaDataParserReader::GetParsedDataProperty_Vector(const FString& Property)
{
	const FString LocalVal = GetParsedDataProperty_String(Property);
	FVector VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}

FRotator UOmegaDataParserReader::GetParsedDataProperty_Rotator(const FString& Property)
{
	const FString LocalVal = GetParsedDataProperty_String(Property);
	FRotator  VectorValue;
	VectorValue.InitFromString(LocalVal);
	return VectorValue;
}


UOmegaDataParserReader* UOmegaDataParserSubsystem::ParseDataFromString(TSubclassOf<UOmegaDataParserReader> ReaderClass,
	const FString& String)
{
	TSubclassOf<UOmegaDataParserReader> LocalClass = UOmegaDataParserReader::StaticClass();
	if(ReaderClass)
	{
		LocalClass = ReaderClass;
	}
	UOmegaDataParserReader* LocalReader = NewObject<UOmegaDataParserReader>(this, LocalClass);
	LocalReader->LoadedString = String;
	return LocalReader;
}

UOmegaDataParserReader* UOmegaDataParserSubsystem::ParseDataFromPath(TSubclassOf<UOmegaDataParserReader> ReaderClass,
                                                                     const FString& Path)
{
	FString FileContent;

	if (FPaths::FileExists(Path))
	{
		if (!FFileHelper::LoadFileToString(FileContent, *Path))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to read the file: %s"), *Path);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("File not found: %s"), *Path);
	}
	
	return ParseDataFromString(ReaderClass, FileContent);
}
