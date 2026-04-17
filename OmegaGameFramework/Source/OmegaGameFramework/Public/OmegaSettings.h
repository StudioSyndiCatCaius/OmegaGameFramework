// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_Bitflag.h"
#include "Types/Struct_CombatantConfig.h"
#include "Types/Struct_InputConfig.h"
#include "OmegaSettings.generated.h"

class AOmegaWorldManager;
class UMetaSoundSource;

class UOmegaSettings_Localization;
class AOmegaDynamicCamera;
class UOmegaMod;
class UOmegaGameplayConfig;
class AOmegaAbility;
class UOmegaFileManagerSettings;
class UEquipmentSlot;
class UOmegaAttribute;
class UHUDLayer;
class UMenu;
class UOmegaActorConfig;
class AOmegaBaseCharacter;
class UDataWidget;
class UOmegaGameManager;
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

	UOmegaGameManager* GetGameCore() const;
	UOmegaFileManagerSettings* GetSettings_File() const;

	// Settings
	UPROPERTY(EditAnywhere, config, Category = "_CORE",DisplayName="⚛️ GAME CORE")
	TSoftClassPtr<UOmegaGameManager> GlobalSettingsClass;
	
	UPROPERTY(EditAnywhere, config, Category = "_CORE",DisplayName="⚛️ WORLD MANAGER",AdvancedDisplay)
	TSoftClassPtr<AOmegaWorldManager> WorldManagerClass;
	
	UPROPERTY(EditAnywhere, config, Category = "_CORE", AdvancedDisplay)
	TSoftObjectPtr<UOmegaSettings_Localization> DefaultSettings_Localization;

	UPROPERTY()
	TSoftObjectPtr<UOmegaTextFormater_Collection> DefaultSettings_Text;
	
	// ---------------------------------------------------------------------------
	// Custom Params
	// ---------------------------------------------------------------------------
	UPROPERTY() TMap<FName, bool> CustomParams_Bool;
	UPROPERTY() TMap<FName, int32> CustomParams_Int32;
	UPROPERTY() TMap<FName, float> CustomParams_Float;
	UPROPERTY() TMap<FName, FString> CustomParams_String;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Player
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "Player") TSoftClassPtr<AOmegaDynamicCamera> DynamicCameraClass;
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) FGameplayTag InputAction_UI_Confirm=FGameplayTag::RequestGameplayTag("INPUT.UI.Confirm");
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) FGameplayTag InputAction_UI_Cancel=FGameplayTag::RequestGameplayTag("INPUT.UI.Cancel");
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) FGameplayTag InputAction_UI_Navigate=FGameplayTag::RequestGameplayTag("INPUT.UI.Nav");
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) float InputAction_UI_Navigate_Cooldown=0.4;
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) bool Input_ReplicateToPlayerController=true;
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) bool Input_ReplicateToPlayerPawn=true;
	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) bool Input_ReplicateToGameMode=true;
	// ---------------------------------------------------------------------------
	// Gameplay
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere, config, Category = "Gameplay")
	TArray<TSoftObjectPtr<UOmegaGameplayConfig>> Imported_GameplaySettings;
	
	TArray<UOmegaGameplayConfig*> GetAllGameplaySettings() const;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Gameplay")
	TMap<FGameplayTag,FOmegaInputConfig> InputActionConfigs;
	
	TMap<FGameplayTag,FOmegaInputConfig> GetAllInputActionConfigs() const;
	FOmegaInputConfig GetInputActionConfig(FGameplayTag input_action) const;
	
	
	UPROPERTY()
	TMap<TSoftClassPtr<AOmegaGameplaySystem>,TSoftClassPtr<AOmegaGameplaySystem>> Replacement_Systems;
	
	UPROPERTY()
	TMap<TSoftClassPtr<UMenu>,TSoftClassPtr<UMenu>> Replacement_Menus;
	
	UPROPERTY()
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
	
	UFUNCTION(BlueprintPure, Category="Omega|Settings") TSubclassOf<AOmegaGameplaySystem> GetSystem_FlowAsset() const;
	UFUNCTION(BlueprintPure, Category="Omega|Settings") TSubclassOf<AOmegaGameplaySystem> GetSystem_Encounter() const;
	UFUNCTION(BlueprintPure, Category="Omega|Settings") TSubclassOf<AOmegaGameplaySystem> GetSystem_Interact() const;
	
	//SAVE
	UClass* GetOmegaGameSaveClass() const;
	
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🎮GAME Save - Class") TSoftClassPtr<UOmegaSaveGame> GameSaveClass;
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🎮GAME Save - Prefex") FString SaveGamePrefex = "save_";
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🌎GLOBAL Save - Class") TSoftClassPtr<UOmegaSaveGlobal> GlobalSaveClass;
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🌎GLOBAL Save - Class") FString GlobalSaveName = "global";

	//Writes save game properties to a Json String. If false, uses legacy method. NOTE: Seting this as 
	//Input
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Constants
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ (Class) System") TMap<FName,TSoftClassPtr<AOmegaGameplaySystem>> Constant_Systems;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ (Class) Menu") TMap<FName,TSoftClassPtr<UMenu>> Constant_Menus;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ (Class) HUD Layer") TMap<FName,TSoftClassPtr<UHUDLayer>> Constant_Huds;
	//UPROPERTY(EditAnywhere, config, Category = "♾️Constants") TMap<FName,TSoftClassPtr<AActor>> Constant_Actors;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ (Class) Data Asset") TMap<FName,TSoftClassPtr<UPrimaryDataAsset>> Constant_DataAssetsClass;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ Int") TMap<FName,int32> Constant_int;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ Float") TMap<FName,float> Constant_float;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ String") TMap<FName,FString> Constant_string;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ Data Asset") TMap<FName,TSoftObjectPtr<UPrimaryDataAsset>> Constant_DataAsset;
	UPROPERTY(EditAnywhere, config, Category = "♾️Constants",DisplayName="♾️ Data Asset (List)") TMap<FName,FOmegaList_DataAsset_Soft> Constant_DataAssetList;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Assets
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	// Root path used in the "Get Sorted Asset" function
	UPROPERTY(EditAnywhere, config, Category = "Assets")
	FDirectoryPath SortedAssetsRootPath;
	
	UPROPERTY(EditAnywhere, config, Category = "Assets")
    TMap<TSubclassOf<UObject>, FDirectoryPath> SortedAssetsRootPathByClass;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//Preferences
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//These paths will automatically scanned on Init. And game preferences found in them will be automatically loaded into the Game Preferences Subsystem.
	UPROPERTY(EditAnywhere, config, Category = "Game Preferences")
	TArray<FDirectoryPath> Preferences_ScanPaths;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Combatant
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant")
	FOmegaCombatantConfig CombatantConfig_Default;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant")
	TMap<TSoftClassPtr<AActor>,FOmegaCombatantConfig> CombatantConfig_ByClass;
	
	FOmegaCombatantConfig L_GetCombatantConfigFromActor(AActor* Actor);
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant")
	TEnumAsByte<EFactionAffinity> Default_FactionAffinity;
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant", meta=(ForceInlineRow))
	TMap<FGameplayTag,TEnumAsByte<EFactionAffinity>> Default_FactionTagAffinity;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant",AdvancedDisplay)
	TSoftObjectPtr<UPrimaryDataAsset> GlobalEntityIdentity = TSoftObjectPtr<UPrimaryDataAsset>(FSoftObjectPath(TEXT("/OmegaGameFramework/DataAssets/_misc/_GLOBAL._GLOBAL")));
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//Asset Defaults
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	

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
	UPROPERTY(EditAnywhere, config, BlueprintReadOnly, Category = "Interaction")
	FGameplayTag Default_InteractTag;
	
	// ---------------------------------------------------------------------------
	// Zones
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere,config,Category = "Zone") bool bAutoSpawnAtFirstPoint=true;
	UPROPERTY(EditAnywhere,config,Category = "Zone") bool bAutoplayZoneBgm=true;
	UPROPERTY(EditAnywhere,config,Category = "Zone") bool bDynamicCameraViewTargetOnTransit=true;
	UPROPERTY(EditAnywhere,config,Category = "Zone") float SpawnAtFirstPointDelay=0.1;
	UPROPERTY(EditAnywhere,config,Category = "Zone") FGameplayTag ZoneBGMSlot;
	UPROPERTY(EditAnywhere,config,Category = "Level") FString LevelData_Suffix="_WorldData";
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftClassPtr<AZoneEntityDisplayActor> DefaultZoneEntityDisplayActor = TSoftClassPtr<AZoneEntityDisplayActor>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Zone/EntityDisplay/ZoneEntityDisplay_Flat.ZoneEntityDisplay_Flat_C")));
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftClassPtr<AOmegaGameplaySystem> ZoneTransitSystem = TSoftClassPtr<AOmegaGameplaySystem>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_ZoneTransit.sys_OMEGA_E_ZoneTransit_C")));
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftObjectPtr<UNiagaraSystem> DefaultZoneTransitParticle  = TSoftObjectPtr<UNiagaraSystem>(FSoftObjectPath(TEXT("/OmegaGameFramework/Niagara/ns_OMEGA_Util_ZoneTransit.ns_OMEGA_Util_ZoneTransit")));;
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Zone") TSoftObjectPtr<ULevelSequence> Sequence_ZoneTransit  = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/Sequences/seq_OMEGA_TransitFade.seq_OMEGA_TransitFade")));;
	UPROPERTY(EditAnywhere,config,Category = "Level") bool SublevelSave_Autoload=true;
	//Prefex for autoloaded sublevels on Save param edit. E.G. if save param is "ExitState" and = 1, the sublevel loaded would be "mState_ExitState_1"
	UPROPERTY(EditAnywhere,config,Category = "Level") FString SublevelSave_Prefix="mState_";
	// ---------------------------------------------------------------------------
	// BGM
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, config, Category = "BGM") float BGM_FadeDuration = 1;
	UPROPERTY(EditAnywhere, config, Category = "BGM") bool FadeBGMOnLevelTransit = true;

	UPROPERTY(EditAnywhere, config, Category = "BGM")
	TSoftObjectPtr<UMetaSoundSource> BgmMetasound{FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/MetaSound/DemoMS_BGM.DemoMS_BGM"))};

	UMetaSoundSource* GetMetaSoundSourceFromPath() const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//Mods
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "File")
	bool bAutogenerateUAsset;
	
	//On Startup will automatically attempt to load any files listed in the `RuntimeImport_BaseDirectory` paths into the `AssetHandler Subsystem`, provided they listed in the `DefaultSettings_File` asset
	UPROPERTY(EditAnywhere, config, Category = "📁External GameData")
	bool bAutoImportGameData;
	UPROPERTY(EditAnywhere, config, Category = "📁External GameData")
	FString GameData_Base_Directory="/GameData/";
	UPROPERTY(EditAnywhere, config, Category = "📁External GameData")
	FString GameData_LuaAutorun_Directory="/lua/autorun/";
	UPROPERTY(EditAnywhere, config, Category = "📁External GameData")
	bool bEnableMods;
	UPROPERTY(EditAnywhere, config, Category = "📁External GameData")
	TSoftClassPtr<UOmegaMod> ModClass;

	// ---------------------------------------------------------------------------
	// EDITOR
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Reference = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Female_blue.SK_MannequinDemo_Female_blue")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Encounter = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_BlackRed.SK_MannequinDemo_Male_BlackRed")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Cinematic = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_green.SK_MannequinDemo_Male_green")));

	UPROPERTY(Config, EditAnywhere, Category = "Editor")
	TMap<TSoftClassPtr<AActor>, FString> ActorLabelDefaultOverrides;
	
	void OverrideActorLabel(AActor* actor,const FString& string="");
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//BitFlags
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
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


