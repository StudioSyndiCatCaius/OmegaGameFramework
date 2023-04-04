// Copyright Incanta Games 2020. All Rights Reserved.

#pragma once

#include "FileSDKFileInfo.generated.h"

USTRUCT(BlueprintType)
struct FFileSDKFileInfo {
  GENERATED_USTRUCT_BODY();

  /** The full absolute path and file name */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  FString AbsolutePath;

  /** The file name without the path */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  FString Filename;

  /** The time that the file or directory was originally created, or FDateTime::MinValue if the creation time is unknown */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  FDateTime CreationTime;

  /** The time that the file or directory was last accessed, or FDateTime::MinValue if the access time is unknown */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  FDateTime AccessTime;

  /** The time the the file or directory was last modified, or FDateTime::MinValue if the modification time is unknown */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  FDateTime ModificationTime;

  /** Size of the file (in bytes), or -1 if the file size is unknown */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  int64 FileSize;

  /** True if this data is for a directory, false if it's for a file */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  bool bIsDirectory;

  /** True if this file is read-only */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  bool bIsReadOnly;

  /** True if file or directory was found, false otherwise. Note that this value being true does not ensure that the other members are filled in with meaningful data, as not all file systems have access to all of this data */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  bool bIsValid;

  FFileSDKFileInfo() {
    AbsolutePath = "";
    Filename = "";
    CreationTime = FDateTime(0);
    AccessTime = FDateTime(0);
    ModificationTime = FDateTime(0);
    FileSize = 0;
    bIsDirectory = false;
    bIsReadOnly = false;
    bIsValid = false;
  }
};
