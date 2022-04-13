// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OmegaGameFramework/Public/Preferences/Asset/GamePreferenceBool.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamePreferenceBool() {}
// Cross Module References
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceBool_NoRegister();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreferenceBool();
	OMEGAGAMEFRAMEWORK_API UClass* Z_Construct_UClass_UGamePreference();
	UPackage* Z_Construct_UPackage__Script_OmegaGameFramework();
// End Cross Module References
	void UGamePreferenceBool::StaticRegisterNativesUGamePreferenceBool()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGamePreferenceBool);
	UClass* Z_Construct_UClass_UGamePreferenceBool_NoRegister()
	{
		return UGamePreferenceBool::StaticClass();
	}
	struct Z_Construct_UClass_UGamePreferenceBool_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDefaultValue_MetaData[];
#endif
		static void NewProp_bDefaultValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGamePreferenceBool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGamePreference,
		(UObject* (*)())Z_Construct_UPackage__Script_OmegaGameFramework,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceBool_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Preferences/Asset/GamePreferenceBool.h" },
		{ "ModuleRelativePath", "Public/Preferences/Asset/GamePreferenceBool.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue_MetaData[] = {
		{ "Category", "Bool" },
		{ "ModuleRelativePath", "Public/Preferences/Asset/GamePreferenceBool.h" },
	};
#endif
	void Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue_SetBit(void* Obj)
	{
		((UGamePreferenceBool*)Obj)->bDefaultValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue = { "bDefaultValue", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGamePreferenceBool), &Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGamePreferenceBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamePreferenceBool_Statics::NewProp_bDefaultValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGamePreferenceBool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGamePreferenceBool>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGamePreferenceBool_Statics::ClassParams = {
		&UGamePreferenceBool::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGamePreferenceBool_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceBool_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGamePreferenceBool_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGamePreferenceBool_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGamePreferenceBool()
	{
		if (!Z_Registration_Info_UClass_UGamePreferenceBool.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGamePreferenceBool.OuterSingleton, Z_Construct_UClass_UGamePreferenceBool_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGamePreferenceBool.OuterSingleton;
	}
	template<> OMEGAGAMEFRAMEWORK_API UClass* StaticClass<UGamePreferenceBool>()
	{
		return UGamePreferenceBool::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGamePreferenceBool);
	struct Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceBool_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceBool_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGamePreferenceBool, UGamePreferenceBool::StaticClass, TEXT("UGamePreferenceBool"), &Z_Registration_Info_UClass_UGamePreferenceBool, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGamePreferenceBool), 66995540U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceBool_h_204472452(TEXT("/Script/OmegaGameFramework"),
		Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceBool_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Rebuild5_Plugins_OmegaGameFramework_Source_OmegaGameFramework_Public_Preferences_Asset_GamePreferenceBool_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
