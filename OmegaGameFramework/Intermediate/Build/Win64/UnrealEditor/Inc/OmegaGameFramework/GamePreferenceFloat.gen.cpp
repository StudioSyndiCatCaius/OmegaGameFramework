// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Preferences/Asset/GamePreferenceFloat.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePreferenceFloat() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceFloat_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceFloat();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreference();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
// End Cross Module References
	void UGamePreferenceFloat::StaticRegisterNativesUGamePreferenceFloat()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGamePreferenceFloat);
	UClass* Z_Construct_UClass_UGamePreferenceFloat_NoRegister()
	{
		return UGamePreferenceFloat::StaticClass();
	}
	struct Z_Construct_UClass_UGamePreferenceFloat_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGamePreferenceFloat_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGamePreference,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceFloat_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Preferences/Asset/GamePreferenceFloat.h" },
		{ "ModuleRelativePath", "Public/Preferences/Asset/GamePreferenceFloat.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceFloat_Statics::NewProp_DefaultValue_MetaData[] = {
		{ "Category", "Float" },
		{ "ModuleRelativePath", "Public/Preferences/Asset/GamePreferenceFloat.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamePreferenceFloat_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamePreferenceFloat, DefaultValue), METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceFloat_Statics::NewProp_DefaultValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceFloat_Statics::NewProp_DefaultValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGamePreferenceFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceFloat_Statics::NewProp_DefaultValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGamePreferenceFloat_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGamePreferenceFloat>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGamePreferenceFloat_Statics::ClassParams = {
		&UGamePreferenceFloat::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGamePreferenceFloat_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceFloat_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceFloat_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceFloat_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGamePreferenceFloat()
	{
		if (!Z_Registration_Info_UClass_UGamePreferenceFloat.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGamePreferenceFloat.OuterSingleton, Z_Construct_UClass_UGamePreferenceFloat_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGamePreferenceFloat.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGamePreferenceFloat>()
	{
		return UGamePreferenceFloat::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGamePreferenceFloat);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceFloat_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceFloat_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGamePreferenceFloat, UGamePreferenceFloat::StaticClass, TEXT("UGamePreferenceFloat"), &Z_Registration_Info_UClass_UGamePreferenceFloat, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGamePreferenceFloat), 485080615U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceFloat_h_1970747831(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceFloat_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceFloat_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
