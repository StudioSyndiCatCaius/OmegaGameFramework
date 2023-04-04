// Copyright Incanta Games 2020. All Rights Reserved.

#include "FileSDKBPLibrary.h"

UFileSDKBPLibrary::UFileSDKBPLibrary(
  const FObjectInitializer& ObjectInitializer
) : Super(ObjectInitializer) {
  //
}

UFileSDKFileReader * UFileSDKBPLibrary::OpenFileReader(
  FString FileName
) {
  UFileSDKFileReader * fileReader = NewObject<UFileSDKFileReader>();
  fileReader->OpenFile(FileName);
  return fileReader;
}

void UFileSDKBPLibrary::CreateFile(
  FString FileName,
  bool ClearContentsIfExists,
  bool CreateDirectoryTree
) {
  IPlatformFile & PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

  FString directoryName = FPaths::GetPath(FileName);
  bool directoryExists = PlatformFile.DirectoryExists(*directoryName);

  if (!directoryExists && CreateDirectoryTree) {
    FFileManagerGeneric::Get().MakeDirectory(*directoryName, true);
  } else if (!directoryExists) {
    UE_LOG(
      LogFileSDK,
      Fatal,
      TEXT("Cannot create file %s because directory %s doesn't exist. Ensure the directory exists before or enable 'CreateDirectoryTree'"),
      *FileName,
      *directoryName
    );
  }

  bool fileExists = PlatformFile.FileExists(*FileName);

  if ((ClearContentsIfExists && fileExists) || !fileExists) {
    FFileHelper::SaveStringToFile(FString(), *FileName);
  }
}

bool UFileSDKBPLibrary::DeleteFile(FString FileName) {
  IPlatformFile & PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

  if (PlatformFile.FileExists(*FileName)) {
    return FFileManagerGeneric::Get().Delete(*FileName);
  } else {
    return false;
  }
}

bool UFileSDKBPLibrary::CreateDirectory(
  FString DirectoryName,
  bool CreateDirectoryTree
) {
  return FFileManagerGeneric::Get().MakeDirectory(*DirectoryName, CreateDirectoryTree);
}

bool UFileSDKBPLibrary::DeleteDirectory(
  FString DirectoryName,
  bool Recursive
) {
  return FFileManagerGeneric::Get().DeleteDirectory(*DirectoryName, false, Recursive);
}

bool UFileSDKBPLibrary::RenameFileOrDirectory(
  FString Source,
  FString Destination
) {
  IPlatformFile & PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

  return PlatformFile.MoveFile(*Destination, *Source);
}

bool UFileSDKBPLibrary::CopyFile(
  FString Source,
  FString Destination,
  const FFileSDKCopyDelegate & ProgressCallback,
  FFileSDKDelegatePreInfo PreInfo,
  int ChunkSizeInKilobytes,
  bool OverwriteDestination
) {
  IPlatformFile & PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

  const int64 MaxBufferSize = ChunkSizeInKilobytes * 1024;

  // Note, the below code is mostly copied from the
  // engine's GenericPlatformFile.cpp source file

  if (PlatformFile.FileExists(*Destination) && !OverwriteDestination) {
    return false;
  }

  TUniquePtr<IFileHandle> FromFile(PlatformFile.OpenRead(*Source, false));
  if (!FromFile) {
    return false;
  }

  TUniquePtr<IFileHandle> ToFile(PlatformFile.OpenWrite(*Destination, false, false));
  if (!ToFile) {
    return false;
  }

  int64 Size = FromFile->Size();
  int totalSizeKb = FMath::DivideAndRoundUp(Size, int64(1000));
  if (Size < 1) {
    check(Size == 0);
    return true;
  }

  int64 AllocSize = FMath::Min<int64>(MaxBufferSize, Size);
  check(AllocSize);

  uint8* Buffer = (uint8*)FMemory::Malloc(int32(AllocSize));
  check(Buffer);

  while (Size) {
    int64 ThisSize = FMath::Min<int64>(AllocSize, Size);
    FromFile->Read(Buffer, ThisSize);
    ToFile->Write(Buffer, ThisSize);
    Size -= ThisSize;
    ProgressCallback.ExecuteIfBound(
      PreInfo.PriorWritten + totalSizeKb - FMath::DivideAndRoundUp(Size, int64(1000)),
      PreInfo.TotalSize > 0 ? PreInfo.TotalSize : totalSizeKb
    );
    check(Size >= 0);
  }

  FMemory::Free(Buffer);

#if PLATFORM_MAC || PLATFORM_IOS
  // Copied from ApplePlatformFile.cpp which has this extra implementation
  // copied the contents of ApplePlatformFile::Stat since it's a private method
  // hacky, but it does the job. the original code hasn't changed in 7 years.
  // also using FPaths::NormalizeFilename since it's the exact same as
  // ApplePlatformFile::NormalizeFilename (which is protected)

  struct stat FileInfo;
  FString normalizedSource(Source);
  FString normalizedDestination(Destination);

  FPaths::NormalizeFilename(normalizedSource);
  FPaths::NormalizeFilename(normalizedDestination);

  if (stat(TCHAR_TO_UTF8(*normalizedSource), &FileInfo) == 0) {
    FileInfo.st_mode |= S_IWUSR;

    chmod(TCHAR_TO_UTF8(*normalizedDestination), FileInfo.st_mode);
  }
#endif

  return true;
}

void UFileSDKBPLibrary::CopyFileAsync(
  FString Source,
  FString Destination,
  const FFileSDKCopyDelegate & ProgressCallback,
  FFileSDKDelegatePreInfo PreInfo,
  int ChunkSizeInKilobytes
) {
  FFunctionGraphTask::CreateAndDispatchWhenReady(
    [=] {
      UFileSDKBPLibrary::CopyFile(
        Source,
        Destination,
        ProgressCallback,
        PreInfo,
        ChunkSizeInKilobytes
      );
    },
    TStatId(),
    nullptr,
    ENamedThreads::AnyThread
  );
}

bool UFileSDKBPLibrary::CopyDirectory(
  FString Source,
  FString Destination,
  const FFileSDKCopyDelegate & ProgressCallback,
  bool OverwriteDestination,
  int ChunkSizeInKilobytes
) {
  IPlatformFile & PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

  // Note, the below code is mostly copied from the
  // engine's GenericPlatformFile.cpp source file

  check(*Destination);
  check(*Source);

  FString DestDir(Destination);
  FPaths::NormalizeDirectoryName(DestDir);

  FString SourceDir(Source);
  FPaths::NormalizeDirectoryName(SourceDir);

  // Does Source dir exist?
  if (!PlatformFile.DirectoryExists(*SourceDir)) {
    return false;
  }

  // Destination directory exists already or can be created ?
  if (
    !PlatformFile.DirectoryExists(*DestDir) &&
    !PlatformFile.CreateDirectory(*DestDir)
  ) {
    return false;
  }

  // Get total size
  struct FStatFilesAndDirs : public IPlatformFile::FDirectoryStatVisitor {
    IPlatformFile & PlatformFile;
    int64 TotalFileSize;

    FStatFilesAndDirs(IPlatformFile& InPlatformFile)
      : PlatformFile(InPlatformFile)
      , TotalFileSize(0) {
    }

    virtual bool Visit(const TCHAR* FilenameOrDirectory, const FFileStatData& StatData) {
      if (!StatData.bIsDirectory) {
        TotalFileSize += StatData.FileSize;
      }

      return true;
    }
  };

  // copy files and directories visitor
  FStatFilesAndDirs StatFilesAndDirs(PlatformFile);

  // don't bother getting file size of dir
  // if the user doesn't want it
  if (ProgressCallback.IsBound()) {
    bool statResult = PlatformFile.IterateDirectoryStatRecursively(*SourceDir, StatFilesAndDirs);

    if (!statResult) {
      return false;
    }
  }

  // Copy all files and directories
  struct FCopyFilesAndDirs : public IPlatformFile::FDirectoryVisitor {
    IPlatformFile & PlatformFile;
    const TCHAR* SourceRoot;
    const TCHAR* DestRoot;
    bool bOverwrite;
    int chunkSizeInKilobytes;
    FFileSDKCopyDelegate progressCallback;
    FFileSDKDelegatePreInfo preInfo;

    FCopyFilesAndDirs(
      IPlatformFile& InPlatformFile,
      const TCHAR* InSourceRoot,
      const TCHAR* InDestRoot,
      bool bInOverwrite,
      int inChunkSizeInKilobytes,
      FFileSDKCopyDelegate inProgressCallback,
      int inTotalSizeKB
    ) :
      PlatformFile(InPlatformFile),
      SourceRoot(InSourceRoot),
      DestRoot(InDestRoot),
      bOverwrite(bInOverwrite),
      chunkSizeInKilobytes(inChunkSizeInKilobytes),
      progressCallback(inProgressCallback) {
        preInfo.TotalSize = inTotalSizeKB;
        preInfo.PriorWritten = 0;
    }

    virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) {
      FString NewName(FilenameOrDirectory);
      // change the root
      NewName = NewName.Replace(SourceRoot, DestRoot);

      if (bIsDirectory) {
        // create new directory structure
        if (!PlatformFile.CreateDirectoryTree(*NewName) && !PlatformFile.DirectoryExists(*NewName)) {
          return false;
        }
      } else {
        // Delete destination file if it exists and we are overwriting
        if (!PlatformFile.FileExists(*NewName) || bOverwrite) {
          // Copy file from source
          if (
            !UFileSDKBPLibrary::CopyFile(
              FilenameOrDirectory,
              NewName,
              progressCallback,
              preInfo,
              chunkSizeInKilobytes
            )
          ) {
            // Not all files could be copied
            return false;
          }
        }

        if (progressCallback.IsBound()) {
          auto statData = PlatformFile.GetStatData(FilenameOrDirectory);
          preInfo.PriorWritten += FMath::DivideAndRoundUp(statData.FileSize, int64(1000));
        }
      }
      return true; // continue searching
    }
  };

  // copy files and directories visitor
  FCopyFilesAndDirs CopyFilesAndDirs(
    PlatformFile,
    *SourceDir,
    *DestDir,
    OverwriteDestination,
    ChunkSizeInKilobytes,
    ProgressCallback,
    FMath::DivideAndRoundUp(StatFilesAndDirs.TotalFileSize, int64(1000))
  );

  // create all files subdirectories and files in subdirectories!
  return PlatformFile.IterateDirectoryRecursively(*SourceDir, CopyFilesAndDirs);
}

void UFileSDKBPLibrary::CopyDirectoryAsync(
  FString Source,
  FString Destination,
  const FFileSDKCopyDelegate & ProgressCallback,
  bool OverwriteDestination,
  int ChunkSizeInKilobytes
) {
  FFunctionGraphTask::CreateAndDispatchWhenReady(
    [=] {
      UFileSDKBPLibrary::CopyDirectory(
        Source,
        Destination,
        ProgressCallback,
        OverwriteDestination,
        ChunkSizeInKilobytes
      );
    },
    TStatId(),
    nullptr,
    ENamedThreads::AnyThread
  );
}

bool UFileSDKBPLibrary::ReadStringFromFile(FString FileName, FString & Content) {
  return FFileHelper::LoadFileToString(Content, *FileName);
}

bool UFileSDKBPLibrary::ReadLinesFromFile(
  FString FileName,
  TSubclassOf<class UFileSDKLineReader> LineReader,
  TArray<FString> & Lines
) {
  bool result = false;

  if (LineReader.GetDefaultObject() != nullptr) {
    auto reader = NewObject<UFileSDKLineReader>(
      (UObject*) GetTransientPackage(),
      *LineReader
    );

    result = FFileHelper::LoadFileToStringArrayWithPredicate(
      Lines,
      *FileName,
      [reader](const FString & line) { return reader->FilterLine(line); }
    );
  } else {
    result = FFileHelper::LoadFileToStringArrayWithPredicate(
      Lines,
      *FileName,
      [](const FString&) { return true; }
    );
  }

  return result;
}

bool UFileSDKBPLibrary::WriteStringToFile(
  FString FileName,
  FString Content,
  bool Append,
  EFileSDKEncodingOptions Encoding
) {
  FFileHelper::EEncodingOptions internalEncoding;
  switch (Encoding) {
    case EFileSDKEncodingOptions::AutoDetect: {
      internalEncoding = FFileHelper::EEncodingOptions::AutoDetect;
      break;
    }
    case EFileSDKEncodingOptions::ForceAnsi: {
      internalEncoding = FFileHelper::EEncodingOptions::ForceAnsi;
      break;
    }
    case EFileSDKEncodingOptions::ForceUnicode: {
      internalEncoding = FFileHelper::EEncodingOptions::ForceUnicode;
      break;
    }
    case EFileSDKEncodingOptions::ForceUTF8: {
      internalEncoding = FFileHelper::EEncodingOptions::ForceUTF8;
      break;
    }
    case EFileSDKEncodingOptions::ForceUTF8WithoutBOM: {
      internalEncoding = FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM;
      break;
    }
    default: {
      internalEncoding = FFileHelper::EEncodingOptions::AutoDetect;
      break;
    }
  }

  if (Append) {
    return FFileHelper::SaveStringToFile(
      Content,
      *FileName,
      internalEncoding,
      &IFileManager::Get(),
      FILEWRITE_Append
    );
  } else {
    return FFileHelper::SaveStringToFile(Content, *FileName, internalEncoding);
  }
}

bool UFileSDKBPLibrary::WriteBytesToFile(FString FileName, TArray<uint8> Content) {
  return FFileHelper::SaveArrayToFile(Content, *FileName);
}

bool UFileSDKBPLibrary::ReadBytesFromFile(FString FileName, TArray<uint8> & Content) {
  return FFileHelper::LoadFileToArray(Content, *FileName);
}

TArray<FString> UFileSDKBPLibrary::GetFilesFromDirectory(
  FString DirectoryToSearch,
  FString FilterFilesWithExtension,
  bool SearchSubfolders,
  EFileSDKFileType FileType
) {
  TArray<FString> FileNames;
  IFileManager & FileManager = IFileManager::Get();

  if (SearchSubfolders) {
    if (FileType == EFileSDKFileType::File) {
      FileManager.FindFilesRecursive(
        FileNames,
        *DirectoryToSearch,
        *(TEXT("*") + FilterFilesWithExtension),
        true,
        false
      );
    } else {
      FileManager.FindFilesRecursive(
        FileNames,
        *DirectoryToSearch,
        TEXT("*"),
        false,
        true
      );
    }
  } else {
    TArray<FString> relativeFileNames;

    if (FileType == EFileSDKFileType::File) {
      FileManager.FindFiles(
        relativeFileNames,
        *DirectoryToSearch,
        *FilterFilesWithExtension
      );
    } else {
      FileManager.FindFiles(
        relativeFileNames,
        *(DirectoryToSearch + FGenericPlatformMisc::GetDefaultPathSeparator() + TEXT("*")),
        false,
        true
      );
    }

    for (FString fileName : relativeFileNames) {
      FileNames.Add(
        DirectoryToSearch +
        FGenericPlatformMisc::GetDefaultPathSeparator() +
        fileName
      );
    }
  }

  return FileNames;
}

TArray<FFileSDKFileInfo> UFileSDKBPLibrary::GetDirectoryContentsWithFileInfo(
  FString Directory,
  bool SearchSubfolders
) {
  TArray<FFileSDKFileInfo> contents;
  IFileManager & FileManager = IFileManager::Get();

  TArray<FString> filePaths;
  if (SearchSubfolders) {
    FileManager.FindFilesRecursive(
      filePaths,
      *Directory,
      TEXT("*"),
      true,
      true
    );
  } else {
    TArray<FString> relativeFileNames;

    FileManager.FindFiles(
      relativeFileNames,
      *(Directory + FGenericPlatformMisc::GetDefaultPathSeparator() + TEXT("*")),
      true,
      true
    );

    for (FString fileName : relativeFileNames) {
      filePaths.Add(
        Directory +
        FGenericPlatformMisc::GetDefaultPathSeparator() +
        fileName
      );
    }
  }

  for (FString path : filePaths) {
    FFileSDKFileInfo info;
    info.AbsolutePath = path;
    info.Filename = FPaths::GetCleanFilename(path);
    UFileSDKBPLibrary::GetFileOrDirectoryInfo(path, info);
    contents.Add(info);
  }

  return contents;
}

void UFileSDKBPLibrary::GetFileOrDirectoryInfo(FString Path, FFileSDKFileInfo & Info) {
  IPlatformFile & PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

  FFileStatData data = PlatformFile.GetStatData(*Path);

  Info.AbsolutePath = Path;
  Info.Filename = FPaths::GetCleanFilename(Path);
  Info.CreationTime = data.CreationTime;
  Info.AccessTime = data.AccessTime;
  Info.ModificationTime = data.ModificationTime;
  Info.FileSize = data.FileSize;
  Info.bIsDirectory = data.bIsDirectory;
  Info.bIsReadOnly = data.bIsReadOnly;
  Info.bIsValid = data.bIsValid;
}

FString UFileSDKBPLibrary::GetCurrentUsername() {
#if PLATFORM_WINDOWS
  return FWindowsPlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("USERNAME"));
#elif PLATFORM_LINUX
  return FUnixPlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("USER"));
#elif PLATFORM_MAC
  return FApplePlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("USER"));
#else
  return "PLATFORM_NOT_SUPPORTED";
#endif
}

FString UFileSDKBPLibrary::GetCurrentUserHomeDirectory() {
#if PLATFORM_WINDOWS
  return FWindowsPlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("HOMEDRIVE")) + FWindowsPlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("HOMEPATH"));
#elif PLATFORM_LINUX
  return FUnixPlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("HOME"));
#elif PLATFORM_MAC
  return FApplePlatformMisc::GetEnvironmentVariable(ANSI_TO_TCHAR("HOME"));
#else
  return "PLATFORM_NOT_SUPPORTED";
#endif
}

FString UFileSDKBPLibrary::GetEnvironmentVariable(FString VariableName) {
#if PLATFORM_WINDOWS
  return FWindowsPlatformMisc::GetEnvironmentVariable(*VariableName);
#elif PLATFORM_LINUX
  return FUnixPlatformMisc::GetEnvironmentVariable(*VariableName);
#elif PLATFORM_MAC
  return FApplePlatformMisc::GetEnvironmentVariable(*VariableName);
#else
  return "PLATFORM_NOT_SUPPORTED";
#endif
}

std::ios_base::seekdir UFileSDKBPLibrary::FileAnchorToSeekDir(
  EFileSDKFileAnchor Anchor
) {
  switch (Anchor) {
    case EFileSDKFileAnchor::Beginning: {
      return std::ios_base::beg;
    }
    case EFileSDKFileAnchor::Current: {
      return std::ios_base::cur;
    }
    case EFileSDKFileAnchor::End:
    default: {
      return std::ios_base::end;
    }
  }
}
