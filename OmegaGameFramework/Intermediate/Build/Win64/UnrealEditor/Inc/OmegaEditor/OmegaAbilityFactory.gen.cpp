// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaEditor/Public/OmegaAbilityFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaAbilityFactory() {}
// Cross Module References
	OMEGAEDITOR_API UClass* Z_Construct_UClass_UOmegaAbilityFactory_NoRegister();
	OMEGAEDITOR_API UClass* Z_Construct_UClass_UOmegaAbilityFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_OmegaEditor();
// End Cross Module References
	void UOmegaAbilityFactory::StaticRegisterNativesUOmegaAbilityFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaAbilityFactory);
	UClass* Z_Construct_UClass_UOmegaAbilityFactory_NoRegister()
	{
		return UOmegaAbilityFactory::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaAbilityFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaAbilityFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaEditor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaAbilityFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OmegaAbilityFactory.h" },
		{ "ModuleRelativePath", "Public/OmegaAbilityFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaAbilityFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaAbilityFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaAbilityFactory_Statics::ClassParams = {
		&UOmegaAbilityFactory::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UOmegaAbilityFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaAbilityFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaAbilityFactory()
	{
		if (!Z_Registration_Info_UClass_UOmegaAbilityFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaAbilityFactory.OuterSingleton, Z_Construct_UClass_UOmegaAbilityFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaAbilityFactory.OuterSingleton;
	}
	template<> OMEGAEDITOR_API UClass* StaticClass<UOmegaAbilityFactory>()
	{
		return UOmegaAbilityFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaAbilityFactory);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaAbilityFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaAbilityFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaAbilityFactory, UOmegaAbilityFactory::StaticClass, TEXT("UOmegaAbilityFactory"), &Z_Registration_Info_UClass_UOmegaAbilityFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaAbilityFactory), 2473688208U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaAbilityFactory_h_3634935576(TEXT("/Script/OmegaEditor"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaAbilityFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaAbilityFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
