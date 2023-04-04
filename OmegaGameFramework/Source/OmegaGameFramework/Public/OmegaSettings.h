// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "OmegaAttribute.h"
#include "Engine/DeveloperSettings.h"

#include "GameFramework/SaveGame.h"
#include "Save/OmegaSaveGame.h"
#include "Save/OmegaSaveGlobal.h"
#include "Preferences/GamePreference.h"
#include "UObject/SoftObjectPath.h"

#include "OmegaSettings.generated.h"

class AOmegaGameplaySystem;
class UOmegaGameplayModule;
class UGamePreferenceFloat;

UENUM(BlueprintType)
enum class EOmegaInputModeType : uint8
{
	Game,
	UI,
	GameAndUI,
};


UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Framework"))
class OMEGAGAMEFRAMEWORK_API UOmegaSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	
	UPROPERTY(config)
	TArray<TSubclassOf<AOmegaGameplaySystem>> AutoActivatedGameplaySystems;

	TArray<TSubclassOf<UOmegaGameplayModule>> GetGameplayModuleClasses() const;

	//Will automatically scan these directories at startup to try and load and actiavate modules from them. NOTE: This can be a slow process. Try and only set these paths to folders containing GameplayModules.
	UPROPERTY(EditAnywhere, config, Category = "Modules", meta = (MetaClass = "OmegaGameplayModule"))
	TArray<FDirectoryPath> AutoModuleScanPaths;
	
	UPROPERTY(EditAnywhere, config, Category = "Modules", meta = (MetaClass = "OmegaGameplayModule"))
	TArray<FSoftClassPath> RegisteredGameplayModules;

	UPROPERTY()
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
	//Input
	
	//########################################################
	//Preferences
	//########################################################
	//These paths will automatically scanned on Init. And game preferences found in them will be automatically loaded into the Game Preferences Subsystem.
	UPROPERTY(EditAnywhere, config, Category = "Game Preferences")
	TArray<FDirectoryPath> Preferences_ScanPaths;

	//########################################################
	//Combat
	//########################################################
	//Gives unique IDs to Attributes for quick access
	UPROPERTY(EditAnywhere, config, Category = "Combatant", meta=(MetaClass="OmegaAttribute"))
	TMap<FString, FSoftObjectPath> AttributeIDs;

	//########################################################
	//BGM
	//########################################################
	UPROPERTY(EditAnywhere, config, Category = "BGM")
	float BGM_FadeDuration = 0.5;

	UPROPERTY(EditAnywhere, config, Category = "BGM", meta=(MetaClass="GamePreferenceFloat"))
	FSoftObjectPath BGM_VolumePreference;

	//########################################################
	//Dyna Cam
	//########################################################
	UPROPERTY(EditAnywhere, config, Category = "Dynamic Camera", meta = (MetaClass = "CameraActor"))
	FSoftClassPath DynamicCameraClass;

	//########################################################
	//Zones
	//########################################################
	
};
