// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Subsystems/OmegaSubsystem_Mods.h"

#include "Subsystems/OmegaSubsystem_GameManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"


void UOmegaModSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	/*
	// Activate the mod manager module
	const TSubclassOf<UOmegaModManager> ManagerClass = GetMutableDefault<UOmegaModSettings>()->GetOmegaModManagerClass();
	ModManager = Cast<UOmegaModManager>(GetGameInstance()->GetSubsystem<UOmegaGameManager>()->ActivateModuleFromClass(ManagerClass));
*/
	if(ModManager)
	{
		for(FString TempPath : GetModListPaths())
		{
			/*
			FString ModFileContent;
			FFileHelper::LoadFileToString(ModFileContent, *TempPath);
			*/
			UOmegaMod* NewMod = NewObject<UOmegaMod>(this, UOmegaMod::StaticClass());
			NewMod->ModStringData=TempPath;
			ModManager->OnModInitialized(NewMod);
			
			ModList.Add(NewMod);

			/*
			// CREATE MOD
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ModFileContent);

			if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
			{
				
			}
			*/
		}
	}
}

void UOmegaModSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

TArray<FString> UOmegaModSubsystem::GetModListPaths()
{
	TArray<FString> FileNames;
	IFileManager & FileManager = IFileManager::Get();
	
	TArray<FString> relativeFileNames;

	FileManager.FindFiles(relativeFileNames,*(GetModsDirectory() + FGenericPlatformMisc::GetDefaultPathSeparator() + TEXT("*")),false,true);
	
	for (FString fileName : relativeFileNames)
	{
		//FString ModTypeExtension = ModManager->GetModFiletype();
		FString ModTypeExtension = ".lua";
		FileNames.Add(GetModsDirectory() + FGenericPlatformMisc::GetDefaultPathSeparator() + fileName  + FGenericPlatformMisc::GetDefaultPathSeparator() + fileName + "." + ModTypeExtension);
	}
	
	return FileNames;
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
		if(TempMod && ModManager->OnGetModActive(TempMod))
		{
			OutMods.Add(TempMod);
		}
	}
	
	return GetInstalledMods();
}

void UOmegaModSubsystem::SetModActive(UOmegaMod* Mod, bool IsActive)
{
	ModManager->OnSetModActive(Mod,IsActive);
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
