// Copyright Incanta Games 2021. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "FileSDKBPLibrary.h"

#include "FileSDKCopyFileAsync.generated.h"

// Event that will be the 'Completed' exec wire in the blueprint node along with all parameters as output pins.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
  FFileSDKOnCopyCompleted,
  bool,
  Successful
);

UCLASS()
class FILESDK_API UFileSDKCopyFileAsync : public UBlueprintAsyncActionBase {
  GENERATED_BODY()

public:

  /** Execute the actual load */
  virtual void Activate() override;

  /**
   * Copy a file or a directory, creating a duplicate version. Performs the copy operation
   * in a separate background thread, preventing the game thread from waiting for the copy
   * operation to finish.
   *
   * @param Source An absolute path to the file or directory you want to copy.
   * @param Destination An absolute path to where you want to copy the file or to. You cannot provide
   * "/path/to/file.csv" for Source and only provide "file-old.csv" for Destination; you must provide
   * the full absolute path of the new file (i.e. "/path/to/file-old.csv").
   * @param ProgressCallback This allows you to attach an event to receive execution when progress is made,
   * allowing you to update a UI or other variables about the progress left for copying the file.
   * @param OverwriteDestination If set to true, if a particular file exists in the respective Destination
   * location, it will be overwritten with the new contents. Otherwise it will be ignored. For example if
   * you're copying "/path/from" to "/path/to", and "/path/to/file.txt" already exists, if this is set to true,
   * /path/from/file.txt will overwrite "/path/to/file.txt", if set to false, "/path/to/file.txt" will remain
   * unchanged.
   * @param ChunkSizeInKilobytes The number of kilobytes you want each chunk of data to be copied as.
   * Smaller numbers can give you more fine progress updates, but at the cost of more disk IO operations,
   * potentially slowing down the overall copy.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Copy File or Directory Async",
      BlueprintInternalUseOnly="true",
      Category="FileSDK",
      WorldContext="WorldContextObject"
    )
  )
  static UFileSDKCopyFileAsync* CopyFileAsync(
    UObject* WorldContextObject,
    FString Source,
    FString Destination,
    const FFileSDKCopyDelegate & ProgressCallback,
    bool OverwriteDestination = false,
    int ChunkSizeInKilobytes = 1024
  );

  /**
   * This execution pin is called when the copy finishes, regardless if it was successful or not.
   */
  UPROPERTY(BlueprintAssignable)
  FFileSDKOnCopyCompleted Completed;

  /**
   * An absolute path to the file you want to copy.
   */
  FString Source;

  /**
   * An absolute path to where you want to copy the file to. You cannot provide
   * "/path/to/file.csv" for Source and only provide "file-old.csv" for Destination; you must provide
   * the full absolute path of the new file (i.e. "/path/to/file-old.csv").
   */
  FString Destination;

  /**
   * This allows you to attach an event to receive execution when progress is made,
   * allowing you to update a UI or other variables about the progress left for copying the file.
   */
  FFileSDKCopyDelegate ProgressCallback;

  /**
   * If set to true, if a particular file exists in the respective Destination
   * location, it will be overwritten with the new contents. Otherwise it will be ignored. For example if
   * you're copying "/path/from" to "/path/to", and "/path/to/file.txt" already exists, if this is set to true,
   * /path/from/file.txt will overwrite "/path/to/file.txt", if set to false, "/path/to/file.txt" will remain
   * unchanged.
   */
  bool OverwriteDestination;

  /**
   * The number of kilobytes you want each chunk of data to be copied as.
   * Smaller numbers can give you more fine progress updates, but at the
   * cost of more disk IO operations, potentially slowing down the overall copy.
   */
  int ChunkSizeInKilobytes;
};