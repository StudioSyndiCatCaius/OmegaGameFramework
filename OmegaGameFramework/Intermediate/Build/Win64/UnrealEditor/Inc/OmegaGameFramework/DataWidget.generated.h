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
class UDataList;
struct FGameplayTagContainer;
class UImage;
class UButton;
class UTextBlock;
class UWidgetAnimation;
#ifdef OMEGAGAMEFRAMEWORK_DataWidget_generated_h
#error "DataWidget.generated.h already included, missing '#pragma once' in DataWidget.h"
#endif
#define OMEGAGAMEFRAMEWORK_DataWidget_generated_h

#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_18_DELEGATE \
struct _Script_OmegaGameFramework_eventOnSelected_Parms \
{ \
	UDataWidget* DataWidget; \
}; \
static inline void FOnSelected_DelegateWrapper(const FMulticastScriptDelegate& OnSelected, UDataWidget* DataWidget) \
{ \
	_Script_OmegaGameFramework_eventOnSelected_Parms Parms; \
	Parms.DataWidget=DataWidget; \
	OnSelected.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_19_DELEGATE \
struct _Script_OmegaGameFramework_eventOnHovered_Parms \
{ \
	UDataWidget* DataWidget; \
	bool bIsHovered; \
}; \
static inline void FOnHovered_DelegateWrapper(const FMulticastScriptDelegate& OnHovered, UDataWidget* DataWidget, bool bIsHovered) \
{ \
	_Script_OmegaGameFramework_eventOnHovered_Parms Parms; \
	Parms.DataWidget=DataWidget; \
	Parms.bIsHovered=bIsHovered ? true : false; \
	OnHovered.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_20_DELEGATE \
struct _Script_OmegaGameFramework_eventOnHighlight_Parms \
{ \
	UDataWidget* DataWidget; \
	bool bIsHighlighted; \
}; \
static inline void FOnHighlight_DelegateWrapper(const FMulticastScriptDelegate& OnHighlight, UDataWidget* DataWidget, bool bIsHighlighted) \
{ \
	_Script_OmegaGameFramework_eventOnHighlight_Parms Parms; \
	Parms.DataWidget=DataWidget; \
	Parms.bIsHighlighted=bIsHighlighted ? true : false; \
	OnHighlight.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_SPARSE_DATA
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetSourceAsset); \
	DECLARE_FUNCTION(execSetHighlighted); \
	DECLARE_FUNCTION(execUnhover); \
	DECLARE_FUNCTION(execHover); \
	DECLARE_FUNCTION(execSelect); \
	DECLARE_FUNCTION(execGetAssetLabel);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetSourceAsset); \
	DECLARE_FUNCTION(execSetHighlighted); \
	DECLARE_FUNCTION(execUnhover); \
	DECLARE_FUNCTION(execHover); \
	DECLARE_FUNCTION(execSelect); \
	DECLARE_FUNCTION(execGetAssetLabel);


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_EVENT_PARMS \
	struct DataWidget_eventAddedToDataList_Parms \
	{ \
		UDataList* DataList; \
		int32 Index; \
		const UObject* Asset; \
		FGameplayTagContainer ListTags; \
	}; \
	struct DataWidget_eventGetBrushImage_Parms \
	{ \
		UImage* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetBrushImage_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetButtonWidget_Parms \
	{ \
		UButton* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetButtonWidget_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetDescriptionTextWidget_Parms \
	{ \
		UTextBlock* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetDescriptionTextWidget_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetHighlightAnimation_Parms \
	{ \
		UWidgetAnimation* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetHighlightAnimation_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetHoverAnimation_Parms \
	{ \
		UWidgetAnimation* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetHoverAnimation_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetMaterialImage_Parms \
	{ \
		UImage* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetMaterialImage_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetNameTextWidget_Parms \
	{ \
		UTextBlock* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetNameTextWidget_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetSelectAnimation_Parms \
	{ \
		UWidgetAnimation* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetSelectAnimation_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventGetTextureImage_Parms \
	{ \
		UImage* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventGetTextureImage_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	}; \
	struct DataWidget_eventIsEntityDisabled_Parms \
	{ \
		UObject* Asset; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventIsEntityDisabled_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct DataWidget_eventIsEntityHidden_Parms \
	{ \
		UObject* Asset; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		DataWidget_eventIsEntityHidden_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct DataWidget_eventOnNewListOwner_Parms \
	{ \
		UObject* ListOwner; \
	};


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_CALLBACK_WRAPPERS
#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDataWidget(); \
	friend struct Z_Construct_UClass_UDataWidget_Statics; \
public: \
	DECLARE_CLASS(UDataWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataWidget)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUDataWidget(); \
	friend struct Z_Construct_UClass_UDataWidget_Statics; \
public: \
	DECLARE_CLASS(UDataWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OmegaGameFramework"), NO_API) \
	DECLARE_SERIALIZER(UDataWidget)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataWidget(UDataWidget&&); \
	NO_API UDataWidget(const UDataWidget&); \
public:


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDataWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDataWidget(UDataWidget&&); \
	NO_API UDataWidget(const UDataWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDataWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDataWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDataWidget)


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_25_PROLOG \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_EVENT_PARMS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_RPC_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_INCLASS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_SPARSE_DATA \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_CALLBACK_WRAPPERS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_INCLASS_NO_PURE_DECLS \
	FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<class UDataWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
