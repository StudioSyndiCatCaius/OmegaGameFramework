// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_CommandLine.h"

#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

FString UOmegaFunctions_Command::Parse_String(const FString& source, const FString& param, const FString& Fallback,bool& bValid)
{
	TArray<FString> tokens;
	TArray<FString> switches;
	TMap<FString,FString> parameters;
	UKismetSystemLibrary::ParseCommandLine(source,tokens,switches,parameters);
	if (parameters.Contains(param))
	{
		bValid=true;
		return parameters[param];
	}
	bValid=false;
	return Fallback;
}

bool UOmegaFunctions_Command::Parse_Bool(const FString& source, const FString& param, bool Fallback, bool& bValid)
{
	FString result=Parse_String(source,param,"",bValid);
	if (bValid)
	{
		return result=="true";
	}
	return Fallback;
}

int32 UOmegaFunctions_Command::Parse_Int32(const FString& source, const FString& param, int32 Fallback, bool& bValid)
{
	FString result=Parse_String(source,param,"",bValid);
	if (bValid)
	{
		return FCString::Atoi(*result);
	}
	return Fallback;
}

float UOmegaFunctions_Command::Parse_Float(const FString& source, const FString& param, float Fallback, bool& bValid)
{
	FString result=Parse_String(source,param,"",bValid);
	if (bValid)
	{
		return FCString::Atof(*result);
	}
	return Fallback;
}

