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
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_OmegaGameplaySystem_generated_h
#error "OmegaGameplaySystem.generated.h already included, missing '#pragma once' in OmegaGameplaySystem.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaGameplaySystem_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_28_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGameplaySystemAbilityRules_Statics; \
	OMEGAGAMEFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<struct FGameplaySystemAbilityRules>();

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_40_DELEGATE \
struct _Script_OmegaGameFramework_eventOnShutdown_Parms \
{ \
	FString Flag; \
}; \
static inline void FOnShutdown_DelegateWrapper(const FMulticastScriptDelegate& OnShutdown, const FString& Flag) \
{ \
	_Script_OmegaGameFramework_eventOnShutdown_Parms Parms; \
	Parms.Flag=Flag; \
	OnShutdown.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execShutdown);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execShutdown);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_EVENT_PARMS \
	struct OmegaGameplaySystem_eventGamePreferenceUpdatedBool_Parms \
	{ \
		UGamePreferenceBool* Preference; \
		bool Value; \
	}; \
	struct OmegaGameplaySystem_eventGamePreferenceUpdatedFloat_Parms \
	{ \
		UGamePreferenceFloat* Preference; \
		float Value; \
	}; \
	struct OmegaGameplaySystem_eventOnActiveGameSaved_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		OmegaGameplaySystem_eventOnActiveGameSaved_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct OmegaGameplaySystem_eventSystemActivated_Parms \
	{ \
		UObject* Context; \
		FString Flag; \
	}; \
	struct OmegaGameplaySystem_eventSystemShutdown_Parms \
	{ \
		FString Flag; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOmegaGameplaySystem(); \
	friend struct Z_Construct_UClass_AOmegaGameplaySystem_Statics; \
public: \
	DECLARE_CLASS(AOmegaGameplaySystem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaGameplaySystem) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \
 \
	virtual UObject* _getUObject() const override { return const_cast<AOmegaGameplaySystem*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_INCLASS \
private: \
	static void StaticRegisterNativesAOmegaGameplaySystem(); \
	friend struct Z_Construct_UClass_AOmegaGameplaySystem_Statics; \
public: \
	DECLARE_CLASS(AOmegaGameplaySystem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaGameplaySystem) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \
 \
	virtual UObject* _getUObject() const override { return const_cast<AOmegaGameplaySystem*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOmegaGameplaySystem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOmegaGameplaySystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaGameplaySystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaGameplaySystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaGameplaySystem(AOmegaGameplaySystem&&); \
	NO_API AOmegaGameplaySystem(const AOmegaGameplaySystem&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaGameplaySystem(AOmegaGameplaySystem&&); \
	NO_API AOmegaGameplaySystem(const AOmegaGameplaySystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaGameplaySystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaGameplaySystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOmegaGameplaySystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_42_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class AOmegaGameplaySystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameplaySystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
