// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_SaveAsync.h"

#include "Misc/OmegaUtils_Methods.h"
#include "Statics/OMEGA_File.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Async/Async.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"
#include "ImageUtils.h"


// =====================================================================================================================
// Helpers
// =====================================================================================================================

// Derives the screenshot path from a .sav file path by replacing the extension with .png.
static FString GetScreenshotPath(const FString& SaveFilePath)
{
	return FPaths::ChangeExtension(SaveFilePath, TEXT("png"));
}

// Loads a companion .png screenshot from disk and returns it as a UTexture2D (must run on game thread).
static UTexture2D* LoadScreenshot(const FString& SaveFilePath)
{
	const FString PngPath = GetScreenshotPath(SaveFilePath);
	if (FPaths::FileExists(PngPath))
	{
		return FImageUtils::ImportFileAsTexture2D(PngPath);
	}
	return nullptr;
}

// Applies FilePath and screenshot to a freshly loaded OmegaSaveGame (game thread).
static void FinalizeLoadedGame(UOmegaSaveGame* Game, const FString& FilePath)
{
	Game->FilePath = FilePath;
	Game->SaveScreenshot = LoadScreenshot(FilePath);
}


// =====================================================================================================================
// Save Active Game To Path
// =====================================================================================================================

UAsyncAction_SaveGameToPath* UAsyncAction_SaveGameToPath::SaveOmegaGameToPath(UObject* WorldContextObject,
	UOmegaSaveGame* SaveGame, const FString& FilePath)
{
	UAsyncAction_SaveGameToPath* Node = NewObject<UAsyncAction_SaveGameToPath>();
	Node->LocalWorldContext = WorldContextObject;
	Node->LocalSaveGame = SaveGame;
	Node->LocalFilePath = FilePath;
	return Node;
}

void UAsyncAction_SaveGameToPath::Activate()
{
	Super::Activate();

	if (!LocalSaveGame || LocalFilePath.IsEmpty() || !LocalWorldContext)
	{
		OnFail.Broadcast(false);
		SetReadyToDestroy();
		return;
	}

	// Set FilePath before calling WriteSaveDataToActive so the subsystem writes the
	// screenshot to the correct path alongside this file.
	LocalSaveGame->FilePath = LocalFilePath;

	// Ensure the target directory exists.
	IFileManager::Get().MakeDirectory(*FPaths::GetPath(LocalFilePath), true);

	// Pull level/player/module data into ActiveSaveData and capture the screenshot.
	// WriteSaveDataToActive reads FilePath off ActiveSaveData for the screenshot destination,
	// so this works correctly when LocalSaveGame == ActiveSaveData (the typical case).
	UOmegaSaveSubsystem* SaveSS = OGF_Subsystems::oSave(LocalWorldContext);
	if (SaveSS)
	{
		SaveSS->WriteSaveDataToActive();
	}

	// --- Serialize on a background thread ---
	TArray<uint8> SaveData;
	if (!UGameplayStatics::SaveGameToMemory(LocalSaveGame, SaveData))
	{
		OnFail.Broadcast(false);
		SetReadyToDestroy();
		return;
	}

	TWeakObjectPtr<UAsyncAction_SaveGameToPath> WeakThis(this);
	FString PathCopy = LocalFilePath;

	SaveSS->OnAsyncSaveStateChange.Broadcast(LocalSaveGame,true);

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis, SaveData, PathCopy]()
	{
		const bool bSaved = FFileHelper::SaveArrayToFile(SaveData, *PathCopy);

		AsyncTask(ENamedThreads::GameThread, [WeakThis, bSaved]()
		{
			if (WeakThis.IsValid())
			{
				if (bSaved) { WeakThis->OnSuccess.Broadcast(true); }
				else        { WeakThis->OnFail.Broadcast(false); }

				if (UOmegaSaveSubsystem* SaveSS = OGF_Subsystems::oSave(WeakThis.Get()))
				{
					SaveSS->OnAsyncSaveStateChange.Broadcast(SaveSS->ActiveSaveData,false);
				}

				WeakThis->SetReadyToDestroy();
			}
		});
	});
}


// =====================================================================================================================
// Load OmegaSaveGame From Path
// =====================================================================================================================

UAsyncAction_LoadOmegaGameFromPath* UAsyncAction_LoadOmegaGameFromPath::LoadOmegaGameFromPath(
	const FString& FilePath, TSubclassOf<UOmegaSaveGame> Class)
{
	UAsyncAction_LoadOmegaGameFromPath* Node = NewObject<UAsyncAction_LoadOmegaGameFromPath>();
	Node->LocalFilePath = FilePath;
	Node->LocalClass = Class;
	return Node;
}

void UAsyncAction_LoadOmegaGameFromPath::Activate()
{
	Super::Activate();

	if (LocalFilePath.IsEmpty() || !FPaths::FileExists(LocalFilePath))
	{
		OnFail.Broadcast(nullptr);
		SetReadyToDestroy();
		return;
	}

	TWeakObjectPtr<UAsyncAction_LoadOmegaGameFromPath> WeakThis(this);
	FString PathCopy = LocalFilePath;
	TSubclassOf<UOmegaSaveGame> ClassCopy = LocalClass;

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis, PathCopy, ClassCopy]()
	{
		TArray<uint8> SaveData;
		const bool bLoaded = FFileHelper::LoadFileToArray(SaveData, *PathCopy);

		AsyncTask(ENamedThreads::GameThread, [WeakThis, SaveData, bLoaded, PathCopy, ClassCopy]()
		{
			if (!WeakThis.IsValid()) { return; }

			if (!bLoaded || SaveData.Num() == 0)
			{
				WeakThis->OnFail.Broadcast(nullptr);
				WeakThis->SetReadyToDestroy();
				return;
			}

			USaveGame* RawSave = UGameplayStatics::LoadGameFromMemory(SaveData);
			UOmegaSaveGame* Result = Cast<UOmegaSaveGame>(RawSave);

			if (!Result)
			{
				WeakThis->OnFail.Broadcast(nullptr);
				WeakThis->SetReadyToDestroy();
				return;
			}

			if (ClassCopy && !Result->GetClass()->IsChildOf(ClassCopy))
			{
				WeakThis->OnFail.Broadcast(nullptr);
				WeakThis->SetReadyToDestroy();
				return;
			}

			FinalizeLoadedGame(Result, PathCopy);
			WeakThis->OnSuccess.Broadcast(Result);
			WeakThis->SetReadyToDestroy();
		});
	});
}


// =====================================================================================================================
// Load All OmegaSaveGames In Path
// =====================================================================================================================

UAsyncAction_LoadAllOmegaGamesInPath* UAsyncAction_LoadAllOmegaGamesInPath::LoadAllOmegaGamesInPath(
	const FString& DirectoryPath, TSubclassOf<UOmegaSaveGame> Class, bool bRecursive)
{
	UAsyncAction_LoadAllOmegaGamesInPath* Node = NewObject<UAsyncAction_LoadAllOmegaGamesInPath>();
	Node->LocalDirectoryPath = DirectoryPath;
	Node->LocalClass = Class;
	Node->bLocalRecursive = bRecursive;
	return Node;
}

void UAsyncAction_LoadAllOmegaGamesInPath::Activate()
{
	Super::Activate();

	if (LocalDirectoryPath.IsEmpty())
	{
		OnFail.Broadcast({});
		SetReadyToDestroy();
		return;
	}

	TWeakObjectPtr<UAsyncAction_LoadAllOmegaGamesInPath> WeakThis(this);
	FString DirCopy = LocalDirectoryPath;
	TSubclassOf<UOmegaSaveGame> ClassCopy = LocalClass;
	bool bRecursiveCopy = bLocalRecursive;

	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [WeakThis, DirCopy, ClassCopy, bRecursiveCopy]()
	{
		// Collect raw file bytes + their full paths on the background thread.
		TArray<FString> Files = OMEGA_File::ListFilesInDirectory(DirCopy, bRecursiveCopy);

		// FindFiles (non-recursive) returns bare filenames; FindFilesRecursive returns full paths.
		struct FFileEntry { FString FullPath; TArray<uint8> Data; };
		TArray<FFileEntry> Loaded;

		for (const FString& File : Files)
		{
			if (FPaths::GetExtension(File) != TEXT("sav")) { continue; }

			const FString FullPath = FPaths::IsRelative(File) ? (DirCopy / File) : File;
			TArray<uint8> SaveData;
			if (FFileHelper::LoadFileToArray(SaveData, *FullPath) && SaveData.Num() > 0)
			{
				Loaded.Add({ FullPath, MoveTemp(SaveData) });
			}
		}

		AsyncTask(ENamedThreads::GameThread, [WeakThis, Loaded, ClassCopy]()
		{
			if (!WeakThis.IsValid()) { return; }

			TArray<UOmegaSaveGame*> Results;
			for (const auto& Entry : Loaded)
			{
				USaveGame* RawSave = UGameplayStatics::LoadGameFromMemory(Entry.Data);
				UOmegaSaveGame* Game = Cast<UOmegaSaveGame>(RawSave);
				if (!Game) { continue; }
				if (ClassCopy && !Game->GetClass()->IsChildOf(ClassCopy)) { continue; }

				FinalizeLoadedGame(Game, Entry.FullPath);
				Results.Add(Game);
			}

			if (Results.Num() > 0) { WeakThis->OnSuccess.Broadcast(Results); }
			else                   { WeakThis->OnFail.Broadcast(Results); }
			WeakThis->SetReadyToDestroy();
		});
	});
}
