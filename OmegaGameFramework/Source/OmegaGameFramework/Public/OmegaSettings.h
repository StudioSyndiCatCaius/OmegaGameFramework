// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "MetasoundSource.h"
#include "UObject/SoftObjectPath.h"
#include "Interfaces/I_BitFlag.h"
#include "OmegaSettings.generated.h"

class AOmegaAbility;
class UOmegaFileManagerSettings;
class UEquipmentSlot;
class UOmegaAttribute;
class UHUDLayer;
class UMenu;
class UOmegaActorConfig;
class AOmegaBaseCharacter;
class UDataWidget;
class UOmegaGlobalSettings;
class AOmegaGameplaySystem;
class UOmegaGameplayModule;
class UGamePreferenceFloat;
class UOmegaSlateStyle;
class UOmegaGameplayStyle;
class UOmegaSettings_Preferences;
class UOmegaSaveGame;
class UOmegaSaveGlobal;
class UOmegaAttributeSet;
class UOAsset_Appearance;
class UOmegaFaction;
class AOmegaActor_ChoiceBASE;
class AZoneEntityDisplayActor;
class UNiagaraSystem;
class ULevelSequence;
class UOmegaTextFormater_Collection;

UENUM(BlueprintType)
enum class EOmegaInputModeType : uint8
{
	Game,
	UI,
	GameAndUI,
};



//// Single entry for a bitflag
USTRUCT(BlueprintType)
struct FOmegaBitmaskEditorEntry
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	FText Title;
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega",meta=(MultiLine))
	FText Description;
	
	FOmegaBitmaskEditorEntry() : Title(FText::GetEmpty()) {}
};

// Data for a single BitEnum entry (has its own title and list of options)
USTRUCT(BlueprintType)
struct FOmegaBitmaskEditorEnumData
{
	GENERATED_BODY()
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	FText Title;
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega",meta=(MultiLine))
	FText Description;

	// Options for this enum (max 16 options, values 0-15)
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TArray<FOmegaBitmaskEditorEntry> Options;

	FOmegaBitmaskEditorEnumData() : Title(FText::GetEmpty()) {}
};

// Complete editor data for a bitflag type
USTRUCT(BlueprintType)
struct FOmegaBitmaskEditorData
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TSoftClassPtr<UObject> CopyFrom;
	
	// Bitflags section (up to 32 entries)
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TArray<FOmegaBitmaskEditorEntry> Bitflags;

	// BitEnums section (up to 16 entries, each with up to 16 options)
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Omega")
	TArray<FOmegaBitmaskEditorEnumData> BitEnums;
};

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Omega: Framework"))
class OMEGAGAMEFRAMEWORK_API UOmegaSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:

	TSubclassOf<AOmegaGameplaySystem> CorrectClass_System(TSubclassOf<AOmegaGameplaySystem> Class) const;
	TSubclassOf<UMenu> CorrectClass_Menu(TSubclassOf<UMenu> Class) const;
	TSubclassOf<UHUDLayer> CorrectClass_HUD(TSubclassOf<UHUDLayer> Class) const;
	
	UPROPERTY(config) TArray<TSubclassOf<AOmegaGameplaySystem>> AutoActivatedGameplaySystems;
	TArray<TSubclassOf<UOmegaGameplayModule>> GetGameplayModuleClasses() const;
	UPROPERTY() TArray<FName> SystemScansPath;
	UPROPERTY() TArray<FString> LuaFields_AutoSavedToGame;
	UClass* GetOmegaGlobalSaveClass() const;

	static UOmegaGlobalSettings* GetGlobalSettings();
	UOmegaFileManagerSettings* GetSettings_File() const;

	// Settings
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets")
	TSoftClassPtr<UOmegaGlobalSettings> GlobalSettingsClass;
	
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaSettings_Gameplay"))
	FSoftObjectPath DefaultSettings_Gameplay{"/OmegaGameFramework/Settings/Settings_OMEGA_Gameplay.Settings_OMEGA_Gameplay"};
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaSettings_Slate"))
	FSoftObjectPath DefaultSettings_Slate{"/OmegaGameFramework/Settings/Settings_OMEGA_Slate.Settings_OMEGA_Slate"};
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaSettings_Preferences"),AdvancedDisplay)
	FSoftObjectPath DefaultSettings_Preferences{"/OmegaGameFramework/Settings/Settings_OMEGA_Preferences.Settings_OMEGA_Preferences"};
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaSettings_Paths"), AdvancedDisplay)
	FSoftObjectPath DefaultSettings_Paths{"/OmegaGameFramework/Settings/Settings_OMEGA_Paths.Settings_OMEGA_Paths"};
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaFileManagerSettings"), AdvancedDisplay)
	FSoftObjectPath DefaultSettings_FileManager{"/OmegaGameFramework/Settings/Settings_OMEGA_File.Settings_OMEGA_File"};
	UPROPERTY(EditAnywhere, config, Category = "Settings Assets", meta=(MetaClass="OmegaSettings_Localization"), AdvancedDisplay)
	FSoftObjectPath DefaultSettings_Localization;

	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Settings Assets",AdvancedDisplay)
	TSoftObjectPtr<UOmegaTextFormater_Collection> DefaultSettings_Text;
	
	
	//Will automatically scan these directories at startup to try and load and actiavate modules from them. NOTE: This can be a slow process. Try and only set these paths to folders containing GameplayModules.
	//UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta = (MetaClass = "OmegaGameplayModule"))
	UPROPERTY()
	TArray<FDirectoryPath> AutoModuleScanPaths;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay", meta = (MetaClass = "OmegaGameplayModule"))
	TArray<FSoftClassPath> RegisteredGameplayModules;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay")
	TMap<TSoftClassPtr<AOmegaGameplaySystem>,TSoftClassPtr<AOmegaGameplaySystem>> Replacement_Systems;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay")
	TMap<TSoftClassPtr<UMenu>,TSoftClassPtr<UMenu>> Replacement_Menus;
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay")
	TMap<TSoftClassPtr<UHUDLayer>,TSoftClassPtr<UHUDLayer>> Replacement_HUDLayers;
	
	UPROPERTY(EditAnywhere, config, BlueprintReadOnly,Category = "Systems",DisplayName="⚙️ System - Flow Asset")
	TSoftClassPtr<AOmegaGameplaySystem> System_FlowAsset;
	UPROPERTY(EditAnywhere, config, BlueprintReadOnly,Category = "Systems",DisplayName="⚙️ System - Combat Encounter")
	TSoftClassPtr<AOmegaGameplaySystem> System_FlowEncounter;
	//System used by the "Interaction Component" by defaylt
	UPROPERTY(EditAnywhere, config, BlueprintReadOnly,Category = "Systems",DisplayName="⚙️ System - Interaction")
	TSoftClassPtr<AOmegaGameplaySystem> System_Interaction;
	//System used by the "Interaction Component" by Tag
	UPROPERTY(EditAnywhere, config, BlueprintReadOnly,Category = "Systems",DisplayName="⚙️ System - Interaction (By Tag)")
	TMap<FGameplayTag,TSoftClassPtr<AOmegaGameplaySystem>> System_Interaction_ByTag;
	
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
	
	//########################################################
	//Preferences
	//########################################################
	//These paths will automatically scanned on Init. And game preferences found in them will be automatically loaded into the Game Preferences Subsystem.
	UPROPERTY(EditAnywhere, config, Category = "Game Preferences")
	TArray<FDirectoryPath> Preferences_ScanPaths;
	
	//########################################################
	//Combat
	//########################################################
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant")
	TSoftObjectPtr<UOmegaAttributeSet> Default_AttributeSet = TSoftObjectPtr<UOmegaAttributeSet>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Attributes/AttSet_OMEGA_Demo.AttSet_OMEGA_Demo")));

	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant")
	TArray<TSoftClassPtr<AOmegaAbility>> Default_Abilities;
	
	//########################################################
	//Asset Defaults
	//########################################################
	

	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Asset - Defaults")
	TSoftObjectPtr<UOAsset_Appearance> Default_CharacterAppearance; // = TSoftObjectPtr<UOmegaAttributeSet>(FSoftObjectPath(TEXT()));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Asset - Defaults")
	TSoftObjectPtr<UOmegaFaction> Default_Faction = TSoftObjectPtr<UOmegaAttributeSet>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Factions/Faction_Neutral.Faction_Neutral")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Asset - Defaults")
	TSoftClassPtr<AOmegaActor_ChoiceBASE> DefaultChoiceInstance = TSoftClassPtr<AOmegaActor_ChoiceBASE>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Choice/OmegaDemo_Choice_Instance.OmegaDemo_Choice_Instance_C")));
		
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Asset - Defaults")
	TSoftClassPtr<UDataWidget> Default_WorldMapPointWidget;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Asset - Defaults")
	TSoftClassPtr<UAnimInstance> DefaultCharacter_AnimClass = TSoftClassPtr<UAnimInstance>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Animation/ABP_OMEGA_Common.ABP_OMEGA_Common_C")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Asset - Defaults")
	TSoftClassPtr<ACharacter> Default_EncounterCharacter;
	
	UPROPERTY(EditAnywhere, config, Category = "Asset - Per Class")
	TMap<TSoftClassPtr<AOmegaBaseCharacter>, TSoftClassPtr<UAnimInstance>> AnimBlueprint_PerClass;
	
	UPROPERTY(EditAnywhere, config, Category = "Asset - Per Class")
	TMap<TSoftClassPtr<AActor>, TSoftClassPtr<UDataWidget>> DataWidgets_PerClass;
	
	UPROPERTY(EditAnywhere, config, Category = "Asset - Per Class")
	TMap<TSoftClassPtr<AActor>, TSoftObjectPtr<UOmegaActorConfig>> ActorConfig_PerClass;
	
	// ---------------------------------------------------------------------------
	// Interaction
	// ---------------------------------------------------------------------------
	//Gives unique IDs to Attributes for quick access
	UPROPERTY(EditAnywhere, config, Category = "Interaction")
	FGameplayTag Default_InteractTag;
	
	// ---------------------------------------------------------------------------
	// Zones
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere,config,Category = "Zone") bool bAutoSpawnAtFirstPoint=true;
	UPROPERTY(EditAnywhere,config,Category = "Zone") bool bAutoplayZoneBgm=true;
	UPROPERTY(EditAnywhere,config,Category = "Zone") bool bDynamicCameraViewTargetOnTransit=true;
	UPROPERTY(EditAnywhere,config,Category = "Zone") float SpawnAtFirstPointDelay=0.1;
	UPROPERTY(EditAnywhere,config,Category = "Zone") FGameplayTag ZoneBGMSlot;
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftClassPtr<AZoneEntityDisplayActor> DefaultZoneEntityDisplayActor = TSoftClassPtr<AZoneEntityDisplayActor>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Zone/EntityDisplay/ZoneEntityDisplay_Flat.ZoneEntityDisplay_Flat_C")));
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftClassPtr<AOmegaGameplaySystem> ZoneTransitSystem = TSoftClassPtr<AOmegaGameplaySystem>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_ZoneTransit.sys_OMEGA_E_ZoneTransit_C")));
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftObjectPtr<UNiagaraSystem> DefaultZoneTransitParticle  = TSoftObjectPtr<UNiagaraSystem>(FSoftObjectPath(TEXT("/OmegaGameFramework/Niagara/ns_OMEGA_Util_ZoneTransit.ns_OMEGA_Util_ZoneTransit")));;
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftObjectPtr<ULevelSequence> Sequence_ZoneTransit  = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/Sequences/seq_OMEGA_TransitFade.seq_OMEGA_TransitFade")));;
	
	// ---------------------------------------------------------------------------
	// BGM
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, config, Category = "BGM")
	float BGM_FadeDuration = 1;
	
	UPROPERTY(EditAnywhere, config, Category = "BGM")
	bool FadeBGMOnLevelTransit = true;

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
	//Mods
	//########################################################
	UPROPERTY(EditAnywhere, config, Category = "File")
	bool bAutogenerateUAsset;
	
	//On Startup will automatically attempt to load any files listed in the `RuntimeImport_BaseDirectory` paths into the `AssetHandler Subsystem`, provided they listed in the `DefaultSettings_File` asset
	UPROPERTY(EditAnywhere, config, Category = "File")
	bool bAutoImportRuntimeAssets;
	UPROPERTY(EditAnywhere, config, Category = "File")
	TArray<FString> RuntimeImport_BaseDirectory;
	
	UPROPERTY(EditAnywhere, config, Category = "Mods")
	bool bAutoInitializeMods=true;
	UPROPERTY(EditAnywhere, config, Category = "Mods", meta = (MetaClass = "OmegaModManager"))
	TArray<FString> ModPaths;
	UPROPERTY(EditAnywhere, config, Category = "Mods", meta = (MetaClass = "OmegaMod"))
    FSoftClassPath ModClass;
	
	UPROPERTY()
	FSoftClassPath ModManagerClass;
	
	// ---------------------------------------------------------------------------
	// EDITOR
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Reference = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Female_blue.SK_MannequinDemo_Female_blue")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Encounter = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_BlackRed.SK_MannequinDemo_Male_BlackRed")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Cinematic = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_green.SK_MannequinDemo_Male_green")));

	
	//########################################################
	//BitFlags
	//########################################################
	// Map of UClass to BitFlag configuration
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "BitFlags")
	TMap<TSoftClassPtr<UObject>, FOmegaBitmaskEditorData> ClassBitflagData;

	
	// Helper function to get editor data based on class
	const FOmegaBitmaskEditorData* GetEditorDataForClass(UClass* Class) const;

	// Helper function to get a bitflag name
	UFUNCTION(BlueprintCallable, Category = "Omega")
	FText GetBitflagName(UClass* Class, int32 BitIndex) const;

	// Helper function to get a bitenum name
	UFUNCTION(BlueprintCallable, Category = "Omega")
	FText GetBitEnumName(UClass* Class, int32 EnumIndex) const;

	// Helper function to get a bitenum option name
	UFUNCTION(BlueprintCallable, Category = "Omega")
	FText GetBitEnumOptionName(UClass* Class, int32 EnumIndex, int32 OptionIndex) const;

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	

};


