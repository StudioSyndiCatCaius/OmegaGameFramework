// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Data/GeneralDataObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGeneralDataObject() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FCustomAssetData();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGeneralDataObject_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGeneralDataObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_General_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CustomAssetData;
class UScriptStruct* FCustomAssetData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CustomAssetData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CustomAssetData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCustomAssetData, Z_Construct_UPackage__Script_OmegaGameFramework(), TEXT("CustomAssetData"));
	}
	return Z_Registration_Info_UScriptStruct_CustomAssetData.OuterSingleton;
}
template<> OMEGAGAMEFRAMEWORK_API UScriptStruct* StaticStruct<FCustomAssetData>()
{
	return FCustomAssetData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCustomAssetData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Texture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomAssetData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCustomAssetData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_DisplayName_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomAssetData, DisplayName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_DisplayName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_DisplayName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomAssetData, Description), METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Description_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Label_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomAssetData, Label), METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Texture_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomAssetData, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Texture_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Texture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomAssetData, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Color_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Color_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCustomAssetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_DisplayName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Description,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Texture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewProp_Color,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCustomAssetData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
		nullptr,
		&NewStructOps,
		"CustomAssetData",
		sizeof(FCustomAssetData),
		alignof(FCustomAssetData),
		Z_Construct_UScriptStruct_FCustomAssetData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomAssetData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomAssetData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCustomAssetData()
	{
		if (!Z_Registration_Info_UScriptStruct_CustomAssetData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CustomAssetData.InnerSingleton, Z_Construct_UScriptStruct_FCustomAssetData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CustomAssetData.InnerSingleton;
	}
	DEFINE_FUNCTION(UGeneralDataObject::execGetGeneralAssetLabel)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Label);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetLabel_Implementation(Z_Param_Out_Label);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGeneralDataObject::execGetGeneralAssetColor)
	{
		P_GET_STRUCT_REF(FLinearColor,Z_Param_Out_Color);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetColor_Implementation(Z_Param_Out_Color);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGeneralDataObject::execGetGeneralDataImages)
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
	DEFINE_FUNCTION(UGeneralDataObject::execGetGeneralDataText)
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
	static FName NAME_UGeneralDataObject_GetGeneralAssetColor = FName(TEXT("GetGeneralAssetColor"));
	void UGeneralDataObject::GetGeneralAssetColor(FLinearColor& Color)
	{
		GeneralDataObject_eventGetGeneralAssetColor_Parms Parms;
		Parms.Color=Color;
		ProcessEvent(FindFunctionChecked(NAME_UGeneralDataObject_GetGeneralAssetColor),&Parms);
		Color=Parms.Color;
	}
	static FName NAME_UGeneralDataObject_GetGeneralAssetLabel = FName(TEXT("GetGeneralAssetLabel"));
	void UGeneralDataObject::GetGeneralAssetLabel(FString& Label)
	{
		GeneralDataObject_eventGetGeneralAssetLabel_Parms Parms;
		Parms.Label=Label;
		ProcessEvent(FindFunctionChecked(NAME_UGeneralDataObject_GetGeneralAssetLabel),&Parms);
		Label=Parms.Label;
	}
	static FName NAME_UGeneralDataObject_GetGeneralDataImages = FName(TEXT("GetGeneralDataImages"));
	void UGeneralDataObject::GetGeneralDataImages(const FString& Label, const UObject* Context, UTexture2D*& Texture, UMaterialInterface*& Material, FSlateBrush& Brush)
	{
		GeneralDataObject_eventGetGeneralDataImages_Parms Parms;
		Parms.Label=Label;
		Parms.Context=Context;
		Parms.Texture=Texture;
		Parms.Material=Material;
		Parms.Brush=Brush;
		ProcessEvent(FindFunctionChecked(NAME_UGeneralDataObject_GetGeneralDataImages),&Parms);
		Texture=Parms.Texture;
		Material=Parms.Material;
		Brush=Parms.Brush;
	}
	static FName NAME_UGeneralDataObject_GetGeneralDataText = FName(TEXT("GetGeneralDataText"));
	void UGeneralDataObject::GetGeneralDataText(const FString& Label, const UObject* Context, FText& Name, FText& Description)
	{
		GeneralDataObject_eventGetGeneralDataText_Parms Parms;
		Parms.Label=Label;
		Parms.Context=Context;
		Parms.Name=Name;
		Parms.Description=Description;
		ProcessEvent(FindFunctionChecked(NAME_UGeneralDataObject_GetGeneralDataText),&Parms);
		Name=Parms.Name;
		Description=Parms.Description;
	}
	void UGeneralDataObject::StaticRegisterNativesUGeneralDataObject()
	{
		UClass* Class = UGeneralDataObject::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGeneralAssetColor", &UGeneralDataObject::execGetGeneralAssetColor },
			{ "GetGeneralAssetLabel", &UGeneralDataObject::execGetGeneralAssetLabel },
			{ "GetGeneralDataImages", &UGeneralDataObject::execGetGeneralDataImages },
			{ "GetGeneralDataText", &UGeneralDataObject::execGetGeneralDataText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralAssetColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::NewProp_Color,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Color\n" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
		{ "ToolTip", "Color" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGeneralDataObject, nullptr, "GetGeneralAssetColor", nullptr, nullptr, sizeof(GeneralDataObject_eventGetGeneralAssetColor_Parms), Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics
	{
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralAssetLabel_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::NewProp_Label,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//AssetLabel\n" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
		{ "ToolTip", "AssetLabel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGeneralDataObject, nullptr, "GetGeneralAssetLabel", nullptr, nullptr, sizeof(GeneralDataObject_eventGetGeneralAssetLabel_Parms), Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataImages_Parms, Label), METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataImages_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Context_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataImages_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataImages_Parms, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Brush = { "Brush", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataImages_Parms, Brush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(nullptr, 0) }; // 852902259
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Texture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Material,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::NewProp_Brush,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Images\n" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
		{ "ToolTip", "Images" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGeneralDataObject, nullptr, "GetGeneralDataImages", nullptr, nullptr, sizeof(GeneralDataObject_eventGetGeneralDataImages_Parms), Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataText_Parms, Label), METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataText_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Context_MetaData)) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataText_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GeneralDataObject_eventGetGeneralDataText_Parms, Description), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::NewProp_Description,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Texts\n" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
		{ "ToolTip", "Texts" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGeneralDataObject, nullptr, "GetGeneralDataText", nullptr, nullptr, sizeof(GeneralDataObject_eventGetGeneralDataText_Parms), Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGeneralDataObject);
	UClass* Z_Construct_UClass_UGeneralDataObject_NoRegister()
	{
		return UGeneralDataObject::StaticClass();
	}
	struct Z_Construct_UClass_UGeneralDataObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CustomData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGeneralDataObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGeneralDataObject_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetColor, "GetGeneralAssetColor" }, // 414904603
		{ &Z_Construct_UFunction_UGeneralDataObject_GetGeneralAssetLabel, "GetGeneralAssetLabel" }, // 2403084960
		{ &Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataImages, "GetGeneralDataImages" }, // 1497819443
		{ &Z_Construct_UFunction_UGeneralDataObject_GetGeneralDataText, "GetGeneralDataText" }, // 2258900874
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGeneralDataObject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Data/GeneralDataObject.h" },
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGeneralDataObject_Statics::NewProp_CustomData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Data/GeneralDataObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGeneralDataObject_Statics::NewProp_CustomData = { "CustomData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGeneralDataObject, CustomData), Z_Construct_UScriptStruct_FCustomAssetData, METADATA_PARAMS(Z_Construct_UClass_UGeneralDataObject_Statics::NewProp_CustomData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGeneralDataObject_Statics::NewProp_CustomData_MetaData)) }; // 2798204308
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGeneralDataObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGeneralDataObject_Statics::NewProp_CustomData,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UGeneralDataObject_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UDataInterface_General_NoRegister, (int32)VTABLE_OFFSET(UGeneralDataObject, IDataInterface_General), false },  // 1389727800
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGeneralDataObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGeneralDataObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGeneralDataObject_Statics::ClassParams = {
		&UGeneralDataObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGeneralDataObject_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGeneralDataObject_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGeneralDataObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGeneralDataObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGeneralDataObject()
	{
		if (!Z_Registration_Info_UClass_UGeneralDataObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGeneralDataObject.OuterSingleton, Z_Construct_UClass_UGeneralDataObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGeneralDataObject.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGeneralDataObject>()
	{
		return UGeneralDataObject::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGeneralDataObject);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics::ScriptStructInfo[] = {
		{ FCustomAssetData::StaticStruct, Z_Construct_UScriptStruct_FCustomAssetData_Statics::NewStructOps, TEXT("CustomAssetData"), &Z_Registration_Info_UScriptStruct_CustomAssetData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCustomAssetData), 2798204308U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGeneralDataObject, UGeneralDataObject::StaticClass, TEXT("UGeneralDataObject"), &Z_Registration_Info_UClass_UGeneralDataObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGeneralDataObject), 355167182U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_455526233(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Data_GeneralDataObject_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
