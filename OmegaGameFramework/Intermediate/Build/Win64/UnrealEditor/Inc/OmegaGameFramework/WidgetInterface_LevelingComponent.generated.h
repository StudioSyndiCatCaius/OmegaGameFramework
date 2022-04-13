// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UProgressBar;
class UTextBlock;
class ULevelingComponent;
#ifdef OMEGAGAMEFRAMEWORK_WidgetInterface_LevelingComponent_generated_h
#error "WidgetInterface_LevelingComponent.generated.h already included, missing '#pragma once' in WidgetInterface_LevelingComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_WidgetInterface_LevelingComponent_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_RPC_WRAPPERS \
	virtual void GetLevelingProgressBar_Implementation(UProgressBar*& ProgressBar) {}; \
	virtual void GetLevelingTexts_Implementation(UTextBlock*& CurrentValue, UTextBlock*& MaxValue) {}; \
	virtual ULevelingComponent* GetLevelingComponent_Implementation() { return NULL; }; \
 \
	DECLARE_FUNCTION(execGetLevelingProgressBar); \
	DECLARE_FUNCTION(execGetLevelingTexts); \
	DECLARE_FUNCTION(execGetLevelingComponent);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void GetLevelingProgressBar_Implementation(UProgressBar*& ProgressBar) {}; \
	virtual void GetLevelingTexts_Implementation(UTextBlock*& CurrentValue, UTextBlock*& MaxValue) {}; \
	virtual ULevelingComponent* GetLevelingComponent_Implementation() { return NULL; }; \
 \
	DECLARE_FUNCTION(execGetLevelingProgressBar); \
	DECLARE_FUNCTION(execGetLevelingTexts); \
	DECLARE_FUNCTION(execGetLevelingComponent);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_EVENT_PARMS \
	struct WidgetInterface_LevelingComponent_eventGetLevelingComponent_Parms \
	{ \
		ULevelingComponent* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		WidgetInterface_LevelingComponent_eventGetLevelingComponent_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct WidgetInterface_LevelingComponent_eventGetLevelingProgressBar_Parms \
	{ \
		UProgressBar* ProgressBar; \
	}; \
	struct WidgetInterface_LevelingComponent_eventGetLevelingTexts_Parms \
	{ \
		UTextBlock* CurrentValue; \
		UTextBlock* MaxValue; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWidgetInterface_LevelingComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidgetInterface_LevelingComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWidgetInterface_LevelingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidgetInterface_LevelingComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWidgetInterface_LevelingComponent(UWidgetInterface_LevelingComponent&&); \
	NO_API UWidgetInterface_LevelingComponent(const UWidgetInterface_LevelingComponent&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWidgetInterface_LevelingComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWidgetInterface_LevelingComponent(UWidgetInterface_LevelingComponent&&); \
	NO_API UWidgetInterface_LevelingComponent(const UWidgetInterface_LevelingComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWidgetInterface_LevelingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidgetInterface_LevelingComponent); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidgetInterface_LevelingComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUWidgetInterface_LevelingComponent(); \
	friend struct Z_Construct_UClass_UWidgetInterface_LevelingComponent_Statics; \
public: \
	DECLARE_CLASS(UWidgetInterface_LevelingComponent, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UWidgetInterface_LevelingComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IWidgetInterface_LevelingComponent() {} \
public: \
	typedef UWidgetInterface_LevelingComponent UClassType; \
	typedef IWidgetInterface_LevelingComponent ThisClass; \
	static ULevelingComponent* Execute_GetLevelingComponent(UObject* O); \
	static void Execute_GetLevelingProgressBar(UObject* O, UProgressBar*& ProgressBar); \
	static void Execute_GetLevelingTexts(UObject* O, UTextBlock*& CurrentValue, UTextBlock*& MaxValue); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_INCLASS_IINTERFACE \
protected: \
	virtual ~IWidgetInterface_LevelingComponent() {} \
public: \
	typedef UWidgetInterface_LevelingComponent UClassType; \
	typedef IWidgetInterface_LevelingComponent ThisClass; \
	static ULevelingComponent* Execute_GetLevelingComponent(UObject* O); \
	static void Execute_GetLevelingProgressBar(UObject* O, UProgressBar*& ProgressBar); \
	static void Execute_GetLevelingTexts(UObject* O, UTextBlock*& CurrentValue, UTextBlock*& MaxValue); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_17_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h_20_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UWidgetInterface_LevelingComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_WidgetInterface_LevelingComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
