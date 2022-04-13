// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCombatantComponent;
class UOmegaAttribute;
class UObject;
struct FGameplayTagContainer;
struct FGameplayTag;
class AOmegaGameplayEffect;
class UAttributeModifierContainer;
class UOmegaAttribute; 
class AOmegaAbility;
class APlayerController;
class AController;
class ACharacter;
class APawn;
class UPrimaryDataAsset;
#ifdef OMEGAGAMEFRAMEWORK_CombatantComponent_generated_h
#error "CombatantComponent.generated.h already included, missing '#pragma once' in CombatantComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_CombatantComponent_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_42_DELEGATE \
struct _Script_OmegaGameFramework_eventOnDamaged_Parms \
{ \
	UCombatantComponent* Combatant; \
	UOmegaAttribute* Attribute; \
	float FinalDamage; \
	UObject* Instigator; \
}; \
static inline void FOnDamaged_DelegateWrapper(const FMulticastScriptDelegate& OnDamaged, UCombatantComponent* Combatant, UOmegaAttribute* Attribute, float FinalDamage, UObject* Instigator) \
{ \
	_Script_OmegaGameFramework_eventOnDamaged_Parms Parms; \
	Parms.Combatant=Combatant; \
	Parms.Attribute=Attribute; \
	Parms.FinalDamage=FinalDamage; \
	Parms.Instigator=Instigator; \
	OnDamaged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_43_DELEGATE \
struct _Script_OmegaGameFramework_eventOnCombatantLevelChange_Parms \
{ \
	int32 NewLevel; \
}; \
static inline void FOnCombatantLevelChange_DelegateWrapper(const FMulticastScriptDelegate& OnCombatantLevelChange, int32 NewLevel) \
{ \
	_Script_OmegaGameFramework_eventOnCombatantLevelChange_Parms Parms; \
	Parms.NewLevel=NewLevel; \
	OnCombatantLevelChange.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_45_DELEGATE \
struct _Script_OmegaGameFramework_eventOnTargetAdded_Parms \
{ \
	UCombatantComponent* Target; \
}; \
static inline void FOnTargetAdded_DelegateWrapper(const FMulticastScriptDelegate& OnTargetAdded, UCombatantComponent* Target) \
{ \
	_Script_OmegaGameFramework_eventOnTargetAdded_Parms Parms; \
	Parms.Target=Target; \
	OnTargetAdded.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_46_DELEGATE \
struct _Script_OmegaGameFramework_eventOnTargetRemoved_Parms \
{ \
	UCombatantComponent* Target; \
}; \
static inline void FOnTargetRemoved_DelegateWrapper(const FMulticastScriptDelegate& OnTargetRemoved, UCombatantComponent* Target) \
{ \
	_Script_OmegaGameFramework_eventOnTargetRemoved_Parms Parms; \
	Parms.Target=Target; \
	OnTargetRemoved.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_47_DELEGATE \
struct _Script_OmegaGameFramework_eventOnAddedAsTarget_Parms \
{ \
	UCombatantComponent* Instigator; \
}; \
static inline void FOnAddedAsTarget_DelegateWrapper(const FMulticastScriptDelegate& OnAddedAsTarget, UCombatantComponent* Instigator) \
{ \
	_Script_OmegaGameFramework_eventOnAddedAsTarget_Parms Parms; \
	Parms.Instigator=Instigator; \
	OnAddedAsTarget.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_48_DELEGATE \
struct _Script_OmegaGameFramework_eventOnRemovedAsTarget_Parms \
{ \
	UCombatantComponent* Instigator; \
}; \
static inline void FOnRemovedAsTarget_DelegateWrapper(const FMulticastScriptDelegate& OnRemovedAsTarget, UCombatantComponent* Instigator) \
{ \
	_Script_OmegaGameFramework_eventOnRemovedAsTarget_Parms Parms; \
	Parms.Instigator=Instigator; \
	OnRemovedAsTarget.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_49_DELEGATE \
struct _Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms \
{ \
	UCombatantComponent* ActiveTarget; \
	bool Valid; \
}; \
static inline void FOnActiveTargetChanged_DelegateWrapper(const FMulticastScriptDelegate& OnActiveTargetChanged, UCombatantComponent* ActiveTarget, bool Valid) \
{ \
	_Script_OmegaGameFramework_eventOnActiveTargetChanged_Parms Parms; \
	Parms.ActiveTarget=ActiveTarget; \
	Parms.Valid=Valid ? true : false; \
	OnActiveTargetChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClearActiveTarget); \
	DECLARE_FUNCTION(execSetActiveTarget); \
	DECLARE_FUNCTION(execClearTargetList); \
	DECLARE_FUNCTION(execRemoveTargetFromList); \
	DECLARE_FUNCTION(execAddTargetsToList); \
	DECLARE_FUNCTION(execAddTargetToList); \
	DECLARE_FUNCTION(execRemoveEffectsWithTags); \
	DECLARE_FUNCTION(execRemoveEffectsOfCategory); \
	DECLARE_FUNCTION(execGetValidActiveEffects); \
	DECLARE_FUNCTION(execGetActiveEffectOfClass); \
	DECLARE_FUNCTION(execGetEffectsOfCategory); \
	DECLARE_FUNCTION(execGetEffectsWithTags); \
	DECLARE_FUNCTION(execTriggerEffectsOfCategory); \
	DECLARE_FUNCTION(execTriggerEffectsWithTags); \
	DECLARE_FUNCTION(execCreateEffect); \
	DECLARE_FUNCTION(execGetAttributeModifiers); \
	DECLARE_FUNCTION(execGetAttributeComparedValue); \
	DECLARE_FUNCTION(execRemoveAttributeModifersWithTags); \
	DECLARE_FUNCTION(execRemoveAttributeModifier); \
	DECLARE_FUNCTION(execAddAttrbuteModifier); \
	DECLARE_FUNCTION(execCreateAttributeModifier); \
	DECLARE_FUNCTION(execSetCombatantLevel); \
	DECLARE_FUNCTION(execSetCurrentAttributeValues); \
	DECLARE_FUNCTION(execGetCurrentAttributeValues); \
	DECLARE_FUNCTION(execGetAttributePercentage); \
	DECLARE_FUNCTION(execGetAttributeBaseValue); \
	DECLARE_FUNCTION(execGetAttributeValue); \
	DECLARE_FUNCTION(execApplyAttributeDamage); \
	DECLARE_FUNCTION(execInitializeFromAsset); \
	DECLARE_FUNCTION(execIsAbilityTagBlocked); \
	DECLARE_FUNCTION(execCancelAbilitiesWithTags); \
	DECLARE_FUNCTION(execGetGrantedAbilitiesWithTags); \
	DECLARE_FUNCTION(execGetGrantedAbilities); \
	DECLARE_FUNCTION(execGetActiveAbilitiesWithTags); \
	DECLARE_FUNCTION(execGetActiveAbilities); \
	DECLARE_FUNCTION(execIsAbilityActive); \
	DECLARE_FUNCTION(execStopAbility); \
	DECLARE_FUNCTION(execExecuteAbility); \
	DECLARE_FUNCTION(execGetAbility); \
	DECLARE_FUNCTION(execUngrantAbility); \
	DECLARE_FUNCTION(execGrantAbility); \
	DECLARE_FUNCTION(execGetOwnerPlayerController); \
	DECLARE_FUNCTION(execGetOwnerController); \
	DECLARE_FUNCTION(execGetOwnerCharacter); \
	DECLARE_FUNCTION(execGetOwnerPawn); \
	DECLARE_FUNCTION(execUpdate); \
	DECLARE_FUNCTION(execCombatantHasAllTag); \
	DECLARE_FUNCTION(execCombatantHasAnyTag); \
	DECLARE_FUNCTION(execCombatantHasTag); \
	DECLARE_FUNCTION(execGetCombatantTags); \
	DECLARE_FUNCTION(execRemoveTagsFromCombatant); \
	DECLARE_FUNCTION(execAddTagsToCombatant); \
	DECLARE_FUNCTION(execRemoveSkill); \
	DECLARE_FUNCTION(execAddSkill); \
	DECLARE_FUNCTION(execFilterCombatantsByAffinity); \
	DECLARE_FUNCTION(execGetAffinityToCombatant); \
	DECLARE_FUNCTION(execGetFactionTag); \
	DECLARE_FUNCTION(execGetAttributeLevel);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClearActiveTarget); \
	DECLARE_FUNCTION(execSetActiveTarget); \
	DECLARE_FUNCTION(execClearTargetList); \
	DECLARE_FUNCTION(execRemoveTargetFromList); \
	DECLARE_FUNCTION(execAddTargetsToList); \
	DECLARE_FUNCTION(execAddTargetToList); \
	DECLARE_FUNCTION(execRemoveEffectsWithTags); \
	DECLARE_FUNCTION(execRemoveEffectsOfCategory); \
	DECLARE_FUNCTION(execGetValidActiveEffects); \
	DECLARE_FUNCTION(execGetActiveEffectOfClass); \
	DECLARE_FUNCTION(execGetEffectsOfCategory); \
	DECLARE_FUNCTION(execGetEffectsWithTags); \
	DECLARE_FUNCTION(execTriggerEffectsOfCategory); \
	DECLARE_FUNCTION(execTriggerEffectsWithTags); \
	DECLARE_FUNCTION(execCreateEffect); \
	DECLARE_FUNCTION(execGetAttributeModifiers); \
	DECLARE_FUNCTION(execGetAttributeComparedValue); \
	DECLARE_FUNCTION(execRemoveAttributeModifersWithTags); \
	DECLARE_FUNCTION(execRemoveAttributeModifier); \
	DECLARE_FUNCTION(execAddAttrbuteModifier); \
	DECLARE_FUNCTION(execCreateAttributeModifier); \
	DECLARE_FUNCTION(execSetCombatantLevel); \
	DECLARE_FUNCTION(execSetCurrentAttributeValues); \
	DECLARE_FUNCTION(execGetCurrentAttributeValues); \
	DECLARE_FUNCTION(execGetAttributePercentage); \
	DECLARE_FUNCTION(execGetAttributeBaseValue); \
	DECLARE_FUNCTION(execGetAttributeValue); \
	DECLARE_FUNCTION(execApplyAttributeDamage); \
	DECLARE_FUNCTION(execInitializeFromAsset); \
	DECLARE_FUNCTION(execIsAbilityTagBlocked); \
	DECLARE_FUNCTION(execCancelAbilitiesWithTags); \
	DECLARE_FUNCTION(execGetGrantedAbilitiesWithTags); \
	DECLARE_FUNCTION(execGetGrantedAbilities); \
	DECLARE_FUNCTION(execGetActiveAbilitiesWithTags); \
	DECLARE_FUNCTION(execGetActiveAbilities); \
	DECLARE_FUNCTION(execIsAbilityActive); \
	DECLARE_FUNCTION(execStopAbility); \
	DECLARE_FUNCTION(execExecuteAbility); \
	DECLARE_FUNCTION(execGetAbility); \
	DECLARE_FUNCTION(execUngrantAbility); \
	DECLARE_FUNCTION(execGrantAbility); \
	DECLARE_FUNCTION(execGetOwnerPlayerController); \
	DECLARE_FUNCTION(execGetOwnerController); \
	DECLARE_FUNCTION(execGetOwnerCharacter); \
	DECLARE_FUNCTION(execGetOwnerPawn); \
	DECLARE_FUNCTION(execUpdate); \
	DECLARE_FUNCTION(execCombatantHasAllTag); \
	DECLARE_FUNCTION(execCombatantHasAnyTag); \
	DECLARE_FUNCTION(execCombatantHasTag); \
	DECLARE_FUNCTION(execGetCombatantTags); \
	DECLARE_FUNCTION(execRemoveTagsFromCombatant); \
	DECLARE_FUNCTION(execAddTagsToCombatant); \
	DECLARE_FUNCTION(execRemoveSkill); \
	DECLARE_FUNCTION(execAddSkill); \
	DECLARE_FUNCTION(execFilterCombatantsByAffinity); \
	DECLARE_FUNCTION(execGetAffinityToCombatant); \
	DECLARE_FUNCTION(execGetFactionTag); \
	DECLARE_FUNCTION(execGetAttributeLevel);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCombatantComponent(); \
	friend struct Z_Construct_UClass_UCombatantComponent_Statics; \
public: \
	DECLARE_CLASS(UCombatantComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UCombatantComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_INCLASS \
private: \
	static void StaticRegisterNativesUCombatantComponent(); \
	friend struct Z_Construct_UClass_UCombatantComponent_Statics; \
public: \
	DECLARE_CLASS(UCombatantComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UCombatantComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCombatantComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCombatantComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombatantComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatantComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCombatantComponent(UCombatantComponent&&); \
	NO_API UCombatantComponent(const UCombatantComponent&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCombatantComponent(UCombatantComponent&&); \
	NO_API UCombatantComponent(const UCombatantComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombatantComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatantComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCombatantComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_52_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h_55_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UCombatantComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantComponent_h


#define FOREACH_ENUM_EFACTIONAFFINITY(op) \
	op(NeutralAffinity) \
	op(FriendlyAffinity) \
	op(HostileAffinity) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
