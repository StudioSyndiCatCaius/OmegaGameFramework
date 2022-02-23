// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/OmegaGameSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameSettings() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameSettings_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaGameSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
// End Cross Module References
	void UOmegaGameSettings::StaticRegisterNativesUOmegaGameSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaGameSettings);
	UClass* Z_Construct_UClass_UOmegaGameSettings_NoRegister()
	{
		return UOmegaGameSettings::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaGameSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaGameSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameSettings_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OmegaGameSettings.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OmegaGameSettings.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaGameSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaGameSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaGameSettings_Statics::ClassParams = {
		&UOmegaGameSettings::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UOmegaGameSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaGameSettings()
	{
		if (!Z_Registration_Info_UClass_UOmegaGameSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaGameSettings.OuterSingleton, Z_Construct_UClass_UOmegaGameSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaGameSettings.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaGameSettings>()
	{
		return UOmegaGameSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaGameSettings);
	struct Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaGameSettings, UOmegaGameSettings::StaticClass, TEXT("UOmegaGameSettings"), &Z_Registration_Info_UClass_UOmegaGameSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaGameSettings), 1133994782U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameSettings_h_1043186993(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OmegaBuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_OmegaGameSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
