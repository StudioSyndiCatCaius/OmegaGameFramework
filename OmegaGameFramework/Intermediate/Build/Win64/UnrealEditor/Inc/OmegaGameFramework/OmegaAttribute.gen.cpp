// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaAttribute.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaAttribute() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaAttribute();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_General_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayTagsInterface_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UOmegaAttribute::execGetGeneralAssetLabel)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Label);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetLabel_Implementation(Z_Param_Out_Label);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaAttribute::execGetGeneralAssetColor)
	{
		P_GET_STRUCT_REF(FLinearColor,Z_Param_Out_Color);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetColor_Implementation(Z_Param_Out_Color);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaAttribute::execGetGeneralDataText)
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
	DEFINE_FUNCTION(UOmegaAttribute::execGetObjectGameplayTags)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetObjectGameplayTags_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaAttribute::execGetObjectGameplayCategory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTag*)Z_Param__Result=P_THIS->GetObjectGameplayCategory_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaAttribute::execGetAttributeValue)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Level);
		P_GET_PROPERTY(FIntProperty,Z_Param_AttributeRank);
		P_GET_STRUCT(FGameplayTag,Z_Param_ValueCategory);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetAttributeValue(Z_Param_Level,Z_Param_AttributeRank,Z_Param_ValueCategory);
		P_NATIVE_END;
	}
	static FName NAME_UOmegaAttribute_GetGeneralAssetColor = FName(TEXT("GetGeneralAssetColor"));
	void UOmegaAttribute::GetGeneralAssetColor(FLinearColor& Color)
	{
		OmegaAttribute_eventGetGeneralAssetColor_Parms Parms;
		Parms.Color=Color;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaAttribute_GetGeneralAssetColor),&Parms);
		Color=Parms.Color;
	}
	static FName NAME_UOmegaAttribute_GetGeneralAssetLabel = FName(TEXT("GetGeneralAssetLabel"));
	void UOmegaAttribute::GetGeneralAssetLabel(FString& Label)
	{
		OmegaAttribute_eventGetGeneralAssetLabel_Parms Parms;
		Parms.Label=Label;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaAttribute_GetGeneralAssetLabel),&Parms);
		Label=Parms.Label;
	}
	static FName NAME_UOmegaAttribute_GetGeneralDataText = FName(TEXT("GetGeneralDataText"));
	void UOmegaAttribute::GetGeneralDataText(const FString& Label, const UObject* Context, FText& Name, FText& Description)
	{
		OmegaAttribute_eventGetGeneralDataText_Parms Parms;
		Parms.Label=Label;
		Parms.Context=Context;
		Parms.Name=Name;
		Parms.Description=Description;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaAttribute_GetGeneralDataText),&Parms);
		Name=Parms.Name;
		Description=Parms.Description;
	}
	static FName NAME_UOmegaAttribute_GetObjectGameplayCategory = FName(TEXT("GetObjectGameplayCategory"));
	FGameplayTag UOmegaAttribute::GetObjectGameplayCategory()
	{
		OmegaAttribute_eventGetObjectGameplayCategory_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaAttribute_GetObjectGameplayCategory),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UOmegaAttribute_GetObjectGameplayTags = FName(TEXT("GetObjectGameplayTags"));
	FGameplayTagContainer UOmegaAttribute::GetObjectGameplayTags()
	{
		OmegaAttribute_eventGetObjectGameplayTags_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UOmegaAttribute_GetObjectGameplayTags),&Parms);
		return Parms.ReturnValue;
	}
	void UOmegaAttribute::StaticRegisterNativesUOmegaAttribute()
	{
		UClass* Class = UOmegaAttribute::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAttributeValue", &UOmegaAttribute::execGetAttributeValue },
			{ "GetGeneralAssetColor", &UOmegaAttribute::execGetGeneralAssetColor },
			{ "GetGeneralAssetLabel", &UOmegaAttribute::execGetGeneralAssetLabel },
			{ "GetGeneralDataText", &UOmegaAttribute::execGetGeneralDataText },
			{ "GetObjectGameplayCategory", &UOmegaAttribute::execGetObjectGameplayCategory },
			{ "GetObjectGameplayTags", &UOmegaAttribute::execGetObjectGameplayTags },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics
	{
		struct OmegaAttribute_eventGetAttributeValue_Parms
		{
			int32 Level;
			int32 AttributeRank;
			FGameplayTag ValueCategory;
			float ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
		static const UECodeGen_Private::FIntPropertyParams NewProp_AttributeRank;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ValueCategory;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetAttributeValue_Parms, Level), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_AttributeRank = { "AttributeRank", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetAttributeValue_Parms, AttributeRank), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_ValueCategory = { "ValueCategory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetAttributeValue_Parms, ValueCategory), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetAttributeValue_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_AttributeRank,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_ValueCategory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "\xce\xa9|Attributes" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaAttribute, nullptr, "GetAttributeValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::OmegaAttribute_eventGetAttributeValue_Parms), Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetGeneralAssetColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::NewProp_Color,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Color\n" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
		{ "ToolTip", "Color" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaAttribute, nullptr, "GetGeneralAssetColor", nullptr, nullptr, sizeof(OmegaAttribute_eventGetGeneralAssetColor_Parms), Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics
	{
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetGeneralAssetLabel_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::NewProp_Label,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//AssetLabel\n" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
		{ "ToolTip", "AssetLabel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaAttribute, nullptr, "GetGeneralAssetLabel", nullptr, nullptr, sizeof(OmegaAttribute_eventGetGeneralAssetLabel_Parms), Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetGeneralDataText_Parms, Label), METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetGeneralDataText_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Context_MetaData)) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetGeneralDataText_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetGeneralDataText_Parms, Description), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::NewProp_Description,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Texts\n" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
		{ "ToolTip", "Texts" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaAttribute, nullptr, "GetGeneralDataText", nullptr, nullptr, sizeof(OmegaAttribute_eventGetGeneralDataText_Parms), Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetObjectGameplayCategory_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaAttribute, nullptr, "GetObjectGameplayCategory", nullptr, nullptr, sizeof(OmegaAttribute_eventGetObjectGameplayCategory_Parms), Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaAttribute_eventGetObjectGameplayTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaAttribute, nullptr, "GetObjectGameplayTags", nullptr, nullptr, sizeof(OmegaAttribute_eventGetObjectGameplayTags_Parms), Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaAttribute);
	UClass* Z_Construct_UClass_UOmegaAttribute_NoRegister()
	{
		return UOmegaAttribute::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaAttribute_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeName_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_AttributeName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeLabel_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AttributeLabel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeIcon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeIcon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AttributeColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartValuePercentage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StartValuePercentage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxValue_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsValueStatic_MetaData[];
#endif
		static void NewProp_bIsValueStatic_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValueStatic;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RankValueCurves_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RankValueCurves_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RankValueCurves;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ValueCategoryAdjustments_ValueProp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ValueCategoryAdjustments_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ValueCategoryAdjustments_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_ValueCategoryAdjustments;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeCategory_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AttributeCategory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AttributeTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaAttribute_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaAttribute_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaAttribute_GetAttributeValue, "GetAttributeValue" }, // 1100302063
		{ &Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetColor, "GetGeneralAssetColor" }, // 3534593483
		{ &Z_Construct_UFunction_UOmegaAttribute_GetGeneralAssetLabel, "GetGeneralAssetLabel" }, // 1085442335
		{ &Z_Construct_UFunction_UOmegaAttribute_GetGeneralDataText, "GetGeneralDataText" }, // 1893066750
		{ &Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayCategory, "GetObjectGameplayCategory" }, // 465365341
		{ &Z_Construct_UFunction_UOmegaAttribute_GetObjectGameplayTags, "GetObjectGameplayTags" }, // 3665198221
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OmegaAttribute.h" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeName_MetaData[] = {
		{ "Category", "General" },
		{ "DisplayName", "Name" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeName = { "AttributeName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, AttributeName), METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeLabel_MetaData[] = {
		{ "Category", "General" },
		{ "DisplayName", "Label" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeLabel = { "AttributeLabel", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, AttributeLabel), METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeLabel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeLabel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeIcon_MetaData[] = {
		{ "Category", "General" },
		{ "DisplayName", "Icon" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeIcon = { "AttributeIcon", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, AttributeIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeIcon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeIcon_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeColor_MetaData[] = {
		{ "Category", "General" },
		{ "DisplayName", "Color" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeColor = { "AttributeColor", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, AttributeColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_StartValuePercentage_MetaData[] = {
		{ "Category", "Value" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_StartValuePercentage = { "StartValuePercentage", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, StartValuePercentage), METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_StartValuePercentage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_StartValuePercentage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_MaxValue_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, MaxValue), METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_MaxValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_MaxValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	void Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic_SetBit(void* Obj)
	{
		((UOmegaAttribute*)Obj)->bIsValueStatic = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic = { "bIsValueStatic", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UOmegaAttribute), &Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic_SetBit, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves_Inner = { "RankValueCurves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(nullptr, 0) }; // 1196190759
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves = { "RankValueCurves", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, RankValueCurves), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves_MetaData)) }; // 1196190759
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_ValueProp = { "ValueCategoryAdjustments", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_Key_KeyProp = { "ValueCategoryAdjustments_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_MetaData[] = {
		{ "Category", "Value" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments = { "ValueCategoryAdjustments", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, ValueCategoryAdjustments), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeCategory_MetaData[] = {
		{ "Category", "Tags" },
		{ "Comment", "//Tags\n" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
		{ "ToolTip", "Tags" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeCategory = { "AttributeCategory", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, AttributeCategory), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeCategory_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/OmegaAttribute.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeTags = { "AttributeTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaAttribute, AttributeTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaAttribute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeLabel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeIcon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_StartValuePercentage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_MaxValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_bIsValueStatic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_RankValueCurves,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_ValueCategoryAdjustments,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeCategory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaAttribute_Statics::NewProp_AttributeTags,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UOmegaAttribute_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UDataInterface_General_NoRegister, (int32)VTABLE_OFFSET(UOmegaAttribute, IDataInterface_General), false },  // 1389727800
			{ Z_Construct_UClass_UGameplayTagsInterface_NoRegister, (int32)VTABLE_OFFSET(UOmegaAttribute, IGameplayTagsInterface), false },  // 2162780125
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaAttribute_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaAttribute>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaAttribute_Statics::ClassParams = {
		&UOmegaAttribute::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaAttribute_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaAttribute_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAttribute_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaAttribute()
	{
		if (!Z_Registration_Info_UClass_UOmegaAttribute.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaAttribute.OuterSingleton, Z_Construct_UClass_UOmegaAttribute_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaAttribute.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaAttribute>()
	{
		return UOmegaAttribute::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaAttribute);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaAttribute, UOmegaAttribute::StaticClass, TEXT("UOmegaAttribute"), &Z_Registration_Info_UClass_UOmegaAttribute, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaAttribute), 3255001517U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_3034496217(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaAttribute_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
