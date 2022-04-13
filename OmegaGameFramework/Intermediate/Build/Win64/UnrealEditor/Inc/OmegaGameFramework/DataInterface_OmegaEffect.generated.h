// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FOmegaEffectContainer;
#ifdef OMEGAGAMEFRAMEWORK_DataInterface_OmegaEffect_generated_h
#error "DataInterface_OmegaEffect.generated.h already included, missing '#pragma once' in DataInterface_OmegaEffect.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataInterface_OmegaEffect_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_RPC_WRAPPERS \
	virtual TArray<FOmegaEffectContainer> GetOmegaEffects_Implementation() { return TArray<FOmegaEffectContainer>(); }; \
 \
	DECLARE_FUNCTION(execGetOmegaEffects);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual TArray<FOmegaEffectContainer> GetOmegaEffects_Implementation() { return TArray<FOmegaEffectContainer>(); }; \
 \
	DECLARE_FUNCTION(execGetOmegaEffects);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_EVENT_PARMS \
	struct DataInterface_OmegaEffect_eventGetOmegaEffects_Parms \
	{ \
		TArray<FOmegaEffectContainer> ReturnValue; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataInterface_OmegaEffect(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_OmegaEffect) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataInterface_OmegaEffect); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_OmegaEffect); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataInterface_OmegaEffect(UDataInterface_OmegaEffect&&); \
	NO_API UDataInterface_OmegaEffect(const UDataInterface_OmegaEffect&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataInterface_OmegaEffect(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataInterface_OmegaEffect(UDataInterface_OmegaEffect&&); \
	NO_API UDataInterface_OmegaEffect(const UDataInterface_OmegaEffect&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataInterface_OmegaEffect); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_OmegaEffect); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_OmegaEffect)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDataInterface_OmegaEffect(); \
	friend struct Z_Construct_UClass_UDataInterface_OmegaEffect_Statics; \
public: \
	DECLARE_CLASS(UDataInterface_OmegaEffect, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataInterface_OmegaEffect)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDataInterface_OmegaEffect() {} \
public: \
	typedef UDataInterface_OmegaEffect UClassType; \
	typedef IDataInterface_OmegaEffect ThisClass; \
	static TArray<FOmegaEffectContainer> Execute_GetOmegaEffects(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~IDataInterface_OmegaEffect() {} \
public: \
	typedef UDataInterface_OmegaEffect UClassType; \
	typedef IDataInterface_OmegaEffect ThisClass; \
	static TArray<FOmegaEffectContainer> Execute_GetOmegaEffects(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_11_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataInterface_OmegaEffect>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_OmegaEffect_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
