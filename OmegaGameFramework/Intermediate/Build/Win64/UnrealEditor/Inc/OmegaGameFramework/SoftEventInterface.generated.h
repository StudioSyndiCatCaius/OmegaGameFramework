// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_SoftEventInterface_generated_h
#error "SoftEventInterface.generated.h already included, missing '#pragma once' in SoftEventInterface.h"
#endif
#define OMEGAGAMEFRAMEWORK_SoftEventInterface_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_RPC_WRAPPERS \
	virtual void OnEventTriggered_Implementation(FName Event, UObject* Instigator) {}; \
 \
	DECLARE_FUNCTION(execOnEventTriggered);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnEventTriggered_Implementation(FName Event, UObject* Instigator) {}; \
 \
	DECLARE_FUNCTION(execOnEventTriggered);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_EVENT_PARMS \
	struct SoftEventInterface_eventOnEventTriggered_Parms \
	{ \
		FName Event; \
		UObject* Instigator; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USoftEventInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USoftEventInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USoftEventInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USoftEventInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USoftEventInterface(USoftEventInterface&&); \
	NO_API USoftEventInterface(const USoftEventInterface&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USoftEventInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USoftEventInterface(USoftEventInterface&&); \
	NO_API USoftEventInterface(const USoftEventInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USoftEventInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USoftEventInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USoftEventInterface)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUSoftEventInterface(); \
	friend struct Z_Construct_UClass_USoftEventInterface_Statics; \
public: \
	DECLARE_CLASS(USoftEventInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(USoftEventInterface)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ISoftEventInterface() {} \
public: \
	typedef USoftEventInterface UClassType; \
	typedef ISoftEventInterface ThisClass; \
	static void Execute_OnEventTriggered(UObject* O, FName Event, UObject* Instigator); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~ISoftEventInterface() {} \
public: \
	typedef USoftEventInterface UClassType; \
	typedef ISoftEventInterface ThisClass; \
	static void Execute_OnEventTriggered(UObject* O, FName Event, UObject* Instigator); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_10_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class USoftEventInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Event_SoftEventInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
