// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDataAsset;
class UDataAsset; 
#ifdef OMEGAGAMEFRAMEWORK_DataAssetCollectionComponent_generated_h
#error "DataAssetCollectionComponent.generated.h already included, missing '#pragma once' in DataAssetCollectionComponent.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataAssetCollectionComponent_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_10_DELEGATE \
struct _Script_OmegaGameFramework_eventOnAssetAdded_Parms \
{ \
	UDataAsset* Asset; \
	int32 Amount; \
	bool IsFull; \
}; \
static inline void FOnAssetAdded_DelegateWrapper(const FMulticastScriptDelegate& OnAssetAdded, UDataAsset* Asset, int32 Amount, bool IsFull) \
{ \
	_Script_OmegaGameFramework_eventOnAssetAdded_Parms Parms; \
	Parms.Asset=Asset; \
	Parms.Amount=Amount; \
	Parms.IsFull=IsFull ? true : false; \
	OnAssetAdded.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_11_DELEGATE \
struct _Script_OmegaGameFramework_eventOnAssetRemoved_Parms \
{ \
	UDataAsset* Asset; \
	int32 Amount; \
	bool IsEmpty; \
}; \
static inline void FOnAssetRemoved_DelegateWrapper(const FMulticastScriptDelegate& OnAssetRemoved, UDataAsset* Asset, int32 Amount, bool IsEmpty) \
{ \
	_Script_OmegaGameFramework_eventOnAssetRemoved_Parms Parms; \
	Parms.Asset=Asset; \
	Parms.Amount=Amount; \
	Parms.IsEmpty=IsEmpty ? true : false; \
	OnAssetRemoved.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCollectionMap); \
	DECLARE_FUNCTION(execSetCollectionMap); \
	DECLARE_FUNCTION(execGetCollectionAsArray); \
	DECLARE_FUNCTION(execGetAssetNumberTotal); \
	DECLARE_FUNCTION(execGetAssetNumberOfType); \
	DECLARE_FUNCTION(execRemoveAsset); \
	DECLARE_FUNCTION(execAddAsset); \
	DECLARE_FUNCTION(execNativeRemoveAsset); \
	DECLARE_FUNCTION(execNativeAddAsset);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCollectionMap); \
	DECLARE_FUNCTION(execSetCollectionMap); \
	DECLARE_FUNCTION(execGetCollectionAsArray); \
	DECLARE_FUNCTION(execGetAssetNumberTotal); \
	DECLARE_FUNCTION(execGetAssetNumberOfType); \
	DECLARE_FUNCTION(execRemoveAsset); \
	DECLARE_FUNCTION(execAddAsset); \
	DECLARE_FUNCTION(execNativeRemoveAsset); \
	DECLARE_FUNCTION(execNativeAddAsset);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDataAssetCollectionComponent(); \
	friend struct Z_Construct_UClass_UDataAssetCollectionComponent_Statics; \
public: \
	DECLARE_CLASS(UDataAssetCollectionComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataAssetCollectionComponent)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUDataAssetCollectionComponent(); \
	friend struct Z_Construct_UClass_UDataAssetCollectionComponent_Statics; \
public: \
	DECLARE_CLASS(UDataAssetCollectionComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataAssetCollectionComponent)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataAssetCollectionComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataAssetCollectionComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataAssetCollectionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataAssetCollectionComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataAssetCollectionComponent(UDataAssetCollectionComponent&&); \
	NO_API UDataAssetCollectionComponent(const UDataAssetCollectionComponent&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataAssetCollectionComponent(UDataAssetCollectionComponent&&); \
	NO_API UDataAssetCollectionComponent(const UDataAssetCollectionComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataAssetCollectionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataAssetCollectionComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDataAssetCollectionComponent)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_13_PROLOG
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataAssetCollectionComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
