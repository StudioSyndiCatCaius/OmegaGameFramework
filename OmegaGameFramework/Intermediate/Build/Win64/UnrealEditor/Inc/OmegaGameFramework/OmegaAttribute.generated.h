// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLinearColor;
class UObject;
struct FGameplayTagContainer;
struct FGameplayTag;
#ifdef OMEGAGAMEFRAMEWORK_OmegaAttribute_generated_h
#error "OmegaAttribute.generated.h already included, missing '#pragma once' in OmegaAttribute.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaAttribute_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_RPC_WRAPPERS \
	virtual void GetGeneralAssetLabel_Implementation(FString& Label); \
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color); \
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description); \
	virtual FGameplayTagContainer GetObjectGameplayTags_Implementation(); \
	virtual FGameplayTag GetObjectGameplayCategory_Implementation(); \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralAssetColor); \
	DECLARE_FUNCTION(execGetGeneralDataText); \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory); \
	DECLARE_FUNCTION(execGetAttributeValue);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralAssetColor); \
	DECLARE_FUNCTION(execGetGeneralDataText); \
	DECLARE_FUNCTION(execGetObjectGameplayTags); \
	DECLARE_FUNCTION(execGetObjectGameplayCategory); \
	DECLARE_FUNCTION(execGetAttributeValue);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_EVENT_PARMS \
	struct OmegaAttribute_eventGetGeneralAssetColor_Parms \
	{ \
		FLinearColor Color; \
	}; \
	struct OmegaAttribute_eventGetGeneralAssetLabel_Parms \
	{ \
		FString Label; \
	}; \
	struct OmegaAttribute_eventGetGeneralDataText_Parms \
	{ \
		FString Label; \
		const UObject* Context; \
		FText Name; \
		FText Description; \
	}; \
	struct OmegaAttribute_eventGetObjectGameplayCategory_Parms \
	{ \
		FGameplayTag ReturnValue; \
	}; \
	struct OmegaAttribute_eventGetObjectGameplayTags_Parms \
	{ \
		FGameplayTagContainer ReturnValue; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOmegaAttribute(); \
	friend struct Z_Construct_UClass_UOmegaAttribute_Statics; \
public: \
	DECLARE_CLASS(UOmegaAttribute, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaAttribute) \
	virtual UObject* _getUObject() const override { return const_cast<UOmegaAttribute*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUOmegaAttribute(); \
	friend struct Z_Construct_UClass_UOmegaAttribute_Statics; \
public: \
	DECLARE_CLASS(UOmegaAttribute, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaAttribute) \
	virtual UObject* _getUObject() const override { return const_cast<UOmegaAttribute*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaAttribute(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaAttribute) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaAttribute); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaAttribute); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaAttribute(UOmegaAttribute&&); \
	NO_API UOmegaAttribute(const UOmegaAttribute&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaAttribute(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaAttribute(UOmegaAttribute&&); \
	NO_API UOmegaAttribute(const UOmegaAttribute&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaAttribute); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaAttribute); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaAttribute)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_17_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaAttribute>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
