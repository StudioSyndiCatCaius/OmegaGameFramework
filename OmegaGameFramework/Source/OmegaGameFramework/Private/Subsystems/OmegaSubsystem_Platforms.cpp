// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "Subsystems/OmegaSubsystem_Platforms.h"
#include "EnhancedInputSubsystems.h"
#include "InputCoreTypes.h"
#include "Subsystems/OmegaSubsystem_Player.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Paths.h"

void UOmegaAchievementListener::UnlockAchievement() const
{
	// unlock cod goes here
}

void UOmegaAchievement::GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name,
	FText& Description)
{
	Name=Achievement_Name;
	Description=Achievement_Description;
}

void UOmegaAchievement::GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context,
	UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
{
	Brush=Achievement_Icon;
}

UOmegaPlatformAsset* UOmegaPlatformSettings::GetPlatformAsset() const
{
	const FString PlatformName = FPlatformMisc::GetUBTPlatform();
	if(PlatformAssets.Contains(PlatformName))
	{
		return SoftRefToPlatformAsset(PlatformAssets[PlatformName]);
	}
	return SoftRefToPlatformAsset(DefaultPlatform);
}

FSlateBrush UOmegaPlatformFunctions::GetCurrentPlatformActionIcon(const UObject* WorldContextObject, UInputAction* Action, APlayerController* Player)
{
	const APlayerController* TempPlayer = UGameplayStatics::GetPlayerController(WorldContextObject,0);
	FSlateBrush OutBrush;
	if(Player)
	{
		TempPlayer = Player;
	}
	if(!Player)
	{
		return FSlateBrush();
	}
	
	if(UOmegaPlatformAsset* PlatformAsset = GetMutableDefault<UOmegaPlatformSettings>()->GetPlatformAsset())
	{
		UEnhancedInputLocalPlayerSubsystem* InputSubsys = TempPlayer->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		TArray<FKey> TempKeys = InputSubsys->QueryKeysMappedToAction(Action);
	
		for(FKey TempKey : TempKeys)
		{
			if(TempKey.IsGamepadKey()==TempPlayer->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->IsUsingGamepad())
			{
				return PlatformAsset->GetKeySlateBrush(TempKey);
			}
		}
	}
	
	return FSlateBrush();
}

FSlateBrush UOmegaPlatformFunctions::GetCurrentPlatformKeyIcon(const UObject* WorldContextObject, FKey Key,
	APlayerController* Player)
{
	if(const UOmegaPlatformAsset* PlatformAsset = GetMutableDefault<UOmegaPlatformSettings>()->GetPlatformAsset())
	{
		return PlatformAsset->GetKeySlateBrush(Key);
	}
	return FSlateBrush();
}

UOmegaPlatformAsset* UOmegaPlatformFunctions::GetCurrentPlatformAsset()
{
	if(UOmegaPlatformAsset* PlatformAsset = GetMutableDefault<UOmegaPlatformSettings>()->GetPlatformAsset())
	{
		return PlatformAsset;
	}
	return nullptr;
}
