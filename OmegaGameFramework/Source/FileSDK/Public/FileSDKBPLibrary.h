// Copyright Incanta Games 2020. All Rights Reserved.

#pragma once

#include <ios>

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManagerGeneric.h"
#include "Async/TaskGraphInterfaces.h"
#include "Templates/SubclassOf.h"

#include "FileSDKFileInfo.h"
#include "FileSDKFileType.h"
#include "FileAnchor.h"
#include "FileSDKLineReader.h"
#include "FileSDKEncodingOptions.h"
#include "FileSDK.h"
#include "FileSDKFileReader.h"

#if PLATFORM_WINDOWS
  #include "Windows/WindowsPlatformMisc.h"
#elif PLATFORM_LINUX || PLATFORM_ANDROID
  #include "Unix/UnixPlatformMisc.h"
#elif PLATFORM_MAC || PLATFORM_IOS
  #include "Apple/ApplePlatformMisc.h"
  #include <sys/stat.h>
#endif

#include "FileSDKBPLibrary.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FFileSDKCopyDelegate, int, KilobytesWritten, int, TotalKilobytes);

USTRUCT(BlueprintType)
struct FFileSDKDelegatePreInfo {
  GENERATED_USTRUCT_BODY();
  int PriorWritten;
  int TotalSize;

  FFileSDKDelegatePreInfo() {
    PriorWritten = 0;
    TotalSize = 0;
  }
};

UCLASS()
class UFileSDKBPLibrary : public UBlueprintFunctionLibrary {
  GENERATED_UCLASS_BODY()

  /**
   * Creates a File Reader instance; File Readers can be used to control how the file is read.
   * You can seek to different parts of the file, only read in a specified number of bytes, etc.
   * This gives you the most amount of control and is great for only reading metadata in large files.
   * NOTE: Most use cases should use "Read String from File" or "Read Bytes from File" nodes.
   *
   * @param FileName An absolute path of the file that you want to open for reading.
   *
   * @return The File Reader instance regardless of the status of successful open.
   * See the `Is Good` node before attempting to read anything.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Open File Reader",
      Keywords = "FileSDK open file reader"
    ),
    Category = "FileSDK"
  )
  static UFileSDKFileReader * OpenFileReader(
    FString FileName
  );

  /**
   * Creates an empty file.
   *
   * @param FileName An absolute path to the file you want to create.
   * @param ClearContentsIfExists If set to true this node will completely delete any content in the file.
   * @param CreateDirectoryTree If set to true, any missing folders to get to File Name will be automatically created.
   * See docs at wiki.incanta.games for more details.
   *
   * @return Returns true if the file was successfully deleted.
   * Returns false if the file doesn't exist or the file couldn't be deleted.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Create File",
      Keywords = "FileSDK create make generate file"
    ),
    Category = "FileSDK"
  )
  static void CreateFile(FString FileName, bool ClearContentsIfExists = true, bool CreateDirectoryTree = true);

  /**
   * Deletes a file if it exists; does nothing if it doesn't exist.
   *
   * @param FileName An absolute path to the file you want to delete.
   *
   * @return Returns true if the file was successfully deleted.
   * Returns false if the file doesn't exist or the file couldn't be deleted.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Delete File",
      Keywords = "FileSDK delete file destroy"
    ),
    Category = "FileSDK"
  )
  static bool DeleteFile(FString FileName);

  /**
   * Creates a directory.
   *
   * @param DirectoryName An absolute path to the directory you want to create.
   * @param CreateDirectoryTree If set to true, any missing folders to get to File Name will be automatically created.
   * See docs at wiki.incanta.games for more details.
   *
   * @return Returns whether or not the directory was successfully created.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Create Directory",
      Keywords = "FileSDK create make generate directory folder"
    ),
    Category = "FileSDK"
  )
  static bool CreateDirectory(FString DirectoryName, bool CreateDirectoryTree = true);

  /**
   * Deletes a directory.
   *
   * @param DirectoryName An absolute path to the directory you want to create.
   * @param Recursive If set to true, all files and folders in this directory will be deleted.
   * If set to false, the directory will only be deleted if it is empty.
   *
   * @return Returns whether or not the directory was successfully deleted.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Delete Directory",
      Keywords = "FileSDK delete destroy remove directory folder"
    ),
    Category = "FileSDK"
  )
  static bool DeleteDirectory(FString DirectoryName, bool Recursive = true);

  /**
   * Renames/moves a file or a directory to a new name/location.
   *
   * @param Source An absolute path to the file/directory that you want to rename/move.
   * @param Destination An absolute path of the new location/name you want for the file or directory.
   * You cannot provide "/path/to/file.csv" for Source and only provide "file-old.csv" for Destination;
   * you must provide the full absolute path of the new file (i.e. "/path/to/file-old.csv").
   *
   * @return Returns whether or not the file/directory was successfully renamed/moved.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Rename File or Directory",
      Keywords = "FileSDK rename move file directory folder"
    ),
    Category = "FileSDK"
  )
  static bool RenameFileOrDirectory(FString Source, FString Destination);

  /**
   * Copies a file, creating a duplicate version. Performs the copy operation on the main game thread;
   * this can have performance issues for large files. See `Copy File Async` to perform the copy in the
   * background (in a separate thread).
   *
   * @param Source An absolute path to the file you want to copy.
   * @param Destination An absolute path to where you want to copy the file to. You cannot provide
   * "/path/to/file.csv" for Source and only provide "file-old.csv" for Destination; you must provide
   * the full absolute path of the new file (i.e. "/path/to/file-old.csv").
   * @param ProgressCallback This allows you to attach an event to receive execution when progress is made,
   * allowing you to update a UI or other variables about the progress left for copying the file.
   * @param PreInfo The number of kilobytes you want each chunk of data to be copied as.
   * Smaller numbers can give you more fine progress updates, but at the cost of more disk IO operations,
   * potentially slowing down the overall copy.
   * @param OverwriteDestination If file exists and this is set to true, the contents of the file will be overwritten.
   *
   * @return Returns false if Source could not be opened (likely because it doesn't exist) or if Destination
   * could not be opened for write permissions (likely the directory doesn't exist, or the user doesn't have
   * permissions to write there). Returns true if the copy was successful.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Copy File",
      Keywords = "FileSDK copy file",
      AutoCreateRefTerm = "ProgressCallback, PreInfo",
      HidePin = "PreInfo"
    ),
    Category = "FileSDK"
  )
  static bool CopyFile(
    FString Source,
    FString Destination,
    const FFileSDKCopyDelegate & ProgressCallback,
    FFileSDKDelegatePreInfo PreInfo,
    int ChunkSizeInKilobytes = 1024,
    bool OverwriteDestination = false
  );

  /**
   * Copies a file, creating a duplicate version. Performs the copy operation in a separate
   * background thread, preventing the game thread from waiting for the copy operation to finish.
   *
   * @param Source An absolute path to the file you want to copy.
   * @param Destination An absolute path to where you want to copy the file to. You cannot provide
   * "/path/to/file.csv" for Source and only provide "file-old.csv" for Destination; you must provide
   * the full absolute path of the new file (i.e. "/path/to/file-old.csv").
   * @param ProgressCallback This allows you to attach an event to receive execution when progress is made,
   * allowing you to update a UI or other variables about the progress left for copying the file.
   * @param ChunkSizeInKilobytes The number of kilobytes you want each chunk of data to be copied as.
   * Smaller numbers can give you more fine progress updates, but at the cost of more disk IO operations,
   * potentially slowing down the overall copy.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DeprecatedFunction,
      DeprecationMessage="This function has been deprecated; please use 'Copy File or Directory Async'.",
      DisplayName = "Copy File Async",
      Keywords = "FileSDK copy file async",
      AutoCreateRefTerm = "ProgressCallback, PreInfo",
      HidePin = "PreInfo"
    ),
    Category = "FileSDK"
  )
  static void CopyFileAsync(
    FString Source,
    FString Destination,
    const FFileSDKCopyDelegate & ProgressCallback,
    FFileSDKDelegatePreInfo PreInfo,
    int ChunkSizeInKilobytes = 1024
  );

  /**
   * Copies a directory, including all of its contents, creating a duplicate version.
   * Performs the copy operation on the main game thread; this can have performance issues for large
   * directories. See "Copy Directory Async" to perform the copy in the background (in a separate thread).
   *
   * @param Source An absolute path to the directory you want to copy.
   * @param Destination An absolute path to where you want to copy the directory to.
   * @param ProgressCallback This allows you to attach an event to receive execution when progress is made,
   * allowing you to update a UI or other variables about the progress left for copying the directory.
   * @param OverwriteDestination If set to true, if a particular file exists in the respective Destination
   * location, it will be overwritten with the new contents. Otherwise it will be ignored. For example if
   * you're copying "/path/from" to "/path/to", and "/path/to/file.txt" already exists, if this is set to true,
   * /path/from/file.txt will overwrite "/path/to/file.txt", if set to false, "/path/to/file.txt" will remain
   * unchanged.
   * @param ChunkSizeInKilobytes The number of kilobytes you want each chunk of data to be copied as.
   * Smaller numbers can give you more fine progress updates, but at the cost of more disk IO operations,
   * potentially slowing down the overall copy.
   *
   * @return Returns true if the copy finished successfully. Returns false if any of the files couldn't be
   * copied or if subdirectories couldn't be created (usually this happens if there are permissions issues
   * or files are open in other programs).
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Copy Directory",
      Keywords = "FileSDK copy directory folder",
      AutoCreateRefTerm = "ProgressCallback"
    ),
    Category = "FileSDK"
  )
  static bool CopyDirectory(
    FString Source,
    FString Destination,
    const FFileSDKCopyDelegate & ProgressCallback,
    bool OverwriteDestination = false,
    int ChunkSizeInKilobytes = 1024
  );

  /**
   * Copies a directory, including all of its contents, creating a duplicate version.
   * Performs the copy operation in a separate background thread, preventing the game thread
   * from waiting for the copy operation to finish.
   *
   * @param Source An absolute path to the directory you want to copy.
   * @param Destination An absolute path to where you want to copy the directory to.
   * @param ProgressCallback This allows you to attach an event to receive execution when progress is made,
   * allowing you to update a UI or other variables about the progress left for copying the directory.
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
      DeprecatedFunction,
      DeprecationMessage="This function has been deprecated; please use 'Copy File or Directory Async'.",
      DisplayName = "Copy Directory Async",
      Keywords = "FileSDK copy directory folder async",
      AutoCreateRefTerm = "ProgressCallback"
    ),
    Category = "FileSDK"
  )
  static void CopyDirectoryAsync(
    FString Source,
    FString Destination,
    const FFileSDKCopyDelegate & ProgressCallback,
    bool OverwriteDestination = false,
    int ChunkSizeInKilobytes = 1024
  );

  /**
   * Reads the entire contents of a file as text into a string.
   *
   * @param FileName An absolute path to the file you would like to read.
   *
   * @param Content The entire contents of File Name.
   * @return Returns true if the file could be opened and read successfully.
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Read String from File",
      Keywords = "FileSDK read file string text"
    ),
    Category = "FileSDK"
  )
  static bool ReadStringFromFile(FString FileName, FString & Content);

  /**
   * Read the entire contents of a file as an array of strings. Each element in the array is a
   * separate line in the file. Both LF (Line Feed, used in Linux and Mac systems) and CRLF
   * (Carriage Return, Line Feed, used in Windows systems) are supported.
   *
   * @param FileName An absolute path to the file you would like to read.
   * @param LineReader While every line is read from the file regardless, you can use this
   * parameter to filter which lines are returned in Lines. To do this, specify a child class
   * of the "FileSDKLineReader" class and override the "FilterLine" function. When the "FilterLine"
   * function returns true, the line is provided in the output of the "Read Lines From File" function.
   * Find more details in our docs at wiki.incanta.games.
   *
   * @param Lines The lines of the file, optionally filtered by LineReader. These do not contain the
   * line endings (i.e. there is no LF or CRLF character(s) at the end of the strings).
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Read Lines from File",
      Keywords = "FileSDK read lines array file string text"
    ),
    Category = "FileSDK"
  )
  static bool ReadLinesFromFile(
    FString FileName,
    TSubclassOf<class UFileSDKLineReader> LineReader,
    TArray<FString> & Lines
  );

  /**
   * Writes a string as text to a file, with options to overwrite/append as well as encoding options.
   * Will create the file if it doesn't exist. This node expects the parent directory to already exist
   * (i.e. it will not create directories for you, and will return false if the parent directories do not exist).
   *
   * @param FileName An absolute path to the file you would like to write.
   * @param Content The text you would like to write to the file.
   * @param Append If set to false, the file will be erased before writing Content to it; if set to true,
   * Content will be written at the end of the file. New lines/carriage returns will not be automatically
   * inserted for you.
   * @param Encoding Encoding options that are passed down to the file writer. "Auto Detect" will do its
   * best to determine the encoding of the string, but you can also use one of the
   * "Force (Ansi | Unicode | UTF8 | UTF8WithoutBOM)" options to force how the contents are encoded.
   *
   * @return Returns true if the file could be opened and written successfully.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Write String to File",
      Keywords = "FileSDK write append save file string text"
    ),
    Category = "FileSDK"
  )
  static bool WriteStringToFile(
    FString FileName,
    FString Content,
    bool Append = false,
    EFileSDKEncodingOptions Encoding = EFileSDKEncodingOptions::AutoDetect
  );

  /**
   * Writes a Byte array as binary data to a file. This node currently always overwrites the
   * file contents. If you have a use case for appending binary files, please let us know.
   * Will create the file if it doesn't exist. This node expects the parent directory to already
   * exist (i.e. it will not create directories for you, and will return false if the parent
   * directories do not exist).
   *
   * @param FileName An absolute path to the file you want to write.
   * @param Content The bytes you would like to write to the file.
   *
   * @return Returns true if the file was opened wnd written successfully.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Write Bytes to File",
      Keywords = "FileSDK write save file bytes binary"
    ),
    Category = "FileSDK"
  )
  static bool WriteBytesToFile(FString FileName, TArray<uint8> Content);

  /**
   * Reads the entire contents of a file as a binary Byte array.
   *
   * @param FileName An absolute path to the file you want to read.
   *
   * @param Content The entire contents of File Name.
   * @return Returns true if the file was opened and read successfully.
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Read Bytes from File",
      Keywords = "FileSDK read file bytes binary"
    ),
    Category = "FileSDK"
  )
  static bool ReadBytesFromFile(FString FileName, TArray<uint8> & Content);

  /**
   * Searches for files or directories in a directory.
   *
   * @param DirectoryToSearch An absolute path to the directory that you want to search in.
   * @param FilterFilesWithExtension Only used if "File Type" is "File". This argument allows
   * you to filter the results by the file extension. Proper usage of this argument is
   * ".txt", ".csv", etc, including the period.
   * @param SearchSubfolders Whether or not to search subdirectories (true) or just search
   * the single folder provided (false).
   * @param FileType Whether or not to search for a "File" or a "Directory".
   *
   * @return An array of absolute paths to each file or directory found.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Get Files or Directories from Directory",
      Keywords = "FileSDK get search find files list directory contents"
    ),
    Category = "FileSDK"
  )
  static TArray<FString> GetFilesFromDirectory(
    FString DirectoryToSearch,
    FString FilterFilesWithExtension,
    bool SearchSubfolders = false,
    EFileSDKFileType FileType = EFileSDKFileType::File
  );

  /**
   * Lists the contents of a directory, including both files and directories, with supplemental information.
   *
   * @param Directory An absolute path to the directory that you want to list contents of.
   * @param SearchSubfolders Whether or not to search subdirectories (true) or just search the
   * single folder provided (false).
   *
   * @return An array of FileSDKFileInfo structs, one for each file and directory, each containing detailed
   * information of the file/directory.
   */
  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Get Directory Contents with File Info",
      Keywords = "FileSDK get search find files list directory contents file info stat"
    ),
    Category = "FileSDK"
  )
  static TArray<FFileSDKFileInfo> GetDirectoryContentsWithFileInfo(
    FString Directory,
    bool SearchSubfolders = false
  );

  /**
   * Returns detailed information for a specific file or directory.
   *
   * @param Path An absolute path to the file or directory you want information for.
   *
   * @param Info The detailed info struct of the file.
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Get File or Directory Info",
      Keywords = "FileSDK get file"
    ),
    Category = "FileSDK"
  )
  static void GetFileOrDirectoryInfo(FString Path, FFileSDKFileInfo & Info);

  /**
   * Retrieves the current username for whoever is running the program/game. (i.e. <user> in C:\Users\<user>)
   *
   * @return On Windows, this returns the environment variable "%USERNAME%". On Mac and Linux, this returns
   * the environment variable "$USER". On other platforms, it returns "PLATFORM_NOT_SUPPORTED".
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Get Current Username",
      Keywords = "FileSDK get current user name username"
    ),
    Category = "FileSDK | Paths"
  )
  static FString GetCurrentUsername();

  /**
   * Returns the current user's home directory. (i.e. the entire C:\Users\<user path)
   *
   * @return On Windows, this returns the environment variable "%HOMEDRIVE%" concatenated with "%HOMEPATH%"
   * (i.e. "%HOMEDRIVE%%HOMEPATH%"). On Mac and Linux, this returns the environment variable "$HOME".
   * On other platforms, it returns "PLATFORM_NOT_SUPPORTED".
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Get Current User Home Directory",
      Keywords = "FileSDK get current user home directory"
    ),
    Category = "FileSDK | Paths"
  )
  static FString GetCurrentUserHomeDirectory();

  /**
   * Returns the value of an environment variable.
   *
   * @param VariableName On Windows, you fetch environment variables in Command Prompt with something like "%VAR%";
   * on Mac and Linux, you fetch environment variables in the terminal with something like "$VAR".
   * In both cases, Variable Name is VAR without the "%" or "$".
   *
   * @return Returns the value of the environment variable if it's set. If it's not set it returns an empty string.
   * On target platforms that are not Windows, Mac, or Linux, "PLATFORM_NOT_SUPPORTED" is returned.
   */
  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Get Environment Variable",
      Keywords = "FileSDK get environment env variable"
    ),
    Category = "FileSDK | Paths"
  )
  static FString GetEnvironmentVariable(FString VariableName);

  static std::ios_base::seekdir FileAnchorToSeekDir(EFileSDKFileAnchor Anchor);
};
