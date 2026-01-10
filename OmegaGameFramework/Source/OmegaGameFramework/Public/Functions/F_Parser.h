// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/OmegaUtils_Structs.h"
#include "F_Parser.generated.h"

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaParserFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable,Category="Omega|File|Parse")
	static FOmegaParsedTable OmegaParse_CSV(const FString& FileString);

	UFUNCTION(BlueprintCallable,Category="Omega|File|Parse")
	static FOmegaParsedTable OmegaParse_YAML(const FString& FileString);

	UFUNCTION(BlueprintCallable,Category="Omega|File|Parse")
	static FOmegaParsedTable OmegaParse_INI(const FString& FileString);

	UFUNCTION(BlueprintCallable,Category="Omega|File|Parse")
	static FOmegaParsedTable OmegaParse_TOML(const FString& FileString);

	/// property get

	UFUNCTION(BlueprintPure,Category="Omega|File|Parse")
	static FString GetParsedTableValue_String(FOmegaParsedTable Table, FName Key, FName SubKey);
	
	UFUNCTION(BlueprintPure,Category="Omega|File|Parse")
	static float GetParsedTableValue_Float(FOmegaParsedTable Table, FName Key, FName SubKey);
	
	UFUNCTION(BlueprintPure,Category="Omega|File|Parse")
	static int32 GetParsedTableValue_Int32(FOmegaParsedTable Table, FName Key, FName SubKey);
	
	UFUNCTION(BlueprintPure,Category="Omega|File|Parse")
	static bool GetParsedTableValue_Bool(FOmegaParsedTable Table, FName Key, FName SubKey);
	
};
