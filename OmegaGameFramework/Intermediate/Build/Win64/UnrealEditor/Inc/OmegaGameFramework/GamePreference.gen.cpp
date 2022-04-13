// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Preferences/GamePreference.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePreference() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreference_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreference();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayTagsInterface_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDataInterface_General_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UGamePreference::execGetGeneralAssetLabel)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Label);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetGeneralAssetLabel_Implementation(Z_Param_Out_Label);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreference::execGetGeneralDataText)
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
	DEFINE_FUNCTION(UGamePreference::execGetObjectGameplayTags)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetObjectGameplayTags_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGamePreference::execGetObjectGameplayCategory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayTag*)Z_Param__Result=P_THIS->GetObjectGameplayCategory_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_UGamePreference_GetGeneralAssetLabel = FName(TEXT("GetGeneralAssetLabel"));
	void UGamePreference::GetGeneralAssetLabel(FString& Label)
	{
		GamePreference_eventGetGeneralAssetLabel_Parms Parms;
		Parms.Label=Label;
		ProcessEvent(FindFunctionChecked(NAME_UGamePreference_GetGeneralAssetLabel),&Parms);
		Label=Parms.Label;
	}
	static FName NAME_UGamePreference_GetGeneralDataText = FName(TEXT("GetGeneralDataText"));
	void UGamePreference::GetGeneralDataText(const FString& Label, const UObject* Context, FText& Name, FText& Description)
	{
		GamePreference_eventGetGeneralDataText_Parms Parms;
		Parms.Label=Label;
		Parms.Context=Context;
		Parms.Name=Name;
		Parms.Description=Description;
		ProcessEvent(FindFunctionChecked(NAME_UGamePreference_GetGeneralDataText),&Parms);
		Name=Parms.Name;
		Description=Parms.Description;
	}
	static FName NAME_UGamePreference_GetObjectGameplayCategory = FName(TEXT("GetObjectGameplayCategory"));
	FGameplayTag UGamePreference::GetObjectGameplayCategory()
	{
		GamePreference_eventGetObjectGameplayCategory_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UGamePreference_GetObjectGameplayCategory),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UGamePreference_GetObjectGameplayTags = FName(TEXT("GetObjectGameplayTags"));
	FGameplayTagContainer UGamePreference::GetObjectGameplayTags()
	{
		GamePreference_eventGetObjectGameplayTags_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UGamePreference_GetObjectGameplayTags),&Parms);
		return Parms.ReturnValue;
	}
	void UGamePreference::StaticRegisterNativesUGamePreference()
	{
		UClass* Class = UGamePreference::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGeneralAssetLabel", &UGamePreference::execGetGeneralAssetLabel },
			{ "GetGeneralDataText", &UGamePreference::execGetGeneralDataText },
			{ "GetObjectGameplayCategory", &UGamePreference::execGetObjectGameplayCategory },
			{ "GetObjectGameplayTags", &UGamePreference::execGetObjectGameplayTags },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics
	{
		static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetGeneralAssetLabel_Parms, Label), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::NewProp_Label,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//AssetLabel\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
		{ "ToolTip", "AssetLabel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreference, nullptr, "GetGeneralAssetLabel", nullptr, nullptr, sizeof(GamePreference_eventGetGeneralAssetLabel_Parms), Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetGeneralDataText_Parms, Label), METADATA_PARAMS(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Label_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Label_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetGeneralDataText_Parms, Context), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Context_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Context_MetaData)) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetGeneralDataText_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetGeneralDataText_Parms, Description), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Label,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Context,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::NewProp_Description,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Data|General" },
		{ "Comment", "//Texts\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
		{ "ToolTip", "Texts" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreference, nullptr, "GetGeneralDataText", nullptr, nullptr, sizeof(GamePreference_eventGetGeneralDataText_Parms), Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreference_GetGeneralDataText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreference_GetGeneralDataText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetObjectGameplayCategory_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) }; // 802167388
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "Comment", "//Interface\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
		{ "ToolTip", "Interface" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreference, nullptr, "GetObjectGameplayCategory", nullptr, nullptr, sizeof(GamePreference_eventGetObjectGameplayCategory_Parms), Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GamePreference_eventGetObjectGameplayTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(nullptr, 0) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::Function_MetaDataParams[] = {
		{ "Category", "GameplayTags" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGamePreference, nullptr, "GetObjectGameplayTags", nullptr, nullptr, sizeof(GamePreference_eventGetObjectGameplayTags_Parms), Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGamePreference);
	UClass* Z_Construct_UClass_UGamePreference_NoRegister()
	{
		return UGamePreference::StaticClass();
	}
	struct Z_Construct_UClass_UGamePreference_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PrefernceName_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_PrefernceName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PreferenceLabel_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_PreferenceLabel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bGlobal_MetaData[];
#endif
		static void NewProp_bGlobal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGlobal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PreferenceCategory_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PreferenceCategory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PreferenceTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PreferenceTags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGamePreference_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGamePreference_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGamePreference_GetGeneralAssetLabel, "GetGeneralAssetLabel" }, // 3730057835
		{ &Z_Construct_UFunction_UGamePreference_GetGeneralDataText, "GetGeneralDataText" }, // 3420904439
		{ &Z_Construct_UFunction_UGamePreference_GetObjectGameplayCategory, "GetObjectGameplayCategory" }, // 780435835
		{ &Z_Construct_UFunction_UGamePreference_GetObjectGameplayTags, "GetObjectGameplayTags" }, // 193693758
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreference_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Preferences/GamePreference.h" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreference_Statics::NewProp_PrefernceName_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UGamePreference_Statics::NewProp_PrefernceName = { "PrefernceName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreference, PrefernceName), METADATA_PARAMS(Z_Construct_UClass_UGamePreference_Statics::NewProp_PrefernceName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::NewProp_PrefernceName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceLabel_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceLabel = { "PreferenceLabel", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreference, PreferenceLabel), METADATA_PARAMS(Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceLabel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceLabel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "//Is this preference saved globally save file?\n" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
		{ "ToolTip", "Is this preference saved globally save file?" },
	};
#endif
	void Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal_SetBit(void* Obj)
	{
		((UGamePreference*)Obj)->bGlobal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal = { "bGlobal", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGamePreference), &Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceCategory_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceCategory = { "PreferenceCategory", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreference, PreferenceCategory), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceCategory_MetaData)) }; // 802167388
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceTags_MetaData[] = {
		{ "Category", "Tags" },
		{ "ModuleRelativePath", "Public/Preferences/GamePreference.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceTags = { "PreferenceTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreference, PreferenceTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceTags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceTags_MetaData)) }; // 506667518
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGamePreference_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreference_Statics::NewProp_PrefernceName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceLabel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreference_Statics::NewProp_bGlobal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceCategory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreference_Statics::NewProp_PreferenceTags,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UGamePreference_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UGameplayTagsInterface_NoRegister, (int32)VTABLE_OFFSET(UGamePreference, IGameplayTagsInterface), false },  // 2162780125
			{ Z_Construct_UClass_UDataInterface_General_NoRegister, (int32)VTABLE_OFFSET(UGamePreference, IDataInterface_General), false },  // 1389727800
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGamePreference_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGamePreference>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGamePreference_Statics::ClassParams = {
		&UGamePreference::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGamePreference_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGamePreference_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreference_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGamePreference()
	{
		if (!Z_Registration_Info_UClass_UGamePreference.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGamePreference.OuterSingleton, Z_Construct_UClass_UGamePreference_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGamePreference.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGamePreference>()
	{
		return UGamePreference::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGamePreference);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGamePreference, UGamePreference::StaticClass, TEXT("UGamePreference"), &Z_Registration_Info_UClass_UGamePreference, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGamePreference), 3800754522U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_3204280271(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_GamePreference_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
