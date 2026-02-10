// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "Functions/F_Lua.h"
#include "OmegaLuaParser_Demo.generated.h"



// ================================================================================
// json
// ================================================================================

UCLASS(DisplayName="Parser - json")
class OMEGADEMO_API UOmegaLuaParser_JSON : public UOmegaLuaParser
{
	GENERATED_BODY()
public:
	virtual FLuaValue ParseStringToTable_Implementation(UObject* WorldContext, const FString& String) override; 
};

// ================================================================================
// CSV
// ================================================================================

UCLASS(DisplayName="Parser - CSV")
class OMEGADEMO_API UOmegaLuaParser_CSV : public UOmegaLuaParser
{
	GENERATED_BODY()
public:
	FString Delimiter=",";
	bool bHasHeader=true;
	TArray<FString> ParseCSVLine(const FString& Line, const FString& LineDelimiter);

	
	virtual FLuaValue ParseStringToTable_Implementation(UObject* WorldContext, const FString& String) override; 
};

// ================================================================================
// TOML
// ================================================================================

UCLASS(DisplayName="Parser - TOML")
class OMEGADEMO_API UOmegaLuaParser_TOML : public UOmegaLuaParser
{
	GENERATED_BODY()
public:
	// Helper functions for TOML parsing
	FLuaValue ParseTOMLValue(const FString& Value);
	void ParseTOMLSection(const FString& SectionName, const TArray<FString>& Lines, int32& LineIndex, FLuaValue& RootTable, TArray<FString>& ArraySections);
	FString GetSectionPath(const FString& SectionName);
	void SetNestedValue(FLuaValue& Table, const TArray<FString>& Path, const FLuaValue& Value);
	FLuaValue GetNestedTable(FLuaValue& Table, const TArray<FString>& Path, bool bCreateIfMissing = true);
	
	virtual FLuaValue ParseStringToTable_Implementation(UObject* WorldContext, const FString& String) override; 
};

// ================================================================================
// Godot .tscene
// ================================================================================

UCLASS(DisplayName="Parser - Godot .TSCN")
class OMEGADEMO_API UOmegaLuaParser_TSCN : public UOmegaLuaParser
{
	GENERATED_BODY()

public:
	virtual FLuaValue ParseStringToTable_Implementation(UObject* WorldContext, const FString& String) override;

private:
	// Parse a section header like [node name="Player" type="CharacterBody2D"]
	void ParseSectionHeader(const FString& Line, FString& OutSectionType, TMap<FString, FString>& OutAttributes);
	
	// Parse a Godot value (Vector2, Color, ExtResource, etc.)
	FLuaValue ParseGodotValue(UObject* WorldContext, const FString& Value);
	
	// Parse Vector2, Vector3, etc.
	FLuaValue ParseVector(UObject* WorldContext, const FString& Value);
	
	// Parse Color
	FLuaValue ParseColor(UObject* WorldContext, const FString& Value);
	
	// Parse array [1, 2, 3]
	FLuaValue ParseArray(UObject* WorldContext, const FString& Value);
	
	// Parse dictionary { "key": "value" }
	FLuaValue ParseDictionary(UObject* WorldContext, const FString& Value);
	
	// Detect and parse primitive types
	FLuaValue ParsePrimitiveValue(UObject* WorldContext, const FString& Value);
};

// ================================================================================
// godot .res
// ================================================================================

UCLASS(DisplayName="Parser - Godot .TRES")
class OMEGADEMO_API UOmegaLuaParser_TRES : public UOmegaLuaParser
{
	GENERATED_BODY()

public:
	virtual FLuaValue ParseStringToTable_Implementation(UObject* WorldContext, const FString& String) override;

private:
	// Parse a section header like [resource]
	void ParseSectionHeader(const FString& Line, FString& OutSectionType, TMap<FString, FString>& OutAttributes);
	
	// Parse a Godot value (same as TSCN)
	FLuaValue ParseGodotValue(UObject* WorldContext, const FString& Value);
	
	// Parse Vector2, Vector3, etc.
	FLuaValue ParseVector(UObject* WorldContext, const FString& Value);
	
	// Parse Color
	FLuaValue ParseColor(UObject* WorldContext, const FString& Value);
	
	// Parse array [1, 2, 3]
	FLuaValue ParseArray(UObject* WorldContext, const FString& Value);
	
	// Parse dictionary { "key": "value" }
	FLuaValue ParseDictionary(UObject* WorldContext, const FString& Value);
	
	// Detect and parse primitive types
	FLuaValue ParsePrimitiveValue(UObject* WorldContext, const FString& Value);
};