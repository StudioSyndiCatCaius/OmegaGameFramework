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
#ifdef OMEGAGAMEFRAMEWORK_DataInterface_General_generated_h
#error "DataInterface_General.generated.h already included, missing '#pragma once' in DataInterface_General.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataInterface_General_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_RPC_WRAPPERS \
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) {}; \
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) {}; \
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) {}; \
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) {}; \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralAssetColor); \
	DECLARE_FUNCTION(execGetGeneralDataImages); \
	DECLARE_FUNCTION(execGetGeneralDataText);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void GetGeneralAssetLabel_Implementation(FString& Label) {}; \
	virtual void GetGeneralAssetColor_Implementation(FLinearColor& Color) {}; \
	virtual void GetGeneralDataImages_Implementation(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush) {}; \
	virtual void GetGeneralDataText_Implementation(const FString& Label, const UObject* Context, FText& Name, FText& Description) {}; \
 \
	DECLARE_FUNCTION(execGetGeneralAssetLabel); \
	DECLARE_FUNCTION(execGetGeneralAssetColor); \
	DECLARE_FUNCTION(execGetGeneralDataImages); \
	DECLARE_FUNCTION(execGetGeneralDataText);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_EVENT_PARMS \
	struct DataInterface_General_eventGetGeneralAssetColor_Parms \
	{ \
		FLinearColor Color; \
	}; \
	struct DataInterface_General_eventGetGeneralAssetLabel_Parms \
	{ \
		FString Label; \
	}; \
	struct DataInterface_General_eventGetGeneralDataImages_Parms \
	{ \
		FString Label; \
		const UObject* Context; \
		UTexture2D* Texture; \
		UMaterialInterface* Material; \
		FSlateBrush Brush; \
	}; \
	struct DataInterface_General_eventGetGeneralDataText_Parms \
	{ \
		FString Label; \
		const UObject* Context; \
		FText Name; \
		FText Description; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_General(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_General) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UDataInterface_General); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_General); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_General(UDataInterface_General&&); \
	OMEGAGAMEFRAMEWORK_API UDataInterface_General(const UDataInterface_General&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_General(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_General(UDataInterface_General&&); \
	OMEGAGAMEFRAMEWORK_API UDataInterface_General(const UDataInterface_General&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UDataInterface_General); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_General); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_General)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDataInterface_General(); \
	friend struct Z_Construct_UClass_UDataInterface_General_Statics; \
public: \
	DECLARE_CLASS(UDataInterface_General, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), OMEGAGAMEFRAMEWORK_API) \
	DECLARE_SERIALIZER(UDataInterface_General)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDataInterface_General() {} \
public: \
	typedef UDataInterface_General UClassType; \
	typedef IDataInterface_General ThisClass; \
	static void Execute_GetGeneralAssetColor(UObject* O, FLinearColor& Color); \
	static void Execute_GetGeneralAssetLabel(UObject* O, FString& Label); \
	static void Execute_GetGeneralDataImages(UObject* O, const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush); \
	static void Execute_GetGeneralDataText(UObject* O, const FString& Label, const UObject* Context, FText& Name, FText& Description); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_INCLASS_IINTERFACE \
protected: \
	virtual ~IDataInterface_General() {} \
public: \
	typedef UDataInterface_General UClassType; \
	typedef IDataInterface_General ThisClass; \
	static void Execute_GetGeneralAssetColor(UObject* O, FLinearColor& Color); \
	static void Execute_GetGeneralAssetLabel(UObject* O, FString& Label); \
	static void Execute_GetGeneralDataImages(UObject* O, const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush); \
	static void Execute_GetGeneralDataText(UObject* O, const FString& Label, const UObject* Context, FText& Name, FText& Description); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_12_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataInterface_General>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
