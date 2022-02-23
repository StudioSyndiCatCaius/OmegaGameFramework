// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class AOmegaGameMode;
class UOmegaGameplayModule;
#ifdef OMEGAGAMEFRAMEWORK_OmegaGameManager_generated_h
#error "OmegaGameManager.generated.h already included, missing '#pragma once' in OmegaGameManager.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaGameManager_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_18_DELEGATE \
struct _Script_OmegaGameFramework_eventOnGlobalEvent_Parms \
{ \
	FName Event; \
	UObject* Instigator; \
}; \
static inline void FOnGlobalEvent_DelegateWrapper(const FMulticastScriptDelegate& OnGlobalEvent, FName Event, UObject* Instigator) \
{ \
	_Script_OmegaGameFramework_eventOnGlobalEvent_Parms Parms; \
	Parms.Event=Event; \
	Parms.Instigator=Instigator; \
	OnGlobalEvent.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_19_DELEGATE \
struct _Script_OmegaGameFramework_eventOnNewLevel_Parms \
{ \
	FString LevelName; \
	AOmegaGameMode* GameMode; \
}; \
static inline void FOnNewLevel_DelegateWrapper(const FMulticastScriptDelegate& OnNewLevel, const FString& LevelName, AOmegaGameMode* GameMode) \
{ \
	_Script_OmegaGameFramework_eventOnNewLevel_Parms Parms; \
	Parms.LevelName=LevelName; \
	Parms.GameMode=GameMode; \
	OnNewLevel.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetGameplayModules); \
	DECLARE_FUNCTION(execGetGameplayModule);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGameplayModules); \
	DECLARE_FUNCTION(execGetGameplayModule);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOmegaGameManager(); \
	friend struct Z_Construct_UClass_UOmegaGameManager_Statics; \
public: \
	DECLARE_CLASS(UOmegaGameManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaGameManager)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUOmegaGameManager(); \
	friend struct Z_Construct_UClass_UOmegaGameManager_Statics; \
public: \
	DECLARE_CLASS(UOmegaGameManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaGameManager)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaGameManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaGameManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaGameManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaGameManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaGameManager(UOmegaGameManager&&); \
	NO_API UOmegaGameManager(const UOmegaGameManager&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaGameManager() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaGameManager(UOmegaGameManager&&); \
	NO_API UOmegaGameManager(const UOmegaGameManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaGameManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaGameManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOmegaGameManager)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_23_PROLOG
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaGameManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
