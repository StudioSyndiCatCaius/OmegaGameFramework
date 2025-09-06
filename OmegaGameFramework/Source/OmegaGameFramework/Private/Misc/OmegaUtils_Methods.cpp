// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Misc/OmegaUtils_Methods.h"
#include "Engine/Engine.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "HAL/PlatformFilemanager.h"
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


