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

// ========================================================
// ACHIEVEMENTS
// ========================================================

UCLASS(BlueprintType, Blueprintable,EditInlineNew, Const,Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaAchievementListener : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent,Category="Achievements")
	void OnBegin_GameInstance() const;

	UFUNCTION(BlueprintImplementableEvent,Category="Achievements")
	void OnBegin_GameWorld() const;

	UFUNCTION(BlueprintCallable,Category="Achievements")
	void UnlockAchievement() const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaAchievement : public UPrimaryDataAsset, public IDataInterface_General
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Achievement",DisplayName="Name")
	FText Achievement_Name;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Achievement",DisplayName="Icon")
	FSlateBrush Achievement_Icon;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Achievement",DisplayName="Description",meta=(MultiLine))
	FText Achievement_Description;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Achievement")
	int32 Score;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Instanced,Category="Achievement")
	TArray<UOmegaAchievementListener*> Listeners;

	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) override;
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) override;
};



UCLASS(BlueprintType, Blueprintable)
class OMEGAGAMEFRAMEWORK_API UOmegaPlatformAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	//Settings will first be imported from the parent asset, then overwritten by this asset's settings.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Platform")
	TArray<UOmegaPlatformAsset*> InheritedSettings;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Platform")
	TMap<FKey,FPlatformKeyInfo> KeyInfo;

	UFUNCTION(BlueprintCallable,Category="Key")
	FSlateBrush GetKeySlateBrush(FKey key) const
	{
		if(KeyInfo.Contains(key))
		{
			return KeyInfo.Find(key)->KeyIcon;
		}
		for(const auto* tempSet : InheritedSettings)
		{
			if(tempSet)
			{
				if(tempSet->KeyInfo.Contains(key))
				{
					return tempSet->GetKeySlateBrush(key);
				}
			}
		}
		return FSlateBrush();
	}
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
		if (UOmegaPlatformAsset* OmegaPlatformAsset = Cast<UOmegaPlatformAsset>(Path.TryLoad()))
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
	
	UFUNCTION(BlueprintPure, Category="Omega|Platform") 
	static FKey GetKeyFromName(const FString& KeyName);
	
	UFUNCTION(BlueprintPure, Category="Omega|Platform", meta = (WorldContext = "WorldContextObject", AdvancedDisplay="Flag, Context")) 
	static UOmegaPlatformAsset* GetCurrentPlatformAsset();
};


