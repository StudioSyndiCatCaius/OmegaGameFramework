#pragma once

#include "CoreMinimal.h"

class OMEGACORE_API OMEGA_File
{
public:
	static FString PathCorrect(const FString& path);
	
	static TArray<FString> ListFilesInDirectory(const FString& path, bool bRecursive);
	static TArray<FString> ListFilesInDirectoryList(TArray<FString> paths, bool bRecursive);

	static void DoDaTing();
};
