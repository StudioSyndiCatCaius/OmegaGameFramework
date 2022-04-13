// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTurnBasedManagerComponent;
struct FGameplayTagContainer;
#ifdef OMEGAGAMEFRAMEWORK_ActorInterface_TurnOrderCombatant_generated_h
#error "ActorInterface_TurnOrderCombatant.generated.h already included, missing '#pragma once' in ActorInterface_TurnOrderCombatant.h"
#endif
#define OMEGAGAMEFRAMEWORK_ActorInterface_TurnOrderCombatant_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_RPC_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_EVENT_PARMS \
	struct ActorInterface_TurnOrderCombatant_eventOnAddedToTurnOrder_Parms \
	{ \
		UTurnBasedManagerComponent* TurnManager; \
		FString Flag; \
		FGameplayTagContainer Tags; \
	}; \
	struct ActorInterface_TurnOrderCombatant_eventOnRemovedFromTurnOrder_Parms \
	{ \
		UTurnBasedManagerComponent* TurnManager; \
		FString Flag; \
		FGameplayTagContainer Tags; \
	}; \
	struct ActorInterface_TurnOrderCombatant_eventOnTurnBegin_Parms \
	{ \
		UTurnBasedManagerComponent* TurnManager; \
	}; \
	struct ActorInterface_TurnOrderCombatant_eventOnTurnEnd_Parms \
	{ \
		UTurnBasedManagerComponent* TurnManager; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActorInterface_TurnOrderCombatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActorInterface_TurnOrderCombatant) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActorInterface_TurnOrderCombatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActorInterface_TurnOrderCombatant); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UActorInterface_TurnOrderCombatant(UActorInterface_TurnOrderCombatant&&); \
	NO_API UActorInterface_TurnOrderCombatant(const UActorInterface_TurnOrderCombatant&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActorInterface_TurnOrderCombatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UActorInterface_TurnOrderCombatant(UActorInterface_TurnOrderCombatant&&); \
	NO_API UActorInterface_TurnOrderCombatant(const UActorInterface_TurnOrderCombatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActorInterface_TurnOrderCombatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActorInterface_TurnOrderCombatant); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActorInterface_TurnOrderCombatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUActorInterface_TurnOrderCombatant(); \
	friend struct Z_Construct_UClass_UActorInterface_TurnOrderCombatant_Statics; \
public: \
	DECLARE_CLASS(UActorInterface_TurnOrderCombatant, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UActorInterface_TurnOrderCombatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IActorInterface_TurnOrderCombatant() {} \
public: \
	typedef UActorInterface_TurnOrderCombatant UClassType; \
	typedef IActorInterface_TurnOrderCombatant ThisClass; \
	static void Execute_OnAddedToTurnOrder(UObject* O, UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags); \
	static void Execute_OnRemovedFromTurnOrder(UObject* O, UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags); \
	static void Execute_OnTurnBegin(UObject* O, UTurnBasedManagerComponent* TurnManager); \
	static void Execute_OnTurnEnd(UObject* O, UTurnBasedManagerComponent* TurnManager); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_INCLASS_IINTERFACE \
protected: \
	virtual ~IActorInterface_TurnOrderCombatant() {} \
public: \
	typedef UActorInterface_TurnOrderCombatant UClassType; \
	typedef IActorInterface_TurnOrderCombatant ThisClass; \
	static void Execute_OnAddedToTurnOrder(UObject* O, UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags); \
	static void Execute_OnRemovedFromTurnOrder(UObject* O, UTurnBasedManagerComponent* TurnManager, FString& Flag, FGameplayTagContainer Tags); \
	static void Execute_OnTurnBegin(UObject* O, UTurnBasedManagerComponent* TurnManager); \
	static void Execute_OnTurnEnd(UObject* O, UTurnBasedManagerComponent* TurnManager); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_13_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UActorInterface_TurnOrderCombatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_ActorInterface_TurnOrderCombatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
