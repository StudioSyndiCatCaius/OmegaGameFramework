// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagContainer;
struct FGameplayTag;
#ifdef OMEGAGAMEFRAMEWORK_GameplayTagsInterface_generated_h
#error "GameplayTagsInterface.generated.h already included, missing '#pragma once' in GameplayTagsInterface.h"
#endif
#define OMEGAGAMEFRAMEWORK_GameplayTagsInterface_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_RPC_WRAPPERS \
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() { return FGameplayTagContainer(); }; \
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() { return FGameplayTag(); }; \
 \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation() { return FGameplayTagContainer(); }; \
	virtual FGameplayTag GetObjectGameplayCategory_Implementation() { return FGameplayTag(); }; \
 \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_EVENT_PARMS \
	struct GameplayTagsInterface_eventGetObjectGameplayCategory_Parms \
	{ \
		FGameplayTag ReturnValue; \
	}; \
	struct GameplayTagsInterface_eventGetObjectGameplayTags_Parms \
	{ \
		FGameplayTagContainer ReturnValue; \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UGameplayTagsInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameplayTagsInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UGameplayTagsInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayTagsInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UGameplayTagsInterface(UGameplayTagsInterface&&); \
	OMEGAGAMEFRAMEWORK_API UGameplayTagsInterface(const UGameplayTagsInterface&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UGameplayTagsInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UGameplayTagsInterface(UGameplayTagsInterface&&); \
	OMEGAGAMEFRAMEWORK_API UGameplayTagsInterface(const UGameplayTagsInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UGameplayTagsInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayTagsInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameplayTagsInterface)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUGameplayTagsInterface(); \
	friend struct Z_Construct_UClass_UGameplayTagsInterface_Statics; \
public: \
	DECLARE_CLASS(UGameplayTagsInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), OMEGAGAMEFRAMEWORK_API) \
	DECLARE_SERIALIZER(UGameplayTagsInterface)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_GENERATED_UINTERFACE_BODY() \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_GENERATED_UINTERFACE_BODY() \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IGameplayTagsInterface() {} \
public: \
	typedef UGameplayTagsInterface UClassType; \
	typedef IGameplayTagsInterface ThisClass; \
	static FGameplayTag Execute_GetObjectGameplayCategory(UObject* O); \
	static FGameplayTagContainer Execute_GetObjectGameplayTags(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_INCLASS_IINTERFACE \
protected: \
	virtual ~IGameplayTagsInterface() {} \
public: \
	typedef UGameplayTagsInterface UClassType; \
	typedef IGameplayTagsInterface ThisClass; \
	static FGameplayTag Execute_GetObjectGameplayCategory(UObject* O); \
	static FGameplayTagContainer Execute_GetObjectGameplayTags(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_13_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UGameplayTagsInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_GameplayTagsInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
