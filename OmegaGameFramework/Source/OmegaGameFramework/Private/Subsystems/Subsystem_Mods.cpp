// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/Subsystem_Mods.h"

#include "LuaBlueprintFunctionLibrary.h"
#include "Subsystems/Subsystem_GameManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "OmegaSettings.h"
#include "Misc/OmegaUtils_Methods.h"


void UOmegaModSubsystem::Init_Mods(UOmegaGameManager* outer)
{
	OGF_Log::Info(" ---- INITIALIZTING OMEGA MODS ----");
	if (TSubclassOf<UOmegaMod> mod_class=GetModClass())
	{
		for(FString TempPath : GetModListPaths(false))
		{
			UOmegaMod* NewMod = NewObject<UOmegaMod>(outer, mod_class);
			FString lua_mod_path=TempPath+"mod.lua";
			NewMod->ModStringData=lua_mod_path;
			NewMod->LuaValue=ULuaBlueprintFunctionLibrary::LuaRunNonContentFile(outer,nullptr,lua_mod_path,false);
			
			NewMod->OnModInitialized(lua_mod_path);
			outer->ModList.Add(NewMod);
			OGF_Log::Info("			CREATED MOD: "+TempPath);	
			
			FString raw_path;
		}
	}
}

void UOmegaModSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	if(GetMutableDefault<UOmegaSettings>()->bAutoInitializeMods)
	{
		//InitializeMods();
	}
	
	mods_initialized=true;
}

void UOmegaModSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

TSubclassOf<UOmegaMod> UOmegaModSubsystem::GetModClass()
{
	if(const TSubclassOf<UOmegaMod> mod_class = GetMutableDefault<UOmegaSettings>()->ModClass.TryLoadClass<UOmegaMod>())
	{
		return mod_class;
	}
	return UOmegaMod::StaticClass();
}

void UOmegaModSubsystem::InitializeMods()
{
	Init_Mods(GetGameInstance()->GetSubsystem<UOmegaGameManager>());
}

TArray<FString> UOmegaModSubsystem::GetModListPaths(bool IncludeBaseOverride)
{
	TArray<FString> FileNames;
	IFileManager & FileManager = IFileManager::Get();
	TArray<FString> relativeFileNames;

	FileManager.FindFiles(relativeFileNames,*(GetModsDirectory() + FGenericPlatformMisc::GetDefaultPathSeparator() + TEXT("*")),false,true);
	
	for (FString fileName : relativeFileNames)
	{
		FString ModTypeExtension = "lua";
		FileNames.Add(GetModsDirectory() + FGenericPlatformMisc::GetDefaultPathSeparator() + fileName  + FGenericPlatformMisc::GetDefaultPathSeparator());// + "mod." + ModTypeExtension);
	}
	if(IncludeBaseOverride)
	{
		FileNames.Add(FPaths::ProjectDir()+"Override/");
	}
	
	return FileNames;
}

TArray<FString> UOmegaModSubsystem::GetModAssetFile(const FString& filename, bool IncludeBaseOverride)
{
	TArray<FString> out;
	TArray<FString> file;
	for(FString str : GetModListPaths(IncludeBaseOverride))
	{
		IFileManager::Get().FindFiles(file,*(str+filename),true,false);
		for(FString to : file)
		{
			out.AddUnique(str+to);
		}
	}

	return out;
}

FString UOmegaModSubsystem::GetModsDirectory()
{
	return FPaths::ProjectModsDir();
}

TArray<UOmegaMod*> UOmegaModSubsystem::GetInstalledMods()
{
	return GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ModList;
}

TArray<UOmegaMod*> UOmegaModSubsystem::GetActiveMods()
{
	TArray<UOmegaMod*> OutMods;
	for(auto* TempMod : GetInstalledMods())
	{
		if(TempMod && TempMod->Get_IsModActive())
		{
			OutMods.Add(TempMod);
		}
	}
	
	return GetInstalledMods();
}

void UOmegaModSubsystem::SetModActive(UOmegaMod* Mod, bool IsActive)
{
	Mod->Set_IsModActive(IsActive);
}

// ================================================================================================================
// MOD Object
// ================================================================================================================

UOmegaMod::UOmegaMod(const FObjectInitializer& ObjectInitializer)
{
	if (const UObject* Owner = GetOuter()) { WorldPrivate = Owner->GetWorld(); }
}

UWorld* UOmegaMod::GetWorld() const
{
	if(WorldPrivate) { return WorldPrivate; }
	if(GetGameInstance()) { return GetGameInstance()->GetWorld(); }
	return nullptr;
}

UGameInstance* UOmegaMod::GetGameInstance() const
{
	return GameInstanceRef;
}

void UOmegaMod::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
                                                  FText& Description)
{
	Name = ModName;
	Description = ModDescription;
}

void UOmegaMod::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture,
	UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush = ModThumbnail;
}
