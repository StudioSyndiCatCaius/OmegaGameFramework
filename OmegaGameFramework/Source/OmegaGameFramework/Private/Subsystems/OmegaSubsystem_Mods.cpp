// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_Mods.h"

#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "OmegaSettings.h"


void UOmegaModSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	if(GetMutableDefault<UOmegaSettings>()->bAutoInitializeMods)
	{
		InitializeMods();
	}
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
	for(FString TempPath : GetModListPaths(false))
	{
		UOmegaMod* NewMod = NewObject<UOmegaMod>(this, GetModClass());
		NewMod->ModStringData=TempPath+"mod.lua";
		ModList.Add(NewMod);

		NewMod->OnModInitialized(TempPath+"mod.lua");
		
		FString raw_path;
	}
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
	return ModList;
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
