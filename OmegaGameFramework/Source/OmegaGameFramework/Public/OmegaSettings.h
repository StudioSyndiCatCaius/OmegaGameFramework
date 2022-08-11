// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "GameFramework/SaveGame.h"
#include "Save/OmegaSaveGame.h"
#include "Save/OmegaSaveGlobal.h"
#include "Preferences/GamePreference.h"
#include "UObject/SoftObjectPath.h"

#include "OmegaSettings.generated.h"

class AOmegaGameplaySystem;
class UOmegaGameplayModule;

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Framework"))
class OMEGAGAMEFRAMEWORK_API UOmegaSettings : public UDeveloperSettings
{

	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(config)
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoActivatedGameplaySystems;

	TArray<TSubclassOf<UOmegaGameplayModule>> GetGameplayModuleClasses() const;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta = (MetaClass = "OmegaGameplayModule"))
	TArray<FSoftClassPath> RegisteredGameplayModules;

	UPROPERTY(EditAnywhere, config, Category = "DataItems")
	TArray<FName> SystemScansPath;
	
	//SAVE

	UClass* GetOmegaGameSaveClass() const;
	
	UPROPERTY(EditAnywhere, config, Category = "Save", meta = (MetaClass = "OmegaSaveGame"))
	FSoftClassPath GameSaveClass;

	UPROPERTY(EditAnywhere, config, Category = "Save")
		FString SaveGamePrefex = "save_";

	UClass* GetOmegaGlobalSaveClass() const;

	UPROPERTY(EditAnywhere, config, Category = "Save", meta = (MetaClass = "OmegaSaveGlobal"))
	FSoftClassPath GlobalSaveClass;

	UPROPERTY(EditAnywhere, config, Category = "Save")
	FString GlobalSaveName = "global";

	//Writes save game properties to a Json String. If false, uses legacy method. NOTE: Seting this as 
	
	
	//Widget

	//Preferences

};
