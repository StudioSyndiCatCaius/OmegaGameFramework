// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FGameplayTagContainer;
struct FGameplayTag;
#ifdef OMEGAGAMEFRAMEWORK_GamePreference_generated_h
#error "GamePreference.generated.h already included, missing '#pragma once' in GamePreference.h"
#endif
#define OMEGAGAMEFRAMEWORK_GamePreference_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_RPC_WRAPPERS \
	virtual void GetGeneralAssetLabel_Implementation(FString& Label); \
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description); \
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation(); \
	virtual FGameplayTag GetObjectGameplayCategory_Implementation(); \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralDataText); \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralDataText); \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_EVENT_PARMS \
	struct GamePreference_eventGetGeneralAssetLabel_Parms \
	{ \
		FString Label; \
	}; \
	struct GamePreference_eventGetGeneralDataText_Parms \
	{ \
		FString Label; \
		const UObject* Context; \
		FText Name; \
		FText Description; \
	}; \
	struct GamePreference_eventGetObjectGameplayCategory_Parms \
	{ \
		FGameplayTag ReturnValue; \
	}; \
	struct GamePreference_eventGetObjectGameplayTags_Parms \
	{ \
		FGameplayTagContainer ReturnValue; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGamePreference(); \
	friend struct Z_Construct_UClass_UGamePreference_Statics; \
public: \
	DECLARE_CLASS(UGamePreference, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UGamePreference) \
	virtual UObject* _getUObject() const override { return const_cast<UGamePreference*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUGamePreference(); \
	friend struct Z_Construct_UClass_UGamePreference_Statics; \
public: \
	DECLARE_CLASS(UGamePreference, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UGamePreference) \
	virtual UObject* _getUObject() const override { return const_cast<UGamePreference*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGamePreference(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGamePreference) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGamePreference); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGamePreference); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGamePreference(UGamePreference&&); \
	NO_API UGamePreference(const UGamePreference&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGamePreference(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGamePreference(UGamePreference&&); \
	NO_API UGamePreference(const UGamePreference&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGamePreference); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGamePreference); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGamePreference)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_15_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UGamePreference>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
