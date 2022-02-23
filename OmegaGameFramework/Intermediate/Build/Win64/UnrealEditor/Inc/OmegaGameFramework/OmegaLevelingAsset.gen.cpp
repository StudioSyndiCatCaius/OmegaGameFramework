// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Attributes/OmegaLevelingAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaLevelingAsset() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaLevelingAsset_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaLevelingAsset();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
// End Cross Module References
	DEFINE_FUNCTION(UOmegaLevelingAsset::execGetXPFromLevel)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Level);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MinLevelXP);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MaxLevelXP);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetXPFromLevel(Z_Param_Level,Z_Param_Out_MinLevelXP,Z_Param_Out_MaxLevelXP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOmegaLevelingAsset::execGetLevelFromXP)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_XP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetLevelFromXP(Z_Param_XP);
		P_NATIVE_END;
	}
	void UOmegaLevelingAsset::StaticRegisterNativesUOmegaLevelingAsset()
	{
		UClass* Class = UOmegaLevelingAsset::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetLevelFromXP", &UOmegaLevelingAsset::execGetLevelFromXP },
			{ "GetXPFromLevel", &UOmegaLevelingAsset::execGetXPFromLevel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics
	{
		struct OmegaLevelingAsset_eventGetLevelFromXP_Parms
		{
			float XP;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_XP;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::NewProp_XP = { "XP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaLevelingAsset_eventGetLevelFromXP_Parms, XP), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaLevelingAsset_eventGetLevelFromXP_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::NewProp_XP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::Function_MetaDataParams[] = {
		{ "Category", "Leveling" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaLevelingAsset, nullptr, "GetLevelFromXP", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::OmegaLevelingAsset_eventGetLevelFromXP_Parms), Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics
	{
		struct OmegaLevelingAsset_eventGetXPFromLevel_Parms
		{
			int32 Level;
			float MinLevelXP;
			float MaxLevelXP;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinLevelXP;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxLevelXP;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaLevelingAsset_eventGetXPFromLevel_Parms, Level), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::NewProp_MinLevelXP = { "MinLevelXP", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaLevelingAsset_eventGetXPFromLevel_Parms, MinLevelXP), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::NewProp_MaxLevelXP = { "MaxLevelXP", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OmegaLevelingAsset_eventGetXPFromLevel_Parms, MaxLevelXP), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::NewProp_MinLevelXP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::NewProp_MaxLevelXP,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Leveling" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOmegaLevelingAsset, nullptr, "GetXPFromLevel", nullptr, nullptr, sizeof(Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::OmegaLevelingAsset_eventGetXPFromLevel_Parms), Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaLevelingAsset);
	UClass* Z_Construct_UClass_UOmegaLevelingAsset_NoRegister()
	{
		return UOmegaLevelingAsset::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaLevelingAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RankName_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_RankName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_XPName_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_XPName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRank_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRank;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ValueCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ValueCurve;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaLevelingAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOmegaLevelingAsset_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOmegaLevelingAsset_GetLevelFromXP, "GetLevelFromXP" }, // 2119450154
		{ &Z_Construct_UFunction_UOmegaLevelingAsset_GetXPFromLevel, "GetXPFromLevel" }, // 3883059330
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaLevelingAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Attributes/OmegaLevelingAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_RankName_MetaData[] = {
		{ "Category", "Leveling" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_RankName = { "RankName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaLevelingAsset, RankName), METADATA_PARAMS(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_RankName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_RankName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_XPName_MetaData[] = {
		{ "Category", "Leveling" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_XPName = { "XPName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaLevelingAsset, XPName), METADATA_PARAMS(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_XPName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_XPName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_MaxRank_MetaData[] = {
		{ "Category", "Leveling" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_MaxRank = { "MaxRank", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaLevelingAsset, MaxRank), METADATA_PARAMS(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_MaxRank_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_MaxRank_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_ValueCurve_MetaData[] = {
		{ "Category", "Leveling" },
		{ "ModuleRelativePath", "Public/Attributes/OmegaLevelingAsset.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_ValueCurve = { "ValueCurve", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOmegaLevelingAsset, ValueCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_ValueCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_ValueCurve_MetaData)) }; // 1196190759
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOmegaLevelingAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_RankName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_XPName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_MaxRank,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOmegaLevelingAsset_Statics::NewProp_ValueCurve,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaLevelingAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaLevelingAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaLevelingAsset_Statics::ClassParams = {
		&UOmegaLevelingAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOmegaLevelingAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaLevelingAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaLevelingAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaLevelingAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaLevelingAsset()
	{
		if (!Z_Registration_Info_UClass_UOmegaLevelingAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaLevelingAsset.OuterSingleton, Z_Construct_UClass_UOmegaLevelingAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaLevelingAsset.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaLevelingAsset>()
	{
		return UOmegaLevelingAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaLevelingAsset);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaLevelingAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaLevelingAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaLevelingAsset, UOmegaLevelingAsset::StaticClass, TEXT("UOmegaLevelingAsset"), &Z_Registration_Info_UClass_UOmegaLevelingAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaLevelingAsset), 3095784386U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaLevelingAsset_h_2519504091(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaLevelingAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Attributes_OmegaLevelingAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
