// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Widget/DataList.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataList() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature();
	OMEGAGAMEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	OMEGAGAMEFRAMEWORK_API UEnum* Z_Construct_UEnum_OmegaGameFramework_EDataListFormat();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataList_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataList();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCustomAssetData();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EOrientation();
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EHorizontalAlignment();
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EVerticalAlignment();
	UMG_API UScriptStruct* Z_Construct_UScriptStruct_FSlateChildSize();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	UMG_API UClass* Z_Construct_UClass_UCanvasPanel_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UWidgetInterface_Input_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnEntrySelected_Parms
		{
			UDataWidget* Entry;
			FString Label;
			UObject* Asset;
			int32 Index;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Entry;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntrySelected_Parms, Entry), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Entry_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Entry_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntrySelected_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntrySelected_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntrySelected_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnEntrySelected__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnEntrySelected_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnEntryHovered_Parms
		{
			UDataWidget* Entry;
			FString Label;
			UObject* Asset;
			int32 Index;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Entry;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHovered_Parms, Entry), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Entry_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Entry_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHovered_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHovered_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHovered_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnEntryHovered__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnEntryHovered_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnEntryUnhovered_Parms
		{
			UDataWidget* Entry;
			FString Label;
			UObject* Asset;
			int32 Index;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Entry;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryUnhovered_Parms, Entry), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Entry_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Entry_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryUnhovered_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryUnhovered_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryUnhovered_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnEntryUnhovered__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnEntryUnhovered_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnEntryHighlighted_Parms
		{
			UDataWidget* Entry;
			FString Label;
			UObject* Asset;
			int32 Index;
			bool IsHighlighted;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Entry;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_IsHighlighted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsHighlighted;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms, Entry), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Entry_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Entry_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_IsHighlighted_SetBit(void* Obj)
	{
		((_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms*)Obj)->IsHighlighted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_IsHighlighted = { "IsHighlighted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms), &Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_IsHighlighted_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::NewProp_IsHighlighted,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnEntryHighlighted__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnEntryHighlighted_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnDataListInputCancel__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnDataListInputPage_Parms
		{
			float Axis;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Axis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnDataListInputPage_Parms, Axis), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::NewProp_Axis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnDataListInputPage__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnDataListInputPage_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics
	{
		struct _Script_OmegaGameFramework_eventOnDataListInputNavigate_Parms
		{
			FVector2D Axis;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Axis;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OmegaGameFramework_eventOnDataListInputNavigate_Parms, Axis), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::NewProp_Axis,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework, nullptr, "OnDataListInputNavigate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::_Script_OmegaGameFramework_eventOnDataListInputNavigate_Parms), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDataListFormat;
	static UEnum* EDataListFormat_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EDataListFormat.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EDataListFormat.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OmegaGameFramework_EDataListFormat, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("EDataListFormat"));
		}
		return Z_Registration_Info_UEnum_EDataListFormat.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UEnum* StaticEnum<EDataListFormat>()
	{
		return EDataListFormat_StaticEnum();
	}
	struct Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::Enumerators[] = {
		{ "EDataListFormat::Format_Box", (int64)EDataListFormat::Format_Box },
		{ "EDataListFormat::Format_ScrollBox", (int64)EDataListFormat::Format_ScrollBox },
		{ "EDataListFormat::Format_UniformGrid", (int64)EDataListFormat::Format_UniformGrid },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::Enum_MetaDataParams[] = {
		{ "Format_Box.DisplayName", "Box" },
		{ "Format_Box.Name", "EDataListFormat::Format_Box" },
		{ "Format_ScrollBox.DisplayName", "Scroll Box" },
		{ "Format_ScrollBox.Name", "EDataListFormat::Format_ScrollBox" },
		{ "Format_UniformGrid.DisplayName", "Uniform Grid" },
		{ "Format_UniformGrid.Name", "EDataListFormat::Format_UniformGrid" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		"EDataListFormat",
		"EDataListFormat",
		Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_OmegaGameFramework_EDataListFormat()
	{
		if (!Z_Registration_Info_UEnum_EDataListFormat.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDataListFormat.InnerSingleton, Z_Construct_UEnum_OmegaGameFramework_EDataListFormat_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EDataListFormat.InnerSingleton;
	}
	DEFINE_FUNCTION(UDataList::execNativeEntityHighlight)
	{
		P_GET_OBJECT(UDataWidget,Z_Param_DataWidget);
		P_GET_UBOOL(Z_Param_bIsHighlighted);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NativeEntityHighlight(Z_Param_DataWidget,Z_Param_bIsHighlighted);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execNativeEntityHover)
	{
		P_GET_OBJECT(UDataWidget,Z_Param_DataWidget);
		P_GET_UBOOL(Z_Param_bIsHovered);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NativeEntityHover(Z_Param_DataWidget,Z_Param_bIsHovered);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execNativeEntitySelect)
	{
		P_GET_OBJECT(UDataWidget,Z_Param_DataWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->NativeEntitySelect(Z_Param_DataWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execBuildList)
	{
		P_GET_OBJECT(UClass,Z_Param_Class);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPanelWidget**)Z_Param__Result=P_THIS->BuildList(Z_Param_Class);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execRebuildList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RebuildList();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execSetListOwner)
	{
		P_GET_OBJECT(UObject,Z_Param_NewOwner);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetListOwner(Z_Param_NewOwner);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execGetEntry)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDataWidget**)Z_Param__Result=P_THIS->GetEntry(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execGetEntryIndex)
	{
		P_GET_OBJECT(UDataWidget,Z_Param_Entry);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetEntryIndex(Z_Param_Entry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execCycleEntry)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CycleEntry(Z_Param_Amount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execSelectHoveredEntry)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectHoveredEntry();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execGetHoveredEntry)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDataWidget**)Z_Param__Result=P_THIS->GetHoveredEntry();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execHoverEntry)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HoverEntry(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execAddedCustomEntryToList)
	{
		P_GET_STRUCT(FCustomAssetData,Z_Param_EntryData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDataWidget**)Z_Param__Result=P_THIS->AddedCustomEntryToList(Z_Param_EntryData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execAddAssetsToList)
	{
		P_GET_TARRAY(UObject*,Z_Param_Assets);
		P_GET_UBOOL(Z_Param_ClearListFirst);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UDataWidget*>*)Z_Param__Result=P_THIS->AddAssetsToList(Z_Param_Assets,Z_Param_ClearListFirst);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execAddAssetToList)
	{
		P_GET_OBJECT(UObject,Z_Param_Asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDataWidget**)Z_Param__Result=P_THIS->AddAssetToList(Z_Param_Asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execRemoveEntryOfAsset)
	{
		P_GET_OBJECT(UObject,Z_Param_Asset);
		P_GET_UBOOL(Z_Param_All);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveEntryOfAsset(Z_Param_Asset,Z_Param_All);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execRemoveEntryFromList)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveEntryFromList(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDataList::execClearList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearList();
		P_NATIVE_END;
	}
	void UDataList::StaticRegisterNativesUDataList()
	{
		UClass* Class = UDataList::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAssetsToList", &UDataList::execAddAssetsToList },
			{ "AddAssetToList", &UDataList::execAddAssetToList },
			{ "AddedCustomEntryToList", &UDataList::execAddedCustomEntryToList },
			{ "BuildList", &UDataList::execBuildList },
			{ "ClearList", &UDataList::execClearList },
			{ "CycleEntry", &UDataList::execCycleEntry },
			{ "GetEntry", &UDataList::execGetEntry },
			{ "GetEntryIndex", &UDataList::execGetEntryIndex },
			{ "GetHoveredEntry", &UDataList::execGetHoveredEntry },
			{ "HoverEntry", &UDataList::execHoverEntry },
			{ "NativeEntityHighlight", &UDataList::execNativeEntityHighlight },
			{ "NativeEntityHover", &UDataList::execNativeEntityHover },
			{ "NativeEntitySelect", &UDataList::execNativeEntitySelect },
			{ "RebuildList", &UDataList::execRebuildList },
			{ "RemoveEntryFromList", &UDataList::execRemoveEntryFromList },
			{ "RemoveEntryOfAsset", &UDataList::execRemoveEntryOfAsset },
			{ "SelectHoveredEntry", &UDataList::execSelectHoveredEntry },
			{ "SetListOwner", &UDataList::execSetListOwner },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataList_AddAssetsToList_Statics
	{
		struct DataList_eventAddAssetsToList_Parms
		{
			TArray<UObject*> Assets;
			bool ClearListFirst;
			TArray<UDataWidget*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Assets_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Assets;
		static void NewProp_ClearListFirst_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ClearListFirst;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_Assets_Inner = { "Assets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_Assets = { "Assets", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventAddAssetsToList_Parms, Assets), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ClearListFirst_SetBit(void* Obj)
	{
		((DataList_eventAddAssetsToList_Parms*)Obj)->ClearListFirst = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ClearListFirst = { "ClearListFirst", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataList_eventAddAssetsToList_Parms), &Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ClearListFirst_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventAddAssetsToList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_Assets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_Assets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ClearListFirst,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "CPP_Default_ClearListFirst", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "AddAssetsToList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::DataList_eventAddAssetsToList_Parms), Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_AddAssetsToList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_AddAssetsToList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_AddAssetToList_Statics
	{
		struct DataList_eventAddAssetToList_Parms
		{
			UObject* Asset;
			UDataWidget* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventAddAssetToList_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventAddAssetToList_Parms, ReturnValue), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_AddAssetToList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddAssetToList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_AddAssetToList_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_AddAssetToList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "AddAssetToList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_AddAssetToList_Statics::DataList_eventAddAssetToList_Parms), Z_Construct_UFunction_UDataList_AddAssetToList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddAssetToList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_AddAssetToList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddAssetToList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_AddAssetToList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_AddAssetToList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics
	{
		struct DataList_eventAddedCustomEntryToList_Parms
		{
			FCustomAssetData EntryData;
			UDataWidget* ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_EntryData;
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_EntryData = { "EntryData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventAddedCustomEntryToList_Parms, EntryData), Z_Construct_UScriptStruct_FCustomAssetData, METADATA_PARAMS(nullptr, 0) }; // 2798204308
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventAddedCustomEntryToList_Parms, ReturnValue), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_EntryData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "AddedCustomEntryToList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::DataList_eventAddedCustomEntryToList_Parms), Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_AddedCustomEntryToList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_AddedCustomEntryToList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_BuildList_Statics
	{
		struct DataList_eventBuildList_Parms
		{
			TSubclassOf<UPanelWidget>  Class;
			UPanelWidget* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
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
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventBuildList_Parms, Class), Z_Construct_UClass_UPanelWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventBuildList_Parms, ReturnValue), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_BuildList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_Class,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_BuildList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_BuildList_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_BuildList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "BuildList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_BuildList_Statics::DataList_eventBuildList_Parms), Z_Construct_UFunction_UDataList_BuildList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_BuildList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_BuildList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_BuildList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_BuildList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_BuildList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_ClearList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_ClearList_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "Comment", "//Clears all ENTRIES from the list\n" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
		{ "ToolTip", "Clears all ENTRIES from the list" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_ClearList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "ClearList", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_ClearList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_ClearList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_ClearList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_ClearList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_CycleEntry_Statics
	{
		struct DataList_eventCycleEntry_Parms
		{
			int32 Amount;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataList_CycleEntry_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventCycleEntry_Parms, Amount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_CycleEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_CycleEntry_Statics::NewProp_Amount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_CycleEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_CycleEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "CycleEntry", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_CycleEntry_Statics::DataList_eventCycleEntry_Parms), Z_Construct_UFunction_UDataList_CycleEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_CycleEntry_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_CycleEntry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_CycleEntry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_CycleEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_CycleEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_GetEntry_Statics
	{
		struct DataList_eventGetEntry_Parms
		{
			int32 Index;
			UDataWidget* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventGetEntry_Parms, Index), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventGetEntry_Parms, ReturnValue), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_GetEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_GetEntry_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_GetEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_GetEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "GetEntry", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_GetEntry_Statics::DataList_eventGetEntry_Parms), Z_Construct_UFunction_UDataList_GetEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetEntry_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_GetEntry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetEntry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_GetEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_GetEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_GetEntryIndex_Statics
	{
		struct DataList_eventGetEntryIndex_Parms
		{
			UDataWidget* Entry;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Entry;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_Entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_Entry = { "Entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventGetEntryIndex_Parms, Entry), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_Entry_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_Entry_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventGetEntryIndex_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_Entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "GetEntryIndex", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::DataList_eventGetEntryIndex_Parms), Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_GetEntryIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_GetEntryIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics
	{
		struct DataList_eventGetHoveredEntry_Parms
		{
			UDataWidget* ReturnValue;
		};
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventGetHoveredEntry_Parms, ReturnValue), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "GetHoveredEntry", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::DataList_eventGetHoveredEntry_Parms), Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_GetHoveredEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_GetHoveredEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_HoverEntry_Statics
	{
		struct DataList_eventHoverEntry_Parms
		{
			int32 Index;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataList_HoverEntry_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventHoverEntry_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_HoverEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_HoverEntry_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_HoverEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "Comment", "//Access Entires\n" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
		{ "ToolTip", "Access Entires" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_HoverEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "HoverEntry", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_HoverEntry_Statics::DataList_eventHoverEntry_Parms), Z_Construct_UFunction_UDataList_HoverEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_HoverEntry_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_HoverEntry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_HoverEntry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_HoverEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_HoverEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics
	{
		struct DataList_eventNativeEntityHighlight_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_DataWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_DataWidget = { "DataWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventNativeEntityHighlight_Parms, DataWidget), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_DataWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_DataWidget_MetaData)) };
	void Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_bIsHighlighted_SetBit(void* Obj)
	{
		((DataList_eventNativeEntityHighlight_Parms*)Obj)->bIsHighlighted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_bIsHighlighted = { "bIsHighlighted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataList_eventNativeEntityHighlight_Parms), &Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_bIsHighlighted_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_DataWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::NewProp_bIsHighlighted,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "NativeEntityHighlight", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::DataList_eventNativeEntityHighlight_Parms), Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_NativeEntityHighlight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_NativeEntityHighlight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_NativeEntityHover_Statics
	{
		struct DataList_eventNativeEntityHover_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_DataWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_DataWidget = { "DataWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventNativeEntityHover_Parms, DataWidget), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_DataWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_DataWidget_MetaData)) };
	void Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_bIsHovered_SetBit(void* Obj)
	{
		((DataList_eventNativeEntityHover_Parms*)Obj)->bIsHovered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_bIsHovered = { "bIsHovered", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataList_eventNativeEntityHover_Parms), &Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_bIsHovered_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_DataWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::NewProp_bIsHovered,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "NativeEntityHover", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::DataList_eventNativeEntityHover_Parms), Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_NativeEntityHover()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_NativeEntityHover_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics
	{
		struct DataList_eventNativeEntitySelect_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::NewProp_DataWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::NewProp_DataWidget = { "DataWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventNativeEntitySelect_Parms, DataWidget), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::NewProp_DataWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::NewProp_DataWidget_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::NewProp_DataWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "NativeEntitySelect", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::DataList_eventNativeEntitySelect_Parms), Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_NativeEntitySelect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_NativeEntitySelect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_RebuildList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_RebuildList_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_RebuildList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "RebuildList", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_RebuildList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_RebuildList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_RebuildList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_RebuildList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics
	{
		struct DataList_eventRemoveEntryFromList_Parms
		{
			int32 Index;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventRemoveEntryFromList_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "RemoveEntryFromList", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::DataList_eventRemoveEntryFromList_Parms), Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_RemoveEntryFromList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_RemoveEntryFromList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics
	{
		struct DataList_eventRemoveEntryOfAsset_Parms
		{
			UObject* Asset;
			bool All;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static void NewProp_All_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_All;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventRemoveEntryOfAsset_Parms, Asset), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::NewProp_All_SetBit(void* Obj)
	{
		((DataList_eventRemoveEntryOfAsset_Parms*)Obj)->All = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::NewProp_All = { "All", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DataList_eventRemoveEntryOfAsset_Parms), &Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::NewProp_All_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::NewProp_All,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "RemoveEntryOfAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::DataList_eventRemoveEntryOfAsset_Parms), Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_RemoveEntryOfAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_RemoveEntryOfAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_SelectHoveredEntry_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_SelectHoveredEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_SelectHoveredEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "SelectHoveredEntry", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_SelectHoveredEntry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_SelectHoveredEntry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_SelectHoveredEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_SelectHoveredEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataList_SetListOwner_Statics
	{
		struct DataList_eventSetListOwner_Parms
		{
			UObject* NewOwner;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NewOwner;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataList_SetListOwner_Statics::NewProp_NewOwner = { "NewOwner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataList_eventSetListOwner_Parms, NewOwner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataList_SetListOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataList_SetListOwner_Statics::NewProp_NewOwner,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataList_SetListOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Widget|DataList" },
		{ "Comment", "//Owner\n" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
		{ "ToolTip", "Owner" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataList_SetListOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataList, nullptr, "SetListOwner", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDataList_SetListOwner_Statics::DataList_eventSetListOwner_Parms), Z_Construct_UFunction_UDataList_SetListOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_SetListOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataList_SetListOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataList_SetListOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataList_SetListOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataList_SetListOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataList);
	UClass* Z_Construct_UClass_UDataList_NoRegister()
	{
		return UDataList::StaticClass();
	}
	struct Z_Construct_UClass_UDataList_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Format_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Format_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Format;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EntryHorizontalAlignment_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_EntryHorizontalAlignment;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EntryVerticalAlignment_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_EntryVerticalAlignment;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EntrySize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EntrySize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoSizeList_MetaData[];
#endif
		static void NewProp_bAutoSizeList_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoSizeList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EntryClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_EntryClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultAssets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAssets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_DefaultAssets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCustomEntries_MetaData[];
#endif
		static void NewProp_bUseCustomEntries_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCustomEntries;
		static const UECodeGen_Private::FStructPropertyParams NewProp_CustomEntries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomEntries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CustomEntries;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UniformGridMaxValue_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_UniformGridMaxValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EntryLabel_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EntryLabel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ListTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ListTags;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Entries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Entries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Entries;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParentPanel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentPanel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoveredEntry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HoveredEntry;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CycleOnInputNavigate_MetaData[];
#endif
		static void NewProp_CycleOnInputNavigate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CycleOnInputNavigate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CycleOnInputPage_MetaData[];
#endif
		static void NewProp_CycleOnInputPage_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_CycleOnInputPage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ListOwner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ListOwner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ListPanel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ListPanel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentA_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentA;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentB_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentB;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEntrySelected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntrySelected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEntryHovered_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntryHovered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEntryUnhovered_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntryUnhovered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEntryHighlighted_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntryHighlighted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnInputCancel_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInputCancel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnInputNavigate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInputNavigate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnInputPage_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInputPage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataList_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataList_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataList_AddAssetsToList, "AddAssetsToList" }, // 3279260874
		{ &Z_Construct_UFunction_UDataList_AddAssetToList, "AddAssetToList" }, // 2701641319
		{ &Z_Construct_UFunction_UDataList_AddedCustomEntryToList, "AddedCustomEntryToList" }, // 2215364257
		{ &Z_Construct_UFunction_UDataList_BuildList, "BuildList" }, // 615641146
		{ &Z_Construct_UFunction_UDataList_ClearList, "ClearList" }, // 3734530348
		{ &Z_Construct_UFunction_UDataList_CycleEntry, "CycleEntry" }, // 4133018956
		{ &Z_Construct_UFunction_UDataList_GetEntry, "GetEntry" }, // 3513986626
		{ &Z_Construct_UFunction_UDataList_GetEntryIndex, "GetEntryIndex" }, // 1808693951
		{ &Z_Construct_UFunction_UDataList_GetHoveredEntry, "GetHoveredEntry" }, // 1508387754
		{ &Z_Construct_UFunction_UDataList_HoverEntry, "HoverEntry" }, // 746253111
		{ &Z_Construct_UFunction_UDataList_NativeEntityHighlight, "NativeEntityHighlight" }, // 1546911116
		{ &Z_Construct_UFunction_UDataList_NativeEntityHover, "NativeEntityHover" }, // 1535562615
		{ &Z_Construct_UFunction_UDataList_NativeEntitySelect, "NativeEntitySelect" }, // 3982439753
		{ &Z_Construct_UFunction_UDataList_RebuildList, "RebuildList" }, // 2489390936
		{ &Z_Construct_UFunction_UDataList_RemoveEntryFromList, "RemoveEntryFromList" }, // 1297008069
		{ &Z_Construct_UFunction_UDataList_RemoveEntryOfAsset, "RemoveEntryOfAsset" }, // 2117912292
		{ &Z_Construct_UFunction_UDataList_SelectHoveredEntry, "SelectHoveredEntry" }, // 1646601293
		{ &Z_Construct_UFunction_UDataList_SetListOwner, "SetListOwner" }, // 2361432912
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Widget/DataList.h" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_Format_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_Format_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_Format = { "Format", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, Format), Z_Construct_UEnum_OmegaGameFramework_EDataListFormat, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_Format_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_Format_MetaData)) }; // 4277020572
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_Orientation_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, Orientation), Z_Construct_UEnum_SlateCore_EOrientation, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_Orientation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_Orientation_MetaData)) }; // 3412645699
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_EntryHorizontalAlignment_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_EntryHorizontalAlignment = { "EntryHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, EntryHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_EntryHorizontalAlignment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_EntryHorizontalAlignment_MetaData)) }; // 4247529014
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_EntryVerticalAlignment_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_EntryVerticalAlignment = { "EntryVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, EntryVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_EntryVerticalAlignment_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_EntryVerticalAlignment_MetaData)) }; // 1453904578
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_EntrySize_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_EntrySize = { "EntrySize", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, EntrySize), Z_Construct_UScriptStruct_FSlateChildSize, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_EntrySize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_EntrySize_MetaData)) }; // 3750423179
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	void Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList_SetBit(void* Obj)
	{
		((UDataList*)Obj)->bAutoSizeList = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList = { "bAutoSizeList", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDataList), &Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_EntryClass_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_EntryClass = { "EntryClass", nullptr, (EPropertyFlags)0x0014000000000815, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, EntryClass), Z_Construct_UClass_UDataWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_EntryClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_EntryClass_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets_Inner = { "DefaultAssets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets = { "DefaultAssets", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, DefaultAssets), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	void Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries_SetBit(void* Obj)
	{
		((UDataList*)Obj)->bUseCustomEntries = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries = { "bUseCustomEntries", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDataList), &Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries_Inner = { "CustomEntries", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FCustomAssetData, METADATA_PARAMS(nullptr, 0) }; // 2798204308
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries = { "CustomEntries", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, CustomEntries), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries_MetaData)) }; // 2798204308
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_UniformGridMaxValue_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_UniformGridMaxValue = { "UniformGridMaxValue", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, UniformGridMaxValue), METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_UniformGridMaxValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_UniformGridMaxValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_EntryLabel_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_EntryLabel = { "EntryLabel", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, EntryLabel), METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_EntryLabel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_EntryLabel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_ListTags_MetaData[] = {
		{ "Category", "Entry" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_ListTags = { "ListTags", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, ListTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_ListTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_ListTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_Entries_Inner = { "Entries", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_Entries_MetaData[] = {
		{ "Category", "Entry" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_Entries = { "Entries", nullptr, (EPropertyFlags)0x001000800000001c, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, Entries), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_Entries_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_Entries_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_ParentPanel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_ParentPanel = { "ParentPanel", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, ParentPanel), Z_Construct_UClass_UCanvasPanel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_ParentPanel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_ParentPanel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_HoveredEntry_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_HoveredEntry = { "HoveredEntry", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, HoveredEntry), Z_Construct_UClass_UDataWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_HoveredEntry_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_HoveredEntry_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	void Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate_SetBit(void* Obj)
	{
		((UDataList*)Obj)->CycleOnInputNavigate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate = { "CycleOnInputNavigate", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDataList), &Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	void Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage_SetBit(void* Obj)
	{
		((UDataList*)Obj)->CycleOnInputPage = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage = { "CycleOnInputPage", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDataList), &Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_ListOwner_MetaData[] = {
		{ "Category", "DataList" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_ListOwner = { "ListOwner", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, ListOwner), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_ListOwner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_ListOwner_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_ListPanel_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_ListPanel = { "ListPanel", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, ListPanel), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_ListPanel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_ListPanel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_CurrentA_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_CurrentA = { "CurrentA", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, CurrentA), METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_CurrentA_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_CurrentA_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_CurrentB_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_CurrentB = { "CurrentB", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, CurrentB), METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_CurrentB_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_CurrentB_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnEntrySelected_MetaData[] = {
		{ "Comment", "//Delegate Props\n" },
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
		{ "ToolTip", "Delegate Props" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnEntrySelected = { "OnEntrySelected", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnEntrySelected), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntrySelected__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntrySelected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntrySelected_MetaData)) }; // 2872363746
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHovered_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHovered = { "OnEntryHovered", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnEntryHovered), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHovered__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHovered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHovered_MetaData)) }; // 1918244397
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryUnhovered_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryUnhovered = { "OnEntryUnhovered", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnEntryUnhovered), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryUnhovered__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryUnhovered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryUnhovered_MetaData)) }; // 3779869777
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHighlighted_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHighlighted = { "OnEntryHighlighted", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnEntryHighlighted), Z_Construct_UDelegateFunction_OmegaGameFramework_OnEntryHighlighted__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHighlighted_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHighlighted_MetaData)) }; // 4054105244
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnInputCancel_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnInputCancel = { "OnInputCancel", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnInputCancel), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputCancel__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnInputCancel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnInputCancel_MetaData)) }; // 1112899809
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnInputNavigate_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnInputNavigate = { "OnInputNavigate", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnInputNavigate), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputNavigate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnInputNavigate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnInputNavigate_MetaData)) }; // 2754102866
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataList_Statics::NewProp_OnInputPage_MetaData[] = {
		{ "ModuleRelativePath", "Public/Widget/DataList.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDataList_Statics::NewProp_OnInputPage = { "OnInputPage", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDataList, OnInputPage), Z_Construct_UDelegateFunction_OmegaGameFramework_OnDataListInputPage__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::NewProp_OnInputPage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::NewProp_OnInputPage_MetaData)) }; // 3369194354
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDataList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_Format_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_Format,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_EntryHorizontalAlignment,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_EntryVerticalAlignment,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_EntrySize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_bAutoSizeList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_EntryClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_DefaultAssets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_bUseCustomEntries,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_CustomEntries,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_UniformGridMaxValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_EntryLabel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_ListTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_Entries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_Entries,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_ParentPanel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_HoveredEntry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputNavigate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_CycleOnInputPage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_ListOwner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_ListPanel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_CurrentA,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_CurrentB,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnEntrySelected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHovered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryUnhovered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnEntryHighlighted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnInputCancel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnInputNavigate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDataList_Statics::NewProp_OnInputPage,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UDataList_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UWidgetInterface_Input_NoRegister, (int32)VTABLE_OFFSET(UDataList, IWidgetInterface_Input), false },  // 2763076704
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataList_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDataList>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataList_Statics::ClassParams = {
		&UDataList::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDataList_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDataList_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataList_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataList()
	{
		if (!Z_Registration_Info_UClass_UDataList.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataList.OuterSingleton, Z_Construct_UClass_UDataList_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataList.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataList>()
	{
		return UDataList::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataList);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics::EnumInfo[] = {
		{ EDataListFormat_StaticEnum, TEXT("EDataListFormat"), &Z_Registration_Info_UEnum_EDataListFormat, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4277020572U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataList, UDataList::StaticClass, TEXT("UDataList"), &Z_Registration_Info_UClass_UDataList, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataList), 2919187768U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_2745641469(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Widget_DataList_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
