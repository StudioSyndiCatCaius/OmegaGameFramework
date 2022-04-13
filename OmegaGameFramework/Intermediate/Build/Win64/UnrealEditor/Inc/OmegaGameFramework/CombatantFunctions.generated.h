// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCombatantComponent;
class UObject;
struct FOmegaEffectContainer;
class UOmegaAttribute;
struct FGameplayTag;
struct FGameplayTagContainer;
#ifdef OMEGAGAMEFRAMEWORK_CombatantFunctions_generated_h
#error "CombatantFunctions.generated.h already included, missing '#pragma once' in CombatantFunctions.h"
#endif
#define OMEGAGAMEFRAMEWORK_CombatantFunctions_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execApplyEffectFromAsset); \
	DECLARE_FUNCTION(execApplyEffectFromContainer); \
	DECLARE_FUNCTION(execGetCombatantWithHighestAttributeValue); \
	DECLARE_FUNCTION(execFilterCombatantsByFaction); \
	DECLARE_FUNCTION(execFilterCombatantsByTags);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execApplyEffectFromAsset); \
	DECLARE_FUNCTION(execApplyEffectFromContainer); \
	DECLARE_FUNCTION(execGetCombatantWithHighestAttributeValue); \
	DECLARE_FUNCTION(execFilterCombatantsByFaction); \
	DECLARE_FUNCTION(execFilterCombatantsByTags);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCombatantFunctions(); \
	friend struct Z_Construct_UClass_UCombatantFunctions_Statics; \
public: \
	DECLARE_CLASS(UCombatantFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UCombatantFunctions)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUCombatantFunctions(); \
	friend struct Z_Construct_UClass_UCombatantFunctions_Statics; \
public: \
	DECLARE_CLASS(UCombatantFunctions, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UCombatantFunctions)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCombatantFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCombatantFunctions) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombatantFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatantFunctions); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCombatantFunctions(UCombatantFunctions&&); \
	NO_API UCombatantFunctions(const UCombatantFunctions&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCombatantFunctions(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCombatantFunctions(UCombatantFunctions&&); \
	NO_API UCombatantFunctions(const UCombatantFunctions&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCombatantFunctions); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCombatantFunctions); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCombatantFunctions)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_14_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UCombatantFunctions>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatantFunctions_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
