#pragma once

#include "CoreMinimal.h"

class OMEGACORE_API OMEGA_File
{
public:
	static FString PathCorrect(const FString& path);
	
	static TArray<FString> ListFilesInDirectory(const FString& path, bool bRecursive);
	static TArray<FString> ListFilesInDirectoryList(TArray<FString> paths, bool bRecursive);
	static TArray<FString> GetAllSubfolders(const FString& BasePath, bool bRecursive);
	
	static UObject* HotloadUasset_FromFile(const FString& filepath);
	static UObject* HotloadUasset_FromBytes(TArray<uint8> byte);
};
