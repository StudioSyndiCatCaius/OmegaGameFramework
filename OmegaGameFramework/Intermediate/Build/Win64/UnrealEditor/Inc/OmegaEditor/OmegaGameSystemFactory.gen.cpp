// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaEditor/Public/OmegaGameSystemFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaGameSystemFactory() {}
// Cross Module References
	OMEGAEDITOR_API UClass* Z_Construct_UClass_UOmegaGameSystemFactory_NoRegister();
	OMEGAEDITOR_API UClass* Z_Construct_UClass_UOmegaGameSystemFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_OmegaEditor();
// End Cross Module References
	void UOmegaGameSystemFactory::StaticRegisterNativesUOmegaGameSystemFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaGameSystemFactory);
	UClass* Z_Construct_UClass_UOmegaGameSystemFactory_NoRegister()
	{
		return UOmegaGameSystemFactory::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaGameSystemFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaGameSystemFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaEditor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaGameSystemFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OmegaGameSystemFactory.h" },
		{ "ModuleRelativePath", "Public/OmegaGameSystemFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaGameSystemFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaGameSystemFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaGameSystemFactory_Statics::ClassParams = {
		&UOmegaGameSystemFactory::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UOmegaGameSystemFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaGameSystemFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaGameSystemFactory()
	{
		if (!Z_Registration_Info_UClass_UOmegaGameSystemFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaGameSystemFactory.OuterSingleton, Z_Construct_UClass_UOmegaGameSystemFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaGameSystemFactory.OuterSingleton;
	}
	template<> OMEGAEDITOR_API UClass* StaticClass<UOmegaGameSystemFactory>()
	{
		return UOmegaGameSystemFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaGameSystemFactory);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaGameSystemFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaGameSystemFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaGameSystemFactory, UOmegaGameSystemFactory::StaticClass, TEXT("UOmegaGameSystemFactory"), &Z_Registration_Info_UClass_UOmegaGameSystemFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaGameSystemFactory), 2909886546U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaGameSystemFactory_h_2172495843(TEXT("/Script/OmegaEditor"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaGameSystemFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaEditor_Public_OmegaGameSystemFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
