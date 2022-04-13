// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;
#ifdef OMEGAGAMEFRAMEWORK_WidgetInterface_Input_generated_h
#error "WidgetInterface_Input.generated.h already included, missing '#pragma once' in WidgetInterface_Input.h"
#endif
#define OMEGAGAMEFRAMEWORK_WidgetInterface_Input_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_RPC_WRAPPERS \
	virtual void InputTag_Implementation(FGameplayTag Tag) {}; \
	virtual bool InputBlocked_Implementation() { return false; }; \
	virtual void InputCancel_Implementation() {}; \
	virtual void InputConfirm_Implementation() {}; \
	virtual void InputPage_Implementation(float Axis) {}; \
	virtual void InputNavigate_Implementation(FVector2D Axis) {}; \
 \
	DECLARE_FUNCTION(execInputTag); \
	DECLARE_FUNCTION(execInputBlocked); \
	DECLARE_FUNCTION(execInputCancel); \
	DECLARE_FUNCTION(execInputConfirm); \
	DECLARE_FUNCTION(execInputPage); \
	DECLARE_FUNCTION(execInputNavigate);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void InputTag_Implementation(FGameplayTag Tag) {}; \
	virtual bool InputBlocked_Implementation() { return false; }; \
	virtual void InputCancel_Implementation() {}; \
	virtual void InputConfirm_Implementation() {}; \
	virtual void InputPage_Implementation(float Axis) {}; \
	virtual void InputNavigate_Implementation(FVector2D Axis) {}; \
 \
	DECLARE_FUNCTION(execInputTag); \
	DECLARE_FUNCTION(execInputBlocked); \
	DECLARE_FUNCTION(execInputCancel); \
	DECLARE_FUNCTION(execInputConfirm); \
	DECLARE_FUNCTION(execInputPage); \
	DECLARE_FUNCTION(execInputNavigate);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_EVENT_PARMS \
	struct WidgetInterface_Input_eventInputBlocked_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		WidgetInterface_Input_eventInputBlocked_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct WidgetInterface_Input_eventInputNavigate_Parms \
	{ \
		FVector2D Axis; \
	}; \
	struct WidgetInterface_Input_eventInputPage_Parms \
	{ \
		float Axis; \
	}; \
	struct WidgetInterface_Input_eventInputTag_Parms \
	{ \
		FGameplayTag Tag; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWidgetInterface_Input(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidgetInterface_Input) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWidgetInterface_Input); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidgetInterface_Input); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWidgetInterface_Input(UWidgetInterface_Input&&); \
	NO_API UWidgetInterface_Input(const UWidgetInterface_Input&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWidgetInterface_Input(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWidgetInterface_Input(UWidgetInterface_Input&&); \
	NO_API UWidgetInterface_Input(const UWidgetInterface_Input&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWidgetInterface_Input); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidgetInterface_Input); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidgetInterface_Input)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUWidgetInterface_Input(); \
	friend struct Z_Construct_UClass_UWidgetInterface_Input_Statics; \
public: \
	DECLARE_CLASS(UWidgetInterface_Input, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UWidgetInterface_Input)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IWidgetInterface_Input() {} \
public: \
	typedef UWidgetInterface_Input UClassType; \
	typedef IWidgetInterface_Input ThisClass; \
	static bool Execute_InputBlocked(UObject* O); \
	static void Execute_InputCancel(UObject* O); \
	static void Execute_InputConfirm(UObject* O); \
	static void Execute_InputNavigate(UObject* O, FVector2D Axis); \
	static void Execute_InputPage(UObject* O, float Axis); \
	static void Execute_InputTag(UObject* O, FGameplayTag Tag); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_INCLASS_IINTERFACE \
protected: \
	virtual ~IWidgetInterface_Input() {} \
public: \
	typedef UWidgetInterface_Input UClassType; \
	typedef IWidgetInterface_Input ThisClass; \
	static bool Execute_InputBlocked(UObject* O); \
	static void Execute_InputCancel(UObject* O); \
	static void Execute_InputConfirm(UObject* O); \
	static void Execute_InputNavigate(UObject* O, FVector2D Axis); \
	static void Execute_InputPage(UObject* O, float Axis); \
	static void Execute_InputTag(UObject* O, FGameplayTag Tag); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_12_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UWidgetInterface_Input>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Input_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
