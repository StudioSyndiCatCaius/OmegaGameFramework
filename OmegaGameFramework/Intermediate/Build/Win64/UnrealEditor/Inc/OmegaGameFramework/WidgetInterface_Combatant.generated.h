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
class UProgressBar;
class UTextBlock;
#ifdef OMEGAGAMEFRAMEWORK_WidgetInterface_Combatant_generated_h
#error "WidgetInterface_Combatant.generated.h already included, missing '#pragma once' in WidgetInterface_Combatant.h"
#endif
#define OMEGAGAMEFRAMEWORK_WidgetInterface_Combatant_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_RPC_WRAPPERS \
	virtual void OnCombatantUpdated_Implementation(UCombatantComponent* Combatant) {}; \
	virtual void GetAttributeProgressBar_Implementation(UOmegaAttribute* Attribute, UProgressBar*& ProgressBar) {}; \
	virtual void GetAttributeTexts_Implementation(UOmegaAttribute* Attribute, UTextBlock*& CurrentValue, UTextBlock*& MaxValue) {}; \
	virtual UCombatantComponent* GetCombatantComponent_Implementation() { return NULL; }; \
 \
	DECLARE_FUNCTION(execOnCombatantUpdated); \
	DECLARE_FUNCTION(execGetAttributeProgressBar); \
	DECLARE_FUNCTION(execGetAttributeTexts); \
	DECLARE_FUNCTION(execGetCombatantComponent);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnCombatantUpdated_Implementation(UCombatantComponent* Combatant) {}; \
	virtual void GetAttributeProgressBar_Implementation(UOmegaAttribute* Attribute, UProgressBar*& ProgressBar) {}; \
	virtual void GetAttributeTexts_Implementation(UOmegaAttribute* Attribute, UTextBlock*& CurrentValue, UTextBlock*& MaxValue) {}; \
	virtual UCombatantComponent* GetCombatantComponent_Implementation() { return NULL; }; \
 \
	DECLARE_FUNCTION(execOnCombatantUpdated); \
	DECLARE_FUNCTION(execGetAttributeProgressBar); \
	DECLARE_FUNCTION(execGetAttributeTexts); \
	DECLARE_FUNCTION(execGetCombatantComponent);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_EVENT_PARMS \
	struct WidgetInterface_Combatant_eventGetAttributeProgressBar_Parms \
	{ \
		UOmegaAttribute* Attribute; \
		UProgressBar* ProgressBar; \
	}; \
	struct WidgetInterface_Combatant_eventGetAttributeTexts_Parms \
	{ \
		UOmegaAttribute* Attribute; \
		UTextBlock* CurrentValue; \
		UTextBlock* MaxValue; \
	}; \
	struct WidgetInterface_Combatant_eventGetCombatantComponent_Parms \
	{ \
		UCombatantComponent* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		WidgetInterface_Combatant_eventGetCombatantComponent_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct WidgetInterface_Combatant_eventOnCombatantUpdated_Parms \
	{ \
		UCombatantComponent* Combatant; \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UWidgetInterface_Combatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidgetInterface_Combatant) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UWidgetInterface_Combatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidgetInterface_Combatant); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UWidgetInterface_Combatant(UWidgetInterface_Combatant&&); \
	OMEGAGAMEFRAMEWORK_API UWidgetInterface_Combatant(const UWidgetInterface_Combatant&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UWidgetInterface_Combatant(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UWidgetInterface_Combatant(UWidgetInterface_Combatant&&); \
	OMEGAGAMEFRAMEWORK_API UWidgetInterface_Combatant(const UWidgetInterface_Combatant&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UWidgetInterface_Combatant); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidgetInterface_Combatant); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidgetInterface_Combatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUWidgetInterface_Combatant(); \
	friend struct Z_Construct_UClass_UWidgetInterface_Combatant_Statics; \
public: \
	DECLARE_CLASS(UWidgetInterface_Combatant, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), OMEGAGAMEFRAMEWORK_API) \
	DECLARE_SERIALIZER(UWidgetInterface_Combatant)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IWidgetInterface_Combatant() {} \
public: \
	typedef UWidgetInterface_Combatant UClassType; \
	typedef IWidgetInterface_Combatant ThisClass; \
	static void Execute_GetAttributeProgressBar(UObject* O, UOmegaAttribute* Attribute, UProgressBar*& ProgressBar); \
	static void Execute_GetAttributeTexts(UObject* O, UOmegaAttribute* Attribute, UTextBlock*& CurrentValue, UTextBlock*& MaxValue); \
	static UCombatantComponent* Execute_GetCombatantComponent(UObject* O); \
	static void Execute_OnCombatantUpdated(UObject* O, UCombatantComponent* Combatant); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_INCLASS_IINTERFACE \
protected: \
	virtual ~IWidgetInterface_Combatant() {} \
public: \
	typedef UWidgetInterface_Combatant UClassType; \
	typedef IWidgetInterface_Combatant ThisClass; \
	static void Execute_GetAttributeProgressBar(UObject* O, UOmegaAttribute* Attribute, UProgressBar*& ProgressBar); \
	static void Execute_GetAttributeTexts(UObject* O, UOmegaAttribute* Attribute, UTextBlock*& CurrentValue, UTextBlock*& MaxValue); \
	static UCombatantComponent* Execute_GetCombatantComponent(UObject* O); \
	static void Execute_OnCombatantUpdated(UObject* O, UCombatantComponent* Combatant); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_16_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h_19_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UWidgetInterface_Combatant>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_WidgetInterface_Combatant_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
