// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCombatantComponent;
#ifdef OMEGAGAMEFRAMEWORK_TurnManagerBase_generated_h
#error "TurnManagerBase.generated.h already included, missing '#pragma once' in TurnManagerBase.h"
#endif
#define OMEGAGAMEFRAMEWORK_TurnManagerBase_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_RPC_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_EVENT_PARMS \
	struct TurnManagerBase_eventShouldTargetActFirst_Parms \
	{ \
		UCombatantComponent* TargetCombatant; \
		UCombatantComponent* ComparedCombatant; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		TurnManagerBase_eventShouldTargetActFirst_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTurnManagerBase(); \
	friend struct Z_Construct_UClass_UTurnManagerBase_Statics; \
public: \
	DECLARE_CLASS(UTurnManagerBase, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UTurnManagerBase)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUTurnManagerBase(); \
	friend struct Z_Construct_UClass_UTurnManagerBase_Statics; \
public: \
	DECLARE_CLASS(UTurnManagerBase, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UTurnManagerBase)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTurnManagerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTurnManagerBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTurnManagerBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTurnManagerBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTurnManagerBase(UTurnManagerBase&&); \
	NO_API UTurnManagerBase(const UTurnManagerBase&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTurnManagerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTurnManagerBase(UTurnManagerBase&&); \
	NO_API UTurnManagerBase(const UTurnManagerBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTurnManagerBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTurnManagerBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTurnManagerBase)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_14_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UTurnManagerBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_TurnBased_TurnManagerBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
