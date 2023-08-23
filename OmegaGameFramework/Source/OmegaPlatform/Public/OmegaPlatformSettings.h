// Copyright Studio Syndicat 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "OmegaPlatformAsset.h"
#include "UObject/SoftObjectPath.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OmegaPlatformSettings.generated.h"

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Platform"))
class OMEGAPLATFORM_API UOmegaPlatformSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(MetaClass="OmegaPlatformAsset"))
	FSoftObjectPath DefaultPlatform;
	UPROPERTY(EditAnywhere, Config, Category="Platforms", meta=(MetaClass="OmegaPlatformAsset"))
	TMap<FString,FSoftObjectPath> PlatformAssets;
	
	UOmegaPlatformAsset* GetPlatformAsset()  const
	{
		const FString PlatformName = FPlatformMisc::GetUBTPlatform();
		if(PlatformAssets.Contains(PlatformName))
		{
			return SoftRefToPlatformAsset(PlatformAssets[PlatformName]);
		}
		return SoftRefToPlatformAsset(DefaultPlatform);
	}

	
private:
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