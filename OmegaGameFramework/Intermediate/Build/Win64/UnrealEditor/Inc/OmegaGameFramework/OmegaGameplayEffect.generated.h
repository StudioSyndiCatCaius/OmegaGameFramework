// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AOmegaGameplayEffect;
struct FGameplayTagContainer;
struct FGameplayTag;
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_OmegaGameplayEffect_generated_h
#error "OmegaGameplayEffect.generated.h already included, missing '#pragma once' in OmegaGameplayEffect.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaGameplayEffect_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOmegaEffectContainer_Statics; \
	OMEGAGAMEFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<struct FOmegaEffectContainer>();

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_28_DELEGATE \
struct _Script_OmegaGameFramework_eventOnEffectTriggered_Parms \
{ \
	AOmegaGameplayEffect* Effect; \
	float DamageValue; \
}; \
static inline void FOnEffectTriggered_DelegateWrapper(const FMulticastScriptDelegate& OnEffectTriggered, AOmegaGameplayEffect* Effect, float DamageValue) \
{ \
	_Script_OmegaGameFramework_eventOnEffectTriggered_Parms Parms; \
	Parms.Effect=Effect; \
	Parms.DamageValue=DamageValue; \
	OnEffectTriggered.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_RPC_WRAPPERS \
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation(); \
	virtual FGameplayTag GetObjectGameplayCategory_Implementation(); \
 \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory); \
	DECLARE_FUNCTION(execCalculateDamageValue); \
	DECLARE_FUNCTION(execLifetimeEnd); \
	DECLARE_FUNCTION(execTriggerEffect);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory); \
	DECLARE_FUNCTION(execCalculateDamageValue); \
	DECLARE_FUNCTION(execLifetimeEnd); \
	DECLARE_FUNCTION(execTriggerEffect);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_EVENT_PARMS \
	struct OmegaGameplayEffect_eventEffectApplied_Parms \
	{ \
		float DamageValue; \
	}; \
	struct OmegaGameplayEffect_eventEffectBeginPlay_Parms \
	{ \
		UObject* Context; \
	}; \
	struct OmegaGameplayEffect_eventGetObjectGameplayCategory_Parms \
	{ \
		FGameplayTag ReturnValue; \
	}; \
	struct OmegaGameplayEffect_eventGetObjectGameplayTags_Parms \
	{ \
		FGameplayTagContainer ReturnValue; \
	}; \
	struct OmegaGameplayEffect_eventLifetimeUpdated_Parms \
	{ \
		float TimeElapsed; \
		float TimeRemaining; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOmegaGameplayEffect(); \
	friend struct Z_Construct_UClass_AOmegaGameplayEffect_Statics; \
public: \
	DECLARE_CLASS(AOmegaGameplayEffect, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaGameplayEffect) \
	virtual UObject* _getUObject() const override { return const_cast<AOmegaGameplayEffect*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_INCLASS \
private: \
	static void StaticRegisterNativesAOmegaGameplayEffect(); \
	friend struct Z_Construct_UClass_AOmegaGameplayEffect_Statics; \
public: \
	DECLARE_CLASS(AOmegaGameplayEffect, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaGameplayEffect) \
	virtual UObject* _getUObject() const override { return const_cast<AOmegaGameplayEffect*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_STANDARD_CONSTRUCTORS \
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


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaGameplayEffect(AOmegaGameplayEffect&&); \
	NO_API AOmegaGameplayEffect(const AOmegaGameplayEffect&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaGameplayEffect); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaGameplayEffect); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOmegaGameplayEffect)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_46_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class AOmegaGameplayEffect>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplayEffect_h


#define FOREACH_ENUM_EEFFECTLIFETIME(op) \
	op(EEffectLifetime::EffectLifetime_Instant) \
	op(EEffectLifetime::EffectLifetime_Timer) \
	op(EEffectLifetime::EffectLifetime_OnTrigger) \
	op(EEffectLifetime::EffectLifetime_OnDestroy) 

enum class EEffectLifetime : uint8;
template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EEffectLifetime>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
