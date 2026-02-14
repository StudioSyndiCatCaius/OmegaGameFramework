// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Parser.h"

#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"



FOmegaParsedTable UOmegaParserFunctions::OmegaParse_CSV(const FString& FileString)
{
    FOmegaParsedTable ParsedTable;
    
    if (FileString.IsEmpty())
    {
        return ParsedTable;
    }
    
    TArray<FString> Lines;
    FileString.ParseIntoArrayLines(Lines);
    
    if (Lines.Num() == 0)
    {
        return ParsedTable;
    }
    
    // Get header row
    TArray<FString> Headers;
    Lines[0].ParseIntoArray(Headers, TEXT(","), true);
    
    // Clean headers (remove quotes and whitespace)
    for (FString& Header : Headers)
    {
        Header = Header.TrimStartAndEnd().Replace(TEXT("\""), TEXT(""));
    }
    
    // Parse data rows
    for (int32 i = 1; i < Lines.Num(); i++)
    {
        TArray<FString> Values;
        Lines[i].ParseIntoArray(Values, TEXT(","), true);
        
        if (Values.Num() > 0)
        {
            FOmegaParsedParams RowParams;
            
            for (int32 j = 0; j < FMath::Min(Headers.Num(), Values.Num()); j++)
            {
                FString CleanValue = Values[j].TrimStartAndEnd().Replace(TEXT("\""), TEXT(""));
                RowParams.params.Add(FName(*Headers[j]), CleanValue);
            }
            
            // Use first column as row key, or generate one if empty
            FString RowKey = Values.Num() > 0 ? Values[0].TrimStartAndEnd().Replace(TEXT("\""), TEXT("")) : FString::Printf(TEXT("Row_%d"), i);
            if (RowKey.IsEmpty())
            {
                RowKey = FString::Printf(TEXT("Row_%d"), i);
            }
            
            ParsedTable.params.Add(FName(*RowKey), RowParams);
        }
    }
    
    return ParsedTable;
}

FOmegaParsedTable UOmegaParserFunctions::OmegaParse_YAML(const FString& FileString)
{
    FOmegaParsedTable ParsedTable;
    
    if (FileString.IsEmpty())
    {
        return ParsedTable;
    }
    
    TArray<FString> Lines;
    FileString.ParseIntoArrayLines(Lines);
    
    FString CurrentSection = TEXT("Default");
    FOmegaParsedParams CurrentParams;
    
    for (const FString& Line : Lines)
    {
        FString TrimmedLine = Line.TrimStartAndEnd();
        
        // Skip empty lines and comments
        if (TrimmedLine.IsEmpty() || TrimmedLine.StartsWith(TEXT("#")))
        {
            continue;
        }
        
        // Check for section (no indentation, ends with colon)
        if (!TrimmedLine.StartsWith(TEXT(" ")) && !TrimmedLine.StartsWith(TEXT("\t")) && TrimmedLine.EndsWith(TEXT(":")))
        {
            // Save previous section if it has data
            if (CurrentParams.params.Num() > 0)
            {
                ParsedTable.params.Add(FName(*CurrentSection), CurrentParams);
                CurrentParams.params.Empty();
            }
            
            CurrentSection = TrimmedLine.Left(TrimmedLine.Len() - 1).TrimStartAndEnd();
        }
        // Check for key-value pair
        else if (TrimmedLine.Contains(TEXT(":")))
        {
            FString Key, Value;
            if (TrimmedLine.Split(TEXT(":"), &Key, &Value))
            {
                Key = Key.TrimStartAndEnd();
                Value = Value.TrimStartAndEnd();
                
                // Remove quotes if present
                if (Value.StartsWith(TEXT("\"")) && Value.EndsWith(TEXT("\"")))
                {
                    Value = Value.Mid(1, Value.Len() - 2);
                }
                else if (Value.StartsWith(TEXT("'")) && Value.EndsWith(TEXT("'")))
                {
                    Value = Value.Mid(1, Value.Len() - 2);
                }
                
                CurrentParams.params.Add(FName(*Key), Value);
            }
        }
    }
    
    // Add the last section
    if (CurrentParams.params.Num() > 0)
    {
        ParsedTable.params.Add(FName(*CurrentSection), CurrentParams);
    }
    
    return ParsedTable;
}

FOmegaParsedTable UOmegaParserFunctions::OmegaParse_INI(const FString& FileString)
{
    FOmegaParsedTable ParsedTable;
    
    if (FileString.IsEmpty())
    {
        return ParsedTable;
    }
    
    TArray<FString> Lines;
    FileString.ParseIntoArrayLines(Lines);
    
    FString CurrentSection = TEXT("Default");
    FOmegaParsedParams CurrentParams;
    
    for (const FString& Line : Lines)
    {
        FString TrimmedLine = Line.TrimStartAndEnd();
        
        // Skip empty lines and comments
        if (TrimmedLine.IsEmpty() || TrimmedLine.StartsWith(TEXT(";")) || TrimmedLine.StartsWith(TEXT("#")))
        {
            continue;
        }
        
        // Check for section [SectionName]
        if (TrimmedLine.StartsWith(TEXT("[")) && TrimmedLine.EndsWith(TEXT("]")))
        {
            // Save previous section if it has data
            if (CurrentParams.params.Num() > 0)
            {
                ParsedTable.params.Add(FName(*CurrentSection), CurrentParams);
                CurrentParams.params.Empty();
            }
            
            CurrentSection = TrimmedLine.Mid(1, TrimmedLine.Len() - 2).TrimStartAndEnd();
        }
        // Check for key-value pair
        else if (TrimmedLine.Contains(TEXT("=")))
        {
            FString Key, Value;
            if (TrimmedLine.Split(TEXT("="), &Key, &Value))
            {
                Key = Key.TrimStartAndEnd();
                Value = Value.TrimStartAndEnd();
                
                // Remove quotes if present
                if (Value.StartsWith(TEXT("\"")) && Value.EndsWith(TEXT("\"")))
                {
                    Value = Value.Mid(1, Value.Len() - 2);
                }
                
                CurrentParams.params.Add(FName(*Key), Value);
            }
        }
    }
    
    // Add the last section
    if (CurrentParams.params.Num() > 0)
    {
        ParsedTable.params.Add(FName(*CurrentSection), CurrentParams);
    }
    
    return ParsedTable;
}

FOmegaParsedTable UOmegaParserFunctions::OmegaParse_TOML(const FString& FileString)
{
    FOmegaParsedTable ParsedTable;
    
    if (FileString.IsEmpty())
    {
        return ParsedTable;
    }
    
    TArray<FString> Lines;
    FileString.ParseIntoArrayLines(Lines);
    
    FString CurrentSection = TEXT("Default");
    FOmegaParsedParams CurrentParams;
    
    for (const FString& Line : Lines)
    {
        FString TrimmedLine = Line.TrimStartAndEnd();
        
        // Skip empty lines and comments
        if (TrimmedLine.IsEmpty() || TrimmedLine.StartsWith(TEXT("#")))
        {
            continue;
        }
        
        // Check for section [section.name]
        if (TrimmedLine.StartsWith(TEXT("[")) && TrimmedLine.EndsWith(TEXT("]")))
        {
            // Save previous section if it has data
            if (CurrentParams.params.Num() > 0)
            {
                ParsedTable.params.Add(FName(*CurrentSection), CurrentParams);
                CurrentParams.params.Empty();
            }
            
            CurrentSection = TrimmedLine.Mid(1, TrimmedLine.Len() - 2).TrimStartAndEnd();
        }
        // Check for key-value pair
        else if (TrimmedLine.Contains(TEXT("=")))
        {
            FString Key, Value;
            if (TrimmedLine.Split(TEXT("="), &Key, &Value))
            {
                Key = Key.TrimStartAndEnd();
                Value = Value.TrimStartAndEnd();
                
                // Handle different TOML value types
                if (Value.StartsWith(TEXT("\"")) && Value.EndsWith(TEXT("\"")))
                {
                    // String value
                    Value = Value.Mid(1, Value.Len() - 2);
                }
                else if (Value.StartsWith(TEXT("'")) && Value.EndsWith(TEXT("'")))
                {
                    // Single-quoted string
                    Value = Value.Mid(1, Value.Len() - 2);
                }
                else if (Value.StartsWith(TEXT("\"\"\"")) && Value.EndsWith(TEXT("\"\"\"")))
                {
                    // Multi-line string
                    Value = Value.Mid(3, Value.Len() - 6);
                }
                else if (Value == TEXT("true") || Value == TEXT("false"))
                {
                    // Boolean - keep as is
                }
                else if (Value.IsNumeric() || Value.Contains(TEXT(".")))
                {
                    // Number - keep as is
                }
                else if (Value.StartsWith(TEXT("[")) && Value.EndsWith(TEXT("]")))
                {
                    // Array - simplified handling, keep as string
                    Value = Value.Mid(1, Value.Len() - 2);
                }
                
                CurrentParams.params.Add(FName(*Key), Value);
            }
        }
    }
    
    // Add the last section
    if (CurrentParams.params.Num() > 0)
    {
        ParsedTable.params.Add(FName(*CurrentSection), CurrentParams);
    }
    
    return ParsedTable;
}


FString UOmegaParserFunctions::GetParsedTableValue_String(FOmegaParsedTable Table, FName Key, FName SubKey)
{
    if (const FOmegaParsedParams* ParamsPtr = Table.params.Find(Key))
    {
        if (const FString* ValuePtr = ParamsPtr->params.Find(SubKey))
        {
            return *ValuePtr;
        }
    }
    
    return FString();
}

float UOmegaParserFunctions::GetParsedTableValue_Float(FOmegaParsedTable Table, FName Key, FName SubKey)
{
    FString StringValue = GetParsedTableValue_String(Table, Key, SubKey);
    
    if (StringValue.IsEmpty())
    {
        return 0.0f;
    }
    
    // Handle common boolean strings that should convert to float
    if (StringValue.ToLower() == TEXT("true"))
    {
        return 1.0f;
    }
    else if (StringValue.ToLower() == TEXT("false"))
    {
        return 0.0f;
    }
    
    // Try to convert to float
    if (StringValue.IsNumeric())
    {
        return FCString::Atof(*StringValue);
    }
    
    return 0.0f;
}

int32 UOmegaParserFunctions::GetParsedTableValue_Int32(FOmegaParsedTable Table, FName Key, FName SubKey)
{
    FString StringValue = GetParsedTableValue_String(Table, Key, SubKey);
    
    if (StringValue.IsEmpty())
    {
        return 0;
    }
    
    // Handle boolean strings
    if (StringValue.ToLower() == TEXT("true"))
    {
        return 1;
    }
    else if (StringValue.ToLower() == TEXT("false"))
    {
        return 0;
    }
    
    // Try to convert to integer
    if (StringValue.IsNumeric())
    {
        return FCString::Atoi(*StringValue);
    }
    
    // Handle float strings by converting to float first, then to int
    float FloatValue = FCString::Atof(*StringValue);
    if (FloatValue != 0.0f || StringValue.Contains(TEXT("0")))
    {
        return FMath::RoundToInt(FloatValue);
    }
    
    return 0;
}

bool UOmegaParserFunctions::GetParsedTableValue_Bool(FOmegaParsedTable Table, FName Key, FName SubKey)
{
    FString StringValue = GetParsedTableValue_String(Table, Key, SubKey);
    
    if (StringValue.IsEmpty())
    {
        return false;
    }
    
    FString LowerValue = StringValue.ToLower();
    
    // Handle common boolean representations
    if (LowerValue == TEXT("true") || 
        LowerValue == TEXT("1") || 
        LowerValue == TEXT("yes") || 
        LowerValue == TEXT("on") || 
        LowerValue == TEXT("enabled"))
    {
        return true;
    }
    else if (LowerValue == TEXT("false") || 
             LowerValue == TEXT("0") || 
             LowerValue == TEXT("no") || 
             LowerValue == TEXT("off") || 
             LowerValue == TEXT("disabled"))
    {
        return false;
    }
    
    // For numeric values, treat non-zero as true
    if (StringValue.IsNumeric())
    {
        float NumericValue = FCString::Atof(*StringValue);
        return NumericValue != 0.0f;
    }
    
    // For non-empty strings that don't match known false values, return true
    return !StringValue.IsEmpty();
}

