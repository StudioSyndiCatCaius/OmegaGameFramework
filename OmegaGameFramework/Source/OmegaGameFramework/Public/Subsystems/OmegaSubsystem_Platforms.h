// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "InputCoreTypes.h"
#include "Interfaces/OmegaInterface_Common.h"
#include "UObject/SoftObjectPath.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaSubsystem_Platforms.generated.h"

USTRUCT(BlueprintType)
struct FPlatformKeyInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slate Brush")
	FSlateBrush KeyIcon;
};

UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaPlatformAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Key")
	TMap<FKey,FPlatformKeyInfo> KeyInfo;
};


UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Platform"))
class OMEGAGAMEFRAMEWORK_API UOmegaPlatformSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(MetaClass="OmegaPlatformAsset"))
	FSoftObjectPath DefaultPlatform;
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(MetaClass="OmegaPlatformAsset"))
	TMap<FString,FSoftObjectPath> PlatformAssets;

	UFUNCTION()
	UOmegaPlatformAsset* GetPlatformAsset() const;
	
private:
	UFUNCTION()
	UOmegaPlatformAsset* SoftRefToPlatformAsset(FSoftObjectPath Path) const
	{
		if (UOmegaPlatformAsset* OmegaPlatformAsset = Cast<UOmegaPlatformAsset>(Path.ResolveObject()))
		{
			return OmegaPlatformAsset;
		}
		return nullptr;
	}
	
};

UCLASS()
class UOmegaPlatformFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Omega|Platform", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static FSlateBrush GetCurrentPlatformActionIcon(const UObject* WorldContextObject, UInputAction* Action, APlayerController* Player);

	UFUNCTION(BlueprintPure, Category="Omega|Platform", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static FSlateBrush GetCurrentPlatformKeyIcon(const UObject* WorldContextObject, FKey Key, APlayerController* Player);
	UFUNCTION(BlueprintPure, Category="Omega|Platform", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static UOmegaPlatformAsset* GetCurrentPlatformAsset();
};
