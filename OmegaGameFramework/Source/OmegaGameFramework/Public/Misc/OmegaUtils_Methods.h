// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
//#include "OmegaUtils_Methods.generated.h"

class USaveGame;
class AActor;

class OGF_Log
{
public:
	// Screen logging functions with color
	static void Error(const FString& Message, float Duration = 5.0f);
	static void Warning(const FString& Message, float Duration = 4.0f);
	static void Info(const FString& Message, float Duration = 3.0f);
	static void Success(const FString& Message, float Duration = 3.0f);
    
	// Console logging (also outputs to screen if bAlsoLogToScreen is true)
	static void LogError(const FString& Message, bool bAlsoLogToScreen = false);
	static void LogWarning(const FString& Message, bool bAlsoLogToScreen = false);
	static void LogInfo(const FString& Message, bool bAlsoLogToScreen = false);
    
	// Custom color logging
	static void LogWithColor(const FString& Message, FColor Color, float Duration = 3.0f);
    
	// Formatted logging (similar to printf)
	template<typename... Args>
	static void ErrorF(const FString& Format, Args... Arguments)
	{
		Error(FString::Printf(*Format, Arguments...));
	}
    
	template<typename... Args>
	static void WarningF(const FString& Format, Args... Arguments)
	{
		Warning(FString::Printf(*Format, Arguments...));
	}
    
	template<typename... Args>
	static void InfoF(const FString& Format, Args... Arguments)
	{
		Info(FString::Printf(*Format, Arguments...));
	}

private:
	// Helper function to handle the actual screen printing
	static void PrintToScreen(const FString& Message, FColor Color, float Duration);
    
	// Static colors for consistency
	static const FColor ErrorColor;
	static const FColor WarningColor;
	static const FColor InfoColor;
	static const FColor SuccessColor;
};

class OGF_Load
{
public:

	static bool LevelStream_IsLoading(UWorld* World);
};


class OGF_Actor
{
public:
	static void SetTagActive(AActor* a, FName tag, bool is_active);
	static void SetTagsActive(AActor* a, TArray<FName> tags, bool is_active);
	static void SetTagActive_list(TArray<AActor*> a, FName tag, bool is_active);
	static void SetTagsActive_list(TArray<AActor*> a, TArray<FName> tags, bool is_active);
};

class OGF_Save
{
public:
	static bool SaveGame(USaveGame* save, const FString& path,const FString& filename);
	static USaveGame* LoadGame(const FString& path,const FString& filename);
};

class OGF_Build
{
public:
};