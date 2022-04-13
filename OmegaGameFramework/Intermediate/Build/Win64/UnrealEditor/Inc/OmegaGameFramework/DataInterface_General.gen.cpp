// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/DataInterface_General.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDataInterface_General() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_General_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_General();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
// End Cross Module References
	DEFINE_FUNCTION(IDataInterface_General::execGetGeneralAssetLabel)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Label);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetLabel_Implementation(Z_Param_Out_Label);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IDataInterface_General::execGetGeneralAssetColor)
	{
		P_GET_STRUCT_REF(FLinearColor,Z_Param_Out_Color);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetColor_Implementation(Z_Param_Out_Color);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IDataInterface_General::execGetGeneralDataImages)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Label);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_GET_OBJECT_REF(UTexture2D,Z_Param_Out_Texture);
		P_GET_OBJECT_REF(UMaterialInterface,Z_Param_Out_Material);
		P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_Brush);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralDataImages_Implementation(Z_Param_Label,Z_Param_Context,Z_Param_Out_Texture,Z_Param_Out_Material,Z_Param_Out_Brush);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IDataInterface_General::execGetGeneralDataText)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Label);
		P_GET_OBJECT(UObject,Z_Param_Context);
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Name);
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Description);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralDataText_Implementation(Z_Param_Label,Z_Param_Context,Z_Param_Out_Name,Z_Param_Out_Description);
		P_NATIVE_END;
	}
	void IDataInterface_General::GetGeneralAssetColor(FLinearColor& Color)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetGeneralAssetColor instead.");
	}
	void IDataInterface_General::GetGeneralAssetLabel(FString& Label)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetGeneralAssetLabel instead.");
	}
	void IDataInterface_General::GetGeneralDataImages(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetGeneralDataImages instead.");
	}
	void IDataInterface_General::GetGeneralDataText(const FString& Label, const UObject* Context, FText& Name, FText& Description)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetGeneralDataText instead.");
	}
	void UDataInterface_General::StaticRegisterNativesUDataInterface_General()
	{
		UClass* Class = UDataInterface_General::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGeneralAssetColor", &IDataInterface_General::execGetGeneralAssetColor },
			{ "GetGeneralAssetLabel", &IDataInterface_General::execGetGeneralAssetLabel },
			{ "GetGeneralDataImages", &IDataInterface_General::execGetGeneralDataImages },
			{ "GetGeneralDataText", &IDataInterface_General::execGetGeneralDataText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralAssetColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::NewProp_Color,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Color\n" },
		{ "ModuleRelativePath", "Public/DataInterface_General.h" },
		{ "ToolTip", "Color" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_General, nullptr, "GetGeneralAssetColor", nullptr, nullptr, sizeof(DataInterface_General_eventGetGeneralAssetColor_Parms), Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics
	{
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralAssetLabel_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::NewProp_Label,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//AssetLabel\n" },
		{ "ModuleRelativePath", "Public/DataInterface_General.h" },
		{ "ToolTip", "AssetLabel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_General, nullptr, "GetGeneralAssetLabel", nullptr, nullptr, sizeof(DataInterface_General_eventGetGeneralAssetLabel_Parms), Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Brush;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataImages_Parms, Label), METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataImages_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Context_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataImages_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataImages_Parms, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Brush = { "Brush", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataImages_Parms, Brush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(nullptr, 0) }; // 852902259
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Texture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Material,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::NewProp_Brush,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Images\n" },
		{ "ModuleRelativePath", "Public/DataInterface_General.h" },
		{ "ToolTip", "Images" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_General, nullptr, "GetGeneralDataImages", nullptr, nullptr, sizeof(DataInterface_General_eventGetGeneralDataImages_Parms), Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Context;
		static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
		static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataText_Parms, Label), METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataText_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Context_MetaData)) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataText_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DataInterface_General_eventGetGeneralDataText_Parms, Description), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::NewProp_Description,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Texts\n" },
		{ "ModuleRelativePath", "Public/DataInterface_General.h" },
		{ "ToolTip", "Texts" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDataInterface_General, nullptr, "GetGeneralDataText", nullptr, nullptr, sizeof(DataInterface_General_eventGetGeneralDataText_Parms), Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDataInterface_General);
	UClass* Z_Construct_UClass_UDataInterface_General_NoRegister()
	{
		return UDataInterface_General::StaticClass();
	}
	struct Z_Construct_UClass_UDataInterface_General_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDataInterface_General_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDataInterface_General_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetColor, "GetGeneralAssetColor" }, // 3896430979
		{ &Z_Construct_UFunction_UDataInterface_General_GetGeneralAssetLabel, "GetGeneralAssetLabel" }, // 3474295450
		{ &Z_Construct_UFunction_UDataInterface_General_GetGeneralDataImages, "GetGeneralDataImages" }, // 4178426636
		{ &Z_Construct_UFunction_UDataInterface_General_GetGeneralDataText, "GetGeneralDataText" }, // 3524620183
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDataInterface_General_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DataInterface_General.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDataInterface_General_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IDataInterface_General>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDataInterface_General_Statics::ClassParams = {
		&UDataInterface_General::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UDataInterface_General_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDataInterface_General_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDataInterface_General()
	{
		if (!Z_Registration_Info_UClass_UDataInterface_General.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDataInterface_General.OuterSingleton, Z_Construct_UClass_UDataInterface_General_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDataInterface_General.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDataInterface_General>()
	{
		return UDataInterface_General::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDataInterface_General);
	static FName NAME_UDataInterface_General_GetGeneralAssetColor = FName(TEXT("GetGeneralAssetColor"));
	void IDataInterface_General::Execute_GetGeneralAssetColor(UObject* O, FLinearColor& Color)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()));
		DataInterface_General_eventGetGeneralAssetColor_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_General_GetGeneralAssetColor);
		if (Func)
		{
			Parms.Color=Color;
			O->ProcessEvent(Func, &Parms);
			Color=Parms.Color;
		}
		else if (auto I = (IDataInterface_General*)(O->GetNativeInterfaceAddress(UDataInterface_General::StaticClass())))
		{
			I->GetGeneralAssetColor_Implementation(Color);
		}
	}
	static FName NAME_UDataInterface_General_GetGeneralAssetLabel = FName(TEXT("GetGeneralAssetLabel"));
	void IDataInterface_General::Execute_GetGeneralAssetLabel(UObject* O, FString& Label)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()));
		DataInterface_General_eventGetGeneralAssetLabel_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_General_GetGeneralAssetLabel);
		if (Func)
		{
			Parms.Label=Label;
			O->ProcessEvent(Func, &Parms);
			Label=Parms.Label;
		}
		else if (auto I = (IDataInterface_General*)(O->GetNativeInterfaceAddress(UDataInterface_General::StaticClass())))
		{
			I->GetGeneralAssetLabel_Implementation(Label);
		}
	}
	static FName NAME_UDataInterface_General_GetGeneralDataImages = FName(TEXT("GetGeneralDataImages"));
	void IDataInterface_General::Execute_GetGeneralDataImages(UObject* O, const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()));
		DataInterface_General_eventGetGeneralDataImages_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_General_GetGeneralDataImages);
		if (Func)
		{
			Parms.Label=Label;
			Parms.Context=Context;
			Parms.Texture=Texture;
			Parms.Material=Material;
			Parms.Brush=Brush;
			O->ProcessEvent(Func, &Parms);
			Texture=Parms.Texture;
			Material=Parms.Material;
			Brush=Parms.Brush;
		}
		else if (auto I = (IDataInterface_General*)(O->GetNativeInterfaceAddress(UDataInterface_General::StaticClass())))
		{
			I->GetGeneralDataImages_Implementation(Label,Context,Texture,Material,Brush);
		}
	}
	static FName NAME_UDataInterface_General_GetGeneralDataText = FName(TEXT("GetGeneralDataText"));
	void IDataInterface_General::Execute_GetGeneralDataText(UObject* O, const FString& Label, const UObject* Context, FText& Name, FText& Description)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UDataInterface_General::StaticClass()));
		DataInterface_General_eventGetGeneralDataText_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UDataInterface_General_GetGeneralDataText);
		if (Func)
		{
			Parms.Label=Label;
			Parms.Context=Context;
			Parms.Name=Name;
			Parms.Description=Description;
			O->ProcessEvent(Func, &Parms);
			Name=Parms.Name;
			Description=Parms.Description;
		}
		else if (auto I = (IDataInterface_General*)(O->GetNativeInterfaceAddress(UDataInterface_General::StaticClass())))
		{
			I->GetGeneralDataText_Implementation(Label,Context,Name,Description);
		}
	}
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDataInterface_General, UDataInterface_General::StaticClass, TEXT("UDataInterface_General"), &Z_Registration_Info_UClass_UDataInterface_General, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDataInterface_General), 1389727800U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_946802706(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DataInterface_General_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
