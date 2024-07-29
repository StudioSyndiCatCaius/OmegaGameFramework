// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MetasoundSource.h"
#include "Subsystems/OmegaSubsystem_Save.h"
#include "UObject/SoftObjectPath.h"

#include "OmegaSettings.generated.h"

class AOmegaGameplaySystem;
class UOmegaGameplayModule;
class UGamePreferenceFloat;
class UOmegaSlateStyle;
class UOmegaGameplayStyle;

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
	
	UPROPERTY(config) TArray<TSubclassOf<AOmegaGameplaySystem>> AutoActivatedGameplaySystems;
	TArray<TSubclassOf<UOmegaGameplayModule>> GetGameplayModuleClasses() const;
	UPROPERTY() TArray<FName> SystemScansPath;
	UPROPERTY() TArray<FString> LuaFields_AutoSavedToGame;
	UClass* GetOmegaGlobalSaveClass() const;
	
	//Will automatically scan these directories at startup to try and load and actiavate modules from them. NOTE: This can be a slow process. Try and only set these paths to folders containing GameplayModules.
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta = (MetaClass = "OmegaGameplayModule"))
	TArray<FDirectoryPath> AutoModuleScanPaths;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta = (MetaClass = "OmegaGameplayModule"))
	TArray<FSoftClassPath> RegisteredGameplayModules;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta=(MetaClass="OmegaSettings_Gameplay"))
	FSoftObjectPath DefaultSettings_Gameplay;
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta=(MetaClass="OmegaSettings_Paths"))
	FSoftObjectPath DefaultSettings_Paths;
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta=(MetaClass="OmegaFileManagerSettings"))
	FSoftObjectPath DefaultSettings_FileManager;
	//SAVE
	UClass* GetOmegaGameSaveClass() const;
	
	UPROPERTY(EditAnywhere, config, Category = "Save", meta = (MetaClass = "OmegaSaveGame"))
	FSoftClassPath GameSaveClass;
	
	UPROPERTY(EditAnywhere, config, Category = "Save")
	FString SaveGamePrefex = "save_";

	UPROPERTY(EditAnywhere, config, Category = "Save", meta = (MetaClass = "OmegaSaveGlobal"))
	FSoftClassPath GlobalSaveClass;

	UPROPERTY(EditAnywhere, config, Category = "Save")
	FString GlobalSaveName = "global";
	UPROPERTY()
    TArray<FString> LuaFields_AutoSavedToGlobal;

	//Writes save game properties to a Json String. If false, uses legacy method. NOTE: Seting this as 
	//Input

	// Root path used in the "Get Sorted Asset" function
	UPROPERTY(EditAnywhere, config, Category = "Assets", meta = (MetaClass = "OmegaGameplayModule"))
	FDirectoryPath SortedAssetsRootPath;
	
	UPROPERTY(EditAnywhere, config, Category = "Assets", meta = (MetaClass = "OmegaGameplayModule"))
    TMap<TSubclassOf<UObject>, FDirectoryPath> SortedAssetsRootPathByClass;

	UPROPERTY(EditAnywhere, config, Category = "Assets")
	TMap<FGameplayTag,FSoftObjectPath> GlobalIDAssets;

	UPROPERTY(EditAnywhere, config, Category = "Assets")
	TMap<FGameplayTag,FSoftClassPath> GlobalIDClasses;
	
	//########################################################
	//Preferences
	//########################################################
	//These paths will automatically scanned on Init. And game preferences found in them will be automatically loaded into the Game Preferences Subsystem.
	UPROPERTY(EditAnywhere, config, Category = "Game Preferences")
	TArray<FDirectoryPath> Preferences_ScanPaths;
	
	//########################################################
	//Player
	//########################################################
	UPROPERTY(EditAnywhere, config, Category = "Player", meta=(MetaClass="OmegaHoverCursor"))
	FSoftClassPath HoverCursorClass;

	UPROPERTY(EditAnywhere, config, Category = "Player", meta=(MetaClass="OmegaSettings_Slate"))
	FSoftObjectPath DefaultSettings_Slate;
	
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
	float BGM_FadeDuration = 1;
	
	UPROPERTY(EditAnywhere, config, Category = "BGM")
	bool FadeBGMOnLevelTransit = true;
	
	UPROPERTY(EditAnywhere, config, Category = "BGM", meta=(MetaClass="GamePreferenceFloat"))
	FSoftObjectPath BGM_VolumePreference;

	UPROPERTY(EditAnywhere, config, Category = "BGM", meta=(MetaClass="MetasoundSource"))
	FSoftObjectPath BgmMetasound{"/OmegaGameFramework/DEMO/MetaSound/DemoMS_BGM.DemoMS_BGM"};

	UMetaSoundSource* GetMetaSoundSourceFromPath() const
	{
		if (UMetaSoundSource* MetaSoundSource = Cast<UMetaSoundSource>(BgmMetasound.ResolveObject()))
		{
			return MetaSoundSource;
		}
		return nullptr;
	}
	
	//########################################################
	//Dyna Cam
	//########################################################
	UPROPERTY(EditAnywhere, config, Category = "Dynamic Camera", meta = (MetaClass = "OmegaDynamicCamera"))
	FSoftClassPath DynamicCameraClass;

	//########################################################
	//Zones
	//########################################################

	UPROPERTY(EditAnywhere, config, Category = "Zones", meta = (MetaClass = "OmegaGameplaySystem"))
	FSoftClassPath ZoneTransitSystem;

	UPROPERTY(EditAnywhere, config, Category = "Zones", meta = (MetaClass = "LevelSequence"))
	FSoftObjectPath TransitSequence;
	
	UPROPERTY(EditAnywhere, config, Category = "Zones")
	FGameplayTag ZoneBGMSlot;

	//########################################################
	//Mods
	//########################################################
	UPROPERTY(EditAnywhere, config, Category = "Mods", meta = (MetaClass = "OmegaModManager"))
	TArray<FString> ModPaths;
	UPROPERTY(EditAnywhere, config, Category = "Mods", meta = (MetaClass = "OmegaMod"))
    FSoftClassPath ModClass;
	
	UPROPERTY()
	FSoftClassPath ModManagerClass;
	
	
};

