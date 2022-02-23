// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Gameplay/CombatInputUtility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCombatInputUtility() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatInputUtility_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatInputUtility();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UCombatantComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_AOmegaAbility_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCombatInputUtility::execExecute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Execute();
		P_NATIVE_END;
	}
	void UCombatInputUtility::StaticRegisterNativesUCombatInputUtility()
	{
		UClass* Class = UCombatInputUtility::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Execute", &UCombatInputUtility::execExecute },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCombatInputUtility_Execute_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCombatInputUtility_Execute_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatInputUtility.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatInputUtility_Execute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCombatInputUtility, nullptr, "Execute", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCombatInputUtility_Execute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatInputUtility_Execute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCombatInputUtility_Execute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatInputUtility_Execute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCombatInputUtility);
	UClass* Z_Construct_UClass_UCombatInputUtility_NoRegister()
	{
		return UCombatInputUtility::StaticClass();
	}
	struct Z_Construct_UClass_UCombatInputUtility_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombatOwner_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CombatOwner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoundAblityClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_BoundAblityClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCombatInputUtility_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCombatInputUtility_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombatInputUtility_Execute, "Execute" }, // 3739075226
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatInputUtility_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Gameplay/CombatInputUtility.h" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatInputUtility.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_CombatOwner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Gameplay/CombatInputUtility.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_CombatOwner = { "CombatOwner", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatInputUtility, CombatOwner), Z_Construct_UClass_UCombatantComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_CombatOwner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_CombatOwner_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_BoundAblityClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/Gameplay/CombatInputUtility.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_BoundAblityClass = { "BoundAblityClass", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCombatInputUtility, BoundAblityClass), Z_Construct_UClass_AOmegaAbility_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_BoundAblityClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_BoundAblityClass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCombatInputUtility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_CombatOwner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatInputUtility_Statics::NewProp_BoundAblityClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCombatInputUtility_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombatInputUtility>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatInputUtility_Statics::ClassParams = {
		&UCombatInputUtility::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCombatInputUtility_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCombatInputUtility_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCombatInputUtility_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCombatInputUtility_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCombatInputUtility()
	{
		if (!Z_Registration_Info_UClass_UCombatInputUtility.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatInputUtility.OuterSingleton, Z_Construct_UClass_UCombatInputUtility_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCombatInputUtility.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UCombatInputUtility>()
	{
		return UCombatInputUtility::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCombatInputUtility);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatInputUtility_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatInputUtility_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCombatInputUtility, UCombatInputUtility::StaticClass, TEXT("UCombatInputUtility"), &Z_Registration_Info_UClass_UCombatInputUtility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatInputUtility), 3135580149U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatInputUtility_h_1404601414(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatInputUtility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Gameplay_CombatInputUtility_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
