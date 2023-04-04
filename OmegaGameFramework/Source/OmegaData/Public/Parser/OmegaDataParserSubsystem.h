// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "OmegaDataParserSubsystem.generated.h"


UCLASS(DisplayName="Omega Engine Subsystem: Data Parser")
class OMEGADATA_API UOmegaDataParserSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="DataParser")
	UOmegaDataParserReader* ParseDataFromString(TSubclassOf<UOmegaDataParserReader> ReaderClass, const FString& String);

	UFUNCTION(BlueprintCallable, Category="DataParser")
	UOmegaDataParserReader* ParseDataFromPath(TSubclassOf<UOmegaDataParserReader> ReaderClass, const FString& Path);
	
};


UCLASS(Blueprintable, BlueprintType)
class OMEGADATA_API UOmegaDataParserReader : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category="DataParset")
	FString LoadedString;

	UFUNCTION(BlueprintImplementableEvent, Category="Parser")
	TMap<FString, FString> ParseStringValues(const FString& Data);

	UFUNCTION(BlueprintNativeEvent, Category="DataParset")
	FString OnGetProperty(const FString& Property);
	
	// Propeties
	UFUNCTION(BlueprintPure, Category="DataParser")
	bool GetParsedDataProperty_Bool(const FString& Property);

	UFUNCTION(BlueprintPure, Category="DataParser")
	float GetParsedDataProperty_Float(const FString& Property);
	
	UFUNCTION(BlueprintPure, Category="DataParser")
	int32 GetParsedDataProperty_Int32(const FString& Property);

	UFUNCTION(BlueprintPure, Category="DataParser")
	FString GetParsedDataProperty_String(const FString& Property);

	UFUNCTION(BlueprintPure, Category="DataParser")
	FText GetParsedDataProperty_Text(const FString& Property);

	UFUNCTION(BlueprintPure, Category="DataParser")
	FVector GetParsedDataProperty_Vector(const FString& Property);
	
	UFUNCTION(BlueprintPure, Category="DataParser")
	FRotator GetParsedDataProperty_Rotator(const FString& Property);
};