// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_Config.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Misc/ConfigCacheIni.h"
#include "Interfaces/IPluginManager.h"

static const TCHAR* IniFileName = TEXT("OmegaGameSettings.ini");

// ── Path Helpers ──────────────────────────────────────────────────────────────

bool UOmegaFunctions_Config::IsInOmegaDeveloperMode()
{
    FString JsonString;
    if (!FFileHelper::LoadFileToString(JsonString, *FPaths::GetProjectFilePath()))
        return false;

    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
        return false;

    bool bDeveloperMode = false;
    JsonObject->TryGetBoolField(TEXT("OmegaDeveloperMode"), bDeveloperMode);
    return bDeveloperMode;
}

FString UOmegaFunctions_Config::L_GetConfigPath()
{
    FString Path = FPaths::ProjectConfigDir() / IniFileName;
    FPaths::MakeStandardFilename(Path);
    return Path;
}

FString UOmegaFunctions_Config::L_GetPluginConfigPath()
{
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("OmegaGameFramework"));
    const FString BaseDir = Plugin.IsValid()
        ? Plugin->GetBaseDir()
        : FPaths::ProjectPluginsDir() / TEXT("OmegaGameFramework");

    FString Path = BaseDir / TEXT("Config") / IniFileName;
    FPaths::MakeStandardFilename(Path);
    return Path;
}

void UOmegaFunctions_Config::L_EnsureFileExists(const FString& Path)
{
    if (!FPaths::FileExists(Path))
        FFileHelper::SaveStringToFile(TEXT(""), *Path, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);

    if (GConfig) GConfig->LoadFile(Path);
}

// ── Core Lookup ───────────────────────────────────────────────────────────────

template <typename T>
static T L_GetValue(
    const FString& Section,
    const FString& Param,
    T DefaultValue,
    TFunction<bool(const FString&, T&)> GetterFn,
    TFunction<void(const FString&)>     DefaultFn)
{
    if (!GConfig) return DefaultValue;

    const FString ProjectPath = UOmegaFunctions_Config::L_GetConfigPath();
    UOmegaFunctions_Config::L_EnsureFileExists(ProjectPath);

    T Out = DefaultValue;
    if (GetterFn(ProjectPath, Out)) return Out;

    const FString PluginPath = UOmegaFunctions_Config::L_GetPluginConfigPath();
    UOmegaFunctions_Config::L_EnsureFileExists(PluginPath);

    if (!GetterFn(PluginPath, Out))
    {
        DefaultFn(ProjectPath);
        if (UOmegaFunctions_Config::IsInOmegaDeveloperMode())
            DefaultFn(PluginPath);
        Out = DefaultValue;
    }

    return Out;
}

// Collapses the repeated two-lambda pattern for each typed getter
#define OMEGA_CFG_GET(Type, GetMethod, SetMethod, Default)                                          \
    return L_GetValue<Type>(Section, Param, Default,                                                \
        [&](const FString& Path, Type& Out) { return GConfig->GetMethod(*Section, *Param, Out, Path); }, \
        [&](const FString& Path)            { GConfig->SetMethod(*Section, *Param, Default, Path); GConfig->Flush(false, Path); })

// ── Public Getters ────────────────────────────────────────────────────────────

bool     UOmegaFunctions_Config::GetBool  (const FString& Section, const FString& Param) { OMEGA_CFG_GET(bool,    GetBool,   SetBool,   false);     }
float    UOmegaFunctions_Config::GetFloat (const FString& Section, const FString& Param) { OMEGA_CFG_GET(float,   GetFloat,  SetFloat,  0.f);       }
int32    UOmegaFunctions_Config::GetInt   (const FString& Section, const FString& Param) { OMEGA_CFG_GET(int32,   GetInt,    SetInt,    0);         }
FString  UOmegaFunctions_Config::GetString(const FString& Section, const FString& Param) { OMEGA_CFG_GET(FString, GetString, SetString, TEXT(""));  }

FVector UOmegaFunctions_Config::GetVector(const FString& Section, const FString& Param)
{
    return FVector(
        GetFloat(Section, Param + TEXT(".X")),
        GetFloat(Section, Param + TEXT(".Y")),
        GetFloat(Section, Param + TEXT(".Z"))
    );
}

FVector2D UOmegaFunctions_Config::GetVector2D(const FString& Section, const FString& Param)
{
    return FVector2D(
        GetFloat(Section, Param + TEXT(".X")),
        GetFloat(Section, Param + TEXT(".Y"))
    );
}

// ── Core Setter ───────────────────────────────────────────────────────────────

static void L_SetValue(
    const FString& Section,
    const FString& Param,
    TFunction<void(const FString&)> SetterFn)
{
    if (!GConfig) return;

    const FString ProjectPath = UOmegaFunctions_Config::L_GetConfigPath();
    UOmegaFunctions_Config::L_EnsureFileExists(ProjectPath);
    SetterFn(ProjectPath);

    if (UOmegaFunctions_Config::IsInOmegaDeveloperMode())
    {
        const FString PluginPath = UOmegaFunctions_Config::L_GetPluginConfigPath();
        UOmegaFunctions_Config::L_EnsureFileExists(PluginPath);
        SetterFn(PluginPath);
    }
}

#define OMEGA_CFG_SET(SetMethod, Value)                                                         \
    L_SetValue(Section, Param,                                                                  \
        [&](const FString& Path) { GConfig->SetMethod(*Section, *Param, Value, Path); GConfig->Flush(false, Path); })

// ── Public Setters ────────────────────────────────────────────────────────────

void UOmegaFunctions_Config::SetBool  (const FString& Section, const FString& Param, bool Value)          { OMEGA_CFG_SET(SetBool,   Value); }
void UOmegaFunctions_Config::SetFloat (const FString& Section, const FString& Param, float Value)         { OMEGA_CFG_SET(SetFloat,  Value); }
void UOmegaFunctions_Config::SetInt   (const FString& Section, const FString& Param, int32 Value)         { OMEGA_CFG_SET(SetInt,    Value); }
void UOmegaFunctions_Config::SetString(const FString& Section, const FString& Param, const FString& Value){ OMEGA_CFG_SET(SetString, *Value); }

void UOmegaFunctions_Config::SetVector(const FString& Section, const FString& Param, FVector Value)
{
    SetFloat(Section, Param + TEXT(".X"), Value.X);
    SetFloat(Section, Param + TEXT(".Y"), Value.Y);
    SetFloat(Section, Param + TEXT(".Z"), Value.Z);
}

void UOmegaFunctions_Config::SetVector2D(const FString& Section, const FString& Param, FVector2D Value)
{
    SetFloat(Section, Param + TEXT(".X"), Value.X);
    SetFloat(Section, Param + TEXT(".Y"), Value.Y);
}