// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCombatantComponent;
struct FGameplayTagContainer;
#ifdef OMEGAGAMEFRAMEWORK_TurnBasedManagerComponent_generated_h
#error "TurnBasedManagerComponent.generated.h already included, missing '#pragma once' in TurnBasedManagerComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_TurnBasedManagerComponent_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_12_DELEGATE \
struct _Script_OmegaGameFramework_eventOnTurnStart_Parms \
{ \
	UCombatantComponent* Combatant; \
	FString Flag; \
	FGameplayTagContainer Tags; \
}; \
static inline void FOnTurnStart_DelegateWrapper(const FMulticastScriptDelegate& OnTurnStart, UCombatantComponent* Combatant, const FString& Flag, FGameplayTagContainer Tags) \
{ \
	_Script_OmegaGameFramework_eventOnTurnStart_Parms Parms; \
	Parms.Combatant=Combatant; \
	Parms.Flag=Flag; \
	Parms.Tags=Tags; \
	OnTurnStart.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_13_DELEGATE \
struct _Script_OmegaGameFramework_eventOnTurnEnd_Parms \
{ \
	UCombatantComponent* Combatant; \
	FString Flag; \
	FGameplayTagContainer Tags; \
}; \
static inline void FOnTurnEnd_DelegateWrapper(const FMulticastScriptDelegate& OnTurnEnd, UCombatantComponent* Combatant, const FString& Flag, FGameplayTagContainer Tags) \
{ \
	_Script_OmegaGameFramework_eventOnTurnEnd_Parms Parms; \
	Parms.Combatant=Combatant; \
	Parms.Flag=Flag; \
	Parms.Tags=Tags; \
	OnTurnEnd.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_14_DELEGATE \
struct _Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms \
{ \
	UCombatantComponent* Combatant; \
	int32 Index; \
	FString Flag; \
	FGameplayTagContainer Tags; \
}; \
static inline void FOnAddedToTurnOrder_DelegateWrapper(const FMulticastScriptDelegate& OnAddedToTurnOrder, UCombatantComponent* Combatant, int32 Index, const FString& Flag, FGameplayTagContainer Tags) \
{ \
	_Script_OmegaGameFramework_eventOnAddedToTurnOrder_Parms Parms; \
	Parms.Combatant=Combatant; \
	Parms.Index=Index; \
	Parms.Flag=Flag; \
	Parms.Tags=Tags; \
	OnAddedToTurnOrder.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_15_DELEGATE \
struct _Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms \
{ \
	UCombatantComponent* Combatant; \
	FString Flag; \
	FGameplayTagContainer Tags; \
}; \
static inline void FOnRemovedFromTurnOrder_DelegateWrapper(const FMulticastScriptDelegate& OnRemovedFromTurnOrder, UCombatantComponent* Combatant, const FString& Flag, FGameplayTagContainer Tags) \
{ \
	_Script_OmegaGameFramework_eventOnRemovedFromTurnOrder_Parms Parms; \
	Parms.Combatant=Combatant; \
	Parms.Flag=Flag; \
	Parms.Tags=Tags; \
	OnRemovedFromTurnOrder.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClearRegisteredCombatants); \
	DECLARE_FUNCTION(execUnregisterCombatant); \
	DECLARE_FUNCTION(execRegisterCombatant); \
	DECLARE_FUNCTION(execClearTurnOrder); \
	DECLARE_FUNCTION(execNextTurn); \
	DECLARE_FUNCTION(execGenerateTurnOrder); \
	DECLARE_FUNCTION(execRemoveFromTurnOrder); \
	DECLARE_FUNCTION(execAddToTurnOrder); \
	DECLARE_FUNCTION(execGetActiveTurnMember);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClearRegisteredCombatants); \
	DECLARE_FUNCTION(execUnregisterCombatant); \
	DECLARE_FUNCTION(execRegisterCombatant); \
	DECLARE_FUNCTION(execClearTurnOrder); \
	DECLARE_FUNCTION(execNextTurn); \
	DECLARE_FUNCTION(execGenerateTurnOrder); \
	DECLARE_FUNCTION(execRemoveFromTurnOrder); \
	DECLARE_FUNCTION(execAddToTurnOrder); \
	DECLARE_FUNCTION(execGetActiveTurnMember);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTurnBasedManagerComponent(); \
	friend struct Z_Construct_UClass_UTurnBasedManagerComponent_Statics; \
public: \
	DECLARE_CLASS(UTurnBasedManagerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UTurnBasedManagerComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUTurnBasedManagerComponent(); \
	friend struct Z_Construct_UClass_UTurnBasedManagerComponent_Statics; \
public: \
	DECLARE_CLASS(UTurnBasedManagerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UTurnBasedManagerComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTurnBasedManagerComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTurnBasedManagerComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTurnBasedManagerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTurnBasedManagerComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTurnBasedManagerComponent(UTurnBasedManagerComponent&&); \
	NO_API UTurnBasedManagerComponent(const UTurnBasedManagerComponent&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTurnBasedManagerComponent(UTurnBasedManagerComponent&&); \
	NO_API UTurnBasedManagerComponent(const UTurnBasedManagerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTurnBasedManagerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTurnBasedManagerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTurnBasedManagerComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_18_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UTurnBasedManagerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnBasedManagerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
