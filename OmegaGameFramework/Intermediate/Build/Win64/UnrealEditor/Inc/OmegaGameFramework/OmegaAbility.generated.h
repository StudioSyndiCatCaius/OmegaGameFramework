// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagContainer;
class USkeletalMeshComponent;
class UCharacterMovementComponent;
class ACharacter;
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_OmegaAbility_generated_h
#error "OmegaAbility.generated.h already included, missing '#pragma once' in OmegaAbility.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaAbility_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_16_DELEGATE \
struct _Script_OmegaGameFramework_eventOnAbilityEnd_Parms \
{ \
	bool bCancelled; \
}; \
static inline void FOnAbilityEnd_DelegateWrapper(const FMulticastScriptDelegate& OnAbilityEnd, bool bCancelled) \
{ \
	_Script_OmegaGameFramework_eventOnAbilityEnd_Parms Parms; \
	Parms.bCancelled=bCancelled ? true : false; \
	OnAbilityEnd.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_RPC_WRAPPERS \
	virtual bool CanActivate_Implementation(); \
 \
	DECLARE_FUNCTION(execRecieveFinish); \
	DECLARE_FUNCTION(execRemoveBlockedAbilityTags); \
	DECLARE_FUNCTION(execAddBlockedAbilityTags); \
	DECLARE_FUNCTION(execGetAbilityOwnerMesh); \
	DECLARE_FUNCTION(execGetAbilityOwnerCharacterMoveComponent); \
	DECLARE_FUNCTION(execGetAbilityOwnerCharacter); \
	DECLARE_FUNCTION(execCancelAbility); \
	DECLARE_FUNCTION(execCompleteAbility); \
	DECLARE_FUNCTION(execSetInputEnabledForOwner); \
	DECLARE_FUNCTION(execCanActivate); \
	DECLARE_FUNCTION(execNative_Trigger); \
	DECLARE_FUNCTION(execNative_Execute); \
	DECLARE_FUNCTION(execExecute);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool CanActivate_Implementation(); \
 \
	DECLARE_FUNCTION(execRecieveFinish); \
	DECLARE_FUNCTION(execRemoveBlockedAbilityTags); \
	DECLARE_FUNCTION(execAddBlockedAbilityTags); \
	DECLARE_FUNCTION(execGetAbilityOwnerMesh); \
	DECLARE_FUNCTION(execGetAbilityOwnerCharacterMoveComponent); \
	DECLARE_FUNCTION(execGetAbilityOwnerCharacter); \
	DECLARE_FUNCTION(execCancelAbility); \
	DECLARE_FUNCTION(execCompleteAbility); \
	DECLARE_FUNCTION(execSetInputEnabledForOwner); \
	DECLARE_FUNCTION(execCanActivate); \
	DECLARE_FUNCTION(execNative_Trigger); \
	DECLARE_FUNCTION(execNative_Execute); \
	DECLARE_FUNCTION(execExecute);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_EVENT_PARMS \
	struct OmegaAbility_eventAbilityActivated_Parms \
	{ \
		UObject* Context; \
	}; \
	struct OmegaAbility_eventAbilityFinished_Parms \
	{ \
		bool Cancelled; \
	}; \
	struct OmegaAbility_eventActivatedTick_Parms \
	{ \
		float DeltaTime; \
	}; \
	struct OmegaAbility_eventCanActivate_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		OmegaAbility_eventCanActivate_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOmegaAbility(); \
	friend struct Z_Construct_UClass_AOmegaAbility_Statics; \
public: \
	DECLARE_CLASS(AOmegaAbility, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaAbility)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_INCLASS \
private: \
	static void StaticRegisterNativesAOmegaAbility(); \
	friend struct Z_Construct_UClass_AOmegaAbility_Statics; \
public: \
	DECLARE_CLASS(AOmegaAbility, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(AOmegaAbility)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOmegaAbility(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOmegaAbility) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaAbility); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaAbility(AOmegaAbility&&); \
	NO_API AOmegaAbility(const AOmegaAbility&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOmegaAbility(AOmegaAbility&&); \
	NO_API AOmegaAbility(const AOmegaAbility&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOmegaAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOmegaAbility); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOmegaAbility)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_34_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class AOmegaAbility>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAbility_h


#define FOREACH_ENUM_EABILITYACTIVATEINPUT(op) \
	op(EAbilityActivateInput::AbilityActivateOn_Started) \
	op(EAbilityActivateInput::AbilityActivateOn_Triggered) 

enum class EAbilityActivateInput;
template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EAbilityActivateInput>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
