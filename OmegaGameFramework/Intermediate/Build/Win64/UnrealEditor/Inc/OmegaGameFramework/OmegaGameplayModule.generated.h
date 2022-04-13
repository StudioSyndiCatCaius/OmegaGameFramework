// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UOmegaSaveGame;
class UGameInstance;
class AOmegaGameMode;
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_OmegaGameplayModule_generated_h
#error "OmegaGameplayModule.generated.h already included, missing '#pragma once' in OmegaGameplayModule.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaGameplayModule_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_RPC_WRAPPERS \
	virtual bool GameFileSaved_Implementation(UOmegaSaveGame* SaveFile); \
 \
	DECLARE_FUNCTION(execGameFileSaved); \
	DECLARE_FUNCTION(execGetGameInstance); \
	DECLARE_FUNCTION(execNative_Initialize); \
	DECLARE_FUNCTION(execNative_OnLevelOpened);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool GameFileSaved_Implementation(UOmegaSaveGame* SaveFile); \
 \
	DECLARE_FUNCTION(execGameFileSaved); \
	DECLARE_FUNCTION(execGetGameInstance); \
	DECLARE_FUNCTION(execNative_Initialize); \
	DECLARE_FUNCTION(execNative_OnLevelOpened);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_EVENT_PARMS \
	struct OmegaGameplayModule_eventGameFileSaved_Parms \
	{ \
		UOmegaSaveGame* SaveFile; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		OmegaGameplayModule_eventGameFileSaved_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct OmegaGameplayModule_eventGameFileStarted_Parms \
	{ \
		UOmegaSaveGame* SaveFile; \
	}; \
	struct OmegaGameplayModule_eventOnGlobalEvent_Parms \
	{ \
		FName Event; \
		UObject* Instigator; \
	}; \
	struct OmegaGameplayModule_eventOnLevelOpened_Parms \
	{ \
		FString LevelName; \
		AOmegaGameMode* GameMode; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOmegaGameplayModule(); \
	friend struct Z_Construct_UClass_UOmegaGameplayModule_Statics; \
public: \
	DECLARE_CLASS(UOmegaGameplayModule, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaGameplayModule)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUOmegaGameplayModule(); \
	friend struct Z_Construct_UClass_UOmegaGameplayModule_Statics; \
public: \
	DECLARE_CLASS(UOmegaGameplayModule, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaGameplayModule)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaGameplayModule(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaGameplayModule) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaGameplayModule); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaGameplayModule); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaGameplayModule(UOmegaGameplayModule&&); \
	NO_API UOmegaGameplayModule(const UOmegaGameplayModule&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaGameplayModule(UOmegaGameplayModule&&); \
	NO_API UOmegaGameplayModule(const UOmegaGameplayModule&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaGameplayModule); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaGameplayModule); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaGameplayModule)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_19_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaGameplayModule>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_OmegaGameplayModule_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
