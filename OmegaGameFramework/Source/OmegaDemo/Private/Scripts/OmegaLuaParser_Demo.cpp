// Fill out your copyright notice in the Description page of Project Settings.


#include "Scripts/OmegaLuaParser_Demo.h"

#include "JsonBlueprintFunctionLibrary.h"
#include "LuaBlueprintFunctionLibrary.h"

// ========================================================================================================================================
// CSV
// ========================================================================================================================================

FLuaValue UOmegaLuaParser_CSV::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	FLuaValue ResultTable = CreateLuaTable();
	
	// Split into lines
	TArray<FString> Lines;
	String.ParseIntoArrayLines(Lines);
	
	if (Lines.Num() == 0)
	{
		return ResultTable;
	}
	
	TArray<FString> Headers;
	int32 StartRow = 0;
	
	if (bHasHeader && Lines.Num() > 0)
	{
		// Parse header row
		Headers = ParseCSVLine(Lines[0], Delimiter);
		StartRow = 1;
	}
	
	// Parse data rows
	int32 LuaIndex = 1; // Lua arrays start at 1
	for (int32 i = StartRow; i < Lines.Num(); i++)
	{
		FString Line = Lines[i].TrimStartAndEnd();
		
		// Skip empty lines
		if (Line.IsEmpty())
		{
			continue;
		}
		
		TArray<FString> Fields = ParseCSVLine(Line, Delimiter);
		FLuaValue RowTable = CreateLuaTable();
		
		if (bHasHeader && Headers.Num() > 0)
		{
			// Use headers as keys
			for (int32 j = 0; j < Fields.Num(); j++)
			{
				FString Key = (j < Headers.Num()) ? Headers[j] : FString::Printf(TEXT("column_%d"), j + 1);
				RowTable.SetField(Key, FLuaValue(Fields[j]));
			}
		}
		else
		{
			// Use numeric indices
			for (int32 j = 0; j < Fields.Num(); j++)
			{
				RowTable.SetFieldByIndex(j + 1, FLuaValue(Fields[j]));
			}
		}
		
		ResultTable.SetFieldByIndex(LuaIndex++, RowTable);
	}
	
	return ResultTable;
}


FLuaValue UOmegaLuaParser_JSON::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	FLuaValue out;
	ULuaBlueprintFunctionLibrary::LuaValueFromJson(WorldContext,nullptr,String,out);
	return out;
}

TArray<FString> UOmegaLuaParser_CSV::ParseCSVLine(const FString& Line, const FString& LineDelimiter)
{
	TArray<FString> Fields;
	FString CurrentField;
	bool bInQuotes = false;
	
	for (int32 i = 0; i < Line.Len(); i++)
	{
		TCHAR Char = Line[i];
		
		if (Char == '"')
		{
			// Handle quotes - toggle quote state
			if (i + 1 < Line.Len() && Line[i + 1] == '"')
			{
				// Escaped quote (two quotes in a row = one quote)
				CurrentField.AppendChar('"');
				i++; // Skip next quote
			}
			else
			{
				bInQuotes = !bInQuotes;
			}
		}
		else if (!bInQuotes && Line.Mid(i, LineDelimiter.Len()) == LineDelimiter)
		{
			// Found delimiter outside quotes
			Fields.Add(TrimQuotes(CurrentField.TrimStartAndEnd()));
			CurrentField.Empty();
			i += LineDelimiter.Len() - 1; // Skip delimiter characters
		}
		else
		{
			CurrentField.AppendChar(Char);
		}
	}
	
	// Add the last field
	Fields.Add(TrimQuotes(CurrentField.TrimStartAndEnd()));
	
	return Fields;
}

\

// ========================================================================================================================================
// TOML
// ========================================================================================================================================

FLuaValue UOmegaLuaParser_TOML::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	FLuaValue RootTable = CreateLuaTable();
	
	// Split into lines
	TArray<FString> Lines;
	String.ParseIntoArrayLines(Lines);
	
	if (Lines.Num() == 0)
	{
		return RootTable;
	}
	
	TArray<FString> ArraySections;
	FLuaValue CurrentTable = RootTable;
	
	// Parse root-level key-value pairs (before first section)
	int32 LineIndex = 0;
	for (; LineIndex < Lines.Num(); LineIndex++)
	{
		FString Line = Lines[LineIndex].TrimStartAndEnd();
		
		// Skip empty lines and comments
		if (Line.IsEmpty() || Line.StartsWith("#"))
		{
			continue;
		}
		
		// Stop at first section
		if (Line.StartsWith("["))
		{
			break;
		}
		
		// Parse key-value pair
		int32 EqualsIndex;
		if (Line.FindChar('=', EqualsIndex))
		{
			FString Key = Line.Left(EqualsIndex).TrimStartAndEnd();
			FString Value = Line.Mid(EqualsIndex + 1).TrimStartAndEnd();
			RootTable.SetField(Key, ParseTOMLValue(Value));
		}
	}
	
	// Parse sections
	for (; LineIndex < Lines.Num(); LineIndex++)
	{
		FString Line = Lines[LineIndex].TrimStartAndEnd();
		
		// Skip empty lines and comments
		if (Line.IsEmpty() || Line.StartsWith("#"))
		{
			continue;
		}
		
		// Parse section header
		if (Line.StartsWith("["))
		{
			int32 SectionEndIndex = Line.Find("]", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
			if (SectionEndIndex != INDEX_NONE)
			{
				FString SectionName = Line.Left(SectionEndIndex + 1);
				LineIndex++; // Move to next line for parsing section content
				ParseTOMLSection(SectionName, Lines, LineIndex, RootTable, ArraySections);
				LineIndex--; // Adjust because loop will increment
			}
		}
	}
	
	return RootTable;

}


FLuaValue UOmegaLuaParser_TOML::ParseTOMLValue(const FString& Value)
{
	FString TrimmedValue = Value.TrimStartAndEnd();
	
	// Check for boolean
	if (TrimmedValue.Equals(TEXT("true"), ESearchCase::IgnoreCase))
	{
		return FLuaValue(true);
	}
	if (TrimmedValue.Equals(TEXT("false"), ESearchCase::IgnoreCase))
	{
		return FLuaValue(false);
	}
	
	// Check for string (quoted)
	if ((TrimmedValue.StartsWith("\"") && TrimmedValue.EndsWith("\"")) ||
		(TrimmedValue.StartsWith("'") && TrimmedValue.EndsWith("'")))
	{
		return FLuaValue(TrimmedValue.Mid(1, TrimmedValue.Len() - 2));
	}
	
	// Check for array
	if (TrimmedValue.StartsWith("[") && TrimmedValue.EndsWith("]"))
	{
		FLuaValue ArrayTable = CreateLuaTable();
		FString ArrayContent = TrimmedValue.Mid(1, TrimmedValue.Len() - 2);
		
		TArray<FString> Elements;
		ArrayContent.ParseIntoArray(Elements, TEXT(","), true);
		
		for (int32 i = 0; i < Elements.Num(); i++)
		{
			ArrayTable.SetFieldByIndex(i + 1, ParseTOMLValue(Elements[i]));
		}
		
		return ArrayTable;
	}
	
	// Check for number (integer or float)
	if (TrimmedValue.IsNumeric() || TrimmedValue.Contains("."))
	{
		if (TrimmedValue.Contains("."))
		{
			// Float
			return FLuaValue(FCString::Atof(*TrimmedValue));
		}
		else
		{
			// Integer
			return FLuaValue(FCString::Atoi(*TrimmedValue));
		}
	}
	
	// Default to string
	return FLuaValue(TrimmedValue);
}

void UOmegaLuaParser_TOML::SetNestedValue(FLuaValue& Table, const TArray<FString>& Path, const FLuaValue& Value)
{
	if (Path.Num() == 0)
	{
		return;
	}
	
	if (Path.Num() == 1)
	{
		Table.SetField(Path[0], Value);
		return;
	}
	
	// Navigate to the parent table
	FLuaValue CurrentTable = Table;
	for (int32 i = 0; i < Path.Num() - 1; i++)
	{
		FLuaValue NextTable = CurrentTable.GetField(Path[i]);
		if (NextTable.Type != ELuaValueType::Table)
		{
			// Create intermediate table if it doesn't exist
			NextTable = CreateLuaTable();
			CurrentTable.SetField(Path[i], NextTable);
		}
		CurrentTable = NextTable;
	}
	
	// Set the final value
	CurrentTable.SetField(Path.Last(), Value);
}

FLuaValue UOmegaLuaParser_TOML::GetNestedTable(FLuaValue& Table, const TArray<FString>& Path, bool bCreateIfMissing)
{
	FLuaValue CurrentTable = Table;
	
	for (const FString& PathPart : Path)
	{
		FLuaValue NextTable = CurrentTable.GetField(PathPart);
		
		if (NextTable.Type != ELuaValueType::Table)
		{
			if (bCreateIfMissing)
			{
				NextTable = CreateLuaTable();
				CurrentTable.SetField(PathPart, NextTable);
			}
			else
			{
				return FLuaValue(); // Return nil
			}
		}
		
		CurrentTable = NextTable;
	}
	
	return CurrentTable;
}

FString UOmegaLuaParser_TOML::GetSectionPath(const FString& SectionName)
{
	// Remove brackets and get the section path
	FString Path = SectionName;
	Path.RemoveFromStart("[");
	Path.RemoveFromEnd("]");
	return Path.TrimStartAndEnd();
}

void UOmegaLuaParser_TOML::ParseTOMLSection(const FString& SectionName, const TArray<FString>& Lines, int32& LineIndex, FLuaValue& RootTable, TArray<FString>& ArraySections)
{
	FString SectionPath = GetSectionPath(SectionName);
	
	// Check if this is an array of tables (denoted by [[section]])
	bool bIsArraySection = SectionName.StartsWith("[[") && SectionName.EndsWith("]]");
	
	TArray<FString> PathParts;
	SectionPath.ParseIntoArray(PathParts, TEXT("."), true);
	
	FLuaValue CurrentTable;
	
	if (bIsArraySection)
	{
		// Get or create the array for this section
		FLuaValue ParentTable = RootTable;
		if (PathParts.Num() > 1)
		{
			TArray<FString> ParentPath = PathParts;
			ParentPath.RemoveAt(ParentPath.Num() - 1);
			ParentTable = GetNestedTable(RootTable, ParentPath, true);
		}
		
		FString ArrayName = PathParts.Last();
		FLuaValue ArrayTable = ParentTable.GetField(ArrayName);
		
		if (ArrayTable.Type != ELuaValueType::Table)
		{
			ArrayTable = CreateLuaTable();
			ParentTable.SetField(ArrayName, ArrayTable);
		}
		
		// Get the current array index
		int32 ArrayIndex = ULuaBlueprintFunctionLibrary::LuaTableGetKeys(ArrayTable).Num() + 1;
		
		// Create a new table for this array element
		CurrentTable = CreateLuaTable();
		ArrayTable.SetFieldByIndex(ArrayIndex, CurrentTable);
	}
	else
	{
		// Regular section - create or get the table
		CurrentTable = GetNestedTable(RootTable, PathParts, true);
	}
	
	// Parse key-value pairs until we hit another section or end of file
	for (; LineIndex < Lines.Num(); LineIndex++)
	{
		FString Line = Lines[LineIndex].TrimStartAndEnd();
		
		// Skip empty lines and comments
		if (Line.IsEmpty() || Line.StartsWith("#"))
		{
			continue;
		}
		
		// Check if we've hit another section
		if (Line.StartsWith("["))
		{
			break;
		}
		
		// Parse key-value pair
		int32 EqualsIndex;
		if (Line.FindChar('=', EqualsIndex))
		{
			FString Key = Line.Left(EqualsIndex).TrimStartAndEnd();
			FString Value = Line.Mid(EqualsIndex + 1).TrimStartAndEnd();
			
			// Handle inline tables (e.g., key = { x = 1, y = 2 })
			if (Value.StartsWith("{") && Value.EndsWith("}"))
			{
				FLuaValue InlineTable = CreateLuaTable();
				FString TableContent = Value.Mid(1, Value.Len() - 2);
				
				TArray<FString> Pairs;
				TableContent.ParseIntoArray(Pairs, TEXT(","), true);
				
				for (const FString& Pair : Pairs)
				{
					int32 PairEqualsIndex;
					if (Pair.FindChar('=', PairEqualsIndex))
					{
						FString PairKey = Pair.Left(PairEqualsIndex).TrimStartAndEnd();
						FString PairValue = Pair.Mid(PairEqualsIndex + 1).TrimStartAndEnd();
						InlineTable.SetField(PairKey, ParseTOMLValue(PairValue));
					}
				}
				
				CurrentTable.SetField(Key, InlineTable);
			}
			else
			{
				CurrentTable.SetField(Key, ParseTOMLValue(Value));
			}
		}
	}
}


// ============================================================================
// TSCN PARSER IMPLEMENTATION
// ============================================================================

FLuaValue UOmegaLuaParser_TSCN::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	FLuaValue RootTable = CreateLuaTable();
	
	// Split into lines
	TArray<FString> Lines;
	String.ParseIntoArrayLines(Lines);
	
	if (Lines.Num() == 0)
	{
		return RootTable;
	}
	
	// Create storage for different section types
	FLuaValue ExtResourcesTable = CreateLuaTable();
	FLuaValue SubResourcesTable = CreateLuaTable();
	FLuaValue NodesTable = CreateLuaTable();
	
	int32 ExtResourceIndex = 1;
	int32 SubResourceIndex = 1;
	int32 NodeIndex = 1;
	
	FString CurrentSectionType;
	FLuaValue CurrentTable;
	
	for (int32 i = 0; i < Lines.Num(); i++)
	{
		FString Line = Lines[i].TrimStartAndEnd();
		
		// Skip empty lines and comments
		if (Line.IsEmpty() || Line.StartsWith(";"))
		{
			continue;
		}
		
		// Check if this is a section header
		if (Line.StartsWith("[") && Line.EndsWith("]"))
		{
			TMap<FString, FString> Attributes;
			ParseSectionHeader(Line, CurrentSectionType, Attributes);
			
			// Create new table for this section
			CurrentTable = CreateLuaTable();
			
			// Add attributes to table
			for (const auto& Attr : Attributes)
			{
				CurrentTable.SetField(Attr.Key, FLuaValue(Attr.Value));
			}
			
			// Store based on section type
			if (CurrentSectionType == "gd_scene")
			{
				RootTable.SetField("scene", CurrentTable);
			}
			else if (CurrentSectionType == "ext_resource")
			{
				ExtResourcesTable.SetFieldByIndex(ExtResourceIndex++, CurrentTable);
			}
			else if (CurrentSectionType == "sub_resource")
			{
				SubResourcesTable.SetFieldByIndex(SubResourceIndex++, CurrentTable);
			}
			else if (CurrentSectionType == "node")
			{
				NodesTable.SetFieldByIndex(NodeIndex++, CurrentTable);
			}
			else if (CurrentSectionType == "connection")
			{
				if (RootTable.GetField("connections").IsNil())
				{
					RootTable.SetField("connections", CreateLuaTable());
				}
				FLuaValue ConnectionsTable = RootTable.GetField("connections");
				int32 ConnectionIndex = ULuaBlueprintFunctionLibrary::LuaTableGetKeys(ConnectionsTable).Num() + 1;
				ConnectionsTable.SetFieldByIndex(ConnectionIndex, CurrentTable);
			}
		}
		else if (Line.Contains("=") && !CurrentTable.IsNil())
		{
			// Parse key=value pair
			int32 EqualsIndex;
			if (Line.FindChar('=', EqualsIndex))
			{
				FString Key = Line.Left(EqualsIndex).TrimStartAndEnd();
				FString Value = Line.Mid(EqualsIndex + 1).TrimStartAndEnd();
				
				CurrentTable.SetField(Key, ParseGodotValue(WorldContext, Value));
			}
		}
	}
	
	// Add arrays to root table if they have items
	if (ULuaBlueprintFunctionLibrary::LuaTableGetKeys(ExtResourcesTable).Num() > 0)
	{
		RootTable.SetField("ext_resources", ExtResourcesTable);
	}
	if (ULuaBlueprintFunctionLibrary::LuaTableGetKeys(SubResourcesTable).Num() > 0)
	{
		RootTable.SetField("sub_resources", SubResourcesTable);
	}
	if (ULuaBlueprintFunctionLibrary::LuaTableGetKeys(NodesTable).Num() > 0)
	{
		RootTable.SetField("nodes", NodesTable);
	}
	
	return RootTable;
}

void UOmegaLuaParser_TSCN::ParseSectionHeader(const FString& Line, FString& OutSectionType, TMap<FString, FString>& OutAttributes)
{
	OutAttributes.Empty();
	
	// Remove brackets
	FString Content = Line.Mid(1, Line.Len() - 2).TrimStartAndEnd();
	
	// First word is the section type
	int32 SpaceIndex;
	if (Content.FindChar(' ', SpaceIndex))
	{
		OutSectionType = Content.Left(SpaceIndex);
		FString AttributesStr = Content.Mid(SpaceIndex + 1).TrimStartAndEnd();
		
		// Parse attributes (key="value" or key=value)
		TArray<FString> Parts;
		int32 CurrentPos = 0;
		FString CurrentKey;
		FString CurrentValue;
		bool InQuotes = false;
		bool ReadingValue = false;
		
		for (int32 i = 0; i < AttributesStr.Len(); i++)
		{
			TCHAR Char = AttributesStr[i];
			
			if (Char == '"')
			{
				InQuotes = !InQuotes;
			}
			else if (Char == '=' && !InQuotes)
			{
				CurrentKey = AttributesStr.Mid(CurrentPos, i - CurrentPos).TrimStartAndEnd();
				CurrentPos = i + 1;
				ReadingValue = true;
			}
			else if (Char == ' ' && !InQuotes && ReadingValue)
			{
				CurrentValue = AttributesStr.Mid(CurrentPos, i - CurrentPos).TrimStartAndEnd();
				CurrentValue = CurrentValue.TrimQuotes();
				OutAttributes.Add(CurrentKey, CurrentValue);
				CurrentPos = i + 1;
				ReadingValue = false;
			}
		}
		
		// Add the last attribute
		if (ReadingValue && CurrentPos < AttributesStr.Len())
		{
			CurrentValue = AttributesStr.Mid(CurrentPos).TrimStartAndEnd();
			CurrentValue = CurrentValue.TrimQuotes();
			OutAttributes.Add(CurrentKey, CurrentValue);
		}
	}
	else
	{
		OutSectionType = Content;
	}
}

FLuaValue UOmegaLuaParser_TSCN::ParseGodotValue(UObject* WorldContext, const FString& Value)
{
	FString TrimmedValue = Value.TrimStartAndEnd();
	
	// Check for function calls like Vector2(x, y), Color(r, g, b, a), etc.
	if (TrimmedValue.Contains("(") && TrimmedValue.EndsWith(")"))
	{
		int32 ParenIndex;
		TrimmedValue.FindChar('(', ParenIndex);
		FString FunctionName = TrimmedValue.Left(ParenIndex);
		
		if (FunctionName == "Vector2" || FunctionName == "Vector3" || FunctionName == "Vector4")
		{
			return ParseVector(WorldContext, TrimmedValue);
		}
		else if (FunctionName == "Color")
		{
			return ParseColor(WorldContext, TrimmedValue);
		}
		// Keep function references as strings
		return FLuaValue(TrimmedValue);
	}
	
	// Check for arrays
	if (TrimmedValue.StartsWith("[") && TrimmedValue.EndsWith("]"))
	{
		return ParseArray(WorldContext, TrimmedValue);
	}
	
	// Check for dictionaries
	if (TrimmedValue.StartsWith("{") && TrimmedValue.EndsWith("}"))
	{
		return ParseDictionary(WorldContext, TrimmedValue);
	}
	
	// Parse primitive values
	return ParsePrimitiveValue(WorldContext, TrimmedValue);
}

FLuaValue UOmegaLuaParser_TSCN::ParseVector(UObject* WorldContext, const FString& Value)
{
	FLuaValue VectorTable = CreateLuaTable();
	
	// Extract content between parentheses
	int32 StartIndex = Value.Find("(") + 1;
	int32 EndIndex = Value.Find(")", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	FString Content = Value.Mid(StartIndex, EndIndex - StartIndex);
	
	// Split by comma
	TArray<FString> Components;
	Content.ParseIntoArray(Components, TEXT(","), true);
	
	// Add as x, y, z, w
	TArray<FString> ComponentNames = {"x", "y", "z", "w"};
	for (int32 i = 0; i < Components.Num() && i < ComponentNames.Num(); i++)
	{
		float ComponentValue = FCString::Atof(*Components[i].TrimStartAndEnd());
		VectorTable.SetField(ComponentNames[i], FLuaValue(ComponentValue));
	}
	
	return VectorTable;
}

FLuaValue UOmegaLuaParser_TSCN::ParseColor(UObject* WorldContext, const FString& Value)
{
	FLuaValue ColorTable = CreateLuaTable();
	
	// Extract content between parentheses
	int32 StartIndex = Value.Find("(") + 1;
	int32 EndIndex = Value.Find(")", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	FString Content = Value.Mid(StartIndex, EndIndex - StartIndex);
	
	// Split by comma
	TArray<FString> Components;
	Content.ParseIntoArray(Components, TEXT(","), true);
	
	// Add as r, g, b, a
	TArray<FString> ComponentNames = {"r", "g", "b", "a"};
	for (int32 i = 0; i < Components.Num() && i < ComponentNames.Num(); i++)
	{
		float ComponentValue = FCString::Atof(*Components[i].TrimStartAndEnd());
		ColorTable.SetField(ComponentNames[i], FLuaValue(ComponentValue));
	}
	
	return ColorTable;
}

FLuaValue UOmegaLuaParser_TSCN::ParseArray(UObject* WorldContext, const FString& Value)
{
	FLuaValue ArrayTable = CreateLuaTable();
	
	// Extract content between brackets
	FString Content = Value.Mid(1, Value.Len() - 2).TrimStartAndEnd();
	
	if (Content.IsEmpty())
	{
		return ArrayTable;
	}
	
	// Split by comma (respecting nested structures)
	TArray<FString> Elements;
	int32 Depth = 0;
	int32 StartIndex = 0;
	bool InQuotes = false;
	
	for (int32 i = 0; i < Content.Len(); i++)
	{
		TCHAR Char = Content[i];
		
		if (Char == '"' && (i == 0 || Content[i-1] != '\\'))
		{
			InQuotes = !InQuotes;
		}
		else if (!InQuotes)
		{
			if (Char == '[' || Char == '{' || Char == '(')
			{
				Depth++;
			}
			else if (Char == ']' || Char == '}' || Char == ')')
			{
				Depth--;
			}
			else if (Char == ',' && Depth == 0)
			{
				Elements.Add(Content.Mid(StartIndex, i - StartIndex));
				StartIndex = i + 1;
			}
		}
	}
	
	// Add last element
	if (StartIndex < Content.Len())
	{
		Elements.Add(Content.Mid(StartIndex));
	}
	
	// Parse each element
	for (int32 i = 0; i < Elements.Num(); i++)
	{
		ArrayTable.SetFieldByIndex(i + 1, ParseGodotValue(WorldContext, Elements[i]));
	}
	
	return ArrayTable;
}

FLuaValue UOmegaLuaParser_TSCN::ParseDictionary(UObject* WorldContext, const FString& Value)
{
	FLuaValue DictTable = CreateLuaTable();
	
	// Extract content between braces
	FString Content = Value.Mid(1, Value.Len() - 2).TrimStartAndEnd();
	
	if (Content.IsEmpty())
	{
		return DictTable;
	}
	
	// Split by comma (respecting nested structures)
	TArray<FString> Pairs;
	int32 Depth = 0;
	int32 StartIndex = 0;
	bool InQuotes = false;
	
	for (int32 i = 0; i < Content.Len(); i++)
	{
		TCHAR Char = Content[i];
		
		if (Char == '"' && (i == 0 || Content[i-1] != '\\'))
		{
			InQuotes = !InQuotes;
		}
		else if (!InQuotes)
		{
			if (Char == '[' || Char == '{' || Char == '(')
			{
				Depth++;
			}
			else if (Char == ']' || Char == '}' || Char == ')')
			{
				Depth--;
			}
			else if (Char == ',' && Depth == 0)
			{
				Pairs.Add(Content.Mid(StartIndex, i - StartIndex));
				StartIndex = i + 1;
			}
		}
	}
	
	// Add last pair
	if (StartIndex < Content.Len())
	{
		Pairs.Add(Content.Mid(StartIndex));
	}
	
	// Parse each key:value pair
	for (const FString& Pair : Pairs)
	{
		int32 ColonIndex;
		if (Pair.FindChar(':', ColonIndex))
		{
			FString Key = Pair.Left(ColonIndex).TrimStartAndEnd().TrimQuotes();
			FString PairValue = Pair.Mid(ColonIndex + 1).TrimStartAndEnd();
			DictTable.SetField(Key, ParseGodotValue(WorldContext, PairValue));
		}
	}
	
	return DictTable;
}

FLuaValue UOmegaLuaParser_TSCN::ParsePrimitiveValue(UObject* WorldContext, const FString& Value)
{
	FString TrimmedValue = Value.TrimStartAndEnd();
	
	// Check for boolean
	if (TrimmedValue.Equals("true", ESearchCase::IgnoreCase))
	{
		return FLuaValue(true);
	}
	if (TrimmedValue.Equals("false", ESearchCase::IgnoreCase))
	{
		return FLuaValue(false);
	}
	
	// Check for null
	if (TrimmedValue.Equals("null", ESearchCase::IgnoreCase))
	{
		return FLuaValue();
	}
	
	// Check for quoted string
	if (TrimmedValue.StartsWith("\"") && TrimmedValue.EndsWith("\""))
	{
		return FLuaValue(TrimmedValue.Mid(1, TrimmedValue.Len() - 2));
	}
	
	// Check for number
	if (TrimmedValue.IsNumeric() || TrimmedValue.Contains(".") || TrimmedValue.StartsWith("-"))
	{
		if (TrimmedValue.Contains("."))
		{
			return FLuaValue(FCString::Atof(*TrimmedValue));
		}
		else
		{
			return FLuaValue(FCString::Atoi(*TrimmedValue));
		}
	}
	
	// Default to string
	return FLuaValue(TrimmedValue);
}

// ============================================================================
// TRES PARSER IMPLEMENTATION
// ============================================================================

FLuaValue UOmegaLuaParser_TRES::ParseStringToTable_Implementation(UObject* WorldContext, const FString& String)
{
	FLuaValue RootTable = CreateLuaTable();
	
	// Split into lines
	TArray<FString> Lines;
	String.ParseIntoArrayLines(Lines);
	
	if (Lines.Num() == 0)
	{
		return RootTable;
	}
	
	// Create storage for different section types
	FLuaValue ExtResourcesTable = CreateLuaTable();
	FLuaValue SubResourcesTable = CreateLuaTable();
	
	int32 ExtResourceIndex = 1;
	int32 SubResourceIndex = 1;
	
	FString CurrentSectionType;
	FLuaValue CurrentTable;
	
	for (int32 i = 0; i < Lines.Num(); i++)
	{
		FString Line = Lines[i].TrimStartAndEnd();
		
		// Skip empty lines and comments
		if (Line.IsEmpty() || Line.StartsWith(";"))
		{
			continue;
		}
		
		// Check if this is a section header
		if (Line.StartsWith("[") && Line.EndsWith("]"))
		{
			TMap<FString, FString> Attributes;
			ParseSectionHeader(Line, CurrentSectionType, Attributes);
			
			// Create new table for this section
			CurrentTable = CreateLuaTable();
			
			// Add attributes to table
			for (const auto& Attr : Attributes)
			{
				CurrentTable.SetField(Attr.Key, FLuaValue(Attr.Value));
			}
			
			// Store based on section type
			if (CurrentSectionType == "gd_resource")
			{
				RootTable.SetField("resource_header", CurrentTable);
			}
			else if (CurrentSectionType == "ext_resource")
			{
				ExtResourcesTable.SetFieldByIndex(ExtResourceIndex++, CurrentTable);
			}
			else if (CurrentSectionType == "sub_resource")
			{
				SubResourcesTable.SetFieldByIndex(SubResourceIndex++, CurrentTable);
			}
			else if (CurrentSectionType == "resource")
			{
				RootTable.SetField("resource", CurrentTable);
			}
		}
		else if (Line.Contains("=") && !CurrentTable.IsNil())
		{
			// Parse key=value pair
			int32 EqualsIndex;
			if (Line.FindChar('=', EqualsIndex))
			{
				FString Key = Line.Left(EqualsIndex).TrimStartAndEnd();
				FString Value = Line.Mid(EqualsIndex + 1).TrimStartAndEnd();
				
				CurrentTable.SetField(Key, ParseGodotValue(WorldContext, Value));
			}
		}
	}
	
	// Add arrays to root table if they have items
	if (ULuaBlueprintFunctionLibrary::LuaTableGetKeys(ExtResourcesTable).Num() > 0)
	{
		RootTable.SetField("ext_resources", ExtResourcesTable);
	}
	if (ULuaBlueprintFunctionLibrary::LuaTableGetKeys(SubResourcesTable).Num() > 0)
	{
		RootTable.SetField("sub_resources", SubResourcesTable);
	}
	
	return RootTable;
}

void UOmegaLuaParser_TRES::ParseSectionHeader(const FString& Line, FString& OutSectionType, TMap<FString, FString>& OutAttributes)
{
	// Same implementation as TSCN
	OutAttributes.Empty();
	
	// Remove brackets
	FString Content = Line.Mid(1, Line.Len() - 2).TrimStartAndEnd();
	
	// First word is the section type
	int32 SpaceIndex;
	if (Content.FindChar(' ', SpaceIndex))
	{
		OutSectionType = Content.Left(SpaceIndex);
		FString AttributesStr = Content.Mid(SpaceIndex + 1).TrimStartAndEnd();
		
		// Parse attributes (key="value" or key=value)
		int32 CurrentPos = 0;
		FString CurrentKey;
		FString CurrentValue;
		bool InQuotes = false;
		bool ReadingValue = false;
		
		for (int32 i = 0; i < AttributesStr.Len(); i++)
		{
			TCHAR Char = AttributesStr[i];
			
			if (Char == '"')
			{
				InQuotes = !InQuotes;
			}
			else if (Char == '=' && !InQuotes)
			{
				CurrentKey = AttributesStr.Mid(CurrentPos, i - CurrentPos).TrimStartAndEnd();
				CurrentPos = i + 1;
				ReadingValue = true;
			}
			else if (Char == ' ' && !InQuotes && ReadingValue)
			{
				CurrentValue = AttributesStr.Mid(CurrentPos, i - CurrentPos).TrimStartAndEnd();
				CurrentValue = CurrentValue.TrimQuotes();
				OutAttributes.Add(CurrentKey, CurrentValue);
				CurrentPos = i + 1;
				ReadingValue = false;
			}
		}
		
		// Add the last attribute
		if (ReadingValue && CurrentPos < AttributesStr.Len())
		{
			CurrentValue = AttributesStr.Mid(CurrentPos).TrimStartAndEnd();
			CurrentValue = CurrentValue.TrimQuotes();
			OutAttributes.Add(CurrentKey, CurrentValue);
		}
	}
	else
	{
		OutSectionType = Content;
	}
}

// Reuse the same parsing functions from TSCN
FLuaValue UOmegaLuaParser_TRES::ParseGodotValue(UObject* WorldContext, const FString& Value)
{
	FString TrimmedValue = Value.TrimStartAndEnd();
	
	// Check for function calls
	if (TrimmedValue.Contains("(") && TrimmedValue.EndsWith(")"))
	{
		int32 ParenIndex;
		TrimmedValue.FindChar('(', ParenIndex);
		FString FunctionName = TrimmedValue.Left(ParenIndex);
		
		if (FunctionName == "Vector2" || FunctionName == "Vector3" || FunctionName == "Vector4")
		{
			return ParseVector(WorldContext, TrimmedValue);
		}
		else if (FunctionName == "Color")
		{
			return ParseColor(WorldContext, TrimmedValue);
		}
		return FLuaValue(TrimmedValue);
	}
	
	// Check for arrays
	if (TrimmedValue.StartsWith("[") && TrimmedValue.EndsWith("]"))
	{
		return ParseArray(WorldContext, TrimmedValue);
	}
	
	// Check for dictionaries
	if (TrimmedValue.StartsWith("{") && TrimmedValue.EndsWith("}"))
	{
		return ParseDictionary(WorldContext, TrimmedValue);
	}
	
	// Parse primitive values
	return ParsePrimitiveValue(WorldContext, TrimmedValue);
}

FLuaValue UOmegaLuaParser_TRES::ParseVector(UObject* WorldContext, const FString& Value)
{
	FLuaValue VectorTable = CreateLuaTable();
	
	int32 StartIndex = Value.Find("(") + 1;
	int32 EndIndex = Value.Find(")", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	FString Content = Value.Mid(StartIndex, EndIndex - StartIndex);
	
	TArray<FString> Components;
	Content.ParseIntoArray(Components, TEXT(","), true);
	
	TArray<FString> ComponentNames = {"x", "y", "z", "w"};
	for (int32 i = 0; i < Components.Num() && i < ComponentNames.Num(); i++)
	{
		float ComponentValue = FCString::Atof(*Components[i].TrimStartAndEnd());
		VectorTable.SetField(ComponentNames[i], FLuaValue(ComponentValue));
	}
	
	return VectorTable;
}

FLuaValue UOmegaLuaParser_TRES::ParseColor(UObject* WorldContext, const FString& Value)
{
	FLuaValue ColorTable = CreateLuaTable();
	
	int32 StartIndex = Value.Find("(") + 1;
	int32 EndIndex = Value.Find(")", ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	FString Content = Value.Mid(StartIndex, EndIndex - StartIndex);
	
	TArray<FString> Components;
	Content.ParseIntoArray(Components, TEXT(","), true);
	
	TArray<FString> ComponentNames = {"r", "g", "b", "a"};
	for (int32 i = 0; i < Components.Num() && i < ComponentNames.Num(); i++)
	{
		float ComponentValue = FCString::Atof(*Components[i].TrimStartAndEnd());
		ColorTable.SetField(ComponentNames[i], FLuaValue(ComponentValue));
	}
	
	return ColorTable;
}

FLuaValue UOmegaLuaParser_TRES::ParseArray(UObject* WorldContext, const FString& Value)
{
	FLuaValue ArrayTable = CreateLuaTable();
	
	FString Content = Value.Mid(1, Value.Len() - 2).TrimStartAndEnd();
	
	if (Content.IsEmpty())
	{
		return ArrayTable;
	}
	
	TArray<FString> Elements;
	int32 Depth = 0;
	int32 StartIndex = 0;
	bool InQuotes = false;
	
	for (int32 i = 0; i < Content.Len(); i++)
	{
		TCHAR Char = Content[i];
		
		if (Char == '"' && (i == 0 || Content[i-1] != '\\'))
		{
			InQuotes = !InQuotes;
		}
		else if (!InQuotes)
		{
			if (Char == '[' || Char == '{' || Char == '(')
			{
				Depth++;
			}
			else if (Char == ']' || Char == '}' || Char == ')')
			{
				Depth--;
			}
			else if (Char == ',' && Depth == 0)
			{
				Elements.Add(Content.Mid(StartIndex, i - StartIndex));
				StartIndex = i + 1;
			}
		}
	}
	
	if (StartIndex < Content.Len())
	{
		Elements.Add(Content.Mid(StartIndex));
	}
	
	for (int32 i = 0; i < Elements.Num(); i++)
	{
		ArrayTable.SetFieldByIndex(i + 1, ParseGodotValue(WorldContext, Elements[i]));
	}
	
	return ArrayTable;
}

FLuaValue UOmegaLuaParser_TRES::ParseDictionary(UObject* WorldContext, const FString& Value)
{
	FLuaValue DictTable = CreateLuaTable();
	
	FString Content = Value.Mid(1, Value.Len() - 2).TrimStartAndEnd();
	
	if (Content.IsEmpty())
	{
		return DictTable;
	}
	
	TArray<FString> Pairs;
	int32 Depth = 0;
	int32 StartIndex = 0;
	bool InQuotes = false;
	
	for (int32 i = 0; i < Content.Len(); i++)
	{
		TCHAR Char = Content[i];
		
		if (Char == '"' && (i == 0 || Content[i-1] != '\\'))
		{
			InQuotes = !InQuotes;
		}
		else if (!InQuotes)
		{
			if (Char == '[' || Char == '{' || Char == '(')
			{
				Depth++;
			}
			else if (Char == ']' || Char == '}' || Char == ')')
			{
				Depth--;
			}
			else if (Char == ',' && Depth == 0)
			{
				Pairs.Add(Content.Mid(StartIndex, i - StartIndex));
				StartIndex = i + 1;
			}
		}
	}
	
	if (StartIndex < Content.Len())
	{
		Pairs.Add(Content.Mid(StartIndex));
	}
	
	for (const FString& Pair : Pairs)
	{
		int32 ColonIndex;
		if (Pair.FindChar(':', ColonIndex))
		{
			FString Key = Pair.Left(ColonIndex).TrimStartAndEnd().TrimQuotes();
			FString PairValue = Pair.Mid(ColonIndex + 1).TrimStartAndEnd();
			DictTable.SetField(Key, ParseGodotValue(WorldContext, PairValue));
		}
	}
	
	return DictTable;
}

FLuaValue UOmegaLuaParser_TRES::ParsePrimitiveValue(UObject* WorldContext, const FString& Value)
{
	FString TrimmedValue = Value.TrimStartAndEnd();
	
	if (TrimmedValue.Equals("true", ESearchCase::IgnoreCase))
	{
		return FLuaValue(true);
	}
	if (TrimmedValue.Equals("false", ESearchCase::IgnoreCase))
	{
		return FLuaValue(false);
	}
	
	if (TrimmedValue.Equals("null", ESearchCase::IgnoreCase))
	{
		return FLuaValue();
	}
	
	if (TrimmedValue.StartsWith("\"") && TrimmedValue.EndsWith("\""))
	{
		return FLuaValue(TrimmedValue.Mid(1, TrimmedValue.Len() - 2));
	}
	
	if (TrimmedValue.IsNumeric() || TrimmedValue.Contains(".") || TrimmedValue.StartsWith("-"))
	{
		if (TrimmedValue.Contains("."))
		{
			return FLuaValue(FCString::Atof(*TrimmedValue));
		}
		else
		{
			return FLuaValue(FCString::Atoi(*TrimmedValue));
		}
	}
	
	return FLuaValue(TrimmedValue);
}