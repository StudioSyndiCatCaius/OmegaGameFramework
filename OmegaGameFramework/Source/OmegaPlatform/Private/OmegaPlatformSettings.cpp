// Copyright Studio Syndicat 2021. All Rights Reserved.

#include "OmegaPlatformSettings.h"
#include "EnhancedInputSubsystems.h"
#include "Player/OmegaPlayerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Paths.h"

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
			if(PlatformAsset->KeyInfo.Contains(TempKey) && TempKey.IsGamepadKey()==TempPlayer->GetLocalPlayer()->GetSubsystem<UOmegaPlayerSubsystem>()->IsUsingGamepad())
			{
				return PlatformAsset->KeyInfo.FindOrAdd(TempKey).KeyIcon;
			}
		}
	}
	
	return FSlateBrush();
}

FSlateBrush UOmegaPlatformFunctions::GetCurrentPlatformKeyIcon(const UObject* WorldContextObject, FKey Key,
	APlayerController* Player)
{
	if(UOmegaPlatformAsset* PlatformAsset = GetMutableDefault<UOmegaPlatformSettings>()->GetPlatformAsset())
	{
		if(PlatformAsset->KeyInfo.Contains(Key))
		{
			return PlatformAsset->KeyInfo.Find(Key)->KeyIcon;
		}
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
