// Copyright Studio Syndicat 2021. All Rights Reserved.

/*=============================================================================
	OmegaSettings.h: Declares the OmegaSettings class.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "Animation/AnimInstance.h"
#include "Engine/SkeletalMesh.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_Bitflag.h"
#include "Types/Struct_CombatantConfig.h"
#include "Types/Struct_InputConfig.h"
#include "Types/Struct_SpawnableTypeConfig.h"
#include "GameFramework/Character.h"
#include "OmegaSettings.generated.h"

class UOmegaProceduralNamedAssetBuilder;
class UOmegaPhysicsSurfaceType;
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

	// Settings
	UPROPERTY(EditAnywhere, config, Category = "_CORE",DisplayName="⚛️ GAME MANAGER")
	TSoftClassPtr<UOmegaGameManager> GlobalSettingsClass;
	
	UPROPERTY(EditAnywhere, config, Category = "_CORE",DisplayName="⚛️ WORLD MANAGER",AdvancedDisplay)
	TSoftClassPtr<AOmegaWorldManager> WorldManagerClass;

	//These paths will automatically scanned on Init. 
	UPROPERTY(EditAnywhere, config, Category = "_CORE",AdvancedDisplay)
	TArray<FString> AutoscanPaths;
	UPROPERTY(EditAnywhere, config, Category = "_CORE",DisplayName="⚛️ Procedural Data Asset Builder")
	TSoftClassPtr<UOmegaProceduralNamedAssetBuilder> ProceduralDataAssetBuilderClass;
	
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
	UPROPERTY(EditAnywhere, config, Category = "👤Player") TSoftClassPtr<AOmegaDynamicCamera> DynamicCameraClass;
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) FGameplayTag InputAction_UI_Confirm=FGameplayTag::RequestGameplayTag("INPUT.UI.Confirm");
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) FGameplayTag InputAction_UI_Cancel=FGameplayTag::RequestGameplayTag("INPUT.UI.Cancel");
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) FGameplayTag InputAction_UI_Navigate=FGameplayTag::RequestGameplayTag("INPUT.UI.Nav");
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) float InputAction_UI_Navigate_Cooldown=0.4;
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) bool Input_ReplicateToPlayerController=true;
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) bool Input_ReplicateToPlayerPawn=true;
//	UPROPERTY(EditAnywhere, config, Category = "Player",AdvancedDisplay) bool Input_ReplicateToPlayerComponents=true;
	UPROPERTY(EditAnywhere, config, Category = "👤Player",AdvancedDisplay) bool Input_ReplicateToGameMode=true;
	// ---------------------------------------------------------------------------
	// Gameplay
	// ---------------------------------------------------------------------------
	UOmegaPhysicsSurfaceType* GetSurfaceTypeFromMaterial(UPhysicalMaterial* mat);
	
	UPROPERTY(EditAnywhere, config, Category = "🎮Gameplay")
	TArray<TSoftObjectPtr<UOmegaGameplayConfig>> Imported_GameplaySettings;
	
	TArray<UOmegaGameplayConfig*> GetAllGameplaySettings() const;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🎮Gameplay")
	TSoftObjectPtr<UOmegaPhysicsSurfaceType> DefaultSurfaceTypeData;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🎮Gameplay",meta=(ForceInlineRow,Categories="INPUT"))
	TMap<FGameplayTag,FOmegaInputConfig> InputActionConfigs;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🎮Gameplay")
	TArray<FKey> PersistentAxisKeys;
	
	TMap<FGameplayTag,FOmegaInputConfig> GetAllInputActionConfigs() const;
	FOmegaInputConfig GetInputActionConfig(FGameplayTag input_action) const;
	
	//SAVE
	UClass* GetOmegaGameSaveClass() const;
	
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🎮GAME Save - Class") TSoftClassPtr<UOmegaSaveGame> GameSaveClass;
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🎮GAME Save - Prefex") FString SaveGamePrefex = "save_";
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🌎GLOBAL Save - Class") TSoftClassPtr<UOmegaSaveGlobal> GlobalSaveClass;
	UPROPERTY(EditAnywhere, config, Category = "💾Save",DisplayName="🌎GLOBAL Save - Class") FString GlobalSaveName = "global";
	//If true, then in editor mode the "User Data" save path will redirect to "Gmae Data"/Project Save folder.
	UPROPERTY(EditAnywhere, config, Category = "💾Save") bool EditorUseProjectSaveForUserSave=true;

    // ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
    // Params
    // ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - Float")   TArray<FName> GlobalParams_float;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - Int32")   TArray<FName> GlobalParams_int32;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - String")  TArray<FName> GlobalParams_string;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - Asset")   TArray<FName> GlobalParams_asset;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - Bool",AdvancedDisplay)    TArray<FName> GlobalParams_bool;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - Vector",AdvancedDisplay)  TArray<FName> GlobalParams_vector;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="🌎 Global Params - Rotator",AdvancedDisplay) TArray<FName> GlobalParams_rotator;
	
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="👤 Entity Params - Int32")  TArray<FName> EntityParams_int32;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="👤 Entity Params - String") TArray<FName> EntityParams_string;
	UPROPERTY(EditAnywhere, config, Category = "🔹Params", DisplayName="👤 Entity Params - Bool",AdvancedDisplay)   TArray<FName> EntityParams_bool;

	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Combatant
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="✊Combatant",meta=(ShowOnlyInnerProperties))
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

	// Root path used in the "Get Sorted Asset" function
	UPROPERTY(EditAnywhere, config, Category = "Assets")
	FDirectoryPath SortedAssetsRootPath;
	
	UPROPERTY(EditAnywhere, config, Category = "Assets")
	TMap<TSubclassOf<UObject>, FDirectoryPath> SortedAssetsRootPathByClass;
	

	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Assets")
	TSoftObjectPtr<UOAsset_Appearance> Default_CharacterAppearance; // = TSoftObjectPtr<UOmegaAttributeSet>(FSoftObjectPath(TEXT()));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Assets")
	TSoftObjectPtr<UOmegaFaction> Default_Faction = TSoftObjectPtr<UOmegaAttributeSet>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Factions/Faction_Neutral.Faction_Neutral")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Assets")
	TSoftClassPtr<AOmegaActor_ChoiceBASE> DefaultChoiceInstance = TSoftClassPtr<AOmegaActor_ChoiceBASE>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Choice/OmegaDemo_Choice_Instance.OmegaDemo_Choice_Instance_C")));
		
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Assets")
	TSoftClassPtr<UDataWidget> Default_WorldMapPointWidget;
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Assets")
	TSoftClassPtr<UAnimInstance> DefaultCharacter_AnimClass = TSoftClassPtr<UAnimInstance>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Animation/ABP_OMEGA_Common.ABP_OMEGA_Common_C")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="Assets")
	TSoftClassPtr<ACharacter> Default_EncounterCharacter;
	
	UPROPERTY(EditAnywhere, config, Category = "Assets")
	TMap<TSoftClassPtr<AOmegaBaseCharacter>, TSoftClassPtr<UAnimInstance>> AnimBlueprint_PerClass;
	
	// ---------------------------------------------------------------------------
	// Spwanables
	// ---------------------------------------------------------------------------
	//Gives unique IDs to Attributes for quick access
	UPROPERTY(EditAnywhere, config, BlueprintReadOnly, Category = "Spwanables")
	TMap<FName,FOmegaSpawnableTypeConfig> SpawnableDefinitions;
	
	// ---------------------------------------------------------------------------
	// Zones
	// ---------------------------------------------------------------------------
	
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") bool bAutoSpawnAtFirstPoint=true;
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") bool bAutoplayZoneBgm=true;
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") bool bDynamicCameraViewTargetOnTransit=true;
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") float SpawnAtFirstPointDelay=0.1;
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") FGameplayTag ZoneBGMSlot;
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") FString LevelData_Suffix="_WorldData";
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🌎Level & Zone") TSoftClassPtr<AZoneEntityDisplayActor> DefaultZoneEntityDisplayActor = TSoftClassPtr<AZoneEntityDisplayActor>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Zone/EntityDisplay/ZoneEntityDisplay_Flat.ZoneEntityDisplay_Flat_C")));
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🌎Level & Zone") TSoftClassPtr<AOmegaGameplaySystem> ZoneTransitSystem = TSoftClassPtr<AOmegaGameplaySystem>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Systems/sys_OMEGA_E_ZoneTransit.sys_OMEGA_E_ZoneTransit_C")));
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🌎Level & Zone") TSoftObjectPtr<UNiagaraSystem> DefaultZoneTransitParticle  = TSoftObjectPtr<UNiagaraSystem>(FSoftObjectPath(TEXT("/OmegaGameFramework/Niagara/ns_OMEGA_Util_ZoneTransit.ns_OMEGA_Util_ZoneTransit")));;
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🌎Level & Zone") TSoftObjectPtr<ULevelSequence> Sequence_ZoneTransit  = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/Sequences/seq_OMEGA_TransitFade.seq_OMEGA_TransitFade")));;
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") bool SublevelSave_Autoload=true;
	//Prefex for autoloaded sublevels on Save param edit. E.G. if save param is "ExitState" and = 1, the sublevel loaded would be "mState_ExitState_1"
	UPROPERTY(EditAnywhere,config,Category = "🌎Level & Zone") FString SublevelSave_Prefix="mState_";
	// ---------------------------------------------------------------------------
	// BGM
	// ---------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, config, Category = "🎵BGM") float BGM_FadeDuration = 1;
	UPROPERTY(EditAnywhere, config, Category = "B🎵M") bool FadeBGMOnLevelTransit = true;

	UPROPERTY(EditAnywhere, config, Category = "🎵BGM")
	TSoftObjectPtr<UMetaSoundSource> BgmMetasound{FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/MetaSound/DemoMS_BGM.DemoMS_BGM"))};

	UMetaSoundSource* GetMetaSoundSourceFromPath() const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Patches
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "🔧Patches") FString PatchRootPath="/Game/5_Patches/";
	UPROPERTY(EditAnywhere, config, Category = "🔧Patches") FString PatchAssetName="GamePatch";
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//Mods
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UPROPERTY(EditAnywhere, config, Category = "📁External GameData")
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
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🛠️Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Reference = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Female_blue.SK_MannequinDemo_Female_blue")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🛠️Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Encounter = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_BlackRed.SK_MannequinDemo_Male_BlackRed")));
	
	UPROPERTY(EditAnywhere,config,BlueprintReadOnly,Category="🛠️Editor")
	TSoftObjectPtr<USkeletalMesh> CharacterMesh_Cinematic = TSoftObjectPtr<ULevelSequence>(FSoftObjectPath(TEXT("/OmegaGameFramework/DEMO/Mannequin/Mesh/SK_MannequinDemo_Male_green.SK_MannequinDemo_Male_green")));

	UPROPERTY(Config, EditAnywhere, Category = "🛠️Editor")
	TMap<TSoftClassPtr<AActor>, FString> ActorLabelDefaultOverrides;
	
	void OverrideActorLabel(AActor* actor,const FString& string="");
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	//BitFlags
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Map of UClass to BitFlag configuration
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "🚩BitFlags")
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


