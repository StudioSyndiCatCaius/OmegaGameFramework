// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/OmegaFunctions_Json.h"

FJsonObjectWrapper UOmegaJsonFunctions::ParseStringToJson_CSV(const FString StringToParse)
{
    FJsonObjectWrapper JsonWrapper;
    TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
    
    if (StringToParse.IsEmpty())
    {
        JsonWrapper.JsonObject = JsonObject;
        return JsonWrapper;
    }

    // Split the string into lines
    TArray<FString> Lines;
    StringToParse.ParseIntoArrayLines(Lines, false);
    
    if (Lines.Num() < 2) // Need at least headers and one data row
    {
        JsonWrapper.JsonObject = JsonObject;
        return JsonWrapper;
    }

    // Parse headers
    TArray<FString> Headers;
    Lines[0].ParseIntoArray(Headers, TEXT(","), true);

    // Create JSON array to store rows
    TArray<TSharedPtr<FJsonValue>> RowsArray;

    // Process data rows
    for (int32 i = 1; i < Lines.Num(); i++)
    {
        TArray<FString> Values;
        Lines[i].ParseIntoArray(Values, TEXT(","), true);
        
        // Create object for this row
        TSharedPtr<FJsonObject> RowObject = MakeShared<FJsonObject>();
        
        // Map values to headers
        for (int32 j = 0; j < FMath::Min(Headers.Num(), Values.Num()); j++)
        {
            // Trim whitespace from values
            FString Value = Values[j].TrimStartAndEnd();
            
            // Try to parse as number if possible
            double NumericValue = 0;
            if (FCString::Atod(*Value))
            {
                RowObject->SetNumberField(Headers[j], NumericValue);
            }
            else
            {
                RowObject->SetStringField(Headers[j], Value);
            }
        }
        
        RowsArray.Add(MakeShared<FJsonValueObject>(RowObject));
    }

    // Set the rows array in the main JSON object
    JsonObject->SetArrayField(TEXT("rows"), RowsArray);
    
    JsonWrapper.JsonObject = JsonObject;
    return JsonWrapper;
}

FJsonObjectWrapper UOmegaJsonFunctions::ParseStringToJson_Lua(const FString StringToParse)
{
    FJsonObjectWrapper JsonWrapper;
    TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
    
    if (StringToParse.IsEmpty())
    {
        JsonWrapper.JsonObject = JsonObject;
        return JsonWrapper;
    }

    // Remove Lua table syntax
    FString CleanString = StringToParse;
    CleanString = CleanString.Replace(TEXT("{"), TEXT(""));
    CleanString = CleanString.Replace(TEXT("}"), TEXT(""));
    
    // Split into key-value pairs
    TArray<FString> Lines;
    CleanString.ParseIntoArrayLines(Lines, false);
    
    for (const FString& Line : Lines)
    {
        // Skip empty lines and comments
        if (Line.TrimStartAndEnd().IsEmpty() || Line.TrimStartAndEnd().StartsWith(TEXT("--")))
        {
            continue;
        }

        // Split key and value
        FString Key, Value;
        if (Line.Split(TEXT("="), &Key, &Value))
        {
            // Clean up key and value
            Key = Key.TrimStartAndEnd();
            Value = Value.TrimStartAndEnd();
            
            // Remove quotes if present
            if (Key.StartsWith(TEXT("\"")) || Key.StartsWith(TEXT("'")))
            {
                Key = Key.Mid(1, Key.Len() - 2);
            }
            if (Value.StartsWith(TEXT("\"")) || Value.StartsWith(TEXT("'")))
            {
                Value = Value.Mid(1, Value.Len() - 2);
            }
            
            // Remove trailing comma if present
            if (Value.EndsWith(TEXT(",")))
            {
                Value = Value.LeftChop(1);
            }

            // Try to parse as number
            double NumericValue = 0;
            if (FCString::Atod(*Value))
            {
                JsonObject->SetNumberField(Key, NumericValue);
            }
            // Check for boolean
            else if (Value.ToLower() == TEXT("true"))
            {
                JsonObject->SetBoolField(Key, true);
            }
            else if (Value.ToLower() == TEXT("false"))
            {
                JsonObject->SetBoolField(Key, false);
            }
            // Handle as string
            else
            {
                JsonObject->SetStringField(Key, Value);
            }
        }
    }
    
    JsonWrapper.JsonObject = JsonObject;
    return JsonWrapper;
}

FJsonObjectWrapper UOmegaJsonFunctions::ParseStringToJson_INI(const FString StringToParse)
{
    FJsonObjectWrapper JsonWrapper;
    TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
    
    if (StringToParse.IsEmpty())
    {
        JsonWrapper.JsonObject = JsonObject;
        return JsonWrapper;
    }

    // Current section object
    TSharedPtr<FJsonObject> CurrentSection = nullptr;
    FString CurrentSectionName;

    // Split into lines
    TArray<FString> Lines;
    StringToParse.ParseIntoArrayLines(Lines, false);
    
    for (const FString& Line : Lines)
    {
        FString TrimmedLine = Line.TrimStartAndEnd();
        
        // Skip empty lines and comments
        if (TrimmedLine.IsEmpty() || TrimmedLine.StartsWith(TEXT(";")) || TrimmedLine.StartsWith(TEXT("#")))
        {
            continue;
        }

        // Check for section header
        if (TrimmedLine.StartsWith(TEXT("[")) && TrimmedLine.EndsWith(TEXT("]")))
        {
            // Extract section name
            CurrentSectionName = TrimmedLine.Mid(1, TrimmedLine.Len() - 2);
            
            // Create new section object
            CurrentSection = MakeShared<FJsonObject>();
            JsonObject->SetObjectField(CurrentSectionName, CurrentSection);
            continue;
        }

        // Handle key-value pairs
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

            // Try to parse as number
            if (FCString::Atod(*Value))
            {
                if (CurrentSection)
                {
                    CurrentSection->SetNumberField(Key, FCString::Atod(*Value));
                }
                else
                {
                    JsonObject->SetNumberField(Key, FCString::Atod(*Value));
                }
            }
            // Check for boolean
            else if (Value.ToLower() == TEXT("true"))
            {
                if (CurrentSection)
                {
                    CurrentSection->SetBoolField(Key, true);
                }
                else
                {
                    JsonObject->SetBoolField(Key, true);
                }
            }
            else if (Value.ToLower() == TEXT("false"))
            {
                if (CurrentSection)
                {
                    CurrentSection->SetBoolField(Key, false);
                }
                else
                {
                    JsonObject->SetBoolField(Key, false);
                }
            }
            // Handle as string
            else
            {
                if (CurrentSection)
                {
                    CurrentSection->SetStringField(Key, Value);
                }
                else
                {
                    JsonObject->SetStringField(Key, Value);
                }
            }
        }
    }
    
    JsonWrapper.JsonObject = JsonObject;
    return JsonWrapper;
}

FJsonObjectWrapper UOmegaJsonFunctions::ParseStringToJson_YAML(const FString StringToParse)
{
    FJsonObjectWrapper JsonWrapper;
    TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
    
    if (StringToParse.IsEmpty())
    {
        JsonWrapper.JsonObject = JsonObject;
        return JsonWrapper;
    }

    struct FYamlNode
    {
        FString Key;
        TSharedPtr<FJsonValue> Value;
        int32 IndentLevel;
        TArray<FYamlNode> Children;
    };

    TArray<FYamlNode> NodeStack;
    FYamlNode RootNode;
    RootNode.IndentLevel = -1;
    NodeStack.Push(RootNode);

    // Split into lines
    TArray<FString> Lines;
    StringToParse.ParseIntoArrayLines(Lines, false);
    
    for (const FString& Line : Lines)
    {
        FString TrimmedLine = Line.TrimEnd();
        
        // Skip empty lines and comments
        if (TrimmedLine.IsEmpty() || TrimmedLine.TrimStart().StartsWith(TEXT("#")))
        {
            continue;
        }

        // Calculate indent level (number of spaces before content)
        int32 IndentLevel = 0;
        while (IndentLevel < TrimmedLine.Len() && TrimmedLine[IndentLevel] == TEXT(' '))
        {
            IndentLevel++;
        }
        IndentLevel /= 2; // Assuming 2 spaces per indent level

        // Remove leading spaces
        FString Content = TrimmedLine.TrimStart();

        // Pop stack until we find parent with lower indent level
        while (NodeStack.Num() > 1 && NodeStack.Last().IndentLevel >= IndentLevel)
        {
            NodeStack.Pop();
        }

        // Parse the line
        if (Content.Contains(TEXT(":")))
        {
            FString Key, Value;
            Content.Split(TEXT(":"), &Key, &Value);
            Key = Key.TrimStartAndEnd();
            Value = Value.TrimStartAndEnd();

            FYamlNode NewNode;
            NewNode.Key = Key;
            NewNode.IndentLevel = IndentLevel;

            // Check if this is a key with value or just a key (parent node)
            if (!Value.IsEmpty())
            {
                // Remove quotes if present
                if (Value.StartsWith(TEXT("\"")) && Value.EndsWith(TEXT("\"")))
                {
                    Value = Value.Mid(1, Value.Len() - 2);
                }

                // Try to parse as number
                if (FCString::Atod(*Value))
                {
                    NewNode.Value = MakeShared<FJsonValueNumber>(FCString::Atod(*Value));
                }
                // Check for boolean
                else if (Value.ToLower() == TEXT("true"))
                {
                    NewNode.Value = MakeShared<FJsonValueBoolean>(true);
                }
                else if (Value.ToLower() == TEXT("false"))
                {
                    NewNode.Value = MakeShared<FJsonValueBoolean>(false);
                }
                // Check for null
                else if (Value.ToLower() == TEXT("null"))
                {
                    NewNode.Value = MakeShared<FJsonValueNull>();
                }
                // Handle as string
                else
                {
                    NewNode.Value = MakeShared<FJsonValueString>(Value);
                }
            }

            NodeStack.Last().Children.Add(NewNode);
            NodeStack.Push(NewNode);
        }
        // Handle array items (starting with -)
        else if (Content.StartsWith(TEXT("-")))
        {
            FString Value = Content.Mid(1).TrimStartAndEnd();
            
            // Create array if not exists
            if (!NodeStack.Last().Value.IsValid())
            {
                NodeStack.Last().Value = MakeShared<FJsonValueArray>(TArray<TSharedPtr<FJsonValue>>());
            }

            TArray<TSharedPtr<FJsonValue>> Array = NodeStack.Last().Value->AsArray();

            // Try to parse as number
            if (FCString::Atod(*Value))
            {
                Array.Add(MakeShared<FJsonValueNumber>(FCString::Atod(*Value)));
            }
            // Check for boolean
            else if (Value.ToLower() == TEXT("true"))
            {
                Array.Add(MakeShared<FJsonValueBoolean>(true));
            }
            else if (Value.ToLower() == TEXT("false"))
            {
                Array.Add(MakeShared<FJsonValueBoolean>(false));
            }
            // Check for null
            else if (Value.ToLower() == TEXT("null"))
            {
                Array.Add(MakeShared<FJsonValueNull>());
            }
            // Handle as string
            else
            {
                Array.Add(MakeShared<FJsonValueString>(Value));
            }
        }
    }

    // Convert node tree to JSON
    std::function<void(const FYamlNode&, TSharedPtr<FJsonObject>)> BuildJson = 
        [&BuildJson](const FYamlNode& Node, TSharedPtr<FJsonObject> Current)
    {
        // If node has a direct value, add it
        if (Node.Value.IsValid())
        {
            Current->SetField(Node.Key, Node.Value);
        }
        // If node has children, process them
        else if (Node.Children.Num() > 0)
        {
            TSharedPtr<FJsonObject> ChildObject = MakeShared<FJsonObject>();
            for (const FYamlNode& Child : Node.Children)
            {
                BuildJson(Child, ChildObject);
            }
            if (!Node.Key.IsEmpty())
            {
                Current->SetObjectField(Node.Key, ChildObject);
            }
            else
            {
                // Copy all fields to current object (for root node)
                for (const auto& Pair : ChildObject->Values)
                {
                    Current->SetField(Pair.Key, Pair.Value);
                }
            }
        }
    };

    BuildJson(RootNode, JsonObject);
    
    JsonWrapper.JsonObject = JsonObject;
    return JsonWrapper;
}

bool UOmegaJsonFunctions::GetJsonValue_Bool(FJsonObjectWrapper json, const FString& field)
{
   return json.JsonObject->GetBoolField(field);
}

int32 UOmegaJsonFunctions::GetJsonValue_Int(FJsonObjectWrapper json, const FString& field)
{
   return json.JsonObject->GetIntegerField(field);
}

float UOmegaJsonFunctions::GetJsonValue_Float(FJsonObjectWrapper json, const FString& field)
{
   return json.JsonObject->GetNumberField(field);
}

FString UOmegaJsonFunctions::GetJsonValue_String(FJsonObjectWrapper json, const FString& field)
{
   return json.JsonObject->GetStringField(field);
}

