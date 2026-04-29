// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaValue.h"
#include "OmegaSettings.h"
#include "UObject/Object.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Misc/OmegaUtils_Enums.h"
#include "Types/Struct_SortedClassPath.h"
#include "GameplayTagContainer.h"
#include "OmegaGameManager.generated.h"

class UTurnBasedManagerComponent;
class UOmegaCombatEncounter_Component;
class UOmegaComponent;
class UOmegaGameAsset;
class UOmegaGameAsset_FlowNode;
class UGameplayActorComponent;
class UDataAssetCollectionComponent;
class UEquipmentComponent;
class UEquipmentSlot;
class UCombatantComponent;
class AOmegaGameplaySystem;
class UGameInstance;

UENUM(BlueprintType)
enum EOmegaGameInitState : uint8
{
	GameInitState_PostModules,
	GameInitState_PostLuaAutorun,
	GameInitState_PostModLoad,
	GameInitState_PostGamedataInit,
	GameInitState_PostGamedataLuaAutorun,
	GameInitState_PostModuleInit,
};


USTRUCT(BlueprintType)
struct FOmegaGameplaySystemConfig
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Gameplay Systems",DisplayName="💜Class")
	TSubclassOf<AOmegaGameplaySystem> SystemClass;
	UPROPERTY(VisibleDefaultsOnly,Category="Gameplay Systems", meta=(ShowInnerProperties, EditInline),DisplayName="🔵Template")
	TObjectPtr<AOmegaGameplaySystem> SystemTemplate;
	
	void ValidateTemplates(UObject* outer);
	static AOmegaGameplaySystem* GetConfigTemplate_System(TArray<FOmegaGameplaySystemConfig> configList, TSubclassOf<AOmegaGameplaySystem> system_class);
};



UCLASS(Const,Blueprintable,BlueprintType,meta=(ShowWorldContextPin),Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGameManager : public UObject
{
	GENERATED_BODY()
	
	void WorldInit(UWorld* World) const;

public:
	static TArray<FString> GetPathsFromAssetName(TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> paths, const FString& AssetName, TSubclassOf<UObject> Class);
	
#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif
    void ValidateTemplates();
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// UPROPERTIES
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="🔵Config") TArray<UOmegaGameplayModule*> GameplayModules;
	
	//Gameplay systems what will always be activated on startup
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🔵Config", meta=(ShowInnerProperties)) TArray<FOmegaGameplaySystemConfig> System_Config;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="🔵Config", meta=(ShowInnerProperties)) TArray<UMenu*> Menu_Config;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="🔵Config", meta=(ShowInnerProperties)) TArray<UHUDLayer*> HUD_Config;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🔵Config") TArray<TSubclassOf<AOmegaGameplaySystem>> Global_Systems;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🔵Config") TArray<TSubclassOf<UHUDLayer>> Global_HUDs;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="🔵Config|Assets")
    TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> ClassPaths;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// GAME
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_PreBegin(UGameInstance* GameInstance) const;

	//UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_InitStateChange(UGameInstance* GameInstance, TEnumAsByte<EOmegaGameInitState> InitState) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_Begin(UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_End(UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_LevelStart(UGameInstance* GameInstance, const FString& LevelName) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnWorldInit(UWorld* World) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Game") void OnGlobalEvent_Named(UGameInstance* Game_Instance, FName Event, UObject* context, FOmegaCommonMeta meta) const;
	UFUNCTION(BlueprintNativeEvent,Category="Game") void OnGlobalEvent_Tagged(UGameInstance* Game_Instance, FGameplayTag Event, UObject* context, FOmegaCommonMeta meta) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// OBJECT
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	//to deprecate?
	UFUNCTION() TArray<FName> Object_AppendMetatags(UObject* WorldContext, UObject* Object) const
	{
		return TArray<FName>();
	};
	UFUNCTION() FString Object_RunClassCommand(UObject* Object, int32 command) const
	{
		return "";
	};
	UFUNCTION() void Object_EditorHideVariables(UObject* Object, TArray<FName>& HiddenProperties, TArray<FName>& HiddenCategories) const
	{
		
	};
	
	UFUNCTION(BlueprintImplementableEvent,Category="Object") FText Object_OverrideName(UObject* Object,FGameplayTag Tag, bool& bOverride) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") FText Object_OverrideDescription(UObject* Object,FGameplayTag Tag, bool& bOverride) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") FSlateBrush Object_OverrideIcon(UObject* Object,FGameplayTag Tag, bool& bOverride) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Object") FString Object_OverrideSoftProperty(UObject* Object, FName ParamName) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") TArray<FString> Object_GetDefaultFlags(UObject* object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") UObject* Override_GetAssetFromPath(const FString& path, TSubclassOf<UObject> Class) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// ACTOR
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	//NOTE this only works for actors dereived from "OmegaCharacterBASE" or "OmegaGameplayActor"
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void Actor_OnConstruct(AActor* Actor) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void Actor_OnBeginPlay(AActor* Actor) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void Actor_OnTagEvent(AActor* Actor, FGameplayTag Event) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") FText Actor_GetDebugText(AActor* Actor) const;
	UFUNCTION(BlueprintNativeEvent,Category="Actor") bool Actor_CanSetTagTarget(AActor* Instigator,AActor* Target,FGameplayTag Tag) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void ActorID_OnConstruct(AActor* Actor,UGameplayActorComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void ActorID_OnBeginPlay(AActor* Actor,UGameplayActorComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void ActorID_IdentityInit(AActor* Actor,UGameplayActorComponent* Component,UPrimaryDataAsset* Identity) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void ActorID_IdentityUninit(AActor* Actor,UGameplayActorComponent* Component,UPrimaryDataAsset* Identity) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") TMap<FName,TSubclassOf<AActor>> Spawnable_GetNamed() const;
	
	
	void GetActorInstanceMetaParams(AActor* Actor,TArray<FName>& OutBoolParams,TArray<FName>& OutIntParams,TArray<FName>& OutFloatParams,
		TArray<FName>& OutStringParams, TArray<FName>& OutDataAssetParams, TArray<FName>& OutActorParams ) const
	{
		
	};
	
	UFUNCTION(BlueprintNativeEvent,Category="Actor") TArray<AActor*> ActorGroup_Filter(const UObject* WorldContext, FGameplayTag GroupTag,const TArray<AActor*>& InitialGroupActors) const;
	UFUNCTION(BlueprintNativeEvent,Category="Actor") bool ActorGroup_AllowActor(AActor* Actor,FGameplayTag GroupTag) const;
	
	// Get available relationship keys for a specific actor
	// This can be customized based on actor type, tags, etc.
	UFUNCTION(BlueprintImplementableEvent, Category = "Actor") TArray<FName> ActorRealtives_GetKeys(AActor* Actor) const;
	
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// COMPONENT
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintImplementableEvent, Category = "Component") void Component_BeginPlay(UOmegaComponent* Component,AActor* Owner) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Message
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintNativeEvent, Category = "Component") FSlateBrush Message_GetPortrait(UObject* WorldContext, const UOmegaGameplayMessage* Message) const;	
	
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// MISC
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	UFUNCTION(BlueprintImplementableEvent,Category="Global") bool Conditional_Check(UObject* WorldContext, FName conditional) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Save") void OnSave_Created(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Save") void OnSave_Started(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Save") void OnSave_Saved(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Combatant") float Attribute_GetMaxValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, int32 AttributeRank, float BaseValue) const;

	UFUNCTION(BlueprintNativeEvent,Category="UI") FText Text_PreGameplayFormat(const FText& Text, FGameplayTag Tag, FOmegaCommonMeta meta, UObject* WorldContext) const;
	UFUNCTION(BlueprintNativeEvent,Category="UI") FText Text_PostGameplayFormat(const FText& Text, FGameplayTag Tag, FOmegaCommonMeta meta, UObject* WorldContext) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Systems") void OnGameplaySystem_Activate(AOmegaGameplaySystem* System,UObject* Context, const FString& Flag) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Systems") void OnGameplaySystem_Notify(AOmegaGameplaySystem* System, UObject* Context, const FString& Notify) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Systems") void OnGameplaySystem_Shutdown(AOmegaGameplaySystem* System) const;	
	
	UFUNCTION(BlueprintImplementableEvent,Category="Lua") TArray<FName> Lua_OnObjectGeneration(UObject* Object, FLuaValue Key, FLuaValue Value) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Lua") FLuaValue Lua_GetObjectValue(UObject* Object) const;

	UFUNCTION(BlueprintNativeEvent,Category="FlowGraph") bool FlowNode_CanPlay(UObject* Node, FName Input) const;
	UFUNCTION(BlueprintImplementableEvent,Category="FlowGraph") void FlowNode_OnStart(UObject* Node, FName Input) const;
	UFUNCTION(BlueprintImplementableEvent,Category="FlowGraph") FLinearColor FlowNode_OverrideColor(UObject* Node, bool& OverrideColor) const;
	UFUNCTION(BlueprintImplementableEvent,Category="FlowGraph") FSlateBrush FlowNode_OverrideIcon(UObject* Node, bool& Override) const;
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// GameAsset
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintImplementableEvent,Category="GameAsset") TArray<TSubclassOf<UOmegaGameAsset_FlowNode>> GameAsset_AppendAcceptedNodes(const UOmegaGameAsset* Asset) const;
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Bitflag
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintImplementableEvent,Category="Bitflag") FOmegaBitmaskEditorData Bitflags_GetByObject(UClass* Object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Bitflag") TArray<FName> CustomList_GetOptions(FName ListID) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Bitflag") TArray<FName> CustomList_GetListFromObject(UObject* object) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Combatant
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	
	UFUNCTION(BlueprintNativeEvent,Category="Combatant") float Combatant_ModifyDamage_PreMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
													   UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const;
	UFUNCTION(BlueprintNativeEvent,Category="Combatant") float Combatant_ModifyDamage_PostMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
													   UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const;
	UFUNCTION(BlueprintImplementableEvent, Category = "Combatant")
	void Combatant_GetParamKeys(UCombatantComponent* Target,TArray<FName>& keys_bool,TArray<FName>& keys_int) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") TArray<UPrimaryDataAsset*> Combatant_Append_Skills(UCombatantComponent* Component) const;
	
	//UFUNCTION(BlueprintImplementableEvent,Category="Combatant") UPrimaryDataAsset* Equipment_OverrideSlot(UCombatantComponent* Component, UEquipmentSlot* Slot) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") TMap<UEquipmentSlot*,UPrimaryDataAsset*> Equipment_Append(UCombatantComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") TMap<UPrimaryDataAsset*,int32> Inventory_Append(UCombatantComponent* Component) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Encounter
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") void Encounter_Begin(UOmegaCombatEncounter_Component* Component,AOmegaCombatEncounter_Instance* Encounter) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") void Encounter_End(UOmegaCombatEncounter_Component* Component,AOmegaCombatEncounter_Instance* Encounter) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") void Encounter_BattlerSpawn(UOmegaCombatEncounter_Component* Component,ACharacter* Battler) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// TurnManager
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") void TurnManager_TurnStart(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") void TurnManager_TurnEnd(UTurnBasedManagerComponent* Component, UCombatantComponent* Combatant) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") void TurnManager_TurnFail(UTurnBasedManagerComponent* Component, const FString& Reason) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// Quest
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────

	UFUNCTION(BlueprintImplementableEvent, Category = "Omega")
	void Globals_GetParamKeys(EOmegaGlobalParamTarget Target,TArray<FName>& keys_bool,TArray<FName>& keys_int,TArray<FName>& keys_DataAsset) const;
	
	TArray<FName> L_GetGlobalParamKeys(EOmegaGlobalParamTarget Target,uint8 type) const;
	TArray<FName> L_GetCombatantParamKeys(UCombatantComponent* Target,uint8 type) const;
	
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	// 友Localization
	// ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────
	UFUNCTION(BlueprintNativeEvent,Category="Actor") USoundBase* Localization_GetClipFromPath(UObject* WorldContext, const FString& subpath, const FString& file) const;
};

/*
UCLASS(Const,Blueprintable,BlueprintType,meta=(ShowWorldContextPin),Abstract)
class OMEGAGAMEFRAMEWORK_API UOmegaGameManager : public UOmega_GameManager
{
	GENERATED_BODY()
};
*/
UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGameCore : public UOmegaGameManager
{
	GENERATED_BODY()
};