// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagContainer;
#ifdef OMEGAGAMEFRAMEWORK_OmegaSaveGame_generated_h
#error "OmegaSaveGame.generated.h already included, missing '#pragma once' in OmegaSaveGame.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaSaveGame_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_RPC_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_EVENT_PARMS \
	struct OmegaSaveGame_eventGetDisplayName_Parms \
	{ \
		FText ReturnValue; \
	}; \
	struct OmegaSaveGame_eventOnGameStarted_Parms \
	{ \
		FGameplayTagContainer Tags; \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOmegaSaveGame(); \
	friend struct Z_Construct_UClass_UOmegaSaveGame_Statics; \
public: \
	DECLARE_CLASS(UOmegaSaveGame, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaSaveGame) \
	virtual UObject* _getUObject() const override { return const_cast<UOmegaSaveGame*>(this); }


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_INCLASS \
private: \
	static void StaticRegisterNativesUOmegaSaveGame(); \
	friend struct Z_Construct_UClass_UOmegaSaveGame_Statics; \
public: \
	DECLARE_CLASS(UOmegaSaveGame, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaSaveGame) \
	virtual UObject* _getUObject() const override { return const_cast<UOmegaSaveGame*>(this); }


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaSaveGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaSaveGame) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaSaveGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaSaveGame); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaSaveGame(UOmegaSaveGame&&); \
	NO_API UOmegaSaveGame(const UOmegaSaveGame&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaSaveGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaSaveGame(UOmegaSaveGame&&); \
	NO_API UOmegaSaveGame(const UOmegaSaveGame&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaSaveGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaSaveGame); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaSaveGame)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_19_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaSaveGame>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGame_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
