// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UOmegaSaveGame;
#ifdef OMEGAGAMEFRAMEWORK_OmegaSaveInterface_generated_h
#error "OmegaSaveInterface.generated.h already included, missing '#pragma once' in OmegaSaveInterface.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaSaveInterface_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_RPC_WRAPPERS \
	virtual void OnGameFileStarted_Implementation(UOmegaSaveGame* SaveFile) {}; \
	virtual bool OnGameFileSaved_Implementation(UOmegaSaveGame* SaveFile) { return false; }; \
 \
	DECLARE_FUNCTION(execOnGameFileStarted); \
	DECLARE_FUNCTION(execOnGameFileSaved);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnGameFileStarted_Implementation(UOmegaSaveGame* SaveFile) {}; \
	virtual bool OnGameFileSaved_Implementation(UOmegaSaveGame* SaveFile) { return false; }; \
 \
	DECLARE_FUNCTION(execOnGameFileStarted); \
	DECLARE_FUNCTION(execOnGameFileSaved);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_EVENT_PARMS \
	struct OmegaSaveInterface_eventOnGameFileSaved_Parms \
	{ \
		UOmegaSaveGame* SaveFile; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		OmegaSaveInterface_eventOnGameFileSaved_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct OmegaSaveInterface_eventOnGameFileStarted_Parms \
	{ \
		UOmegaSaveGame* SaveFile; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaSaveInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaSaveInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaSaveInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaSaveInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaSaveInterface(UOmegaSaveInterface&&); \
	NO_API UOmegaSaveInterface(const UOmegaSaveInterface&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaSaveInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaSaveInterface(UOmegaSaveInterface&&); \
	NO_API UOmegaSaveInterface(const UOmegaSaveInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaSaveInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaSaveInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaSaveInterface)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUOmegaSaveInterface(); \
	friend struct Z_Construct_UClass_UOmegaSaveInterface_Statics; \
public: \
	DECLARE_CLASS(UOmegaSaveInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaSaveInterface)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IOmegaSaveInterface() {} \
public: \
	typedef UOmegaSaveInterface UClassType; \
	typedef IOmegaSaveInterface ThisClass; \
	static bool Execute_OnGameFileSaved(UObject* O, UOmegaSaveGame* SaveFile); \
	static void Execute_OnGameFileStarted(UObject* O, UOmegaSaveGame* SaveFile); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_INCLASS_IINTERFACE \
protected: \
	virtual ~IOmegaSaveInterface() {} \
public: \
	typedef UOmegaSaveInterface UClassType; \
	typedef IOmegaSaveInterface ThisClass; \
	static bool Execute_OnGameFileSaved(UObject* O, UOmegaSaveGame* SaveFile); \
	static void Execute_OnGameFileStarted(UObject* O, UOmegaSaveGame* SaveFile); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_12_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaSaveInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
