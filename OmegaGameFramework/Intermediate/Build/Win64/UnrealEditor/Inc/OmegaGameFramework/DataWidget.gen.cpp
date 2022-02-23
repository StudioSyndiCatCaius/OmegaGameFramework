// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Widget/DataWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataWidget() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataWidget_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataList_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetAnimation_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnSelected_Parms
		{
			UDataWidget* DataWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DataWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::NewProp_DataWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::NewProp_DataWidget = { "DataWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnSelected_Parms, DataWidget), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::NewProp_DataWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::NewProp_DataWidget_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::NewProp_DataWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnSelected__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnSelected_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnHovered_Parms
		{
			UDataWidget* DataWidget;
			bool bIsHovered;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DataWidget;
		static void NewProp_bIsHovered_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHovered;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_DataWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_DataWidget = { "DataWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnHovered_Parms, DataWidget), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_DataWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_DataWidget_MetaData)) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_bIsHovered_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnHovered_Parms*)Obj)->bIsHovered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_bIsHovered = { "bIsHovered", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnHovered_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_bIsHovered_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_DataWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::NewProp_bIsHovered,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnHovered__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnHovered_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnHighlight_Parms
		{
			UDataWidget* DataWidget;
			bool bIsHighlighted;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DataWidget;
		static void NewProp_bIsHighlighted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHighlighted;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_DataWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_DataWidget = { "DataWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnHighlight_Parms, DataWidget), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_DataWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_DataWidget_MetaData)) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_bIsHighlighted_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnHighlight_Parms*)Obj)->bIsHighlighted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_bIsHighlighted = { "bIsHighlighted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnHighlight_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_bIsHighlighted_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_DataWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::NewProp_bIsHighlighted,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnHighlight__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnHighlight_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UDataWidget::execSetSourceAsset)
	{
		P_GET_OBJECT(UObject,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSourceAsset(Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataWidget::execSetHighlighted)
	{
		P_GET_UBOOL(Z_Param_Highlighted);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHighlighted(Z_Param_Highlighted);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataWidget::execUnhover)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Unhover();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataWidget::execHover)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Hover();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataWidget::execSelect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Select();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataWidget::execGetAssetLabel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetLabel();
		P_NATIVE_END;
	}
	static FName NAME_UDataWidget_AddedToDataList = FName(TEXT("AddedToDataList"));
	void UDataWidget::AddedToDataList(UDataList* DataList, int32 Index, const UObject* Asset, FGameplayTagContainer ListTags)
	{
		DataWidget_eventAddedToDataList_Parms Parms;
		Parms.DataList=DataList;
		Parms.Index=Index;
		Parms.Asset=Asset;
		Parms.ListTags=ListTags;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_AddedToDataList),&Parms);
	}
	static FName NAME_UDataWidget_GetBrushImage = FName(TEXT("GetBrushImage"));
	UImage* UDataWidget::GetBrushImage()
	{
		DataWidget_eventGetBrushImage_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetBrushImage),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetButtonWidget = FName(TEXT("GetButtonWidget"));
	UButton* UDataWidget::GetButtonWidget()
	{
		DataWidget_eventGetButtonWidget_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetButtonWidget),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetDescriptionTextWidget = FName(TEXT("GetDescriptionTextWidget"));
	UTextBlock* UDataWidget::GetDescriptionTextWidget()
	{
		DataWidget_eventGetDescriptionTextWidget_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetDescriptionTextWidget),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetHighlightAnimation = FName(TEXT("GetHighlightAnimation"));
	UWidgetAnimation* UDataWidget::GetHighlightAnimation()
	{
		DataWidget_eventGetHighlightAnimation_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetHighlightAnimation),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetHoverAnimation = FName(TEXT("GetHoverAnimation"));
	UWidgetAnimation* UDataWidget::GetHoverAnimation()
	{
		DataWidget_eventGetHoverAnimation_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetHoverAnimation),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetMaterialImage = FName(TEXT("GetMaterialImage"));
	UImage* UDataWidget::GetMaterialImage()
	{
		DataWidget_eventGetMaterialImage_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetMaterialImage),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetNameTextWidget = FName(TEXT("GetNameTextWidget"));
	UTextBlock* UDataWidget::GetNameTextWidget()
	{
		DataWidget_eventGetNameTextWidget_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetNameTextWidget),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetSelectAnimation = FName(TEXT("GetSelectAnimation"));
	UWidgetAnimation* UDataWidget::GetSelectAnimation()
	{
		DataWidget_eventGetSelectAnimation_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetSelectAnimation),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_GetTextureImage = FName(TEXT("GetTextureImage"));
	UImage* UDataWidget::GetTextureImage()
	{
		DataWidget_eventGetTextureImage_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_GetTextureImage),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_IsEntityDisabled = FName(TEXT("IsEntityDisabled"));
	bool UDataWidget::IsEntityDisabled(UObject* Asset)
	{
		DataWidget_eventIsEntityDisabled_Parms Parms;
		Parms.Asset=Asset;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_IsEntityDisabled),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_IsEntityHidden = FName(TEXT("IsEntityHidden"));
	bool UDataWidget::IsEntityHidden(UObject* Asset)
	{
		DataWidget_eventIsEntityHidden_Parms Parms;
		Parms.Asset=Asset;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_IsEntityHidden),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_UDataWidget_OnNewListOwner = FName(TEXT("OnNewListOwner"));
	void UDataWidget::OnNewListOwner(UObject* ListOwner)
	{
		DataWidget_eventOnNewListOwner_Parms Parms;
		Parms.ListOwner=ListOwner;
		ProcessEvent(FindFunctionChecked(NAME_UDataWidget_OnNewListOwner),&Parms);
	}
	void UDataWidget::StaticRegisterNativesUDataWidget()
	{
		UClass* Class = UDataWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetLabel", &UDataWidget::execGetAssetLabel },
			{ "Hover", &UDataWidget::execHover },
			{ "Select", &UDataWidget::execSelect },
			{ "SetHighlighted", &UDataWidget::execSetHighlighted },
			{ "SetSourceAsset", &UDataWidget::execSetSourceAsset },
			{ "Unhover", &UDataWidget::execUnhover },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataList_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DataList;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Asset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ListTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_DataList_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_DataList = { "DataList", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventAddedToDataList_Parms, DataList), Z_Construct_UClass_UDataList_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_DataList_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_DataList_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventAddedToDataList_Parms, Index), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Asset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventAddedToDataList_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Asset_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Asset_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_ListTags = { "ListTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventAddedToDataList_Parms, ListTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_DataList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::NewProp_ListTags,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::Function_MetaDataParams[] = {
		{ "Category", "DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "AddedToDataList", nullptr, nullptr, sizeof(DataWidget_eventAddedToDataList_Parms), Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_AddedToDataList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_AddedToDataList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics
	{
		struct DataWidget_eventGetAssetLabel_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetAssetLabel_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetAssetLabel", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::DataWidget_eventGetAssetLabel_Parms), Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetAssetLabel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetAssetLabel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetBrushImage_Parms, ReturnValue), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetBrushImage", nullptr, nullptr, sizeof(DataWidget_eventGetBrushImage_Parms), Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetBrushImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetBrushImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetButtonWidget_Parms, ReturnValue), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetButtonWidget", nullptr, nullptr, sizeof(DataWidget_eventGetButtonWidget_Parms), Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetButtonWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetButtonWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetDescriptionTextWidget_Parms, ReturnValue), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetDescriptionTextWidget", nullptr, nullptr, sizeof(DataWidget_eventGetDescriptionTextWidget_Parms), Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetHighlightAnimation_Parms, ReturnValue), Z_Construct_UClass_UWidgetAnimation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetHighlightAnimation", nullptr, nullptr, sizeof(DataWidget_eventGetHighlightAnimation_Parms), Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetHighlightAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetHighlightAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetHoverAnimation_Parms, ReturnValue), Z_Construct_UClass_UWidgetAnimation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animations" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetHoverAnimation", nullptr, nullptr, sizeof(DataWidget_eventGetHoverAnimation_Parms), Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetHoverAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetHoverAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetMaterialImage_Parms, ReturnValue), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetMaterialImage", nullptr, nullptr, sizeof(DataWidget_eventGetMaterialImage_Parms), Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetMaterialImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetMaterialImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetNameTextWidget_Parms, ReturnValue), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "Comment", "//BINDABLE WIDGETS\n" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
		{ "ToolTip", "BINDABLE WIDGETS" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetNameTextWidget", nullptr, nullptr, sizeof(DataWidget_eventGetNameTextWidget_Parms), Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetNameTextWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetNameTextWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetSelectAnimation_Parms, ReturnValue), Z_Construct_UClass_UWidgetAnimation_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Animations" },
		{ "Comment", "//BINDABLE Anims\n" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
		{ "ToolTip", "BINDABLE Anims" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetSelectAnimation", nullptr, nullptr, sizeof(DataWidget_eventGetSelectAnimation_Parms), Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetSelectAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetSelectAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventGetTextureImage_Parms, ReturnValue), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Widgets" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "GetTextureImage", nullptr, nullptr, sizeof(DataWidget_eventGetTextureImage_Parms), Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x1C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_GetTextureImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_GetTextureImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_Hover_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_Hover_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_Hover_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "Hover", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_Hover_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_Hover_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_Hover()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_Hover_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventIsEntityDisabled_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DataWidget_eventIsEntityDisabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataWidget_eventIsEntityDisabled_Parms), &Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "IsEntityDisabled", nullptr, nullptr, sizeof(DataWidget_eventIsEntityDisabled_Parms), Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_IsEntityDisabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_IsEntityDisabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventIsEntityHidden_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DataWidget_eventIsEntityHidden_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataWidget_eventIsEntityHidden_Parms), &Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "IsEntityHidden", nullptr, nullptr, sizeof(DataWidget_eventIsEntityHidden_Parms), Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_IsEntityHidden()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_IsEntityHidden_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ListOwner;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::NewProp_ListOwner = { "ListOwner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventOnNewListOwner_Parms, ListOwner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::NewProp_ListOwner,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "OnNewListOwner", nullptr, nullptr, sizeof(DataWidget_eventOnNewListOwner_Parms), Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_OnNewListOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_OnNewListOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_Select_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_Select_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "Comment", "//FUNCTIONS\n" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
		{ "ToolTip", "FUNCTIONS" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_Select_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "Select", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_Select_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_Select_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_Select()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_Select_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics
	{
		struct DataWidget_eventSetHighlighted_Parms
		{
			bool Highlighted;
		};
		static void NewProp_Highlighted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Highlighted;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::NewProp_Highlighted_SetBit(void* Obj)
	{
		((DataWidget_eventSetHighlighted_Parms*)Obj)->Highlighted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::NewProp_Highlighted = { "Highlighted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataWidget_eventSetHighlighted_Parms), &Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::NewProp_Highlighted_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::NewProp_Highlighted,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "SetHighlighted", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::DataWidget_eventSetHighlighted_Parms), Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_SetHighlighted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_SetHighlighted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics
	{
		struct DataWidget_eventSetSourceAsset_Parms
		{
			UObject* Asset;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataWidget_eventSetSourceAsset_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::NewProp_Asset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "SetSourceAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::DataWidget_eventSetSourceAsset_Parms), Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_SetSourceAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_SetSourceAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataWidget_Unhover_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataWidget_Unhover_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataWidget_Unhover_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataWidget, nullptr, "Unhover", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataWidget_Unhover_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataWidget_Unhover_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataWidget_Unhover()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataWidget_Unhover_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataWidget);
	UClass* Z_Construct_UClass_UDataWidget_NoRegister()
	{
		return UDataWidget::StaticClass();
	}
	struct Z_Construct_UClass_UDataWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParentList_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetLabel_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetLabel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReferencedAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReferencedAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ListIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ListIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsHighlighted_MetaData[];
#endif
		static void NewProp_bIsHighlighted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHighlighted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsHovered_MetaData[];
#endif
		static void NewProp_bIsHovered_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHovered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoverSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HoverSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorSound_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ErrorSound;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSelected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSelected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnHovered_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHovered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnHighlight_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHighlight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataWidget_AddedToDataList, "AddedToDataList" }, // 3102875015
		{ &Z_Construct_UFunction_UDataWidget_GetAssetLabel, "GetAssetLabel" }, // 3209151891
		{ &Z_Construct_UFunction_UDataWidget_GetBrushImage, "GetBrushImage" }, // 2844784585
		{ &Z_Construct_UFunction_UDataWidget_GetButtonWidget, "GetButtonWidget" }, // 2256317427
		{ &Z_Construct_UFunction_UDataWidget_GetDescriptionTextWidget, "GetDescriptionTextWidget" }, // 3398566267
		{ &Z_Construct_UFunction_UDataWidget_GetHighlightAnimation, "GetHighlightAnimation" }, // 1465047634
		{ &Z_Construct_UFunction_UDataWidget_GetHoverAnimation, "GetHoverAnimation" }, // 3716430598
		{ &Z_Construct_UFunction_UDataWidget_GetMaterialImage, "GetMaterialImage" }, // 1319596133
		{ &Z_Construct_UFunction_UDataWidget_GetNameTextWidget, "GetNameTextWidget" }, // 2526425373
		{ &Z_Construct_UFunction_UDataWidget_GetSelectAnimation, "GetSelectAnimation" }, // 1515808882
		{ &Z_Construct_UFunction_UDataWidget_GetTextureImage, "GetTextureImage" }, // 458206659
		{ &Z_Construct_UFunction_UDataWidget_Hover, "Hover" }, // 3394641144
		{ &Z_Construct_UFunction_UDataWidget_IsEntityDisabled, "IsEntityDisabled" }, // 1164139974
		{ &Z_Construct_UFunction_UDataWidget_IsEntityHidden, "IsEntityHidden" }, // 3009351327
		{ &Z_Construct_UFunction_UDataWidget_OnNewListOwner, "OnNewListOwner" }, // 1952764154
		{ &Z_Construct_UFunction_UDataWidget_Select, "Select" }, // 3386763699
		{ &Z_Construct_UFunction_UDataWidget_SetHighlighted, "SetHighlighted" }, // 419125231
		{ &Z_Construct_UFunction_UDataWidget_SetSourceAsset, "SetSourceAsset" }, // 4058183652
		{ &Z_Construct_UFunction_UDataWidget_Unhover, "Unhover" }, // 3673574634
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widget/DataWidget.h" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_ParentList_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_ParentList = { "ParentList", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, ParentList), Z_Construct_UClass_UDataList_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_ParentList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_ParentList_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_AssetLabel_MetaData[] = {
		{ "Category", "DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_AssetLabel = { "AssetLabel", nullptr, (EPropertyFlags)0x0010000000000801, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, AssetLabel), METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_AssetLabel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_AssetLabel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_ReferencedAsset_MetaData[] = {
		{ "Category", "DataWidget" },
		{ "DisplayName", "Source Asset" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_ReferencedAsset = { "ReferencedAsset", nullptr, (EPropertyFlags)0x0011000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, ReferencedAsset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_ReferencedAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_ReferencedAsset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_ListIndex_MetaData[] = {
		{ "Category", "DataWidget" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_ListIndex = { "ListIndex", nullptr, (EPropertyFlags)0x0011000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, ListIndex), METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_ListIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_ListIndex_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted_MetaData[] = {
		{ "Category", "DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	void Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted_SetBit(void* Obj)
	{
		((UDataWidget*)Obj)->bIsHighlighted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted = { "bIsHighlighted", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDataWidget), &Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered_MetaData[] = {
		{ "Category", "DataWidget" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	void Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered_SetBit(void* Obj)
	{
		((UDataWidget*)Obj)->bIsHovered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered = { "bIsHovered", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDataWidget), &Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_SelectSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "//Sounds\n" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
		{ "ToolTip", "Sounds" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_SelectSound = { "SelectSound", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, SelectSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_SelectSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_SelectSound_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_HoverSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_HoverSound = { "HoverSound", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, HoverSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_HoverSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_HoverSound_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_ErrorSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_ErrorSound = { "ErrorSound", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, ErrorSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_ErrorSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_ErrorSound_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_OnSelected_MetaData[] = {
		{ "Comment", "//////////////////////////////////////////////////////////////////////////////////////////\n//////////______________________________DELEGATES______________________________//////////\n////////////////////////////////////////////////////////////////////////////////////////\n" },
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
		{ "ToolTip", "/______________________________DELEGATES______________________________/\n/" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_OnSelected = { "OnSelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, OnSelected), Z_Construct_UDelegateFunction_OmegaGameFramework_OnSelected__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_OnSelected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_OnSelected_MetaData)) }; // 279696238
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHovered_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHovered = { "OnHovered", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, OnHovered), Z_Construct_UDelegateFunction_OmegaGameFramework_OnHovered__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHovered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHovered_MetaData)) }; // 2675332434
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHighlight_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataWidget.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHighlight = { "OnHighlight", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataWidget, OnHighlight), Z_Construct_UDelegateFunction_OmegaGameFramework_OnHighlight__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHighlight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHighlight_MetaData)) }; // 489609730
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDataWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_ParentList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_AssetLabel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_ReferencedAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_ListIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHighlighted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_bIsHovered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_SelectSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_HoverSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_ErrorSound,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_OnSelected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHovered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataWidget_Statics::NewProp_OnHighlight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataWidget_Statics::ClassParams = {
		&UDataWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDataWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDataWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataWidget()
	{
		if (!Z_Registration_Info_UClass_UDataWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataWidget.OuterSingleton, Z_Construct_UClass_UDataWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataWidget.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataWidget>()
	{
		return UDataWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataWidget);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataWidget, UDataWidget::StaticClass, TEXT("UDataWidget"), &Z_Registration_Info_UClass_UDataWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataWidget), 138664478U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_536679791(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
