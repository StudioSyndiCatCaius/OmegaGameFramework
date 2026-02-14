// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Misc/OmegaUtils_Methods.h"

#include "LuaSubsystem.h"
#include "OmegaSettings.h"
#include "Engine/Engine.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "HAL/PlatformFilemanager.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/FileHelper.h"
// Define static color constants
const FColor OGF_Log::ErrorColor = FColor::Red;
const FColor OGF_Log::WarningColor = FColor::Yellow;
const FColor OGF_Log::InfoColor = FColor::Cyan;
const FColor OGF_Log::SuccessColor = FColor::Green;

void OGF_Log::Error(const FString& Message, float Duration)
{
    PrintToScreen(Message, ErrorColor, Duration);
    
    // Also log to console with error level
    UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
}

void OGF_Log::Warning(const FString& Message, float Duration)
{
    PrintToScreen(Message, WarningColor, Duration);
    
    // Also log to console with warning level
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

void OGF_Log::Info(const FString& Message, float Duration)
{
    PrintToScreen(Message, InfoColor, Duration);
    
    // Also log to console with log level
    UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
}

void OGF_Log::Success(const FString& Message, float Duration)
{
    PrintToScreen(Message, SuccessColor, Duration);
    
    // Also log to console with log level
    UE_LOG(LogTemp, Log, TEXT("SUCCESS: %s"), *Message);
}

void OGF_Log::LogError(const FString& Message, bool bAlsoLogToScreen)
{
    UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
    
    if (bAlsoLogToScreen)
    {
        PrintToScreen(Message, ErrorColor, 5.0f);
    }
}

void OGF_Log::LogWarning(const FString& Message, bool bAlsoLogToScreen)
{
    UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
    
    if (bAlsoLogToScreen)
    {
        PrintToScreen(Message, WarningColor, 4.0f);
    }
}

void OGF_Log::LogInfo(const FString& Message, bool bAlsoLogToScreen)
{
    UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
    
    if (bAlsoLogToScreen)
    {
        PrintToScreen(Message, InfoColor, 3.0f);
    }
}

void OGF_Log::LogWithColor(const FString& Message, FColor Color, float Duration)
{
    PrintToScreen(Message, Color, Duration);
    
    // Also log to console
    UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
}

void OGF_Log::PrintToScreen(const FString& Message, FColor Color, float Duration)
{
    // Check if GEngine is valid before using it
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, Duration, Color, Message);
    }
    else
    {
        // Fallback to console if GEngine is not available
        UE_LOG(LogTemp, Warning, TEXT("GEngine not available, console fallback: %s"), *Message);
    }
}

// ================================================================================================================
// LOAD
// ================================================================================================================
bool OGF_Load::LevelStream_IsLoading(UWorld* World)
{
    if(World)
    {
       for (ULevelStreaming* StreamingLevel : World->GetStreamingLevels())
       {
           if (StreamingLevel && StreamingLevel->IsStreamingStatePending())
           {
               return true;
           }
       }
    }
    return false;
}

FString OGF_File::PathCorrect(const FString& path)
{
    FString out=path;
    out=out.Replace(TEXT("{project}"),*FPaths::ProjectDir());
    out=out.Replace(TEXT("{content}"),*FPaths::ProjectContentDir());
    out=out.Replace(TEXT("{mods}"),*FPaths::ProjectModsDir());
    out=out.Replace(TEXT("{saves}"),*FPaths::GameAgnosticSavedDir());
    out=out.Replace(TEXT("//"),TEXT("/"));
    
    FPaths::NormalizeFilename(out);
    return out;
}

TArray<FString> OGF_File::ListFilesInDirectory(const FString& path, bool bRecursive)
{
    FString _Path=PathCorrect(path);
    TArray<FString> FoundFiles;
    
    if (bRecursive)
    {
        // Search recursively for all files in the directory and subdirectories
        IFileManager::Get().FindFilesRecursive(FoundFiles, *_Path, TEXT("*"), true, false);
    }
    else
    {
        // Search only in the specified directory (non-recursive)
        FString SearchPath = _Path / TEXT("*");
        IFileManager::Get().FindFiles(FoundFiles, *SearchPath, true, false);
    }
    
    return FoundFiles;
}

TArray<FString> OGF_File::ListFilesInDirectoryList(TArray<FString> paths, bool bRecursive)
{
    TArray<FString> out;
    for (FString dir : paths)
    {
        out.Append(ListFilesInDirectory(dir, bRecursive));
    }
    return out;
}


// ================================================================================================================
// ACTOR
// ================================================================================================================
void OGF_Actor::SetTagActive(AActor* a, FName tag, bool is_active)
{
    if(a && !tag.IsNone())
    {
        if(is_active)
        {
            a->Tags.AddUnique(tag);
        }
        else if (a->Tags.Contains(tag))
        {
            a->Tags.Remove(tag);
        }
    }
}

void OGF_Actor::SetTagsActive(AActor* a, TArray<FName> tags, bool is_active)
{
    if(!a){ return;}
    for(auto t : tags)
    {
        SetTagActive(a,t,is_active);
    }
}

void OGF_Actor::SetTagActive_list(TArray<AActor*> a, FName tag, bool is_active)
{
    for(auto* ac : a)
    {
        if(ac) { SetTagActive(ac,tag,is_active);}
    }
}

void OGF_Actor::SetTagsActive_list(TArray<AActor*> a, TArray<FName> tags, bool is_active)
{
    for(auto* ac : a)
    {
        if(ac) { SetTagsActive(ac,tags,is_active);}
    }
}

bool OGF_Save::SaveGame(USaveGame* save, const FString& path,const FString& filename)
{
    const FString file_path=path+filename+".sav";
    
    if (!save)
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_SaveGame: SaveGameObject is null"));
        return false;
    }

    if (file_path.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_SaveGame: FilePath is empty"));
        return false;
    }

    // save file data
    TArray<uint8> SaveData;
    if(!UGameplayStatics::SaveGameToMemory(save,SaveData))
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_SaveGame: Failed to save game to memory array: %s"), *file_path);
        return false;  
    }

    
     if (!FFileHelper::SaveArrayToFile(SaveData, *file_path))
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_SaveGame: Failed to save file to int array: %s"), *file_path);
         return false;
    }
  
    return true;  
}

USaveGame* OGF_Save::LoadGame(const FString& path,const FString& filename)
{
    const FString file_path=path+filename+".sav";
    
    if (file_path.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_LoadGame: FilePath is empty"));
        return nullptr;
    }

    // Check if file exists
    if (!FPaths::FileExists(file_path))
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_LoadGame: File does not exist: %s"), *file_path);
        return nullptr;
    }

    // Load file data
    TArray<uint8> SaveData;
    if (!FFileHelper::LoadFileToArray(SaveData, *file_path))
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_LoadGame: Failed to load file: %s"), *file_path);
        return nullptr;
    }

    if (SaveData.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_LoadGame: File is empty: %s"), *file_path);
        return nullptr;
    }

    // Use UE5's built-in function to deserialize from memory
    USaveGame* LoadedSaveGame = UGameplayStatics::LoadGameFromMemory(SaveData);
    if (!LoadedSaveGame)
    {
        UE_LOG(LogTemp, Warning, TEXT("Custom_LoadGame: Failed to deserialize SaveGame from: %s"), *file_path);
        return nullptr;
    }

    UE_LOG(LogTemp, Log, TEXT("Custom_LoadGame: Successfully loaded from: %s"), *file_path);
    return LoadedSaveGame;
}

TArray<FName> OGF_Assets::Keys_Attribute()
{
    TArray<FName> out;

    return out;
}

TMap<FName, UOmegaAttribute*> OGF_Assets::Map_NamedAttribute(TArray<FName> names)
{
    TMap<FName, UOmegaAttribute*> out;

    return out;
}

TMap<UOmegaAttribute*, float> OGF_Assets::NamedAttributes_ToFloat(TMap<FName, float> vals)
{
    TMap<UOmegaAttribute*, float> out;
    TArray<FName> nams;
    vals.GetKeys(nams);
    TMap<FName, UOmegaAttribute*> named_atts=Map_NamedAttribute(nams);
    for(FName n : nams)
    {
        if(named_atts.Contains(n) && named_atts[n])
        {
            out.Add(named_atts[n],vals[n]);
        }
    }
    return out;
}

void OGF_SoftParam::Bitmask_Set(int32& bitmask, uint8 flag, bool Value)
{
    // Ensure the bit index is valid (0-31 for int32)
    if (flag < 0 || flag > 31)
    {
        return;
    }
    
    if (Value)
    {
        // Set the bit using bitwise OR
        bitmask |= (1 << flag);
    }
    else
    {
        // Clear the bit using bitwise AND with inverted mask
        bitmask &= ~(1 << flag);
    }
}

bool OGF_SoftParam::Bitmask_Get(int32 bitmask, uint8 flag)
{
    // Ensure the bit index is valid (0-31 for int32)
    if (flag < 0 || flag > 31)
    {
        return false;
    }
    
    // Use bitwise AND to check if the bit is set
    return (bitmask & (1 << flag)) != 0;
}

float OGF_SoftParam::Conv_float(TMap<FName, FString> params, FName key, float def)
{
    const FString LocalVal = Conv_string(params, key,FString::SanitizeFloat(def));
    return FCString::Atof(*LocalVal);
}

int32 OGF_SoftParam::Conv_int(TMap<FName, FString> params, FName key, int32 def)
{
    const FString LocalVal = Conv_string(params, key,FString::FromInt(def));
    return FCString::Atoi(*LocalVal);
}

bool OGF_SoftParam::Conv_bool(TMap<FName, FString> params, FName key, bool def)
{
    FString BoolStr = def ? TEXT("true") : TEXT("false");
    const FString LocalVal = Conv_string(params, key,BoolStr);
    return LocalVal.ToBool();
}

FString OGF_SoftParam::Conv_string(TMap<FName, FString> params, FName key, FString def)
{
    if(params.Contains(key)) { return params[key]; } return def;
}

void OGF_SoftParam::set_float(TMap<FName, FString>& params, FName key, float def)
{
    params.Add(key,FString::SanitizeFloat(def));
}

void OGF_SoftParam::set_int(TMap<FName, FString>& params, FName key, int32 def)
{
    params.Add(key,FString::FromInt(def));
}

void OGF_SoftParam::set_bool(TMap<FName, FString>& params, FName key, bool def)
{
    FString BoolStr = def ? TEXT("true") : TEXT("false");
    params.Add(key,BoolStr);
}

void OGF_SoftParam::set_string(TMap<FName, FString>& params, FName key, FString def)
{
    params.Add(key,def);
}

TArray<FName> OGF_Lua::GKeys(UWorld* World, const FString global)
{
    TArray<FName> out;
    if(World)
    {
        return World->GetSubsystem<ULuaWorldSubsystem>()->GetGlobalKeys(global);
    }
    return out;
}




