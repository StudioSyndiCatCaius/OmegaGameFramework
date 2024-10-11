// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OmegaFunctions_Paker.generated.h"

UCLASS()
class UOmegaPakFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "PAK")
	static void MountAndRegisterPak(FString PakFilePath,bool& bIsMountSuccessful);

	UFUNCTION(BlueprintCallable, Category = "PAK")
	static bool MountPakFile(const FString& PakFilePath, const FString& PakMountPoint);

	UFUNCTION(BlueprintCallable, Category = "PAK")
	static bool UnmountPakFile(const FString& PakFilePath);

	UFUNCTION(BlueprintCallable, Category = "PAK")
	static void RegisterMountPoint(const FString& RootPath, const FString& ContentPath);

	UFUNCTION(BlueprintCallable, Category = "PAK")
	static void UnRegisterMountPoint(const FString& RootPath, const FString& ContentPath);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "PAK")
	static FString const GetPakMountPoint(const FString& PakFilePath);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "PAK")
	static TArray<FString> GetPakContent(const FString& PakFilePath, bool bOnlyCooked = true);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "PAK")
	static FString GetPakMountContentPath(const FString& PakFilePath);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PAK")
	static UClass* LoadPakObjClassReference(FString PakContentPath);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PAK")
	static UClass* LoadPakFileClass(const FString& FileName);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "PAK")
	static FString Conv_PakContentPathToReferenceString(const FString PakContentPath, const FString PakMountPath);
	
};
