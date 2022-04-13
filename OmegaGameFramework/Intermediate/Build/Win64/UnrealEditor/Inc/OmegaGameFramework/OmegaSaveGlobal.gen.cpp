// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Save/OmegaSaveGlobal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOmegaSaveGlobal() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGlobal_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveGlobal();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UOmegaSaveBase();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
// End Cross Module References
	void UOmegaSaveGlobal::StaticRegisterNativesUOmegaSaveGlobal()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOmegaSaveGlobal);
	UClass* Z_Construct_UClass_UOmegaSaveGlobal_NoRegister()
	{
		return UOmegaSaveGlobal::StaticClass();
	}
	struct Z_Construct_UClass_UOmegaSaveGlobal_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOmegaSaveGlobal_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UOmegaSaveBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOmegaSaveGlobal_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Save/OmegaSaveGlobal.h" },
		{ "ModuleRelativePath", "Public/Save/OmegaSaveGlobal.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOmegaSaveGlobal_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOmegaSaveGlobal>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOmegaSaveGlobal_Statics::ClassParams = {
		&UOmegaSaveGlobal::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UOmegaSaveGlobal_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOmegaSaveGlobal_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOmegaSaveGlobal()
	{
		if (!Z_Registration_Info_UClass_UOmegaSaveGlobal.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOmegaSaveGlobal.OuterSingleton, Z_Construct_UClass_UOmegaSaveGlobal_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOmegaSaveGlobal.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UOmegaSaveGlobal>()
	{
		return UOmegaSaveGlobal::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOmegaSaveGlobal);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOmegaSaveGlobal, UOmegaSaveGlobal::StaticClass, TEXT("UOmegaSaveGlobal"), &Z_Registration_Info_UClass_UOmegaSaveGlobal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOmegaSaveGlobal), 114634928U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_1656985684(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Save_OmegaSaveGlobal_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
