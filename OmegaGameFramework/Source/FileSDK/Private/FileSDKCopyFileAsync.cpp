// Copyright Incanta Games 2021. All Rights Reserved.

#include "FileSDKCopyFileAsync.h"

void UFileSDKCopyFileAsync::Activate() {
  FFileSDKFileInfo fileInfo;
  UFileSDKBPLibrary::GetFileOrDirectoryInfo(Source, fileInfo);

  if (fileInfo.bIsDirectory) {
    FFunctionGraphTask::CreateAndDispatchWhenReady(
      [=] {
        auto successful = UFileSDKBPLibrary::CopyDirectory(
          Source,
          Destination,
          ProgressCallback,
          OverwriteDestination,
          ChunkSizeInKilobytes
        );

        Completed.Broadcast(successful);
      },
      TStatId(),
      nullptr,
      ENamedThreads::AnyThread
    );
  } else {
    FFileSDKDelegatePreInfo PreInfo;
    FFunctionGraphTask::CreateAndDispatchWhenReady(
      [=] {
        auto successful = UFileSDKBPLibrary::CopyFile(
          Source,
          Destination,
          ProgressCallback,
          PreInfo,
          ChunkSizeInKilobytes,
          OverwriteDestination
        );

        Completed.Broadcast(successful);
      },
      TStatId(),
      nullptr,
      ENamedThreads::AnyThread
    );
  }
}

UFileSDKCopyFileAsync* UFileSDKCopyFileAsync::CopyFileAsync(
  UObject* WorldContextObject,
  FString Source,
  FString Destination,
  const FFileSDKCopyDelegate & ProgressCallback,
  bool OverwriteDestination,
  int ChunkSizeInKilobytes
) {
  // Create Action Instance for Blueprint System
  UFileSDKCopyFileAsync* Action = NewObject<UFileSDKCopyFileAsync>();
  Action->Source = Source;
  Action->Destination = Destination;
  Action->ProgressCallback = ProgressCallback;
  Action->OverwriteDestination = OverwriteDestination;
  Action->ChunkSizeInKilobytes = ChunkSizeInKilobytes;
  Action->RegisterWithGameInstance(WorldContextObject);

  return Action;
}