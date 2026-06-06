// Copyright Notice Here

#include "AssetActions/OmegaAA_PAL.h"
#include "Engine/PrimaryAssetLabel.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/PlatformProcess.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "ToolMenuSection.h"
#include "UObject/ObjectRedirector.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FText FMyPrimaryAssetLabelActions::GetName() const
{
	return LOCTEXT("PrimaryAssetLabelActions", "Primary Asset Label");
}

UClass* FMyPrimaryAssetLabelActions::GetSupportedClass() const
{
	return UPrimaryAssetLabel::StaticClass();
}

FColor FMyPrimaryAssetLabelActions::GetTypeColor() const
{
	return FColor(128, 200, 128);
}

uint32 FMyPrimaryAssetLabelActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void FMyPrimaryAssetLabelActions::GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section)
{
	TArray<TWeakObjectPtr<UPrimaryAssetLabel>> Labels;
	for (UObject* Obj : InObjects)
	{
		if (UPrimaryAssetLabel* Label = Cast<UPrimaryAssetLabel>(Obj))
		{
			Labels.Add(Label);
		}
	}

	if (Labels.Num() == 0)
	{
		return;
	}

	Section.AddMenuEntry(
		"CookAndPakFull",
		LOCTEXT("CookAndPakFull", "Cook & Pak (Full)"),
		LOCTEXT("CookAndPakFullTooltip", "Cook all assets and create .pak file"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateSP(this, &FMyPrimaryAssetLabelActions::ExecuteCookAndPak, Labels, false))
	);

	Section.AddMenuEntry(
		"CookAndPakIterative",
		LOCTEXT("CookAndPakIterative", "Cook & Pak (Iterative)"),
		LOCTEXT("CookAndPakIterativeTooltip", "Cook only changed assets and create .pak file (faster)"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateSP(this, &FMyPrimaryAssetLabelActions::ExecuteCookAndPak, Labels, true))
	);
}

void FMyPrimaryAssetLabelActions::ExecuteCookAndPak(TArray<TWeakObjectPtr<UPrimaryAssetLabel>> Labels, bool bIterative)
{
	UE_LOG(LogTemp, Display, TEXT("========================================"));
	UE_LOG(LogTemp, Display, TEXT("  Cook & Pak - Primary Asset Label"));
	UE_LOG(LogTemp, Display, TEXT("========================================"));
	UE_LOG(LogTemp, Display, TEXT("Mode: %s"), bIterative ? TEXT("Iterative") : TEXT("Full"));

	// Collect packages
	TSet<FName> PackageSet = CollectPackagesFromLabels(Labels);
	TArray<FName> Packages = PackageSet.Array();

	if (Packages.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No packages found in Primary Asset Labels"));
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("Found %d packages to cook"), Packages.Num());

	// Get chunk ID
	int32 ChunkId = 0;
	if (Labels.Num() > 0 && Labels[0].IsValid())
	{
		ChunkId = Labels[0].Get()->Rules.ChunkId;
	}

	if (ChunkId < 0)
	{
		ChunkId = 0;
		UE_LOG(LogTemp, Warning, TEXT("No chunk ID set, using 0"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Chunk ID: %d"), ChunkId);
	}

	// Cook
	CookPackages(Packages, bIterative);

	// Create pak
	FString PakFilename = FString::Printf(TEXT("pakchunk%d-Windows.pak"), ChunkId);
	FString OutputPath = FPaths::ProjectSavedDir() / TEXT("Omega_Pak") / PakFilename;
	
	CreatePakFile(Packages, OutputPath);

	UE_LOG(LogTemp, Display, TEXT("========================================"));
	UE_LOG(LogTemp, Display, TEXT("  Complete!"));
	UE_LOG(LogTemp, Display, TEXT("========================================"));
	UE_LOG(LogTemp, Display, TEXT("Output: %s"), *OutputPath);
	UE_LOG(LogTemp, Display, TEXT(""));
	UE_LOG(LogTemp, Display, TEXT("Copy to: {Game}/Content/Paks/%s"), *PakFilename);
}

TSet<FName> FMyPrimaryAssetLabelActions::CollectPackagesFromLabels(const TArray<TWeakObjectPtr<UPrimaryAssetLabel>>& Labels)
{
	TSet<FName> AllPackages;
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	FTopLevelAssetPath RedirectorPath = UObjectRedirector::StaticClass()->GetClassPathName();

	for (const TWeakObjectPtr<UPrimaryAssetLabel>& LabelPtr : Labels)
	{
		if (!LabelPtr.IsValid())
		{
			continue;
		}

		UPrimaryAssetLabel* Label = LabelPtr.Get();

		// Get the directory this label is in
		FString LabelPackageName = Label->GetPackage()->GetName();
		FString LabelPath = FPackageName::GetLongPackagePath(LabelPackageName);

		UE_LOG(LogTemp, Display, TEXT("Scanning directory: %s"), *LabelPath);

		// Get all assets in this directory and subdirectories
		TArray<FAssetData> AssetDataList;
		AssetRegistry.GetAssetsByPath(FName(*LabelPath), AssetDataList, true);

		UE_LOG(LogTemp, Display, TEXT("  Found %d assets in directory"), AssetDataList.Num());

		for (const FAssetData& AssetData : AssetDataList)
		{
			// Skip the label itself
			if (AssetData.AssetName == Label->GetFName())
			{
				continue;
			}

			// Skip redirectors
			if (!AssetData.AssetClassPath.IsNull() && AssetData.AssetClassPath == RedirectorPath)
			{
				continue;
			}

			// Skip if no valid class
			if (AssetData.AssetClassPath.IsNull())
			{
				continue;
			}

			AllPackages.Add(AssetData.PackageName);
		}

		// Also add explicitly assigned assets
		for (const TSoftObjectPtr<UObject>& AssetPtr : Label->ExplicitAssets)
		{
			if (!AssetPtr.IsNull())
			{
				FString AssetPath = AssetPtr.ToString();
				FString PackageName = FPackageName::ObjectPathToPackageName(AssetPath);
				AllPackages.Add(FName(*PackageName));
			}
		}

		// Also add explicitly assigned blueprints
		for (const TSoftClassPtr<UObject>& BlueprintPtr : Label->ExplicitBlueprints)
		{
			if (!BlueprintPtr.IsNull())
			{
				FString AssetPath = BlueprintPtr.ToString();
				FString PackageName = FPackageName::ObjectPathToPackageName(AssetPath);
				AllPackages.Add(FName(*PackageName));
			}
		}
	}

	UE_LOG(LogTemp, Display, TEXT("Total packages collected: %d"), AllPackages.Num());
	return AllPackages;
}

void FMyPrimaryAssetLabelActions::CookPackages(const TArray<FName>& Packages, bool bIterative)
{
	UE_LOG(LogTemp, Display, TEXT(""));
	UE_LOG(LogTemp, Display, TEXT("=== COOKING ==="));

	// Write package list
	FString PackageListPath = FPaths::ProjectSavedDir() / TEXT("Temp") / TEXT("OmegaPakCookList.txt");
	FString PackageListContent;
	for (const FName& Package : Packages)
	{
		PackageListContent += Package.ToString() + TEXT("\n");
	}

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString TempDir = FPaths::GetPath(PackageListPath);
	if (!PlatformFile.DirectoryExists(*TempDir))
	{
		PlatformFile.CreateDirectoryTree(*TempDir);
	}

	FFileHelper::SaveStringToFile(PackageListContent, *PackageListPath);
	UE_LOG(LogTemp, Log, TEXT("Package list: %s"), *PackageListPath);

	// Build cook command
	FString EditorPath = FPlatformProcess::ExecutablePath();
	FString ProjectPath = FPaths::GetProjectFilePath();
	
	FString CookArgs = FString::Printf(
		TEXT("\"%s\" -run=Cook -TargetPlatform=Windows %s -cookpackagelist=\"%s\""),
		*ProjectPath,
		bIterative ? TEXT("-iterate") : TEXT(""),
		*PackageListPath
	);

	UE_LOG(LogTemp, Display, TEXT("Starting cook..."));

	// Execute cook
	void* ReadPipe = nullptr;
	void* WritePipe = nullptr;
	FPlatformProcess::CreatePipe(ReadPipe, WritePipe);

	FProcHandle ProcHandle = FPlatformProcess::CreateProc(
		*EditorPath,
		*CookArgs,
		false, false, false,
		nullptr, 0, nullptr,
		WritePipe, ReadPipe
	);

	if (!ProcHandle.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to start cook process"));
		FPlatformProcess::ClosePipe(ReadPipe, WritePipe);
		return;
	}

	// Stream output
	FString OutputBuffer;
	while (FPlatformProcess::IsProcRunning(ProcHandle))
	{
		OutputBuffer += FPlatformProcess::ReadPipe(ReadPipe);
		TArray<FString> Lines;
		OutputBuffer.ParseIntoArrayLines(Lines, false);
		
		for (int32 i = 0; i < Lines.Num() - 1; ++i)
		{
			if (!Lines[i].IsEmpty())
			{
				UE_LOG(LogTemp, Log, TEXT("[Cook] %s"), *Lines[i]);
			}
		}
		
		OutputBuffer = Lines.Num() > 0 ? Lines.Last() : TEXT("");
		FPlatformProcess::Sleep(0.1f);
	}

	// Read remaining
	OutputBuffer += FPlatformProcess::ReadPipe(ReadPipe);
	TArray<FString> RemainingLines;
	OutputBuffer.ParseIntoArrayLines(RemainingLines);
	for (const FString& Line : RemainingLines)
	{
		if (!Line.IsEmpty())
		{
			UE_LOG(LogTemp, Log, TEXT("[Cook] %s"), *Line);
		}
	}

	int32 ReturnCode = 0;
	FPlatformProcess::GetProcReturnCode(ProcHandle, &ReturnCode);
	FPlatformProcess::CloseProc(ProcHandle);
	FPlatformProcess::ClosePipe(ReadPipe, WritePipe);

	if (ReturnCode == 0)
	{
		UE_LOG(LogTemp, Display, TEXT("Cook completed successfully"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Cook failed with code %d"), ReturnCode);
	}
}

void FMyPrimaryAssetLabelActions::CreatePakFile(const TArray<FName>& Packages, const FString& OutputPath)
{
	UE_LOG(LogTemp, Display, TEXT(""));
	UE_LOG(LogTemp, Display, TEXT("=== CREATING PAK ==="));

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Cooked files location
	FString CookedDir = FPaths::ProjectSavedDir() / TEXT("Cooked/Windows") / FApp::GetProjectName();
	FString CookedContentDir = CookedDir / TEXT("Content");
	
	UE_LOG(LogTemp, Display, TEXT("Scanning cooked directory: %s"), *CookedContentDir);
	
	// Build response file by including ALL files in the cooked Content directory
	FString ResponseContent;
	int32 FileCount = 0;

	// Get all files recursively
	TArray<FString> AllFiles;
	PlatformFile.FindFilesRecursively(AllFiles, *CookedContentDir, nullptr);

	UE_LOG(LogTemp, Display, TEXT("Found %d total files in cooked directory"), AllFiles.Num());

	// Ensure CookedContentDir has trailing slash for proper string replacement
	FString CookedContentDirWithSlash = CookedContentDir;
	if (!CookedContentDirWithSlash.EndsWith(TEXT("/")))
	{
		CookedContentDirWithSlash += TEXT("/");
	}

	for (const FString& CookedFilePath : AllFiles)
	{
		// Get relative path by removing the cooked content directory prefix
		FString RelativePath = CookedFilePath;
		if (RelativePath.StartsWith(CookedContentDirWithSlash))
		{
			RelativePath = RelativePath.RightChop(CookedContentDirWithSlash.Len());
		}
		
		// Normalize path separators to forward slashes
		RelativePath = RelativePath.Replace(TEXT("\\"), TEXT("/"));
		
		// Skip if we couldn't get a valid relative path
		if (RelativePath.IsEmpty() || RelativePath.StartsWith(TEXT("/")))
		{
			continue;
		}

		// Create mount path - Format: ../../../{ProjectName}/Content/{RelativePath}
		// This is the path where the game will look for the file
		FString MountPath = FString::Printf(TEXT("../../../%s/Content/%s"), 
			FApp::GetProjectName(), *RelativePath);

		// Add to response file
		ResponseContent += FString::Printf(TEXT("\"%s\" \"%s\"\n"), *CookedFilePath, *MountPath);
		FileCount++;
		
		// Log levels specifically so we can verify mount paths
		if (CookedFilePath.EndsWith(TEXT(".umap")))
		{
			UE_LOG(LogTemp, Display, TEXT("  Level found:"));
			UE_LOG(LogTemp, Display, TEXT("    File: %s"), *RelativePath);
			UE_LOG(LogTemp, Display, TEXT("    Mount: %s"), *MountPath);
		}
	}

	if (FileCount == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("No cooked files found!"));
		UE_LOG(LogTemp, Error, TEXT("Expected files at: %s"), *CookedContentDir);
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("Packing %d files"), FileCount);

	// Save response file
	FString ResponsePath = FPaths::ProjectSavedDir() / TEXT("Temp") / TEXT("OmegaPakResponse.txt");
	FFileHelper::SaveStringToFile(ResponseContent, *ResponsePath);
	UE_LOG(LogTemp, Log, TEXT("Response file: %s"), *ResponsePath);
	UE_LOG(LogTemp, Log, TEXT("Check this file to verify mount paths are correct!"));

	// Create output directory
	FString OutputDir = FPaths::GetPath(OutputPath);
	if (!PlatformFile.DirectoryExists(*OutputDir))
	{
		PlatformFile.CreateDirectoryTree(*OutputDir);
	}

	// Find UnrealPak
	FString UnrealPakPath = FPaths::EngineDir() / TEXT("Binaries/Win64/UnrealPak.exe");
	if (!PlatformFile.FileExists(*UnrealPakPath))
	{
		UE_LOG(LogTemp, Error, TEXT("UnrealPak.exe not found at: %s"), *UnrealPakPath);
		return;
	}

	// Run UnrealPak
	FString PakArgs = FString::Printf(
		TEXT("\"%s\" -create=\"%s\" -compress"),
		*OutputPath,
		*ResponsePath
	);

	UE_LOG(LogTemp, Display, TEXT("Running UnrealPak..."));

	int32 ReturnCode = 0;
	FString StdOut, StdErr;
	FPlatformProcess::ExecProcess(*UnrealPakPath, *PakArgs, &ReturnCode, &StdOut, &StdErr);

	if (ReturnCode == 0)
	{
		int64 FileSize = PlatformFile.FileSize(*OutputPath);
		double SizeMB = FileSize / (1024.0 * 1024.0);
		UE_LOG(LogTemp, Display, TEXT("✓ Pak created successfully: %.2f MB"), SizeMB);
		
		// Log what file types were included
		TMap<FString, int32> ExtensionCounts;
		for (const FString& File : AllFiles)
		{
			FString Extension = FPaths::GetExtension(File, true);
			ExtensionCounts.FindOrAdd(Extension)++;
		}
		
		UE_LOG(LogTemp, Display, TEXT("File types included:"));
		for (const auto& Pair : ExtensionCounts)
		{
			UE_LOG(LogTemp, Display, TEXT("  %s: %d files"), *Pair.Key, Pair.Value);
		}
		
		UE_LOG(LogTemp, Display, TEXT(""));
		UE_LOG(LogTemp, Display, TEXT("Verify pak structure with: UnrealPak.exe \"%s\" -list"), *OutputPath);
		UE_LOG(LogTemp, Display, TEXT("Should show: ../../../%s/Content/1_mod/... (NOT Content/Content/)"), FApp::GetProjectName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UnrealPak failed with code %d"), ReturnCode);
		if (!StdErr.IsEmpty())
		{
			UE_LOG(LogTemp, Error, TEXT("Error: %s"), *StdErr);
		}
	}
}

#undef LOCTEXT_NAMESPACE