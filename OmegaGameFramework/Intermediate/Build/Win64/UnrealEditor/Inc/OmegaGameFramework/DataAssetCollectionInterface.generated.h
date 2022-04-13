// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OMEGAGAMEFRAMEWORK_DataAssetCollectionInterface_generated_h
#error "DataAssetCollectionInterface.generated.h already included, missing '#pragma once' in DataAssetCollectionInterface.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataAssetCollectionInterface_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_RPC_WRAPPERS \
	virtual int32 GetMaxCollectionNumber_Implementation() { return 0; }; \
 \
	DECLARE_FUNCTION(execGetMaxCollectionNumber);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual int32 GetMaxCollectionNumber_Implementation() { return 0; }; \
 \
	DECLARE_FUNCTION(execGetMaxCollectionNumber);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_EVENT_PARMS \
	struct DataAssetCollectionInterface_eventGetMaxCollectionNumber_Parms \
	{ \
		int32 ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataAssetCollectionInterface_eventGetMaxCollectionNumber_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	};


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_CALLBACK_WRAPPERS
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UDataAssetCollectionInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataAssetCollectionInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UDataAssetCollectionInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataAssetCollectionInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UDataAssetCollectionInterface(UDataAssetCollectionInterface&&); \
	OMEGAGAMEFRAMEWORK_API UDataAssetCollectionInterface(const UDataAssetCollectionInterface&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OMEGAGAMEFRAMEWORK_API UDataAssetCollectionInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OMEGAGAMEFRAMEWORK_API UDataAssetCollectionInterface(UDataAssetCollectionInterface&&); \
	OMEGAGAMEFRAMEWORK_API UDataAssetCollectionInterface(const UDataAssetCollectionInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OMEGAGAMEFRAMEWORK_API, UDataAssetCollectionInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataAssetCollectionInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataAssetCollectionInterface)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUDataAssetCollectionInterface(); \
	friend struct Z_Construct_UClass_UDataAssetCollectionInterface_Statics; \
public: \
	DECLARE_CLASS(UDataAssetCollectionInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), OMEGAGAMEFRAMEWORK_API) \
	DECLARE_SERIALIZER(UDataAssetCollectionInterface)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IDataAssetCollectionInterface() {} \
public: \
	typedef UDataAssetCollectionInterface UClassType; \
	typedef IDataAssetCollectionInterface ThisClass; \
	static int32 Execute_GetMaxCollectionNumber(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IDataAssetCollectionInterface() {} \
public: \
	typedef UDataAssetCollectionInterface UClassType; \
	typedef IDataAssetCollectionInterface ThisClass; \
	static int32 Execute_GetMaxCollectionNumber(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_10_PROLOG \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_EVENT_PARMS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_CALLBACK_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataAssetCollectionInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_DataAssetCollectionInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
