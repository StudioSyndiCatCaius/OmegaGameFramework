// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMenu;
struct FGameplayTagContainer;
enum class ESlateVisibility : uint8;
class UHUDLayer;
class UObject;
struct FGameplayTag;
class UUserWidget;
class AActor;
#ifdef OMEGAGAMEFRAMEWORK_OmegaPlayerSubsystem_generated_h
#error "OmegaPlayerSubsystem.generated.h already included, missing '#pragma once' in OmegaPlayerSubsystem.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaPlayerSubsystem_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_13_DELEGATE \
struct _Script_OmegaGameFramework_eventMenuOpened_Parms \
{ \
	UMenu* Menu; \
	FGameplayTagContainer Tags; \
	bool FirstMenu; \
}; \
static inline void FMenuOpened_DelegateWrapper(const FMulticastScriptDelegate& MenuOpened, UMenu* Menu, FGameplayTagContainer Tags, bool FirstMenu) \
{ \
	_Script_OmegaGameFramework_eventMenuOpened_Parms Parms; \
	Parms.Menu=Menu; \
	Parms.Tags=Tags; \
	Parms.FirstMenu=FirstMenu ? true : false; \
	MenuOpened.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_14_DELEGATE \
struct _Script_OmegaGameFramework_eventMenuClosed_Parms \
{ \
	UMenu* Menu; \
	FGameplayTagContainer Tags; \
	bool LastMenu; \
}; \
static inline void FMenuClosed_DelegateWrapper(const FMulticastScriptDelegate& MenuClosed, UMenu* Menu, FGameplayTagContainer Tags, bool LastMenu) \
{ \
	_Script_OmegaGameFramework_eventMenuClosed_Parms Parms; \
	Parms.Menu=Menu; \
	Parms.Tags=Tags; \
	Parms.LastMenu=LastMenu ? true : false; \
	MenuClosed.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_15_DELEGATE \
static inline void FClearHoveredWidgets_DelegateWrapper(const FMulticastScriptDelegate& ClearHoveredWidgets) \
{ \
	ClearHoveredWidgets.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetHUDVisibilityWithTags); \
	DECLARE_FUNCTION(execRemoveAllHudLayers); \
	DECLARE_FUNCTION(execRemoveHUDLayersWithTags); \
	DECLARE_FUNCTION(execGetHUDLayersWithTags); \
	DECLARE_FUNCTION(execGetHUDLayers); \
	DECLARE_FUNCTION(execRemoveHUDLayer); \
	DECLARE_FUNCTION(execAddHUDLayer); \
	DECLARE_FUNCTION(execInputTag); \
	DECLARE_FUNCTION(execInputPage); \
	DECLARE_FUNCTION(execInputNavigate); \
	DECLARE_FUNCTION(execInputCancel); \
	DECLARE_FUNCTION(execInputConfirm); \
	DECLARE_FUNCTION(execRemoveMenuFromActiveList); \
	DECLARE_FUNCTION(execClearControlWidget); \
	DECLARE_FUNCTION(execSetControlWidget); \
	DECLARE_FUNCTION(execCloseAllMenus); \
	DECLARE_FUNCTION(execGetMenu); \
	DECLARE_FUNCTION(execCloseMenu); \
	DECLARE_FUNCTION(execOpenMenu);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetHUDVisibilityWithTags); \
	DECLARE_FUNCTION(execRemoveAllHudLayers); \
	DECLARE_FUNCTION(execRemoveHUDLayersWithTags); \
	DECLARE_FUNCTION(execGetHUDLayersWithTags); \
	DECLARE_FUNCTION(execGetHUDLayers); \
	DECLARE_FUNCTION(execRemoveHUDLayer); \
	DECLARE_FUNCTION(execAddHUDLayer); \
	DECLARE_FUNCTION(execInputTag); \
	DECLARE_FUNCTION(execInputPage); \
	DECLARE_FUNCTION(execInputNavigate); \
	DECLARE_FUNCTION(execInputCancel); \
	DECLARE_FUNCTION(execInputConfirm); \
	DECLARE_FUNCTION(execRemoveMenuFromActiveList); \
	DECLARE_FUNCTION(execClearControlWidget); \
	DECLARE_FUNCTION(execSetControlWidget); \
	DECLARE_FUNCTION(execCloseAllMenus); \
	DECLARE_FUNCTION(execGetMenu); \
	DECLARE_FUNCTION(execCloseMenu); \
	DECLARE_FUNCTION(execOpenMenu);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOmegaPlayerSubsystem(); \
	friend struct Z_Construct_UClass_UOmegaPlayerSubsystem_Statics; \
public: \
	DECLARE_CLASS(UOmegaPlayerSubsystem, ULocalPlayerSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaPlayerSubsystem)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUOmegaPlayerSubsystem(); \
	friend struct Z_Construct_UClass_UOmegaPlayerSubsystem_Statics; \
public: \
	DECLARE_CLASS(UOmegaPlayerSubsystem, ULocalPlayerSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaPlayerSubsystem)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaPlayerSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaPlayerSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaPlayerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaPlayerSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaPlayerSubsystem(UOmegaPlayerSubsystem&&); \
	NO_API UOmegaPlayerSubsystem(const UOmegaPlayerSubsystem&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaPlayerSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaPlayerSubsystem(UOmegaPlayerSubsystem&&); \
	NO_API UOmegaPlayerSubsystem(const UOmegaPlayerSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaPlayerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaPlayerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOmegaPlayerSubsystem)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_20_PROLOG
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaPlayerSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Player_OmegaPlayerSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
