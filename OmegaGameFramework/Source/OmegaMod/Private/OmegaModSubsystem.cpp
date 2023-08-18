// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "OmegaModSubsystem.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"


void UOmegaModSubsystem::Initialize(FSubsystemCollectionBase& Colection)
{
	// Directory Search

	for(FString TempPath : GetModListPaths())
	{
		FString ModFileContent;
		FFileHelper::LoadFileToString(ModFileContent, *TempPath);
		
		// CREATE MOD
		

		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ModFileContent);

		if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
		{
			UOmegaMod* NewMod = NewObject<UOmegaMod>(this, UOmegaMod::StaticClass());
			// Access properties from the JSON object
			NewMod->ModName = FText::FromString(JsonObject->GetStringField("Name"));
			NewMod->ModDescription = FText::FromString(JsonObject->GetStringField("Description"));
			
			// Print the values
			//UE_LOG(LogTemp, Log, TEXT("Name: %s"), *Name);
			//UE_LOG(LogTemp, Log, TEXT("Age: %d"), Age);
			//UE_LOG(LogTemp, Log, TEXT("Is Student: %s"), bIsStudent ? TEXT("true") : TEXT("false"));
			
			ModList.Add(NewMod);
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
		FileNames.Add(GetModsDirectory() + FGenericPlatformMisc::GetDefaultPathSeparator() + fileName  + FGenericPlatformMisc::GetDefaultPathSeparator() + fileName + ".json");
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
	return GetInstalledMods();
}

void UOmegaModSubsystem::SetModActive(UOmegaMod* Mod, bool IsActive)
{
	
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
