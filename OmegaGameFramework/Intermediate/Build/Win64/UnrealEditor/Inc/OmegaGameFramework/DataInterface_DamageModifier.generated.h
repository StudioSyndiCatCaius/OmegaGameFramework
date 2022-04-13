// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UOmegaAttribute;
class UCombatantComponent;
class UObject;
#ifdef OMEGAGAMEFRAMEWORK_DataInterface_DamageModifier_generated_h
#error "DataInterface_DamageModifier.generated.h already included, missing '#pragma once' in DataInterface_DamageModifier.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataInterface_DamageModifier_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_RPC_WRAPPERS \
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage) { return 0; }; \
 \
	DECLARE_FUNCTION(execModifyDamage);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual float ModifyDamage_Implementation(UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage) { return 0; }; \
 \
	DECLARE_FUNCTION(execModifyDamage);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_EVENT_PARMS \
	struct DataInterface_DamageModifier_eventModifyDamage_Parms \
	{ \
		UOmegaAttribute* Attribute; \
		UCombatantComponent* Target; \
		UObject* Instigator; \
		float BaseDamage; \
		float ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataInterface_DamageModifier_eventModifyDamage_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataInterface_DamageModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_DamageModifier) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataInterface_DamageModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_DamageModifier); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataInterface_DamageModifier(UDataInterface_DamageModifier&&); \
	NO_API UDataInterface_DamageModifier(const UDataInterface_DamageModifier&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataInterface_DamageModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataInterface_DamageModifier(UDataInterface_DamageModifier&&); \
	NO_API UDataInterface_DamageModifier(const UDataInterface_DamageModifier&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataInterface_DamageModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_DamageModifier); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_DamageModifier)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDataInterface_DamageModifier(); \
	friend struct Z_Construct_UClass_UDataInterface_DamageModifier_Statics; \
public: \
	DECLARE_CLASS(UDataInterface_DamageModifier, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataInterface_DamageModifier)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDataInterface_DamageModifier() {} \
public: \
	typedef UDataInterface_DamageModifier UClassType; \
	typedef IDataInterface_DamageModifier ThisClass; \
	static float Execute_ModifyDamage(UObject* O, UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~IDataInterface_DamageModifier() {} \
public: \
	typedef UDataInterface_DamageModifier UClassType; \
	typedef IDataInterface_DamageModifier ThisClass; \
	static float Execute_ModifyDamage(UObject* O, UOmegaAttribute* Attribute, UCombatantComponent* Target, UObject* Instigator, float BaseDamage); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_11_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataInterface_DamageModifier>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_DamageModifier_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
