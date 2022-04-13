// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGamePreferenceBool;
class UGamePreferenceFloat;
class UGamePreferenceString;
class UGamePreferenceTag;
struct FGameplayTag;
class UOmegaSaveSubsystem;
#ifdef OMEGAGAMEFRAMEWORK_GamePreferenceSubsystem_generated_h
#error "GamePreferenceSubsystem.generated.h already included, missing '#pragma once' in GamePreferenceSubsystem.h"
#endif
#define OMEGAGAMEFRAMEWORK_GamePreferenceSubsystem_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_18_DELEGATE \
struct _Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms \
{ \
	UGamePreferenceBool* Preference; \
	bool bValue; \
}; \
static inline void FOnPrefernceBoolUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnPrefernceBoolUpdated, UGamePreferenceBool* Preference, bool bValue) \
{ \
	_Script_OmegaGameFramework_eventOnPrefernceBoolUpdated_Parms Parms; \
	Parms.Preference=Preference; \
	Parms.bValue=bValue ? true : false; \
	OnPrefernceBoolUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_19_DELEGATE \
struct _Script_OmegaGameFramework_eventOnPrefernceFloatUpdated_Parms \
{ \
	UGamePreferenceFloat* Preference; \
	float Value; \
}; \
static inline void FOnPrefernceFloatUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnPrefernceFloatUpdated, UGamePreferenceFloat* Preference, float Value) \
{ \
	_Script_OmegaGameFramework_eventOnPrefernceFloatUpdated_Parms Parms; \
	Parms.Preference=Preference; \
	Parms.Value=Value; \
	OnPrefernceFloatUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_20_DELEGATE \
struct _Script_OmegaGameFramework_eventOnPrefernceStringUpdated_Parms \
{ \
	UGamePreferenceString* Preference; \
	FString bValue; \
}; \
static inline void FOnPrefernceStringUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnPrefernceStringUpdated, UGamePreferenceString* Preference, const FString& bValue) \
{ \
	_Script_OmegaGameFramework_eventOnPrefernceStringUpdated_Parms Parms; \
	Parms.Preference=Preference; \
	Parms.bValue=bValue; \
	OnPrefernceStringUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_21_DELEGATE \
struct _Script_OmegaGameFramework_eventOnPrefernceTagUpdated_Parms \
{ \
	UGamePreferenceTag* Preference; \
	FGameplayTag Value; \
}; \
static inline void FOnPrefernceTagUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnPrefernceTagUpdated, UGamePreferenceTag* Preference, FGameplayTag Value) \
{ \
	_Script_OmegaGameFramework_eventOnPrefernceTagUpdated_Parms Parms; \
	Parms.Preference=Preference; \
	Parms.Value=Value; \
	OnPrefernceTagUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetGamePreferenceTag); \
	DECLARE_FUNCTION(execGetGamePreferenceTag); \
	DECLARE_FUNCTION(execSetGamePreferenceString); \
	DECLARE_FUNCTION(execGetGamePreferenceString); \
	DECLARE_FUNCTION(execSetGamePreferenceFloat); \
	DECLARE_FUNCTION(execGetGamePreferenceFloat); \
	DECLARE_FUNCTION(execSetGamePreferenceBool); \
	DECLARE_FUNCTION(execGetGamePreferenceBool); \
	DECLARE_FUNCTION(execGetSaveSubsystem);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetGamePreferenceTag); \
	DECLARE_FUNCTION(execGetGamePreferenceTag); \
	DECLARE_FUNCTION(execSetGamePreferenceString); \
	DECLARE_FUNCTION(execGetGamePreferenceString); \
	DECLARE_FUNCTION(execSetGamePreferenceFloat); \
	DECLARE_FUNCTION(execGetGamePreferenceFloat); \
	DECLARE_FUNCTION(execSetGamePreferenceBool); \
	DECLARE_FUNCTION(execGetGamePreferenceBool); \
	DECLARE_FUNCTION(execGetSaveSubsystem);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGamePreferenceSubsystem(); \
	friend struct Z_Construct_UClass_UGamePreferenceSubsystem_Statics; \
public: \
	DECLARE_CLASS(UGamePreferenceSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UGamePreferenceSubsystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_INCLASS \
private: \
	static void StaticRegisterNativesUGamePreferenceSubsystem(); \
	friend struct Z_Construct_UClass_UGamePreferenceSubsystem_Statics; \
public: \
	DECLARE_CLASS(UGamePreferenceSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UGamePreferenceSubsystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGamePreferenceSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGamePreferenceSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGamePreferenceSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGamePreferenceSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGamePreferenceSubsystem(UGamePreferenceSubsystem&&); \
	NO_API UGamePreferenceSubsystem(const UGamePreferenceSubsystem&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGamePreferenceSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGamePreferenceSubsystem(UGamePreferenceSubsystem&&); \
	NO_API UGamePreferenceSubsystem(const UGamePreferenceSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGamePreferenceSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGamePreferenceSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGamePreferenceSubsystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_27_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UGamePreferenceSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreferenceSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
