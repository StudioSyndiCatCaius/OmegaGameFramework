// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCombatantComponent;
class UOmegaAttribute; 
struct FGameplayTag;
#ifdef OMEGAGAMEFRAMEWORK_DataInterface_Combatant_generated_h
#error "DataInterface_Combatant.generated.h already included, missing '#pragma once' in DataInterface_Combatant.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataInterface_Combatant_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_RPC_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_EVENT_PARMS \
	struct DataInterface_Combatant_eventOverrideAttributeLevels_Parms \
	{ \
		UCombatantComponent* Combatant; \
		bool bOverride; \
		TMap<UOmegaAttribute*,int32> ReturnValue; \
	}; \
	struct DataInterface_Combatant_eventOverrideAttributeValueCategory_Parms \
	{ \
		UCombatantComponent* Combatant; \
		bool bOverride; \
		FGameplayTag ReturnValue; \
	}; \
	struct DataInterface_Combatant_eventOverrideCombatantLevel_Parms \
	{ \
		UCombatantComponent* Combatant; \
		bool bOverride; \
		int32 ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataInterface_Combatant_eventOverrideCombatantLevel_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	}; \
	struct DataInterface_Combatant_eventOverrideCurrentAttributeValues_Parms \
	{ \
		UCombatantComponent* Combatant; \
		bool bOverride; \
		TMap<UOmegaAttribute*,float> ReturnValue; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataInterface_Combatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_Combatant) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataInterface_Combatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_Combatant); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataInterface_Combatant(UDataInterface_Combatant&&); \
	NO_API UDataInterface_Combatant(const UDataInterface_Combatant&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataInterface_Combatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataInterface_Combatant(UDataInterface_Combatant&&); \
	NO_API UDataInterface_Combatant(const UDataInterface_Combatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataInterface_Combatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataInterface_Combatant); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataInterface_Combatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDataInterface_Combatant(); \
	friend struct Z_Construct_UClass_UDataInterface_Combatant_Statics; \
public: \
	DECLARE_CLASS(UDataInterface_Combatant, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataInterface_Combatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDataInterface_Combatant() {} \
public: \
	typedef UDataInterface_Combatant UClassType; \
	typedef IDataInterface_Combatant ThisClass; \
	static TMap<UOmegaAttribute*,int32> Execute_OverrideAttributeLevels(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	static FGameplayTag Execute_OverrideAttributeValueCategory(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	static int32 Execute_OverrideCombatantLevel(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	static TMap<UOmegaAttribute*,float> Execute_OverrideCurrentAttributeValues(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_INCLASS_IINTERFACE \
protected: \
	virtual ~IDataInterface_Combatant() {} \
public: \
	typedef UDataInterface_Combatant UClassType; \
	typedef IDataInterface_Combatant ThisClass; \
	static TMap<UOmegaAttribute*,int32> Execute_OverrideAttributeLevels(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	static FGameplayTag Execute_OverrideAttributeValueCategory(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	static int32 Execute_OverrideCombatantLevel(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	static TMap<UOmegaAttribute*,float> Execute_OverrideCurrentAttributeValues(UObject* O, UCombatantComponent* Combatant, bool& bOverride); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_14_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_25_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h_17_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataInterface_Combatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_DataInterface_Combatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
