// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OMEGAGAMEFRAMEWORK_ActorInterface_Leveling_generated_h
#error "ActorInterface_Leveling.generated.h already included, missing '#pragma once' in ActorInterface_Leveling.h"
#endif
#define OMEGAGAMEFRAMEWORK_ActorInterface_Leveling_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_RPC_WRAPPERS \
	virtual float GetXPRateOffset_Implementation() { return 0; }; \
 \
	DECLARE_FUNCTION(execGetXPRateOffset);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual float GetXPRateOffset_Implementation() { return 0; }; \
 \
	DECLARE_FUNCTION(execGetXPRateOffset);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_EVENT_PARMS \
	struct ActorInterface_Leveling_eventGetXPRateOffset_Parms \
	{ \
		float ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		ActorInterface_Leveling_eventGetXPRateOffset_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActorInterface_Leveling(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActorInterface_Leveling) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActorInterface_Leveling); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActorInterface_Leveling); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UActorInterface_Leveling(UActorInterface_Leveling&&); \
	NO_API UActorInterface_Leveling(const UActorInterface_Leveling&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActorInterface_Leveling(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UActorInterface_Leveling(UActorInterface_Leveling&&); \
	NO_API UActorInterface_Leveling(const UActorInterface_Leveling&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActorInterface_Leveling); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActorInterface_Leveling); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActorInterface_Leveling)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUActorInterface_Leveling(); \
	friend struct Z_Construct_UClass_UActorInterface_Leveling_Statics; \
public: \
	DECLARE_CLASS(UActorInterface_Leveling, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UActorInterface_Leveling)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IActorInterface_Leveling() {} \
public: \
	typedef UActorInterface_Leveling UClassType; \
	typedef IActorInterface_Leveling ThisClass; \
	static float Execute_GetXPRateOffset(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IActorInterface_Leveling() {} \
public: \
	typedef UActorInterface_Leveling UClassType; \
	typedef IActorInterface_Leveling ThisClass; \
	static float Execute_GetXPRateOffset(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_10_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UActorInterface_Leveling>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_ActorInterface_Leveling_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
