// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaEditor/Public/OmegaEffectFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaEffectFactory() {}
// Cross Module References
	OMEGAEDITOR_API UClass* Z_Construct_UClass_UOmegaEffectFactory_NoRegister();
	OMEGAEDITOR_API UClass* Z_Construct_UClass_UOmegaEffectFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_OmegaEditor();
// End Cross Module References
	void UOmegaEffectFactory::StaticRegisterNativesUOmegaEffectFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaEffectFactory);
	UClass* Z_Construct_UClass_UOmegaEffectFactory_NoRegister()
	{
		return UOmegaEffectFactory::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaEffectFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaEffectFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaEditor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaEffectFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OmegaEffectFactory.h" },
		{ "ModuleRelativePath", "Public/OmegaEffectFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaEffectFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaEffectFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaEffectFactory_Statics::ClassParams = {
		&UOmegaEffectFactory::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UOmegaEffectFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaEffectFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaEffectFactory()
	{
		if (!Z_Registration_Info_UClass_UOmegaEffectFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaEffectFactory.OuterSingleton, Z_Construct_UClass_UOmegaEffectFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaEffectFactory.OuterSingleton;
	}
	template<> OMEGAEDITOR_API UClass* StaticClass<UOmegaEffectFactory>()
	{
		return UOmegaEffectFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaEffectFactory);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaEffectFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaEffectFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaEffectFactory, UOmegaEffectFactory::StaticClass, TEXT("UOmegaEffectFactory"), &Z_Registration_Info_UClass_UOmegaEffectFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaEffectFactory), 3637842346U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaEffectFactory_h_3853803737(TEXT("/Script/OmegaEditor"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaEffectFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaEffectFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
