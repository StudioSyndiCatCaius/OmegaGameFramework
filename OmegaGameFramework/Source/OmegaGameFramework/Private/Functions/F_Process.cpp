// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Functions/F_Process.h"// In your source file (.cpp)
#include "Misc/Paths.h"

FString UOmegaFunctions_Process::BuildCommandLineString(const TArray<FString>& Args)
{
    if (Args.Num() == 0)
    {
        return FString();
    }

    TArray<FString> QuotedArgs;
    QuotedArgs.Reserve(Args.Num());

    for (const FString& Arg : Args)
    {
        // Check if the argument contains spaces or special characters
        if (Arg.Contains(TEXT(" ")) || Arg.Contains(TEXT("\t")))
        {
            // Wrap in quotes if it contains spaces
            QuotedArgs.Add(FString::Printf(TEXT("\"%s\""), *Arg));
        }
        else
        {
            QuotedArgs.Add(Arg);
        }
    }

    // Join all arguments with spaces
    return FString::Join(QuotedArgs, TEXT(" "));
}

bool UOmegaFunctions_Process::LaunchExternalProcess(
    const FString& ExecutablePath,
    const TArray<FString>& CommandLineArgs,
    bool bLaunchDetached,
    bool bLaunchHidden,
    FPlatformProcessHandle& ProcessHandle)
{
    // Verify the file exists
    if (!FPaths::FileExists(ExecutablePath))
    {
        UE_LOG(LogTemp, Error, TEXT("File not found: %s"), *ExecutablePath);
        return false;
    }

    FString FinalExecutable = ExecutablePath;
    FString FinalArgs = BuildCommandLineString(CommandLineArgs);
    FString WorkingDirectory = FPaths::GetPath(ExecutablePath);

    // Check if this is a .bat file
    FString Extension = FPaths::GetExtension(ExecutablePath).ToLower();
    if (Extension == TEXT("bat") || Extension == TEXT("cmd"))
    {
        // For batch files, we need to launch through cmd.exe
        FinalExecutable = TEXT("cmd.exe");
        
        // /c executes the command and terminates
        // Wrap the batch file path in quotes in case it has spaces
        FinalArgs = FString::Printf(TEXT("/c \"%s\" %s"), *ExecutablePath, *FinalArgs);
        
        UE_LOG(LogTemp, Log, TEXT("Launching batch file via cmd.exe: %s"), *FinalArgs);
    }

    uint32 ProcessID = 0;
    FProcHandle Handle = FPlatformProcess::CreateProc(
        *FinalExecutable,
        *FinalArgs,
        bLaunchDetached,
        bLaunchHidden,
        bLaunchHidden,
        &ProcessID,
        0, // Priority (0 = normal)
        *WorkingDirectory,
        nullptr
    );

    if (Handle.IsValid())
    {
        UE_LOG(LogTemp, Log, TEXT("Successfully launched process: %s (PID: %d)"), *ExecutablePath, ProcessID);
        ProcessHandle.ProcessHandle = MakeShared<FProcHandle>(Handle);
        return true;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to launch process: %s"), *ExecutablePath);
        return false;
    }
}

bool UOmegaFunctions_Process::IsProcessRunning(const FPlatformProcessHandle& ProcessHandle)
{
    if (!ProcessHandle.IsValid())
    {
        return false;
    }
    
    return FPlatformProcess::IsProcRunning(*ProcessHandle.ProcessHandle);
}

bool UOmegaFunctions_Process::TerminateProcess(const FPlatformProcessHandle& ProcessHandle, bool bKillTree)
{
    if (!ProcessHandle.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot terminate process: Invalid handle"));
        return false;
    }
    
    FPlatformProcess::TerminateProc(*ProcessHandle.ProcessHandle, bKillTree);
    return true;
}

bool UOmegaFunctions_Process::GetProcessReturnCode(const FPlatformProcessHandle& ProcessHandle, int32& ReturnCode)
{
    if (!ProcessHandle.IsValid())
    {
        return false;
    }
    
    return FPlatformProcess::GetProcReturnCode(*ProcessHandle.ProcessHandle, &ReturnCode);
}

void UOmegaFunctions_Process::CloseProcessHandle(FPlatformProcessHandle& ProcessHandle)
{
    if (ProcessHandle.IsValid())
    {
        FPlatformProcess::CloseProc(*ProcessHandle.ProcessHandle);
        ProcessHandle.ProcessHandle.Reset();
    }
}

bool UOmegaFunctions_Process::IsProcessHandleValid(const FPlatformProcessHandle& ProcessHandle)
{
    return ProcessHandle.IsValid();
}