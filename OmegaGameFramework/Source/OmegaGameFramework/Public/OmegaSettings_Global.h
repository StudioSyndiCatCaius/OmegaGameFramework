// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaValue.h"
#include "OmegaSettings.h"
#include "Misc/OmegaAttribute.h"
#include "UObject/Object.h"
#include "Misc/OmegaUtils_Structs.h"
#include "GameplayTagContainer.h"
#include "OmegaSettings_Global.generated.h"


class UActorIdentityComponent;
class UDataAssetCollectionComponent;
class UEquipmentComponent;
class UEquipmentSlot;
class UCombatantComponent;
class AOmegaBaseSystem;
class UGameInstance;

UCLASS(Const,Blueprintable,BlueprintType,meta=(ShowWorldContextPin))
class OMEGAGAMEFRAMEWORK_API UOmegaGlobalSettings : public UObject
{
	GENERATED_BODY()
	
	void WorldInit(UWorld* World) const;

public:
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnGame_Begin(UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnGame_End(UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnGame_LevelStart(UGameInstance* GameInstance, const FString& LevelName) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnWorldInit(UWorld* World) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TArray<FName> Object_AppendMetatags(UObject* WorldContext, UObject* Object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") FString Object_OverrideSoftProperty(UObject* Object, FName ParamName) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") FString Object_RunClassCommand(UObject* Object, int32 command) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void Object_EditorHideVariables(UObject* Object, TArray<FName>& HiddenProperties, TArray<FName>& HiddenCategories) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") bool Conditional_Check(UObject* WorldContext, FName conditional) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnSave_Created(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnSave_Started(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnSave_Saved(UOmegaSaveGame* Save,UGameInstance* GameInstance) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Keys") float Attribute_GetMaxValue(UCombatantComponent* Combatant, UOmegaAttribute* Attribute, int32 AttributeRank, float BaseValue) const;

	UFUNCTION(BlueprintNativeEvent,Category="Keys") FText Text_PreGameplayFormat(const FText& Text, FGameplayTag Tag, FOmegaCommonMeta meta) const;
	UFUNCTION(BlueprintNativeEvent,Category="Keys") FText Text_PostGameplayFormat(const FText& Text, FGameplayTag Tag, FOmegaCommonMeta meta) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") FText Actor_GetDebugText(AActor* Actor) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void ActorID_OnConstruct(AActor* Actor,UActorIdentityComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void ActorID_OnBeginPlay(AActor* Actor,UActorIdentityComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnGameplaySystem_Activate(AOmegaBaseSystem* System,UObject* Context, const FString& Flag) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnGameplaySystem_Notify(AOmegaBaseSystem* System, UObject* Context, const FString& Notify) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void OnGameplaySystem_Shutdown(AOmegaBaseSystem* System) const;	
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TArray<FName> OnLuaObjectGeneration(UObject* Object, FLuaValue Key, FLuaValue Value) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") FLuaValue Lua_GetObjectValue(UObject* Object) const;

	UFUNCTION(BlueprintNativeEvent,Category="Keys") bool FlowNode_CanPlay(UObject* Node, FName Input) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") void FlowNode_OnStart(UObject* Node, FName Input) const;
	

	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") FOmegaBitmaskEditorData Bitflags_GetByObject(UClass* Object) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TArray<FName> CustomList_GetOptions(FName ListID) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TArray<FName> CustomList_GetListFromObject(UObject* object) const;
	
	UFUNCTION(BlueprintNativeEvent,Category="Keys") float Combatant_ModifyDamage_PreMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
													   UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const;
	UFUNCTION(BlueprintNativeEvent,Category="Keys") float Combatant_ModifyDamage_PostMod(UOmegaAttribute* Attribute, UCombatantComponent* Target,
													   UCombatantComponent* Instigator, float BaseDamage, UOmegaDamageType* DamageType, UObject* Context) const;

	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TArray<UPrimaryDataAsset*> Combatant_Append_Skills(UCombatantComponent* Component) const;
	
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TMap<UEquipmentSlot*,UPrimaryDataAsset*> Append_Equipment(UEquipmentComponent* Component) const;
	UFUNCTION(BlueprintImplementableEvent,Category="Keys") TMap<UPrimaryDataAsset*,int32> Append_Inventory(UDataAssetCollectionComponent* Component) const;
};
