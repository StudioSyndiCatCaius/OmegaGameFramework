// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaValue.h"
#include "OmegaSettings.h"
#include "Misc/OmegaAttribute.h"
#include "UObject/Object.h"
#include "Misc/OmegaUtils_Structs.h"
#include "Types/Struct_SortedClassPath.h"
#include "GameplayTagContainer.h"
#include "OmegaGameCore.generated.h"


class UActorIdentityComponent;
class UDataAssetCollectionComponent;
class UEquipmentComponent;
class UEquipmentSlot;
class UCombatantComponent;
class AOmegaBaseSystem;
class UGameInstance;

UCLASS(Const,Blueprintable,BlueprintType,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaGameCore : public UObject
{
	GENERATED_BODY()
	
	void WorldInit(UWorld* World) const;

public:
	static TArray<FString> GetPathsFromAssetName(TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> paths, const FString& AssetName, TSubclassOf<UObject> Class);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Instanced,Category="Modules")
	TArray<UOmegaGameplayModule*> GameplayModules;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Assets")
    TMap<TSubclassOf<UObject>, FOmegaSortedClassPathData> ClassPaths;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_Begin(UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_End(UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnGame_LevelStart(UGameInstance* GameInstance, const FString& LevelName) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Game") void OnWorldInit(UWorld* World) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Object") TArray<FName> Object_AppendMetatags(UObject* WorldContext, UObject* Object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") FString Object_OverrideSoftProperty(UObject* Object, FName ParamName) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") FString Object_RunClassCommand(UObject* Object, int32 command) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") void Object_EditorHideVariables(UObject* Object, TArray<FName>& HiddenProperties, TArray<FName>& HiddenCategories) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") TArray<FString> Object_GetDefaultFlags(UObject* object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Object") UObject* Override_GetAssetFromPath(const FString& path, TSubclassOf<UObject> Class) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") FText Actor_GetDebugText(AActor* Actor) const;
	
	//NOTE this only works for actors dereived from "OmegaCharacterBASE" or "OmegaGameplayActor"
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void OmegaActor_OnConstruct(AActor* Actor) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void OmegaActor_OnBeginPlay(AActor* Actor) const;
	UFUNCTION(BlueprintNativeEvent, Category = "Omega")
	void GetActorInstanceMetaParams(
		AActor* Actor,
		TArray<FName>& OutBoolParams,
		TArray<FName>& OutIntParams,
		TArray<FName>& OutFloatParams,
		TArray<FName>& OutStringParams,
		TArray<FName>& OutDataAssetParams,
		TArray<FName>& OutActorParams
	) const;
	
	
	// Get available relationship keys for a specific actor
	// This can be customized based on actor type, tags, etc.
	UFUNCTION(BlueprintImplementableEvent, Category = "Actor") TArray<FName> ActorRealtives_GetKeys(AActor* Actor) const;
	
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void ActorID_OnConstruct(AActor* Actor,UActorIdentityComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void ActorID_OnBeginPlay(AActor* Actor,UActorIdentityComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Global") bool Conditional_Check(UObject* WorldContext, FName conditional) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Save") void OnSave_Created(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Save") void OnSave_Started(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Save") void OnSave_Saved(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Combatant") float Attribute_GetMaxValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, int32 AttributeRank, float BaseValue) const;

	UFUNCTION(BlueprintNativeEvent,Category="UI") FText Text_PreGameplayFormat(const FText& Text, FGameplayTag Tag, FOmegaCommonMeta meta, UObject* WorldContext) const;
	UFUNCTION(BlueprintNativeEvent,Category="UI") FText Text_PostGameplayFormat(const FText& Text, FGameplayTag Tag, FOmegaCommonMeta meta, UObject* WorldContext) const;
	

	UFUNCTION(BlueprintImplementableEvent,Category="Systems") void OnGameplaySystem_Activate(AOmegaBaseSystem* System,UObject* Context, const FString& Flag) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Systems") void OnGameplaySystem_Notify(AOmegaBaseSystem* System, UObject* Context, const FString& Notify) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Systems") void OnGameplaySystem_Shutdown(AOmegaBaseSystem* System) const;	
	
	UFUNCTION(BlueprintImplementableEvent,Category="Lua") TArray<FName> Lua_OnObjectGeneration(UObject* Object, FLuaValue Key, FLuaValue Value) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Lua") FLuaValue Lua_GetObjectValue(UObject* Object) const;

	UFUNCTION(BlueprintNativeEvent,Category="FlowGraph") bool FlowNode_CanPlay(UObject* Node, FName Input) const;
	UFUNCTION(BlueprintImplementableEvent,Category="FlowGraph") void FlowNode_OnStart(UObject* Node, FName Input) const;
	UFUNCTION(BlueprintImplementableEvent,Category="FlowGraph") FLinearColor FlowNode_OverrideColor(UObject* Node, bool& OverrideColor) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Bitflag") FOmegaBitmaskEditorData Bitflags_GetByObject(UClass* Object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Bitflag") TArray<FName> CustomList_GetOptions(FName ListID) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Bitflag") TArray<FName> CustomList_GetListFromObject(UObject* object) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Combatant") float Combatant_ModifyDamage_PreMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
													   UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const;
	UFUNCTION(BlueprintNativeEvent,Category="Combatant") float Combatant_ModifyDamage_PostMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
													   UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Combatant") TArray<UPrimaryDataAsset*> Combatant_Append_Skills(UCombatantComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Entity") TMap<UEquipmentSlot*,UPrimaryDataAsset*> Append_Equipment(UEquipmentComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Entity") TMap<UPrimaryDataAsset*,int32> Append_Inventory(UDataAssetCollectionComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void Quest_OnStart(UOmegaQuest* Quest, UOmegaQuestSubsystem* subsytem) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Actor") void Quest_OnEnd(UOmegaQuest* Quest, UOmegaQuestSubsystem* subsytem) const;
	UFUNCTION(BlueprintNativeEvent,Category="Actor") bool Quest_CanStart(UOmegaQuest* Quest, UOmegaQuestSubsystem* subsytem) const;
};

UCLASS()
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalSettings : public UOmegaGameCore
{
	GENERATED_BODY()
};
