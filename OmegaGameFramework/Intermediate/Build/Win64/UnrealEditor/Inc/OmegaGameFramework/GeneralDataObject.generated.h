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
class UTexture2D;
class UMaterialInterface;
struct FSlateBrush;
#ifdef OMEGAGAMEFRAMEWORK_GeneralDataObject_generated_h
#error "GeneralDataObject.generated.h already included, missing '#pragma once' in GeneralDataObject.h"
#endif
#define OMEGAGAMEFRAMEWORK_GeneralDataObject_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCustomAssetData_Statics; \
	OMEGAGAMEFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<struct FCustomAssetData>();

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_RPC_WRAPPERS \
	virtual void GetGeneralAssetLabel_Implementation(FString& Label); \
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color); \
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush); \
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description); \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralAssetColor); \
	DECLARE_FUNCTION(execGetGeneralDataImages); \
	DECLARE_FUNCTION(execGetGeneralDataText);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralAssetColor); \
	DECLARE_FUNCTION(execGetGeneralDataImages); \
	DECLARE_FUNCTION(execGetGeneralDataText);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_EVENT_PARMS \
	struct GeneralDataObject_eventGetGeneralAssetColor_Parms \
	{ \
		FLinearColor Color; \
	}; \
	struct GeneralDataObject_eventGetGeneralAssetLabel_Parms \
	{ \
		FString Label; \
	}; \
	struct GeneralDataObject_eventGetGeneralDataImages_Parms \
	{ \
		FString Label; \
		const UObject* Context; \
		UTexture2D* Texture; \
		UMaterialInterface* Material; \
		FSlateBrush Brush; \
	}; \
	struct GeneralDataObject_eventGetGeneralDataText_Parms \
	{ \
		FString Label; \
		const UObject* Context; \
		FText Name; \
		FText Description; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGeneralDataObject(); \
	friend struct Z_Construct_UClass_UGeneralDataObject_Statics; \
public: \
	DECLARE_CLASS(UGeneralDataObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UGeneralDataObject) \
	virtual UObject* _getUObject() const override { return const_cast<UGeneralDataObject*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUGeneralDataObject(); \
	friend struct Z_Construct_UClass_UGeneralDataObject_Statics; \
public: \
	DECLARE_CLASS(UGeneralDataObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UGeneralDataObject) \
	virtual UObject* _getUObject() const override { return const_cast<UGeneralDataObject*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGeneralDataObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGeneralDataObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGeneralDataObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGeneralDataObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGeneralDataObject(UGeneralDataObject&&); \
	NO_API UGeneralDataObject(const UGeneralDataObject&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGeneralDataObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGeneralDataObject(UGeneralDataObject&&); \
	NO_API UGeneralDataObject(const UGeneralDataObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGeneralDataObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGeneralDataObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGeneralDataObject)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_29_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UGeneralDataObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
