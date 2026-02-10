// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "UObject/SoftObjectPath.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "F_Process.generated.h"

USTRUCT(BlueprintType)
struct FPlatformProcessHandle
{
	GENERATED_BODY()

	// Use a shared pointer to wrap FProcHandle since it can't be default-initialized
	TSharedPtr<FProcHandle> ProcessHandle;
    
	FPlatformProcessHandle()
		: ProcessHandle(nullptr)
	{}

	bool IsValid() const
	{
		return ProcessHandle.IsValid() && ProcessHandle->IsValid();
	}
};


UCLASS()
class UOmegaFunctions_Process : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
     /**
     * Launches an external executable with optional command line arguments
     * @param ExecutablePath - Full path to the .exe or .bat file
     * @param CommandLineArgs - Optional array of command line arguments
     * @param bLaunchDetached - If true, process runs independently and cannot be monitored
     * @param bLaunchHidden - If true, launches without showing a window
     * @param ProcessHandle - Output handle to the process (only valid if bLaunchDetached is false)
     * @return True if the process was launched successfully
     */
    UFUNCTION(BlueprintCallable, Category = "External Process")
    static bool LaunchExternalProcess(
        const FString& ExecutablePath,
        const TArray<FString>& CommandLineArgs,
        bool bLaunchDetached,
        bool bLaunchHidden,
        FPlatformProcessHandle& ProcessHandle);

    /**
     * Check if a process is still running
     * @param ProcessHandle - Handle to the process
     * @return True if the process is still running
     */
    UFUNCTION(BlueprintPure, Category = "External Process")
    static bool IsProcessRunning(const FPlatformProcessHandle& ProcessHandle);

    /**
     * Terminate a running process
     * @param ProcessHandle - Handle to the process to terminate
     * @param bKillTree - If true, kills all child processes as well
     * @return True if the process was terminated successfully
     */
    UFUNCTION(BlueprintCallable, Category = "External Process")
    static bool TerminateProcess(const FPlatformProcessHandle& ProcessHandle, bool bKillTree = false);

    /**
     * Get the return code of a finished process (non-blocking)
     * @param ProcessHandle - Handle to the process
     * @param ReturnCode - Output return code
     * @return True if the process has finished and return code was retrieved
     */
    UFUNCTION(BlueprintCallable, Category = "External Process")
    static bool GetProcessReturnCode(const FPlatformProcessHandle& ProcessHandle, int32& ReturnCode);

    /**
     * Close the process handle (doesn't terminate the process, just releases the handle)
     * @param ProcessHandle - Handle to close
     */
    UFUNCTION(BlueprintCallable, Category = "External Process")
    static void CloseProcessHandle(UPARAM(ref) FPlatformProcessHandle& ProcessHandle);

    /**
     * Check if a process handle is valid
     * @param ProcessHandle - Handle to check
     * @return True if the handle is valid
     */
    UFUNCTION(BlueprintPure, Category = "External Process")
    static bool IsProcessHandleValid(const FPlatformProcessHandle& ProcessHandle);

private:
    /**
     * Helper function to convert array of arguments to a single command line string
     * Handles proper quoting for arguments with spaces
     */
    static FString BuildCommandLineString(const TArray<FString>& Args);
	
};


