

#include "Statics/OMEGA_File.h"
#include "Internationalization/Culture.h"

FString OMEGA_File::PathCorrect(const FString& path)
{
	FString out=path;
	
	out=out.Replace(TEXT("{project}"),*FPaths::ProjectDir());
	out=out.Replace(TEXT("{content}"),*FPaths::ProjectContentDir());
	out=out.Replace(TEXT("{mods}"),*FPaths::ProjectModsDir());
	out=out.Replace(TEXT("{saves}"),*FPaths::GameAgnosticSavedDir());
	out=out.Replace(TEXT("{culture}"),*FInternationalization::Get().GetCurrentCulture()->GetName());
	out=out.Replace(TEXT("//"),TEXT("/"));
    
	FPaths::NormalizeFilename(out);
	
	return out;
}

TArray<FString> OMEGA_File::ListFilesInDirectory(const FString& path, bool bRecursive)
{
	FString _Path=PathCorrect(path);
	TArray<FString> FoundFiles;
    
	if (bRecursive)
	{
		// Search recursively for all files in the directory and subdirectories
		IFileManager::Get().FindFilesRecursive(FoundFiles, *_Path, TEXT("*"), true, false);
	}
	else
	{
		// Search only in the specified directory (non-recursive)
		FString SearchPath = _Path / TEXT("*");
		IFileManager::Get().FindFiles(FoundFiles, *SearchPath, true, false);
	}
    
	return FoundFiles;
}

TArray<FString> OMEGA_File::ListFilesInDirectoryList(TArray<FString> paths, bool bRecursive)
{
	TArray<FString> out;
	for (FString dir : paths)
	{
		out.Append(ListFilesInDirectory(dir, bRecursive));
	}
	return out;
}

void OMEGA_File::DoDaTing()
{
	return ;
}
