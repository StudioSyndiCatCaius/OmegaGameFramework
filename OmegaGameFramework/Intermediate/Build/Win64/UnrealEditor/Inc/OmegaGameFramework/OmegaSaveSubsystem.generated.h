// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimaryDataAsset;
class AActor;
struct FGameplayTagContainer;
struct FGameplayTag;
struct FGameplayTagQuery;
class UOmegaSaveBase;
class UOmegaSaveGame;
#ifdef OMEGAGAMEFRAMEWORK_OmegaSaveSubsystem_generated_h
#error "OmegaSaveSubsystem.generated.h already included, missing '#pragma once' in OmegaSaveSubsystem.h"
#endif
#define OMEGAGAMEFRAMEWORK_OmegaSaveSubsystem_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsDataAssetInSaveCollection); \
	DECLARE_FUNCTION(execRemoveDataAssetFromSaveCollection); \
	DECLARE_FUNCTION(execAddDataAssetToSaveCollection); \
	DECLARE_FUNCTION(execRemoveSavedActorTags); \
	DECLARE_FUNCTION(execAddSavedActorTags); \
	DECLARE_FUNCTION(execSetSavedActorState); \
	DECLARE_FUNCTION(execSaveTagsMatchQuery); \
	DECLARE_FUNCTION(execGetStoryTags); \
	DECLARE_FUNCTION(execRemoveStoryTags); \
	DECLARE_FUNCTION(execAddStoryTags); \
	DECLARE_FUNCTION(execSetStoryState); \
	DECLARE_FUNCTION(execGetSaveObject); \
	DECLARE_FUNCTION(execStartGame); \
	DECLARE_FUNCTION(execCreateNewGame); \
	DECLARE_FUNCTION(execSaveActiveGame); \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execGetSaveSlotList); \
	DECLARE_FUNCTION(execGetSaveSlotName);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsDataAssetInSaveCollection); \
	DECLARE_FUNCTION(execRemoveDataAssetFromSaveCollection); \
	DECLARE_FUNCTION(execAddDataAssetToSaveCollection); \
	DECLARE_FUNCTION(execRemoveSavedActorTags); \
	DECLARE_FUNCTION(execAddSavedActorTags); \
	DECLARE_FUNCTION(execSetSavedActorState); \
	DECLARE_FUNCTION(execSaveTagsMatchQuery); \
	DECLARE_FUNCTION(execGetStoryTags); \
	DECLARE_FUNCTION(execRemoveStoryTags); \
	DECLARE_FUNCTION(execAddStoryTags); \
	DECLARE_FUNCTION(execSetStoryState); \
	DECLARE_FUNCTION(execGetSaveObject); \
	DECLARE_FUNCTION(execStartGame); \
	DECLARE_FUNCTION(execCreateNewGame); \
	DECLARE_FUNCTION(execSaveActiveGame); \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execGetSaveSlotList); \
	DECLARE_FUNCTION(execGetSaveSlotName);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOmegaSaveSubsystem(); \
	friend struct Z_Construct_UClass_UOmegaSaveSubsystem_Statics; \
public: \
	DECLARE_CLASS(UOmegaSaveSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaSaveSubsystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_INCLASS \
private: \
	static void StaticRegisterNativesUOmegaSaveSubsystem(); \
	friend struct Z_Construct_UClass_UOmegaSaveSubsystem_Statics; \
public: \
	DECLARE_CLASS(UOmegaSaveSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UOmegaSaveSubsystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaSaveSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOmegaSaveSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaSaveSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaSaveSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaSaveSubsystem(UOmegaSaveSubsystem&&); \
	NO_API UOmegaSaveSubsystem(const UOmegaSaveSubsystem&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOmegaSaveSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOmegaSaveSubsystem(UOmegaSaveSubsystem&&); \
	NO_API UOmegaSaveSubsystem(const UOmegaSaveSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOmegaSaveSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOmegaSaveSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOmegaSaveSubsystem)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_27_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UOmegaSaveSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveSubsystem_h


#define FOREACH_ENUM_ELEVELOPENTYPE(op) \
	op(ELevelOpenType::LvlOp_None) \
	op(ELevelOpenType::LvlOp_Save) \
	op(ELevelOpenType::LvlOp_Custom) 

enum class ELevelOpenType : uint8;
template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<ELevelOpenType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
