// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OMEGAGAMEFRAMEWORK_LevelingComponent_generated_h
#error "LevelingComponent.generated.h already included, missing '#pragma once' in LevelingComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_LevelingComponent_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_10_DELEGATE \
struct _Script_OmegaGameFramework_eventOnXpUpdated_Parms \
{ \
	float XP; \
}; \
static inline void FOnXpUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnXpUpdated, float XP) \
{ \
	_Script_OmegaGameFramework_eventOnXpUpdated_Parms Parms; \
	Parms.XP=XP; \
	OnXpUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_11_DELEGATE \
struct _Script_OmegaGameFramework_eventOnLevelUp_Parms \
{ \
	int32 NewLevel; \
}; \
static inline void FOnLevelUp_DelegateWrapper(const FMulticastScriptDelegate& OnLevelUp, int32 NewLevel) \
{ \
	_Script_OmegaGameFramework_eventOnLevelUp_Parms Parms; \
	Parms.NewLevel=NewLevel; \
	OnLevelUp.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_12_DELEGATE \
struct _Script_OmegaGameFramework_eventOnLevelDown_Parms \
{ \
	int32 NewLevel; \
}; \
static inline void FOnLevelDown_DelegateWrapper(const FMulticastScriptDelegate& OnLevelDown, int32 NewLevel) \
{ \
	_Script_OmegaGameFramework_eventOnLevelDown_Parms Parms; \
	Parms.NewLevel=NewLevel; \
	OnLevelDown.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAdjustXPRate); \
	DECLARE_FUNCTION(execGetCurrentLevelMaxXP); \
	DECLARE_FUNCTION(execGetCurrentLevelMinXP); \
	DECLARE_FUNCTION(execGetPercentageToNextLevel); \
	DECLARE_FUNCTION(execGetCurrentLevel); \
	DECLARE_FUNCTION(execSetXP); \
	DECLARE_FUNCTION(execAddXP); \
	DECLARE_FUNCTION(execGetXPRate);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAdjustXPRate); \
	DECLARE_FUNCTION(execGetCurrentLevelMaxXP); \
	DECLARE_FUNCTION(execGetCurrentLevelMinXP); \
	DECLARE_FUNCTION(execGetPercentageToNextLevel); \
	DECLARE_FUNCTION(execGetCurrentLevel); \
	DECLARE_FUNCTION(execSetXP); \
	DECLARE_FUNCTION(execAddXP); \
	DECLARE_FUNCTION(execGetXPRate);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULevelingComponent(); \
	friend struct Z_Construct_UClass_ULevelingComponent_Statics; \
public: \
	DECLARE_CLASS(ULevelingComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(ULevelingComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_INCLASS \
private: \
	static void StaticRegisterNativesULevelingComponent(); \
	friend struct Z_Construct_UClass_ULevelingComponent_Statics; \
public: \
	DECLARE_CLASS(ULevelingComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(ULevelingComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULevelingComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULevelingComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULevelingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULevelingComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULevelingComponent(ULevelingComponent&&); \
	NO_API ULevelingComponent(const ULevelingComponent&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULevelingComponent(ULevelingComponent&&); \
	NO_API ULevelingComponent(const ULevelingComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULevelingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULevelingComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULevelingComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_15_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class ULevelingComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_LevelingComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
