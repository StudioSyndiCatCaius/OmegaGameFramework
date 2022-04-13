// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDataWidget;
class UObject;
class UPanelWidget;
struct FCustomAssetData;
#ifdef OMEGAGAMEFRAMEWORK_DataList_generated_h
#error "DataList.generated.h already included, missing '#pragma once' in DataList.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataList_generated_h

#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_23_DELEGATE \
struct _Script_OmegaGameFramework_eventOnEntrySelected_Parms \
{ \
	UDataWidget* Entry; \
	FString Label; \
	UObject* Asset; \
	int32 Index; \
}; \
static inline void FOnEntrySelected_DelegateWrapper(const FMulticastScriptDelegate& OnEntrySelected, UDataWidget* Entry, const FString& Label, UObject* Asset, int32 Index) \
{ \
	_Script_OmegaGameFramework_eventOnEntrySelected_Parms Parms; \
	Parms.Entry=Entry; \
	Parms.Label=Label; \
	Parms.Asset=Asset; \
	Parms.Index=Index; \
	OnEntrySelected.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_24_DELEGATE \
struct _Script_OmegaGameFramework_eventOnEntryHovered_Parms \
{ \
	UDataWidget* Entry; \
	FString Label; \
	UObject* Asset; \
	int32 Index; \
}; \
static inline void FOnEntryHovered_DelegateWrapper(const FMulticastScriptDelegate& OnEntryHovered, UDataWidget* Entry, const FString& Label, UObject* Asset, int32 Index) \
{ \
	_Script_OmegaGameFramework_eventOnEntryHovered_Parms Parms; \
	Parms.Entry=Entry; \
	Parms.Label=Label; \
	Parms.Asset=Asset; \
	Parms.Index=Index; \
	OnEntryHovered.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_25_DELEGATE \
struct _Script_OmegaGameFramework_eventOnEntryUnhovered_Parms \
{ \
	UDataWidget* Entry; \
	FString Label; \
	UObject* Asset; \
	int32 Index; \
}; \
static inline void FOnEntryUnhovered_DelegateWrapper(const FMulticastScriptDelegate& OnEntryUnhovered, UDataWidget* Entry, const FString& Label, UObject* Asset, int32 Index) \
{ \
	_Script_OmegaGameFramework_eventOnEntryUnhovered_Parms Parms; \
	Parms.Entry=Entry; \
	Parms.Label=Label; \
	Parms.Asset=Asset; \
	Parms.Index=Index; \
	OnEntryUnhovered.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_26_DELEGATE \
struct _Script_OmegaGameFramework_eventOnEntryHighlighted_Parms \
{ \
	UDataWidget* Entry; \
	FString Label; \
	UObject* Asset; \
	int32 Index; \
	bool IsHighlighted; \
}; \
static inline void FOnEntryHighlighted_DelegateWrapper(const FMulticastScriptDelegate& OnEntryHighlighted, UDataWidget* Entry, const FString& Label, UObject* Asset, int32 Index, bool IsHighlighted) \
{ \
	_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms Parms; \
	Parms.Entry=Entry; \
	Parms.Label=Label; \
	Parms.Asset=Asset; \
	Parms.Index=Index; \
	Parms.IsHighlighted=IsHighlighted ? true : false; \
	OnEntryHighlighted.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_28_DELEGATE \
static inline void FOnDataListInputCancel_DelegateWrapper(const FMulticastScriptDelegate& OnDataListInputCancel) \
{ \
	OnDataListInputCancel.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_29_DELEGATE \
struct _Script_OmegaGameFramework_eventOnDataListInputPage_Parms \
{ \
	float Axis; \
}; \
static inline void FOnDataListInputPage_DelegateWrapper(const FMulticastScriptDelegate& OnDataListInputPage, float Axis) \
{ \
	_Script_OmegaGameFramework_eventOnDataListInputPage_Parms Parms; \
	Parms.Axis=Axis; \
	OnDataListInputPage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_30_DELEGATE \
struct _Script_OmegaGameFramework_eventOnDataListInputNavigate_Parms \
{ \
	FVector2D Axis; \
}; \
static inline void FOnDataListInputNavigate_DelegateWrapper(const FMulticastScriptDelegate& OnDataListInputNavigate, FVector2D Axis) \
{ \
	_Script_OmegaGameFramework_eventOnDataListInputNavigate_Parms Parms; \
	Parms.Axis=Axis; \
	OnDataListInputNavigate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_SPARSE_DATA
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execNativeEntityHighlight); \
	DECLARE_FUNCTION(execNativeEntityHover); \
	DECLARE_FUNCTION(execNativeEntitySelect); \
	DECLARE_FUNCTION(execBuildList); \
	DECLARE_FUNCTION(execRebuildList); \
	DECLARE_FUNCTION(execSetListOwner); \
	DECLARE_FUNCTION(execGetEntiresWithTag); \
	DECLARE_FUNCTION(execGetEntry); \
	DECLARE_FUNCTION(execGetEntryIndex); \
	DECLARE_FUNCTION(execCycleEntry); \
	DECLARE_FUNCTION(execSelectHoveredEntry); \
	DECLARE_FUNCTION(execGetHoveredEntry); \
	DECLARE_FUNCTION(execHoverEntry); \
	DECLARE_FUNCTION(execAddedCustomEntryToList); \
	DECLARE_FUNCTION(execAddAssetsToList); \
	DECLARE_FUNCTION(execAddAssetToList); \
	DECLARE_FUNCTION(execRemoveEntryOfAsset); \
	DECLARE_FUNCTION(execRemoveEntryFromList); \
	DECLARE_FUNCTION(execClearList);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNativeEntityHighlight); \
	DECLARE_FUNCTION(execNativeEntityHover); \
	DECLARE_FUNCTION(execNativeEntitySelect); \
	DECLARE_FUNCTION(execBuildList); \
	DECLARE_FUNCTION(execRebuildList); \
	DECLARE_FUNCTION(execSetListOwner); \
	DECLARE_FUNCTION(execGetEntiresWithTag); \
	DECLARE_FUNCTION(execGetEntry); \
	DECLARE_FUNCTION(execGetEntryIndex); \
	DECLARE_FUNCTION(execCycleEntry); \
	DECLARE_FUNCTION(execSelectHoveredEntry); \
	DECLARE_FUNCTION(execGetHoveredEntry); \
	DECLARE_FUNCTION(execHoverEntry); \
	DECLARE_FUNCTION(execAddedCustomEntryToList); \
	DECLARE_FUNCTION(execAddAssetsToList); \
	DECLARE_FUNCTION(execAddAssetToList); \
	DECLARE_FUNCTION(execRemoveEntryOfAsset); \
	DECLARE_FUNCTION(execRemoveEntryFromList); \
	DECLARE_FUNCTION(execClearList);


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDataList(); \
	friend struct Z_Construct_UClass_UDataList_Statics; \
public: \
	DECLARE_CLASS(UDataList, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataList) \
	virtual UObject* _getUObject() const override { return const_cast<UDataList*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_INCLASS \
private: \
	static void StaticRegisterNativesUDataList(); \
	friend struct Z_Construct_UClass_UDataList_Statics; \
public: \
	DECLARE_CLASS(UDataList, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataList) \
	virtual UObject* _getUObject() const override { return const_cast<UDataList*>(this); }


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataList) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataList); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataList); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataList(UDataList&&); \
	NO_API UDataList(const UDataList&); \
public:


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataList(UDataList&&); \
	NO_API UDataList(const UDataList&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataList); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataList); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataList)


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_41_PROLOG
#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_RPC_WRAPPERS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_INCLASS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_SPARSE_DATA \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_INCLASS_NO_PURE_DECLS \
	FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataList>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h


#define FOREACH_ENUM_EDATALISTFORMAT(op) \
	op(EDataListFormat::Format_Box) \
	op(EDataListFormat::Format_ScrollBox) \
	op(EDataListFormat::Format_UniformGrid) 

enum class EDataListFormat : uint8;
template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EDataListFormat>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
