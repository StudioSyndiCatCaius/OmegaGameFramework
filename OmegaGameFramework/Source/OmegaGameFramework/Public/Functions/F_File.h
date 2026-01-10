// Copyright Studio Syndicat 2022. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "F_File.generated.h"


UCLASS(Blueprintable,BlueprintType,EditInlineNew,Const,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaFileImportScript : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="FileImport")
	UClass* ImportClass;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="FileImport")
	TArray<FString> ValidExtensions;
	
	UFUNCTION(BlueprintImplementableEvent,Category="FileImport")
	UObject* ImportAsObject(const FString& path, const FString& name, const FString& extension, UGameInstance* GameInstance=nullptr) const;
};





UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaFileManagerSettings : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UObject* ImportFile(const FString& path) const;
	

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Instanced,Category="FileImporter")
	TArray<UOmegaFileImportScript*> ImportScripts;
	
};



UCLASS()
class UOmegaFileFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Omega|File")
	static TArray<FString> GetExternalContentDirectories();
	
	UFUNCTION(BlueprintCallable,Category="Omega|File")
	static TArray<FString> GetSubfolders(FString RootPath, bool OnlyNames=false);
	
	UFUNCTION(BlueprintCallable,Category="Omega|File|Import",meta=(AdvancedDisplay="MipGenSettings"))
	static UTexture2D* OmegaImport_Texture2D(const FString& FilePath,TEnumAsByte<TextureMipGenSettings> MipGenSettings);

	UFUNCTION(BlueprintCallable,Category="Omega|File|Import")
	static USoundWave* OmegaImport_Sound(const FString& FilePath, FString& Error);
};


