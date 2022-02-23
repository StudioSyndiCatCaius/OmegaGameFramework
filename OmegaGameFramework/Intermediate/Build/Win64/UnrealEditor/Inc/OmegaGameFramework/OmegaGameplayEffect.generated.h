// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UCombatantComponent;
class AActor;
#ifdef OMEGAGAMEFRAMEWORK_OmegaGameplayEffect_generated_h
#error "OmegaGameplayEffect.generated.h already included, missing '#pragma once' in OmegaGameplayEffect.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaGameplayEffect_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCalculateDamageValue); \
	DECLARE_FUNCTION(execLifetimeEnd); \
	DECLARE_FUNCTION(execTriggerEffect);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCalculateDamageValue); \
	DECLARE_FUNCTION(execLifetimeEnd); \
	DECLARE_FUNCTION(execTriggerEffect);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_EVENT_PARMS \
	struct OmegaGameplayEffect_eventEffectBeginPlay_Parms \
	{ \
		UCombatantComponent* EffectInstigator; \
		AActor* TargetedActor; \
	}; \
	struct OmegaGameplayEffect_eventLifetimeUpdated_Parms \
	{ \
		float TimeElapsed; \
		float TimeRemaining; \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOmegaGameplayEffect(); \
	friend struct Z_Construct_UClass_AOmegaGameplayEffect_Statics; \
public: \
	DECLARE_CLASS(AOmegaGameplayEffect, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaGameplayEffect)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_INCLASS \
private: \
	static void StaticRegisterNativesAOmegaGameplayEffect(); \
	friend struct Z_Construct_UClass_AOmegaGameplayEffect_Statics; \
public: \
	DECLARE_CLASS(AOmegaGameplayEffect, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaGameplayEffect)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOmegaGameplayEffect(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOmegaGameplayEffect) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaGameplayEffect); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaGameplayEffect); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaGameplayEffect(AOmegaGameplayEffect&&); \
	NO_API AOmegaGameplayEffect(const AOmegaGameplayEffect&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaGameplayEffect(AOmegaGameplayEffect&&); \
	NO_API AOmegaGameplayEffect(const AOmegaGameplayEffect&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaGameplayEffect); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaGameplayEffect); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOmegaGameplayEffect)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_28_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class AOmegaGameplayEffect>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h


#define FOREACH_ENUM_EEFFECTLIFETIME(op) \
	op(EEffectLifetime::EffectLifetime_Instant) \
	op(EEffectLifetime::EffectLifetime_Timer) \
	op(EEffectLifetime::EffectLifetime_OnTrigger) 

enum class EEffectLifetime : uint8;
template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EEffectLifetime>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
