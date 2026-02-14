// Copyright Studio Syndicat 2021. All Rights Reserved.


#include "Functions/F_Paker.h"
#include "IPlatformFilePak.h"

bool UOmegaPakFunctions::MountPakFile(const FString& PakFilePath, const FString& PakMountPoint)
{
	int32 PakOrder = 0;
	bool bIsMounted = false;

	//Check to see if running in editor
    //#if WITH_EDITOR
	//return bIsMounted;
    //#endif


	FString InputPath = PakFilePath;
	FPaths::MakePlatformFilename(InputPath);


	FPakPlatformFile* PakFileMgr = (FPakPlatformFile*)(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")));
	if (PakFileMgr == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get PakPlatformFile for pak file (mount): %s"), *(PakFilePath));
		return false;
	}
	if (!PakMountPoint.IsEmpty())
	{
		bIsMounted = PakFileMgr->Mount(*InputPath, PakOrder, *PakMountPoint);
	}
	else
	{
		bIsMounted = PakFileMgr->Mount(*InputPath, PakOrder);
	}
	return bIsMounted;
}

bool UOmegaPakFunctions::UnmountPakFile(const FString& PakFilePath)
{
	FPakPlatformFile* PakFileMgr = (FPakPlatformFile*)(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")));
	if (PakFileMgr == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to get PakPlatformFile for pak file (Unmount): %s"), *(PakFilePath));
		return false;
	}
	return PakFileMgr->Unmount(*PakFilePath);
}

void UOmegaPakFunctions::RegisterMountPoint(const FString& RootPath, const FString& ContentPath)
{
	FPackageName::RegisterMountPoint(RootPath, ContentPath);
}

void UOmegaPakFunctions::UnRegisterMountPoint(const FString& RootPath, const FString& ContentPath)
{
	FPackageName::UnRegisterMountPoint(RootPath, ContentPath);
}

FString const UOmegaPakFunctions::GetPakMountPoint(const FString& PakFilePath)
{
	FPakFile* Pak = nullptr;
	TRefCountPtr<FPakFile> PakFile = new FPakFile(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")), *PakFilePath, false);
	Pak = PakFile.GetReference();
	if (Pak->IsValid())
	{
		return Pak->GetMountPoint();
	}
	return FString();
}

TArray<FString> UOmegaPakFunctions::GetPakContent(const FString& PakFilePath, bool bOnlyCooked /*= true*/)
{
	TArray<FString> PakContent;
	/*
	FPakFile* Pak = nullptr;
	TRefCountPtr<FPakFile> PakFile = new FPakFile(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")), *PakFilePath, false);
	Pak = PakFile.GetReference();
	

	if (Pak->IsValid())
	{
		FString ContentPath, PakAppendPath;
		FString MountPoint = GetPakMountPoint(PakFilePath);
		MountPoint.Split("/Content/", &ContentPath, &PakAppendPath);
		
		TArray<FPakFile::FFilenameIterator> Records;
		for (FPakFile::FFilenameIterator It(*Pak, false); It; ++It)
		{
			Records.Add(It);
		}

		for (auto& It : Records)
		{
			if (bOnlyCooked)
			{
				if (FPaths::GetExtension(It.Filename()) == TEXT("uasset"))
				{
					PakContent.Add(FString::Printf(TEXT("%s%s"), *PakAppendPath, *It.Filename()));
				}
			}
			else
			{
				PakContent.Add(FString::Printf(TEXT("%s%s"), *PakAppendPath, *It.Filename()));
			}
		}
	}
	*/
	return PakContent;
}

FString UOmegaPakFunctions::GetPakMountContentPath(const FString& PakFilePath)
{
	FString ContentPath, RightStr;
	bool bIsContent;
	FString MountPoint = GetPakMountPoint(PakFilePath);
	bIsContent = MountPoint.Split("/Content/", &ContentPath, &RightStr);
	if (bIsContent)
	{
		return FString::Printf(TEXT("%s/Content/"), *ContentPath);
	}
	// Check Pak Content for /Content/ Path
	else
	{
		TArray<FString> Content = GetPakContent(PakFilePath);
		if (Content.Num() > 0)
		{
			FString FullPath = FString::Printf(TEXT("%s%s"), *MountPoint, *Content[0]);
			bIsContent = FullPath.Split("/Content/", &ContentPath, &RightStr);
			if (bIsContent)
			{
				return FString::Printf(TEXT("%s/Content/"), *ContentPath);
			}
		}
	}
	//Failed to Find Content
	return FString("");
}

void UOmegaPakFunctions::MountAndRegisterPak(FString PakFilePath, bool& bIsMountSuccessful)
{
	FString PakRootPath = "/Game/";
	if (!PakFilePath.IsEmpty())
	{
		if (MountPakFile(PakFilePath, FString()))
		{
			bIsMountSuccessful = true;
			const FString MountPoint = GetPakMountContentPath(PakFilePath);
			RegisterMountPoint(PakRootPath, MountPoint);
		}
	}
}

UClass* UOmegaPakFunctions::LoadPakObjClassReference(FString PakContentPath)
{
	FString PakRootPath = "/Game/";
	const FString FileName = Conv_PakContentPathToReferenceString(PakContentPath, PakRootPath);
	return LoadPakFileClass(FileName);
}

UClass* UOmegaPakFunctions::LoadPakFileClass(const FString& FileName)
{
	const FString Name = FileName + TEXT(".") + FPackageName::GetShortName(FileName) + TEXT("_C");
	return StaticLoadClass(UObject::StaticClass(), nullptr, *Name);
}

FString UOmegaPakFunctions::Conv_PakContentPathToReferenceString(const FString PakContentPath, const FString PakMountPath)
{
	return FString::Printf(TEXT("%s%s.%s"),
		*PakMountPath, *FPaths::GetBaseFilename(PakContentPath, false), *FPaths::GetBaseFilename(PakContentPath, true));
}