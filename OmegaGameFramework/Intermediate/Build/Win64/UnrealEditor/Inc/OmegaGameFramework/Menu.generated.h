// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagContainer;
class UObject;
class APlayerController;
class UWidgetAnimation;
#ifdef OMEGAGAMEFRAMEWORK_Menu_generated_h
#error "Menu.generated.h already included, missing '#pragma once' in Menu.h"
#endif
#define OMEGAGAMEFRAMEWORK_Menu_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_15_DELEGATE \
struct _Script_OmegaGameFramework_eventOpened_Parms \
{ \
	FGameplayTagContainer Tags; \
}; \
static inline void FOpened_DelegateWrapper(const FMulticastScriptDelegate& Opened, FGameplayTagContainer Tags) \
{ \
	_Script_OmegaGameFramework_eventOpened_Parms Parms; \
	Parms.Tags=Tags; \
	Opened.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_16_DELEGATE \
struct _Script_OmegaGameFramework_eventClosed_Parms \
{ \
	FGameplayTagContainer Tags; \
}; \
static inline void FClosed_DelegateWrapper(const FMulticastScriptDelegate& Closed, FGameplayTagContainer Tags) \
{ \
	_Script_OmegaGameFramework_eventClosed_Parms Parms; \
	Parms.Tags=Tags; \
	Closed.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCloseMenu); \
	DECLARE_FUNCTION(execOpenMenu);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCloseMenu); \
	DECLARE_FUNCTION(execOpenMenu);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_EVENT_PARMS \
	struct Menu_eventGetCloseAnimation_Parms \
	{ \
		UWidgetAnimation* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		Menu_eventGetCloseAnimation_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct Menu_eventGetOpenAnimation_Parms \
	{ \
		UWidgetAnimation* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		Menu_eventGetOpenAnimation_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct Menu_eventMenuClosed_Parms \
	{ \
		FGameplayTagContainer Tags; \
	}; \
	struct Menu_eventMenuOpened_Parms \
	{ \
		FGameplayTagContainer Tags; \
		UObject* Context; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMenu(); \
	friend struct Z_Construct_UClass_UMenu_Statics; \
public: \
	DECLARE_CLASS(UMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UMenu) \
	virtual UObject* _getUObject() const override { return const_cast<UMenu*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUMenu(); \
	friend struct Z_Construct_UClass_UMenu_Statics; \
public: \
	DECLARE_CLASS(UMenu, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UMenu) \
	virtual UObject* _getUObject() const override { return const_cast<UMenu*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMenu) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMenu); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMenu(UMenu&&); \
	NO_API UMenu(const UMenu&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMenu(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMenu(UMenu&&); \
	NO_API UMenu(const UMenu&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMenu); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMenu); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMenu)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_18_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UMenu>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_Menu_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
