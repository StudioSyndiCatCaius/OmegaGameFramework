// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EActionState : uint8;
class UActorComponent;
class AActor;
class UObject;
class UAction;
#ifdef ACTIONS_Action_generated_h
#error "Action.generated.h already included, missing '#pragma once' in Action.h"
#endif
#define ACTIONS_Action_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_40_DELEGATE \
static inline void FActionActivatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& ActionActivatedDelegate) \
{ \
	ActionActivatedDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_41_DELEGATE \
struct _Script_Actions_eventActionFinishedDelegate_Parms \
{ \
	EActionState Reason; \
}; \
static inline void FActionFinishedDelegate_DelegateWrapper(const FMulticastScriptDelegate& ActionFinishedDelegate, const EActionState Reason) \
{ \
	_Script_Actions_eventActionFinishedDelegate_Parms Parms; \
	Parms.Reason=Reason; \
	ActionFinishedDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_RPC_WRAPPERS \
	virtual bool ReceiveCanActivate_Implementation(); \
 \
	DECLARE_FUNCTION(execGetOwnerComponent); \
	DECLARE_FUNCTION(execGetOwnerActor); \
	DECLARE_FUNCTION(execGetOwner); \
	DECLARE_FUNCTION(execGetTickRate); \
	DECLARE_FUNCTION(execGetParentAction); \
	DECLARE_FUNCTION(execGetParent); \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execFailed); \
	DECLARE_FUNCTION(execSucceeded); \
	DECLARE_FUNCTION(execIsRunning); \
	DECLARE_FUNCTION(execReceiveCanActivate); \
	DECLARE_FUNCTION(execFail); \
	DECLARE_FUNCTION(execSucceed); \
	DECLARE_FUNCTION(execActivate);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ReceiveCanActivate_Implementation(); \
 \
	DECLARE_FUNCTION(execGetOwnerComponent); \
	DECLARE_FUNCTION(execGetOwnerActor); \
	DECLARE_FUNCTION(execGetOwner); \
	DECLARE_FUNCTION(execGetTickRate); \
	DECLARE_FUNCTION(execGetParentAction); \
	DECLARE_FUNCTION(execGetParent); \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execFailed); \
	DECLARE_FUNCTION(execSucceeded); \
	DECLARE_FUNCTION(execIsRunning); \
	DECLARE_FUNCTION(execReceiveCanActivate); \
	DECLARE_FUNCTION(execFail); \
	DECLARE_FUNCTION(execSucceed); \
	DECLARE_FUNCTION(execActivate);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_EVENT_PARMS \
	struct Action_eventReceiveCanActivate_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		Action_eventReceiveCanActivate_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct Action_eventReceiveFinished_Parms \
	{ \
		EActionState Reason; \
	}; \
	struct Action_eventReceiveTick_Parms \
	{ \
		float DeltaTime; \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAction(); \
	friend struct Z_Construct_UClass_UAction_Statics; \
public: \
	DECLARE_CLASS(UAction, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Actions"), NO_API) \
	DECLARE_SERIALIZER(UAction)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_INCLASS \
private: \
	static void StaticRegisterNativesUAction(); \
	friend struct Z_Construct_UClass_UAction_Statics; \
public: \
	DECLARE_CLASS(UAction, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Actions"), NO_API) \
	DECLARE_SERIALIZER(UAction)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAction) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAction); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAction(UAction&&); \
	NO_API UAction(const UAction&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAction(UAction&&); \
	NO_API UAction(const UAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAction)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_47_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACTIONS_API UClass* StaticClass<class UAction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_Actions_Public_Action_h


#define FOREACH_ENUM_EACTIONSTATE(op) \
	op(EActionState::Preparing) \
	op(EActionState::Running) \
	op(EActionState::Success) \
	op(EActionState::Failure) \
	op(EActionState::Cancelled) 

enum class EActionState : uint8;
template<> ACTIONS_API UEnum* StaticEnum<EActionState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
