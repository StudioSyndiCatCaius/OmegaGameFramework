// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FOmegaAttributeModifier;
#ifdef OMEGAGAMEFRAMEWORK_DataInterface_AttributeModifier_generated_h
#error "DataInterface_AttributeModifier.generated.h already included, missing '#pragma once' in DataInterface_AttributeModifier.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataInterface_AttributeModifier_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOmegaAttributeModifier_Statics; \
	OMEGAGAMEFRAMEWORK_API static class UScriptStruct* StaticStruct();


template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<struct FOmegaAttributeModifier>();

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_RPC_WRAPPERS \
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() { return TArray<FOmegaAttributeModifier>(); }; \
 \
	DECLARE_FUNCTION(execGetModifierValues);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual TArray<FOmegaAttributeModifier> GetModifierValues_Implementation() { return TArray<FOmegaAttributeModifier>(); }; \
 \
	DECLARE_FUNCTION(execGetModifierValues);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_EVENT_PARMS \
	struct DataInterface_AttributeModifier_eventGetModifierValues_Parms \
	{ \
		TArray<FOmegaAttributeModifier> ReturnValue; \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_AttributeModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_AttributeModifier) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UDataInterface_AttributeModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_AttributeModifier); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_AttributeModifier(UDataInterface_AttributeModifier&&); \
	OMEGAGAMEFRAMEWORK_API UDataInterface_AttributeModifier(const UDataInterface_AttributeModifier&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_AttributeModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UDataInterface_AttributeModifier(UDataInterface_AttributeModifier&&); \
	OMEGAGAMEFRAMEWORK_API UDataInterface_AttributeModifier(const UDataInterface_AttributeModifier&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UDataInterface_AttributeModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_AttributeModifier); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_AttributeModifier)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDataInterface_AttributeModifier(); \
	friend struct Z_Construct_UClass_UDataInterface_AttributeModifier_Statics; \
public: \
	DECLARE_CLASS(UDataInterface_AttributeModifier, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), OMEGAGAMEFRAMEWORK_API) \
	DECLARE_SERIALIZER(UDataInterface_AttributeModifier)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_GENERATED_UINTERFACE_BODY() \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_GENERATED_UINTERFACE_BODY() \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDataInterface_AttributeModifier() {} \
public: \
	typedef UDataInterface_AttributeModifier UClassType; \
	typedef IDataInterface_AttributeModifier ThisClass; \
	static TArray<FOmegaAttributeModifier> Execute_GetModifierValues(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_INCLASS_IINTERFACE \
protected: \
	virtual ~IDataInterface_AttributeModifier() {} \
public: \
	typedef UDataInterface_AttributeModifier UClassType; \
	typedef IDataInterface_AttributeModifier ThisClass; \
	static TArray<FOmegaAttributeModifier> Execute_GetModifierValues(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_25_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h_28_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataInterface_AttributeModifier>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_AttributeModifier_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
