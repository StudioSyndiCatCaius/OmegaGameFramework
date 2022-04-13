// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimaryDataAsset;
 class UPrimaryDataAsset;
#ifdef OMEGAGAMEFRAMEWORK_EquipmentComponent_generated_h
#error "EquipmentComponent.generated.h already included, missing '#pragma once' in EquipmentComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_EquipmentComponent_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_10_DELEGATE \
struct _Script_OmegaGameFramework_eventOnItemEquipped_Parms \
{ \
	UPrimaryDataAsset* Item; \
	FString Slot; \
}; \
static inline void FOnItemEquipped_DelegateWrapper(const FMulticastScriptDelegate& OnItemEquipped, UPrimaryDataAsset* Item, const FString& Slot) \
{ \
	_Script_OmegaGameFramework_eventOnItemEquipped_Parms Parms; \
	Parms.Item=Item; \
	Parms.Slot=Slot; \
	OnItemEquipped.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_11_DELEGATE \
struct _Script_OmegaGameFramework_eventOnItemUnequipped_Parms \
{ \
	UPrimaryDataAsset* Item; \
	FString Slot; \
}; \
static inline void FOnItemUnequipped_DelegateWrapper(const FMulticastScriptDelegate& OnItemUnequipped, UPrimaryDataAsset* Item, const FString& Slot) \
{ \
	_Script_OmegaGameFramework_eventOnItemUnequipped_Parms Parms; \
	Parms.Item=Item; \
	Parms.Slot=Slot; \
	OnItemUnequipped.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetEquipmentInSlot); \
	DECLARE_FUNCTION(execUnequipSlot); \
	DECLARE_FUNCTION(execEquipItem); \
	DECLARE_FUNCTION(execSetEquipment); \
	DECLARE_FUNCTION(execGetEquipment);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetEquipmentInSlot); \
	DECLARE_FUNCTION(execUnequipSlot); \
	DECLARE_FUNCTION(execEquipItem); \
	DECLARE_FUNCTION(execSetEquipment); \
	DECLARE_FUNCTION(execGetEquipment);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEquipmentComponent(); \
	friend struct Z_Construct_UClass_UEquipmentComponent_Statics; \
public: \
	DECLARE_CLASS(UEquipmentComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UEquipmentComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUEquipmentComponent(); \
	friend struct Z_Construct_UClass_UEquipmentComponent_Statics; \
public: \
	DECLARE_CLASS(UEquipmentComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UEquipmentComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEquipmentComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEquipmentComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEquipmentComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipmentComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEquipmentComponent(UEquipmentComponent&&); \
	NO_API UEquipmentComponent(const UEquipmentComponent&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEquipmentComponent(UEquipmentComponent&&); \
	NO_API UEquipmentComponent(const UEquipmentComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEquipmentComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipmentComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEquipmentComponent)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_13_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UEquipmentComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_Equipment_EquipmentComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
