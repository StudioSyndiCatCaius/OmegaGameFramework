


#include "Statics/OMEGA_File.h"
#include "Internationalization/Culture.h"
#include "Misc/FileHelper.h"
#include "Misc/Guid.h"
#include "Misc/PackageName.h"
#include "UObject/Package.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/UObjectHash.h"

FString OMEGA_File::PathCorrect(const FString& path)
{
	FString out=path;

	out=out.Replace(TEXT("{project}"),*FPaths::ProjectDir());
	out=out.Replace(TEXT("{content}"),*FPaths::ProjectContentDir());
	out=out.Replace(TEXT("{mods}"),*FPaths::ProjectModsDir());
	out=out.Replace(TEXT("{saves}"),*FPaths::GameAgnosticSavedDir());
	out=out.Replace(TEXT("{culture}"),*FInternationalization::Get().GetCurrentCulture()->GetName());
	out=out.Replace(TEXT("//"),TEXT("/"));

	FPaths::NormalizeFilename(out);

	return out;
}

TArray<FString> OMEGA_File::ListFilesInDirectory(const FString& path, bool bRecursive)
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

TArray<FString> OMEGA_File::ListFilesInDirectoryList(TArray<FString> paths, bool bRecursive)
{
	TArray<FString> out;
	for (FString dir : paths)
	{
		out.Append(ListFilesInDirectory(dir, bRecursive));
	}
	return out;
}

TArray<FString> OMEGA_File::GetAllSubfolders(const FString& BasePath, bool bRecursive)
{

	TArray<FString> Subfolders;

	IFileManager& FileManager = IFileManager::Get();

	if (!FileManager.DirectoryExists(*BasePath))
	{
		return Subfolders;
	}

	if (bRecursive)
	{
		FileManager.IterateDirectoryRecursively(*BasePath, [&Subfolders, &BasePath](const TCHAR* FilenameOrDirectory, bool bIsDirectory) -> bool
		{
			if (bIsDirectory)
			{
				Subfolders.Add(FilenameOrDirectory);
			}
			return true; // Continue iteration
		});
	}
	else
	{
		FileManager.IterateDirectory(*BasePath, [&Subfolders](const TCHAR* FilenameOrDirectory, bool bIsDirectory) -> bool
		{
			if (bIsDirectory)
			{
				Subfolders.Add(FilenameOrDirectory);
			}
			return true; // Continue iteration
		});
	}

	return Subfolders;
}

// NOTE: In packaged builds, .uasset files must be cooked for the target platform.
// Raw editor .uasset files will not load correctly in packaged builds.
// Place cooked assets alongside the packaged game (e.g. in the Saved directory or a custom mods folder).

UObject* OMEGA_File::HotloadUasset_FromFile(const FString& filepath)
{
	// Resolve and normalize the absolute path
	FString FullPath = FPaths::ConvertRelativePathToFull(filepath);
	FPaths::NormalizeFilename(FullPath);

	if (!FPaths::FileExists(FullPath))
	{
		UE_LOG(LogTemp, Error, TEXT("HotloadUasset_FromFile: File not found: %s"), *FullPath);
		return nullptr;
	}

	FString Directory = FPaths::GetPath(FullPath);
	FString AssetName = FPaths::GetBaseFilename(FullPath); // strips .uasset

	// Build a stable virtual mount point keyed to this directory.
	// Same directory always gets the same mount so re-registering is safe.
	FString ContentPath = Directory.EndsWith(TEXT("/")) ? Directory : Directory + TEXT("/");
	uint32 DirHash = GetTypeHash(Directory.ToLower());
	FString MountRoot = FString::Printf(TEXT("/OmegaHotload_%u/"), DirHash);

	if (!FPackageName::MountPointExists(MountRoot))
	{
		FPackageName::RegisterMountPoint(MountRoot, ContentPath);
	}

	FString PackagePath = MountRoot + AssetName;

	// Reuse an already-loaded package rather than double-loading
	if (UPackage* Existing = FindPackage(nullptr, *PackagePath))
	{
		Existing->FullyLoad();
		return Existing->FindAssetInPackage();
	}

	UPackage* Package = LoadPackage(nullptr, *PackagePath, LOAD_None);
	if (!Package)
	{
		UE_LOG(LogTemp, Error, TEXT("HotloadUasset_FromFile: LoadPackage failed for %s (virtual: %s)"), *FullPath, *PackagePath);
		return nullptr;
	}

	Package->FullyLoad();

	UObject* Asset = Package->FindAssetInPackage();
	if (!Asset)
	{
		// Fallback: iterate objects in the package and return the first asset found
		ForEachObjectWithPackage(Package, [&Asset](UObject* Obj) -> bool
		{
			if (Obj && Obj->IsAsset())
			{
				Asset = Obj;
				return false; // stop iteration
			}
			return true;
		}, false);
	}

	return Asset;
}

UObject* OMEGA_File::HotloadUasset_FromBytes(TArray<uint8> byte)
{
	// Write bytes to a uniquely-named temp file, load from it, then clean up.
	// The loaded package stays resident in memory after the file is deleted.
	FString TempDir = FPaths::ProjectSavedDir() / TEXT("OmegaHotload");
	IFileManager::Get().MakeDirectory(*TempDir, true);

	FString TempFile = TempDir / (FGuid::NewGuid().ToString() + TEXT(".uasset"));

	if (!FFileHelper::SaveArrayToFile(byte, *TempFile))
	{
		UE_LOG(LogTemp, Error, TEXT("HotloadUasset_FromBytes: Failed to write temp file: %s"), *TempFile);
		return nullptr;
	}

	UObject* Result = HotloadUasset_FromFile(TempFile);

	// Remove the temp file — package data is already in memory
	IFileManager::Get().Delete(*TempFile);

	return Result;
}


