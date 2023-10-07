// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UObject/SoftObjectPath.h"
#include "OmegaModSubsystem.h"
#include "OmegaModSettings.generated.h"


UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Mods"))
class OMEGAMOD_API UOmegaModSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(EditAnywhere, config, Category = "Modules", meta = (MetaClass = "OmegaModManager"))
	FSoftClassPath ModManagerClass;
	
	TSubclassOf<UOmegaModManager> GetOmegaModManagerClass() const
	{
		if(ModManagerClass.ResolveClass())
		{
			return ModManagerClass.ResolveClass();
		}
		return UOmegaModManager::StaticClass();
	}

};


