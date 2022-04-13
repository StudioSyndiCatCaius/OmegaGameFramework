// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputActionValue;
class AActor;
#ifdef OMEGAGAMEFRAMEWORK_InputReceiverComponent_generated_h
#error "InputReceiverComponent.generated.h already included, missing '#pragma once' in InputReceiverComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_InputReceiverComponent_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_10_DELEGATE \
static inline void FOnInputStart_DelegateWrapper(const FMulticastScriptDelegate& OnInputStart) \
{ \
	OnInputStart.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_11_DELEGATE \
static inline void FOnInputTrigger_DelegateWrapper(const FMulticastScriptDelegate& OnInputTrigger) \
{ \
	OnInputTrigger.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_12_DELEGATE \
static inline void FOnInputComplete_DelegateWrapper(const FMulticastScriptDelegate& OnInputComplete) \
{ \
	OnInputComplete.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_13_DELEGATE \
static inline void FOnInputCancel_DelegateWrapper(const FMulticastScriptDelegate& OnInputCancel) \
{ \
	OnInputCancel.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execNative_Ongoing); \
	DECLARE_FUNCTION(execNative_Cancel); \
	DECLARE_FUNCTION(execNative_Complete); \
	DECLARE_FUNCTION(execNative_Triggered); \
	DECLARE_FUNCTION(execNative_Started); \
	DECLARE_FUNCTION(execGetInputActionValue); \
	DECLARE_FUNCTION(execOverrideInputOwner);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNative_Ongoing); \
	DECLARE_FUNCTION(execNative_Cancel); \
	DECLARE_FUNCTION(execNative_Complete); \
	DECLARE_FUNCTION(execNative_Triggered); \
	DECLARE_FUNCTION(execNative_Started); \
	DECLARE_FUNCTION(execGetInputActionValue); \
	DECLARE_FUNCTION(execOverrideInputOwner);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInputReceiverComponent(); \
	friend struct Z_Construct_UClass_UInputReceiverComponent_Statics; \
public: \
	DECLARE_CLASS(UInputReceiverComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UInputReceiverComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUInputReceiverComponent(); \
	friend struct Z_Construct_UClass_UInputReceiverComponent_Statics; \
public: \
	DECLARE_CLASS(UInputReceiverComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UInputReceiverComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInputReceiverComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInputReceiverComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInputReceiverComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInputReceiverComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInputReceiverComponent(UInputReceiverComponent&&); \
	NO_API UInputReceiverComponent(const UInputReceiverComponent&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInputReceiverComponent(UInputReceiverComponent&&); \
	NO_API UInputReceiverComponent(const UInputReceiverComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInputReceiverComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInputReceiverComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInputReceiverComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_16_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UInputReceiverComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Input_InputReceiverComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
