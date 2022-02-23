// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/DamageFormula.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDamageFormula() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDamageFormula_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UDamageFormula();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	static FName NAME_UDamageFormula_GetDamageAmount = FName(TEXT("GetDamageAmount"));
	void UDamageFormula::GetDamageAmount(UObject* Instigator, UObject* Target, float& DamageOut)
	{
		DamageFormula_eventGetDamageAmount_Parms Parms;
		Parms.Instigator=Instigator;
		Parms.Target=Target;
		Parms.DamageOut=DamageOut;
		ProcessEvent(FindFunctionChecked(NAME_UDamageFormula_GetDamageAmount),&Parms);
		DamageOut=Parms.DamageOut;
	}
	void UDamageFormula::StaticRegisterNativesUDamageFormula()
	{
	}
	struct Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageOut;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DamageFormula_eventGetDamageAmount_Parms, Instigator), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DamageFormula_eventGetDamageAmount_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::NewProp_DamageOut = { "DamageOut", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DamageFormula_eventGetDamageAmount_Parms, DamageOut), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::NewProp_Instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::NewProp_DamageOut,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DamageFormula.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDamageFormula, nullptr, "GetDamageAmount", nullptr, nullptr, sizeof(DamageFormula_eventGetDamageAmount_Parms), Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDamageFormula_GetDamageAmount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDamageFormula_GetDamageAmount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDamageFormula);
	UClass* Z_Construct_UClass_UDamageFormula_NoRegister()
	{
		return UDamageFormula::StaticClass();
	}
	struct Z_Construct_UClass_UDamageFormula_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDamageFormula_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDamageFormula_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDamageFormula_GetDamageAmount, "GetDamageAmount" }, // 3861949714
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageFormula_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "DamageFormula.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DamageFormula.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDamageFormula_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDamageFormula>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDamageFormula_Statics::ClassParams = {
		&UDamageFormula::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDamageFormula_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDamageFormula_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDamageFormula()
	{
		if (!Z_Registration_Info_UClass_UDamageFormula.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDamageFormula.OuterSingleton, Z_Construct_UClass_UDamageFormula_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDamageFormula.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UDamageFormula>()
	{
		return UDamageFormula::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDamageFormula);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DamageFormula_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DamageFormula_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDamageFormula, UDamageFormula::StaticClass, TEXT("UDamageFormula"), &Z_Registration_Info_UClass_UDamageFormula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDamageFormula), 1406777316U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DamageFormula_h_3571031258(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DamageFormula_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_DamageFormula_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
