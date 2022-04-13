// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_ActorInterface_Combatant_generated_h
#error "ActorInterface_Combatant.generated.h already included, missing '#pragma once' in ActorInterface_Combatant.h"
#endif
#define OMEGAGAMEFRAMEWORK_ActorInterface_Combatant_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_RPC_WRAPPERS \
	virtual TArray<UObject*> GetAttributeModifiers_Implementation() { return TArray<UObject*>(); }; \
 \
	DECLARE_FUNCTION(execGetAttributeModifiers);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual TArray<UObject*> GetAttributeModifiers_Implementation() { return TArray<UObject*>(); }; \
 \
	DECLARE_FUNCTION(execGetAttributeModifiers);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_EVENT_PARMS \
	struct ActorInterface_Combatant_eventGetAttributeModifiers_Parms \
	{ \
		TArray<UObject*> ReturnValue; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActorInterface_Combatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActorInterface_Combatant) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActorInterface_Combatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActorInterface_Combatant); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UActorInterface_Combatant(UActorInterface_Combatant&&); \
	NO_API UActorInterface_Combatant(const UActorInterface_Combatant&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UActorInterface_Combatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UActorInterface_Combatant(UActorInterface_Combatant&&); \
	NO_API UActorInterface_Combatant(const UActorInterface_Combatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UActorInterface_Combatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UActorInterface_Combatant); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UActorInterface_Combatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUActorInterface_Combatant(); \
	friend struct Z_Construct_UClass_UActorInterface_Combatant_Statics; \
public: \
	DECLARE_CLASS(UActorInterface_Combatant, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UActorInterface_Combatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IActorInterface_Combatant() {} \
public: \
	typedef UActorInterface_Combatant UClassType; \
	typedef IActorInterface_Combatant ThisClass; \
	static TArray<UObject*> Execute_GetAttributeModifiers(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IActorInterface_Combatant() {} \
public: \
	typedef UActorInterface_Combatant UClassType; \
	typedef IActorInterface_Combatant ThisClass; \
	static TArray<UObject*> Execute_GetAttributeModifiers(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_10_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UActorInterface_Combatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_ActorInterface_Combatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
