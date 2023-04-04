// Copyright Incanta Games 2021. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "FileAnchor.h"

#include "HAL/FileManager.h"
#include "Serialization/Archive.h"

#include "FileSDKFileReader.generated.h"

class UFileSDKBPLibrary;

UCLASS(BlueprintType, Blueprintable)
class UFileSDKFileReader : public UObject {
  GENERATED_UCLASS_BODY()

  void OpenFile(FString fileName);

  /**
   * Checks to see if the file reader is in a "good" state. This is synonymous to the C++ good function.
   * This function returns false if the file reader is in a bad state, failed, or at the end of the file.
   *
   * @return Returns false if the file reader is in a bad state, failed, or at the end of the file.
   * Returns true if the file is successfully open and ready to read more bytes (i.e. the pointer
   * is not at the end of the file).
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "File Is Good",
      Keywords = "FileSDK file reader is good open"
    ),
    Category = "FileSDK | File Reader"
  )
  bool IsGood();

  /**
   * Returns the current position of the pointer for reading the file.
   *
   * @return The current position.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Get File Position",
      Keywords = "FileSDK get current file position pointer"
    ),
    Category = "FileSDK | File Reader"
  )
  int64 GetFilePosition();

  /**
   * Change the position of the File Reader; this is essentially a pointer of where you're going
   * to start reading for any of the following read nodes. When you open a File Reader, the seek
   * position starts at the Beginning. This is synonymous to the C++ seekg function.
   *
   * @param Anchor This defines the "from" where that Offset is applied to.
   * @param Offset Number of bytes to offset from the Anchor.
   *
   * @return Returns true if the file is open and "File Is Good"; otherwise returns false.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Seek File Position",
      Keywords = "FileSDK seek change file position pointer"
    ),
    Category = "FileSDK | File Reader"
  )
  bool SeekFilePosition(EFileSDKFileAnchor Anchor, int64 Offset);

  /**
   * Reads a specified number of bytes from the current file reader location as a binary Byte array.
   * The file reader location is advanced to where ever it finishes reading.
   *
   * @param Num The number of bytes to read. If Num greater than the number of bytes left in the file,
   * it will read to the end of the file.
   *
   * @param Content The bytes that were read in as a binary Byte array.
   * @return 	The actual number of bytes read. This is usually only different than Num if you reached
   * the end of the file. You should, however, still use Is Good to check if you're at the end of the file.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Read Bytes",
      Keywords = "FileSDK read bytes"
    ),
    Category = "FileSDK | File Reader"
  )
  int64 ReadBytes(int64 Num, TArray<uint8> & Content);

  /**
   * Reads the rest of the file from the current location as a binary Byte array. The file reader
   * location is advanced to the end of the file.
   *
   * @param Content The bytes that were read in as a binary Byte array.
   * @return The actual number of bytes read.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Read Bytes To End",
      Keywords = "FileSDK read bytes to end"
    ),
    Category = "FileSDK | File Reader"
  )
  int64 ReadBytesToEnd(TArray<uint8> & Content);

  /**
   * Reads a specified number of bytes from the current file reader location as a String.
   * The file reader location is advanced to where ever it finishes reading.
   *
   * @param Num The number of bytes to read. If Num greater than the number of bytes left in the file,
   * it will read to the end of the file.
   *
   * @param Content The bytes that were read in as a String.
   * @return The actual number of bytes read. This is usually only different than Num if you reached
   * the end of the file. You should, however, still use "File Is Good" to check if you're at the end of the file.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Read String",
      Keywords = "FileSDK read string chars characters"
    ),
    Category = "FileSDK | File Reader"
  )
  int64 ReadString(int64 Num, FString & Content);

  /**
   * Reads the rest of the file from the current location as a String. The file reader location
   * is advanced to the end of the file.
   *
   * @param Content The bytes that were read in as a String.
   * @return The actual number of bytes read.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Read String to End",
      Keywords = "FileSDK read string chars characters to end"
    ),
    Category = "FileSDK | File Reader"
  )
  int64 ReadStringToEnd(FString & Content);

  /**
   * Closes the file if it's valid/open. Does nothing otherwise.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Close File Reader",
      Keywords = "FileSDK file reader close"
    ),
    Category = "FileSDK | File Reader"
  )
  void Close();

  /**
   * The absolute path to the file being read.
   */
  UPROPERTY(BlueprintReadOnly, Category = "Details")
  FString FileName;

private:
  FArchive * fileReader;

  friend class UFileSDKBPLibrary;
};
