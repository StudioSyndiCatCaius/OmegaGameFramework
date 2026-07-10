// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Subsystems/Subsystem_Save.h"
#include "F_SaveAsync.generated.h"


// =====================================================================================================================
// Save Active Game To Path
// =====================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncSaveDelegate, bool, bSuccess);

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAsyncAction_SaveGameToPath : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Omega") FAsyncSaveDelegate OnSuccess;
	UPROPERTY(BlueprintAssignable, Category="Omega") FAsyncSaveDelegate OnFail;

	UPROPERTY() UOmegaSaveGame* LocalSaveGame = nullptr;
	UPROPERTY() FString LocalFilePath;
	UPROPERTY() UObject* LocalWorldContext = nullptr;

	virtual void Activate() override;

	// Saves the given OmegaSaveGame to a full file path (e.g. "C:/MySaves/slot1.sav").
	// Calls WriteSaveDataToActive() so level name, player transform, and all game data are captured first.
	// A screenshot is written alongside the file as <name>.png.
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly, WorldContext="WorldContextObject"),
		Category="Omega|Save|Custom", DisplayName="💾 Save OmegaGame To Path (Async)")
	static UAsyncAction_SaveGameToPath* SaveOmegaGameToPath(UObject* WorldContextObject,
		UOmegaSaveGame* SaveGame, const FString& FilePath);
};


// =====================================================================================================================
// Load OmegaSaveGame From Path
// =====================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncOmegaLoadDelegate, UOmegaSaveGame*, SaveGame);

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAsyncAction_LoadOmegaGameFromPath : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Omega") FAsyncOmegaLoadDelegate OnSuccess;
	UPROPERTY(BlueprintAssignable, Category="Omega") FAsyncOmegaLoadDelegate OnFail;

	UPROPERTY() FString LocalFilePath;
	UPROPERTY() TSubclassOf<UOmegaSaveGame> LocalClass;

	virtual void Activate() override;

	// Loads a .sav file from any absolute path and returns it as UOmegaSaveGame.
	// Optionally filter by subclass via Class (leave None to accept any UOmegaSaveGame).
	// Sets FilePath on the result and loads the companion screenshot (<name>.png) into SaveScreenshot.
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly),
		Category="Omega|Save|Custom", DisplayName="💾 Load OmegaGame From Path (Async)")
	static UAsyncAction_LoadOmegaGameFromPath* LoadOmegaGameFromPath(const FString& FilePath,
		TSubclassOf<UOmegaSaveGame> Class);
};


// =====================================================================================================================
// Load All OmegaSaveGames In Path
// =====================================================================================================================

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncOmegaLoadAllDelegate, const TArray<UOmegaSaveGame*>&, SaveGames);

UCLASS()
class OMEGAGAMEFRAMEWORK_API UAsyncAction_LoadAllOmegaGamesInPath : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Omega") FAsyncOmegaLoadAllDelegate OnSuccess;
	UPROPERTY(BlueprintAssignable, Category="Omega") FAsyncOmegaLoadAllDelegate OnFail;

	UPROPERTY() FString LocalDirectoryPath;
	UPROPERTY() TSubclassOf<UOmegaSaveGame> LocalClass;
	UPROPERTY() bool bLocalRecursive = false;

	virtual void Activate() override;

	// Scans a directory for .sav files, loads each as UOmegaSaveGame, and optionally filters by subclass.
	// Sets FilePath and loads the companion screenshot on every result.
	// OnSuccess fires when at least one valid save is found; OnFail fires when none are found.
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly),
		Category="Omega|Save|Custom", DisplayName="💾 Load All OmegaGames In Path (Async)")
	static UAsyncAction_LoadAllOmegaGamesInPath* LoadAllOmegaGamesInPath(const FString& DirectoryPath,
		TSubclassOf<UOmegaSaveGame> Class, bool bRecursive);
};
